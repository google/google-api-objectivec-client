/* Copyright (c) 2011 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
//  LatitudeSampleWindowController.m
//

#import "LatitudeSampleWindowController.h"

#import "GTL/GTMOAuth2WindowController.h"
#import "GTL/GTMHTTPFetcherLogging.h"

@interface LatitudeSampleWindowController ()

@property (readonly) GTLServiceLatitude *latitudeService;

- (void)updateUI;
- (void)displayAlert:(NSString *)title format:(NSString *)format, ...;

- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel;
- (GTLLatitudeLocation *)selectedLocationItem;

- (BOOL)isHistorySelected;
- (BOOL)isBestGranularitySelected;
- (void)setLocationForTimestamp:(NSString *)timestamp;

- (void)fetchLocations;
- (void)deleteLocation;

@end

NSString *const kKeychainItemName = @"Latitude Sample: Google Latitude";

@implementation LatitudeSampleWindowController

@synthesize locationsFeed = locationsFeed_,
            locationsTicket = locationsTicket_,
            locationsFetchError = locationsFetchError_,
            editLocationTicket = editLocationTicket_;

+ (LatitudeSampleWindowController *)sharedWindowController {
  static LatitudeSampleWindowController* gWindowController = nil;
  if (!gWindowController) {
    gWindowController = [[LatitudeSampleWindowController alloc] init];
  }
  return gWindowController;
}


- (id)init {
  return [self initWithWindowNibName:@"LatitudeSampleWindow"];
}

- (void)awakeFromNib {
  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  GTMOAuth2Authentication *auth;
  auth = [GTMOAuth2WindowController authForGoogleFromKeychainForName:kKeychainItemName
                                                            clientID:clientID
                                                        clientSecret:clientSecret];
  [self.latitudeService setAuthorizer:auth];

  // Set the result text fields to have a distinctive color and mono-spaced font
  [locationsResultTextField_ setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [locationsResultTextField_ setFont:resultTextFont];

  [datePicker_ setDateValue:[NSDate date]];

  // We'll try to use the location manager to initialize the latitude/logitude
  // text fields to the current location
  [self updateUI];
}

- (void)dealloc {
  [locationsFeed_ release];
  [locationsTicket_ release];
  [locationsFetchError_ release];
  [editLocationTicket_ release];

  [super dealloc];
}

#pragma mark -

- (NSString *)signedInUsername {
  // Get the email address of the signed-in user
  GTLServiceLatitude *service = self.latitudeService;
  GTMOAuth2Authentication *auth = [service authorizer];
  BOOL isSignedIn = [auth canAuthorize];
  if (isSignedIn) {
    return [auth userEmail];
  } else {
    return nil;
  }
}

- (BOOL)isSignedIn {
  NSString *name = [self signedInUsername];
  return (name != nil);
}

#pragma mark IBActions

+ (NSString *)timestampForDate:(NSDate *)date {
  NSTimeInterval seconds = [date timeIntervalSince1970];
  double millisecs = seconds * 1000.0;
  unsigned long long val = (long long)millisecs;
  NSString *str = [NSString stringWithFormat:@"%qu", val];
  return str;
}

+ (NSDate *)dateForTimestamp:(NSString *)timestamp {
  // the server returns timestamp as a string, milliseconds since the unix epoch
  long long val = [timestamp longLongValue];
  NSTimeInterval seconds = (NSTimeInterval)val / 1000.0;
  NSDate *date = [NSDate dateWithTimeIntervalSince1970:seconds];
  return date;
}

- (IBAction)signInClicked:(id)sender {
  if (![self isSignedIn]) {
    // sign in
    [self runSigninThenInvokeSelector:@selector(updateUI)];
  } else {
    // sign out
    GTLServiceLatitude *service = self.latitudeService;

    [GTMOAuth2WindowController removeAuthFromKeychainForName:kKeychainItemName];
    [service setAuthorizer:nil];
    [self updateUI];
  }
}

- (IBAction)getLocationsClicked:(id)sender {
  if (![self isSignedIn]) {
    [self runSigninThenInvokeSelector:@selector(fetchLocations)];
  } else {
    [self fetchLocations];
  }
}

- (IBAction)cancelLocationsFetchClicked:(id)sender {
  // cancel any location feed fetch
  [self.locationsTicket cancelTicket];
  [self setLocationsTicket:nil];

  // cancel if we're editing the location
  [self.editLocationTicket cancelTicket];
  [self setEditLocationTicket:nil];

  [self updateUI];
}

- (IBAction)locationRadioButtonClicked:(id)sender {
  // enabled/disable buttons
  [self updateUI];
}

- (IBAction)addLocationClicked:(id)sender {
  [self setLocationForTimestamp:nil];
}

- (IBAction)updateLocationClicked:(id)sender {
  BOOL isHistorySelected = [self isHistorySelected];
  if (isHistorySelected) {
    // replace an existing location
    GTLLatitudeLocation *location = [self selectedLocationItem];
    if (location) {
      NSString *timestamp = [location timestampMs];
      [self setLocationForTimestamp:timestamp];
    }
  } else {
    // replace current location
    [self setLocationForTimestamp:nil];
  }
}

- (IBAction)deleteLocationClicked:(id)sender {
  [self deleteLocation];
}

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://code.google.com/apis/console"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMHTTPFetcher setLoggingEnabled:[sender state]];
}

#pragma mark -

// get a service object with the current username/password
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information (such as cookies and the "last modified" date for
// fetched data.)

- (GTLServiceLatitude *)latitudeService {

  static GTLServiceLatitude* service = nil;

  if (!service) {
    service = [[GTLServiceLatitude alloc] init];

    // have the service object fetch consecutive pages of the feed so we
    // do not need to manually fetch them
    service.shouldFetchNextPages = YES;

    // have the service object retry temporary error conditions automatically
    service.retryEnabled = YES;
  }
  return service;
}

// get the comment selected in the bottom list, or nil if non
- (GTLLatitudeLocation *)selectedLocationItem {
  int rowIndex = [locationsTable_ selectedRow];
  if (rowIndex > -1) {
    GTLLatitudeLocation *item = [self.locationsFeed.items objectAtIndex:rowIndex];
    return item;
  }
  return nil;
}

#pragma mark Fetch the locations feed

- (BOOL)isHistorySelected {
  int timeTag = [[timeMatrix_ selectedCell] tag];
  BOOL isHistoryRequest = (timeTag == 0);
  return isHistoryRequest;
}

- (BOOL)isBestGranularitySelected {
  int granularityTag = [[granularityMatrix_ selectedCell] tag];
  BOOL isBest = (granularityTag == 1);
  return isBest;
}

// begin retrieving the feed
- (void)fetchLocations {

  self.locationsFeed = nil;
  self.locationsFetchError = nil;

  GTLQueryLatitude *query;
  if ([self isHistorySelected]) {
    query = [GTLQueryLatitude queryForLocationList];
  } else {
    query = [GTLQueryLatitude queryForCurrentLocationGet];
  }

  NSString *granularity;
  if ([self isBestGranularitySelected]) {
    granularity = kGTLLatitudeGranularityBest;
  } else {
    granularity = kGTLLatitudeGranularityCity;
  }
  [query setGranularity:granularity];

  GTLServiceLatitude *service = self.latitudeService;
  self.locationsTicket = [service executeQuery:query
                             completionHandler:^(GTLServiceTicket *ticket,
                                                 id object, NSError *error) {
                               // callback
                               GTLLatitudeLocationFeed *feed;

                               if ([object isKindOfClass:[GTLLatitudeLocation class]]) {
                                 // we fetched the current location, which is an item rather than a feed;
                                 // we'll create a feed around the item
                                 feed = [[[GTLLatitudeLocationFeed alloc] init] autorelease];
                                 feed.items = [NSMutableArray arrayWithObject:object];
                               } else {
                                 // we fetched a feed
                                 feed = (GTLLatitudeLocationFeed *)object;
                               }

                               self.locationsFeed = feed;
                               self.locationsFetchError = error;
                               self.locationsTicket = nil;

                               [self updateUI];
                             }];
  [self updateUI];
}

#pragma mark Add or Update a location

- (void)setLocationForTimestamp:(NSString *)timestamp {
  // set a location item with the latitude and longitude and, for
  // inserting into the location history, the date set in the picker
  //
  // if timestamp is specified, it replaces any existing location with that
  // timestamp
  NSString *lat = [latitudeField_ stringValue];
  NSString *lng = [longitudeField_ stringValue];

  NSDecimalNumber *latNum = [NSDecimalNumber decimalNumberWithString:lat];
  NSDecimalNumber *lngNum = [NSDecimalNumber decimalNumberWithString:lng];

  GTLLatitudeLocation *newLocation = [GTLLatitudeLocation object];
  newLocation.latitude = latNum;
  newLocation.longitude = lngNum;

  GTLQueryLatitude *query;
  BOOL isHistorySelected = [self isHistorySelected];
  if (isHistorySelected) {

    if ([timestamp length] > 0) {
      // replacing a previous location
      [newLocation setTimestampMs:timestamp];
    } else {
      // adding a new location to the history
      NSDate *date = [datePicker_ dateValue];
      newLocation.timestampMs = [[self class] timestampForDate:date];
    }
    query = [GTLQueryLatitude queryForLocationInsertWithObject:newLocation];
  } else {
    // replacing current location
    query = [GTLQueryLatitude queryForCurrentLocationInsertWithObject:newLocation];
  }

  // even though replacing a location should logically be done with an http
  // PUT to update the item, the Latitude API relies on POST for both
  // insert and update
  GTLServiceLatitude *service = self.latitudeService;
  self.editLocationTicket = [service executeQuery:query
                                completionHandler:^(GTLServiceTicket *ticket,
                                                    id object, NSError *error) {
                                  // callback
                                  self.editLocationTicket = nil;

                                  GTLLatitudeLocation *item = object;
                                  if (error == nil) {
                                    [self displayAlert:@"Location Set"
                                                format:@"Set location %@,%@ for date %@",
                                     item.latitude, item.longitude,
                                     [[self class] dateForTimestamp:item.timestampMs]];

                                    [self fetchLocations];
                                  } else {
                                    [self displayAlert:@"Set Location Error"
                                                format:@"%@", error];
                                    [self updateUI];
                                  }

                                }];
  [self updateUI];
}

#pragma mark Delete Location from History

- (void)deleteLocation {
  GTLQueryLatitude *query = nil;
  BOOL isHistorySelected = [self isHistorySelected];
  if (isHistorySelected) {
    // delete the selected location
    GTLLatitudeLocation *selectedLocation = [self selectedLocationItem];
    if (selectedLocation) {
      query = [GTLQueryLatitude queryForLocationDeleteWithLocationId:selectedLocation.timestampMs];
    }
  } else {
    // delete the current location
    query = [GTLQueryLatitude queryForCurrentLocationDelete];
  }

  if (query) {
    GTLServiceLatitude *service = self.latitudeService;
    self.editLocationTicket = [service executeQuery:query
                                  completionHandler:^(GTLServiceTicket *ticket,
                                                      id object, NSError *error) {
                                    // callback
                                    self.editLocationTicket = nil;

                                    if (error == nil) {
                                      [self displayAlert:@"Location Deleted"
                                                  format:@"Deleted location"];
                                      [self fetchLocations];
                                    } else {
                                      [self displayAlert:@"Delete Location Error"
                                                  format:@"%@", error];
                                      [self updateUI];
                                    }

                                  }];
    [self updateUI];
  }
}

#pragma mark -

#pragma mark Client ID and Client Secret Sheet

// Sample apps need this sheet to ask for the client ID and client secret
// strings
//
// Your application will just hardcode the client ID and client secret strings
// into the source rather than ask the user for them.
//
// The string values are obtained from the API Console,
// https://code.google.com/apis/console
//

- (IBAction)clientIDClicked:(id)sender {
  // show the sheet for developers to enter client ID and client secret
  [NSApp beginSheet:clientIDSheet_
     modalForWindow:[self window]
      modalDelegate:self
     didEndSelector:@selector(clientIDSheetDidEnd:returnCode:contextInfo:)
        contextInfo:NULL];
}

- (IBAction)clientIDDoneClicked:(id)sender {
  [NSApp endSheet:clientIDSheet_
       returnCode:NSOKButton];
}

- (void)clientIDSheetDidEnd:(NSWindow *)sheet returnCode:(NSInteger)returnCode contextInfo:(void *)contextInfo {
  [sheet orderOut:self];
  [self updateUI];
}

#pragma mark Sign In

- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel {
  NSString *scope = [GTMOAuth2Authentication scopeWithStrings:
                     kGTLAuthScopeLatitudeAllBest,
                     kGTLAuthScopeLatitudeCurrentBest,
                     nil];

  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  if ([clientID length] == 0 || [clientSecret length] == 0) {
    // remind the developer that client ID and client secret are needed
    [clientIDButton_ performSelector:@selector(performClick:)
                          withObject:self
                          afterDelay:0.5];
    return;
  }

  NSBundle *frameworkBundle = [NSBundle bundleForClass:[GTMOAuth2WindowController class]];
  GTMOAuth2WindowController *windowController;
  windowController = [GTMOAuth2WindowController controllerWithScope:scope
                                                           clientID:clientID
                                                       clientSecret:clientSecret
                                                   keychainItemName:kKeychainItemName
                                                     resourceBundle:frameworkBundle];
  
  [windowController signInSheetModalForWindow:[self window]
                            completionHandler:^(GTMOAuth2Authentication *auth,
                                                NSError *error) {
                              // callback
                              if (error == nil) {
                                self.latitudeService.authorizer = auth;
                                if (signInDoneSel) {
                                  [self performSelector:signInDoneSel];
                                }
                              } else {
                                self.locationsFetchError = error;
                                [self updateUI];
                              }
                            }];
}

#pragma mark UI

- (void)updateUI {
  BOOL isSignedIn = [self isSignedIn];
  NSString *username = [self signedInUsername];
  [signedInButton_ setTitle:(isSignedIn ? @"Sign Out" : @"Sign In")];
  [signedInField_ setStringValue:(isSignedIn ? username : @"No")];

  // locations table
  [locationsTable_ reloadData];

  if ([self locationsTicket] != nil || [self editLocationTicket] != nil) {
    [locationsProgressIndicator_ startAnimation:self];
    [locationsCancelButton_ setEnabled:YES];
  } else {
    [locationsProgressIndicator_ stopAnimation:self];
    [locationsCancelButton_ setEnabled:NO];
  }

  GTLLatitudeLocation *selectedLocation = [self selectedLocationItem];
  NSString *resultStr = @"";
  NSError *fetchError = self.locationsFetchError;
  if (fetchError != nil) {
    resultStr = [fetchError description];
    // also display any server error data present
    NSData *errData = [[fetchError userInfo] objectForKey:kGTMHTTPFetcherStatusDataKey];
    if (errData) {
      NSString *dataStr = [[[NSString alloc] initWithData:errData
                                                 encoding:NSUTF8StringEncoding] autorelease];
      resultStr = [resultStr stringByAppendingFormat:@"\n%@", dataStr];
    }
  } else {
    if (selectedLocation) {
      resultStr = [selectedLocation description];
    }
  }
  [locationsResultTextField_ setString:resultStr];

  // enable buttons
  BOOL hasLatitude = ([[latitudeField_ stringValue] length] > 0);
  BOOL hasLongitude = ([[longitudeField_ stringValue] length] > 0);
  BOOL hasLatLong = (hasLatitude && hasLongitude);
  BOOL hasSelectedLocation = (selectedLocation != nil);
  BOOL isHistorySelected = [self isHistorySelected];

  [addLocationButton_ setEnabled:(hasLatLong && isHistorySelected)];
  [updateLocationButton_ setEnabled:((hasSelectedLocation || !isHistorySelected)
                                     && hasLatLong)];
  [deleteLocationButton_ setEnabled:hasSelectedLocation];

  [datePicker_ setEnabled:isHistorySelected];

  // show or hide the text indicating that the client ID or client secret are
  // needed
  BOOL hasClientIDStrings = [[clientIDField_ stringValue] length] > 0
    && [[clientSecretField_ stringValue] length] > 0;
  [clientIDRequiredTextField_ setHidden:hasClientIDStrings];
}

- (void)displayAlert:(NSString *)title format:(NSString *)format, ... {
  NSString *result = format;
  if (format) {
    va_list argList;
    va_start(argList, format);
    result = [[[NSString alloc] initWithFormat:format
                                     arguments:argList] autorelease];
    va_end(argList);
  }
  NSBeginAlertSheet(title, nil, nil, nil, [self window], nil, nil,
                    nil, nil, @"%@", result);
}

#pragma mark Text field delegate methods

- (void)controlTextDidChange:(NSNotification *)note {
  [self updateUI]; // enabled/disable buttons
}

#pragma mark TableView delegate and data source methods

- (void)tableViewSelectionDidChange:(NSNotification *)notification {
  [self updateUI];
}

// table view data source methods
- (int)numberOfRowsInTableView:(NSTableView *)tableView {
  return [self.locationsFeed.items count];
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(int)row {
  // make a string with the location date and lat/long
  NSArray *items = self.locationsFeed.items;
  GTLLatitudeLocation *location = [items objectAtIndex:row];
  NSDate *date = [[self class] dateForTimestamp:location.timestampMs];
  NSString *resultStr = [NSString stringWithFormat:@"%@ (%@, %@)",
                         date, location.latitude, location.longitude];
  return resultStr;
}

@end

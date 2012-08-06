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
//  CalendarSampleWindowController.m
//

#import "CalendarSampleWindowController.h"
#import "EditEventWindowController.h"
#import "EditACLWindowController.h"

#import "GTL/GTLUtilities.h"
#import "GTL/GTMHTTPFetcherLogging.h"

enum {
  kEventsSegment = 0,
  kAccessControlSegment = 1,
  kSettingsSegment = 2
};

@interface CalendarSampleWindowController ()

@property (readonly) GTLServiceCalendar *calendarService;

@property (retain) GTLCalendarCalendarList *calendarList;
@property (retain) GTLServiceTicket *calendarListTicket;
@property (retain) NSError *calendarListFetchError;

@property (retain) GTLServiceTicket *editCalendarListTicket;

@property (retain) GTLCalendarEvents *events;
@property (retain) GTLServiceTicket *eventsTicket;
@property (retain) NSError *eventsFetchError;

@property (retain) GTLCalendarAcl *ACLs;
@property (retain) NSError *ACLsFetchError;

@property (retain) GTLCalendarSettings *settings;
@property (retain) NSError *settingsFetchError;

@property (retain) GTLServiceTicket *editEventTicket;


- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel;

- (void)updateUI;
- (NSString *)displayStringForACLRule:(GTLCalendarAclRule *)rule;
- (void)displayAlert:(NSString *)title format:(NSString *)format, ...;

- (void)fetchCalendarList;
- (void)fetchSelectedCalendar;
- (void)addACalendar;
- (void)renameSelectedCalendar;
- (void)deleteSelectedCalendar;

- (void)addAnEvent;
- (void)addEvent:(GTLCalendarEvent *)event;
- (void)editSelectedEvent;
- (void)editSelectedEventWithEvent:(GTLCalendarEvent *)revisedEvent;
- (void)deleteSelectedEvent;
- (void)queryTodaysEvents;
- (void)queryFreeBusy;

- (void)addAnACLRule;
- (void)addACLRule:(GTLCalendarAclRule *)rule;
- (void)editSelectedACLRule;
- (void)editSelectedACLRuleWithRule:(GTLCalendarAclRule *)revisedRule;
- (void)deleteSelectedACLRule;

- (GTLCalendarCalendarListEntry *)selectedCalendarListEntry;
- (GTLCalendarEvent *)selectedEvent;

@end

// Keychain item name for saving the user's authentication information
NSString *const kKeychainItemName = @"CalendarSample: Google Calendar";

@implementation CalendarSampleWindowController

@synthesize calendarList = calendarList_,
            calendarListTicket = calendarListTicket_,
            calendarListFetchError = calendarFetchError_,
            editCalendarListTicket = editCalendarListTicket_,
            events = events_,
            eventsTicket = eventTicket_,
            eventsFetchError = eventsFetchError_,
            ACLs = calendarACLs_,
            ACLsFetchError = calendarACLsFetchError_,
            settings = settings_,
            settingsFetchError = settingsFetchError_,
            editEventTicket = editEventTicket_;

+ (CalendarSampleWindowController *)sharedWindowController {
  static CalendarSampleWindowController* gWindowController = nil;
  if (!gWindowController) {
    gWindowController = [[CalendarSampleWindowController alloc] init];
  }
  return gWindowController;
}

- (id)init {
  return [self initWithWindowNibName:@"CalendarSampleWindow"];
}

- (void)awakeFromNib {
  // Load the OAuth token from the keychain, if it was previously saved
  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  GTMOAuth2Authentication *auth;
  auth = [GTMOAuth2WindowController authForGoogleFromKeychainForName:kKeychainItemName
                                                            clientID:clientID
                                                        clientSecret:clientSecret];
  self.calendarService.authorizer = auth;

  // Set the result text fields to have a distinctive color and mono-spaced font
  [calendarResultTextField_ setTextColor:[NSColor darkGrayColor]];
  [eventResultTextField_ setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [calendarResultTextField_ setFont:resultTextFont];
  [eventResultTextField_ setFont:resultTextFont];

  [self updateUI];
}

- (void)dealloc {
  [calendarList_ release];
  [calendarListTicket_ release];
  [calendarFetchError_ release];

  [editCalendarListTicket_ release];

  [events_ release];
  [eventTicket_ release];
  [eventsFetchError_ release];

  [calendarACLs_ release];
  [calendarACLsFetchError_ release];

  [settings_ release];
  [settingsFetchError_ release];

  [editEventTicket_ release];

  [super dealloc];
}

#pragma mark -

- (NSString *)signedInUsername {
  // Get the email address of the signed-in user
  GTMOAuth2Authentication *auth = self.calendarService.authorizer;
  BOOL isSignedIn = auth.canAuthorize;
  if (isSignedIn) {
    return auth.userEmail;
  } else {
    return nil;
  }
}

- (BOOL)isSignedIn {
  NSString *name = [self signedInUsername];
  return (name != nil);
}

#pragma mark IBActions

- (IBAction)signInClicked:(id)sender {
  if (![self isSignedIn]) {
    // Sign in
    [self runSigninThenInvokeSelector:@selector(updateUI)];
  } else {
    // Sign out
    GTLServiceCalendar *service = self.calendarService;

    [GTMOAuth2WindowController removeAuthFromKeychainForName:kKeychainItemName];
    service.authorizer = nil;
    [self updateUI];
  }
}

- (IBAction)getCalendarList:(id)sender {
  if (![self isSignedIn]) {
    [self runSigninThenInvokeSelector:@selector(fetchCalendarList)];
  } else {
    [self fetchCalendarList];
  }
}

- (IBAction)cancelCalendarFetch:(id)sender {
  [self.calendarListTicket cancelTicket];
  self.calendarListTicket = nil;

  [self.editCalendarListTicket cancelTicket];
  self.editCalendarListTicket = nil;

  [self updateUI];
}

- (IBAction)cancelEventsFetch:(id)sender {
  [self.eventsTicket cancelTicket];
  self.eventsTicket = nil;

  [self.editEventTicket cancelTicket];
  self.editEventTicket = nil;

  [self updateUI];
}

- (IBAction)entrySegmentClicked:(id)sender {
  [self updateUI];
}

- (IBAction)addCalendar:(id)sender {
  [self addACalendar];
}

- (IBAction)renameCalendar:(id)sender {
  [self renameSelectedCalendar];
}

- (IBAction)deleteCalendar:(id)sender {
  GTLCalendarCalendarListEntry *calendar = [self selectedCalendarListEntry];
  NSString *title = calendar.summary;

  NSBeginAlertSheet(@"Delete", nil, @"Cancel", nil,
                    [self window], self,
                    @selector(deleteCalendarSheetDidEnd:returnCode:contextInfo:),
                    nil, nil, @"Delete \"%@\"?", title);
}

- (void)deleteCalendarSheetDidEnd:(NSWindow *)sheet
                       returnCode:(int)returnCode
                      contextInfo:(void *)contextInfo {
  if (returnCode == NSAlertDefaultReturn) {
    [self deleteSelectedCalendar];
  }
}

- (IBAction)addEntry:(id)sender {
  NSInteger segment = [entrySegmentedControl_ selectedSegment];
  if (segment == kEventsSegment) {
    [self addAnEvent];
  } else {
    [self addAnACLRule];
  }
}

- (IBAction)editEntry:(id)sender {
  NSInteger segment = [entrySegmentedControl_ selectedSegment];
  if (segment == kEventsSegment) {
    [self editSelectedEvent];
  } else {
    [self editSelectedACLRule];
  }
}

- (IBAction)deleteEntries:(id)sender {
  NSInteger segment = [entrySegmentedControl_ selectedSegment];
  if (segment == kEventsSegment) {
    [self deleteSelectedEvent];
  } else {
    [self deleteSelectedACLRule];
  }
}

- (IBAction)queryTodayClicked:(id)sender {
  [self queryTodaysEvents];
}

- (IBAction)queryFreeBusyClicked:(id)sender {
  [self queryFreeBusy];
}

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://code.google.com/apis/console"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMHTTPFetcher setLoggingEnabled:[sender state]];
}

#pragma mark -

// Get a service object with the current username/password
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information (such as cookies and the "last modified" date for
// fetched data.)

- (GTLServiceCalendar *)calendarService {
  static GTLServiceCalendar *service = nil;

  if (!service) {
    service = [[GTLServiceCalendar alloc] init];

    // Have the service object set tickets to fetch consecutive pages
    // of the feed so we do not need to manually fetch them
    service.shouldFetchNextPages = YES;

    // Have the service object set tickets to retry temporary error conditions
    // automatically
    service.retryEnabled = YES;
  }
  return service;
}

- (GTLCalendarCalendarListEntry *)selectedCalendarListEntry {
  int rowIndex = [calendarTable_ selectedRow];
  if (rowIndex > -1) {
    GTLCalendarCalendarListEntry *item = [self.calendarList itemAtIndex:rowIndex];
    return item;
  }
  return nil;
}

- (GTLCalendarEvent *)selectedEvent {
  if ([entrySegmentedControl_ selectedSegment] == kEventsSegment) {
    int rowIndex = [eventTable_ selectedRow];
    if (rowIndex > -1) {
      GTLCalendarEvent *item = [self.events itemAtIndex:rowIndex];
      return item;
    }
  }
  return nil;
}

- (GTLCalendarAclRule *)selectedACLRule {
  if ([entrySegmentedControl_ selectedSegment] == kAccessControlSegment) {
    int rowIndex = [eventTable_ selectedRow];
    if (rowIndex > -1) {
      GTLCalendarAclRule *item = [self.ACLs itemAtIndex:rowIndex];
      return item;
    }
  }
  return nil;
}

- (GTLCalendarSetting *)selectedSetting {
  if ([entrySegmentedControl_ selectedSegment] == kSettingsSegment) {
    int rowIndex = [eventTable_ selectedRow];
    if (rowIndex > -1) {
      GTLCalendarSetting *item = [self.settings itemAtIndex:rowIndex];
      return item;
    }
  }
  return nil;
}

#pragma mark Fetch Calendar List

- (void)fetchCalendarList {
  self.calendarList = nil;
  self.calendarListFetchError = nil;

  GTLServiceCalendar *service = self.calendarService;


  GTLQueryCalendar *query = [GTLQueryCalendar queryForCalendarListList];

  BOOL shouldFetchedOwned = ([calendarSegmentedControl_ selectedSegment] == 1);
  if (shouldFetchedOwned) {
    query.minAccessRole = kGTLCalendarMinAccessRoleOwner;
  }

  self.calendarListTicket = [service executeQuery:query
                                completionHandler:^(GTLServiceTicket *ticket,
                                                    id calendarList, NSError *error) {
                                  // Callback
                                  self.calendarList = calendarList;
                                  self.calendarListFetchError = error;
                                  self.calendarListTicket = nil;

                                  [self updateUI];
                                }];
  [self updateUI];
}

#pragma mark Fetch Selected Calendar

- (void)fetchSelectedCalendar {
  self.events = nil;
  self.eventsFetchError = nil;

  self.ACLs = nil;
  self.ACLsFetchError = nil;

  self.settings = nil;
  self.settingsFetchError = nil;

  GTLServiceCalendar *service = self.calendarService;

  GTLCalendarCalendarListEntry *selectedCalendar = [self selectedCalendarListEntry];
  if (selectedCalendar) {
    NSString *calendarID = selectedCalendar.identifier;

    // We will fetch the events for this calendar, the ACLs for this calendar,
    // and the user's settings, together in a single batch.
    GTLBatchQuery *batch = [GTLBatchQuery batchQuery];

    GTLQueryCalendar *eventsQuery = [GTLQueryCalendar queryForEventsListWithCalendarId:calendarID];
    eventsQuery.completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
      self.events = object;
      self.eventsFetchError = error;
    };
    [batch addQuery:eventsQuery];

    GTLQueryCalendar *aclQuery = [GTLQueryCalendar queryForAclListWithCalendarId:calendarID];
    aclQuery.completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
      self.ACLs = object;
      self.ACLsFetchError = error;
    };
    [batch addQuery:aclQuery];

    GTLQueryCalendar *settingsQuery = [GTLQueryCalendar queryForSettingsList];
    settingsQuery.completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
      self.settings = object;
      self.settingsFetchError = error;
    };
    [batch addQuery:settingsQuery];

    self.eventsTicket = [service executeQuery:batch
                            completionHandler:^(GTLServiceTicket *ticket,
                                                id object, NSError *error) {
                              // Callback
                              //
                              // For batch queries with successful execution,
                              // the result is a GTLBatchResult object
                              //
                              // At this point, the query completion blocks
                              // have already been called
                              self.eventsTicket = nil;

                              [self updateUI];
                            }];
    [self updateUI];
  }
}

#pragma mark Add, Rename, and Delete a Calendar

- (void)addACalendar {
  NSString *newCalendarName = [calendarNameField_ stringValue];

  GTLServiceCalendar *service = self.calendarService;

  GTLCalendarCalendar *newEntry = [GTLCalendarCalendar object];
  newEntry.summary = newCalendarName;
  newEntry.timeZone = [[NSTimeZone localTimeZone] name];

  GTLQueryCalendar *query = [GTLQueryCalendar queryForCalendarsInsertWithObject:newEntry];
  self.editCalendarListTicket = [service executeQuery:query
                                    completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
                                      // Callback
                                      self.editCalendarListTicket = nil;
                                      if (error == nil) {
                                        [calendarNameField_ setStringValue:@""];
                                        [self fetchCalendarList];
                                      } else {
                                        [self displayAlert:@"Add failed"
                                                    format:@"Calendar add failed: %@", error];
                                      }
                                      [self updateUI];
                                    }];
  [self updateUI];
}

- (void)renameSelectedCalendar {
  GTLCalendarCalendarListEntry *selectedCalendarListEntry = [self selectedCalendarListEntry];
  if (selectedCalendarListEntry) {
    GTLServiceCalendar *service = self.calendarService;

    NSString *newCalendarName = [calendarNameField_ stringValue];

    // Modify a copy of the selected calendar, not the existing one in memory
    GTLCalendarCalendar *patchObject = [GTLCalendarCalendar object];
    patchObject.summary = newCalendarName;

    NSString *calendarID = selectedCalendarListEntry.identifier;
    GTLQueryCalendar *query = [GTLQueryCalendar queryForCalendarsPatchWithObject:patchObject
                                                                      calendarId:calendarID];
    self.editCalendarListTicket = [service executeQuery:query
                                      completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
                                        // Callback
                                        self.editCalendarListTicket = nil;
                                        if (error == nil) {
                                          GTLCalendarCalendar *calendar = object;

                                          [self displayAlert:@"Renamed"
                                                      format:@"Renamed calendar \"%@\" as \"%@\"",
                                           selectedCalendarListEntry.summary,
                                           calendar.summary];

                                          [calendarNameField_ setStringValue:@""];

                                          [self fetchCalendarList];
                                        } else {
                                          [self displayAlert:@"Update failed"
                                                      format:@"Calendar update failed: %@", error];
                                        }
                                        [self updateUI];
                                      }];
    [self updateUI];
  }
}

- (void)deleteSelectedCalendar {
  GTLCalendarCalendarListEntry *selectedCalendarListEntry = [self selectedCalendarListEntry];
  if (selectedCalendarListEntry) {
    GTLServiceCalendar *service = self.calendarService;

    NSString *calendarID = selectedCalendarListEntry.identifier;
    GTLQueryCalendar *query = [GTLQueryCalendar queryForCalendarsDeleteWithCalendarId:calendarID];

    self.editCalendarListTicket = [service executeQuery:query
                                      completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
                                        // Callback
                                        self.editCalendarListTicket = nil;
                                        if (error == nil) {
                                          [self displayAlert:@"Deleted"
                                                      format:@"Deleted \"%@\"",
                                           selectedCalendarListEntry.summary];
                                          [self fetchCalendarList];
                                          [self updateUI];
                                        } else {
                                          [self displayAlert:@"Delete failed"
                                                      format:@"Delete failed: %@", error];
                                        }
                                      }];
  }
}

#pragma mark Add, Edit, and Delete an Event

- (void)addAnEvent {
  // Make a new event, and show it to the user to edit
  GTLCalendarEvent *newEvent = [GTLCalendarEvent object];
  newEvent.summary = @"Sample Added Event";
  newEvent.descriptionProperty = @"Description of sample added event";

  // We'll set the start time to now, and the end time to an hour from now,
  // with a reminder 10 minutes before
  NSDate *anHourFromNow = [NSDate dateWithTimeIntervalSinceNow:60*60];
  GTLDateTime *startDateTime = [GTLDateTime dateTimeWithDate:[NSDate date]
                                                    timeZone:[NSTimeZone systemTimeZone]];
  GTLDateTime *endDateTime = [GTLDateTime dateTimeWithDate:anHourFromNow
                                                  timeZone:[NSTimeZone systemTimeZone]];

  newEvent.start = [GTLCalendarEventDateTime object];
  newEvent.start.dateTime = startDateTime;

  newEvent.end = [GTLCalendarEventDateTime object];
  newEvent.end.dateTime = endDateTime;

  GTLCalendarEventReminder *reminder = [GTLCalendarEventReminder object];
  reminder.minutes = [NSNumber numberWithInteger:10];
  reminder.method = @"email";

  newEvent.reminders = [GTLCalendarEventReminders object];
  newEvent.reminders.overrides = [NSArray arrayWithObject:reminder];
  newEvent.reminders.useDefault = [NSNumber numberWithBool:NO];

  // Display the event edit dialog
  EditEventWindowController *controller = [[[EditEventWindowController alloc] init] autorelease];
  [controller runModalForWindow:[self window]
                          event:newEvent
              completionHandler:^(NSInteger returnCode, GTLCalendarEvent *event) {
                // Callback
                if (returnCode == NSOKButton) {
                  [self addEvent:event];
                }
              }];
}

- (void)addEvent:(GTLCalendarEvent *)event {
  GTLServiceCalendar *service = self.calendarService;
  GTLCalendarCalendarListEntry *selectedCalendar = [self selectedCalendarListEntry];
  NSString *calendarID = selectedCalendar.identifier;

  GTLQueryCalendar *query = [GTLQueryCalendar queryForEventsInsertWithObject:event
                                                                  calendarId:calendarID];
  self.editEventTicket = [service executeQuery:query
                             completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
                               // Callback
                               self.editEventTicket = nil;
                               if (error == nil) {
                                 GTLCalendarEvent *event = object;
                                 [self displayAlert:@"Event Added"
                                             format:@"Added event \"%@\"",
                                  event.summary];
                                 [self fetchSelectedCalendar];
                               } else {
                                 [self displayAlert:@"Add failed"
                                             format:@"Event add failed: %@", error];
                               }
                               [self updateUI];
                             }];
  [self updateUI];
}

- (void)editSelectedEvent {
  // Show the selected event to the user to edit
  GTLCalendarEvent *eventToEdit = [self selectedEvent];
  if (eventToEdit) {
    EditEventWindowController *controller = [[[EditEventWindowController alloc] init] autorelease];
    [controller runModalForWindow:[self window]
                            event:eventToEdit
                completionHandler:^(NSInteger returnCode, GTLCalendarEvent *event) {
                  // Callback
                  if (returnCode == NSOKButton) {
                    [self editSelectedEventWithEvent:event];
                  }
                }];
  }
}

- (void)editSelectedEventWithEvent:(GTLCalendarEvent *)revisedEvent {
  GTLServiceCalendar *service = self.calendarService;
  GTLCalendarCalendarListEntry *selectedCalendarListEntry = [self selectedCalendarListEntry];

  GTLCalendarEvent *originalEvent = [self selectedEvent];
  GTLCalendarEvent *patchEvent = [revisedEvent patchObjectFromOriginal:originalEvent];
  if (patchEvent) {
    NSString *calendarID = selectedCalendarListEntry.identifier;
    NSString *eventID = originalEvent.identifier;
    GTLQueryCalendar *query = [GTLQueryCalendar queryForEventsPatchWithObject:patchEvent
                                                                   calendarId:calendarID
                                                                      eventId:eventID];
    self.editEventTicket = [service executeQuery:query
                               completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
                                 // Callback
                                 self.editEventTicket = nil;
                                 if (error == nil) {
                                   GTLCalendarEvent *event = object;
                                   [self displayAlert:@"Event Updated"
                                               format:@"Patched event \"%@\"",
                                    event.summary];
                                   [self fetchSelectedCalendar];
                                 } else {
                                   [self displayAlert:@"Update failed"
                                               format:@"Event patch failed: %@", error];
                                 }
                                 [self updateUI];
                               }];
    [self updateUI];
  }
}

- (void)deleteSelectedEvent {
  GTLServiceCalendar *service = self.calendarService;

  GTLCalendarCalendarListEntry *selectedCalendarListEntry = [self selectedCalendarListEntry];
  NSString *calendarID = selectedCalendarListEntry.identifier;

  GTLCalendarEvent *selectedEvent = [self selectedEvent];
  NSString *eventID = selectedEvent.identifier;

  if (calendarID && eventID) {
    GTLQueryCalendar *query = [GTLQueryCalendar queryForEventsDeleteWithCalendarId:calendarID
                                                                           eventId:eventID];
    self.editEventTicket = [service executeQuery:query
                                      completionHandler:^(GTLServiceTicket *ticket, id nilObject, NSError *error) {
                                        // Callback
                                        self.editEventTicket = nil;
                                        if (error == nil) {
                                          [self displayAlert:@"Event deleted"
                                                      format:@"Deleted \"%@\"",
                                           selectedEvent.summary];
                                          [self fetchSelectedCalendar];
                                        } else {
                                          [self displayAlert:@"Delete failed"
                                                      format:@"Event delete failed: %@", error];
                                        }
                                        [self updateUI];
                                      }];
    [self updateUI];
  }
}

#pragma mark Query Events

// Utility routine to make a GTLDateTime object for sometime today
- (GTLDateTime *)dateTimeForTodayAtHour:(int)hour
                                 minute:(int)minute
                                 second:(int)second {

  int const kComponentBits = (NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit
                              | NSHourCalendarUnit | NSMinuteCalendarUnit | NSSecondCalendarUnit);

  NSCalendar *cal = [[[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar] autorelease];

  NSDateComponents *dateComponents = [cal components:kComponentBits
                                            fromDate:[NSDate date]];
  [dateComponents setHour:hour];
  [dateComponents setMinute:minute];
  [dateComponents setSecond:second];
  [dateComponents setTimeZone:[NSTimeZone localTimeZone]];

  GTLDateTime *dateTime = [GTLDateTime dateTimeWithDateComponents:dateComponents];
  return dateTime;
}

- (void)queryTodaysEvents {
  GTLCalendarCalendarListEntry *selectedCalendar = [self selectedCalendarListEntry];
  if (selectedCalendar) {
    NSString *calendarID = selectedCalendar.identifier;

    GTLDateTime *startOfDay = [self dateTimeForTodayAtHour:0 minute:0 second:0];
    GTLDateTime *endOfDay = [self dateTimeForTodayAtHour:23 minute:59 second:59];

    GTLQueryCalendar *query = [GTLQueryCalendar queryForEventsListWithCalendarId:calendarID];
    query.maxResults = 10;
    query.timeMin = startOfDay;
    query.timeMax = endOfDay;

    GTLServiceCalendar *service = self.calendarService;
    GTLServiceTicket *ticket = [service executeQuery:query
                                   completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
       // Callback
       if (error == nil) {
         // Make a comma-separated list of event titles
         GTLCalendarEvents *events = object;

         NSArray *titles = [events.items valueForKey:@"summary"];
         NSString *joined = [titles componentsJoinedByString:@", "];
         [self displayAlert:@"Today's Events"
                     format:@"Query result: %@", joined];
       } else {
         [self displayAlert:@"Query failed"
                     format:@"%@", error];
       }
       [self updateUI];
     }];

    // The service is set to fetch all pages, but for querying today's events,
    // we only want the first 10 results
    ticket.shouldFetchNextPages = NO;
  }
}

- (void)queryFreeBusy {
  GTLCalendarCalendarListEntry *selectedCalendar = [self selectedCalendarListEntry];
  if (selectedCalendar) {
    NSString *calendarID = selectedCalendar.identifier;

    GTLDateTime *startOfDay = [self dateTimeForTodayAtHour:0 minute:0 second:0];
    GTLDateTime *endOfDay = [self dateTimeForTodayAtHour:23 minute:59 second:59];

    GTLCalendarFreeBusyRequestItem *requestItem = [GTLCalendarFreeBusyRequestItem object];
    requestItem.identifier = calendarID;

    GTLQueryCalendar *query = [GTLQueryCalendar queryForFreebusyQuery];
    query.items = [NSArray arrayWithObject:requestItem];
    query.maxResults = 10;
    query.timeMin = startOfDay;
    query.timeMax = endOfDay;

    GTLServiceCalendar *service = self.calendarService;
    GTLServiceTicket *ticket = [service executeQuery:query
                                   completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
      // Callback
      if (error == nil) {
        // Display a list of busy periods for the calendar account
        NSMutableString *displayStr = [NSMutableString string];

        GTLCalendarFreeBusyResponse *response = object;
        GTLCalendarFreeBusyResponseCalendars *responseCals = response.calendars;
        NSDictionary *props = responseCals.additionalProperties;

        // Step through the free-busy calendar IDs, and display each calendar
        // name (the summary field) and free/busy times
        for (NSString *calendarID in props) {
          GTLCalendarCalendarListEntry *calendar;
          calendar = [GTLUtilities firstObjectFromArray:self.calendarList.items
                                              withValue:calendarID
                                             forKeyPath:@"identifier"];
          [displayStr appendFormat:@"%@: ", calendar.summary];

          GTLCalendarFreeBusyCalendar *calResponse = [props objectForKey:calendarID];
          NSArray *busyArray = calResponse.busy;
          for (GTLCalendarTimePeriod *period in busyArray) {
            GTLDateTime *startTime = period.start;
            GTLDateTime *endTime = period.end;
            NSString *startStr = [NSDateFormatter localizedStringFromDate:startTime.date
                                                                dateStyle:NSDateFormatterNoStyle
                                                                timeStyle:NSDateFormatterShortStyle];
            NSString *endStr = [NSDateFormatter localizedStringFromDate:endTime.date
                                                              dateStyle:NSDateFormatterNoStyle
                                                              timeStyle:NSDateFormatterShortStyle];
            [displayStr appendFormat:@"(%@-%@) ", startStr, endStr];
          }
        }

        [self displayAlert:@"Today's Busy Periods"
                    format:@"%@", displayStr];
      } else {
        [self displayAlert:@"Query failed"
                    format:@"%@", error];
      }
      [self updateUI];
    }];

    // The service is set to fetch all pages, but for querying today's busy
    // periods, we only want the first 10 results
    ticket.shouldFetchNextPages = NO;
  }
}

#pragma mark Add, Edit, and Delete an ACL Rule

- (void)addAnACLRule {
  // Make a new ACL rule
  GTLCalendarAclRuleScope *scope = [GTLCalendarAclRuleScope object];
  scope.type = @"user";
  scope.value = @"mark.twain@example.com";

  GTLCalendarAclRule *newRule = [GTLCalendarAclRule object];
  newRule.role = @"reader";
  newRule.scope = scope;

  // Display the ACL edit dialog
  EditACLWindowController *controller = [[[EditACLWindowController alloc] init] autorelease];
  [controller runModalForWindow:[self window]
                        ACLRule:newRule
              completionHandler:^(NSInteger returnCode, GTLCalendarAclRule *rule) {
                // Callback
                if (returnCode == NSOKButton) {
                  [self addACLRule:rule];
                }
              }];
}

- (void)addACLRule:(GTLCalendarAclRule *)aclRule {
  GTLServiceCalendar *service = self.calendarService;
  GTLCalendarCalendarListEntry *selectedCalendar = [self selectedCalendarListEntry];
  NSString *calendarID = selectedCalendar.identifier;

  GTLQueryCalendar *query = [GTLQueryCalendar queryForAclInsertWithObject:aclRule
                                                               calendarId:calendarID];
  self.editEventTicket = [service executeQuery:query
                             completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
                               // Callback
                               self.editEventTicket = nil;
                               if (error == nil) {
                                 GTLCalendarAclRule *rule = object;
                                 [self displayAlert:@"Added"
                                             format:@"Added ACL rule: %@",
                                  [self displayStringForACLRule:rule]];
                                 [self fetchSelectedCalendar];
                               } else {
                                 [self displayAlert:@"Add failed"
                                             format:@"ACL rule add failed: %@", error];
                               }
                               [self updateUI];
                             }];
  [self updateUI];
}

- (void)editSelectedACLRule {
  // Show the selected rule to the user to edit
  GTLCalendarAclRule *ruleToEdit = [self selectedACLRule];
  if (ruleToEdit) {
    EditACLWindowController *controller = [[[EditACLWindowController alloc] init] autorelease];
    [controller runModalForWindow:[self window]
                          ACLRule:ruleToEdit
                completionHandler:^(NSInteger returnCode, GTLCalendarAclRule *rule) {
                  // Callback
                  if (returnCode == NSOKButton) {
                    [self editSelectedACLRuleWithRule:rule];
                  }
                }];
  }
}

- (void)editSelectedACLRuleWithRule:(GTLCalendarAclRule *)revisedRule {
  GTLServiceCalendar *service = self.calendarService;
  GTLCalendarCalendarListEntry *selectedCalendarListEntry = [self selectedCalendarListEntry];

  // We create an object reflecting just the changes from the original rule
  // needing to be patched
  GTLCalendarAclRule *originalRule = [self selectedACLRule];
  GTLCalendarAclRule *patchRule = [revisedRule patchObjectFromOriginal:originalRule];
  if (patchRule) {
    // If patchRule is non-nil, there are some fields to be changed
    NSString *calendarID = selectedCalendarListEntry.identifier;
    NSString *ruleID = originalRule.identifier;
    GTLQueryCalendar *query = [GTLQueryCalendar queryForAclPatchWithObject:patchRule
                                                                calendarId:calendarID
                                                                    ruleId:ruleID];
    self.editEventTicket = [service executeQuery:query
                               completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
                                 // Callback
                                 self.editEventTicket = nil;
                                 if (error == nil) {
                                   GTLCalendarAclRule *rule = object;
                                   [self displayAlert:@"Rule Updated"
                                               format:@"Patched rule \"%@\"",
                                    [self displayStringForACLRule:rule]];
                                   [self fetchSelectedCalendar];
                                 } else {
                                   [self displayAlert:@"Update Failed"
                                               format:@"Rule patch failed: %@", error];
                                 }
                                 [self updateUI];
                               }];
    [self updateUI];
  }
}

- (void)deleteSelectedACLRule {
  GTLServiceCalendar *service = self.calendarService;

  GTLCalendarCalendarListEntry *selectedCalendarListEntry = [self selectedCalendarListEntry];
  NSString *calendarID = selectedCalendarListEntry.identifier;

  GTLCalendarAclRule *selectedACLRule = [self selectedACLRule];
  NSString *ruleID = selectedACLRule.identifier;

  if (calendarID && ruleID) {
    GTLQueryCalendar *query = [GTLQueryCalendar queryForAclDeleteWithCalendarId:calendarID
                                                                         ruleId:ruleID];
    self.editEventTicket = [service executeQuery:query
                               completionHandler:^(GTLServiceTicket *ticket, id nilObject, NSError *error) {
                                 // Callback
                                 self.editEventTicket = nil;
                                 if (error == nil) {
                                   [self displayAlert:@"ACL Rule Deleted"
                                               format:@"Deleted \"%@\"",
                                    [self displayStringForACLRule:selectedACLRule]];
                                   [self fetchSelectedCalendar];
                                 } else {
                                   [self displayAlert:@"Delete Failed"
                                               format:@"Rule delete failed: %@", error];
                                 }
                                 [self updateUI];
                               }];
    [self updateUI];
  }
}

#pragma mark Sign In

- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel {
  // Applications should have client ID and client secret strings
  // hardcoded into the source, but the sample application asks the
  // developer for the strings
  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  if ([clientID length] == 0 || [clientSecret length] == 0) {
    // Remind the developer that client ID and client secret are needed
    [clientIDButton_ performSelector:@selector(performClick:)
                          withObject:self
                          afterDelay:0.5];
    return;
  }

  // Show the OAuth 2 sign-in controller
  NSBundle *frameworkBundle = [NSBundle bundleForClass:[GTMOAuth2WindowController class]];
  GTMOAuth2WindowController *windowController;
  windowController = [GTMOAuth2WindowController controllerWithScope:kGTLAuthScopeCalendar
                                                           clientID:clientID
                                                       clientSecret:clientSecret
                                                   keychainItemName:kKeychainItemName
                                                     resourceBundle:frameworkBundle];

  [windowController signInSheetModalForWindow:[self window]
                            completionHandler:^(GTMOAuth2Authentication *auth,
                                                NSError *error) {
                              // Callback
                              if (error == nil) {
                                self.calendarService.authorizer = auth;
                                if (signInDoneSel) {
                                  [self performSelector:signInDoneSel];
                                }
                              } else {
                                self.calendarListFetchError = error;
                                [self updateUI];
                              }
                            }];
}

#pragma mark UI

- (NSString *)displayStringForACLRule:(GTLCalendarAclRule *)rule  {
  // Make a concise, readable string showing the scope type, scope value,
  // and role value for an ACL entry, like:
  //
  //    scope: user "fred@flintstone.com"  role:owner

  NSMutableString *resultStr = [NSMutableString string];

  GTLCalendarAclRuleScope *scope = rule.scope;
  if (scope) {
    NSString *type = (scope.type ? scope.type : @"");
    NSString *value = @"";
    if (scope.value) {
      value = [NSString stringWithFormat:@"\"%@\"", scope.value];
    }
    [resultStr appendFormat:@"scope: %@ %@  ", type, value];
  }

  NSString *role = rule.role;
  if (role) {
    [resultStr appendFormat:@"role: %@", role];
  }
  return resultStr;
}

- (void)updateUI {
  BOOL isSignedIn = [self isSignedIn];
  NSString *username = [self signedInUsername];
  [signedInButton_ setTitle:(isSignedIn ? @"Sign Out" : @"Sign In")];
  [signedInField_ setStringValue:(isSignedIn ? username : @"No")];

  //
  // CalendarList table
  //
  [calendarTable_ reloadData];

  if (self.calendarListTicket != nil || self.editCalendarListTicket != nil) {
    [calendarProgressIndicator_ startAnimation:self];
  } else {
    [calendarProgressIndicator_ stopAnimation:self];
  }

  // Get the description of the selected item, or the feed fetch error
  NSString *resultStr = @"";

  if (self.calendarListFetchError) {
    // Display the error
    resultStr = [self.calendarListFetchError description];

    // Also display any server data present
    NSData *errData = [[self.calendarListFetchError userInfo] objectForKey:kGTMHTTPFetcherStatusDataKey];
    if (errData) {
      NSString *dataStr = [[[NSString alloc] initWithData:errData
                                                 encoding:NSUTF8StringEncoding] autorelease];
      resultStr = [resultStr stringByAppendingFormat:@"\n%@", dataStr];
    }
  } else {
    // Display the selected item
    GTLCalendarCalendarListEntry *item = [self selectedCalendarListEntry];
    if (item) {
      resultStr = [item description];
    }
  }
  [calendarResultTextField_ setString:resultStr];

  //
  // Events list
  //
  [eventTable_ reloadData];

  if (self.eventsTicket != nil || self.editEventTicket != nil) {
    [eventProgressIndicator_ startAnimation:self];
  } else {
    [eventProgressIndicator_ stopAnimation:self];
  }

  // Get the description of the selected item, or the feed fetch error
  resultStr = @"";
  switch ([entrySegmentedControl_ selectedSegment]) {
    case kEventsSegment:
      if (self.eventsFetchError) {
        resultStr = [self.eventsFetchError description];
      } else {
        GTLCalendarEvent *item = [self selectedEvent];
        if (item) {
          resultStr = [item description];
        }
      }
      break;
    case kAccessControlSegment:
      if (self.ACLsFetchError) {
        resultStr = [self.ACLsFetchError description];
      } else {
        GTLCalendarAclRule *item = [self selectedACLRule];
        if (item) {
          resultStr = [item description];
        }
      }
      break;
    case kSettingsSegment:
      if (self.settingsFetchError) {
        resultStr = [self.settingsFetchError description];
      } else {
        GTLCalendarSetting *item = [self selectedSetting];
        if (item) {
          resultStr = [item description];
        }
      }
      break;
    default: break;
  }

  [eventResultTextField_ setString:resultStr];

  // Enable buttons
  BOOL isFetchingCalendars = (self.calendarListTicket != nil);
  BOOL isEditingCalendar = (self.editCalendarListTicket != nil);
  [calendarCancelButton_ setEnabled:(isFetchingCalendars || isEditingCalendar)];

  BOOL isFetchingEvents = (self.eventsTicket != nil);
  BOOL isEditingEvent = (self.editEventTicket != nil);
  [eventCancelButton_ setEnabled:(isFetchingEvents || isEditingEvent)];

  BOOL isCalendarSelected = ([self selectedCalendarListEntry] != nil);
  BOOL hasNewName = ([[calendarNameField_ stringValue] length] > 0);
  [addCalendarButton_ setEnabled:(isSignedIn && hasNewName)];
  [renameCalendarButton_ setEnabled:(isSignedIn && isCalendarSelected && hasNewName)];
  [deleteCalendarButton_ setEnabled:(isSignedIn && isCalendarSelected)];

  NSInteger segment = [entrySegmentedControl_ selectedSegment];
  BOOL isEventsSegmentSelected = (segment == kEventsSegment);
  BOOL isACLsSegmentSelected = (segment == kAccessControlSegment);

  if (isEventsSegmentSelected) {
    // Events
    BOOL isEventSelected = ([self selectedEvent] != nil);

    [addEntryButton_ setEnabled:isCalendarSelected];
    [editEntryButton_ setEnabled:isEventSelected];
    [deleteEntriesButton_ setEnabled:isEventSelected];
  } else if (isACLsSegmentSelected) {
    // ACLs
    BOOL isACLSelected = ([self selectedACLRule] != nil);

    [addEntryButton_ setEnabled:isCalendarSelected];
    [editEntryButton_ setEnabled:isACLSelected];
    [deleteEntriesButton_ setEnabled:isACLSelected];
  } else {
    // Settings
    [addEntryButton_ setEnabled:NO];
    [editEntryButton_ setEnabled:NO];
    [deleteEntriesButton_ setEnabled:NO];
  }

  [queryTodaysEventsButton_ setEnabled:isCalendarSelected];
  [queryFreeBusyButton_ setEnabled:isCalendarSelected];

  // Show or hide the text indicating that the client ID or client secret are
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

#pragma mark Client ID Sheet

// Client ID and Client Secret Sheet
//
// Sample apps need this sheet to ask for the client ID and client secret
// strings
//
// Your application will just hardcode the client ID and client secret strings
// into the source rather than ask the user for them.
//
// The string values are obtained from the API Console,
// https://code.google.com/apis/console

- (IBAction)clientIDClicked:(id)sender {
  // Show the sheet for developers to enter their client ID and client secret
  [NSApp beginSheet:clientIDSheet_
     modalForWindow:[self window]
      modalDelegate:self
     didEndSelector:@selector(clientIDSheetDidEnd:returnCode:contextInfo:)
        contextInfo:NULL];
}

- (IBAction)clientIDDoneClicked:(id)sender {
  [NSApp endSheet:clientIDSheet_ returnCode:NSOKButton];
}

- (void)clientIDSheetDidEnd:(NSWindow *)sheet returnCode:(NSInteger)returnCode contextInfo:(void *)contextInfo {
  [sheet orderOut:self];
  [self updateUI];
}

#pragma mark Text field delegate methods

- (void)controlTextDidChange:(NSNotification *)note {
  [self updateUI];  // enable and disable buttons
}

#pragma mark TableView delegate and data source methods

- (void)tableViewSelectionDidChange:(NSNotification *)notification {
  if ([notification object] == calendarTable_) {
    // The calendar list selection changed
    [self fetchSelectedCalendar];
  } else {
    // The event list selection changed
    [self updateUI];
  }
}

// Table view data source methods
- (int)numberOfRowsInTableView:(NSTableView *)tableView {
  if (tableView == calendarTable_) {
    return [self.calendarList.items count];
  } else {
    switch ([entrySegmentedControl_ selectedSegment]) {
      case kEventsSegment:        return [self.events.items count];
      case kAccessControlSegment: return [self.ACLs.items count];
      case kSettingsSegment:      return [self.settings.items count];
      default: return 0;
    }
  }
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(int)row {
  if (tableView == calendarTable_) {
    // Calendar table
    GTLCalendarCalendar *calendar = [self.calendarList itemAtIndex:row];
    NSString *str = calendar.summary;
    return str;
  } else {
    // Events/ACLs/Settings table
    switch ([entrySegmentedControl_ selectedSegment]) {
      case kEventsSegment: {
        GTLCalendarEvent *event = [self.events itemAtIndex:row];
        NSString *str = event.summary;
        return str;
      }
      case kAccessControlSegment:  {
        GTLCalendarAclRule *rule = [self.ACLs itemAtIndex:row];
        NSString *str = [self displayStringForACLRule:rule];
        return str;
      }
      case kSettingsSegment: {
        GTLCalendarSetting *setting = [self.settings itemAtIndex:row];
        NSString *str = [NSString stringWithFormat:@"%@: %@",
                         setting.identifier, setting.value];
        return str;
      }
      default:
        return nil;
    }
  }
}

@end

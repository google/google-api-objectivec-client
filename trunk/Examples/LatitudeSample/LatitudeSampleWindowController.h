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
//  LatitudeSampleWindowController.h
//

#import <Cocoa/Cocoa.h>
#import <CoreLocation/CoreLocation.h>

#import "GTLLatitude.h"

@interface LatitudeSampleWindowController : NSWindowController {
 @private
  IBOutlet NSTextField *signedInField_;
  IBOutlet NSButton *signedInButton_;

  IBOutlet NSMatrix *timeMatrix_;
  IBOutlet NSMatrix *granularityMatrix_;

  IBOutlet NSTableView *locationsTable_;
  IBOutlet NSProgressIndicator *locationsProgressIndicator_;
  IBOutlet NSTextView *locationsResultTextField_;
  IBOutlet NSButton *locationsCancelButton_;

  IBOutlet NSTextField *latitudeField_;
  IBOutlet NSTextField *longitudeField_;
  IBOutlet NSDatePicker *datePicker_;

  IBOutlet NSButton *addLocationButton_;
  IBOutlet NSButton *updateLocationButton_;
  IBOutlet NSButton *deleteLocationButton_;

  // client ID sheet
  IBOutlet NSButton *clientIDButton_;
  IBOutlet NSTextField *clientIDRequiredTextField_;
  IBOutlet NSWindow *clientIDSheet_;
  IBOutlet NSTextField *clientIDField_;
  IBOutlet NSTextField *clientSecretField_;

  GTLLatitudeLocationFeed *locationsFeed_;
  GTLServiceTicket *locationsTicket_;
  NSError *locationsFetchError_;

  GTLServiceTicket *editLocationTicket_;
}

@property (retain, nonatomic) GTLLatitudeLocationFeed *locationsFeed;
@property (retain, nonatomic) GTLServiceTicket *locationsTicket;
@property (retain, nonatomic) NSError *locationsFetchError;

@property (retain, nonatomic) GTLServiceTicket *editLocationTicket;

+ (LatitudeSampleWindowController *)sharedWindowController;

- (IBAction)signInClicked:(id)sender;

- (IBAction)getLocationsClicked:(id)sender;
- (IBAction)cancelLocationsFetchClicked:(id)sender;
- (IBAction)locationRadioButtonClicked:(id)sender;

- (IBAction)addLocationClicked:(id)sender;
- (IBAction)updateLocationClicked:(id)sender;
- (IBAction)deleteLocationClicked:(id)sender;

- (IBAction)clientIDClicked:(id)sender;
- (IBAction)clientIDDoneClicked:(id)sender;

- (IBAction)APIConsoleClicked:(id)sender;
- (IBAction)loggingCheckboxClicked:(id)sender;
@end

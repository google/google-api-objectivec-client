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
//  CalendarSampleWindowController.h
//

#import <Cocoa/Cocoa.h>

#import "GTLCalendar.h"
#import "GTL/GTMOAuth2WindowController.h"

@interface CalendarSampleWindowController : NSWindowController {
 @private
  IBOutlet NSTextField *signedInField_;
  IBOutlet NSButton *signedInButton_;

  IBOutlet NSTableView *calendarTable_;
  IBOutlet NSProgressIndicator *calendarProgressIndicator_;
  IBOutlet NSTextView *calendarResultTextField_;
  IBOutlet NSButton *calendarCancelButton_;

  IBOutlet NSSegmentedControl *calendarSegmentedControl_;
  IBOutlet NSButton *addCalendarButton_;
  IBOutlet NSButton *renameCalendarButton_;
  IBOutlet NSButton *deleteCalendarButton_;
  IBOutlet NSTextField *calendarNameField_;

  IBOutlet NSTableView *eventTable_;
  IBOutlet NSProgressIndicator *eventProgressIndicator_;
  IBOutlet NSTextView *eventResultTextField_;
  IBOutlet NSButton *eventCancelButton_;

  IBOutlet NSButton *addEntryButton_;
  IBOutlet NSButton *editEntryButton_;
  IBOutlet NSButton *deleteEntriesButton_;
  IBOutlet NSButton *queryTodaysEventsButton_;
  IBOutlet NSButton *queryFreeBusyButton_;

  IBOutlet NSSegmentedControl *entrySegmentedControl_;

  IBOutlet NSButton *clientIDButton_;
  IBOutlet NSTextField *clientIDRequiredTextField_;
  IBOutlet NSWindow *clientIDSheet_;
  IBOutlet NSTextField *clientIDField_;
  IBOutlet NSTextField *clientSecretField_;

  GTLCalendarCalendarList *calendarList_;
  GTLServiceTicket *calendarListTicket_;
  NSError *calendarFetchError_;

  GTLServiceTicket *editCalendarListTicket_;

  GTLCalendarEvents *events_;
  GTLServiceTicket *eventTicket_;
  NSError *eventsFetchError_;

  GTLServiceTicket *editEventTicket_;

  GTLCalendarAcl *calendarACLs_;
  NSError *calendarACLsFetchError_;

  GTLCalendarSettings *settings_;
  NSError *settingsFetchError_;
}

+ (CalendarSampleWindowController *)sharedWindowController;

- (IBAction)signInClicked:(id)sender;

- (IBAction)getCalendarList:(id)sender;

- (IBAction)cancelCalendarFetch:(id)sender;
- (IBAction)cancelEventsFetch:(id)sender;

- (IBAction)addCalendar:(id)sender;
- (IBAction)renameCalendar:(id)sender;
- (IBAction)deleteCalendar:(id)sender;

- (IBAction)entrySegmentClicked:(id)sender;

- (IBAction)addEntry:(id)sender;
- (IBAction)editEntry:(id)sender;
- (IBAction)deleteEntries:(id)sender;

- (IBAction)queryTodayClicked:(id)sender;
- (IBAction)queryFreeBusyClicked:(id)sender;

- (IBAction)loggingCheckboxClicked:(id)sender;

// Client ID sheet
- (IBAction)clientIDClicked:(id)sender;
- (IBAction)clientIDDoneClicked:(id)sender;
- (IBAction)APIConsoleClicked:(id)sender;

@end

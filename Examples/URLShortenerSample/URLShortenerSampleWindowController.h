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
//  URLShortenerSampleWindowController.h
//

#import <Cocoa/Cocoa.h>

#import "GTLUrlshortener.h"

@interface URLShortenerSampleWindowController : NSWindowController {
 @private
  // IBOutlets - main window
  IBOutlet NSTextField *signedInField_;
  IBOutlet NSButton *signedInButton_;

  IBOutlet NSTableView *historyTable_;
  IBOutlet NSProgressIndicator *historyProgressIndicator_;
  IBOutlet NSTextView *historyResultTextField_;
  IBOutlet NSButton *historyCancelButton_;

  IBOutlet NSSegmentedControl *analyticsSegmentedControl_;
  IBOutlet NSTableView *analyticsTable_;
  IBOutlet NSProgressIndicator *analyticsProgressIndicator_;
  IBOutlet NSButton *analyticsCancelButton_;
  IBOutlet NSTextField *shortURLClicksField_;
  IBOutlet NSTextField *longURLClicksField_;

  IBOutlet NSTextField *addShortenedURLField_;
  IBOutlet NSButton *addShortenedURLButton_;
  
  // IBOutlets - client ID sheet
  IBOutlet NSButton *clientIDButton_;
  IBOutlet NSTextField *clientIDRequiredTextField_;
  IBOutlet NSWindow *clientIDSheet_;
  IBOutlet NSTextField *clientIDField_;
  IBOutlet NSTextField *clientSecretField_;

  // property storage
  GTLUrlshortenerUrlHistory *historyFeed_;
  GTLServiceTicket *historyTicket_;
  NSError *historyFetchError_;

  GTLUrlshortenerUrl *analyticsItem_;
  GTLServiceTicket *analyticsTicket_;
  NSError *analyticsFetchError_;
}

+ (URLShortenerSampleWindowController *)sharedWindowController;

// Sign-in
- (IBAction)signInClicked:(id)sender;
- (IBAction)clientIDClicked:(id)sender;
- (IBAction)clientIDDoneClicked:(id)sender;
- (IBAction)APIConsoleClicked:(id)sender;

// Main UI
- (IBAction)getHistoryClicked:(id)sender;
- (IBAction)analyticsSegmentClicked:(id)sender;
- (IBAction)cancelHistoryFetchClicked:(id)sender;
- (IBAction)cancelAnalyticsFetchClicked:(id)sender;
- (IBAction)addShortenedURLClicked:(id)sender;

- (IBAction)loggingCheckboxClicked:(id)sender;
@end

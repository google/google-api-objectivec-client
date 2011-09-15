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
//  PlusSampleWindowController.h
//

#import <Cocoa/Cocoa.h>

#import "GTLPlus.h"
#import "GTL/GTMOAuth2WindowController.h"

@interface PlusSampleWindowController : NSWindowController {
 @private
  IBOutlet NSTextField *signedInField_;
  IBOutlet NSButton *signedInButton_;

  IBOutlet NSButton *profileFetchCancelButton_;

  IBOutlet NSTableView *profileTable_;
  IBOutlet NSProgressIndicator *profileProgressIndicator_;
  IBOutlet NSTextView *profileResultTextView_;
  IBOutlet NSImageView *profileImageView_;

  IBOutlet NSTableView *activityFeedTable_;
  IBOutlet NSTextView *activityFeedResultTextView_;
  IBOutlet NSImageView *activityFeedImageView_;

  IBOutlet NSButton *clientIDButton_;
  IBOutlet NSTextField *clientIDRequiredTextField_;
  IBOutlet NSWindow *clientIDSheet_;
  IBOutlet NSTextField *clientIDField_;
  IBOutlet NSTextField *clientSecretField_;

  GTLPlusPerson *userProfile_;
  GTLPlusActivityFeed *activityFeed_;
  GTLServiceTicket *profileTicket_;
  NSError *profileFetchError_;
  NSError *activityFeedFetchError_;
}

+ (PlusSampleWindowController *)sharedWindowController;

- (IBAction)signInClicked:(id)sender;

- (IBAction)getFeedClicked:(id)sender;
- (IBAction)cancelProfileFetch:(id)sender;

- (IBAction)APIConsoleClicked:(id)sender;
- (IBAction)loggingCheckboxClicked:(id)sender;

// Client ID sheet
- (IBAction)clientIDClicked:(id)sender;
- (IBAction)clientIDDoneClicked:(id)sender;

@end

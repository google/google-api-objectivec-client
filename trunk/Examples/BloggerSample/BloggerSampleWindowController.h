/* Copyright (c) 2012 Google Inc.
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
//  BloggerSampleWindowController.h
//

#import <Cocoa/Cocoa.h>

#import "GTLBlogger.h"
#import "GTL/GTMOAuth2WindowController.h"

@interface BloggerSampleWindowController : NSWindowController {
 @private
  IBOutlet NSTextField *signedInField_;
  IBOutlet NSButton *signedInButton_;

  IBOutlet NSTableView *blogListTable_;
  IBOutlet NSProgressIndicator *blogListProgressIndicator_;
  IBOutlet NSTextView *blogListResultTextView_;
  IBOutlet NSButton *blogListCancelButton_;

  IBOutlet NSTableView *postListTable_;
  IBOutlet NSProgressIndicator *postListProgressIndicator_;
  IBOutlet NSTextView *postListResultTextView_;
  IBOutlet NSButton *postListCancelButton_;

  IBOutlet NSTextField *postTitleField_;
  IBOutlet NSTextField *postBodyField_;

  IBOutlet NSButton *addPostButton_;
  IBOutlet NSButton *updatePostButton_;
  IBOutlet NSButton *deletePostButton_;
  IBOutlet NSButton *deleteAllPostsButton_;

  // Client ID Sheet outlets (Not needed for real apps)
  IBOutlet NSButton *clientIDButton_;
  IBOutlet NSTextField *clientIDRequiredTextField_;
  IBOutlet NSWindow *clientIDSheet_;
  IBOutlet NSTextField *clientIDField_;
  IBOutlet NSTextField *clientSecretField_;


  GTLBloggerBlogList *blogList_;
  GTLServiceTicket *blogListTicket_;
  NSError *blogListFetchError_;

  GTLBloggerPostList *postList_;
  GTLServiceTicket *postListTicket_;
  NSError *postListFetchError_;

  GTLServiceTicket *editPostTicket_;
}

+ (BloggerSampleWindowController *)sharedWindowController;

- (IBAction)signInClicked:(id)sender;

- (IBAction)getBlogListClicked:(id)sender;

- (IBAction)cancelBlogFetchClicked:(id)sender;
- (IBAction)cancelPostFetchClicked:(id)sender;

- (IBAction)addPostClicked:(id)sender;
- (IBAction)updatePostClicked:(id)sender;
- (IBAction)deletePostClicked:(id)sender;
- (IBAction)deleteAllPostsClicked:(id)sender;

- (IBAction)APIConsoleClicked:(id)sender;
- (IBAction)loggingCheckboxClicked:(id)sender;

// Client ID sheet
- (IBAction)clientIDClicked:(id)sender;
- (IBAction)clientIDDoneClicked:(id)sender;

@end

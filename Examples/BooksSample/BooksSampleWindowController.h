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
//  BooksSampleWindowController.h
//

#import <Cocoa/Cocoa.h>

#import "GTLBooks.h"
#import "GTL/GTMOAuth2WindowController.h"

@interface BooksSampleWindowController : NSWindowController {
 @private
  IBOutlet NSTextField *signedInField_;
  IBOutlet NSButton *signedInButton_;

  IBOutlet NSTextField *keywordsField_;
  IBOutlet NSButton *searchButton_;

  IBOutlet NSButton *addToMyLibraryButton_;
  IBOutlet NSButton *publicVolumesCancelButton_;

  IBOutlet NSTableView *publicVolumesTable_;
  IBOutlet NSProgressIndicator *publicVolumesProgressIndicator_;
  IBOutlet NSTextView *publicVolumesResultTextView_;
  IBOutlet NSImageView *publicVolumesImageView_;

  IBOutlet NSButton *fetchMyLibraryButton_;
  IBOutlet NSPopUpButton *myBookshelvesPopup_;
  IBOutlet NSButton *myLibraryCancelButton_;

  IBOutlet NSTableView *myVolumesTable_;
  IBOutlet NSProgressIndicator *myVolumesProgressIndicator_;
  IBOutlet NSTextView *myVolumesResultTextView_;
  IBOutlet NSImageView *myVolumesImageView_;

  IBOutlet NSButton *removeButton_;
  IBOutlet NSButton *removeAllButton_;

  IBOutlet NSButton *clientIDButton_;
  IBOutlet NSTextField *clientIDRequiredTextField_;
  IBOutlet NSWindow *clientIDSheet_;
  IBOutlet NSTextField *clientIDField_;
  IBOutlet NSTextField *clientSecretField_;

  GTLBooksVolumes *publicVolumes_;
  GTLServiceTicket *publicVolumesTicket_;
  NSError *publicVolumesFetchError_;

  GTLBooksBookshelves *bookshelves_;
  GTLServiceTicket *bookshelvesTicket_;

  GTLBooksVolumes *myVolumes_;
  GTLServiceTicket *myVolumesTicket_;
  NSError *myVolumesFetchError_;

  GTLServiceTicket *editMyVolumeTicket_;
}

+ (BooksSampleWindowController *)sharedWindowController;

- (IBAction)signInClicked:(id)sender;

- (IBAction)searchClicked:(id)sender;

- (IBAction)cancelSearchClicked:(id)sender;

- (IBAction)fetchMyVolumesClicked:(id)sender;
- (IBAction)cancelMyVolumesFetchClicked:(id)sender;

- (IBAction)addToMyLibraryClicked:(id)sender;
- (IBAction)removeFromMyLibraryClicked:(id)sender;
- (IBAction)removeAllFromMyLibraryClicked:(id)sender;

- (IBAction)APIConsoleClicked:(id)sender;
- (IBAction)loggingCheckboxClicked:(id)sender;

// Client ID sheet
- (IBAction)clientIDClicked:(id)sender;
- (IBAction)clientIDDoneClicked:(id)sender;

@end

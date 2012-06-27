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
//  DriveSampleWindowController.h
//

#import <Cocoa/Cocoa.h>

#import "GTLDrive.h"
#import "GTL/GTMOAuth2WindowController.h"

@interface DriveSampleWindowController : NSWindowController {
 @private
  IBOutlet NSTextField *signedInField_;
  IBOutlet NSButton *signedInButton_;

  IBOutlet NSTableView *fileListTable_;
  IBOutlet NSProgressIndicator *fileListProgressIndicator_;
  IBOutlet NSTextView *fileListResultTextField_;
  IBOutlet NSButton *fileListCancelButton_;
  IBOutlet NSImageView *thumbnailView_;

  IBOutlet NSPopUpButton *downloadButton_;
  IBOutlet NSButton *viewButton_;
  IBOutlet NSButton *duplicateButton_;
  IBOutlet NSButton *trashButton_;
  IBOutlet NSButton *deleteButton_;

  IBOutlet NSButton *uploadButton_;
  IBOutlet NSProgressIndicator *uploadProgressIndicator_;
  IBOutlet NSButton *pauseUploadButton_;
  IBOutlet NSButton *stopUploadButton_;
  IBOutlet NSButton *newFolderButton_;

  IBOutlet NSSegmentedControl *segmentedControl_;
  IBOutlet NSTableView *detailTable_;
  IBOutlet NSProgressIndicator *detailProgressIndicator_;
  IBOutlet NSTextView *detailResultTextField_;
  IBOutlet NSButton *detailCancelButton_;

  // Client ID Sheet (Not needed by real applications)
  IBOutlet NSButton *clientIDButton_;
  IBOutlet NSTextField *clientIDRequiredTextField_;
  IBOutlet NSWindow *clientIDSheet_;
  IBOutlet NSTextField *clientIDField_;
  IBOutlet NSTextField *clientSecretField_;


  GTLDriveFileList *fileList_;
  GTLServiceTicket *fileListTicket_;
  NSError *fileListFetchError_;
  GTLServiceTicket *editFileListTicket_;
  GTLServiceTicket *uploadFileTicket_;

  GTLDriveRevisionList *revisionList_;
  NSError *revisionListFetchError_;

  GTLDrivePermissionList *permissionList_;
  NSError *permissionListFetchError_;

  GTLDriveChildList *childList_;
  NSError *childListFetchError_;

  GTLDriveParentList *parentsList_;
  NSError *parentsListFetchError_;

  GTLServiceTicket *detailsTicket_;
  NSError *detailsFetchError_;
}

+ (DriveSampleWindowController *)sharedWindowController;

- (IBAction)signInClicked:(id)sender;

- (IBAction)getFileList:(id)sender;

- (IBAction)cancelFileListFetch:(id)sender;

- (IBAction)viewClicked:(id)sender;
- (IBAction)duplicateClicked:(id)sender;
- (IBAction)trashClicked:(id)sender;
- (IBAction)deleteClicked:(id)sender;

- (IBAction)uploadFileClicked:(id)sender;
- (IBAction)pauseUploadClicked:(id)sender;
- (IBAction)stopUploadClicked:(id)sender;
- (IBAction)createFolderClicked:(id)sender;

- (IBAction)segmentedControlClicked:(id)sender;

- (IBAction)loggingCheckboxClicked:(id)sender;

// Client ID Sheet
- (IBAction)clientIDClicked:(id)sender;
- (IBAction)clientIDDoneClicked:(id)sender;
- (IBAction)APIConsoleClicked:(id)sender;

@end

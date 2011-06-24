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
//  TasksSampleWindowController.h
//

#import <Cocoa/Cocoa.h>

#import "GTLTasks.h"
#import "GTL/GTMOAuth2WindowController.h"

@interface TasksSampleWindowController : NSWindowController {
 @private
  IBOutlet NSTextField *mSignedInField;
  IBOutlet NSButton *mSignedInButton;

  IBOutlet NSTableView *mTaskListsTable;
  IBOutlet NSProgressIndicator *mTaskListsProgressIndicator;
  IBOutlet NSTextView *mTaskListsResultTextView;

  IBOutlet NSButton *mTaskListsCancelButton;

  IBOutlet NSButton *mAddTaskListButton;
  IBOutlet NSButton *mRenameTaskListButton;
  IBOutlet NSButton *mDeleteTaskListButton;
  IBOutlet NSTextField *mTaskListNameField;

  IBOutlet NSOutlineView *mTasksOutline;
  IBOutlet NSProgressIndicator *mTasksProgressIndicator;
  IBOutlet NSTextView *mTasksResultTextView;

  IBOutlet NSButton *mShowCompletedTasksCheckbox;
  IBOutlet NSButton *mShowHiddenTasksCheckbox;
  IBOutlet NSButton *mShowDeletedTasksCheckbox;
  IBOutlet NSButton *mTasksCancelButton;

  IBOutlet NSButton *mAddTaskButton;
  IBOutlet NSButton *mRenameTaskButton;
  IBOutlet NSButton *mDeleteTaskButton;
  IBOutlet NSButton *mCompleteTaskButton;
  IBOutlet NSButton *mClearTasksButton;
  IBOutlet NSButton *mCompleteAllTasksButton;
  IBOutlet NSButton *mDeleteAllTasksButton;
  IBOutlet NSTextField *mTaskNameField;

  IBOutlet NSButton *mClientIDButton;
  IBOutlet NSTextField *mClientIDRequiredTextField;
  IBOutlet NSWindow *mClientIDSheet;
  IBOutlet NSTextField *mClientIDField;
  IBOutlet NSTextField *mClientSecretField;

  GTLTasksTaskLists *mTasksLists;
  GTLServiceTicket *mTaskListsTicket;
  NSError *mTaskListsFetchError;

  GTLServiceTicket *mEditTaskListTicket;

  GTLTasksTasks *mTasks;
  GTLServiceTicket *mTasksTicket;
  NSError *mTasksFetchError;

  GTLServiceTicket *mEditTaskTicket;
}

+ (TasksSampleWindowController *)sharedWindowController;

- (IBAction)signInClicked:(id)sender;

- (IBAction)getTaskListsClicked:(id)sender;
- (IBAction)cancelTaskListsFetch:(id)sender;
- (IBAction)cancelTasksFetch:(id)sender;

- (IBAction)addTaskListClicked:(id)sender;
- (IBAction)renameTaskListClicked:(id)sender;
- (IBAction)deleteTaskListClicked:(id)sender;

- (IBAction)addTaskClicked:(id)sender;
- (IBAction)renameTaskClicked:(id)sender;
- (IBAction)deleteTaskClicked:(id)sender;
- (IBAction)completeTaskClicked:(id)sender;
- (IBAction)clearTasksClicked:(id)sender;
- (IBAction)completeAllTasksClicked:(id)sender;
- (IBAction)deleteAllTasksClicked:(id)sender;
- (IBAction)showTasksCheckboxClicked:(id)sender;

- (IBAction)APIConsoleClicked:(id)sender;
- (IBAction)loggingCheckboxClicked:(id)sender;

// Client ID sheet
- (IBAction)clientIDClicked:(id)sender;
- (IBAction)clientIDDoneClicked:(id)sender;

@end

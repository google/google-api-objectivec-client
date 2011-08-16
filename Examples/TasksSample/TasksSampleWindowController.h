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
  IBOutlet NSTextField *signedInField_;
  IBOutlet NSButton *signedInButton_;

  IBOutlet NSTableView *taskListsTable__;
  IBOutlet NSProgressIndicator *taskListsProgressIndicator_;
  IBOutlet NSTextView *taskListsResultTextView_;

  IBOutlet NSButton *taskListsCancelButton_;

  IBOutlet NSButton *addTaskListButton_;
  IBOutlet NSButton *renameTaskListButton_;
  IBOutlet NSButton *deleteTaskListButton_;
  IBOutlet NSTextField *taskListNameField_;

  IBOutlet NSOutlineView *tasksOutline_;
  IBOutlet NSProgressIndicator *tasksProgressIndicator_;
  IBOutlet NSTextView *tasksResultTextView_;

  IBOutlet NSButton *showCompletedTasksCheckbox_;
  IBOutlet NSButton *showHiddenTasksCheckbox_;
  IBOutlet NSButton *showDeletedTasksCheckbox_;
  IBOutlet NSButton *tasksCancelButton_;

  IBOutlet NSButton *addTaskButton_;
  IBOutlet NSButton *renameTaskButton_;
  IBOutlet NSButton *deleteTaskButton_;
  IBOutlet NSButton *completeTaskButton_;
  IBOutlet NSButton *clearTasksButton_;
  IBOutlet NSButton *completeAllTasksButton_;
  IBOutlet NSButton *deleteAllTasksButton_;
  IBOutlet NSTextField *taskNameField_;

  IBOutlet NSButton *clientIDButton_;
  IBOutlet NSTextField *clientIDRequiredTextField_;
  IBOutlet NSWindow *clientIDSheet_;
  IBOutlet NSTextField *clientIDField_;
  IBOutlet NSTextField *clientSecretField_;

  GTLTasksTaskLists *tasksLists_;
  GTLServiceTicket *taskListsTicket_;
  NSError *taskListsFetchError_;

  GTLServiceTicket *editTaskListTicket_;

  GTLTasksTasks *tasks_;
  GTLServiceTicket *tasksTicket_;
  NSError *tasksFetchError_;

  GTLServiceTicket *editTaskTicket_;
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

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
//  TasksSampleWindowController.m
//

#import "TasksSampleWindowController.h"

#import "GTL/GTLUtilities.h"
#import "GTL/GTMHTTPFetcherLogging.h"

@interface TasksSampleWindowController ()

@property (readonly) GTLServiceTasks *tasksService;

@property (retain) GTLTasksTaskLists *taskLists;
@property (retain) GTLServiceTicket *taskListsTicket;
@property (retain) NSError *taskListsFetchError;

@property (retain) GTLServiceTicket *editTaskListTicket;

@property (retain) GTLTasksTasks *tasks;
@property (retain) GTLServiceTicket *tasksTicket;
@property (retain) NSError *tasksFetchError;

@property (retain) GTLServiceTicket *editTaskTicket;

- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel;

- (void)updateUI;
- (void)displayAlert:(NSString *)title format:(NSString *)format, ...;

- (void)fetchTaskLists;
- (void)fetchTasksForSelectedList;

- (void)addATaskList;
- (void)renameSelectedTaskList;
- (void)deleteSelectedTaskList;

- (void)addATask;
- (void)renameSelectedTask;
- (void)deleteSelectedTask;
- (void)completeSelectedTask;
- (void)hideCompletedTasks;
- (void)completeAllTasks;
- (void)deleteAllTasks;

- (GTLTasksTaskList *)selectedTaskList;
- (GTLTasksTask *)selectedTask;

@end

// Constants that ought to be defined by the API
NSString *const kTaskStatusCompleted = @"completed";
NSString *const kTaskStatusNeedsAction = @"needsAction";

// Keychain item name for saving the user's authentication information
NSString *const kKeychainItemName = @"TasksSample: Google Tasks";

@implementation TasksSampleWindowController

@synthesize taskLists = tasksLists_,
            taskListsTicket = taskListsTicket_,
            taskListsFetchError = taskListsFetchError_,
            editTaskListTicket = editTaskListTicket_,
            tasks = tasks_,
            tasksTicket = tasksTicket_,
            tasksFetchError = tasksFetchError_,
            editTaskTicket = editTaskTicket_;

+ (TasksSampleWindowController *)sharedWindowController {
  static TasksSampleWindowController* gWindowController = nil;
  if (!gWindowController) {
    gWindowController = [[TasksSampleWindowController alloc] init];
  }
  return gWindowController;
}

- (id)init {
  return [self initWithWindowNibName:@"TasksSampleWindow"];
}

- (void)awakeFromNib {
  // Load the OAuth token from the keychain, if it was previously saved
  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  GTMOAuth2Authentication *auth;
  auth = [GTMOAuth2WindowController authForGoogleFromKeychainForName:kKeychainItemName
                                                            clientID:clientID
                                                        clientSecret:clientSecret];
  self.tasksService.authorizer = auth;

  // Set the result text fields to have a distinctive color and mono-spaced font
  [taskListsResultTextView_ setTextColor:[NSColor darkGrayColor]];
  [tasksResultTextView_ setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [taskListsResultTextView_ setFont:resultTextFont];
  [tasksResultTextView_ setFont:resultTextFont];

  [tasksOutline_ registerForDraggedTypes:[NSArray arrayWithObject:NSPasteboardTypeString]];
  [self updateUI];
}

- (void)dealloc {
  [tasksLists_ release];
  [taskListsTicket_ release];
  [taskListsFetchError_ release];

  [editTaskListTicket_ release];

  [tasks_ release];
  [tasksTicket_ release];
  [tasksFetchError_ release];

  [editTaskTicket_ release];

  [super dealloc];
}

#pragma mark -

- (NSString *)signedInUsername {
  // Get the email address of the signed-in user
  GTMOAuth2Authentication *auth = self.tasksService.authorizer;
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
    GTLServiceTasks *service = self.tasksService;

    [GTMOAuth2WindowController removeAuthFromKeychainForName:kKeychainItemName];
    service.authorizer = nil;
    [self updateUI];
  }
}

- (IBAction)getTaskListsClicked:(id)sender {
  if (![self isSignedIn]) {
    [self runSigninThenInvokeSelector:@selector(fetchTaskLists)];
  } else {
    [self fetchTaskLists];
  }
}

- (IBAction)cancelTaskListsFetch:(id)sender {
  [self.taskListsTicket cancelTicket];
  self.taskListsTicket = nil;

  [self.editTaskListTicket cancelTicket];
  self.editTaskListTicket = nil;

  [self updateUI];
}

- (IBAction)cancelTasksFetch:(id)sender {
  [self.tasksTicket cancelTicket];
  self.tasksTicket = nil;

  [self.editTaskTicket cancelTicket];
  self.editTaskTicket = nil;

  [self updateUI];
}

- (IBAction)addTaskListClicked:(id)sender {
  [self addATaskList];
}

- (IBAction)renameTaskListClicked:(id)sender {
  [self renameSelectedTaskList];
}

- (IBAction)deleteTaskListClicked:(id)sender {
  GTLTasksTaskList *tasklist = [self selectedTaskList];
  NSString *title = tasklist.title;

  NSBeginAlertSheet(@"Delete", nil, @"Cancel", nil,
                    [self window], self,
                    @selector(deleteTaskListSheetDidEnd:returnCode:contextInfo:),
                    nil, nil, @"Delete \"%@\"?", title);
}

- (void)deleteTaskListSheetDidEnd:(NSWindow *)sheet
                       returnCode:(int)returnCode
                      contextInfo:(void *)contextInfo {
  if (returnCode == NSAlertDefaultReturn) {
    [self deleteSelectedTaskList];
  }
}

- (IBAction)addTaskClicked:(id)sender {
  [self addATask];
}

- (IBAction)renameTaskClicked:(id)sender {
  [self renameSelectedTask];
}

- (IBAction)deleteTaskClicked:(id)sender {
  GTLTasksTask *task = [self selectedTask];
  NSString *title = task.title;

  NSBeginAlertSheet(@"Delete", nil, @"Cancel", nil,
                    [self window], self,
                    @selector(deleteTaskSheetDidEnd:returnCode:contextInfo:),
                    nil, nil, @"Delete \"%@\"?", title);
}

- (void)deleteTaskSheetDidEnd:(NSWindow *)sheet
                   returnCode:(int)returnCode
                  contextInfo:(void *)contextInfo {
  if (returnCode == NSAlertDefaultReturn) {
    [self deleteSelectedTask];
  }
}

- (IBAction)completeTaskClicked:(id)sender {
  [self completeSelectedTask];
}

- (IBAction)clearTasksClicked:(id)sender {
  [self hideCompletedTasks];
}

- (IBAction)completeAllTasksClicked:(id)sender {
  [self completeAllTasks];
}

- (IBAction)deleteAllTasksClicked:(id)sender {
  [self deleteAllTasks];
}

- (IBAction)showTasksCheckboxClicked:(id)sender {
  [self fetchTasksForSelectedList];
}

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://code.google.com/apis/console"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMHTTPFetcher setLoggingEnabled:[sender state]];
}

#pragma mark -

// get a service object with the current username/password
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information (such as cookies and the "last modified" date for
// fetched data.)

- (GTLServiceTasks *)tasksService {
  static GTLServiceTasks *service = nil;

  if (!service) {
    service = [[GTLServiceTasks alloc] init];

    // Have the service object set tickets to fetch consecutive pages
    // of the feed so we do not need to manually fetch them
    service.shouldFetchNextPages = YES;

    // Have the service object set tickets to retry temporary error conditions
    // automatically
    service.retryEnabled = YES;
  }
  return service;
}

- (GTLTasksTaskList *)selectedTaskList {
  int rowIndex = [taskListsTable__ selectedRow];
  if (rowIndex > -1) {
    GTLTasksTaskList *item = [self.taskLists itemAtIndex:rowIndex];
    return item;
  }
  return nil;
}

- (GTLTasksTask *)selectedTask {
  int rowIndex = [tasksOutline_ selectedRow];
  GTLTasksTask *item = [tasksOutline_ itemAtRow:rowIndex];
  return item;
}

- (NSArray *)completedTasks {
  NSArray *array = [GTLUtilities objectsFromArray:self.tasks.items
                                        withValue:kTaskStatusCompleted
                                       forKeyPath:@"status"];
  return array;
}

#pragma mark Create ID Map and Ordered Child Arrays

// For the efficient access to tasks in the tasks object, we'll
// build a map from task identifier to each task item, and arrays
// for the children of the top-level object and for the children
// of every parent task

static NSString *const kGTLTaskMapProperty = @"taskMap";
static NSString *const kGTLChildTasksProperty = @"childTasks";

- (void)createPropertiesForTasks:(GTLTasksTasks *)tasks {
  // First, build a dictionary, mapping item identifier strings to items objects
  //
  // This will allow for much faster lookup than would linear search of
  // task list's items
  NSMutableDictionary *taskMap = [NSMutableDictionary dictionary];
  for (GTLTasksTask *task in tasks) {
    [taskMap setObject:task
                forKey:task.identifier];
  }
  [tasks setProperty:taskMap
              forKey:kGTLTaskMapProperty];

  // Make an array for each parent with pointers to its immediate children, in
  // the order the children occur in the list.  We'll store the array in a
  // property of the parent task item.
  //
  // For top-level tasks, we'll store the array in a property of the list
  // object.
  NSMutableArray *topTasks = [NSMutableArray array];
  [tasks setProperty:topTasks
              forKey:kGTLChildTasksProperty];

  for (GTLTasksTask *task in tasks) {
    NSString *parentID = task.parent;
    if (parentID == nil) {
      // this is a top-level task in the list, so the task's parent is the
      // main list
      [topTasks addObject:task];
    } else {
      // this task is child of another task; add it to the parent's list
      GTLTasksTask *parentTask = [taskMap objectForKey:parentID];
      NSMutableArray *childTasks = [parentTask propertyForKey:kGTLChildTasksProperty];
      if (childTasks == nil) {
        childTasks = [NSMutableArray array];
        [parentTask setProperty:childTasks
                         forKey:kGTLChildTasksProperty];
      }
      [childTasks addObject:task];
    }
  }
}

- (GTLTasksTask *)taskWithIdentifier:(NSString *)taskID
                           fromTasks:(GTLTasksTasks *)tasks {
  NSDictionary *taskMap = [tasks propertyForKey:kGTLTaskMapProperty];
  GTLTasksTask *task = [taskMap valueForKey:taskID];
  return task;
}

- (NSArray *)taskChildrenForObject:(GTLObject *)obj {
  // Object is either a GTLTasksTasks (the top-level tasks list)
  // or a GTLTasksTask (a task which may be a parent of other tasks)
  NSArray *array = [obj propertyForKey:kGTLChildTasksProperty];
  return array;
}

#pragma mark Fetch Task Lists

- (void)fetchTaskLists {
  self.taskLists = nil;
  self.taskListsFetchError = nil;

  GTLServiceTasks *service = self.tasksService;

  GTLQueryTasks *query = [GTLQueryTasks queryForTasklistsList];

  self.taskListsTicket = [service executeQuery:query
                             completionHandler:^(GTLServiceTicket *ticket,
                                                 id taskLists, NSError *error) {
                               // callback
                               self.taskLists = taskLists;
                               self.taskListsFetchError = error;
                               self.taskListsTicket = nil;

                               [self updateUI];
                             }];
  [self updateUI];
}

#pragma mark Fetch Tasks

- (void)fetchTasksForSelectedList {
  self.tasks = nil;
  self.tasksFetchError = nil;

  GTLServiceTasks *service = self.tasksService;

  GTLTasksTaskList *selectedTasklist = [self selectedTaskList];
  if (selectedTasklist) {
    NSString *tasklistID = selectedTasklist.identifier;

    GTLQueryTasks *query = [GTLQueryTasks queryForTasksListWithTasklist:tasklistID];
    query.showCompleted = [showCompletedTasksCheckbox_ state];
    query.showHidden = [showHiddenTasksCheckbox_ state];
    query.showDeleted = [showDeletedTasksCheckbox_ state];

    self.tasksTicket = [service executeQuery:query
                           completionHandler:^(GTLServiceTicket *ticket,
                                               id tasks, NSError *error) {
                             // callback
                             [self createPropertiesForTasks:tasks];

                             self.tasks = tasks;
                             self.tasksFetchError = error;
                             self.tasksTicket = nil;

                             [self updateUI];
                           }];
    [self updateUI];
  }
}

#pragma mark Add a Task List

- (void)addATaskList {
  NSString *title = [taskListNameField_ stringValue];
  if ([title length] > 0) {
    // Make a new task list
    GTLTasksTaskList *tasklist = [GTLTasksTaskList object];
    tasklist.title = title;

    GTLQueryTasks *query = [GTLQueryTasks queryForTasklistsInsertWithObject:tasklist];

    GTLServiceTasks *service = self.tasksService;
    self.editTaskListTicket = [service executeQuery:query
                                  completionHandler:^(GTLServiceTicket *ticket,
                                                      id item, NSError *error) {
                                    // callback
                                    self.editTaskListTicket = nil;
                                    GTLTasksTaskList *tasklist = item;

                                    if (error == nil) {
                                      [self displayAlert:@"Task List Added"
                                                  format:@"Added task list \"%@\"", tasklist.title];
                                      [self fetchTaskLists];
                                      [taskListNameField_ setStringValue:@""];
                                    } else {
                                      [self displayAlert:@"Error"
                                                  format:@"%@", error];
                                      [self updateUI];
                                    }
                                  }];
    [self updateUI];
  }
}

#pragma mark Rename a Task List

- (void)renameSelectedTaskList {
  NSString *title = [taskListNameField_ stringValue];
  if ([title length] > 0) {
    // Rename the selected task list

    // Rather than update the object with a complete replacement, we'll make
    // a patch object containing just the changed title
    GTLTasksTaskList *patchObject = [GTLTasksTaskList object];
    patchObject.title = title;

    GTLTasksTaskList *selectedTaskList = [self selectedTaskList];

    GTLQueryTasks *query = [GTLQueryTasks queryForTasklistsPatchWithObject:patchObject
                                                                  tasklist:selectedTaskList.identifier];
    GTLServiceTasks *service = self.tasksService;
    self.editTaskListTicket = [service executeQuery:query
                                  completionHandler:^(GTLServiceTicket *ticket,
                                                      id item, NSError *error) {
                                    // callback
                                    self.editTaskListTicket = nil;
                                    GTLTasksTaskList *tasklist = item;

                                    if (error == nil) {
                                      [self displayAlert:@"Task List Updated"
                                                  format:@"Updated task list \"%@\"", tasklist.title];
                                      [self fetchTaskLists];
                                      [taskListNameField_ setStringValue:@""];
                                    } else {
                                      [self displayAlert:@"Error"
                                                  format:@"%@", error];
                                      [self updateUI];
                                    }
                                  }];
    [self updateUI];
  }
}

#pragma mark Delete a Task List

- (void)deleteSelectedTaskList {
  GTLTasksTaskList *tasklist = [self selectedTaskList];

  GTLQueryTasks *query = [GTLQueryTasks queryForTasklistsDeleteWithTasklist:tasklist.identifier];

  GTLServiceTasks *service = self.tasksService;
  self.editTaskListTicket = [service executeQuery:query
                                completionHandler:^(GTLServiceTicket *ticket,
                                                    id item, NSError *error) {
                                  // callback
                                  self.editTaskListTicket = nil;

                                  if (error == nil) {
                                    [self displayAlert:@"Task List Deleted"
                                                format:@"Deleted task list \"%@\"", tasklist.title];
                                    [self fetchTaskLists];
                                  } else {
                                    [self displayAlert:@"Error"
                                                format:@"%@", error];
                                    [self updateUI];
                                  }
                                }];
  [self updateUI];
}

#pragma mark Add a Task

- (void)addATask {
  NSString *title = [taskNameField_ stringValue];
  if ([title length] > 0) {
    // Make a new task
    GTLTasksTask *task = [GTLTasksTask object];
    task.title = title;

    GTLTasksTaskList *tasklist = [self selectedTaskList];
    GTLQueryTasks *query = [GTLQueryTasks queryForTasksInsertWithObject:task
                                                               tasklist:tasklist.identifier];
    GTLServiceTasks *service = self.tasksService;
    self.editTaskTicket = [service executeQuery:query
                              completionHandler:^(GTLServiceTicket *ticket,
                                                  id item, NSError *error) {
                                // callback
                                self.editTaskTicket = nil;
                                GTLTasksTask *task = item;

                                if (error == nil) {
                                  [self displayAlert:@"Task Added"
                                              format:@"Added task \"%@\"", task.title];
                                  [self fetchTasksForSelectedList];
                                  [taskNameField_ setStringValue:@""];
                                } else {
                                  [self displayAlert:@"Error"
                                              format:@"%@", error];
                                  [self updateUI];
                                }
                              }];
    [self updateUI];
  }
}

#pragma mark Rename a Task

- (void)renameSelectedTask {
  NSString *title = [taskNameField_ stringValue];
  if ([title length] > 0) {
    // Rename the selected task

    // Rather than update the object with a complete replacement, we'll make
    // a patch object containing just the changes
    GTLTasksTask *patchObject = [GTLTasksTask object];
    patchObject.title = title;

    GTLTasksTask *task = [self selectedTask];
    GTLTasksTaskList *tasklist = [self selectedTaskList];
    GTLQueryTasks *query = [GTLQueryTasks queryForTasksPatchWithObject:patchObject
                                                              tasklist:tasklist.identifier
                                                                  task:task.identifier];
    GTLServiceTasks *service = self.tasksService;
    self.editTaskTicket = [service executeQuery:query
                              completionHandler:^(GTLServiceTicket *ticket,
                                                  id item, NSError *error) {
                                // callback
                                self.editTaskTicket = nil;
                                GTLTasksTask *task = item;

                                if (error == nil) {
                                  [self displayAlert:@"Task Updated"
                                              format:@"Renamed task to \"%@\"", task.title];
                                  [self fetchTasksForSelectedList];
                                  [taskNameField_ setStringValue:@""];
                                } else {
                                  [self displayAlert:@"Error"
                                              format:@"%@", error];
                                  [self updateUI];
                                }
                              }];
    [self updateUI];
  }
}

#pragma mark Delete a Task

- (void)deleteSelectedTask {
  // Delete a task
  GTLTasksTask *task = [self selectedTask];
  NSString *taskTitle = task.title;

  GTLTasksTaskList *tasklist = [self selectedTaskList];
  GTLQueryTasks *query = [GTLQueryTasks queryForTasksDeleteWithTasklist:tasklist.identifier
                                                                   task:task.identifier];
  GTLServiceTasks *service = self.tasksService;
  self.editTaskTicket = [service executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                id item, NSError *error) {
                              // callback
                              self.editTaskTicket = nil;

                              if (error == nil) {
                                [self displayAlert:@"Task Deleted"
                                            format:@"Deleted task \"%@\"", taskTitle];
                                [self fetchTasksForSelectedList];
                              } else {
                                [self displayAlert:@"Error"
                                            format:@"%@", error];
                                [self updateUI];
                              }
                            }];
  [self updateUI];
}

#pragma mark Change a Task's Complete Status

- (void)completeSelectedTask {
  // Mark a task as completed or incomplete
  GTLTasksTask *selectedTask = [self selectedTask];
  GTLTasksTask *patchObject = [GTLTasksTask object];

  if ([selectedTask.status isEqual:kTaskStatusCompleted]) {
    // Change the status to not complete
    patchObject.status = kTaskStatusNeedsAction;
    patchObject.completed = [GTLObject nullValue]; // remove the completed date
  } else {
    // Change the status to complete
    patchObject.status = kTaskStatusCompleted;
  }

  GTLTasksTaskList *tasklist = [self selectedTaskList];
  GTLQueryTasks *query = [GTLQueryTasks queryForTasksPatchWithObject:patchObject
                                                            tasklist:tasklist.identifier
                                                                task:selectedTask.identifier];
  GTLServiceTasks *service = self.tasksService;
  self.editTaskTicket = [service executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                id item, NSError *error) {
                              // callback
                              self.editTaskTicket = nil;
                              GTLTasksTask *task = item;

                              if (error == nil) {
                                NSString *displayStatus;
                                if ([task.status isEqual:kTaskStatusCompleted]) {
                                  displayStatus = @"complete";
                                } else {
                                  displayStatus = @"incomplete";
                                }

                                [self displayAlert:@"Task Updated"
                                            format:@"Marked task \"%@\" %@", task.title, displayStatus];
                                [self fetchTasksForSelectedList];
                              } else {
                                [self displayAlert:@"Error"
                                            format:@"%@", error];
                                [self updateUI];
                              }
                            }];
  [self updateUI];
}

#pragma mark Hide Completed Tasks

- (void)hideCompletedTasks {
  // Make all completed tasks hidden
  NSArray *previouslyCompletedTasks = [self completedTasks];
  GTLTasksTaskList *tasklist = [self selectedTaskList];
  GTLQueryTasks *query = [GTLQueryTasks queryForTasksClearWithTasklist:tasklist.identifier];

  GTLServiceTasks *service = self.tasksService;
  self.editTaskTicket = [service executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                id item, NSError *error) {
                              // callback
                              self.editTaskTicket = nil;

                              if (error == nil) {
                                [self displayAlert:@"Task List Clear"
                                            format:@"Made %lu tasks hidden", (unsigned long) [previouslyCompletedTasks count]];
                                [self fetchTasksForSelectedList];
                              } else {
                                [self displayAlert:@"Error"
                                            format:@"%@", error];
                                [self updateUI];
                              }
                            }];
  [self updateUI];
}

#pragma mark Complete All Tasks

- (void)completeAllTasks {
  // Change all tasks to be completed or uncompleted
  NSArray *completedTasks = [self completedTasks];
  NSUInteger numberOfCompletedTasks = [completedTasks count];
  NSUInteger numberOfTasks = [self.tasks.items count];
  BOOL wereAllTasksCompleted = (numberOfCompletedTasks == numberOfTasks);

  // Make a batch of queries to set all tasks to completed or uncompleted
  GTLTasksTaskList *tasklist = [self selectedTaskList];

  GTLBatchQuery *batchQuery = [GTLBatchQuery batchQuery];

  for (GTLTasksTask *task in self.tasks) {
    GTLTasksTask *patchObject = [GTLTasksTask object];

    if (wereAllTasksCompleted) {
      // Change the status to not complete
      patchObject.status = kTaskStatusNeedsAction;
      patchObject.completed = [GTLObject nullValue]; // remove the completed date
    } else {
      // Change the status to complete
      patchObject.status = kTaskStatusCompleted;
    }

    GTLQueryTasks *query = [GTLQueryTasks queryForTasksPatchWithObject:patchObject
                                                              tasklist:tasklist.identifier
                                                                  task:task.identifier];
    [batchQuery addQuery:query];
  }

  GTLServiceTasks *service = self.tasksService;
  self.editTaskTicket = [service executeQuery:batchQuery
                            completionHandler:^(GTLServiceTicket *ticket,
                                                id object, NSError *error) {
                              // callback
                              self.editTaskTicket = nil;

                              if (error == nil) {
                                GTLBatchResult *batchResults = (GTLBatchResult *)object;
                                NSString *status = wereAllTasksCompleted ? @"Uncompleted" : @"Completed";

                                NSDictionary *successes = batchResults.successes;
                                NSDictionary *failures = batchResults.failures;

                                NSUInteger numberUpdated = [successes count];
                                NSUInteger numberFailed = [failures count];

                                NSArray *successTasks = [successes allValues];
                                NSArray *titles = [successTasks valueForKey:@"title"];
                                NSString *titlesStr = [titles componentsJoinedByString:@", "];

                                [self displayAlert:@"Tasks Updated"
                                            format:@"%@: %lu\n%@\nErrors: %lu\n%@",
                                 status,
                                 (unsigned long) numberUpdated, titlesStr,
                                 (unsigned long) numberFailed, failures];

                                [self fetchTasksForSelectedList];
                              } else {
                                [self displayAlert:@"Error"
                                            format:@"%@", error];
                                [self updateUI];
                              }
                            }];
  [self updateUI];
}

#pragma mark Delete All Tasks

- (void)deleteAllTasks {
  // Make a batch of queries to delete all tasks
  GTLTasksTaskList *tasklist = [self selectedTaskList];

  GTLBatchQuery *batch = [GTLBatchQuery batchQuery];

  for (GTLTasksTask *task in self.tasks) {
    GTLQueryTasks *query = [GTLQueryTasks queryForTasksDeleteWithTasklist:tasklist.identifier
                                                                     task:task.identifier];
    [batch addQuery:query];
  }

  GTLServiceTasks *service = self.tasksService;
  self.editTaskTicket = [service executeQuery:batch
                            completionHandler:^(GTLServiceTicket *ticket,
                                                id object, NSError *error) {
                              // callback
                              self.editTaskTicket = nil;

                              if (error == nil) {
                                GTLBatchResult *batch = (GTLBatchResult *)object;

                                NSUInteger numberDeleted = [batch.successes count];

                                [self displayAlert:@"Tasks Deleted"
                                            format:@"Deleted: %lu\nErrors: %@",
                                 (unsigned long) numberDeleted,
                                 batch.failures];

                                [self fetchTasksForSelectedList];
                              } else {
                                [self displayAlert:@"Error"
                                            format:@"%@", error];
                                [self updateUI];
                              }
                            }];
  [self updateUI];
}

#pragma mark Move Task

- (void)moveTaskWithIdentifier:(NSString *)taskID
                    toParentID:(NSString *)destinationParentIDorNil
                         index:(NSInteger)destinationIndex {
  // Make all completed tasks hidden
  GTLTasksTaskList *tasklist = [self selectedTaskList];
  GTLQueryTasks *query = [GTLQueryTasks queryForTasksMoveWithTasklist:tasklist.identifier
                                                                 task:taskID];
  query.parent = destinationParentIDorNil;

  // Determine the ID of the task preceding the new location
  if (destinationIndex > 0) {
    GTLObject *parentTask;
    if (destinationParentIDorNil) {
      parentTask = [self taskWithIdentifier:destinationParentIDorNil
                                  fromTasks:self.tasks];
    } else {
      // There is no parent; it's a top-level task
      parentTask = self.tasks;
    }
    NSArray *children = [self taskChildrenForObject:parentTask];

    GTLTasksTask *previousTask = [children objectAtIndex:(destinationIndex - 1)];
    query.previous = previousTask.identifier;
  }

  GTLServiceTasks *service = self.tasksService;
  self.editTaskTicket = [service executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                id item, NSError *error) {
                              // callback
                              self.editTaskTicket = nil;

                              if (error == nil) {
                                [self fetchTasksForSelectedList];
                              } else {
                                [self displayAlert:@"Error"
                                            format:@"%@", error];
                                [self updateUI];
                              }
                            }];
  [self updateUI];
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
  windowController = [GTMOAuth2WindowController controllerWithScope:kGTLAuthScopeTasks
                                                           clientID:clientID
                                                       clientSecret:clientSecret
                                                   keychainItemName:kKeychainItemName
                                                     resourceBundle:frameworkBundle];

  [windowController signInSheetModalForWindow:[self window]
                            completionHandler:^(GTMOAuth2Authentication *auth,
                                                NSError *error) {
                              // callback
                              if (error == nil) {
                                self.tasksService.authorizer = auth;
                                if (signInDoneSel) {
                                  [self performSelector:signInDoneSel];
                                }
                              } else {
                                self.taskListsFetchError = error;
                                [self updateUI];
                              }
                            }];
}

#pragma mark UI

- (void)updateUI {
  BOOL isSignedIn = [self isSignedIn];
  NSString *username = [self signedInUsername];
  [signedInButton_ setTitle:(isSignedIn ? @"Sign Out" : @"Sign In")];
  [signedInField_ setStringValue:(isSignedIn ? username : @"No")];

  //
  // Task lists table
  //
  [taskListsTable__ reloadData];

  if (self.taskListsTicket != nil || self.editTaskListTicket != nil) {
    [taskListsProgressIndicator_ startAnimation:self];
  } else {
    [taskListsProgressIndicator_ stopAnimation:self];
  }

  // Get the description of the selected item, or the feed fetch error
  NSString *resultStr = @"";

  if (self.taskListsFetchError) {
    // Display the error
    resultStr = [self.taskListsFetchError description];

    // Also display any server data present
    NSData *errData = [[self.taskListsFetchError userInfo] objectForKey:kGTMHTTPFetcherStatusDataKey];
    if (errData) {
      NSString *dataStr = [[[NSString alloc] initWithData:errData
                                                 encoding:NSUTF8StringEncoding] autorelease];
      resultStr = [resultStr stringByAppendingFormat:@"\n%@", dataStr];
    }
  } else {
    // Display the selected item
    GTLTasksTaskList *item = [self selectedTaskList];
    if (item) {
      resultStr = [item description];
    }
  }
  [taskListsResultTextView_ setString:resultStr];

  //
  // Tasks outline
  //
  [tasksOutline_ reloadData];

  if (self.tasksTicket != nil) {
    [tasksProgressIndicator_ startAnimation:self];
  } else {
    [tasksProgressIndicator_ stopAnimation:self];
  }

  // Get the description of the selected item, or the feed fetch error
  resultStr = @"";
  if (self.tasksFetchError) {
    resultStr = [self.tasksFetchError description];
  } else {
    GTLTasksTask *item = [self selectedTask];
    if (item) {
      resultStr = [item description];
    }
  }
  [tasksResultTextView_ setString:resultStr];

  // Enable task lists buttons
  BOOL hasTaskLists = (self.taskLists != nil);
  BOOL isTaskListSelected = ([self selectedTaskList] != nil);
  BOOL hasTaskListTitle = ([[taskListNameField_ stringValue] length] > 0);

  [addTaskListButton_ setEnabled:(hasTaskListTitle && hasTaskLists)];
  [renameTaskListButton_ setEnabled:(hasTaskListTitle && isTaskListSelected)];
  [deleteTaskListButton_ setEnabled:(isTaskListSelected)];

  BOOL isFetchingTaskLists = (self.taskListsTicket != nil);
  BOOL isEditingTaskList = (self.editTaskListTicket != nil);
  [taskListsCancelButton_ setEnabled:(isFetchingTaskLists || isEditingTaskList)];

  // Enable tasks buttons
  GTLTasksTask *selectedTask = [self selectedTask];
  BOOL hasTasks = (self.tasks != nil);
  BOOL isTaskSelected = (selectedTask != nil);
  BOOL hasTaskTitle = ([[taskNameField_ stringValue] length] > 0);

  [addTaskButton_ setEnabled:(hasTaskTitle && hasTasks)];
  [renameTaskButton_ setEnabled:(hasTaskTitle && isTaskSelected)];
  [deleteTaskButton_ setEnabled:(isTaskSelected)];

  BOOL isCompleted = [selectedTask.status isEqual:kTaskStatusCompleted];
  [completeTaskButton_ setEnabled:isTaskSelected];
  [completeTaskButton_ setTitle:(isCompleted ? @"Uncomplete" : @"Complete")];

  NSArray *completedTasks = [self completedTasks];
  NSUInteger numberOfCompletedTasks = [completedTasks count];
  [clearTasksButton_ setEnabled:(numberOfCompletedTasks > 0)];

  NSUInteger numberOfTasks = [self.tasks.items count];
  [deleteAllTasksButton_ setEnabled:(numberOfTasks > 0)];

  BOOL areAllTasksCompleted = (numberOfCompletedTasks == numberOfTasks);
  [completeAllTasksButton_ setEnabled:(numberOfTasks > 0)];
  [completeAllTasksButton_ setTitle:(areAllTasksCompleted ?
                                     @"Uncomplete All" : @"Complete All")];

  BOOL isFetchingTasks = (self.tasksTicket != nil);
  BOOL isEditingTask = (self.editTaskTicket != nil);
  [tasksCancelButton_ setEnabled:(isFetchingTasks || isEditingTask)];

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
  // The task list selection changed
  [self fetchTasksForSelectedList];
}

// Table view data source methods
- (int)numberOfRowsInTableView:(NSTableView *)tableView {
  return [self.taskLists.items count];
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(int)row {
  GTLTasksTaskList *item = [self.taskLists itemAtIndex:row];
  NSString *title = item.title;
  return title;
}

#pragma mark OutlineView delegate and data source methods

- (NSArray *)childTasksOfItem:(GTLTasksTask *)item {
  // This is a utility routine for getting the children of a task
  // list or of a task
  //
  // We added child task arrays by calling -createPropertiesForTasks
  // above after fetching the tasks
  NSArray *children;
  if (item == nil) {
    // item is the top level
    children = [self taskChildrenForObject:self.tasks];
  } else {
    // item is a task entry
    children = [self taskChildrenForObject:item];
  }
  return children;
}

- (id)outlineView:(NSOutlineView *)outlineView child:(NSInteger)index ofItem:(id)item {
  NSArray *childTasks = [self childTasksOfItem:item];
  GTLTasksTask *task = [childTasks objectAtIndex:index];
  return task;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isItemExpandable:(id)item {
  NSArray *childTasks = [self childTasksOfItem:item];
  NSUInteger numberOfChildren = [childTasks count];
  return (numberOfChildren > 0);
}

- (NSInteger)outlineView:(NSOutlineView *)outlineView numberOfChildrenOfItem:(id)item {
  NSArray *childTasks = [self childTasksOfItem:item];
  NSUInteger numberOfChildren = [childTasks count];
  return numberOfChildren;
}

- (id)outlineView:(NSOutlineView *)outlineView objectValueForTableColumn:(NSTableColumn *)tableColumn byItem:(id)item {
  GTLTasksTask *task = (GTLTasksTask *)item;
  NSString *str = task.title;

  if ([str length] == 0) {
    // If the task has no title, make one from its identifier
    str = [NSString stringWithFormat:@"<task %@>", task.identifier];
  }

  if ([task.notes length] > 0) {
    // append a pencil to indicate this task has notes
    str = [str stringByAppendingString:@" \u270E"];
  }

  if ([task.status isEqual:kTaskStatusCompleted]) {
    // append a checkmark to indicate this task has been completed
    str = [str stringByAppendingString:@" \u2713"];
  }

  if ([task.hidden boolValue]) {
    // append a moon to indicate this task is hidden
    str = [str stringByAppendingString:@" \u263E"];
  }

  if ([task.deleted boolValue]) {
    // prepend an X mark if this is a deleted task
    str = [NSString stringWithFormat:@"\u2717 %@", str];
  }
  return str;
}

- (void)outlineViewSelectionDidChange:(NSNotification *)notification {
  // We want to update the UI when the selection changes, but we need to avoid
  // doing so immediately as a result of selection changes from reloading the
  // data when updating the UI, since that would cause recursive calls to
  // reloadData
  [self performSelector:@selector(updateUI)
             withObject:nil
             afterDelay:0.01];
}

// OutlineView Dragging Support

- (NSDragOperation)draggingSourceOperationMaskForLocal:(BOOL)flag {
  return NSDragOperationMove;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView
         writeItems:(NSArray *)items
       toPasteboard:(NSPasteboard *)pasteboard {
  // Only one task can be selected, so one task will be in the items;
  // we'll put its identifier into an array for the pasteboard
  NSArray *identifiers = [items valueForKey:@"identifier"];

  [pasteboard clearContents];
  [pasteboard writeObjects:identifiers];
  return YES;
}

- (NSDragOperation)outlineView:(NSOutlineView *)outlineView
                  validateDrop:(id <NSDraggingInfo>)info
                  proposedItem:(id)item
            proposedChildIndex:(NSInteger)index {
  // Verify that the item being dragged is a task ID
  NSPasteboard *pb = [info draggingPasteboard];
  NSArray *classes = [NSArray arrayWithObject:[NSString class]];
  NSArray *taskIDs = [pb readObjectsForClasses:classes
                                       options:nil];
  if ([taskIDs count] == 1) {
    NSString *taskID = [taskIDs lastObject];
    GTLTasksTask *task = [self taskWithIdentifier:taskID
                                        fromTasks:self.tasks];
    if (task != nil) {
      // There is a task object for this ID
      return NSDragOperationMove;
    }
  }
  return NSDragOperationNone;
}

- (BOOL)outlineView:(NSOutlineView *)outlineView
         acceptDrop:(id <NSDraggingInfo>)info
               item:(id)item
         childIndex:(NSInteger)index {
  // A task was dropped at a new location
  NSPasteboard *pb = [info draggingPasteboard];
  NSArray *classes = [NSArray arrayWithObject:[NSString class]];
  NSArray *taskIDs = [pb readObjectsForClasses:classes
                                       options:nil];

  [self moveTaskWithIdentifier:[taskIDs objectAtIndex:0]
                    toParentID:[item identifier]
                         index:index];
  return YES;
}

@end

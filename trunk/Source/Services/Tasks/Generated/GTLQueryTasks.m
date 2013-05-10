/* Copyright (c) 2013 Google Inc.
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
//  GTLQueryTasks.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Tasks API (tasks/v1)
// Description:
//   Lets you manage your tasks and task lists.
// Documentation:
//   https://developers.google.com/google-apps/tasks/firstapp
// Classes:
//   GTLQueryTasks (14 custom class methods, 15 custom properties)

#import "GTLQueryTasks.h"

#import "GTLTasksTask.h"
#import "GTLTasksTaskList.h"
#import "GTLTasksTaskLists.h"
#import "GTLTasksTasks.h"

@implementation GTLQueryTasks

@dynamic completedMax, completedMin, dueMax, dueMin, fields, maxResults,
         pageToken, parent, previous, showCompleted, showDeleted, showHidden,
         task, tasklist, updatedMin;

#pragma mark -
#pragma mark "tasklists" methods
// These create a GTLQueryTasks object.

+ (id)queryForTasklistsDeleteWithTasklist:(NSString *)tasklist {
  NSString *methodName = @"tasks.tasklists.delete";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.tasklist = tasklist;
  return query;
}

+ (id)queryForTasklistsGetWithTasklist:(NSString *)tasklist {
  NSString *methodName = @"tasks.tasklists.get";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.tasklist = tasklist;
  query.expectedObjectClass = [GTLTasksTaskList class];
  return query;
}

+ (id)queryForTasklistsInsertWithObject:(GTLTasksTaskList *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"tasks.tasklists.insert";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLTasksTaskList class];
  return query;
}

+ (id)queryForTasklistsList {
  NSString *methodName = @"tasks.tasklists.list";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLTasksTaskLists class];
  return query;
}

+ (id)queryForTasklistsPatchWithObject:(GTLTasksTaskList *)object
                              tasklist:(NSString *)tasklist {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"tasks.tasklists.patch";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.tasklist = tasklist;
  query.expectedObjectClass = [GTLTasksTaskList class];
  return query;
}

+ (id)queryForTasklistsUpdateWithObject:(GTLTasksTaskList *)object
                               tasklist:(NSString *)tasklist {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"tasks.tasklists.update";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.tasklist = tasklist;
  query.expectedObjectClass = [GTLTasksTaskList class];
  return query;
}

#pragma mark -
#pragma mark "tasks" methods
// These create a GTLQueryTasks object.

+ (id)queryForTasksClearWithTasklist:(NSString *)tasklist {
  NSString *methodName = @"tasks.tasks.clear";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.tasklist = tasklist;
  return query;
}

+ (id)queryForTasksDeleteWithTasklist:(NSString *)tasklist
                                 task:(NSString *)task {
  NSString *methodName = @"tasks.tasks.delete";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.tasklist = tasklist;
  query.task = task;
  return query;
}

+ (id)queryForTasksGetWithTasklist:(NSString *)tasklist
                              task:(NSString *)task {
  NSString *methodName = @"tasks.tasks.get";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.tasklist = tasklist;
  query.task = task;
  query.expectedObjectClass = [GTLTasksTask class];
  return query;
}

+ (id)queryForTasksInsertWithObject:(GTLTasksTask *)object
                           tasklist:(NSString *)tasklist {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"tasks.tasks.insert";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.tasklist = tasklist;
  query.expectedObjectClass = [GTLTasksTask class];
  return query;
}

+ (id)queryForTasksListWithTasklist:(NSString *)tasklist {
  NSString *methodName = @"tasks.tasks.list";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.tasklist = tasklist;
  query.expectedObjectClass = [GTLTasksTasks class];
  return query;
}

+ (id)queryForTasksMoveWithTasklist:(NSString *)tasklist
                               task:(NSString *)task {
  NSString *methodName = @"tasks.tasks.move";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.tasklist = tasklist;
  query.task = task;
  query.expectedObjectClass = [GTLTasksTask class];
  return query;
}

+ (id)queryForTasksPatchWithObject:(GTLTasksTask *)object
                          tasklist:(NSString *)tasklist
                              task:(NSString *)task {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"tasks.tasks.patch";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.tasklist = tasklist;
  query.task = task;
  query.expectedObjectClass = [GTLTasksTask class];
  return query;
}

+ (id)queryForTasksUpdateWithObject:(GTLTasksTask *)object
                           tasklist:(NSString *)tasklist
                               task:(NSString *)task {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"tasks.tasks.update";
  GTLQueryTasks *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.tasklist = tasklist;
  query.task = task;
  query.expectedObjectClass = [GTLTasksTask class];
  return query;
}

@end

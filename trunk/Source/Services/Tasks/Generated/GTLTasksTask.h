/* Copyright (c) 2015 Google Inc.
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
//  GTLTasksTask.h
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
//   GTLTasksTask (0 custom class methods, 15 custom properties)
//   GTLTasksTaskLinksItem (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLTasksTaskLinksItem;

// ----------------------------------------------------------------------------
//
//   GTLTasksTask
//

@interface GTLTasksTask : GTLObject

// Completion date of the task (as a RFC 3339 timestamp). This field is omitted
// if the task has not been completed.
@property (nonatomic, retain) GTLDateTime *completed;

// Flag indicating whether the task has been deleted. The default if False.
@property (nonatomic, retain) NSNumber *deleted;  // boolValue

// Due date of the task (as a RFC 3339 timestamp). Optional.
@property (nonatomic, retain) GTLDateTime *due;

// ETag of the resource.
@property (nonatomic, copy) NSString *ETag;

// Flag indicating whether the task is hidden. This is the case if the task had
// been marked completed when the task list was last cleared. The default is
// False. This field is read-only.
@property (nonatomic, retain) NSNumber *hidden;  // boolValue

// Task identifier.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Type of the resource. This is always "tasks#task".
@property (nonatomic, copy) NSString *kind;

// Collection of links. This collection is read-only.
@property (nonatomic, retain) NSArray *links;  // of GTLTasksTaskLinksItem

// Notes describing the task. Optional.
@property (nonatomic, copy) NSString *notes;

// Parent task identifier. This field is omitted if it is a top-level task. This
// field is read-only. Use the "move" method to move the task under a different
// parent or to the top level.
@property (nonatomic, copy) NSString *parent;

// String indicating the position of the task among its sibling tasks under the
// same parent task or at the top level. If this string is greater than another
// task's corresponding position string according to lexicographical ordering,
// the task is positioned after the other task under the same parent task (or at
// the top level). This field is read-only. Use the "move" method to move the
// task to another position.
@property (nonatomic, copy) NSString *position;

// URL pointing to this task. Used to retrieve, update, or delete this task.
@property (nonatomic, copy) NSString *selfLink;

// Status of the task. This is either "needsAction" or "completed".
@property (nonatomic, copy) NSString *status;

// Title of the task.
@property (nonatomic, copy) NSString *title;

// Last modification time of the task (as a RFC 3339 timestamp).
@property (nonatomic, retain) GTLDateTime *updated;

@end


// ----------------------------------------------------------------------------
//
//   GTLTasksTaskLinksItem
//

@interface GTLTasksTaskLinksItem : GTLObject

// The description. In HTML speak: Everything between <a> and </a>.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// The URL.
@property (nonatomic, copy) NSString *link;

// Type of the link, e.g. "email".
@property (nonatomic, copy) NSString *type;

@end

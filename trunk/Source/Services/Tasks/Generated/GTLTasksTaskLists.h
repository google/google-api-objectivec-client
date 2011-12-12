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
//  GTLTasksTaskLists.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Tasks API (tasks/v1)
// Description:
//   Lets you manage your tasks and task lists.
// Documentation:
//   http://code.google.com/apis/tasks/v1/using.html
// Classes:
//   GTLTasksTaskLists (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLTasksTaskList;

// ----------------------------------------------------------------------------
//
//   GTLTasksTaskLists
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLTasksTaskLists : GTLCollectionObject

// ETag of the resource.
@property (copy) NSString *ETag;

// Collection of task lists.
@property (retain) NSArray *items;  // of GTLTasksTaskList

// Type of the resource. This is always "tasks#taskLists".
@property (copy) NSString *kind;

// Token that can be used to request the next page of this result.
@property (copy) NSString *nextPageToken;

@end

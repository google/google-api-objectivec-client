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
//  GTLTasksTask.m
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

#import "GTLTasksTask.h"

// ----------------------------------------------------------------------------
//
//   GTLTasksTask
//

@implementation GTLTasksTask
@dynamic completed, deleted, due, ETag, hidden, identifier, kind, links, notes,
         parent, position, selfLink, status, title, updated;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"etag", @"ETag",
      @"id", @"identifier",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLTasksTaskLinksItem class]
                                forKey:@"links"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"tasks#task"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLTasksTaskLinksItem
//

@implementation GTLTasksTaskLinksItem
@dynamic descriptionProperty, link, type;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"description"
                                forKey:@"descriptionProperty"];
  return map;
}

@end

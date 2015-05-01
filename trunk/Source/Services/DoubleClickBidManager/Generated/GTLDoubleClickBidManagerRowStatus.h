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
//  GTLDoubleClickBidManagerRowStatus.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   DoubleClick Bid Manager API (doubleclickbidmanager/v1)
// Description:
//   API for viewing and managing your reports in DoubleClick Bid Manager.
// Documentation:
//   https://developers.google.com/bid-manager/
// Classes:
//   GTLDoubleClickBidManagerRowStatus (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLDoubleClickBidManagerRowStatus
//

// Represents the upload status of a row in the request.

@interface GTLDoubleClickBidManagerRowStatus : GTLObject

// Whether the stored entity is changed as a result of upload.
@property (nonatomic, retain) NSNumber *changed;  // boolValue

// Entity Id.
@property (nonatomic, retain) NSNumber *entityId;  // longLongValue

// Entity name.
@property (nonatomic, copy) NSString *entityName;

// Reasons why the entity can't be uploaded.
@property (nonatomic, retain) NSArray *errors;  // of NSString

// Whether the entity is persisted.
@property (nonatomic, retain) NSNumber *persisted;  // boolValue

// Row number.
@property (nonatomic, retain) NSNumber *rowNumber;  // intValue

@end

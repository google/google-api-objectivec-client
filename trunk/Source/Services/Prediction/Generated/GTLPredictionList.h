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
//  GTLPredictionList.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Prediction API (prediction/v1.6)
// Description:
//   Lets you access a cloud hosted machine learning service that makes it easy
//   to build smart apps
// Documentation:
//   https://developers.google.com/prediction/docs/developer-guide
// Classes:
//   GTLPredictionList (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLPredictionInsert2;

// ----------------------------------------------------------------------------
//
//   GTLPredictionList
//

// This class supports NSFastEnumeration over its "items" property. It also
// supports -itemAtIndex: to retrieve individual objects from "items".

@interface GTLPredictionList : GTLCollectionObject

// List of models.
@property (nonatomic, retain) NSArray *items;  // of GTLPredictionInsert2

// What kind of resource this is.
@property (nonatomic, copy) NSString *kind;

// Pagination token to fetch the next page, if one exists.
@property (nonatomic, copy) NSString *nextPageToken;

// A URL to re-request this resource.
@property (nonatomic, copy) NSString *selfLink;

@end

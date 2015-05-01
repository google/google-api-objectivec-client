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
//  GTLQueryQPXExpress.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   QPX Express API (qpxExpress/v1)
// Description:
//   Lets you find the least expensive flights between an origin and a
//   destination.
// Documentation:
//   http://developers.google.com/qpx-express
// Classes:
//   GTLQueryQPXExpress (1 custom class methods, 2 custom properties)

#import "GTLQueryQPXExpress.h"

#import "GTLQPXExpressTripOptionsRequest.h"
#import "GTLQPXExpressTripsSearchResponse.h"

@implementation GTLQueryQPXExpress

@dynamic fields, request;

#pragma mark -
#pragma mark "trips" methods
// These create a GTLQueryQPXExpress object.

+ (instancetype)queryForTripsSearch {
  NSString *methodName = @"qpxExpress.trips.search";
  GTLQueryQPXExpress *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLQPXExpressTripsSearchResponse class];
  return query;
}

@end

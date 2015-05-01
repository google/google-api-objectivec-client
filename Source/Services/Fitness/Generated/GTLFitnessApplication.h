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
//  GTLFitnessApplication.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Fitness (fitness/v1)
// Description:
//   Google Fit API
// Documentation:
//   https://developers.google.com/fit/rest/
// Classes:
//   GTLFitnessApplication (0 custom class methods, 4 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLFitnessApplication
//

// See: google3/java/com/google/android/apps/heart/platform/api/Application.java

@interface GTLFitnessApplication : GTLObject

// An optional URI that can be used to link back to the application.
@property (nonatomic, copy) NSString *detailsUrl;

// The name of this application. This is required for REST clients, but we do
// not enforce uniqueness of this name. It is provided as a matter of
// convenience for other developers who would like to identify which REST
// created an Application or Data Source.
@property (nonatomic, copy) NSString *name;

// Package name for this application. This is used as a unique identifier when
// created by Android applications, but cannot be specified by REST clients.
// REST clients will have their developer project number reflected into the Data
// Source data stream IDs, instead of the packageName.
@property (nonatomic, copy) NSString *packageName;

// Version of the application. You should update this field whenever the
// application changes in a way that affects the computation of the data.
@property (nonatomic, copy) NSString *version;

@end

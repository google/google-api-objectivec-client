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
//  GTLFitnessListSessionsResponse.h
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
//   GTLFitnessListSessionsResponse (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLFitnessSession;

// ----------------------------------------------------------------------------
//
//   GTLFitnessListSessionsResponse
//

@interface GTLFitnessListSessionsResponse : GTLObject

// If includeDeleted is set to true in the request, this list will contain
// sessions deleted with original end times that are within the startTime and
// endTime frame.
@property (nonatomic, retain) NSArray *deletedSession;  // of GTLFitnessSession

// The continuation token, which is used to page through large result sets.
// Provide this value in a subsequent request to return the next page of
// results.
@property (nonatomic, copy) NSString *nextPageToken;

// Sessions with an end time that is between startTime and endTime of the
// request.
@property (nonatomic, retain) NSArray *session;  // of GTLFitnessSession

@end

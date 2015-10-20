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
//  GTLBigqueryStreamingbuffer.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   BigQuery API (bigquery/v2)
// Description:
//   A data platform for customers to create, manage, share and query data.
// Documentation:
//   https://cloud.google.com/bigquery/
// Classes:
//   GTLBigqueryStreamingbuffer (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLBigqueryStreamingbuffer
//

@interface GTLBigqueryStreamingbuffer : GTLObject

// [Output-only] A lower-bound estimate of the number of bytes currently in the
// streaming buffer.
@property (nonatomic, retain) NSNumber *estimatedBytes;  // unsignedLongLongValue

// [Output-only] A lower-bound estimate of the number of rows currently in the
// streaming buffer.
@property (nonatomic, retain) NSNumber *estimatedRows;  // unsignedLongLongValue

// [Output-only] Contains the timestamp of the oldest entry in the streaming
// buffer, in milliseconds since the epoch, if the streaming buffer is
// available.
@property (nonatomic, retain) NSNumber *oldestEntryTime;  // unsignedLongLongValue

@end

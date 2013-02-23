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
//  GTLYouTubeVideoProcessingDetailsProcessingProgress.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube Data API (youtube/v3)
// Description:
//   Programmatic access to YouTube features.
// Documentation:
//   https://developers.google.com/youtube/v3
// Classes:
//   GTLYouTubeVideoProcessingDetailsProcessingProgress (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLYouTubeVideoProcessingDetailsProcessingProgress
//

// Video processing progress and completion time estimate.

@interface GTLYouTubeVideoProcessingDetailsProcessingProgress : GTLObject

// Number of parts already processed. Progress expressed in percent should be
// computed as: 100 * parts_processed / parts_total.
@property (retain) NSNumber *partsProcessed;  // unsignedLongLongValue

// An estimate of total number of parts to process. The number might be updated
// with more precise estimates as the processing progresses.
@property (retain) NSNumber *partsTotal;  // unsignedLongLongValue

// Estimated time till video processing is complete, in milliseconds.
@property (retain) NSNumber *timeLeftMs;  // unsignedLongLongValue

@end

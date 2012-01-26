/* Copyright (c) 2012 Google Inc.
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
//  GTLOrkutConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Orkut API (orkut/v2)
// Description:
//   Lets you manage activities, comments and badges in Orkut. More stuff coming
//   in time.
// Documentation:
//   http://code.google.com/apis/orkut/v2/reference.html

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// Manage your Orkut activity
GTL_EXTERN NSString * const kGTLAuthScopeOrkut;          // "https://www.googleapis.com/auth/orkut"
// View your Orkut data
GTL_EXTERN NSString * const kGTLAuthScopeOrkutReadonly;  // "https://www.googleapis.com/auth/orkut.readonly"

// Collection
GTL_EXTERN NSString * const kGTLOrkutCollectionAll;     // "all"
GTL_EXTERN NSString * const kGTLOrkutCollectionScraps;  // "scraps"
GTL_EXTERN NSString * const kGTLOrkutCollectionStream;  // "stream"

// OrderBy
GTL_EXTERN NSString * const kGTLOrkutOrderByAscending;   // "ascending"
GTL_EXTERN NSString * const kGTLOrkutOrderByDescending;  // "descending"
GTL_EXTERN NSString * const kGTLOrkutOrderById;          // "id"
GTL_EXTERN NSString * const kGTLOrkutOrderByRanked;      // "ranked"

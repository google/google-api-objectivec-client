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
//  GTLBatchQuery.h
//

#import "GTLQuery.h"

@interface GTLBatchQuery : NSObject <GTLQueryProtocol> {
 @private
  NSMutableArray *queries_;
  NSMutableDictionary *requestIDMap_;
  BOOL skipAuthorization_;
}

// Queries included in this batch.  Each query should have a unique requestID.
@property (retain) NSArray *queries;

// Clients may set this to NO to disallow authorization. Defaults to YES.
@property (assign) BOOL shouldSkipAuthorization;

+ (id)batchQuery;
+ (id)batchQueryWithQueries:(NSArray *)array;

- (void)addQuery:(GTLQuery *)query;

- (GTLQuery *)queryForRequestID:(NSString *)requestID;

@end

/* Copyright (c) 2014 Google Inc.
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
//  GTLQueryAppState.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google App State API (appstate/v1)
// Description:
//   The Google App State API.
// Documentation:
//   https://developers.google.com/games/services/web/api/states
// Classes:
//   GTLQueryAppState (5 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLAppStateUpdateRequest;

@interface GTLQueryAppState : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *currentDataVersion;
@property (copy) NSString *currentStateVersion;
@property (assign) BOOL includeData;
@property (assign) NSInteger stateKey;

#pragma mark -
#pragma mark "states" methods
// These create a GTLQueryAppState object.

// Method: appstate.states.clear
// Clears (sets to empty) the data for the passed key if and only if the passed
// version matches the currently stored version. This method results in a
// conflict error on version mismatch.
//  Required:
//   stateKey: The key for the data to be retrieved. (0..3)
//  Optional:
//   currentDataVersion: The version of the data to be cleared. Version strings
//     are returned by the server.
//  Authorization scope(s):
//   kGTLAuthScopeAppState
// Fetches a GTLAppStateWriteResult.
+ (id)queryForStatesClearWithStateKey:(NSInteger)stateKey;

// Method: appstate.states.delete
// Deletes a key and the data associated with it. The key is removed and no
// longer counts against the key quota. Note that since this method is not safe
// in the face of concurrent modifications, it should only be used for
// development and testing purposes. Invoking this method in shipping code can
// result in data loss and data corruption.
//  Required:
//   stateKey: The key for the data to be retrieved. (0..3)
//  Authorization scope(s):
//   kGTLAuthScopeAppState
+ (id)queryForStatesDeleteWithStateKey:(NSInteger)stateKey;

// Method: appstate.states.get
// Retrieves the data corresponding to the passed key. If the key does not exist
// on the server, an HTTP 404 will be returned.
//  Required:
//   stateKey: The key for the data to be retrieved. (0..3)
//  Authorization scope(s):
//   kGTLAuthScopeAppState
// Fetches a GTLAppStateGetResponse.
+ (id)queryForStatesGetWithStateKey:(NSInteger)stateKey;

// Method: appstate.states.list
// Lists all the states keys, and optionally the state data.
//  Optional:
//   includeData: Whether to include the full data in addition to the version
//     number (Default false)
//  Authorization scope(s):
//   kGTLAuthScopeAppState
// Fetches a GTLAppStateListResponse.
+ (id)queryForStatesList;

// Method: appstate.states.update
// Update the data associated with the input key if and only if the passed
// version matches the currently stored version. This method is safe in the face
// of concurrent writes. Maximum per-key size is 128KB.
//  Required:
//   stateKey: The key for the data to be retrieved. (0..3)
//  Optional:
//   currentStateVersion: The version of the app state your application is
//     attempting to update. If this does not match the current version, this
//     method will return a conflict error. If there is no data stored on the
//     server for this key, the update will succeed irrespective of the value of
//     this parameter.
//  Authorization scope(s):
//   kGTLAuthScopeAppState
// Fetches a GTLAppStateWriteResult.
+ (id)queryForStatesUpdateWithObject:(GTLAppStateUpdateRequest *)object
                            stateKey:(NSInteger)stateKey;

@end

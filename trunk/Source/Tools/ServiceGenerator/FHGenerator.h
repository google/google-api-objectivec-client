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

#import <Foundation/Foundation.h>

#import "GTLDiscovery.h"

typedef enum {
  kFHGeneratorHandlerMessageError = 1,
  kFHGeneratorHandlerMessageWarning,
  kFHGeneratorHandlerMessageInfo
} FHGeneratorHandlerMessageType;


@interface FHGenerator : NSObject 

@property (readonly, retain) GTLDiscoveryRpcDescription* api;
@property (readonly, assign) NSUInteger verboseLevel;
@property (readonly, assign) BOOL allowRootURLOverrides;

+ (id)generatorForApi:(GTLDiscoveryRpcDescription *)api
         verboseLevel:(NSUInteger)verboseLevel
allowRootURLOverrides:(BOOL)allowRootURLOverrides
formattedNameOverride:(NSString *)formattedNameOverride;

// Keys are the file names; values are the contents of the files.
- (NSDictionary *)generateFilesWithHandler:(void (^)(FHGeneratorHandlerMessageType msgType,
                                                     NSString *message))messageHandler;

// The API name formatted for use as a directory name.
- (NSString *)formattedApiName;

@end

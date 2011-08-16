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
//  GTLObject.m
//

#include <objc/runtime.h>

#import "GTLUploadParameters.h"

@implementation GTLUploadParameters

@synthesize MIMEType = MIMEType_,
            data = data_,
            fileHandle = fileHandle_,
            shouldSendUploadOnly = shouldSendUploadOnly_;

+ (GTLUploadParameters *)uploadParametersWithData:(NSData *)data
                                         MIMEType:(NSString *)mimeType {
  GTLUploadParameters *params = [[[GTLUploadParameters alloc] init] autorelease];
  params.data = data;
  params.MIMEType = mimeType;
  return params;
}

+ (GTLUploadParameters *)uploadParametersWithFileHandleData:(NSFileHandle *)fileHandle
                                                   MIMEType:(NSString *)mimeType {
  GTLUploadParameters *params = [[[GTLUploadParameters alloc] init] autorelease];
  params.fileHandle = fileHandle;
  params.MIMEType = mimeType;
  return params;
}

- (id)copyWithZone:(NSZone *)zone {
  GTLUploadParameters *newParams = [[[self class] allocWithZone:zone] init];
  newParams.MIMEType = self.MIMEType;
  newParams.data = self.data;
  newParams.fileHandle = self.fileHandle;
  newParams.shouldSendUploadOnly = self.shouldSendUploadOnly;
  return newParams;
}

- (void)dealloc {
  [MIMEType_ release];
  [data_ release];
  [fileHandle_ release];

  [super dealloc];
}

@end

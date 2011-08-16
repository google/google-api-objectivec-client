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
//  GTLUploadParameters.h
//

#import <Foundation/Foundation.h>

#import "GTLDefines.h"

@interface GTLUploadParameters : NSObject <NSCopying> {
 @private
  NSString *MIMEType_;
  NSData *data_;
  NSFileHandle *fileHandle_;
  BOOL shouldSendUploadOnly_;
}

@property (copy) NSString *MIMEType;
@property (retain) NSData *data;
@property (retain) NSFileHandle *fileHandle;
@property (assign) BOOL shouldSendUploadOnly;

+ (GTLUploadParameters *)uploadParametersWithData:(NSData *)data
                                         MIMEType:(NSString *)mimeType;

+ (GTLUploadParameters *)uploadParametersWithFileHandleData:(NSFileHandle *)fileHandle
                                                   MIMEType:(NSString *)mimeType;

@end

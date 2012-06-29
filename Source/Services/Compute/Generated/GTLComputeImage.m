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
//  GTLComputeImage.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Compute Engine API (compute/v1beta12)
// Description:
//   API for the Google Compute Engine service.
// Documentation:
//   https://developers.google.com/compute/docs/reference/v1beta12
// Classes:
//   GTLComputeImage (0 custom class methods, 10 custom properties)
//   GTLComputeImageDiskSnapshot (0 custom class methods, 1 custom properties)
//   GTLComputeImageRawDisk (0 custom class methods, 3 custom properties)

#import "GTLComputeImage.h"

// ----------------------------------------------------------------------------
//
//   GTLComputeImage
//

@implementation GTLComputeImage
@dynamic creationTimestamp, descriptionProperty, diskSnapshot, identifier, kind,
         name, preferredKernel, rawDisk, selfLink, sourceType;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"description", @"descriptionProperty",
      @"id", @"identifier",
      nil];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"compute#image"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLComputeImageDiskSnapshot
//

@implementation GTLComputeImageDiskSnapshot
@dynamic source;
@end


// ----------------------------------------------------------------------------
//
//   GTLComputeImageRawDisk
//

@implementation GTLComputeImageRawDisk
@dynamic containerType, sha1Checksum, source;
@end

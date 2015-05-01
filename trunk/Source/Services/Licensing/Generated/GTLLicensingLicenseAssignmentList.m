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
//  GTLLicensingLicenseAssignmentList.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Enterprise License Manager API (licensing/v1)
// Description:
//   Licensing API to view and manage license for your domain.
// Documentation:
//   https://developers.google.com/google-apps/licensing/
// Classes:
//   GTLLicensingLicenseAssignmentList (0 custom class methods, 4 custom properties)

#import "GTLLicensingLicenseAssignmentList.h"

#import "GTLLicensingLicenseAssignment.h"

// ----------------------------------------------------------------------------
//
//   GTLLicensingLicenseAssignmentList
//

@implementation GTLLicensingLicenseAssignmentList
@dynamic ETag, items, kind, nextPageToken;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"ETag" : @"etag"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"items" : [GTLLicensingLicenseAssignment class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"licensing#licenseAssignmentList"];
}

@end

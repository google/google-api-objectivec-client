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
//  GTLShoppingModelDebug.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Search API For Shopping (shopping/v1)
// Description:
//   Lets you search over product data.
// Documentation:
//   http://code.google.com/apis/shopping/search/v1/getting_started.html
// Classes:
//   GTLShoppingModelDebug (0 custom class methods, 7 custom properties)
//   GTLShoppingModelDebugBackendTimesItem (0 custom class methods, 4 custom properties)

#import "GTLShoppingModelDebug.h"

// ----------------------------------------------------------------------------
//
//   GTLShoppingModelDebug
//

@implementation GTLShoppingModelDebug
@dynamic backendTimes, elapsedMillis, facetsRequest, facetsResponse,
         rdcResponse, searchRequest, searchResponse;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLShoppingModelDebugBackendTimesItem class]
                                forKey:@"backendTimes"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLShoppingModelDebugBackendTimesItem
//

@implementation GTLShoppingModelDebugBackendTimesItem
@dynamic elapsedMillis, hostName, name, serverMillis;
@end

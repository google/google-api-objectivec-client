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
//  GTLErrorObject.m
//

#import "GTLErrorObject.h"

@implementation GTLErrorObject

@dynamic code;
@dynamic message;
@dynamic data;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = [NSDictionary dictionaryWithObject:[GTLErrorObjectData class]
                                                  forKey:@"data"];
  return map;
}

@end

@implementation GTLErrorObjectData
@dynamic domain;
@dynamic reason;
@dynamic message;
@dynamic location;
@end



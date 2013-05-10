/* Copyright (c) 2013 Google Inc.
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
//  GTLDiscoveryJsonSchema.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   APIs Discovery Service (discovery/v1)
// Description:
//   Lets you discover information about other Google APIs, such as what APIs
//   are available, the resource and method details for each API.
// Documentation:
//   https://developers.google.com/discovery/
// Classes:
//   GTLDiscoveryJsonSchema (0 custom class methods, 19 custom properties)
//   GTLDiscoveryJsonSchemaAnnotations (0 custom class methods, 1 custom properties)
//   GTLDiscoveryJsonSchemaProperties (0 custom class methods, 0 custom properties)

#import "GTLDiscoveryJsonSchema.h"

// ----------------------------------------------------------------------------
//
//   GTLDiscoveryJsonSchema
//

@implementation GTLDiscoveryJsonSchema
@dynamic xRef, additionalPropertiesProperty, annotations, defaultProperty,
         descriptionProperty, enumProperty, enumDescriptions, format,
         identifier, items, location, maximum, minimum, pattern, properties,
         readOnly, repeated, required, type;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"additionalProperties", @"additionalPropertiesProperty",
      @"default", @"defaultProperty",
      @"description", @"descriptionProperty",
      @"enum", @"enumProperty",
      @"id", @"identifier",
      @"$ref", @"xRef",
      nil];
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [NSString class], @"enum",
      [NSString class], @"enumDescriptions",
      nil];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryJsonSchemaAnnotations
//

@implementation GTLDiscoveryJsonSchemaAnnotations
@dynamic required;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[NSString class]
                                forKey:@"required"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryJsonSchemaProperties
//

@implementation GTLDiscoveryJsonSchemaProperties

+ (Class)classForAdditionalProperties {
  return [GTLDiscoveryJsonSchema class];
}

@end

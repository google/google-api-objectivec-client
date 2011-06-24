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

#define GTLOBJECT_DEFINE_GLOBALS 1

#include <objc/runtime.h>

#import "GTLObject.h"
#import "GTLRuntimeCommon.h"
#import "GTLJSONParser.h"

static NSString *const kUserDataPropertyKey = @"_userData";

@interface GTLObject () <GTLRuntimeCommon>
+ (NSMutableArray *)allDeclaredProperties;
+ (NSArray *)allKnownKeys;
@end

@implementation GTLObject

@synthesize JSON = json_;
@synthesize surrogates = surrogates_;
@synthesize userProperties = userProperties_;

+ (id)object {
  return [[[self alloc] init] autorelease];
}

+ (id)objectWithJSON:(NSMutableDictionary *)dict {
  GTLObject *obj = [self object];
  obj.JSON = dict;
  return obj;
}

+ (NSDictionary *)propertyToJSONKeyMap {
  return nil;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  return nil;
}

+ (Class)classForAdditionalProperties {
  return [GTLObject class];
}

- (BOOL)isEqual:(GTLObject *)other {
  if (self == other) return YES;
  if (![other isKindOfClass:[self class]]) return NO;

  // What we're not comparing here:
  //   properties
  return GTL_AreEqualOrBothNil(json_, [other JSON]);
}

// By definition, for two objects to potentially be considered equal,
// they must have the same hash value.  The hash is mostly ignored,
// but removeObjectsInArray: in Leopard does seem to check the hash,
// and NSObject's default hash method just returns the instance pointer.
// We'll define hash here for all of our GTLObjects.
- (NSUInteger)hash {
  return (NSUInteger) (void *) [GTLObject class];
}

- (id)copyWithZone:(NSZone *)zone {
  GTLObject* newObject = [[[self class] allocWithZone:zone] init];
  CFPropertyListRef ref = CFPropertyListCreateDeepCopy(kCFAllocatorDefault,
                    json_, kCFPropertyListMutableContainers);
  [NSMakeCollectable(ref) autorelease];
  newObject.JSON = (NSMutableDictionary *)ref;
  newObject.surrogates = self.surrogates;

  // What we're not copying:
  //   userProperties
  return newObject;
}

- (NSString *)descriptionWithLocale:(id)locale {
  return [self description];
}

- (void)dealloc {
  self.JSON = nil;
  self.surrogates = nil;
  self.userProperties = nil;

  [childCache_ release];

  [super dealloc];
}

#pragma mark JSON values

- (void)setJSONValue:(id)obj forKey:(NSString *)key {
  NSMutableDictionary *dict = self.JSON;
  if (dict == nil && obj != nil) {
    dict = [NSMutableDictionary dictionaryWithCapacity:1];
    self.JSON = dict;
  }
  [dict setValue:obj forKey:key];
}

- (id)JSONValueForKey:(NSString *)key {
  id obj = [self.JSON objectForKey:key];
  return obj;
}

- (NSString *)JSONString {
  NSError *error = nil;
  NSString *str = [GTLJSONParser stringWithObject:[self JSON]
                                    humanReadable:YES
                                            error:&error];
  if (error) {
    return [error description];
  }
  return str;
}

- (NSArray *)additionalJSONKeys {
  NSArray *knownKeys = [[self class] allKnownKeys];
  NSMutableArray *result = [NSMutableArray arrayWithArray:[json_ allKeys]];
  [result removeObjectsInArray:knownKeys];
  // Return nil instead of an empty array.
  if ([result count] == 0) {
    result = nil;
  }
  return result;
}

#pragma mark Additional Properties

- (id)additionalPropertyForName:(NSString *)name {
  // Return the cached object, if any, before creating one.
  id result = [self cacheChildForKey:name];
  if (result != nil) {
    return result;
  }

  Class defaultClass = [[self class] classForAdditionalProperties];
  id jsonObj = [self JSONValueForKey:name];
  BOOL shouldCache = NO;
  if (jsonObj != nil) {
    NSDictionary *surrogates = self.surrogates;
    result = [GTLRuntimeCommon objectFromJSON:jsonObj
                                 defaultClass:defaultClass
                                   surrogates:surrogates
                                  isCacheable:&shouldCache];
  }

  [self setCacheChild:(shouldCache ? result : nil)
               forKey:name];
  return result;
}

- (void)setAdditionalProperty:(id)obj forName:(NSString *)name {
  BOOL shouldCache = NO;
  Class defaultClass = [[self class] classForAdditionalProperties];
  id json = [GTLRuntimeCommon jsonFromAPIObject:obj
                                  expectedClass:defaultClass
                                    isCacheable:&shouldCache];
  [self setJSONValue:json forKey:name];
  [self setCacheChild:(shouldCache ? obj : nil)
               forKey:name];
}

- (NSDictionary *)additionalProperties {
  NSMutableDictionary *result = [NSMutableDictionary dictionary];

  NSArray *propertyNames = [self additionalJSONKeys];
  for (NSString *name in propertyNames) {
    id obj = [self additionalPropertyForName:name];
    [result setObject:obj forKey:name];
  }

  return result;
}

#pragma mark Child Cache methods

// There is no property for childCache_ as there shouldn't be KVC/KVO
// support for it, it's an implementation detail.

- (void)setCacheChild:(id)obj forKey:(NSString *)key {
  if (childCache_ == nil && obj != nil) {
    childCache_ =
    [[NSMutableDictionary alloc] initWithObjectsAndKeys:obj, key, nil];
  } else {
    [childCache_ setValue:obj forKey:key];
  }
}

- (id)cacheChildForKey:(NSString *)key {
  id obj = [childCache_ objectForKey:key];
  return obj;
}

#pragma mark userData and user properties

- (void)setUserData:(id)userData {
  [self setProperty:userData forKey:kUserDataPropertyKey];
}

- (id)userData {
  // be sure the returned pointer has the life of the autorelease pool,
  // in case self is released immediately
  return [[[self propertyForKey:kUserDataPropertyKey] retain] autorelease];
}

- (void)setProperty:(id)obj forKey:(NSString *)key {
  if (obj == nil) {
    // user passed in nil, so delete the property
    [userProperties_ removeObjectForKey:key];
  } else {
    // be sure the property dictionary exists
    if (userProperties_ == nil) {
      self.userProperties = [NSMutableDictionary dictionary];
    }
    [userProperties_ setObject:obj forKey:key];
  }
}

- (id)propertyForKey:(NSString *)key {
  id obj = [userProperties_ objectForKey:key];

  // be sure the returned pointer has the life of the autorelease pool,
  // in case self is released immediately
  return [[obj retain] autorelease];
}

#pragma mark Support methods

+ (NSMutableArray *)allDeclaredProperties {
  NSMutableArray *array = [NSMutableArray array];

  // walk from this class up the hierarchy to GTLObject
  Class topClass = class_getSuperclass([GTLObject class]);
  for (Class currClass = self;
       currClass != topClass;
       currClass = class_getSuperclass(currClass)) {
    // step through this class's properties, and add the property names to the
    // array
    objc_property_t *properties = class_copyPropertyList(currClass, NULL);
    if (properties) {
      for (objc_property_t *prop = properties;
           *prop != NULL;
           ++prop) {
        const char *propName = property_getName(*prop);
        // We only want dynamic properties; their attributes contain ",D".
        const char *attr = property_getAttributes(*prop);
        const char *dynamicMarker = strstr(attr, ",D");
        if (dynamicMarker &&
            (dynamicMarker[2] == 0 || dynamicMarker[2] == ',' )) {
          [array addObject:[NSString stringWithUTF8String:propName]];
        }
      }
      free(properties);
    }
  }
  return array;
}

+ (NSArray *)allKnownKeys {
  NSArray *allProps = [self allDeclaredProperties];
  NSMutableArray *knownKeys = [NSMutableArray arrayWithArray:allProps];

  NSDictionary *propMap = [GTLObject propertyToJSONKeyMapForClass:[self class]];

  NSUInteger idx = 0;
  for (NSString *propName in allProps) {
    NSString *jsonKey = [propMap objectForKey:propName];
    if (jsonKey) {
      [knownKeys replaceObjectAtIndex:idx
                           withObject:jsonKey];
    }
    ++idx;
  }
  return knownKeys;
}

- (NSString *)description {
  // find the list of declared and otherwise known JSON keys for this class
  NSArray *knownKeys = [[self class] allKnownKeys];

  NSMutableString *descStr = [NSMutableString string];

  NSString *spacer = @"";
  for (NSString *key in json_) {
    NSString *value = nil;
    // show question mark for JSON keys not supported by a declared property:
    //   foo?:"Hi mom."
    NSString *qmark = [knownKeys containsObject:key] ? @"" : @"?";

    // determine property value to dislay
    id rawValue = [json_ valueForKey:key];
    if ([rawValue isKindOfClass:[NSDictionary class]]) {
      // for dictionaries, show the list of keys:
      //   {key1,key2,key3}
      NSString *subkeyList = [[rawValue allKeys] componentsJoinedByString:@","];
      value = [NSString stringWithFormat:@"{%@}", subkeyList];
    } else if ([rawValue isKindOfClass:[NSArray class]]) {
      // for arrays, show the number of items in the array:
      //   [3]
      value = [NSString stringWithFormat:@"[%lu]", [rawValue count]];
    } else if ([rawValue isKindOfClass:[NSString class]]) {
      // for strings, show the string in quotes:
      //   "Hi mom."
      value = [NSString stringWithFormat:@"\"%@\"", rawValue];
    } else {
      // for numbers, show just the number
      value = [rawValue description];
    }
    [descStr appendFormat:@"%@%@%@:%@", spacer, key, qmark, value];
    spacer = @" ";
  }

  NSString *str = [NSString stringWithFormat:@"%@ %p: {%@}",
                   [self class], self, descStr];
  return str;
}

#pragma mark Class Registration

static NSMutableDictionary *gKindMap = nil;

+ (Class)registeredObjectClassForKind:(NSString *)kind {
  Class resultClass = [gKindMap objectForKey:kind];
  return resultClass;
}

+ (void)registerObjectClassForKind:(NSString *)kind {
  // there's no autorelease pool in place at +load time, so we'll create our own
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

  if (gKindMap == nil) {
    gKindMap = [GTLUtilities createStaticDictionary];
  }

  Class selfClass = [self class];

  // ensure this is a unique registration
  GTL_DEBUG_ASSERT([gKindMap objectForKey:kind] == nil,
                     @"%@ (%@) registration conflicts with %@",
                     selfClass, kind, [gKindMap objectForKey:kind]);
  GTL_DEBUG_ASSERT([[gKindMap allKeysForObject:selfClass] count] == 0,
                     @"%@ (%@) registration conflicts with %@",
                     selfClass, kind, [gKindMap allKeysForObject:selfClass]);

  [gKindMap setValue:selfClass forKey:kind];

  // we drain here to keep the clang static analyzer quiet
  [pool drain];
}

#pragma mark Object Instantiation

+ (GTLObject *)objectForJSON:(NSMutableDictionary *)json
                defaultClass:(Class)defaultClass
                  surrogates:(NSDictionary *)surrogates
               batchClassMap:(NSDictionary *)batchClassMap {
  if ([json isEqual:[NSNull null]]) {
    // no actual result, such as the response from a delete
    return nil;
  }

  GTL_ASSERT([json count] != 0, @"Creating object from empty json");
  if ([json count] == 0) return nil;

  // Determine the class to instantiate, based on the original fetch
  // request or by looking up "kind" string from the registration at
  // +load time of GTLObject subclasses
  //
  // We're letting the dynamic kind override the default class so
  // feeds of heterogenous entries can use the defaultClass as a
  // fallback
  Class classToCreate = defaultClass;
  NSString *kind = [json valueForKey:@"kind"];
  if ([kind isKindOfClass:[NSString class]] && [kind length] > 0) {
    Class dynamicClass = [GTLObject registeredObjectClassForKind:kind];
    if (dynamicClass) {
      classToCreate = dynamicClass;
    }
  }

  // Warn the developer that no specific class of GTLObject
  // was requested with the fetch call, and no class is found
  // compiled in to match the "kind" attribute of the JSON
  // returned by the server
  GTL_ASSERT(classToCreate != nil,
             @"Could not find registered GTLObject subclass to "
             "match JSON with kind \"%@\"", kind);

  if (classToCreate == nil) {
    classToCreate = [self class];
  }

  // See if the top-level class for the JSON is listed in the surrogates;
  // if so, instantiate the surrogate class instead
  Class baseSurrogate = [surrogates objectForKey:classToCreate];
  if (baseSurrogate) {
    classToCreate = baseSurrogate;
  }

  // now instantiate the GTLObject
  GTLObject *parsedObject = [classToCreate object];

  parsedObject.surrogates = surrogates;
  parsedObject.JSON = json;

  // it's time to instantiate inner items
  if ([parsedObject respondsToSelector:@selector(createItemsWithClassMap:)]) {
    [parsedObject performSelector:@selector(createItemsWithClassMap:)
                       withObject:batchClassMap];
  }

  return parsedObject;
}

#pragma mark Runtime Utilities

static NSMutableDictionary *gJSONKeyMapCache = nil;
static NSMutableDictionary *gArrayPropertyToClassMapCache = nil;

+ (void)initialize {
  // Note that initialize is guaranteed by the runtime to be called in a
  // thread-safe manner
  if (gJSONKeyMapCache == nil) {
    gJSONKeyMapCache = [GTLUtilities createStaticDictionary];
  }
  if (gArrayPropertyToClassMapCache == nil) {
    gArrayPropertyToClassMapCache = [GTLUtilities createStaticDictionary];
  }
}

+ (NSDictionary *)propertyToJSONKeyMapForClass:(Class<GTLRuntimeCommon>)aClass {
  NSDictionary *resultMap =
    [GTLUtilities mergedClassDictionaryForSelector:@selector(propertyToJSONKeyMap)
                                        startClass:aClass
                                     ancestorClass:[GTLObject class]
                                             cache:gJSONKeyMapCache];
  return resultMap;
}

+ (NSDictionary *)arrayPropertyToClassMapForClass:(Class<GTLRuntimeCommon>)aClass {
  NSDictionary *resultMap =
    [GTLUtilities mergedClassDictionaryForSelector:@selector(arrayPropertyToClassMap)
                                        startClass:aClass
                                     ancestorClass:[GTLObject class]
                                             cache:gArrayPropertyToClassMapCache];
  return resultMap;
}

#pragma mark Runtime Support

+ (Class<GTLRuntimeCommon>)ancestorClass {
  return [GTLObject class];
}

+ (BOOL)resolveInstanceMethod:(SEL)sel {
  BOOL resolved = [GTLRuntimeCommon resolveInstanceMethod:sel onClass:self];
  if (resolved)
    return YES;

  return [super resolveInstanceMethod:sel];
}

@end

@implementation GTLCollectionObject

// Subclasses must implement the items method dynamically.

- (id)itemAtIndex:(NSUInteger)idx {
  NSArray *items = [self performSelector:@selector(items)];
  if (idx < [items count]) {
    return [items objectAtIndex:idx];
  }
  return nil;
}

// NSFastEnumeration protocol
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id *)stackbuf
                                    count:(NSUInteger)len {
  NSArray *items = [self performSelector:@selector(items)];
  NSUInteger result = [items countByEnumeratingWithState:state
                                                 objects:stackbuf
                                                   count:len];
  return result;
}

@end

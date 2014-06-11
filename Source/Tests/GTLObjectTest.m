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

#import <XCTest/XCTest.h>

#import <objc/runtime.h>

#import "GTLObject.h"
#import "GTLDateTime.h"
#import "GTLJSONParser.h"

// Custom subclass for testing the property handling.
@class GTLTestingObject;
@interface GTLTestingObject : GTLObject
// Basic types
@property (copy) NSString *aStr;
@property (copy) NSString *str2;
@property (copy) NSString *identifier;
@property (retain) NSNumber *aNum;
@property (retain) GTLDateTime *aDate;
@property (retain) GTLDateTime *date2;
// Object
@property (retain) GTLTestingObject *child;
// Anything
@property (retain) id anything;
// Arrays
@property (retain) NSArray *arrayString;
@property (retain) NSArray *arrayNumber;
@property (retain) NSArray *arrayDate;
@property (retain) NSArray *arrayKids;
@property (retain) NSArray *arrayAnything;
// Use of getter= for Xcode 5's ARC treatment of init*.
@property (retain, getter=valueOf_initFoo) NSNumber *initFoo;
@end

@implementation GTLTestingObject
@dynamic aStr, str2, identifier, aNum, aDate, date2, child, anything;
@dynamic arrayString, arrayNumber, arrayDate, arrayKids, arrayAnything;
@dynamic initFoo;
+ (NSDictionary *)propertyToJSONKeyMap {
  // Use the name mapping on a few...
  return @{ @"aStr" : @"a_str",
            @"aNum" : @"a.num",  // Test property names with '.' to be safe.
            @"aDate" : @"a_date" };
}
+ (NSDictionary *)arrayPropertyToClassMap {
  return @{ @"arrayString" : [NSString class],
            @"arrayNumber" : [NSNumber class],
            @"arrayDate" : [GTLDateTime class],
            @"arrayKids" : [GTLTestingObject class],
            @"arrayAnything" : [NSObject class] };
}
@end

@interface GTLTestingObjectWithPrimeKey : GTLTestingObject
@property (copy) NSString *str2Prime;
@end

@implementation GTLTestingObjectWithPrimeKey
@dynamic str2Prime;
@end

@interface GTLTestingCollection : GTLCollectionObject
@property (retain) NSArray *items;  // of GTLTestingObject
@end

@implementation GTLTestingCollection
@dynamic items;
@end

// Subclass we can change the default type for additonal properies to make
// testing easier.
@interface GTLTestingAdditionalPropertiesObject : GTLObject
+ (void)setAdditionalPropsClass:(Class)aClass;
@end

@implementation GTLTestingAdditionalPropertiesObject
static Class gAdditionalPropsClass = Nil;
+ (void)setAdditionalPropsClass:(Class)aClass {
  gAdditionalPropsClass = aClass;
}
// Override the call needed by GTLObject subclasses and return the class
// currently being tested.
+ (Class)classForAdditionalProperties {
  return gAdditionalPropsClass;
}
@end

@interface GTLTestingResultArray : GTLResultArray
@property (retain, readonly) NSArray *items;
@end

@implementation GTLTestingResultArray
- (NSArray *)items {
  return [self itemsWithItemClass:[GTLTestingObject class]];
}
@end

@interface GTLTestingResultArray2 : GTLResultArray
@property (retain, readonly) NSArray *items;
@end

@implementation GTLTestingResultArray2
- (NSArray *)items {
  return [self itemsWithItemClass:[NSString class]];
}
@end

@interface GTLObjectTest : XCTestCase
@end

@implementation GTLObjectTest

- (void)testCreation {
  GTLTestingObject *obj;

  obj = [GTLTestingObject object];
  XCTAssertNotNil(obj);

  obj = [GTLTestingObject objectWithJSON:nil];
  XCTAssertNotNil(obj);

  obj = [GTLTestingObject objectWithJSON:[NSMutableDictionary dictionary]];
  XCTAssertNotNil(obj);
}

#pragma mark Getters and Setters

- (void)testSetBasicTypes {
  GTLTestingObject *obj = [GTLTestingObject object];
  XCTAssertNotNil(obj);
  NSMutableDictionary *expected;

  // test setting basic types

  // string
  obj.aStr = @"foo bar";
  obj.str2 = @"mumble";
  expected = [[@{ @"a_str" : @"foo bar",
                  @"str2" : @"mumble" } mutableCopy] autorelease];
  XCTAssertEqualObjects(obj.JSON, expected);

  // number
  obj.aNum = @1234;
  expected[@"a.num"] = @1234;
  XCTAssertEqualObjects(obj.JSON, expected);

  // date
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  obj.aDate = [GTLDateTime dateTimeWithRFC3339String:dateStr];
  expected[@"a_date"] = dateStr;
  XCTAssertEqualObjects(obj.JSON, expected);
}

- (void)testGetBasicTypes {
  NSString * const jsonStr =
    @"{\"a_date\":\"2011-01-14T15:00:00-01:00\",\"a.num\":1234,\"a_str\":\"foo bar\"}";
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingObject *obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  // test getting basic types

  // string
  XCTAssertEqualObjects(obj.aStr, @"foo bar");
  XCTAssertNil(obj.str2);

  // number
  XCTAssertEqualObjects(obj.aNum, @1234);

  // date
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  XCTAssertEqualObjects(obj.aDate,
                       [GTLDateTime dateTimeWithRFC3339String:dateStr]);
  XCTAssertNil(obj.date2, @"unexpected dateTime: %@", obj.date2);
}

- (void)testSetArrayBasicTypes {
  GTLTestingObject *obj = [GTLTestingObject object];
  XCTAssertNotNil(obj);
  NSMutableDictionary *expected = [NSMutableDictionary dictionary];

  // test setting array of basic types

  // string
  obj.arrayString = @[ @"foo bar" ];
  expected[@"arrayString"] = @[ @"foo bar" ];
  XCTAssertEqualObjects(obj.JSON, expected);

  // number
  obj.arrayNumber = @[ @1234 ];
  expected[@"arrayNumber"] = @[ @1234 ];
  XCTAssertEqualObjects(obj.JSON, expected);

  // date
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  obj.arrayDate = @[ [GTLDateTime dateTimeWithRFC3339String:dateStr] ];
  expected[@"arrayDate"] = @[ dateStr ];
  XCTAssertEqualObjects(obj.JSON, expected);
}

- (void)testGetArrayBasicTypes {
  NSString * const jsonStr =
    @"{\"arrayDate\":[\"2011-01-14T15:00:00-01:00\"],\"arrayNumber\":[1234],\"arrayString\":[\"foo bar\"]}";
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingObject *obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  // test getting basic types

  // string
  XCTAssertEqualObjects(obj.arrayString, @[ @"foo bar" ]);

  // number
  XCTAssertEqualObjects(obj.arrayNumber, @[ @1234 ]);

  // date
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  XCTAssertEqualObjects(obj.arrayDate,
                       @[ [GTLDateTime dateTimeWithRFC3339String:dateStr] ]);
}

- (void)testSetAnyTypeProperty {
  GTLTestingObject *obj = [GTLTestingObject object];
  XCTAssertNotNil(obj);
  NSMutableDictionary *expected = [NSMutableDictionary dictionary];

  NSString *anythingStr = @"as string";
  NSNumber *anythingNumber = @9876;
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  GTLDateTime *anythingDate = [GTLDateTime dateTimeWithRFC3339String:dateStr];
  NSArray *anythingArray = @[ @"array of string" ];

  // string

  obj.anything = anythingStr;
  expected[@"anything"] = anythingStr;
  XCTAssertEqualObjects(obj.JSON, expected);

  // number

  obj.anything = anythingNumber;
  expected[@"anything"] = anythingNumber;
  XCTAssertEqualObjects(obj.JSON, expected);

  // date

  obj.anything = anythingDate;
  expected[@"anything"] = dateStr;
  XCTAssertEqualObjects(obj.JSON, expected);

  // GTLObject support tested in the SubObjectSupport test.

  // array (just test of string as plumbing is generic)

  obj.anything = anythingArray;
  expected[@"anything"] = anythingArray;
  XCTAssertEqualObjects(obj.JSON, expected);
}

- (void)testGetAnyPropertyType {
  NSError *err = nil;
  NSMutableDictionary *json;
  GTLTestingObject *obj;

  NSString * const jsonStrAnyString =
    @"{\"anything\":\"as string\"}";
  NSString * const jsonStrAnyNumber =
    @"{\"anything\":9876}";
  NSString * const jsonStrAnyDate =
    @"{\"anything\":\"2011-01-14T15:00:00-01:00\"}";
  NSString * const jsonStrAnyArray =
    @"{\"anything\":[\"array of string\"]}";

  // string

  json = [GTLJSONParser objectWithString:jsonStrAnyString
                                   error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  XCTAssertEqualObjects(obj.anything, @"as string");

  // number

  json = [GTLJSONParser objectWithString:jsonStrAnyNumber
                                   error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  XCTAssertEqualObjects(obj.anything, @9876);

  // date (there is nothing in the JSON to know it's a date, so it comes
  // back as a string.

  json = [GTLJSONParser objectWithString:jsonStrAnyDate
                                   error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  XCTAssertEqualObjects(obj.anything, dateStr);

  // GTLObject support tested in the SubObjectSupport test.

  // array (just test of string as plumbing is generic)

  json = [GTLJSONParser objectWithString:jsonStrAnyArray
                                   error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  XCTAssertEqualObjects(obj.anything, @[ @"array of string" ]);
}

- (void)testSetArrayAnyTypeProperty {
  GTLTestingObject *obj = [GTLTestingObject object];
  XCTAssertNotNil(obj);
  NSMutableDictionary *expected = [NSMutableDictionary dictionary];

  NSArray *arrayAnythingStr = @[ @"as string" ];
  NSArray *arrayAnythingNumber = @[ @9876 ];
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  NSArray *arrayAnythingDate =
    @[ [GTLDateTime dateTimeWithRFC3339String:dateStr] ];

  // string

  obj.arrayAnything = arrayAnythingStr;
  expected[@"arrayAnything"] = arrayAnythingStr;
  XCTAssertEqualObjects(obj.JSON, expected);

  // number

  obj.arrayAnything = arrayAnythingNumber;
  expected[@"arrayAnything"] = arrayAnythingNumber;
  XCTAssertEqualObjects(obj.JSON, expected);

  // date

  obj.arrayAnything = arrayAnythingDate;
  expected[@"arrayAnything"] = @[ dateStr ];
  XCTAssertEqualObjects(obj.JSON, expected);

  // GTLObject support tested in the ArraySubObjectSupport test.
}

- (void)testGetArrayAnyPropertyType {
  NSError *err = nil;
  NSMutableDictionary *json;
  GTLTestingObject *obj;

  NSString * const jsonStrArrayAnyString =
    @"{\"anything\":[\"as string\"]}";
  NSString * const jsonStrArrayAnyNumber =
    @"{\"anything\":[9876]}";
  NSString * const jsonStrArrayAnyDate =
    @"{\"anything\":[\"2011-01-14T15:00:00-01:00\"]}";

  // string

  json = [GTLJSONParser objectWithString:jsonStrArrayAnyString
                                   error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  XCTAssertEqualObjects(obj.anything, @[ @"as string" ]);

  // number

  json = [GTLJSONParser objectWithString:jsonStrArrayAnyNumber
                                   error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  XCTAssertEqualObjects(obj.anything, @[ @9876 ]);

  // date (there is nothing in the JSON to know it's a date, so it comes
  // back as a string.

  json = [GTLJSONParser objectWithString:jsonStrArrayAnyDate
                                   error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  XCTAssertEqualObjects(obj.anything, @[ dateStr ]);

  // GTLObject support tested in the ArraySubObjectSupport test.
}

- (void)testSubObjectSupport {

  // test sub (child) objects

  GTLTestingObject *obj = [GTLTestingObject object];
  XCTAssertNotNil(obj);
  GTLTestingObject *child = [GTLTestingObject object];
  XCTAssertNotNil(child);
  GTLTestingObject *child2 = [GTLTestingObject object];
  XCTAssertNotNil(child2);

  child.aStr = @"I'm the kid";
  child2.aStr = @"I'm the any kid";
  obj.child = child;
  obj.anything = child2;
  XCTAssertNotNil(obj.child);

  NSString *jsonStr = obj.JSONString;
  XCTAssertNotNil(jsonStr);
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingObject *obj2 = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj2);

  // object matches (including kids)
  XCTAssertEqualObjects(obj, obj2);
  XCTAssertEqualObjects(obj.JSON, obj2.JSON);

  // new object also has kids
  XCTAssertNotNil(obj2.child);
  XCTAssertNotNil(obj2.anything);

  // kids match and wasn't same pointer
  XCTAssertTrue(obj2.child != child);
  XCTAssertEqualObjects(obj2.child, child);
  XCTAssertTrue(obj2.anything != child2);
  XCTAssertEqualObjects(obj2.anything, child2);
}

- (void)testNestedSetters {
  // ensure that adding an empty object to an empty object doesn't leave the
  // internal JSON tree unbuilt
  GTLTestingObject *obj = [GTLTestingObject object];

  obj.child = [GTLTestingObject object];
  obj.child.child = [GTLTestingObject object];
  obj.child.child.aStr = @"froglegs";

  NSMutableDictionary *json = obj.JSON;
  XCTAssertNotNil(json);

  GTLTestingObject *obj2 = [GTLTestingObject objectWithJSON:json];
  XCTAssertEqualObjects(obj2.child.child.aStr, @"froglegs");

  // ensure that the internal JSON tree is built even when adding to an
  // object of ambiguous type
  obj = [GTLTestingObject object];

  obj2 = [GTLTestingObject object];
  obj.anything = obj2;
  obj2.child = [GTLTestingObject object];
  obj2.child.aStr = @"froglegs";

  json = obj.JSON;
  XCTAssertNotNil(json);
}

- (void)testArraySubObjectSupport {

  // test array of sub (child) objects

  GTLTestingObject *obj = [GTLTestingObject object];
  XCTAssertNotNil(obj);
  GTLTestingObject *child = [GTLTestingObject object];
  XCTAssertNotNil(child);
  GTLTestingObject *child2 = [GTLTestingObject object];
  XCTAssertNotNil(child2);

  child.aStr = @"I'm a kid";
  child2.aStr = @"I'm a any kid";
  obj.arrayKids = @[ child ];
  obj.arrayAnything = @[ child2 ];

  NSString *jsonStr = obj.JSONString;
  XCTAssertNotNil(jsonStr);
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingObject *obj2 = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj2);

  // object matches (including kids)
  XCTAssertEqualObjects(obj, obj2);
  XCTAssertEqualObjects(obj.JSON, obj2.JSON);

  // new object also has kids
  XCTAssertNotNil(obj2.arrayKids);
  XCTAssertNotNil(obj2.arrayAnything);

  // kids match and wasn't same pointer
  XCTAssertTrue(obj2.arrayKids[0] != child);
  XCTAssertEqualObjects(obj2.arrayKids[0], child);
  XCTAssertTrue(obj2.arrayAnything[0] != child2);
  XCTAssertEqualObjects(obj2.arrayAnything[0], child2);
}

- (void)testPropertyNameSubStrings {
  // We had a bug where if there were two properties, one a proper substring
  // of the other, we'd match wrong.  This test makes sure we don't regress
  // that.

  GTLTestingObjectWithPrimeKey *obj = [GTLTestingObjectWithPrimeKey object];

  // Test lookup for a setter.

  XCTAssertNotNil(obj);
  obj.str2 = @"for base class";
  obj.str2Prime = @"for subclass";
  NSDictionary *expected = [[@{ @"str2" : @"for base class",
                                @"str2Prime" : @"for subclass" } mutableCopy] autorelease];
  XCTAssertEqualObjects(obj.JSON, expected);

  // Test lookup for a getter.

  XCTAssertEqualObjects(obj.str2, @"for base class");
  XCTAssertEqualObjects(obj.str2Prime, @"for subclass");
}

- (void)testSetArrayOfArrayOfDotDotDot {
  GTLTestingObject *obj = [GTLTestingObject object];
  XCTAssertNotNil(obj);
  NSMutableDictionary *expected = [NSMutableDictionary dictionary];

  // test setting arrays of arrays of...

  obj.arrayString = @[ @[ @"foo" ] ];
  expected[@"arrayString"] = @[ @[ @"foo" ] ];
  XCTAssertEqualObjects(obj.JSON, expected);

  obj.arrayNumber = @[ @[ @[ @987 ] ] ];
  expected[@"arrayNumber"] = @[ @[ @[ @987 ] ] ];
  XCTAssertEqualObjects(obj.JSON, expected);

  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  obj.arrayDate = @[ @[ [GTLDateTime dateTimeWithRFC3339String:dateStr] ] ];
  expected[@"arrayDate"] = @[ @[ dateStr ] ];
  XCTAssertEqualObjects(obj.JSON, expected);

  GTLTestingObject *child = [GTLTestingObject object];
  XCTAssertNotNil(child);
  child.aStr = @"I'm a kid";

  obj.arrayKids = @[ @[ child ] ];
  expected[@"arrayKids"] = @[ @[ child.JSON ] ];
  XCTAssertEqualObjects(obj.JSON, expected);

  // Array of anything as a string.
  obj.arrayAnything = @[ @[ @"a string" ] ];
  expected[@"arrayAnything"] = @[ @[ @"a string" ] ];
  XCTAssertEqualObjects(obj.JSON, expected);

  GTLTestingObject *child2 = [GTLTestingObject object];
  XCTAssertNotNil(child2);
  child2.aStr = @"I'm a any kid";

  // Array of anything as an object.
  obj.arrayAnything = @[ @[ child2 ] ];
  expected[@"arrayAnything"] = @[ @[ child2.JSON ] ];
  XCTAssertEqualObjects(obj.JSON, expected);
}

- (void)testGetArrayOfArrayOfDotDotDot {
  NSString * const jsonStr =
    @"{\"arrayString\" : [[\"foo\"]],"
    @" \"arrayNumber\" : [[[987]]],"
    @" \"arrayDate\" : [[\"2011-01-14T15:00:00-01:00\"]],"
    @" \"arrayKids\" : [[{\"a_str\" : \"I'm a kid\"}]],"
    @" \"arrayAnything\" : [[\"a string\"]]"
    @"}";
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err, @"got error parsing: %@", err);
  XCTAssertNotNil(json);

  GTLTestingObject *obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  // test getting arrays of arrays of...

  XCTAssertEqualObjects(obj.arrayString, @[ @[ @"foo" ] ],
                       @"array of array of string");

  XCTAssertEqualObjects(obj.arrayNumber, @[ @[ @[ @987 ] ] ],
                       @"array of array of array of number");

  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  XCTAssertEqualObjects(obj.arrayDate,
                       @[ @[ [GTLDateTime dateTimeWithRFC3339String:dateStr] ] ],
                       @"array of array of datetime");

  // Kid in array of array.
  NSArray *aArray = obj.arrayKids;
  XCTAssertEqual([aArray count], (NSUInteger)1);
  aArray = aArray[0];
  XCTAssertEqual([aArray count], (NSUInteger)1);
  GTLTestingObject *child = aArray[0];
  XCTAssertEqualObjects(child.aStr, @"I'm a kid");

  // Anything (string) in array of array.
  XCTAssertEqualObjects(obj.arrayAnything,
                       @[ @[ @"a string" ] ],
                       @"array of array of anything as string");

  // anything (kid) in array of array.

  NSString * const jsonStr2 =
    @"{\"arrayAnything\" : [[{\"a_str\" : \"I'm a any kid\"}]]}";
  err = nil;
  json = [GTLJSONParser objectWithString:jsonStr2 error:&err];
  XCTAssertNil(err, @"got error parsing: %@", err);
  XCTAssertNotNil(json);
  obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  aArray = obj.arrayAnything;
  XCTAssertEqual([aArray count], (NSUInteger)1);
  aArray = aArray[0];
  XCTAssertEqual([aArray count], (NSUInteger)1);
  // Test doesn't use kinds, so this comes in as a generic object.
  GTLObject *anyChild = aArray[0];
  XCTAssertEqualObjects([anyChild additionalPropertyForName:@"a_str"],
                       @"I'm a any kid");
}

- (void)testInitFoo {

  // Set/Get it.
  GTLTestingObject *obj = [GTLTestingObject object];
  XCTAssertNotNil(obj);
  obj.initFoo = @7;
  NSDictionary *expected = @{ @"initFoo" : @7 };
  XCTAssertEqualObjects(obj.JSON, expected);
  XCTAssertEqualObjects(obj.initFoo, @7);

  // Decode from string and get it.
  NSString * const jsonStr = @"{\"initFoo\":1234}";
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  obj = [GTLTestingObject objectWithJSON:json];
  XCTAssertNotNil(obj);
  XCTAssertEqualObjects(obj.initFoo, @1234);
}

#pragma mark Additional Properties

- (void)testSetAdditionalPropertiesBasicTypes {
  GTLTestingAdditionalPropertiesObject *obj =
    [GTLTestingAdditionalPropertiesObject object];
  XCTAssertNotNil(obj);
  NSMutableDictionary *expected;

  // test setting basic types

  // string
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSString class]];
  [obj setAdditionalProperty:@"foo bar" forName:@"ap1"];
  expected = [[@{ @"ap1" : @"foo bar" } mutableCopy] autorelease];
  XCTAssertEqualObjects(obj.JSON, expected);

  // number
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSNumber class]];
  [obj setAdditionalProperty:@987
                     forName:@"ap2"];
  expected[@"ap2"] = @987;
  XCTAssertEqualObjects(obj.JSON, expected);

  // date
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[GTLDateTime class]];
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  [obj setAdditionalProperty:[GTLDateTime dateTimeWithRFC3339String:dateStr]
                     forName:@"ap3"];
  expected[@"ap3"] = dateStr;
  XCTAssertEqualObjects(obj.JSON, expected);
}

- (void)testGetAdditionalPropertiesBasicTypes {
  NSString * const jsonStr =
    @"{\"ap3\":\"2011-01-14T15:00:00-01:00\",\"ap2\":1234,\"ap1\":\"foo bar\"}";
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingObject *obj = [GTLTestingAdditionalPropertiesObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  // test getting basic types

  // string
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSString class]];
  XCTAssertEqualObjects([obj additionalPropertyForName:@"ap1"],
                       @"foo bar");

  // number
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSNumber class]];
  XCTAssertEqualObjects([obj additionalPropertyForName:@"ap2"],
                       @1234);

  // date
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[GTLDateTime class]];
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  XCTAssertEqualObjects([obj additionalPropertyForName:@"ap3"],
                       [GTLDateTime dateTimeWithRFC3339String:dateStr]);
}

- (void)testSetAdditionalPropertiesObject {
  GTLTestingAdditionalPropertiesObject *obj =
    [GTLTestingAdditionalPropertiesObject object];
  XCTAssertNotNil(obj);
  NSMutableDictionary *expected;

  GTLTestingObject *child = [GTLTestingObject object];
  XCTAssertNotNil(child);

  child.aStr = @"I'm a kid";

  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[GTLTestingObject class]];
  [obj setAdditionalProperty:child forName:@"aKid"];
  expected = [[@{ @"aKid" : child.JSON } mutableCopy] autorelease];
  XCTAssertEqualObjects(obj.JSON, expected);
}

- (void)testGetAdditionalPropertiesObject {
  NSString * const jsonStr =
    @"{\"aKid\":{ \"a_str\": \"I'm a kid\" } }";
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingObject *obj = [GTLTestingAdditionalPropertiesObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[GTLTestingObject class]];
  GTLTestingObject *child = [obj additionalPropertyForName:@"aKid"];
  XCTAssertNotNil(child);
  XCTAssertTrue([child isKindOfClass:[GTLTestingObject class]]);
  XCTAssertEqualObjects(child.aStr, @"I'm a kid");
}

- (void)testSetAdditionalPropertiesAnything {
  GTLTestingAdditionalPropertiesObject *obj =
    [GTLTestingAdditionalPropertiesObject object];
  XCTAssertNotNil(obj);
  NSMutableDictionary *expected;

  // test setting when it can be anything
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSObject class]];

  // string
  [obj setAdditionalProperty:@"foo bar" forName:@"ap1"];
  expected = [[@{ @"ap1": @"foo bar" } mutableCopy] autorelease];
  XCTAssertEqualObjects(obj.JSON, expected);

  // number
  [obj setAdditionalProperty:@987
                     forName:@"ap2"];
  expected[@"ap2"] = @987;
  XCTAssertEqualObjects(obj.JSON, expected);

  // date
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  [obj setAdditionalProperty:[GTLDateTime dateTimeWithRFC3339String:dateStr]
                     forName:@"ap3"];
  expected[@"ap3"] = dateStr;
  XCTAssertEqualObjects(obj.JSON, expected);

  // object
  GTLTestingObject *child = [GTLTestingObject object];
  XCTAssertNotNil(child);

  child.aStr = @"I'm a kid";

  [obj setAdditionalProperty:child forName:@"aKid"];
  expected[@"aKid"] = child.JSON;
  XCTAssertEqualObjects(obj.JSON, expected);
}

- (void)testGetAdditionalPropertiesAnything {
  NSString * const jsonStr =
    @"{\"ap3\":\"2011-01-14T15:00:00-01:00\",\"ap2\":1234,\"ap1\":\"foo bar\", \"aKid\":{ \"a_str\": \"I'm a kid\" } }";
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingObject *obj = [GTLTestingAdditionalPropertiesObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  // test getting when it can be anything
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSObject class]];

  // string
  XCTAssertEqualObjects([obj additionalPropertyForName:@"ap1"],
                       @"foo bar");

  // number
  XCTAssertEqualObjects([obj additionalPropertyForName:@"ap2"],
                       @1234);

  // date - just get the string back, nothing tells it to conver to a date.
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  XCTAssertEqualObjects([obj additionalPropertyForName:@"ap3"],
                       dateStr);

  GTLObject *child = [obj additionalPropertyForName:@"aKid"];
  XCTAssertNotNil(child);
  XCTAssertTrue([child isMemberOfClass:[GTLObject class]]);
  XCTAssertEqualObjects([child additionalPropertyForName:@"a_str"],
                       @"I'm a kid");
}

- (void)testSetAdditionalPropertiesArraysOfBasicTypes {
  GTLTestingAdditionalPropertiesObject *obj =
    [GTLTestingAdditionalPropertiesObject object];
  XCTAssertNotNil(obj);
  NSMutableDictionary *expected;

  // test setting arrays of basic types

  // string
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSString class]];
  [obj setAdditionalProperty:@[ @"foo bar" ]
                     forName:@"apArray1"];
  expected = [[@{ @"apArray1": @[ @"foo bar" ] } mutableCopy] autorelease];
  XCTAssertEqualObjects(obj.JSON, expected);

  // number
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSNumber class]];
  [obj setAdditionalProperty:@[ @987 ]
                     forName:@"apArray2"];
  expected[@"apArray2"] = @[ @987 ];
  XCTAssertEqualObjects(obj.JSON, expected);

  // date
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[GTLDateTime class]];
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  [obj setAdditionalProperty:@[ [GTLDateTime dateTimeWithRFC3339String:dateStr] ]
                     forName:@"apArray3"];
  expected[@"apArray3"] = @[ dateStr ];
  XCTAssertEqualObjects(obj.JSON, expected);
}

- (void)testGetAdditionalPropertiesArraysOfBasicTypes {
  NSString * const jsonStr =
    @"{\"apArray3\":[\"2011-01-14T15:00:00-01:00\"],\"apArray2\":[1234],\"apArray1\":[\"foo bar\"]}";
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingObject *obj = [GTLTestingAdditionalPropertiesObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  // test getting arrays of basic types

  // string
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSString class]];
  XCTAssertEqualObjects([obj additionalPropertyForName:@"apArray1"],
                       @[ @"foo bar" ]);

  // number
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSNumber class]];
  XCTAssertEqualObjects([obj additionalPropertyForName:@"apArray2"],
                       @[ @1234 ]);

  // date
  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[GTLDateTime class]];
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  XCTAssertEqualObjects([obj additionalPropertyForName:@"apArray3"],
                       @[ [GTLDateTime dateTimeWithRFC3339String:dateStr] ]);
}

- (void)testSetAdditionalPropertiesArraysOfObject {
  GTLTestingAdditionalPropertiesObject *obj =
    [GTLTestingAdditionalPropertiesObject object];
  XCTAssertNotNil(obj);
  NSMutableDictionary *expected;

  GTLTestingObject *child = [GTLTestingObject object];
  XCTAssertNotNil(child);

  child.aStr = @"I'm a kid";

  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[GTLTestingObject class]];
  [obj setAdditionalProperty:@[ child ]
                     forName:@"aKidArray"];
  expected = [[@{ @"aKidArray": @[ child.JSON ] } mutableCopy] autorelease];
  XCTAssertEqualObjects(obj.JSON, expected);
}

- (void)testGetAdditionalPropertiesArraysOfObject {
  NSString * const jsonStr =
    @"{\"aKidArray\":[ { \"a_str\": \"I'm a kid\" } ] }";
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingObject *obj = [GTLTestingAdditionalPropertiesObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[GTLTestingObject class]];
  NSArray *kidArray = [obj additionalPropertyForName:@"aKidArray"];
  XCTAssertNotNil(kidArray);
  XCTAssertTrue([kidArray isKindOfClass:[NSArray class]]);
  XCTAssertEqual([kidArray count], (NSUInteger)1);

  GTLTestingObject *child = kidArray[0];
  XCTAssertNotNil(child);
  XCTAssertTrue([child isKindOfClass:[GTLTestingObject class]]);
  XCTAssertEqualObjects(child.aStr, @"I'm a kid");
}

- (void)testSetAdditionalPropertiesArraysOfArrayOfDotDotDot {
  GTLTestingAdditionalPropertiesObject *obj =
    [GTLTestingAdditionalPropertiesObject object];
  XCTAssertNotNil(obj);
  NSMutableDictionary *expected;

  // test setting arrays of arrays of...

  // NOTE: We only test with strings, because at this point the plumbing no
  // matter what type the property is.

  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSString class]];

  [obj setAdditionalProperty:@[ @[ @"foo" ] ]
                     forName:@"apArray1"];
  expected = [[@{ @"apArray1": @[ @[ @"foo" ] ] } mutableCopy] autorelease];
  XCTAssertEqualObjects(obj.JSON, expected);

  [obj setAdditionalProperty:@[ @[ @[ @"bar" ] ] ]
                     forName:@"apArray2"];
  expected[@"apArray2"] = @[ @[ @[ @"bar" ] ] ];
  XCTAssertEqualObjects(obj.JSON, expected);
}

- (void)testGetAdditionalPropertiesArraysOfArraysOfDotDotDot {
  NSString * const jsonStr =
    @"{\"apArray2\":[[[\"bar\"]]],\"apArray1\":[[\"foo\"]]}";
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingObject *obj = [GTLTestingAdditionalPropertiesObject objectWithJSON:json];
  XCTAssertNotNil(obj);

  // test getting arrays of arrays of...

  // NOTE: We only test with strings, because at this point the plumbing no
  // matter what type the property is.

  [GTLTestingAdditionalPropertiesObject setAdditionalPropsClass:[NSString class]];
  XCTAssertEqualObjects([obj additionalPropertyForName:@"apArray1"],
                       @[ @[ @"foo" ] ],
                       @"array of array of string");

  XCTAssertEqualObjects([obj additionalPropertyForName:@"apArray2"],
                       @[ @[ @[ @"bar" ] ] ],
                       @"array of array of array of string");
}

#pragma mark Partial

- (GTLTestingObject *)objectForPartialTests {
  // This helper method returns a new instance of a reasonably complex
  // object for testing fields and patch
  GTLTestingObject *obj = [GTLTestingObject object];

  // Object hierarchy
  obj.aStr = @"green";
  obj.aNum = @123;
  obj.aDate = [GTLDateTime dateTimeWithRFC3339String:@"2011-05-04T23:28:20.888Z"];
  // Nested child object
  obj.child = [GTLTestingObject object];
  obj.child.child = [GTLTestingObject object];
  obj.child.child.aStr = @"blue-gold";
  // Array of objects
  GTLTestingObject *a1 = [GTLTestingObject object];
  a1.aStr = @"yellow-gold-aqua";
  a1.child = [GTLTestingObject object];
  a1.child.str2 = @"brown";
  a1.str2 = @"yellow-gold-indigo";
  GTLTestingObject *a2 = [GTLTestingObject object];
  a2.aStr = @"yellow-gold";
  obj.child.child.arrayKids = @[ a1, a2 ];
  // Arrays of basic types
  obj.child.child.arrayString = @[ @"cat", @"dog" ];
  obj.child.child.arrayNumber = @[ @111, @222 ];
  return obj;
}

- (void)testFieldsDescription {
  // Empty object
  GTLTestingObject *obj = [GTLTestingObject object];
  NSString *fields = [obj fieldsDescription];
  XCTAssertEqualObjects(fields, @"");

  // Object hierarchy
  obj = [self objectForPartialTests];

  fields = [obj fieldsDescription];
  NSString *expected = @"a.num,a_date,a_str,"
    @"child/child/a_str,"
    @"child/child/arrayKids(a_str,child/str2,str2),"
    @"child/child/arrayNumber,"
    @"child/child/arrayString";
  XCTAssertEqualObjects(fields, expected);
}

- (void)testPatchObjectGeneration {
  GTLTestingObject *obj1 = [GTLTestingObject object];
  GTLTestingObject *obj2 = [GTLTestingObject object];

  GTLTestingObject *resultObj = [obj1 patchObjectFromOriginal:obj2];
  XCTAssertNil(resultObj);

  // It might be cleaner to test against expected JSON strings rather than
  // dictionaries, but SBJSON by default doesn't sort keys so the
  // JSON strings have keys in random order.

  // Compare the testing object to an empty object; everything should be
  // marked for deletion (with NSNull)
  obj1 = [self objectForPartialTests];
  obj2 = [GTLTestingObject object];
  resultObj = [obj2 patchObjectFromOriginal:obj1];

  NSDictionary *expected = @{ @"a_str" : [NSNull null],
                              @"a_date" : [NSNull null],
                              @"a.num" : [NSNull null],
                              @"child" : [NSNull null] };
  XCTAssertEqualObjects(resultObj.JSON, expected);

  // Reverse: compare an empty object to the testing object,
  // and everything should be added
  resultObj = [obj1 patchObjectFromOriginal:obj2];

  expected = obj1.JSON;
  XCTAssertEqualObjects(resultObj.JSON, expected);

  // Equal objects should return a nil result
  obj1 = [self objectForPartialTests];
  obj2 = [self objectForPartialTests];
  resultObj = [obj1 patchObjectFromOriginal:obj2];
  XCTAssertNil(resultObj);

  // Selectively add, change, and remove fields
  obj1 = [self objectForPartialTests];
  obj2 = [self objectForPartialTests];

  obj1.aNum = @9.87f;
  obj1.aStr = nil;
  obj1.str2 = @"raven";
  resultObj = [obj1 patchObjectFromOriginal:obj2];
  expected = @{ @"a.num" : @9.87f,
                @"a_str" : [NSNull null],
                @"str2" : @"raven" };

  XCTAssertEqualObjects(resultObj.JSON, expected);

  // Reverse the comparison direction
  resultObj = [obj2 patchObjectFromOriginal:obj1];
  expected = @{ @"a.num" : @123.0f,
                @"a_str" : @"green",
                @"str2" : [NSNull null] };
  XCTAssertEqualObjects(resultObj.JSON, expected);

  // Change the array of strings; we'll expect the patch to be only the new
  // array
  obj1 = [self objectForPartialTests];
  obj2 = [self objectForPartialTests];

  obj1.child.child.arrayString = @[ @"monkey" ];

  resultObj = [obj1 patchObjectFromOriginal:obj2];

  GTLTestingObject *expectedObj = [GTLTestingObject object];
  expectedObj.child = [GTLTestingObject object];
  expectedObj.child.child = [GTLTestingObject object];
  expectedObj.child.child.arrayString = @[ @"monkey" ];

  XCTAssertEqualObjects(resultObj.JSON, expectedObj.JSON);

  // Change the array of child objects by omitting the second child;
  // the result should be only an array with the first child
  obj1 = [self objectForPartialTests];
  obj2 = [self objectForPartialTests];

  GTLObject *firstKid = obj1.child.child.arrayKids[0];
  obj1.child.child.arrayKids = @[ firstKid ];

  resultObj = [obj1 patchObjectFromOriginal:obj2];

  expectedObj = [GTLTestingObject object];
  expectedObj.child = [GTLTestingObject object];
  expectedObj.child.child = [GTLTestingObject object];
  expectedObj.child.child.arrayKids = @[ firstKid ];

  XCTAssertEqualObjects(resultObj.JSON, expectedObj.JSON);
}

- (void)testNullPatchValues {
  // Ensure that we can set and get nulls for use with patch
  GTLTestingObject *obj = [GTLTestingObject object];
  obj.aStr = [GTLObject nullValue];
  obj.str2 = [GTLObject nullValue];
  obj.aNum = [GTLObject nullValue];
  obj.aDate = [GTLObject nullValue];
  obj.child = [GTLObject nullValue];
  obj.arrayString = [GTLObject nullValue];
  obj.arrayNumber = [GTLObject nullValue];
  obj.arrayDate = [GTLObject nullValue];
  obj.arrayKids = [GTLObject nullValue];
  obj.arrayAnything = [GTLObject nullValue];

  XCTAssertEqualObjects(obj.aStr, [NSNull null]);
  XCTAssertEqualObjects(obj.str2, [NSNull null]);
  XCTAssertEqualObjects(obj.aNum, [NSNull null]);
  XCTAssertEqualObjects(obj.aDate, [NSNull null]);
  XCTAssertEqualObjects(obj.child, [NSNull null]);
  XCTAssertEqualObjects(obj.arrayString, [NSNull null]);
  XCTAssertEqualObjects(obj.arrayNumber, [NSNull null]);
  XCTAssertEqualObjects(obj.arrayDate, [NSNull null]);
  XCTAssertEqualObjects(obj.arrayKids, [NSNull null]);
  XCTAssertEqualObjects(obj.arrayAnything, [NSNull null]);

  NSError *error = nil;
  NSString *jsonStr = obj.JSONString;

  XCTAssertNil(error);
  NSMutableDictionary *jsonDict = [GTLJSONParser objectWithString:jsonStr
                                                            error:&error];
  XCTAssertNil(error);

  GTLTestingObject *obj2 = [GTLTestingObject objectWithJSON:jsonDict];

  XCTAssertEqualObjects(obj2.aStr, [NSNull null]);
  XCTAssertEqualObjects(obj2.str2, [NSNull null]);
  XCTAssertEqualObjects(obj2.aNum, [NSNull null]);
  XCTAssertEqualObjects(obj2.aDate, [NSNull null]);
  XCTAssertEqualObjects(obj2.child, [NSNull null]);
  XCTAssertEqualObjects(obj2.arrayString, [NSNull null]);
  XCTAssertEqualObjects(obj2.arrayNumber, [NSNull null]);
  XCTAssertEqualObjects(obj2.arrayDate, [NSNull null]);
  XCTAssertEqualObjects(obj2.arrayKids, [NSNull null]);
  XCTAssertEqualObjects(obj2.arrayAnything, [NSNull null]);
}

#pragma mark GTLCollectionObject

- (void)testCollection {
  GTLTestingCollection *collection = [GTLTestingCollection object];

  // Test enumeration and subscripts on empty collection.
  for (id foundItem in collection) {
    XCTFail(@"Unexpected: %@", foundItem);
  }
  XCTAssertNil(collection[0]);
  XCTAssertNil([collection itemForIdentifier:@"foo"]);

  // Put two items in the collection.
  GTLTestingObject *obj0 = [GTLTestingObject object];
  obj0.aStr = @"aaa";
  obj0.identifier = @"obj0";
  GTLTestingObject *obj1 = [GTLTestingObject object];
  obj1.aStr = @"bbb";
  obj1.identifier = @"obj1";
  NSArray *items = @[ obj0, obj1 ];

  collection.items = [[items copy] autorelease];

  // Test fast enumeration.
  NSUInteger counter = 0;
  for (id foundItem in collection) {
    XCTAssertEqualObjects(foundItem, items[counter]);
    counter++;
  }
  XCTAssertEqual(counter, (NSUInteger)2);

  // Test indexed subscripts.
  XCTAssertEqualObjects(collection[0], items[0]);
  XCTAssertEqualObjects(collection[1], items[1]);
  XCTAssertNil(collection[3]);

  // Test itemForIdentifier:.
  [collection resetIdentifierMap];
  XCTAssertEqualObjects([collection itemForIdentifier:@"obj0"], items[0]);
  XCTAssertEqualObjects([collection itemForIdentifier:@"obj1"], items[1]);
  XCTAssertNil([collection itemForIdentifier:@"obj2"]);

  // Verify that the first item with a non-unique identifier is returned.
  GTLTestingObject *obj2 = [GTLTestingObject object];
  obj2.aStr = @"ccc";
  obj2.identifier = @"obj0";  // Same identifier as obj0.
  items = [items arrayByAddingObject:obj2];
  collection.items = [[items copy] autorelease];

  [collection resetIdentifierMap];
  XCTAssertEqual([collection.items count], (NSUInteger)3);
  XCTAssertEqualObjects(collection[2], items[2]);
  XCTAssertEqualObjects([collection itemForIdentifier:@"obj0"], items[0]);
}

#pragma mark GTLResultArray Parsing

- (void)testResultArrayParsing {

  // Of Object

  NSString * const jsonStr =
    @"[ {\"a_str\":\"obj 1\"}, {\"a_str\":\"obj 2\"} ]";
  NSError *err = nil;
  NSMutableDictionary *json = [GTLJSONParser objectWithString:jsonStr
                                                        error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingResultArray *arrayResult = (GTLTestingResultArray *)
    [GTLObject objectForJSON:json
                defaultClass:[GTLTestingResultArray class]
                  surrogates:nil
               batchClassMap:nil];
  XCTAssertTrue([arrayResult isKindOfClass:[GTLTestingResultArray class]]);
  NSArray *items = arrayResult.items;
  XCTAssertEqual([items count], (NSUInteger)2);

  GTLTestingObject *obj = items[0];
  XCTAssertTrue([obj isKindOfClass:[GTLTestingObject class]]);
  XCTAssertEqualObjects(obj.aStr, @"obj 1");

  obj = items[1];
  XCTAssertTrue([obj isKindOfClass:[GTLTestingObject class]]);
  XCTAssertEqualObjects(obj.aStr, @"obj 2");

  // Of String

  NSString * const jsonStr2 = @"[ \"str 1\", \"str 2\" ]";
  err = nil;
  json = [GTLJSONParser objectWithString:jsonStr2 error:&err];
  XCTAssertNil(err);
  XCTAssertNotNil(json);

  GTLTestingResultArray2 *arrayResult2 = (GTLTestingResultArray2 *)
    [GTLObject objectForJSON:json
                defaultClass:[GTLTestingResultArray2 class]
                  surrogates:nil
               batchClassMap:nil];
  XCTAssertTrue([arrayResult2 isKindOfClass:[GTLTestingResultArray2 class]]);
  items = arrayResult2.items;
  XCTAssertEqual([items count], (NSUInteger)2);

  NSString *str = items[0];
  XCTAssertTrue([str isKindOfClass:[NSString class]]);
  XCTAssertEqualObjects(str, @"str 1");

  str = items[1];
  XCTAssertTrue([str isKindOfClass:[NSString class]]);
  XCTAssertEqualObjects(str, @"str 2");
}

@end

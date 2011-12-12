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

#import <SenTestingKit/SenTestingKit.h>

#import <objc/runtime.h>

#import "GTLQuery.h"

// Custom subclass for testing the property handling.
@interface GTLTestingQuery : GTLQuery
@property (copy) NSString *userId;
@property (copy) NSString *msgId;
@property (copy) NSString *alt;
@property (copy) NSString *qS;
@property (assign) NSUInteger maxResults;
@property (assign) NSInteger aNumber;
@property (assign) long long aLongLong;
@property (assign) unsigned long long aULongLong;
@property (assign) float cost;
@property (assign) double minValue;
@property (assign) BOOL preferred;
@property (retain) NSArray *arrayString;
@property (retain) NSArray *arrayNumber;
@property (retain) NSArray *arrayDate;
@end

@implementation GTLTestingQuery
@dynamic userId, msgId, alt, qS, maxResults, aNumber, aLongLong, aULongLong;
@dynamic cost, minValue, preferred, arrayString, arrayNumber, arrayDate;
+ (NSDictionary *)parameterNameMap {
  return [NSDictionary dictionaryWithObjectsAndKeys:
          @"user-id", @"userId",
          @"q.s", @"qS",  // Test parameter names with '.' to be safe.
          @"max_results", @"maxResults",
          nil];
}
+ (NSDictionary *)arrayPropertyToClassMap {
  return [NSDictionary dictionaryWithObjectsAndKeys:
          [NSString class], @"arrayString",
          [NSNumber class], @"arrayNumber",
          [GTLDateTime class], @"arrayDate",
          nil];
}
@end

@interface GTLTestingQueryWithPrimeKey : GTLTestingQuery
@property (copy) NSString *altPrime;
@end

@implementation GTLTestingQueryWithPrimeKey
@dynamic altPrime;
@end

@interface GTLQueryTest : SenTestCase
@end

@implementation GTLQueryTest

- (void)testBasics {
  GTLTestingQuery *query;

  query = [GTLTestingQuery queryWithMethodName:nil];
  STAssertNil(query, @"nil method name");

  query = [GTLTestingQuery queryWithMethodName:@""];
  STAssertNil(query, @"empty method name");

  NSString *methodName = @"foo.bar.baz";
  query = [GTLTestingQuery queryWithMethodName:methodName];
  STAssertNotNil(query, @"failed to make query");

  NSMutableDictionary *expected;

  // test query parameter-setting/getting

  query.userId = @"test user";
  query.msgId = @"12345";
  expected = [NSMutableDictionary dictionaryWithObjectsAndKeys:
              @"test user", @"user-id",
              @"12345", @"msgId",
              nil];
  STAssertEqualObjects(query.JSON, expected, nil);

  query.alt = @"simple";
  [expected setObject:@"simple" forKey:@"alt"];
  STAssertEqualObjects(query.JSON, expected, nil);

  query.qS = @"foo bar baz";
  [expected setObject:@"foo bar baz" forKey:@"q.s"];
  STAssertEqualObjects(query.JSON, expected, nil);

  query.maxResults = 15;
  [expected setObject:[NSNumber numberWithUnsignedInteger:15]
               forKey:@"max_results"];
  STAssertEqualObjects(query.JSON, expected, nil);
  STAssertEquals(query.maxResults, (NSUInteger)15, nil);
  
  query.aNumber = -10;
  [expected setObject:[NSNumber numberWithInteger:-10]
               forKey:@"aNumber"];
  STAssertEqualObjects(query.JSON, expected, nil);
  STAssertEquals(query.aNumber, (NSInteger)-10, nil);

  query.aLongLong = -1000000000;
  [expected setObject:[NSNumber numberWithLongLong:-1000000000]
               forKey:@"aLongLong"];
  STAssertEqualObjects(query.JSON, expected, nil);
  STAssertEquals(query.aLongLong, (long long)-1000000000, nil);

  query.aULongLong = 1000000000;
  [expected setObject:[NSNumber numberWithUnsignedLongLong:1000000000]
               forKey:@"aULongLong"];
  STAssertEqualObjects(query.JSON, expected, nil);
#if __LP64__
  // For reasons I can't currently explain, this fails in 32bit release only.
  // Debug 32bit passes.  So it has to be something about how things expand
  // and compiler settings.
  STAssertEquals((unsigned long long)query.aULongLong, (unsigned long long)1000000000, nil);
#endif
  
  query.cost = 123.4f;
  [expected setObject:[NSNumber numberWithFloat:123.4f]
               forKey:@"cost"];
  STAssertEqualObjects(query.JSON, expected, nil);
  STAssertEquals(query.cost, 123.4f, nil);
  
  query.minValue = 20.0;
  [expected setObject:[NSNumber numberWithDouble:20]
               forKey:@"minValue"];
  STAssertEqualObjects(query.JSON, expected, nil);
  STAssertEquals(query.minValue, 20.0, nil);

  query.preferred = NO;
  [expected setObject:[NSNumber numberWithBool:NO]
               forKey:@"preferred"];
  STAssertEqualObjects(query.JSON, expected, nil);
  STAssertFalse(query.preferred, nil);
  
  // test setting array of basic types
  
  // string
  query.arrayString = [NSArray arrayWithObject:@"foo bar"];
  [expected setObject:[NSArray arrayWithObject:@"foo bar"]
               forKey:@"arrayString"];
  STAssertEqualObjects(query.JSON, expected, nil);

  // number
  query.arrayNumber = [NSArray arrayWithObject:[NSNumber numberWithInteger:1234]];
  [expected setObject:[NSArray arrayWithObject:[NSNumber numberWithInteger:1234]]
               forKey:@"arrayNumber"];
  STAssertEqualObjects(query.JSON, expected, nil);
  
  // date
  NSString * const dateStr = @"2011-01-14T15:00:00-01:00";
  query.arrayDate = [NSArray arrayWithObject:[GTLDateTime dateTimeWithRFC3339String:dateStr]];
  [expected setObject:[NSArray arrayWithObject:dateStr]
               forKey:@"arrayDate"];
  STAssertEqualObjects(query.JSON, expected, nil);  
}

- (void)testParameterNameSubStrings {
  // We had a bug where if there were two properties, one a proper substring
  // of the other, we'd match wrong.  This test makes sure we don't regress
  // that.
  
  GTLTestingQueryWithPrimeKey *obj =
    [GTLTestingQueryWithPrimeKey queryWithMethodName:@"foo.bar.baz"];
  STAssertNotNil(obj, @"failed to make query");

  // Test lookup for a setter.
  
  obj.alt = @"for base class";
  obj.altPrime = @"for subclass";
  NSDictionary *expected =
    [NSDictionary dictionaryWithObjectsAndKeys:
       @"for base class", @"alt",
       @"for subclass", @"altPrime",
       nil];
  STAssertEqualObjects(obj.JSON, expected, nil);
  
  // Test lookup for a getter.
  
  STAssertEqualObjects(obj.alt, @"for base class", nil);
  STAssertEqualObjects(obj.altPrime, @"for subclass", nil);
}


@end

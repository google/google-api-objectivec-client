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
@property (retain) NSString *userId;
@property (retain) NSString *msgId;
@property (retain) NSString *alt;
@property (retain) NSString *qS;
@property (assign) NSUInteger maxResults;
@property (assign) NSInteger aNumber;
@property (assign) double minValue;
@property (assign) BOOL preferred;
@end

@implementation GTLTestingQuery
@dynamic userId, msgId, alt, qS, maxResults, aNumber, minValue, preferred;
+ (NSDictionary *)parameterNameMap {
  return [NSDictionary dictionaryWithObjectsAndKeys:
          @"user-id", @"userId",
          @"q.s", @"qS",  // Test parameter names with '.' to be safe.
          @"max_results", @"maxResults",
          nil];
}
+ (NSDictionary *)defaultValueMap {
  NSDictionary *allMethods = [NSDictionary dictionaryWithObjectsAndKeys:
                              [NSNumber numberWithUnsignedInteger:20], @"max_results",
                              [NSNumber numberWithBool:YES], @"preferred",
                              nil];
  NSDictionary *mumbleMethod = [NSDictionary dictionaryWithObjectsAndKeys:
                                [NSNull null], @"max_results",
                                @"complex", @"alt",
                                nil];
  return [NSDictionary dictionaryWithObjectsAndKeys:
          allMethods, @"***",
          mumbleMethod, @"foo.bar.mumble",
          nil];
}
@end

@interface GTLTestingQueryWithPrimeKey : GTLTestingQuery
@property (retain) NSString *altPrime;
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
  STAssertEqualObjects(query.parameters, expected, nil);

  query.alt = @"simple";
  [expected setObject:@"simple" forKey:@"alt"];
  STAssertEqualObjects(query.parameters, expected, nil);

  query.qS = @"foo bar baz";
  [expected setObject:@"foo bar baz" forKey:@"q.s"];
  STAssertEqualObjects(query.parameters, expected, nil);

  query.maxResults = 15;
  [expected setObject:[NSNumber numberWithUnsignedInteger:15]
               forKey:@"max_results"];
  STAssertEqualObjects(query.parameters, expected, nil);
  STAssertEquals(query.maxResults, (NSUInteger)15, nil);
  
  query.aNumber = -10;
  [expected setObject:[NSNumber numberWithInteger:-10]
               forKey:@"aNumber"];
  STAssertEqualObjects(query.parameters, expected, nil);
  STAssertEquals(query.aNumber, (NSInteger)-10, nil);

  query.minValue = 20.0;
  [expected setObject:[NSNumber numberWithDouble:20]
               forKey:@"minValue"];
  STAssertEqualObjects(query.parameters, expected, nil);
  STAssertEquals(query.minValue, 20.0, nil);

  query.preferred = NO;
  [expected setObject:[NSNumber numberWithBool:NO]
               forKey:@"preferred"];
  STAssertEqualObjects(query.parameters, expected, nil);
  STAssertFalse(query.preferred, nil);
  
  // Default values don't show up in params but still fetch.xxx
  
  query.maxResults = 20;
  [expected removeObjectForKey:@"max_results"];
  STAssertEqualObjects(query.parameters, expected, nil);
  STAssertEquals(query.maxResults, (NSUInteger)20, nil);

  query.preferred = YES;
  [expected removeObjectForKey:@"preferred"];
  STAssertEqualObjects(query.parameters, expected, nil);
  STAssertTrue(query.preferred, nil);

  // Test method specific defaults
  
  methodName = @"foo.bar.mumble";
  query = [GTLTestingQuery queryWithMethodName:methodName];
  STAssertNotNil(query, @"failed to make query");
  [expected removeAllObjects];

  query.alt = @"simple";
  [expected setObject:@"simple" forKey:@"alt"];
  STAssertEqualObjects(query.parameters, expected, nil);

  query.alt = @"complex";
  [expected removeObjectForKey:@"alt"];
  STAssertEqualObjects(query.parameters, expected, nil);
  
  // Test no default in an override
  
  query.maxResults = 15;
  [expected setObject:[NSNumber numberWithUnsignedInteger:15]
               forKey:@"max_results"];
  STAssertEqualObjects(query.parameters, expected, nil);

  query.maxResults = 20;
  [expected setObject:[NSNumber numberWithUnsignedInteger:20]
               forKey:@"max_results"];
  STAssertEqualObjects(query.parameters, expected, nil);
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
  STAssertEqualObjects(obj.parameters, expected, nil);
  
  // Test lookup for a getter.
  
  STAssertEqualObjects(obj.alt, @"for base class", nil);
  STAssertEqualObjects(obj.altPrime, @"for subclass", nil);
}


@end

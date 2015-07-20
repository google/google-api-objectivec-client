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

#import "GTLUtilities.h"

@interface GTLUtilitiesTest : XCTestCase
@end

@implementation GTLUtilitiesTest

- (void)testPercentEncodingUTF8 {

  NSString *input;
  NSString *output;

  input = nil;
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  XCTAssertNil(output, @"nil test");

  input = @"";
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  XCTAssertEqualObjects(output, input, @"empty string");

  input = @"Fred & Wilma";
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  XCTAssertEqualObjects(output, input, @"plain string");

  input = [NSString stringWithFormat:@"The Beach at S%Cte", (unichar)0x00E8];
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  XCTAssertEqualObjects(output, @"The Beach at S%C3%A8te", @"8-bit failure");

  input = @"\ttab\tline1\rline2%percent\nline3";
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  XCTAssertEqualObjects(output, @"%09tab%09line1%0Dline2%25percent%0Aline3",
                       @"control char");

  input = [NSString stringWithFormat:@"photo%C.jpg", (unichar)0x53C3];
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  XCTAssertEqualObjects(output, @"photo%E5%8F%83.jpg", @"cjk failure");
}

- (void)testURLEncodingForStringParameter {
  NSString *input;
  NSString *output;
  NSString *expected;

  input = nil;
  output = [GTLUtilities stringByURLEncodingStringParameter:input];
  XCTAssertNil(output, @"nil test");

  input = @"";
  output = [GTLUtilities stringByURLEncodingStringParameter:input];
  XCTAssertEqualObjects(output, input, @"empty string");

  input = @"abcdef";
  output = [GTLUtilities stringByURLEncodingStringParameter:input];
  expected = @"abcdef";
  XCTAssertEqualObjects(output, expected, @"plain string");

  input = @"abc def";
  output = [GTLUtilities stringByURLEncodingStringParameter:input];
  expected = @"abc+def";
  XCTAssertEqualObjects(output, expected, @"plain string with space");

  input = @"abc!*'();:@&=+$,/?%#[]def";
  output = [GTLUtilities stringByURLEncodingStringParameter:input];
  expected = @"abc%21%2A%27%28%29%3B%3A%40%26%3D%2B%24%2C%2F%3F%25%23%5B%5Ddef";
  XCTAssertEqualObjects(output, expected, @"all chars to escape");
}

#pragma mark -

- (void)testFullURLFromStringQueryParameters {
  NSString *inputStr;
  NSDictionary *inputDict;
  NSURL *output;
  NSURL *expected;

  inputStr = nil;
  inputDict = nil;
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  XCTAssertNil(output, @"nil string test");

  inputStr = @"";
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  XCTAssertNil(output, @"empty string");

  inputStr = nil;
  inputDict = @{@"b": @"1"};
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  XCTAssertNil(output, @"nil string with params");

  inputStr = @"";
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  XCTAssertNil(output, @"empty string with params");

  inputStr = @"http://www.google.com";
  inputDict = nil;
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  expected = [NSURL URLWithString:@"http://www.google.com"];
  XCTAssertEqualObjects(output, expected, @"plain string");

  inputDict = @{};
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  XCTAssertEqualObjects(output, expected, @"plain string with empty params");

  inputDict = @{@"a": @"1", @"b": @"&"};
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  expected = [NSURL URLWithString:@"http://www.google.com?a=1&b=%26"];
  XCTAssertEqualObjects(output, expected, @"simple build");

  inputStr = @"http://www.google.com?q=spam";
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  expected = [NSURL URLWithString:@"http://www.google.com?q=spam&a=1&b=%26"];
  XCTAssertEqualObjects(output, expected, @"existing query args");
}

#pragma mark -

- (void)testEnsureNSNumber {
  NSNumber *num;
  NSNumber *result;

  result = GTL_EnsureNSNumber(nil);
  XCTAssertNil(result);

  // Give it a number, get the same thing back
  num = @12;
  result = GTL_EnsureNSNumber(num);
  XCTAssertEqualObjects(result, num);
  XCTAssertEqual(result, num);

  // Give it a string, and it converts...
  num = @0;
  result = GTL_EnsureNSNumber((NSNumber*)@"");
  XCTAssertEqualObjects(result, num);

  num = @0;
  result = GTL_EnsureNSNumber((NSNumber*)@"0");
  XCTAssertEqualObjects(result, num);

  num = @1000.01;
  result = GTL_EnsureNSNumber((NSNumber*)@"1000.01");
  XCTAssertEqualObjects(result, num);

  num = @-1000.01;
  result = GTL_EnsureNSNumber((NSNumber*)@"-1000.01");
  XCTAssertEqualObjects(result, num);

  // Check the values of the NSNumber objects created from strings.
  result = GTL_EnsureNSNumber((NSNumber*)@"1");
  XCTAssertEqual([result longLongValue], 1LL);

  result = GTL_EnsureNSNumber((NSNumber*)@"-1");
  XCTAssertEqual([result longLongValue], -1LL);

  result = GTL_EnsureNSNumber((NSNumber*)@"71100000000007780");
  XCTAssertEqual([result longLongValue], 71100000000007780LL);

  result = GTL_EnsureNSNumber((NSNumber*)@"-71100000000007780");
  XCTAssertEqual([result longLongValue], -71100000000007780LL);

  NSString *ullongmaxStr = [@(ULLONG_MAX) stringValue];
  result = GTL_EnsureNSNumber((NSNumber*)ullongmaxStr);
  XCTAssertEqual([result unsignedLongLongValue], ULLONG_MAX);

  NSString *llongminStr = [@(LLONG_MIN) stringValue];
  result = GTL_EnsureNSNumber((NSNumber*)llongminStr);
  XCTAssertEqual([result longLongValue], LLONG_MIN);
}

#pragma mark -

- (void)doTestEqualAndDistinctElementsInArray:(NSArray *)testArray
                                 andArrayCopy:(NSArray *)copyArray {

  NSUInteger numItems = [testArray count];

  // test that we got an equal copy
  XCTAssertEqualObjects(copyArray, testArray,
                       @"Array copy failed (%lu items)",
                       (unsigned long) numItems);

  // check that the objects in the copy are actual copies, not retains
  // of the original objects
  NSEnumerator *enumTest = [testArray objectEnumerator];
  NSEnumerator *enumCopy = [copyArray objectEnumerator];

  id objTest = [enumTest nextObject];
  id objCopy = [enumCopy nextObject];

  while (objTest) {
    XCTAssertTrue(objTest != objCopy,
                  @"array copy is reusing original object (%lu items)",
                 (unsigned long) numItems);

    objTest = [enumTest nextObject];
    objCopy = [enumCopy nextObject];
  }
}

- (void)doTestEqualAndDistinctElementsInDictionary:(NSDictionary *)testDict
                                 andDictionaryCopy:(NSDictionary *)copyDict {

  NSUInteger numItems = [testDict count];

  // test that we got an equal copy
  XCTAssertEqualObjects(copyDict, testDict,
                       @"Dict copy failed (%lu items)",
                       (unsigned long) numItems);

  // check that the objects in the copy are actual copies, not retains
  // of the original objects
  NSEnumerator *enumTestKeys = [testDict keyEnumerator];

  id testKey = [enumTestKeys nextObject];
  while (testKey) {
    id objTest = testDict[testKey];
    id objCopy = copyDict[testKey];

    XCTAssertTrue(objTest != objCopy,
                  @"dict copy is reusing original object (%lu items)",
                 (unsigned long) numItems);

    // if the elements are arrays, apply the array comparison too
    if ([objTest isKindOfClass:[NSArray class]]) {

     [self doTestEqualAndDistinctElementsInArray:objTest
                                    andArrayCopy:objCopy];
    }

    testKey = [enumTestKeys nextObject];
  }
}

@end

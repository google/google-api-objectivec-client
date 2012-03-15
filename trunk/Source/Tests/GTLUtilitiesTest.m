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

#import "GTLUtilities.h"

@interface GTLUtilitiesTest : SenTestCase
@end

@implementation GTLUtilitiesTest

- (void)testPercentEncodingUTF8 {

  NSString *input;
  NSString *output;

  input = nil;
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  STAssertNil(output, @"nil test");

  input = @"";
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  STAssertEqualObjects(output, input, @"empty string");

  input = @"Fred & Wilma";
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  STAssertEqualObjects(output, input, @"plain string");

  input = [NSString stringWithFormat:@"The Beach at S%Cte", 0x00E8];
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  STAssertEqualObjects(output, @"The Beach at S%C3%A8te", @"8-bit failure");

  input = @"\ttab\tline1\rline2%percent\nline3";
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  STAssertEqualObjects(output, @"%09tab%09line1%0Dline2%25percent%0Aline3",
                       @"control char");

  input = [NSString stringWithFormat:@"photo%C.jpg", 0x53C3];
  output = [GTLUtilities stringByPercentEncodingUTF8ForString:input];
  STAssertEqualObjects(output, @"photo%E5%8F%83.jpg", @"cjk failure");
}

- (void)testURLEncodingForURI {
  NSString *input;
  NSString *output;
  NSString *expected;

  input = nil;
  output = [GTLUtilities stringByURLEncodingForURI:input];
  STAssertNil(output, @"nil test");

  input = @"";
  output = [GTLUtilities stringByURLEncodingForURI:input];
  STAssertEqualObjects(output, input, @"empty string");

  input = @"abcdef";
  output = [GTLUtilities stringByURLEncodingForURI:input];
  expected = @"abcdef";
  STAssertEqualObjects(output, expected, @"plain string");

  input = @"abc def";
  output = [GTLUtilities stringByURLEncodingForURI:input];
  expected = @"abc%20def";
  STAssertEqualObjects(output, expected, @"plain string with space");

  input = @"abc!*'();:@&=+$,/?%#[]def";
  output = [GTLUtilities stringByURLEncodingForURI:input];
  expected = @"abc%21%2A%27%28%29%3B%3A%40%26%3D%2B%24%2C%2F%3F%25%23%5B%5Ddef";
  STAssertEqualObjects(output, expected, @"all chars to escape");
}

- (void)testURLEncodingForStringParameter {
  NSString *input;
  NSString *output;
  NSString *expected;

  input = nil;
  output = [GTLUtilities stringByURLEncodingStringParameter:input];
  STAssertNil(output, @"nil test");

  input = @"";
  output = [GTLUtilities stringByURLEncodingStringParameter:input];
  STAssertEqualObjects(output, input, @"empty string");

  input = @"abcdef";
  output = [GTLUtilities stringByURLEncodingStringParameter:input];
  expected = @"abcdef";
  STAssertEqualObjects(output, expected, @"plain string");

  input = @"abc def";
  output = [GTLUtilities stringByURLEncodingStringParameter:input];
  expected = @"abc+def";
  STAssertEqualObjects(output, expected, @"plain string with space");

  input = @"abc!*'();:@&=+$,/?%#[]def";
  output = [GTLUtilities stringByURLEncodingStringParameter:input];
  expected = @"abc%21%2A%27%28%29%3B%3A%40%26%3D%2B%24%2C%2F%3F%25%23%5B%5Ddef";
  STAssertEqualObjects(output, expected, @"all chars to escape");
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
  STAssertNil(output, @"nil string test");

  inputStr = @"";
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  STAssertNil(output, @"empty string");

  inputStr = nil;
  inputDict = [NSDictionary dictionaryWithObject:@"1" forKey:@"b"];
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  STAssertNil(output, @"nil string with params");

  inputStr = @"";
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  STAssertNil(output, @"empty string with params");

  inputStr = @"http://www.google.com";
  inputDict = nil;
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  expected = [NSURL URLWithString:@"http://www.google.com"];
  STAssertEqualObjects(output, expected, @"plain string");

  inputDict = [NSDictionary dictionary];
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  STAssertEqualObjects(output, expected, @"plain string with empty params");

  inputDict = [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"a", @"&", @"b", nil];
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  expected = [NSURL URLWithString:@"http://www.google.com?a=1&b=%26"];
  STAssertEqualObjects(output, expected, @"simple build");

  inputStr = @"http://www.google.com?q=spam";
  output = [GTLUtilities URLWithString:inputStr queryParameters:inputDict];
  expected = [NSURL URLWithString:@"http://www.google.com?q=spam&a=1&b=%26"];
  STAssertEqualObjects(output, expected, @"existing query args");
}

#pragma mark -

- (void)testEnsureNSNumber {
  NSNumber *num;
  NSNumber *result;

  // Give it a number, get the same thing back
  num = [NSNumber numberWithInteger:12];
  result = GTL_EnsureNSNumber(num);
  STAssertEqualObjects(num, result, nil);
  STAssertEquals(num, result, nil);

  // Give it a string, and it converts...
  num = [NSNumber numberWithDouble:1000.01];
  result = GTL_EnsureNSNumber((NSNumber*)@"1000.01");
  STAssertEqualObjects(num, result, nil);
}

#pragma mark -

- (void)doTestEqualAndDistinctElementsInArray:(NSArray *)testArray
                                 andArrayCopy:(NSArray *)copyArray {

  NSUInteger numItems = [testArray count];

  // test that we got an equal copy
  STAssertEqualObjects(copyArray, testArray,
                       @"Array copy failed (%lu items)",
                       (unsigned long) numItems);

  // check that the objects in the copy are actual copies, not retains
  // of the original objects
  NSEnumerator *enumTest = [testArray objectEnumerator];
  NSEnumerator *enumCopy = [copyArray objectEnumerator];

  id objTest = [enumTest nextObject];
  id objCopy = [enumCopy nextObject];

  while (objTest) {
    STAssertTrue(objTest != objCopy,
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
  STAssertEqualObjects(copyDict, testDict,
                       @"Dict copy failed (%lu items)",
                       (unsigned long) numItems);

  // check that the objects in the copy are actual copies, not retains
  // of the original objects
  NSEnumerator *enumTestKeys = [testDict keyEnumerator];

  id testKey = [enumTestKeys nextObject];
  while (testKey) {
    id objTest = [testDict objectForKey:testKey];
    id objCopy = [copyDict objectForKey:testKey];

    STAssertTrue(objTest != objCopy,
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

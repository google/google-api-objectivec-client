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

#import <Foundation/Foundation.h>


// Find the number of items in an inlined array.
#define ARRAY_COUNT(a) (sizeof(a) / sizeof(*(a)))


@interface FHUtils : NSObject

// This does its best to convert the strings (from discovery) into usable
// Objective-C names.  It filters out all non letter/number characters and
// uses those as markers to capitalize the next character to make CamelCase
// names. i.e. -
//     "max-results"  -> "maxResults"
//     "foo_bar"      -> "fooBar"
//     "userID"       -> "userID" (no change)
//     "800_number"   -> "x800Number" (ensure it starts with a letter)
+ (NSString *)objcName:(NSString *)str shouldCapitalize:(BOOL)shouldCapitalize;
+ (NSString *)objcName:(NSString *)str
      shouldCapitalize:(BOOL)shouldCapitalize
    allowLeadingDigits:(BOOL)allowLeadingDigits;

// Helper that takes all the elements in an array, and breaks them into lines
// word wrapped at 80 columns using the requested prefix/suffixes on the lines.
// Returns the resulting lines as a string.  A string in the array that is
// just a newline ('\n') will force the wrapping to start a new line.
+ (NSString *)stringOfLinesFromStrings:(NSArray *)arrayOfStrings
                       firstLinePrefix:(NSString *)firstLinePrefix
                      extraLinesPrefix:(NSString *)extraLinesPrefix
                           linesSuffix:(NSString *)linesSuffix
                        lastLineSuffix:(NSString *)lastLineSuffix
                         elementJoiner:(NSString *)elementJoiner;

// Helper to word wrap a string giving its specific prefix, suffix, and joiner.
// Newlines within str are honored.
+ (NSString *)stringOfLinesFromString:(NSString *)str
                      firstLinePrefix:(NSString *)firstLinePrefix
                     extraLinesPrefix:(NSString *)extraLinesPrefix
                          linesSuffix:(NSString *)linesSuffix
                       lastLineSuffix:(NSString *)lastLineSuffix
                        elementJoiner:(NSString *)elementJoiner;

// Helper to word wrap a string into a few lines when only needing a prefix and
// joined by spaces.  Newlines within str are honored.
+ (NSString *)stringOfLinesFromString:(NSString *)str
                           linePrefix:(NSString *)linePrefix;

// Helper to generate a class method that returns a mapping (dictionary).
+ (NSString *)classMapForMethodNamed:(NSString *)methodName
                               pairs:(NSDictionary *)pairs
                         quoteValues:(BOOL)quoteValues;

// Helper to wrap a bunch of strings with a suffix and/or prefix.
+ (NSArray *)wrapStrings:(NSArray *)arrayOfString
                  prefix:(NSString *)prefixStr
                  suffix:(NSString *)suffixStr;

// Helper to check if a string ends in a number.
+ (BOOL)stringEndsInNumber:(NSString *)str;

// Makes path into a full path handling relative or absolute paths.
+ (NSString *)fullPathWithPath:(NSString *)path;

// Looks for "yes" or "y", everything else is NO.
+ (BOOL)boolFromArg:(const char *)arg;

// Turns a BOOL into a string.
+ (const char *)strFromBool:(BOOL)val;

// Creates a directory and any intermediates.
+ (BOOL)createDir:(NSString *)fullPath error:(NSError **)err;

// Appends a URL parameter and value to the given URL string.
+ (NSString *)URLString:(NSString *)urlString
            addingParam:(NSString *)paramName
                  value:(NSString *)value;

@end

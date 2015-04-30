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

#import "FHUtils.h"
#import "GTLUtilities.h"

@implementation FHUtils

+ (NSString *)objcName:(NSString *)str shouldCapitalize:(BOOL)shouldCapitalize {
  return [self objcName:str
       shouldCapitalize:shouldCapitalize
     allowLeadingDigits:NO];
}

+ (NSString *)objcName:(NSString *)str
      shouldCapitalize:(BOOL)shouldCapitalize
    allowLeadingDigits:(BOOL)allowLeadingDigits {
  // Cache the character sets because this is done a lot...
  static NSCharacterSet *letterSet = nil;
  if (!letterSet) {
    // Just want a-zA-Z
    NSMutableCharacterSet *setBuilder =
        [NSMutableCharacterSet characterSetWithRange:NSMakeRange('a', 26)];
    [setBuilder addCharactersInRange:NSMakeRange('A', 26)];
    // Use immutable versions for speed in our checks.
    letterSet = [setBuilder copy];
  }
  static NSCharacterSet *letterNumSet = nil;
  if (!letterNumSet) {
    // Add 0-9 to our letterSet.
    NSMutableCharacterSet *setBuilder = [[letterSet mutableCopy] autorelease];
    [setBuilder addCharactersInRange:NSMakeRange('0', 10)];
    // Use immutable versions for speed in our checks.
    letterNumSet = [setBuilder copy];
  }

  if ([str length] == 0) {
    return nil;
  }

  // Do the transform...

  NSMutableString *worker = [NSMutableString string];

  BOOL isNewWord = shouldCapitalize;

  // If it doesn't start with a letter, put 'x' on the front.
  if (!allowLeadingDigits
      && ![letterSet characterIsMember:[str characterAtIndex:0]]) {
    [worker appendString:(isNewWord ? @"X" : @"x")];
    isNewWord = NO;
  }

  for (NSUInteger len = [str length], idx = 0; idx < len; ++idx ) {
    unichar curChar = [str characterAtIndex:idx];
    if ([letterNumSet characterIsMember:curChar]) {
      NSString *curCharStr = [NSString stringWithFormat:@"%C", curChar];
      if (isNewWord) {
        curCharStr = [curCharStr uppercaseString];
        isNewWord = NO;
      }
      [worker appendString:curCharStr];
    } else {
      isNewWord = YES;
    }

  }

  return worker;
}

#pragma mark -

+ (NSString *)stringOfLinesFromStrings:(NSArray *)arrayOfStrings
                       firstLinePrefix:(NSString *)firstLinePrefix
                      extraLinesPrefix:(NSString *)extraLinesPrefix
                           linesSuffix:(NSString *)linesSuffix
                        lastLineSuffix:(NSString *)lastLineSuffix
                         elementJoiner:(NSString *)elementJoiner {
  NSMutableArray *lines = [NSMutableArray array];

  const NSUInteger kMaxWidth = 80;

  // NOTE: This can trip up if it ever gets an element in arrayOfStrings that
  // is too long to fit on a line.

  NSUInteger linesSuffixLen = [linesSuffix length];
  NSUInteger lastLineSuffixLen = [lastLineSuffix length];
  NSUInteger suffixLen = MAX(linesSuffixLen, lastLineSuffixLen);
  NSUInteger elementJoinerLen = [elementJoiner length];

  NSMutableString *currentLine = [NSMutableString stringWithString:firstLinePrefix];
  BOOL needsJoiner = NO;

  for (NSString *element in arrayOfStrings) {
    BOOL elementIsNewline = [element isEqual:@"\n"];
    // Is this a newline or does it not fit?
    if (elementIsNewline ||
        (([currentLine length] + (needsJoiner ? elementJoinerLen : 0) + [element length]) > (kMaxWidth - suffixLen))) {
      // Add the current line to the result (but watch out for duplicate
      // newlines for leading newlines).
      if (![currentLine isEqual:extraLinesPrefix] &&
          ![currentLine isEqual:firstLinePrefix]) {
        // Add it.
        [lines addObject:currentLine];

        // Start a new line.
        currentLine = [NSMutableString stringWithString:extraLinesPrefix];
      }

      // New line is empty, no joiner needed.
      needsJoiner = NO;
    }
    if (!elementIsNewline) {
      if (needsJoiner) {
        [currentLine appendString:elementJoiner];
      }
      [currentLine appendString:element];
      needsJoiner = YES;
    }
  }
  // If we need a joiner, it means something got added to the last line, so
  // add it into the result.
  if (needsJoiner) {
    [lines addObject:currentLine];
  }

  // Result now has all of the mutable strings, so we join by the suffix and
  // a new line to glue all the lines together, and then we stick the final
  // line suffix onto the end.
  NSString *lineJoiner = [linesSuffix stringByAppendingString:@"\n"];
  NSString *allLinesStr = [lines componentsJoinedByString:lineJoiner];
  NSString *result = [allLinesStr stringByAppendingString:lastLineSuffix];
  return [result stringByAppendingString:@"\n"];
}

+ (NSString *)stringOfLinesFromString:(NSString *)str
                      firstLinePrefix:(NSString *)firstLinePrefix
                     extraLinesPrefix:(NSString *)extraLinesPrefix
                          linesSuffix:(NSString *)linesSuffix
                       lastLineSuffix:(NSString *)lastLineSuffix
                        elementJoiner:(NSString *)elementJoiner {
  // Support forced new line by letting them through as words.
  // The strings from discovery likely contain something like "foo\n- bar", we
  // want to tokenize to words, so we mainly use a split on spaces for that.
  // But since we want the newline marks not to be attached to words, we first
  // turn all of them into " \n ".  This way the split on spaces gives us
  // words along with the newline markers (ie- ["foo", "\n", "-", "bar"]).
  NSCharacterSet *nlSet = [NSCharacterSet newlineCharacterSet];
  NSArray *words = [str componentsSeparatedByCharactersInSet:nlSet];
  if ([words count] > 1) {
    str = [words componentsJoinedByString:@" \n "];
  }
  NSCharacterSet *wsSet = [NSCharacterSet whitespaceCharacterSet];
  words = [str componentsSeparatedByCharactersInSet:wsSet];

  // componentsSeparatedByCharactersInSet (and componentsSeparatedByString) is
  // documented to take adjacent occurrences of the separator and produce empty
  // strings in the result; remove those empty strings.
  NSMutableArray *cleanedWords = [NSMutableArray arrayWithArray:words];
  [cleanedWords removeObject:@""];

  // Now word wrap it.
  return [self stringOfLinesFromStrings:cleanedWords
                        firstLinePrefix:firstLinePrefix
                       extraLinesPrefix:extraLinesPrefix
                            linesSuffix:linesSuffix
                         lastLineSuffix:lastLineSuffix
                          elementJoiner:elementJoiner];
}

+ (NSString *)stringOfLinesFromString:(NSString *)str
                           linePrefix:(NSString *)linePrefix {
  return [self stringOfLinesFromString:str
                       firstLinePrefix:linePrefix
                      extraLinesPrefix:linePrefix
                           linesSuffix:@""
                        lastLineSuffix:@""
                         elementJoiner:@" "];
}

#pragma mark -

+ (NSString *)classMapForMethodNamed:(NSString *)methodName
                               pairs:(NSDictionary *)pairs
                         quoteValues:(BOOL)quoteValues {
  if ([pairs count] == 0) {
    return nil;
  }

  NSMutableString *result = [NSMutableString string];
  NSString *valueBefore = @"";
  NSString *valueAfter = @"";
  if (quoteValues) {
    valueBefore = @"@\"";
    valueAfter = @"\"";
  }

  NSArray *sortedKeys =
    [[pairs allKeys] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
  [result appendFormat:@"+ (NSDictionary *)%@ {\n", methodName];
  [result appendString:@"  NSDictionary *map = @{\n"];
  NSString *lastKey = sortedKeys.lastObject;
  for (NSString *key in sortedKeys) {
    NSString *value = [pairs objectForKey:key];
    [result appendFormat:@"    @\"%@\" : %@%@%@%@\n",
     key, valueBefore, value, valueAfter, (key == lastKey ? @"" : @",")];
  }
  [result appendString:@"  };\n"];
  [result appendString:@"  return map;\n"];
  [result appendString:@"}\n"];
  return result;
}

#pragma mark -

+ (NSArray *)wrapStrings:(NSArray *)arrayOfString
                  prefix:(NSString *)prefixStr
                  suffix:(NSString *)suffixStr {
  NSMutableArray *result = [NSMutableArray arrayWithCapacity:[arrayOfString count]];

  if (prefixStr == nil) prefixStr = @"";
  if (suffixStr == nil) suffixStr = @"";

  for (NSString *str in arrayOfString) {
    NSString *newStr = [NSString stringWithFormat:@"%@%@%@",
                        prefixStr, str, suffixStr];
    [result addObject:newStr];
  }

  return result;
}

+ (BOOL)stringEndsInNumber:(NSString *)str {
  if ([str length] == 0) {
    return NO;
  }

  unichar lastChar = [str characterAtIndex:[str length] - 1];
  BOOL result = (lastChar >= '0') && (lastChar <= '9');
  return result;
}

#pragma mark -

+ (NSString *)fullPathWithPath:(NSString *)path {
  if (![path hasPrefix:@"/"]) {
    NSFileManager *fm = [NSFileManager defaultManager];
    path = [[fm currentDirectoryPath] stringByAppendingPathComponent:path];
  }
  return [path stringByStandardizingPath];
}

+ (BOOL)boolFromArg:(const char *)arg {
  BOOL result = NO;
  if (strcasecmp(arg, "y") == 0 || strcasecmp(arg, "yes") == 0) {
    result = YES;
  }
  return result;
}

+ (const char *)strFromBool:(BOOL)val {
  return (val ? "YES" : "NO");
}

#pragma  mark -

+ (BOOL)createDir:(NSString *)fullPath error:(NSError **)err {
  NSFileManager *fm = [NSFileManager defaultManager];
  return [fm createDirectoryAtPath:fullPath
       withIntermediateDirectories:YES
                        attributes:nil
                             error:err];
}

#pragma mark -

+ (NSString *)URLString:(NSString *)urlString
            addingParam:(NSString *)paramName
                  value:(NSString *)value {
  if (urlString == nil) {
    return nil;
  }
  NSDictionary *params = @{ paramName : value };
  NSURL *resultURL = [GTLUtilities URLWithString:urlString
                                    queryParameters:params];
  NSString *result = [resultURL absoluteString];
  return result;
}

@end

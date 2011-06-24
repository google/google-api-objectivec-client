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
//  GTLDateTimeTest.m
//

#import <SenTestingKit/SenTestingKit.h>

#import "GTLDateTime.h"

@interface GTLDateTimeTest : SenTestCase
@end

@implementation GTLDateTimeTest
- (void)testGTLDateTime {
  const NSCalendarUnit kComponents =
    NSEraCalendarUnit
    | NSYearCalendarUnit
    | NSMonthCalendarUnit
    | NSDayCalendarUnit
    | NSHourCalendarUnit
    | NSMinuteCalendarUnit
    | NSSecondCalendarUnit;

  struct DateTimeTestRecord {
    NSString *dateTimeStr;
    NSInteger year;
    NSInteger month;
    NSInteger day;
    NSInteger hour;
    NSInteger minute;
    NSInteger second;
    NSInteger timeZoneOffsetSeconds;
    BOOL isUniversalTime;
    BOOL hasTime;
  };

  struct DateTimeTestRecord tests[] = {
    { @"2006-10-14T15:00:00-01:00", 2006, 10, 14, 15, 0, 0, -60*60, 0, 1 },
    { @"2006-10-14T15:00:00Z", 2006, 10, 14, 15, 0, 0, 0, 1, 1 },
    { @"2006-10-14", 2006, 10, 14, 12, 0, 0, 0, 1, 0 },
    { nil, 0, 0, 0, 0, 0, 0, 0, 0 }
  };

  int idx;
  for (idx = 0; tests[idx].dateTimeStr != nil; idx++) {
    NSString *testString1 = tests[idx].dateTimeStr;
    GTLDateTime *dateTime = [GTLDateTime dateTimeWithRFC3339String:testString1];
    NSString *outputString = [dateTime RFC3339String];

    STAssertEqualObjects(outputString, testString1,
                         @"failed to recreate string %@ as %@",
                         testString1, outputString);

    NSDate *outputDate = [dateTime date];

    NSCalendar *cal = [dateTime calendar];
    NSDateComponents *outputComponents = [cal components:kComponents
                                                fromDate:outputDate];
    STAssertEquals([outputComponents year], tests[idx].year, @"bad year");
    STAssertEquals([outputComponents month], tests[idx].month, @"bad month");
    STAssertEquals([outputComponents day], tests[idx].day, @"bad day");
    STAssertEquals([outputComponents hour], tests[idx].hour, @"bad hour");
    STAssertEquals([outputComponents minute], tests[idx].minute, @"bad minute");
    STAssertEquals([outputComponents second], tests[idx].second, @"bad second");

    STAssertEquals([[dateTime timeZone] secondsFromGMT], tests[idx].timeZoneOffsetSeconds, @"bad timezone");
    STAssertEquals([dateTime isUniversalTime], tests[idx].isUniversalTime, @"bad Zulu value");
    STAssertEquals([dateTime hasTime], tests[idx].hasTime, @"bad hasTime value");

    if ([dateTime hasTime]) {
      // remove the time, test the output
      [dateTime setHasTime:NO];
      NSString *outputStringWithoutTime = [dateTime RFC3339String];
      STAssertFalse([dateTime hasTime], @"should have time removed");
      STAssertTrue([testString1 hasPrefix:outputStringWithoutTime]
                   && [testString1 length] > [outputStringWithoutTime length],
                   @"bad string after time removed");
    } else {
      // add time, test the output
      [dateTime setHasTime:YES];
      NSString *outputStringWithTime = [dateTime RFC3339String];
      STAssertTrue([dateTime hasTime], @"should have time added");
      STAssertTrue([outputStringWithTime hasPrefix:testString1]
                   && [testString1 length] < [outputStringWithTime length],
                   @"bad string after time removed");
    }
  }
}

- (void)testTimeZonePreservation {
  NSTimeZone *denverTZ = [NSTimeZone timeZoneWithName:@"America/Denver"];
  NSCalendarDate *date = [NSCalendarDate dateWithYear:2007 month:01 day:01
                                                 hour:01 minute:01 second:01
                                             timeZone:denverTZ];

  GTLDateTime *dateTime = [GTLDateTime dateTimeWithDate:date
                                                   timeZone:denverTZ];
  NSTimeZone *testTZ = [dateTime timeZone];
  STAssertEqualObjects(testTZ, denverTZ, @"Time zone changed");
}
@end

//2006-11-20 17:53:23.880 otest[5401] timezone=GMT-0100 (GMT-0100) offset -3600
//2006-11-20 17:53:23.880 otest[5401] era:1 year:2006 month:10 day:14   hour:15 min:0 sec:0

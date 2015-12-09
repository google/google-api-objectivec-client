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

#import <XCTest/XCTest.h>

#import "GTLDateTime.h"

@interface GTLDateTimeTest : XCTestCase
@end

@implementation GTLDateTimeTest

- (void)testGTLDateTime {
  const NSCalendarUnit kComponents = (NSCalendarUnitEra
                                      | NSCalendarUnitYear
                                      | NSCalendarUnitMonth
                                      | NSCalendarUnitDay
                                      | NSCalendarUnitHour
                                      | NSCalendarUnitMinute
                                      | NSCalendarUnitSecond);
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
    { nil, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
  };

  GTLDateTime *dateTimeFromNil = [GTLDateTime dateTimeWithRFC3339String:nil];
  XCTAssertNil(dateTimeFromNil);

  GTLDateTime *dateTimeFromEmpty = [GTLDateTime dateTimeWithRFC3339String:@""];
  XCTAssertEqual([dateTimeFromEmpty.dateComponents year], NSDateComponentUndefined);

  int idx;
  for (idx = 0; tests[idx].dateTimeStr != nil; idx++) {
    NSString *testString1 = tests[idx].dateTimeStr;
    GTLDateTime *dateTimeOriginal = [GTLDateTime dateTimeWithRFC3339String:testString1];
    // Copy the date to make sure that works and then validate everything on
    // the copy.
    GTLDateTime *dateTime = [[dateTimeOriginal copy] autorelease];
    XCTAssertEqualObjects(dateTimeOriginal, dateTime);

    NSString *outputString = dateTime.RFC3339String;

    XCTAssertEqualObjects(outputString, testString1,
                         @"failed to recreate string %@ as %@",
                         testString1, outputString);

    NSDate *outputDate = dateTime.date;

    NSCalendar *cal = dateTime.calendar;
    NSDateComponents *outputComponents = [cal components:kComponents
                                                fromDate:outputDate];
    XCTAssertEqual([outputComponents year], tests[idx].year);
    XCTAssertEqual([outputComponents month], tests[idx].month);
    XCTAssertEqual([outputComponents day], tests[idx].day);
    XCTAssertEqual([outputComponents hour], tests[idx].hour);
    XCTAssertEqual([outputComponents minute], tests[idx].minute);
    XCTAssertEqual([outputComponents second], tests[idx].second);

    XCTAssertEqual([dateTime.timeZone secondsFromGMT], tests[idx].timeZoneOffsetSeconds);
    XCTAssertEqual(dateTime.isUniversalTime, tests[idx].isUniversalTime);
    XCTAssertEqual(dateTime.hasTime, tests[idx].hasTime);
  }
}

- (void)testFractionalSeconds {
  // See the note at the top of GTLDateTime for the expected behaviors.

  struct FractionalSecondsTestRecord {
    NSString *input;
    NSString *expected;
  };

  struct FractionalSecondsTestRecord tests[] = {
    // This was a trouble case and called for the round() usage, without round
    // and using a cast, it truncates the double to 734 even though %f prints it
    // as .735.
    { @"2011-05-03T23:14:20.735Z", @"2011-05-03T23:14:20.735Z" }, // Same in/out
    // Extra digits
    { @"2011-05-03T23:14:20.12345Z", @"2011-05-03T23:14:20.123Z" },
    // Fewer digits
    { @"2011-05-03T23:14:20.12Z", @"2011-05-03T23:14:20.120Z" },
    { @"2011-05-03T23:14:20.1Z", @"2011-05-03T23:14:20.100Z" },
    // Leading zero (make sure we never turn .001 -> .1.
    { @"2011-05-03T23:14:20.001Z", @"2011-05-03T23:14:20.001Z" }, // Same in/out
    { @"2011-05-03T23:14:20.01Z", @"2011-05-03T23:14:20.010Z" },
    // We eat (don't display) fractions of just zeros.
    { @"2011-05-03T23:14:20.000Z", @"2011-05-03T23:14:20Z" },
    { @"2011-05-03T23:14:20.00Z", @"2011-05-03T23:14:20Z" },
    { @"2011-05-03T23:14:20.0Z", @"2011-05-03T23:14:20Z" },
    // Quick test of the other time offset format
    { @"2006-10-14T15:00:00.111-01:00", @"2006-10-14T15:00:00.111-01:00" }, // Same in/out
    // Done
    { nil, nil }
  };

  for (int idx = 0; tests[idx].input != nil; idx++) {
    NSString *testString = tests[idx].input;
    NSString *expectedString = tests[idx].expected;

    GTLDateTime *dateTimeOriginal = [GTLDateTime dateTimeWithRFC3339String:testString];

    // Bounce through a -copy and an NSDate to make sure the fractions of a
    // second make it all the way.
    GTLDateTime *dateTimeCopied = [[dateTimeOriginal copy] autorelease];
    XCTAssertEqualObjects(dateTimeCopied, dateTimeOriginal);
    NSDate *outputDate = dateTimeCopied.date;
    GTLDateTime *dateTimeFromDate = [GTLDateTime dateTimeWithDate:outputDate
                                                         timeZone:dateTimeCopied.timeZone];
    XCTAssertEqualObjects(dateTimeFromDate, dateTimeOriginal);

    XCTAssertEqualObjects(dateTimeFromDate.RFC3339String, expectedString);
  }
}

- (void)testTimeZonePreservation {
  NSTimeZone *denverTZ = [NSTimeZone timeZoneWithName:@"America/Denver"];
  NSDate *date = [self dateWithYear:2007
                              month:01
                                day:01
                               hour:01
                             minute:01
                             second:01
                           timeZone:denverTZ];

  GTLDateTime *dateTime = [GTLDateTime dateTimeWithDate:date
                                               timeZone:denverTZ];
  NSTimeZone *testTZ = dateTime.timeZone;
  XCTAssertEqualObjects(testTZ, denverTZ);
}

- (void)testCalendarCaching {
  NSTimeZone *denverTZ = [NSTimeZone timeZoneWithName:@"America/Denver"];
  NSDate *date = [self dateWithYear:2007
                              month:01
                                day:01
                               hour:01
                             minute:01
                             second:01
                           timeZone:denverTZ];

  GTLDateTime *dateTime = [GTLDateTime dateTimeWithDate:date
                                               timeZone:denverTZ];

  // Test that the calendar instance is cached for the time zone (comparing
  // pointer values.)
  NSTimeZone *denverTZ2 = [NSTimeZone timeZoneWithName:@"America/Denver"];
  GTLDateTime *dateTime2 = [GTLDateTime dateTimeWithDate:date
                                               timeZone:denverTZ2];
  XCTAssertEqual(dateTime2.calendar, dateTime.calendar);

  // RFC3339 strings have offsets but not named time zones.
  NSString *str = [dateTime RFC3339String];
  GTLDateTime *dateTime3 = [GTLDateTime dateTimeWithRFC3339String:str];
  GTLDateTime *dateTime4 = [GTLDateTime dateTimeWithRFC3339String:str];

  XCTAssertEqual(dateTime3.calendar, dateTime4.calendar);

  // The timezones don't match, so the calendars should be unique, but the
  // time zone offsets from GMT are the same.
  XCTAssertNotEqual(dateTime3.calendar, dateTime.calendar);
  XCTAssertEqual(dateTime3.calendar.timeZone.secondsFromGMT,
                 (dateTime.calendar.timeZone.secondsFromGMT -
                  (NSInteger)[dateTime.timeZone daylightSavingTimeOffset]));
}

- (NSDate *)dateWithYear:(NSInteger)year
                   month:(NSInteger)month
                     day:(NSInteger)day
                    hour:(NSInteger)hour
                  minute:(NSInteger)minute
                  second:(NSInteger)second
                timeZone:(NSTimeZone *)tz {
  NSCalendar *calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];
  NSDateComponents *components = [[[NSDateComponents alloc] init] autorelease];
  components.year = year;
  components.month = month;
  components.day = day;
  components.hour = hour;
  components.minute = minute;
  components.second = second;
  components.timeZone = tz;
  NSDate *result = [calendar dateFromComponents:components];
  return result;
}

@end

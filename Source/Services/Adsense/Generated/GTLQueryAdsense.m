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
//  GTLQueryAdsense.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://code.google.com/apis/adsense/management/
// Classes:
//   GTLQueryAdsense (5 custom class methods, 14 custom properties)

#import "GTLQueryAdsense.h"

#import "GTLAdsenseAdClients.h"
#import "GTLAdsenseAdsenseReportsGenerateResponse.h"
#import "GTLAdsenseAdUnits.h"
#import "GTLAdsenseCustomChannels.h"
#import "GTLAdsenseUrlChannels.h"

@implementation GTLQueryAdsense

@dynamic adClientId, currency, dimension, endDate, fields, filter,
         includeInactive, locale, maxResults, metric, pageToken, sort,
         startDate, startIndex;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [NSString class], @"dimension",
      [NSString class], @"filter",
      [NSString class], @"metric",
      [NSString class], @"sort",
      nil];
  return map;
}

#pragma mark -
#pragma mark "adclients" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAdclientsList {
  NSString *methodName = @"adsense.adclients.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLAdsenseAdClients class];
  return query;
}

#pragma mark -
#pragma mark "adunits" methods
// These create a GTLQueryAdsense object.

+ (id)queryForAdunitsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.adunits.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdsenseAdUnits class];
  return query;
}

#pragma mark -
#pragma mark "customchannels" methods
// These create a GTLQueryAdsense object.

+ (id)queryForCustomchannelsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.customchannels.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdsenseCustomChannels class];
  return query;
}

#pragma mark -
#pragma mark "reports" methods
// These create a GTLQueryAdsense object.

+ (id)queryForReportsGenerateWithStartDate:(NSString *)startDate
                                   endDate:(NSString *)endDate {
  NSString *methodName = @"adsense.reports.generate";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.startDate = startDate;
  query.endDate = endDate;
  query.expectedObjectClass = [GTLAdsenseAdsenseReportsGenerateResponse class];
  return query;
}

#pragma mark -
#pragma mark "urlchannels" methods
// These create a GTLQueryAdsense object.

+ (id)queryForUrlchannelsListWithAdClientId:(NSString *)adClientId {
  NSString *methodName = @"adsense.urlchannels.list";
  GTLQueryAdsense *query = [self queryWithMethodName:methodName];
  query.adClientId = adClientId;
  query.expectedObjectClass = [GTLAdsenseUrlChannels class];
  return query;
}

@end

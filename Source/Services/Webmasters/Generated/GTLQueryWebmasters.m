/* Copyright (c) 2015 Google Inc.
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
//  GTLQueryWebmasters.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Webmaster Tools API (webmasters/v3)
// Description:
//   Lets you view Google Webmaster Tools data for your verified sites.
// Documentation:
//   https://developers.google.com/webmaster-tools/
// Classes:
//   GTLQueryWebmasters (13 custom class methods, 15 custom properties)

#import "GTLQueryWebmasters.h"

#import "GTLWebmastersApiDimensionFilterGroup.h"
#import "GTLWebmastersSearchAnalyticsQueryResponse.h"
#import "GTLWebmastersSitemapsListResponse.h"
#import "GTLWebmastersSitesListResponse.h"
#import "GTLWebmastersUrlCrawlErrorsCountsQueryResponse.h"
#import "GTLWebmastersUrlCrawlErrorsSample.h"
#import "GTLWebmastersUrlCrawlErrorsSamplesListResponse.h"
#import "GTLWebmastersWmxSite.h"
#import "GTLWebmastersWmxSitemap.h"

@implementation GTLQueryWebmasters

@dynamic aggregationType, category, dimensionFilterGroups, dimensions, endDate,
         feedpath, fields, latestCountsOnly, platform, rowLimit, searchType,
         sitemapIndex, siteUrl, startDate, url;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"dimensionFilterGroups" : [GTLWebmastersApiDimensionFilterGroup class],
    @"dimensions" : [NSString class]
  };
  return map;
}

#pragma mark - "searchanalytics" methods
// These create a GTLQueryWebmasters object.

+ (instancetype)queryForSearchanalyticsQueryWithSiteUrl:(NSString *)siteUrl {
  NSString *methodName = @"webmasters.searchanalytics.query";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.expectedObjectClass = [GTLWebmastersSearchAnalyticsQueryResponse class];
  return query;
}

#pragma mark - "sitemaps" methods
// These create a GTLQueryWebmasters object.

+ (instancetype)queryForSitemapsDeleteWithSiteUrl:(NSString *)siteUrl
                                         feedpath:(NSString *)feedpath {
  NSString *methodName = @"webmasters.sitemaps.delete";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.feedpath = feedpath;
  return query;
}

+ (instancetype)queryForSitemapsGetWithSiteUrl:(NSString *)siteUrl
                                      feedpath:(NSString *)feedpath {
  NSString *methodName = @"webmasters.sitemaps.get";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.feedpath = feedpath;
  query.expectedObjectClass = [GTLWebmastersWmxSitemap class];
  return query;
}

+ (instancetype)queryForSitemapsListWithSiteUrl:(NSString *)siteUrl {
  NSString *methodName = @"webmasters.sitemaps.list";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.expectedObjectClass = [GTLWebmastersSitemapsListResponse class];
  return query;
}

+ (instancetype)queryForSitemapsSubmitWithSiteUrl:(NSString *)siteUrl
                                         feedpath:(NSString *)feedpath {
  NSString *methodName = @"webmasters.sitemaps.submit";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.feedpath = feedpath;
  return query;
}

#pragma mark - "sites" methods
// These create a GTLQueryWebmasters object.

+ (instancetype)queryForSitesAddWithSiteUrl:(NSString *)siteUrl {
  NSString *methodName = @"webmasters.sites.add";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  return query;
}

+ (instancetype)queryForSitesDeleteWithSiteUrl:(NSString *)siteUrl {
  NSString *methodName = @"webmasters.sites.delete";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  return query;
}

+ (instancetype)queryForSitesGetWithSiteUrl:(NSString *)siteUrl {
  NSString *methodName = @"webmasters.sites.get";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.expectedObjectClass = [GTLWebmastersWmxSite class];
  return query;
}

+ (instancetype)queryForSitesList {
  NSString *methodName = @"webmasters.sites.list";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLWebmastersSitesListResponse class];
  return query;
}

#pragma mark - "urlcrawlerrorscounts" methods
// These create a GTLQueryWebmasters object.

+ (instancetype)queryForUrlcrawlerrorscountsQueryWithSiteUrl:(NSString *)siteUrl {
  NSString *methodName = @"webmasters.urlcrawlerrorscounts.query";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.expectedObjectClass = [GTLWebmastersUrlCrawlErrorsCountsQueryResponse class];
  return query;
}

#pragma mark - "urlcrawlerrorssamples" methods
// These create a GTLQueryWebmasters object.

+ (instancetype)queryForUrlcrawlerrorssamplesGetWithSiteUrl:(NSString *)siteUrl
                                                        url:(NSString *)url
                                                   category:(NSString *)category
                                                   platform:(NSString *)platform {
  NSString *methodName = @"webmasters.urlcrawlerrorssamples.get";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.url = url;
  query.category = category;
  query.platform = platform;
  query.expectedObjectClass = [GTLWebmastersUrlCrawlErrorsSample class];
  return query;
}

+ (instancetype)queryForUrlcrawlerrorssamplesListWithSiteUrl:(NSString *)siteUrl
                                                    category:(NSString *)category
                                                    platform:(NSString *)platform {
  NSString *methodName = @"webmasters.urlcrawlerrorssamples.list";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.category = category;
  query.platform = platform;
  query.expectedObjectClass = [GTLWebmastersUrlCrawlErrorsSamplesListResponse class];
  return query;
}

+ (instancetype)queryForUrlcrawlerrorssamplesMarkAsFixedWithSiteUrl:(NSString *)siteUrl
                                                                url:(NSString *)url
                                                           category:(NSString *)category
                                                           platform:(NSString *)platform {
  NSString *methodName = @"webmasters.urlcrawlerrorssamples.markAsFixed";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.url = url;
  query.category = category;
  query.platform = platform;
  return query;
}

@end

/* Copyright (c) 2014 Google Inc.
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
//   https://developers.google.com/webmaster-tools/v3/welcome
// Classes:
//   GTLQueryWebmasters (12 custom class methods, 8 custom properties)

#import "GTLQueryWebmasters.h"

#import "GTLWebmastersSitemapsListResponse.h"
#import "GTLWebmastersSitesListResponse.h"
#import "GTLWebmastersUrlCrawlErrorsCountsQueryResponse.h"
#import "GTLWebmastersUrlCrawlErrorsSample.h"
#import "GTLWebmastersUrlCrawlErrorsSamplesListResponse.h"
#import "GTLWebmastersWmxSite.h"
#import "GTLWebmastersWmxSitemap.h"

@implementation GTLQueryWebmasters

@dynamic category, feedpath, fields, latestCountsOnly, platform, sitemapIndex,
         siteUrl, url;

#pragma mark -
#pragma mark "sitemaps" methods
// These create a GTLQueryWebmasters object.

+ (id)queryForSitemapsDeleteWithSiteUrl:(NSString *)siteUrl
                               feedpath:(NSString *)feedpath {
  NSString *methodName = @"webmasters.sitemaps.delete";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.feedpath = feedpath;
  return query;
}

+ (id)queryForSitemapsGetWithSiteUrl:(NSString *)siteUrl
                            feedpath:(NSString *)feedpath {
  NSString *methodName = @"webmasters.sitemaps.get";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.feedpath = feedpath;
  query.expectedObjectClass = [GTLWebmastersWmxSitemap class];
  return query;
}

+ (id)queryForSitemapsListWithSiteUrl:(NSString *)siteUrl {
  NSString *methodName = @"webmasters.sitemaps.list";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.expectedObjectClass = [GTLWebmastersSitemapsListResponse class];
  return query;
}

+ (id)queryForSitemapsSubmitWithSiteUrl:(NSString *)siteUrl
                               feedpath:(NSString *)feedpath {
  NSString *methodName = @"webmasters.sitemaps.submit";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.feedpath = feedpath;
  return query;
}

#pragma mark -
#pragma mark "sites" methods
// These create a GTLQueryWebmasters object.

+ (id)queryForSitesAddWithSiteUrl:(NSString *)siteUrl {
  NSString *methodName = @"webmasters.sites.add";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  return query;
}

+ (id)queryForSitesDeleteWithSiteUrl:(NSString *)siteUrl {
  NSString *methodName = @"webmasters.sites.delete";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  return query;
}

+ (id)queryForSitesGetWithSiteUrl:(NSString *)siteUrl {
  NSString *methodName = @"webmasters.sites.get";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.expectedObjectClass = [GTLWebmastersWmxSite class];
  return query;
}

+ (id)queryForSitesList {
  NSString *methodName = @"webmasters.sites.list";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLWebmastersSitesListResponse class];
  return query;
}

#pragma mark -
#pragma mark "urlcrawlerrorscounts" methods
// These create a GTLQueryWebmasters object.

+ (id)queryForUrlcrawlerrorscountsQueryWithSiteUrl:(NSString *)siteUrl {
  NSString *methodName = @"webmasters.urlcrawlerrorscounts.query";
  GTLQueryWebmasters *query = [self queryWithMethodName:methodName];
  query.siteUrl = siteUrl;
  query.expectedObjectClass = [GTLWebmastersUrlCrawlErrorsCountsQueryResponse class];
  return query;
}

#pragma mark -
#pragma mark "urlcrawlerrorssamples" methods
// These create a GTLQueryWebmasters object.

+ (id)queryForUrlcrawlerrorssamplesGetWithSiteUrl:(NSString *)siteUrl
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

+ (id)queryForUrlcrawlerrorssamplesListWithSiteUrl:(NSString *)siteUrl
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

+ (id)queryForUrlcrawlerrorssamplesMarkAsFixedWithSiteUrl:(NSString *)siteUrl
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

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
//  GTLQueryWebmasters.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLWebmastersApiDimensionFilterGroup;

@interface GTLQueryWebmasters : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, copy) NSString *aggregationType;
@property (nonatomic, copy) NSString *category;
@property (nonatomic, retain) NSArray *dimensionFilterGroups;  // of GTLWebmastersApiDimensionFilterGroup
@property (nonatomic, retain) NSArray *dimensions;  // of NSString
@property (nonatomic, copy) NSString *endDate;
@property (nonatomic, copy) NSString *feedpath;
@property (nonatomic, assign) BOOL latestCountsOnly;
@property (nonatomic, copy) NSString *platform;
@property (nonatomic, assign) NSInteger rowLimit;
@property (nonatomic, copy) NSString *searchType;
@property (nonatomic, copy) NSString *sitemapIndex;
@property (nonatomic, copy) NSString *siteUrl;
@property (nonatomic, copy) NSString *startDate;
@property (nonatomic, copy) NSString *url;

#pragma mark -
#pragma mark "searchanalytics" methods
// These create a GTLQueryWebmasters object.

// Method: webmasters.searchanalytics.query
// [LIMITED ACCESS]
// Query your data with filters and parameters that you define. Returns zero or
// more rows grouped by the row keys that you define. You must define a date
// range of one or more days.
// When date is one of the group by values, any days without data are omitted
// from the result list. If you need to know which days have data, issue a broad
// date range query grouped by date for any metric, and see which day rows are
// returned.
//  Required:
//   siteUrl: The site's URL, including protocol. For example:
//     http://www.example.com/
//  Optional:
//   aggregationType: [Optional; Default is AUTO] How data is aggregated. If
//     aggregated by property, all data for the same property is aggregated; if
//     aggregated by page, all data is aggregated by canonical URI. If you
//     filter or group by page, choose AUTO; otherwise you can aggregate either
//     by property or by page, depending on how you want your data calculated;
//     see the help documentation to learn how data is calculated differently by
//     site versus by page.
//     Note: If you group or filter by page, you cannot aggregate by property.
//     If you specify any value other than AUTO, the aggregation type in the
//     result will match the requested type, or if you request an invalid type,
//     you will get an error. The API will never change your aggregation type if
//     the requested type is invalid.
//   dimensionFilterGroups: [Optional] Zero or more filters to apply to the
//     dimension grouping values; for example, 'Country CONTAINS "Guinea"' to
//     see only data where the country contains the substring "Guinea". You can
//     filter by a dimension without grouping by it.
//   dimensions: [Optional] Zero or more dimensions to group results by.
//     Dimensions are the group-by values in the Search Analytics page.
//     Dimensions are combined to create a unique row key for each row. Results
//     are grouped in the order that you supply these dimensions.
//   endDate: [Required] End date of the requested date range, in YYYY-MM-DD
//     format, in PST (UTC - 8:00). Must be greater than or equal to the start
//     date. This value is included in the range.
//   rowLimit: [Optional; Default is 1000] The maximum number of rows to return.
//     Must be a number from 1 to 1,000 (inclusive).
//   searchType: [Optional; Default is WEB] The search type to filter for.
//   startDate: [Required] Start date of the requested date range, in YYYY-MM-DD
//     format, in PST time (UTC - 8:00). Must be less than or equal to the end
//     date. This value is included in the range.
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
//   kGTLAuthScopeWebmastersReadonly
// Fetches a GTLWebmastersSearchAnalyticsQueryResponse.
+ (instancetype)queryForSearchanalyticsQueryWithSiteUrl:(NSString *)siteUrl;

#pragma mark -
#pragma mark "sitemaps" methods
// These create a GTLQueryWebmasters object.

// Method: webmasters.sitemaps.delete
// Deletes a sitemap from this site.
//  Required:
//   siteUrl: The site's URL, including protocol. For example:
//     http://www.example.com/
//   feedpath: The URL of the actual sitemap. For example:
//     http://www.example.com/sitemap.xml
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
+ (instancetype)queryForSitemapsDeleteWithSiteUrl:(NSString *)siteUrl
                                         feedpath:(NSString *)feedpath;

// Method: webmasters.sitemaps.get
// Retrieves information about a specific sitemap.
//  Required:
//   siteUrl: The site's URL, including protocol. For example:
//     http://www.example.com/
//   feedpath: The URL of the actual sitemap. For example:
//     http://www.example.com/sitemap.xml
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
//   kGTLAuthScopeWebmastersReadonly
// Fetches a GTLWebmastersWmxSitemap.
+ (instancetype)queryForSitemapsGetWithSiteUrl:(NSString *)siteUrl
                                      feedpath:(NSString *)feedpath;

// Method: webmasters.sitemaps.list
// Lists the sitemaps-entries submitted for this site, or included in the
// sitemap index file (if sitemapIndex is specified in the request).
//  Required:
//   siteUrl: The site's URL, including protocol. For example:
//     http://www.example.com/
//  Optional:
//   sitemapIndex: A URL of a site's sitemap index. For example:
//     http://www.example.com/sitemapindex.xml
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
//   kGTLAuthScopeWebmastersReadonly
// Fetches a GTLWebmastersSitemapsListResponse.
+ (instancetype)queryForSitemapsListWithSiteUrl:(NSString *)siteUrl;

// Method: webmasters.sitemaps.submit
// Submits a sitemap for a site.
//  Required:
//   siteUrl: The site's URL, including protocol. For example:
//     http://www.example.com/
//   feedpath: The URL of the sitemap to add. For example:
//     http://www.example.com/sitemap.xml
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
+ (instancetype)queryForSitemapsSubmitWithSiteUrl:(NSString *)siteUrl
                                         feedpath:(NSString *)feedpath;

#pragma mark -
#pragma mark "sites" methods
// These create a GTLQueryWebmasters object.

// Method: webmasters.sites.add
// Adds a site to the set of the user's sites in Webmaster Tools.
//  Required:
//   siteUrl: The URL of the site to add.
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
+ (instancetype)queryForSitesAddWithSiteUrl:(NSString *)siteUrl;

// Method: webmasters.sites.delete
// Removes a site from the set of the user's Webmaster Tools sites.
//  Required:
//   siteUrl: The URI of the property as defined in Search Console. Examples:
//     http://www.example.com/ or android-app://com.example/
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
+ (instancetype)queryForSitesDeleteWithSiteUrl:(NSString *)siteUrl;

// Method: webmasters.sites.get
// Retrieves information about specific site.
//  Required:
//   siteUrl: The URI of the property as defined in Search Console. Examples:
//     http://www.example.com/ or android-app://com.example/
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
//   kGTLAuthScopeWebmastersReadonly
// Fetches a GTLWebmastersWmxSite.
+ (instancetype)queryForSitesGetWithSiteUrl:(NSString *)siteUrl;

// Method: webmasters.sites.list
// Lists the user's Webmaster Tools sites.
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
//   kGTLAuthScopeWebmastersReadonly
// Fetches a GTLWebmastersSitesListResponse.
+ (instancetype)queryForSitesList;

#pragma mark -
#pragma mark "urlcrawlerrorscounts" methods
// These create a GTLQueryWebmasters object.

// Method: webmasters.urlcrawlerrorscounts.query
// Retrieves a time series of the number of URL crawl errors per error category
// and platform.
//  Required:
//   siteUrl: The site's URL, including protocol. For example:
//     http://www.example.com/
//  Optional:
//   category: The crawl error category. For example: serverError. If not
//     specified, returns results for all categories.
//      kGTLWebmastersCategoryAuthPermissions: "authPermissions"
//      kGTLWebmastersCategoryManyToOneRedirect: "manyToOneRedirect"
//      kGTLWebmastersCategoryNotFollowed: "notFollowed"
//      kGTLWebmastersCategoryNotFound: "notFound"
//      kGTLWebmastersCategoryOther: "other"
//      kGTLWebmastersCategoryRoboted: "roboted"
//      kGTLWebmastersCategoryServerError: "serverError"
//      kGTLWebmastersCategorySoft404: "soft404"
//   latestCountsOnly: If true, returns only the latest crawl error counts.
//     (Default true)
//   platform: The user agent type (platform) that made the request. For
//     example: web. If not specified, returns results for all platforms.
//      kGTLWebmastersPlatformMobile: "mobile"
//      kGTLWebmastersPlatformSmartphoneOnly: "smartphoneOnly"
//      kGTLWebmastersPlatformWeb: "web"
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
//   kGTLAuthScopeWebmastersReadonly
// Fetches a GTLWebmastersUrlCrawlErrorsCountsQueryResponse.
+ (instancetype)queryForUrlcrawlerrorscountsQueryWithSiteUrl:(NSString *)siteUrl;

#pragma mark -
#pragma mark "urlcrawlerrorssamples" methods
// These create a GTLQueryWebmasters object.

// Method: webmasters.urlcrawlerrorssamples.get
// Retrieves details about crawl errors for a site's sample URL.
//  Required:
//   siteUrl: The site's URL, including protocol. For example:
//     http://www.example.com/
//   url: The relative path (without the site) of the sample URL. It must be one
//     of the URLs returned by list(). For example, for the URL
//     https://www.example.com/pagename on the site https://www.example.com/,
//     the url value is pagename
//   category: The crawl error category. For example: authPermissions
//      kGTLWebmastersCategoryAuthPermissions: "authPermissions"
//      kGTLWebmastersCategoryManyToOneRedirect: "manyToOneRedirect"
//      kGTLWebmastersCategoryNotFollowed: "notFollowed"
//      kGTLWebmastersCategoryNotFound: "notFound"
//      kGTLWebmastersCategoryOther: "other"
//      kGTLWebmastersCategoryRoboted: "roboted"
//      kGTLWebmastersCategoryServerError: "serverError"
//      kGTLWebmastersCategorySoft404: "soft404"
//   platform: The user agent type (platform) that made the request. For
//     example: web
//      kGTLWebmastersPlatformMobile: "mobile"
//      kGTLWebmastersPlatformSmartphoneOnly: "smartphoneOnly"
//      kGTLWebmastersPlatformWeb: "web"
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
//   kGTLAuthScopeWebmastersReadonly
// Fetches a GTLWebmastersUrlCrawlErrorsSample.
+ (instancetype)queryForUrlcrawlerrorssamplesGetWithSiteUrl:(NSString *)siteUrl
                                                        url:(NSString *)url
                                                   category:(NSString *)category
                                                   platform:(NSString *)platform;

// Method: webmasters.urlcrawlerrorssamples.list
// Lists a site's sample URLs for the specified crawl error category and
// platform.
//  Required:
//   siteUrl: The site's URL, including protocol. For example:
//     http://www.example.com/
//   category: The crawl error category. For example: authPermissions
//      kGTLWebmastersCategoryAuthPermissions: "authPermissions"
//      kGTLWebmastersCategoryManyToOneRedirect: "manyToOneRedirect"
//      kGTLWebmastersCategoryNotFollowed: "notFollowed"
//      kGTLWebmastersCategoryNotFound: "notFound"
//      kGTLWebmastersCategoryOther: "other"
//      kGTLWebmastersCategoryRoboted: "roboted"
//      kGTLWebmastersCategoryServerError: "serverError"
//      kGTLWebmastersCategorySoft404: "soft404"
//   platform: The user agent type (platform) that made the request. For
//     example: web
//      kGTLWebmastersPlatformMobile: "mobile"
//      kGTLWebmastersPlatformSmartphoneOnly: "smartphoneOnly"
//      kGTLWebmastersPlatformWeb: "web"
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
//   kGTLAuthScopeWebmastersReadonly
// Fetches a GTLWebmastersUrlCrawlErrorsSamplesListResponse.
+ (instancetype)queryForUrlcrawlerrorssamplesListWithSiteUrl:(NSString *)siteUrl
                                                    category:(NSString *)category
                                                    platform:(NSString *)platform;

// Method: webmasters.urlcrawlerrorssamples.markAsFixed
// Marks the provided site's sample URL as fixed, and removes it from the
// samples list.
//  Required:
//   siteUrl: The site's URL, including protocol. For example:
//     http://www.example.com/
//   url: The relative path (without the site) of the sample URL. It must be one
//     of the URLs returned by list(). For example, for the URL
//     https://www.example.com/pagename on the site https://www.example.com/,
//     the url value is pagename
//   category: The crawl error category. For example: authPermissions
//      kGTLWebmastersCategoryAuthPermissions: "authPermissions"
//      kGTLWebmastersCategoryManyToOneRedirect: "manyToOneRedirect"
//      kGTLWebmastersCategoryNotFollowed: "notFollowed"
//      kGTLWebmastersCategoryNotFound: "notFound"
//      kGTLWebmastersCategoryOther: "other"
//      kGTLWebmastersCategoryRoboted: "roboted"
//      kGTLWebmastersCategoryServerError: "serverError"
//      kGTLWebmastersCategorySoft404: "soft404"
//   platform: The user agent type (platform) that made the request. For
//     example: web
//      kGTLWebmastersPlatformMobile: "mobile"
//      kGTLWebmastersPlatformSmartphoneOnly: "smartphoneOnly"
//      kGTLWebmastersPlatformWeb: "web"
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
+ (instancetype)queryForUrlcrawlerrorssamplesMarkAsFixedWithSiteUrl:(NSString *)siteUrl
                                                                url:(NSString *)url
                                                           category:(NSString *)category
                                                           platform:(NSString *)platform;

@end

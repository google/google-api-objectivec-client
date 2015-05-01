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
//   https://developers.google.com/webmaster-tools/v3/welcome
// Classes:
//   GTLQueryWebmasters (12 custom class methods, 8 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@interface GTLQueryWebmasters : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, copy) NSString *category;
@property (nonatomic, copy) NSString *feedpath;
@property (nonatomic, assign) BOOL latestCountsOnly;
@property (nonatomic, copy) NSString *platform;
@property (nonatomic, copy) NSString *sitemapIndex;
@property (nonatomic, copy) NSString *siteUrl;
@property (nonatomic, copy) NSString *url;

#pragma mark -
#pragma mark "sitemaps" methods
// These create a GTLQueryWebmasters object.

// Method: webmasters.sitemaps.delete
// Deletes a sitemap from this site.
//  Required:
//   siteUrl: The site's URL, including protocol, for example
//     'http://www.example.com/'
//   feedpath: The URL of the actual sitemap (for example
//     http://www.example.com/sitemap.xml).
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
+ (instancetype)queryForSitemapsDeleteWithSiteUrl:(NSString *)siteUrl
                                         feedpath:(NSString *)feedpath;

// Method: webmasters.sitemaps.get
// Retrieves information about a specific sitemap.
//  Required:
//   siteUrl: The site's URL, including protocol, for example
//     'http://www.example.com/'
//   feedpath: The URL of the actual sitemap (for example
//     http://www.example.com/sitemap.xml).
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
//   kGTLAuthScopeWebmastersReadonly
// Fetches a GTLWebmastersWmxSitemap.
+ (instancetype)queryForSitemapsGetWithSiteUrl:(NSString *)siteUrl
                                      feedpath:(NSString *)feedpath;

// Method: webmasters.sitemaps.list
// Lists sitemaps uploaded to the site.
//  Required:
//   siteUrl: The site's URL, including protocol, for example
//     'http://www.example.com/'
//  Optional:
//   sitemapIndex: A URL of a site's sitemap index.
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
//   kGTLAuthScopeWebmastersReadonly
// Fetches a GTLWebmastersSitemapsListResponse.
+ (instancetype)queryForSitemapsListWithSiteUrl:(NSString *)siteUrl;

// Method: webmasters.sitemaps.submit
// Submits a sitemap for a site.
//  Required:
//   siteUrl: The site's URL, including protocol, for example
//     'http://www.example.com/'
//   feedpath: The URL of the sitemap to add.
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
//   siteUrl: The site's URL, including protocol, for example
//     'http://www.example.com/'
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
+ (instancetype)queryForSitesDeleteWithSiteUrl:(NSString *)siteUrl;

// Method: webmasters.sites.get
// Retrieves information about specific site.
//  Required:
//   siteUrl: The site's URL, including protocol, for example
//     'http://www.example.com/'
//  Authorization scope(s):
//   kGTLAuthScopeWebmasters
//   kGTLAuthScopeWebmastersReadonly
// Fetches a GTLWebmastersWmxSite.
+ (instancetype)queryForSitesGetWithSiteUrl:(NSString *)siteUrl;

// Method: webmasters.sites.list
// Lists your Webmaster Tools sites.
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
//   siteUrl: The site's URL, including protocol, for example
//     'http://www.example.com/'
//  Optional:
//   category: The crawl error category, for example 'serverError'. If not
//     specified, we return results for all categories.
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
//   platform: The user agent type (platform) that made the request, for example
//     'web'. If not specified, we return results for all platforms.
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
//   siteUrl: The site's URL, including protocol, for example
//     'http://www.example.com/'
//   url: The relative path (without the site) of the sample URL; must be one of
//     the URLs returned by list
//   category: The crawl error category, for example 'authPermissions'
//      kGTLWebmastersCategoryAuthPermissions: "authPermissions"
//      kGTLWebmastersCategoryManyToOneRedirect: "manyToOneRedirect"
//      kGTLWebmastersCategoryNotFollowed: "notFollowed"
//      kGTLWebmastersCategoryNotFound: "notFound"
//      kGTLWebmastersCategoryOther: "other"
//      kGTLWebmastersCategoryRoboted: "roboted"
//      kGTLWebmastersCategoryServerError: "serverError"
//      kGTLWebmastersCategorySoft404: "soft404"
//   platform: The user agent type (platform) that made the request, for example
//     'web'
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
//   siteUrl: The site's URL, including protocol, for example
//     'http://www.example.com/'
//   category: The crawl error category, for example 'authPermissions'
//      kGTLWebmastersCategoryAuthPermissions: "authPermissions"
//      kGTLWebmastersCategoryManyToOneRedirect: "manyToOneRedirect"
//      kGTLWebmastersCategoryNotFollowed: "notFollowed"
//      kGTLWebmastersCategoryNotFound: "notFound"
//      kGTLWebmastersCategoryOther: "other"
//      kGTLWebmastersCategoryRoboted: "roboted"
//      kGTLWebmastersCategoryServerError: "serverError"
//      kGTLWebmastersCategorySoft404: "soft404"
//   platform: The user agent type (platform) that made the request, for example
//     'web'
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
//   siteUrl: The site's URL, including protocol, for example
//     'http://www.example.com/'
//   url: The relative path (without the site) of the sample URL; must be one of
//     the URLs returned by list
//   category: The crawl error category, for example 'authPermissions'
//      kGTLWebmastersCategoryAuthPermissions: "authPermissions"
//      kGTLWebmastersCategoryManyToOneRedirect: "manyToOneRedirect"
//      kGTLWebmastersCategoryNotFollowed: "notFollowed"
//      kGTLWebmastersCategoryNotFound: "notFound"
//      kGTLWebmastersCategoryOther: "other"
//      kGTLWebmastersCategoryRoboted: "roboted"
//      kGTLWebmastersCategoryServerError: "serverError"
//      kGTLWebmastersCategorySoft404: "soft404"
//   platform: The user agent type (platform) that made the request, for example
//     'web'
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

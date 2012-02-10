/* Copyright (c) 2012 Google Inc.
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
//  GTLQueryAdsense.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.1)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://code.google.com/apis/adsense/management/
// Classes:
//   GTLQueryAdsense (20 custom class methods, 18 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@interface GTLQueryAdsense : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
// "accountId" has different types for some query methods; see the documentation
// for the right type for each query method.
@property (retain) id accountId;
@property (copy) NSString *adClientId;
@property (copy) NSString *adUnitId;
@property (copy) NSString *currency;
@property (copy) NSString *customChannelId;
@property (retain) NSArray *dimension;  // of NSString
@property (copy) NSString *endDate;
@property (retain) NSArray *filter;  // of NSString
@property (assign) BOOL includeInactive;
@property (copy) NSString *locale;
@property (assign) NSInteger maxResults;
@property (retain) NSArray *metric;  // of NSString
@property (copy) NSString *pageToken;
@property (retain) NSArray *sort;  // of NSString
@property (copy) NSString *startDate;
@property (assign) NSInteger startIndex;
@property (assign) BOOL tree;

#pragma mark -
#pragma mark "accounts.adclients" methods
// These create a GTLQueryAdsense object.

// Method: adsense.accounts.adclients.list
// List all ad clients in the specified account.
//  Required:
//   accountId: Account for which to list ad clients.
//  Optional:
//   maxResults: The maximum number of ad clients to include in the response,
//     used for paging. (0..10000)
//   pageToken: A continuation token, used to page through ad clients. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAdClients.
+ (id)queryForAccountsAdclientsListWithAccountId:(NSString *)accountId;

#pragma mark -
#pragma mark "accounts.adunits.customchannels" methods
// These create a GTLQueryAdsense object.

// Method: adsense.accounts.adunits.customchannels.list
// List all custom channels which the specified ad unit belongs to.
//  Required:
//   accountId: Account to which the ad client belongs.
//   adClientId: Ad client which contains the ad unit.
//   adUnitId: Ad unit for which to list custom channels.
//  Optional:
//   maxResults: The maximum number of custom channels to include in the
//     response, used for paging. (0..10000)
//   pageToken: A continuation token, used to page through custom channels. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseCustomChannels.
+ (id)queryForAccountsAdunitsCustomchannelsListWithAccountId:(NSString *)accountId
                                                  adClientId:(NSString *)adClientId
                                                    adUnitId:(NSString *)adUnitId;

#pragma mark -
#pragma mark "accounts.adunits" methods
// These create a GTLQueryAdsense object.

// Method: adsense.accounts.adunits.get
// Gets the specified ad unit in the specified ad client for the specified
// account.
//  Required:
//   accountId: Account to which the ad client belongs.
//   adClientId: Ad client for which to get the ad unit.
//   adUnitId: Ad unit to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAdUnit.
+ (id)queryForAccountsAdunitsGetWithAccountId:(NSString *)accountId
                                   adClientId:(NSString *)adClientId
                                     adUnitId:(NSString *)adUnitId;

// Method: adsense.accounts.adunits.list
// List all ad units in the specified ad client for the specified account.
//  Required:
//   accountId: Account to which the ad client belongs.
//   adClientId: Ad client for which to list ad units.
//  Optional:
//   includeInactive: Whether to include inactive ad units. Default: true.
//   maxResults: The maximum number of ad units to include in the response, used
//     for paging. (0..10000)
//   pageToken: A continuation token, used to page through ad units. To retrieve
//     the next page, set this parameter to the value of "nextPageToken" from
//     the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAdUnits.
+ (id)queryForAccountsAdunitsListWithAccountId:(NSString *)accountId
                                    adClientId:(NSString *)adClientId;

#pragma mark -
#pragma mark "accounts.customchannels.adunits" methods
// These create a GTLQueryAdsense object.

// Method: adsense.accounts.customchannels.adunits.list
// List all ad units in the specified custom channel.
//  Required:
//   accountId: Account to which the ad client belongs.
//   adClientId: Ad client which contains the custom channel.
//   customChannelId: Custom channel for which to list ad units.
//  Optional:
//   includeInactive: Whether to include inactive ad units. Default: true.
//   maxResults: The maximum number of ad units to include in the response, used
//     for paging. (0..10000)
//   pageToken: A continuation token, used to page through ad units. To retrieve
//     the next page, set this parameter to the value of "nextPageToken" from
//     the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAdUnits.
+ (id)queryForAccountsCustomchannelsAdunitsListWithAccountId:(NSString *)accountId
                                                  adClientId:(NSString *)adClientId
                                             customChannelId:(NSString *)customChannelId;

#pragma mark -
#pragma mark "accounts.customchannels" methods
// These create a GTLQueryAdsense object.

// Method: adsense.accounts.customchannels.get
// Get the specified custom channel from the specified ad client for the
// specified account.
//  Required:
//   accountId: Account to which the ad client belongs.
//   adClientId: Ad client which contains the custom channel.
//   customChannelId: Custom channel to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseCustomChannel.
+ (id)queryForAccountsCustomchannelsGetWithAccountId:(NSString *)accountId
                                          adClientId:(NSString *)adClientId
                                     customChannelId:(NSString *)customChannelId;

// Method: adsense.accounts.customchannels.list
// List all custom channels in the specified ad client for the specified
// account.
//  Required:
//   accountId: Account to which the ad client belongs.
//   adClientId: Ad client for which to list custom channels.
//  Optional:
//   maxResults: The maximum number of custom channels to include in the
//     response, used for paging. (0..10000)
//   pageToken: A continuation token, used to page through custom channels. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseCustomChannels.
+ (id)queryForAccountsCustomchannelsListWithAccountId:(NSString *)accountId
                                           adClientId:(NSString *)adClientId;

#pragma mark -
#pragma mark "accounts" methods
// These create a GTLQueryAdsense object.

// Method: adsense.accounts.get
// Get information about the selected AdSense account.
//  Required:
//   accountId: Account to get information about.
//  Optional:
//   tree: Whether the tree of sub accounts should be returned.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAccount.
+ (id)queryForAccountsGetWithAccountId:(NSString *)accountId;

// Method: adsense.accounts.list
// List all accounts available to this AdSense account.
//  Optional:
//   maxResults: The maximum number of accounts to include in the response, used
//     for paging. (0..10000)
//   pageToken: A continuation token, used to page through accounts. To retrieve
//     the next page, set this parameter to the value of "nextPageToken" from
//     the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAccounts.
+ (id)queryForAccountsList;

#pragma mark -
#pragma mark "accounts.reports" methods
// These create a GTLQueryAdsense object.

// Method: adsense.accounts.reports.generate
// Generate an AdSense report based on the report request sent in the query
// parameters. Returns the result as JSON; to retrieve output in CSV format
// specify "alt=csv" as a query parameter.
//  Required:
//   startDate: Start of the date range to report on in "YYYY-MM-DD" format,
//     inclusive.
//   endDate: End of the date range to report on in "YYYY-MM-DD" format,
//     inclusive.
//  Optional:
//   accountId: Account upon which to report.
//     Note: For this method, "accountId" should be of type NSString.
//   currency: Optional currency to use when reporting on monetary metrics.
//     Defaults to the account's currency if not set.
//   dimension: Dimensions to base the report on.
//   filter: Filters to be run on the report.
//   locale: Optional locale to use for translating report output to a local
//     language. Defaults to "en_US" if not specified.
//   maxResults: The maximum number of rows of report data to return. (0..50000)
//   metric: Numeric columns to include in the report.
//   sort: The name of a dimension or metric to sort the resulting report on,
//     optionally prefixed with "+" to sort ascending or "-" to sort descending.
//     If no prefix is specified, the column is sorted ascending.
//   startIndex: Index of the first row of report data to return. (0..5000)
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAdsenseReportsGenerateResponse.
+ (id)queryForAccountsReportsGenerateWithStartDate:(NSString *)startDate
                                           endDate:(NSString *)endDate;

#pragma mark -
#pragma mark "accounts.urlchannels" methods
// These create a GTLQueryAdsense object.

// Method: adsense.accounts.urlchannels.list
// List all URL channels in the specified ad client for the specified account.
//  Required:
//   accountId: Account to which the ad client belongs.
//   adClientId: Ad client for which to list URL channels.
//  Optional:
//   maxResults: The maximum number of URL channels to include in the response,
//     used for paging. (0..10000)
//   pageToken: A continuation token, used to page through URL channels. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseUrlChannels.
+ (id)queryForAccountsUrlchannelsListWithAccountId:(NSString *)accountId
                                        adClientId:(NSString *)adClientId;

#pragma mark -
#pragma mark "adclients" methods
// These create a GTLQueryAdsense object.

// Method: adsense.adclients.list
// List all ad clients in this AdSense account.
//  Optional:
//   maxResults: The maximum number of ad clients to include in the response,
//     used for paging. (0..10000)
//   pageToken: A continuation token, used to page through ad clients. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAdClients.
+ (id)queryForAdclientsList;

#pragma mark -
#pragma mark "adunits.customchannels" methods
// These create a GTLQueryAdsense object.

// Method: adsense.adunits.customchannels.list
// List all custom channels which the specified ad unit belongs to.
//  Required:
//   adClientId: Ad client which contains the ad unit.
//   adUnitId: Ad unit for which to list custom channels.
//  Optional:
//   maxResults: The maximum number of custom channels to include in the
//     response, used for paging. (0..10000)
//   pageToken: A continuation token, used to page through custom channels. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseCustomChannels.
+ (id)queryForAdunitsCustomchannelsListWithAdClientId:(NSString *)adClientId
                                             adUnitId:(NSString *)adUnitId;

#pragma mark -
#pragma mark "adunits" methods
// These create a GTLQueryAdsense object.

// Method: adsense.adunits.get
// Gets the specified ad unit in the specified ad client.
//  Required:
//   adClientId: Ad client for which to get the ad unit.
//   adUnitId: Ad unit to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAdUnit.
+ (id)queryForAdunitsGetWithAdClientId:(NSString *)adClientId
                              adUnitId:(NSString *)adUnitId;

// Method: adsense.adunits.list
// List all ad units in the specified ad client for this AdSense account.
//  Required:
//   adClientId: Ad client for which to list ad units.
//  Optional:
//   includeInactive: Whether to include inactive ad units. Default: true.
//   maxResults: The maximum number of ad units to include in the response, used
//     for paging. (0..10000)
//   pageToken: A continuation token, used to page through ad units. To retrieve
//     the next page, set this parameter to the value of "nextPageToken" from
//     the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAdUnits.
+ (id)queryForAdunitsListWithAdClientId:(NSString *)adClientId;

#pragma mark -
#pragma mark "customchannels.adunits" methods
// These create a GTLQueryAdsense object.

// Method: adsense.customchannels.adunits.list
// List all ad units in the specified custom channel.
//  Required:
//   adClientId: Ad client which contains the custom channel.
//   customChannelId: Custom channel for which to list ad units.
//  Optional:
//   includeInactive: Whether to include inactive ad units. Default: true.
//   maxResults: The maximum number of ad units to include in the response, used
//     for paging. (0..10000)
//   pageToken: A continuation token, used to page through ad units. To retrieve
//     the next page, set this parameter to the value of "nextPageToken" from
//     the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAdUnits.
+ (id)queryForCustomchannelsAdunitsListWithAdClientId:(NSString *)adClientId
                                      customChannelId:(NSString *)customChannelId;

#pragma mark -
#pragma mark "customchannels" methods
// These create a GTLQueryAdsense object.

// Method: adsense.customchannels.get
// Get the specified custom channel from the specified ad client.
//  Required:
//   adClientId: Ad client which contains the custom channel.
//   customChannelId: Custom channel to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseCustomChannel.
+ (id)queryForCustomchannelsGetWithAdClientId:(NSString *)adClientId
                              customChannelId:(NSString *)customChannelId;

// Method: adsense.customchannels.list
// List all custom channels in the specified ad client for this AdSense account.
//  Required:
//   adClientId: Ad client for which to list custom channels.
//  Optional:
//   maxResults: The maximum number of custom channels to include in the
//     response, used for paging. (0..10000)
//   pageToken: A continuation token, used to page through custom channels. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseCustomChannels.
+ (id)queryForCustomchannelsListWithAdClientId:(NSString *)adClientId;

#pragma mark -
#pragma mark "reports" methods
// These create a GTLQueryAdsense object.

// Method: adsense.reports.generate
// Generate an AdSense report based on the report request sent in the query
// parameters. Returns the result as JSON; to retrieve output in CSV format
// specify "alt=csv" as a query parameter.
//  Required:
//   startDate: Start of the date range to report on in "YYYY-MM-DD" format,
//     inclusive.
//   endDate: End of the date range to report on in "YYYY-MM-DD" format,
//     inclusive.
//  Optional:
//   accountId: Accounts upon which to report.
//     Note: For this method, "accountId" should be of type NSArray.
//   currency: Optional currency to use when reporting on monetary metrics.
//     Defaults to the account's currency if not set.
//   dimension: Dimensions to base the report on.
//   filter: Filters to be run on the report.
//   locale: Optional locale to use for translating report output to a local
//     language. Defaults to "en_US" if not specified.
//   maxResults: The maximum number of rows of report data to return. (0..50000)
//   metric: Numeric columns to include in the report.
//   sort: The name of a dimension or metric to sort the resulting report on,
//     optionally prefixed with "+" to sort ascending or "-" to sort descending.
//     If no prefix is specified, the column is sorted ascending.
//   startIndex: Index of the first row of report data to return. (0..5000)
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseAdsenseReportsGenerateResponse.
+ (id)queryForReportsGenerateWithStartDate:(NSString *)startDate
                                   endDate:(NSString *)endDate;

#pragma mark -
#pragma mark "urlchannels" methods
// These create a GTLQueryAdsense object.

// Method: adsense.urlchannels.list
// List all URL channels in the specified ad client for this AdSense account.
//  Required:
//   adClientId: Ad client for which to list URL channels.
//  Optional:
//   maxResults: The maximum number of URL channels to include in the response,
//     used for paging. (0..10000)
//   pageToken: A continuation token, used to page through URL channels. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdsense
//   kGTLAuthScopeAdsenseReadonly
// Fetches a GTLAdsenseUrlChannels.
+ (id)queryForUrlchannelsListWithAdClientId:(NSString *)adClientId;

@end

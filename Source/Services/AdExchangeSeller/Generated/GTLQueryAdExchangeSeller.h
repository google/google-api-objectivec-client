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
//  GTLQueryAdExchangeSeller.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Seller API (adexchangeseller/v2.0)
// Description:
//   Gives Ad Exchange seller users access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/ad-exchange/seller-rest/
// Classes:
//   GTLQueryAdExchangeSeller (14 custom class methods, 16 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@interface GTLQueryAdExchangeSeller : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *accountId;
@property (copy) NSString *adClientId;
@property (copy) NSString *customChannelId;
@property (copy) NSString *dealId;
@property (retain) NSArray *dimension;  // of NSString
@property (copy) NSString *endDate;
@property (retain) NSArray *filter;  // of NSString
@property (copy) NSString *locale;
// "maxResults" has different types for some query methods; see the
// documentation for the right type for each query method.
@property (retain) id maxResults;
@property (retain) NSArray *metric;  // of NSString
@property (copy) NSString *pageToken;
@property (copy) NSString *savedReportId;
@property (retain) NSArray *sort;  // of NSString
@property (copy) NSString *startDate;
// "startIndex" has different types for some query methods; see the
// documentation for the right type for each query method.
@property (retain) id startIndex;

#pragma mark -
#pragma mark "accounts.adclients" methods
// These create a GTLQueryAdExchangeSeller object.

// Method: adexchangeseller.accounts.adclients.list
// List all ad clients in this Ad Exchange account.
//  Required:
//   accountId: Account to which the ad client belongs.
//  Optional:
//   maxResults: The maximum number of ad clients to include in the response,
//     used for paging. (0..10000)
//     Note: For this method, "maxResults" should be of type NSUInteger.
//   pageToken: A continuation token, used to page through ad clients. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerAdClients.
+ (id)queryForAccountsAdclientsListWithAccountId:(NSString *)accountId;

#pragma mark -
#pragma mark "accounts.alerts" methods
// These create a GTLQueryAdExchangeSeller object.

// Method: adexchangeseller.accounts.alerts.list
// List the alerts for this Ad Exchange account.
//  Required:
//   accountId: Account owning the alerts.
//  Optional:
//   locale: The locale to use for translating alert messages. The account
//     locale will be used if this is not supplied. The AdSense default
//     (English) will be used if the supplied locale is invalid or unsupported.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerAlerts.
+ (id)queryForAccountsAlertsListWithAccountId:(NSString *)accountId;

#pragma mark -
#pragma mark "accounts.customchannels" methods
// These create a GTLQueryAdExchangeSeller object.

// Method: adexchangeseller.accounts.customchannels.get
// Get the specified custom channel from the specified ad client.
//  Required:
//   accountId: Account to which the ad client belongs.
//   adClientId: Ad client which contains the custom channel.
//   customChannelId: Custom channel to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerCustomChannel.
+ (id)queryForAccountsCustomchannelsGetWithAccountId:(NSString *)accountId
                                          adClientId:(NSString *)adClientId
                                     customChannelId:(NSString *)customChannelId;

// Method: adexchangeseller.accounts.customchannels.list
// List all custom channels in the specified ad client for this Ad Exchange
// account.
//  Required:
//   accountId: Account to which the ad client belongs.
//   adClientId: Ad client for which to list custom channels.
//  Optional:
//   maxResults: The maximum number of custom channels to include in the
//     response, used for paging. (0..10000)
//     Note: For this method, "maxResults" should be of type NSUInteger.
//   pageToken: A continuation token, used to page through custom channels. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerCustomChannels.
+ (id)queryForAccountsCustomchannelsListWithAccountId:(NSString *)accountId
                                           adClientId:(NSString *)adClientId;

#pragma mark -
#pragma mark "accounts" methods
// These create a GTLQueryAdExchangeSeller object.

// Method: adexchangeseller.accounts.get
// Get information about the selected Ad Exchange account.
//  Required:
//   accountId: Account to get information about. Tip: 'myaccount' is a valid
//     ID.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerAccount.
+ (id)queryForAccountsGetWithAccountId:(NSString *)accountId;

// Method: adexchangeseller.accounts.list
// List all accounts available to this Ad Exchange account.
//  Optional:
//   maxResults: The maximum number of accounts to include in the response, used
//     for paging. (0..10000)
//     Note: For this method, "maxResults" should be of type NSInteger.
//   pageToken: A continuation token, used to page through accounts. To retrieve
//     the next page, set this parameter to the value of "nextPageToken" from
//     the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerAccounts.
+ (id)queryForAccountsList;

#pragma mark -
#pragma mark "accounts.metadata.dimensions" methods
// These create a GTLQueryAdExchangeSeller object.

// Method: adexchangeseller.accounts.metadata.dimensions.list
// List the metadata for the dimensions available to this AdExchange account.
//  Required:
//   accountId: Account with visibility to the dimensions.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerMetadata.
+ (id)queryForAccountsMetadataDimensionsListWithAccountId:(NSString *)accountId;

#pragma mark -
#pragma mark "accounts.metadata.metrics" methods
// These create a GTLQueryAdExchangeSeller object.

// Method: adexchangeseller.accounts.metadata.metrics.list
// List the metadata for the metrics available to this AdExchange account.
//  Required:
//   accountId: Account with visibility to the metrics.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerMetadata.
+ (id)queryForAccountsMetadataMetricsListWithAccountId:(NSString *)accountId;

#pragma mark -
#pragma mark "accounts.preferreddeals" methods
// These create a GTLQueryAdExchangeSeller object.

// Method: adexchangeseller.accounts.preferreddeals.get
// Get information about the selected Ad Exchange Preferred Deal.
//  Required:
//   accountId: Account owning the deal.
//   dealId: Preferred deal to get information about.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerPreferredDeal.
+ (id)queryForAccountsPreferreddealsGetWithAccountId:(NSString *)accountId
                                              dealId:(NSString *)dealId;

// Method: adexchangeseller.accounts.preferreddeals.list
// List the preferred deals for this Ad Exchange account.
//  Required:
//   accountId: Account owning the deals.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerPreferredDeals.
+ (id)queryForAccountsPreferreddealsListWithAccountId:(NSString *)accountId;

#pragma mark -
#pragma mark "accounts.reports" methods
// These create a GTLQueryAdExchangeSeller object.

// Method: adexchangeseller.accounts.reports.generate
// Generate an Ad Exchange report based on the report request sent in the query
// parameters. Returns the result as JSON; to retrieve output in CSV format
// specify "alt=csv" as a query parameter.
//  Required:
//   accountId: Account which owns the generated report.
//   startDate: Start of the date range to report on in "YYYY-MM-DD" format,
//     inclusive.
//   endDate: End of the date range to report on in "YYYY-MM-DD" format,
//     inclusive.
//  Optional:
//   dimension: Dimensions to base the report on.
//   filter: Filters to be run on the report.
//   locale: Optional locale to use for translating report output to a local
//     language. Defaults to "en_US" if not specified.
//   maxResults: The maximum number of rows of report data to return. (0..50000)
//     Note: For this method, "maxResults" should be of type NSUInteger.
//   metric: Numeric columns to include in the report.
//   sort: The name of a dimension or metric to sort the resulting report on,
//     optionally prefixed with "+" to sort ascending or "-" to sort descending.
//     If no prefix is specified, the column is sorted ascending.
//   startIndex: Index of the first row of report data to return. (0..5000)
//     Note: For this method, "startIndex" should be of type NSUInteger.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerReport.
+ (id)queryForAccountsReportsGenerateWithAccountId:(NSString *)accountId
                                         startDate:(NSString *)startDate
                                           endDate:(NSString *)endDate;

#pragma mark -
#pragma mark "accounts.reports.saved" methods
// These create a GTLQueryAdExchangeSeller object.

// Method: adexchangeseller.accounts.reports.saved.generate
// Generate an Ad Exchange report based on the saved report ID sent in the query
// parameters.
//  Required:
//   accountId: Account owning the saved report.
//   savedReportId: The saved report to retrieve.
//  Optional:
//   locale: Optional locale to use for translating report output to a local
//     language. Defaults to "en_US" if not specified.
//   maxResults: The maximum number of rows of report data to return. (0..50000)
//     Note: For this method, "maxResults" should be of type NSInteger.
//   startIndex: Index of the first row of report data to return. (0..5000)
//     Note: For this method, "startIndex" should be of type NSInteger.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerReport.
+ (id)queryForAccountsReportsSavedGenerateWithAccountId:(NSString *)accountId
                                          savedReportId:(NSString *)savedReportId;

// Method: adexchangeseller.accounts.reports.saved.list
// List all saved reports in this Ad Exchange account.
//  Required:
//   accountId: Account owning the saved reports.
//  Optional:
//   maxResults: The maximum number of saved reports to include in the response,
//     used for paging. (0..100)
//     Note: For this method, "maxResults" should be of type NSInteger.
//   pageToken: A continuation token, used to page through saved reports. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerSavedReports.
+ (id)queryForAccountsReportsSavedListWithAccountId:(NSString *)accountId;

#pragma mark -
#pragma mark "accounts.urlchannels" methods
// These create a GTLQueryAdExchangeSeller object.

// Method: adexchangeseller.accounts.urlchannels.list
// List all URL channels in the specified ad client for this Ad Exchange
// account.
//  Required:
//   accountId: Account to which the ad client belongs.
//   adClientId: Ad client for which to list URL channels.
//  Optional:
//   maxResults: The maximum number of URL channels to include in the response,
//     used for paging. (0..10000)
//     Note: For this method, "maxResults" should be of type NSUInteger.
//   pageToken: A continuation token, used to page through URL channels. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdExchangeSellerAdexchangeSeller
//   kGTLAuthScopeAdExchangeSellerAdexchangeSellerReadonly
// Fetches a GTLAdExchangeSellerUrlChannels.
+ (id)queryForAccountsUrlchannelsListWithAccountId:(NSString *)accountId
                                        adClientId:(NSString *)adClientId;

@end

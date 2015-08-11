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
//  GTLQueryAdSenseHost.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Host API (adsensehost/v4.1)
// Description:
//   Gives AdSense Hosts access to report generation, ad code generation, and
//   publisher management capabilities.
// Documentation:
//   https://developers.google.com/adsense/host/
// Classes:
//   GTLQueryAdSenseHost (26 custom class methods, 24 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLAdSenseHostAdUnit;
@class GTLAdSenseHostCustomChannel;
@class GTLAdSenseHostUrlChannel;

@interface GTLQueryAdSenseHost : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, copy) NSString *accountId;
@property (nonatomic, copy) NSString *adClientId;
@property (nonatomic, copy) NSString *adUnitId;
@property (nonatomic, copy) NSString *customChannelId;
@property (nonatomic, retain) NSArray *dimension;  // of NSString
@property (nonatomic, copy) NSString *endDate;
@property (nonatomic, retain) NSArray *filter;  // of NSString
@property (nonatomic, retain) NSArray *filterAdClientId;  // of NSString
@property (nonatomic, retain) NSArray *hostCustomChannelId;  // of NSString
@property (nonatomic, assign) BOOL includeInactive;
@property (nonatomic, copy) NSString *locale;
@property (nonatomic, assign) NSUInteger maxResults;
@property (nonatomic, retain) NSArray *metric;  // of NSString
@property (nonatomic, copy) NSString *pageToken;
@property (nonatomic, retain) NSArray *productCode;  // of NSString
@property (nonatomic, retain) NSArray *sort;  // of NSString
@property (nonatomic, copy) NSString *startDate;
@property (nonatomic, assign) NSUInteger startIndex;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *urlChannelId;
@property (nonatomic, copy) NSString *userLocale;
@property (nonatomic, copy) NSString *websiteLocale;
@property (nonatomic, copy) NSString *websiteUrl;

#pragma mark - "accounts.adclients" methods
// These create a GTLQueryAdSenseHost object.

// Method: adsensehost.accounts.adclients.get
// Get information about one of the ad clients in the specified publisher's
// AdSense account.
//  Required:
//   accountId: Account which contains the ad client.
//   adClientId: Ad client to get.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAdClient.
+ (instancetype)queryForAccountsAdclientsGetWithAccountId:(NSString *)accountId
                                               adClientId:(NSString *)adClientId;

// Method: adsensehost.accounts.adclients.list
// List all hosted ad clients in the specified hosted account.
//  Required:
//   accountId: Account for which to list ad clients.
//  Optional:
//   maxResults: The maximum number of ad clients to include in the response,
//     used for paging. (0..10000)
//   pageToken: A continuation token, used to page through ad clients. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAdClients.
+ (instancetype)queryForAccountsAdclientsListWithAccountId:(NSString *)accountId;

#pragma mark - "accounts.adunits" methods
// These create a GTLQueryAdSenseHost object.

// Method: adsensehost.accounts.adunits.delete
// Delete the specified ad unit from the specified publisher AdSense account.
//  Required:
//   accountId: Account which contains the ad unit.
//   adClientId: Ad client for which to get ad unit.
//   adUnitId: Ad unit to delete.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAdUnit.
+ (instancetype)queryForAccountsAdunitsDeleteWithAccountId:(NSString *)accountId
                                                adClientId:(NSString *)adClientId
                                                  adUnitId:(NSString *)adUnitId;

// Method: adsensehost.accounts.adunits.get
// Get the specified host ad unit in this AdSense account.
//  Required:
//   accountId: Account which contains the ad unit.
//   adClientId: Ad client for which to get ad unit.
//   adUnitId: Ad unit to get.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAdUnit.
+ (instancetype)queryForAccountsAdunitsGetWithAccountId:(NSString *)accountId
                                             adClientId:(NSString *)adClientId
                                               adUnitId:(NSString *)adUnitId;

// Method: adsensehost.accounts.adunits.getAdCode
// Get ad code for the specified ad unit, attaching the specified host custom
// channels.
//  Required:
//   accountId: Account which contains the ad client.
//   adClientId: Ad client with contains the ad unit.
//   adUnitId: Ad unit to get the code for.
//  Optional:
//   hostCustomChannelId: Host custom channel to attach to the ad code.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAdCode.
+ (instancetype)queryForAccountsAdunitsGetAdCodeWithAccountId:(NSString *)accountId
                                                   adClientId:(NSString *)adClientId
                                                     adUnitId:(NSString *)adUnitId;

// Method: adsensehost.accounts.adunits.insert
// Insert the supplied ad unit into the specified publisher AdSense account.
//  Required:
//   accountId: Account which will contain the ad unit.
//   adClientId: Ad client into which to insert the ad unit.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAdUnit.
+ (instancetype)queryForAccountsAdunitsInsertWithObject:(GTLAdSenseHostAdUnit *)object
                                              accountId:(NSString *)accountId
                                             adClientId:(NSString *)adClientId;

// Method: adsensehost.accounts.adunits.list
// List all ad units in the specified publisher's AdSense account.
//  Required:
//   accountId: Account which contains the ad client.
//   adClientId: Ad client for which to list ad units.
//  Optional:
//   includeInactive: Whether to include inactive ad units. Default: true.
//   maxResults: The maximum number of ad units to include in the response, used
//     for paging. (0..10000)
//   pageToken: A continuation token, used to page through ad units. To retrieve
//     the next page, set this parameter to the value of "nextPageToken" from
//     the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAdUnits.
+ (instancetype)queryForAccountsAdunitsListWithAccountId:(NSString *)accountId
                                              adClientId:(NSString *)adClientId;

// Method: adsensehost.accounts.adunits.patch
// Update the supplied ad unit in the specified publisher AdSense account. This
// method supports patch semantics.
//  Required:
//   accountId: Account which contains the ad client.
//   adClientId: Ad client which contains the ad unit.
//   adUnitId: Ad unit to get.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAdUnit.
+ (instancetype)queryForAccountsAdunitsPatchWithObject:(GTLAdSenseHostAdUnit *)object
                                             accountId:(NSString *)accountId
                                            adClientId:(NSString *)adClientId
                                              adUnitId:(NSString *)adUnitId;

// Method: adsensehost.accounts.adunits.update
// Update the supplied ad unit in the specified publisher AdSense account.
//  Required:
//   accountId: Account which contains the ad client.
//   adClientId: Ad client which contains the ad unit.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAdUnit.
+ (instancetype)queryForAccountsAdunitsUpdateWithObject:(GTLAdSenseHostAdUnit *)object
                                              accountId:(NSString *)accountId
                                             adClientId:(NSString *)adClientId;

#pragma mark - "accounts" methods
// These create a GTLQueryAdSenseHost object.

// Method: adsensehost.accounts.get
// Get information about the selected associated AdSense account.
//  Required:
//   accountId: Account to get information about.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAccount.
+ (instancetype)queryForAccountsGetWithAccountId:(NSString *)accountId;

// Method: adsensehost.accounts.list
// List hosted accounts associated with this AdSense account by ad client id.
//  Required:
//   filterAdClientId: Ad clients to list accounts for.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAccounts.
+ (instancetype)queryForAccountsListWithFilterAdClientId:(NSArray *)filterAdClientId;

#pragma mark - "accounts.reports" methods
// These create a GTLQueryAdSenseHost object.

// Method: adsensehost.accounts.reports.generate
// Generate an AdSense report based on the report request sent in the query
// parameters. Returns the result as JSON; to retrieve output in CSV format
// specify "alt=csv" as a query parameter.
//  Required:
//   accountId: Hosted account upon which to report.
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
//   metric: Numeric columns to include in the report.
//   sort: The name of a dimension or metric to sort the resulting report on,
//     optionally prefixed with "+" to sort ascending or "-" to sort descending.
//     If no prefix is specified, the column is sorted ascending.
//   startIndex: Index of the first row of report data to return. (0..5000)
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostReport.
+ (instancetype)queryForAccountsReportsGenerateWithAccountId:(NSString *)accountId
                                                   startDate:(NSString *)startDate
                                                     endDate:(NSString *)endDate;

#pragma mark - "adclients" methods
// These create a GTLQueryAdSenseHost object.

// Method: adsensehost.adclients.get
// Get information about one of the ad clients in the Host AdSense account.
//  Required:
//   adClientId: Ad client to get.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAdClient.
+ (instancetype)queryForAdclientsGetWithAdClientId:(NSString *)adClientId;

// Method: adsensehost.adclients.list
// List all host ad clients in this AdSense account.
//  Optional:
//   maxResults: The maximum number of ad clients to include in the response,
//     used for paging. (0..10000)
//   pageToken: A continuation token, used to page through ad clients. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAdClients.
+ (instancetype)queryForAdclientsList;

#pragma mark - "associationsessions" methods
// These create a GTLQueryAdSenseHost object.

// Method: adsensehost.associationsessions.start
// Create an association session for initiating an association with an AdSense
// user.
//  Required:
//   productCode: Products to associate with the user.
//      kGTLAdSenseHostProductCodeAfc: AdSense For Content
//      kGTLAdSenseHostProductCodeAfg: AdSense For Games
//      kGTLAdSenseHostProductCodeAfmc: AdSense For Mobile Content
//      kGTLAdSenseHostProductCodeAfs: AdSense For Search
//      kGTLAdSenseHostProductCodeAfv: AdSense For Video
//   websiteUrl: The URL of the user's hosted website.
//  Optional:
//   userLocale: The preferred locale of the user.
//   websiteLocale: The locale of the user's hosted website.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAssociationSession.
+ (instancetype)queryForAssociationsessionsStartWithProductCode:(NSArray *)productCode
                                                     websiteUrl:(NSString *)websiteUrl;

// Method: adsensehost.associationsessions.verify
// Verify an association session after the association callback returns from
// AdSense signup.
//  Required:
//   token: The token returned to the association callback URL.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostAssociationSession.
+ (instancetype)queryForAssociationsessionsVerifyWithToken:(NSString *)token;

#pragma mark - "customchannels" methods
// These create a GTLQueryAdSenseHost object.

// Method: adsensehost.customchannels.delete
// Delete a specific custom channel from the host AdSense account.
//  Required:
//   adClientId: Ad client from which to delete the custom channel.
//   customChannelId: Custom channel to delete.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostCustomChannel.
+ (instancetype)queryForCustomchannelsDeleteWithAdClientId:(NSString *)adClientId
                                           customChannelId:(NSString *)customChannelId;

// Method: adsensehost.customchannels.get
// Get a specific custom channel from the host AdSense account.
//  Required:
//   adClientId: Ad client from which to get the custom channel.
//   customChannelId: Custom channel to get.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostCustomChannel.
+ (instancetype)queryForCustomchannelsGetWithAdClientId:(NSString *)adClientId
                                        customChannelId:(NSString *)customChannelId;

// Method: adsensehost.customchannels.insert
// Add a new custom channel to the host AdSense account.
//  Required:
//   adClientId: Ad client to which the new custom channel will be added.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostCustomChannel.
+ (instancetype)queryForCustomchannelsInsertWithObject:(GTLAdSenseHostCustomChannel *)object
                                            adClientId:(NSString *)adClientId;

// Method: adsensehost.customchannels.list
// List all host custom channels in this AdSense account.
//  Required:
//   adClientId: Ad client for which to list custom channels.
//  Optional:
//   maxResults: The maximum number of custom channels to include in the
//     response, used for paging. (0..10000)
//   pageToken: A continuation token, used to page through custom channels. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostCustomChannels.
+ (instancetype)queryForCustomchannelsListWithAdClientId:(NSString *)adClientId;

// Method: adsensehost.customchannels.patch
// Update a custom channel in the host AdSense account. This method supports
// patch semantics.
//  Required:
//   adClientId: Ad client in which the custom channel will be updated.
//   customChannelId: Custom channel to get.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostCustomChannel.
+ (instancetype)queryForCustomchannelsPatchWithObject:(GTLAdSenseHostCustomChannel *)object
                                           adClientId:(NSString *)adClientId
                                      customChannelId:(NSString *)customChannelId;

// Method: adsensehost.customchannels.update
// Update a custom channel in the host AdSense account.
//  Required:
//   adClientId: Ad client in which the custom channel will be updated.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostCustomChannel.
+ (instancetype)queryForCustomchannelsUpdateWithObject:(GTLAdSenseHostCustomChannel *)object
                                            adClientId:(NSString *)adClientId;

#pragma mark - "reports" methods
// These create a GTLQueryAdSenseHost object.

// Method: adsensehost.reports.generate
// Generate an AdSense report based on the report request sent in the query
// parameters. Returns the result as JSON; to retrieve output in CSV format
// specify "alt=csv" as a query parameter.
//  Required:
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
//   metric: Numeric columns to include in the report.
//   sort: The name of a dimension or metric to sort the resulting report on,
//     optionally prefixed with "+" to sort ascending or "-" to sort descending.
//     If no prefix is specified, the column is sorted ascending.
//   startIndex: Index of the first row of report data to return. (0..5000)
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostReport.
+ (instancetype)queryForReportsGenerateWithStartDate:(NSString *)startDate
                                             endDate:(NSString *)endDate;

#pragma mark - "urlchannels" methods
// These create a GTLQueryAdSenseHost object.

// Method: adsensehost.urlchannels.delete
// Delete a URL channel from the host AdSense account.
//  Required:
//   adClientId: Ad client from which to delete the URL channel.
//   urlChannelId: URL channel to delete.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostUrlChannel.
+ (instancetype)queryForUrlchannelsDeleteWithAdClientId:(NSString *)adClientId
                                           urlChannelId:(NSString *)urlChannelId;

// Method: adsensehost.urlchannels.insert
// Add a new URL channel to the host AdSense account.
//  Required:
//   adClientId: Ad client to which the new URL channel will be added.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostUrlChannel.
+ (instancetype)queryForUrlchannelsInsertWithObject:(GTLAdSenseHostUrlChannel *)object
                                         adClientId:(NSString *)adClientId;

// Method: adsensehost.urlchannels.list
// List all host URL channels in the host AdSense account.
//  Required:
//   adClientId: Ad client for which to list URL channels.
//  Optional:
//   maxResults: The maximum number of URL channels to include in the response,
//     used for paging. (0..10000)
//   pageToken: A continuation token, used to page through URL channels. To
//     retrieve the next page, set this parameter to the value of
//     "nextPageToken" from the previous response.
//  Authorization scope(s):
//   kGTLAuthScopeAdSenseHost
// Fetches a GTLAdSenseHostUrlChannels.
+ (instancetype)queryForUrlchannelsListWithAdClientId:(NSString *)adClientId;

@end

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
//  GTLAdExchangeBuyer.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Ad Exchange Buyer API (adexchangebuyer/v1.4)
// Description:
//   Accesses your bidding-account information, submits creatives for
//   validation, finds available direct deals, and retrieves performance
//   reports.
// Documentation:
//   https://developers.google.com/ad-exchange/buyer-rest

#import "GTLAdExchangeBuyerConstants.h"

#import "GTLAdExchangeBuyerAccount.h"
#import "GTLAdExchangeBuyerAccountsList.h"
#import "GTLAdExchangeBuyerAddOrderDealsResponse.h"
#import "GTLAdExchangeBuyerAddOrderNotesResponse.h"
#import "GTLAdExchangeBuyerAdSize.h"
#import "GTLAdExchangeBuyerAdSlotDto.h"
#import "GTLAdExchangeBuyerAdvertiserDto.h"
#import "GTLAdExchangeBuyerAudienceSegment.h"
#import "GTLAdExchangeBuyerBillingInfo.h"
#import "GTLAdExchangeBuyerBillingInfoList.h"
#import "GTLAdExchangeBuyerBrandDto.h"
#import "GTLAdExchangeBuyerBudget.h"
#import "GTLAdExchangeBuyerBuyer.h"
#import "GTLAdExchangeBuyerBuyerDto.h"
#import "GTLAdExchangeBuyerClientAccessCapabilities.h"
#import "GTLAdExchangeBuyerContactInformation.h"
#import "GTLAdExchangeBuyerCreateOrdersResponse.h"
#import "GTLAdExchangeBuyerCreative.h"
#import "GTLAdExchangeBuyerCreativesList.h"
#import "GTLAdExchangeBuyerDateTime.h"
#import "GTLAdExchangeBuyerDealPartyDto.h"
#import "GTLAdExchangeBuyerDealTerms.h"
#import "GTLAdExchangeBuyerDealTermsGuaranteedFixedPriceTerms.h"
#import "GTLAdExchangeBuyerDealTermsNonGuaranteedAuctionTerms.h"
#import "GTLAdExchangeBuyerDealTermsNonGuaranteedFixedPriceTerms.h"
#import "GTLAdExchangeBuyerDeleteOrderDealsResponse.h"
#import "GTLAdExchangeBuyerDeliveryControl.h"
#import "GTLAdExchangeBuyerDeliveryControlFrequencyCap.h"
#import "GTLAdExchangeBuyerEditAllOrderDealsResponse.h"
#import "GTLAdExchangeBuyerEditHistoryDto.h"
#import "GTLAdExchangeBuyerGetNegotiationsResponse.h"
#import "GTLAdExchangeBuyerGetOffersResponse.h"
#import "GTLAdExchangeBuyerGetOrderDealsResponse.h"
#import "GTLAdExchangeBuyerGetOrderNotesResponse.h"
#import "GTLAdExchangeBuyerGetOrdersResponse.h"
#import "GTLAdExchangeBuyerInventorySegmentTargeting.h"
#import "GTLAdExchangeBuyerListClientAccessCapabilitiesResponse.h"
#import "GTLAdExchangeBuyerListOffersResponse.h"
#import "GTLAdExchangeBuyerMarketplaceDeal.h"
#import "GTLAdExchangeBuyerMarketplaceDealParty.h"
#import "GTLAdExchangeBuyerMarketplaceLabel.h"
#import "GTLAdExchangeBuyerMarketplaceNote.h"
#import "GTLAdExchangeBuyerMarketplaceOffer.h"
#import "GTLAdExchangeBuyerMarketplaceOrder.h"
#import "GTLAdExchangeBuyerMoneyDto.h"
#import "GTLAdExchangeBuyerNegotiationDto.h"
#import "GTLAdExchangeBuyerNegotiationRoundDto.h"
#import "GTLAdExchangeBuyerOfferDto.h"
#import "GTLAdExchangeBuyerPerformanceReport.h"
#import "GTLAdExchangeBuyerPerformanceReportList.h"
#import "GTLAdExchangeBuyerPretargetingConfig.h"
#import "GTLAdExchangeBuyerPretargetingConfigList.h"
#import "GTLAdExchangeBuyerPrice.h"
#import "GTLAdExchangeBuyerPricePerBuyer.h"
#import "GTLAdExchangeBuyerPrivateData.h"
#import "GTLAdExchangeBuyerRuleKeyValuePair.h"
#import "GTLAdExchangeBuyerSeller.h"
#import "GTLAdExchangeBuyerSharedTargeting.h"
#import "GTLAdExchangeBuyerStatsDto.h"
#import "GTLAdExchangeBuyerTargetingValue.h"
#import "GTLAdExchangeBuyerTargetingValueCreativeSize.h"
#import "GTLAdExchangeBuyerTargetingValueDayPartTargeting.h"
#import "GTLAdExchangeBuyerTargetingValueDayPartTargetingDayPart.h"
#import "GTLAdExchangeBuyerTargetingValueSize.h"
#import "GTLAdExchangeBuyerTermsDto.h"
#import "GTLAdExchangeBuyerWebPropertyDto.h"

#import "GTLQueryAdExchangeBuyer.h"
#import "GTLServiceAdExchangeBuyer.h"

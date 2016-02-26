/* Copyright (c) 2016 Google Inc.
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
//  GTLAdExchangeBuyerMarketplaceDeal.m
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
// Classes:
//   GTLAdExchangeBuyerMarketplaceDeal (0 custom class methods, 23 custom properties)

#import "GTLAdExchangeBuyerMarketplaceDeal.h"

#import "GTLAdExchangeBuyerContactInformation.h"
#import "GTLAdExchangeBuyerDealServingMetadata.h"
#import "GTLAdExchangeBuyerDealTerms.h"
#import "GTLAdExchangeBuyerDeliveryControl.h"
#import "GTLAdExchangeBuyerPrivateData.h"
#import "GTLAdExchangeBuyerSharedTargeting.h"

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerMarketplaceDeal
//

@implementation GTLAdExchangeBuyerMarketplaceDeal
@dynamic buyerPrivateData, creationTimeMs, creativePreApprovalPolicy,
         creativeSafeFrameCompatibility, dealId, dealServingMetadata,
         deliveryControl, externalDealId, flightEndTimeMs, flightStartTimeMs,
         inventoryDescription, kind, lastUpdateTimeMs, name, productId,
         productRevisionNumber, programmaticCreativeSource, proposalId,
         sellerContacts, sharedTargetings, syndicationProduct, terms,
         webPropertyCode;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"sellerContacts" : [GTLAdExchangeBuyerContactInformation class],
    @"sharedTargetings" : [GTLAdExchangeBuyerSharedTargeting class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"adexchangebuyer#marketplaceDeal"];
}

@end

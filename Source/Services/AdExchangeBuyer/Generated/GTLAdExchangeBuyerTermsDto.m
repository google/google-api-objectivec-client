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
//  GTLAdExchangeBuyerTermsDto.m
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
//   GTLAdExchangeBuyerTermsDto (0 custom class methods, 27 custom properties)

#import "GTLAdExchangeBuyerTermsDto.h"

#import "GTLAdExchangeBuyerAdSlotDto.h"
#import "GTLAdExchangeBuyerAdvertiserDto.h"
#import "GTLAdExchangeBuyerAudienceSegment.h"
#import "GTLAdExchangeBuyerDateTime.h"
#import "GTLAdExchangeBuyerInventorySegmentTargeting.h"
#import "GTLAdExchangeBuyerMoneyDto.h"

// ----------------------------------------------------------------------------
//
//   GTLAdExchangeBuyerTermsDto
//

@implementation GTLAdExchangeBuyerTermsDto
@dynamic adSlots, advertisers, audienceSegment, audienceSegmentDescription,
         billingTerms, buyerBillingType, cpm, creativeBlockingLevel,
         creativeReviewPolicy, dealPremium, descriptionProperty,
         descriptiveName, endDate, estimatedImpressionsPerDay, estimatedSpend,
         finalizeAutomatically, inventorySegmentTargeting, isReservation,
         minimumSpendMicros, minimumTrueLooks, monetizerType, semiTransparent,
         startDate, targetByDealId, targetingAllAdSlots, termsAttributes, urls;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"descriptionProperty" : @"description"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"adSlots" : [GTLAdExchangeBuyerAdSlotDto class],
    @"advertisers" : [GTLAdExchangeBuyerAdvertiserDto class],
    @"termsAttributes" : [NSString class],
    @"urls" : [NSString class]
  };
  return map;
}

@end

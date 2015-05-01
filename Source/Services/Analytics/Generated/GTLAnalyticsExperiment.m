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
//  GTLAnalyticsExperiment.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   https://developers.google.com/analytics/
// Classes:
//   GTLAnalyticsExperiment (0 custom class methods, 28 custom properties)
//   GTLAnalyticsExperimentParentLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsExperimentVariationsItem (0 custom class methods, 5 custom properties)

#import "GTLAnalyticsExperiment.h"

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsExperiment
//

@implementation GTLAnalyticsExperiment
@dynamic accountId, created, descriptionProperty, editableInGaUi, endTime,
         equalWeighting, identifier, internalWebPropertyId, kind,
         minimumExperimentLengthInDays, name, objectiveMetric, optimizationType,
         parentLink, profileId, reasonExperimentEnded,
         rewriteVariationUrlsAsOriginal, selfLink, servingFramework, snippet,
         startTime, status, trafficCoverage, updated, variations, webPropertyId,
         winnerConfidenceLevel, winnerFound;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"descriptionProperty" : @"description",
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"variations" : [GTLAnalyticsExperimentVariationsItem class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"analytics#experiment"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsExperimentParentLink
//

@implementation GTLAnalyticsExperimentParentLink
@dynamic href, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsExperimentVariationsItem
//

@implementation GTLAnalyticsExperimentVariationsItem
@dynamic name, status, url, weight, won;
@end

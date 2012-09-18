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
//  GTLAnalyticsGoal.m
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
//   GTLAnalyticsGoal (0 custom class methods, 18 custom properties)
//   GTLAnalyticsGoalEventDetails (0 custom class methods, 2 custom properties)
//   GTLAnalyticsGoalParentLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsGoalUrlDestinationDetails (0 custom class methods, 5 custom properties)
//   GTLAnalyticsGoalVisitNumPagesDetails (0 custom class methods, 2 custom properties)
//   GTLAnalyticsGoalVisitTimeOnSiteDetails (0 custom class methods, 2 custom properties)
//   GTLAnalyticsGoalEventDetailsEventConditionsItem (0 custom class methods, 5 custom properties)
//   GTLAnalyticsGoalUrlDestinationDetailsStepsItem (0 custom class methods, 3 custom properties)

#import "GTLAnalyticsGoal.h"

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoal
//

@implementation GTLAnalyticsGoal
@dynamic accountId, active, created, eventDetails, identifier,
         internalWebPropertyId, kind, name, parentLink, profileId, selfLink,
         type, updated, urlDestinationDetails, value, visitNumPagesDetails,
         visitTimeOnSiteDetails, webPropertyId;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"analytics#goal"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalEventDetails
//

@implementation GTLAnalyticsGoalEventDetails
@dynamic eventConditions, useEventValue;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLAnalyticsGoalEventDetailsEventConditionsItem class]
                                forKey:@"eventConditions"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalParentLink
//

@implementation GTLAnalyticsGoalParentLink
@dynamic href, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalUrlDestinationDetails
//

@implementation GTLAnalyticsGoalUrlDestinationDetails
@dynamic caseSensitive, firstStepRequired, matchType, steps, url;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLAnalyticsGoalUrlDestinationDetailsStepsItem class]
                                forKey:@"steps"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalVisitNumPagesDetails
//

@implementation GTLAnalyticsGoalVisitNumPagesDetails
@dynamic comparisonType, comparisonValue;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalVisitTimeOnSiteDetails
//

@implementation GTLAnalyticsGoalVisitTimeOnSiteDetails
@dynamic comparisonType, comparisonValue;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalEventDetailsEventConditionsItem
//

@implementation GTLAnalyticsGoalEventDetailsEventConditionsItem
@dynamic comparisonType, comparisonValue, expression, matchType, type;
@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalUrlDestinationDetailsStepsItem
//

@implementation GTLAnalyticsGoalUrlDestinationDetailsStepsItem
@dynamic name, number, url;
@end

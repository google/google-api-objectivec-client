/* Copyright (c) 2011 Google Inc.
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
//  GTLAnalyticsGoal.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Google Analytics API (analytics/v3)
// Description:
//   View and manage your Google Analytics data
// Documentation:
//   http://code.google.com/apis/analytics
// Classes:
//   GTLAnalyticsGoal (0 custom class methods, 18 custom properties)
//   GTLAnalyticsGoalEventDetails (0 custom class methods, 2 custom properties)
//   GTLAnalyticsGoalParentLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsGoalUrlDestinationDetails (0 custom class methods, 5 custom properties)
//   GTLAnalyticsGoalVisitNumPagesDetails (0 custom class methods, 2 custom properties)
//   GTLAnalyticsGoalVisitTimeOnSiteDetails (0 custom class methods, 2 custom properties)
//   GTLAnalyticsGoalEventDetailsEventConditionsItem (0 custom class methods, 5 custom properties)
//   GTLAnalyticsGoalUrlDestinationDetailsStepsItem (0 custom class methods, 3 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsGoalEventDetails;
@class GTLAnalyticsGoalEventDetailsEventConditionsItem;
@class GTLAnalyticsGoalParentLink;
@class GTLAnalyticsGoalUrlDestinationDetails;
@class GTLAnalyticsGoalUrlDestinationDetailsStepsItem;
@class GTLAnalyticsGoalVisitNumPagesDetails;
@class GTLAnalyticsGoalVisitTimeOnSiteDetails;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoal
//

@interface GTLAnalyticsGoal : GTLObject

// Account ID to which this goal belongs.
@property (retain) NSString *accountId;

// Determines whether this goal is active.
@property (retain) NSNumber *active;  // boolValue

// Time this goal was created.
@property (retain) GTLDateTime *created;

// Details for the goal of the type EVENT.
@property (retain) GTLAnalyticsGoalEventDetails *eventDetails;

// Goal ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (retain) NSString *identifier;

// Internal ID for the web property to which this goal belongs.
@property (retain) NSString *internalWebPropertyId;

// Resource type for an Analytics goal.
@property (retain) NSString *kind;

// Goal name.
@property (retain) NSString *name;

// Parent link for a goal. Points to the profile to which this goal belongs.
@property (retain) GTLAnalyticsGoalParentLink *parentLink;

// Profile ID to which this goal belongs.
@property (retain) NSString *profileId;

// Link for this goal.
@property (retain) NSString *selfLink;

// Goal type. Possible values are URL_DESTINATION, VISIT_TIME_ON_SITE,
// VISIT_NUM_PAGES, AND EVENT.
@property (retain) NSString *type;

// Time this goal was last modified.
@property (retain) GTLDateTime *updated;

// Details for the goal of the type URL_DESTINATION.
@property (retain) GTLAnalyticsGoalUrlDestinationDetails *urlDestinationDetails;

// Goal value.
@property (retain) NSNumber *value;  // floatValue

// Details for the goal of the type VISIT_NUM_PAGES.
@property (retain) GTLAnalyticsGoalVisitNumPagesDetails *visitNumPagesDetails;

// Details for the goal of the type VISIT_TIME_ON_SITE.
@property (retain) GTLAnalyticsGoalVisitTimeOnSiteDetails *visitTimeOnSiteDetails;

// Web property ID to which this goal belongs. The web property ID is of the
// form UA-XXXXX-YY.
@property (retain) NSString *webPropertyId;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalEventDetails
//

@interface GTLAnalyticsGoalEventDetails : GTLObject

// List of event conditions.
@property (retain) NSArray *eventConditions;  // of GTLAnalyticsGoalEventDetailsEventConditionsItem

// Determines if the event value should be used as the value for this goal.
@property (retain) NSNumber *useEventValue;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalParentLink
//

@interface GTLAnalyticsGoalParentLink : GTLObject

// Link to the profile to which this goal belongs.
@property (retain) NSString *href;

// Value is "analytics#profile".
@property (retain) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalUrlDestinationDetails
//

@interface GTLAnalyticsGoalUrlDestinationDetails : GTLObject

// Determines if the goal URL must exactly match the capitalization of visited
// URLs.
@property (retain) NSNumber *caseSensitive;  // boolValue

// Determines if the first step in this goal is required.
@property (retain) NSNumber *firstStepRequired;  // boolValue

// Match type for the goal URL. Possible values are HEAD, EXACT, or REGEX.
@property (retain) NSString *matchType;

// List of steps configured for this goal funnel.
@property (retain) NSArray *steps;  // of GTLAnalyticsGoalUrlDestinationDetailsStepsItem

// URL for this goal.
@property (retain) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalVisitNumPagesDetails
//

@interface GTLAnalyticsGoalVisitNumPagesDetails : GTLObject

// Type of comparison. Possible values are LESS_THAN, GREATER_THAN, or EQUAL.
@property (retain) NSString *comparisonType;

// Value used for this comparison.
@property (retain) NSNumber *comparisonValue;  // longLongValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalVisitTimeOnSiteDetails
//

@interface GTLAnalyticsGoalVisitTimeOnSiteDetails : GTLObject

// Type of comparison. Possible values are LESS_THAN or GREATER_THAN.
@property (retain) NSString *comparisonType;

// Value used for this comparison.
@property (retain) NSNumber *comparisonValue;  // longLongValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalEventDetailsEventConditionsItem
//

@interface GTLAnalyticsGoalEventDetailsEventConditionsItem : GTLObject

// Type of comparison. Possible values are LESS_THAN, GREATER_THAN or EQUAL.
@property (retain) NSString *comparisonType;

// Value used for this comparison.
@property (retain) NSNumber *comparisonValue;  // longLongValue

// Expression used for this match.
@property (retain) NSString *expression;

// Type of the match to be performed. Possible values are REGEXP, BEGINS_WITH,
// or EXACT.
@property (retain) NSString *matchType;

// Type of this event condition. Possible values are CATEGORY, ACTION, LABEL, or
// VALUE.
@property (retain) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalUrlDestinationDetailsStepsItem
//

@interface GTLAnalyticsGoalUrlDestinationDetailsStepsItem : GTLObject

// Step name.
@property (retain) NSString *name;

// Step number.
@property (retain) NSNumber *number;  // intValue

// URL for this step.
@property (retain) NSString *url;

@end

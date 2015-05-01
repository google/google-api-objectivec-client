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
//  GTLAnalyticsGoal.h
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

// JSON template for Analytics goal resource.

@interface GTLAnalyticsGoal : GTLObject

// Account ID to which this goal belongs.
@property (nonatomic, copy) NSString *accountId;

// Determines whether this goal is active.
@property (nonatomic, retain) NSNumber *active;  // boolValue

// Time this goal was created.
@property (nonatomic, retain) GTLDateTime *created;

// Details for the goal of the type EVENT.
@property (nonatomic, retain) GTLAnalyticsGoalEventDetails *eventDetails;

// Goal ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Internal ID for the web property to which this goal belongs.
@property (nonatomic, copy) NSString *internalWebPropertyId;

// Resource type for an Analytics goal.
@property (nonatomic, copy) NSString *kind;

// Goal name.
@property (nonatomic, copy) NSString *name;

// Parent link for a goal. Points to the view (profile) to which this goal
// belongs.
@property (nonatomic, retain) GTLAnalyticsGoalParentLink *parentLink;

// View (Profile) ID to which this goal belongs.
@property (nonatomic, copy) NSString *profileId;

// Link for this goal.
@property (nonatomic, copy) NSString *selfLink;

// Goal type. Possible values are URL_DESTINATION, VISIT_TIME_ON_SITE,
// VISIT_NUM_PAGES, AND EVENT.
@property (nonatomic, copy) NSString *type;

// Time this goal was last modified.
@property (nonatomic, retain) GTLDateTime *updated;

// Details for the goal of the type URL_DESTINATION.
@property (nonatomic, retain) GTLAnalyticsGoalUrlDestinationDetails *urlDestinationDetails;

// Goal value.
@property (nonatomic, retain) NSNumber *value;  // floatValue

// Details for the goal of the type VISIT_NUM_PAGES.
@property (nonatomic, retain) GTLAnalyticsGoalVisitNumPagesDetails *visitNumPagesDetails;

// Details for the goal of the type VISIT_TIME_ON_SITE.
@property (nonatomic, retain) GTLAnalyticsGoalVisitTimeOnSiteDetails *visitTimeOnSiteDetails;

// Web property ID to which this goal belongs. The web property ID is of the
// form UA-XXXXX-YY.
@property (nonatomic, copy) NSString *webPropertyId;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalEventDetails
//

@interface GTLAnalyticsGoalEventDetails : GTLObject

// List of event conditions.
@property (nonatomic, retain) NSArray *eventConditions;  // of GTLAnalyticsGoalEventDetailsEventConditionsItem

// Determines if the event value should be used as the value for this goal.
@property (nonatomic, retain) NSNumber *useEventValue;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalParentLink
//

@interface GTLAnalyticsGoalParentLink : GTLObject

// Link to the view (profile) to which this goal belongs.
@property (nonatomic, copy) NSString *href;

// Value is "analytics#profile".
@property (nonatomic, copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalUrlDestinationDetails
//

@interface GTLAnalyticsGoalUrlDestinationDetails : GTLObject

// Determines if the goal URL must exactly match the capitalization of visited
// URLs.
@property (nonatomic, retain) NSNumber *caseSensitive;  // boolValue

// Determines if the first step in this goal is required.
@property (nonatomic, retain) NSNumber *firstStepRequired;  // boolValue

// Match type for the goal URL. Possible values are HEAD, EXACT, or REGEX.
@property (nonatomic, copy) NSString *matchType;

// List of steps configured for this goal funnel.
@property (nonatomic, retain) NSArray *steps;  // of GTLAnalyticsGoalUrlDestinationDetailsStepsItem

// URL for this goal.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalVisitNumPagesDetails
//

@interface GTLAnalyticsGoalVisitNumPagesDetails : GTLObject

// Type of comparison. Possible values are LESS_THAN, GREATER_THAN, or EQUAL.
@property (nonatomic, copy) NSString *comparisonType;

// Value used for this comparison.
@property (nonatomic, retain) NSNumber *comparisonValue;  // longLongValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalVisitTimeOnSiteDetails
//

@interface GTLAnalyticsGoalVisitTimeOnSiteDetails : GTLObject

// Type of comparison. Possible values are LESS_THAN or GREATER_THAN.
@property (nonatomic, copy) NSString *comparisonType;

// Value used for this comparison.
@property (nonatomic, retain) NSNumber *comparisonValue;  // longLongValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalEventDetailsEventConditionsItem
//

@interface GTLAnalyticsGoalEventDetailsEventConditionsItem : GTLObject

// Type of comparison. Possible values are LESS_THAN, GREATER_THAN or EQUAL.
@property (nonatomic, copy) NSString *comparisonType;

// Value used for this comparison.
@property (nonatomic, retain) NSNumber *comparisonValue;  // longLongValue

// Expression used for this match.
@property (nonatomic, copy) NSString *expression;

// Type of the match to be performed. Possible values are REGEXP, BEGINS_WITH,
// or EXACT.
@property (nonatomic, copy) NSString *matchType;

// Type of this event condition. Possible values are CATEGORY, ACTION, LABEL, or
// VALUE.
@property (nonatomic, copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsGoalUrlDestinationDetailsStepsItem
//

@interface GTLAnalyticsGoalUrlDestinationDetailsStepsItem : GTLObject

// Step name.
@property (nonatomic, copy) NSString *name;

// Step number.
@property (nonatomic, retain) NSNumber *number;  // intValue

// URL for this step.
@property (nonatomic, copy) NSString *url;

@end

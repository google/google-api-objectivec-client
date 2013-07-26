/* Copyright (c) 2013 Google Inc.
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
//  GTLAnalyticsExperiment.h
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
//   GTLAnalyticsExperiment (0 custom class methods, 27 custom properties)
//   GTLAnalyticsExperimentParentLink (0 custom class methods, 2 custom properties)
//   GTLAnalyticsExperimentVariationsItem (0 custom class methods, 5 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAnalyticsExperimentParentLink;
@class GTLAnalyticsExperimentVariationsItem;

// ----------------------------------------------------------------------------
//
//   GTLAnalyticsExperiment
//

// JSON template for Analytics experiment resource.

@interface GTLAnalyticsExperiment : GTLObject

// Account ID to which this experiment belongs. This field is read-only.
@property (copy) NSString *accountId;

// Time the experiment was created. This field is read-only.
@property (retain) GTLDateTime *created;

// Notes about this experiment.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// If true, the end user will be able to edit the experiment via the Google
// Analytics user interface.
@property (retain) id editableInGaUi;

// The ending time of the experiment (the time the status changed from RUNNING
// to ENDED). This field is present only if the experiment has ended. This field
// is read-only.
@property (retain) GTLDateTime *endTime;

// Experiment ID. Required for patch and update. Disallowed for create.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Internal ID for the web property to which this experiment belongs. This field
// is read-only.
@property (copy) NSString *internalWebPropertyId;

// Resource type for an Analytics experiment. This field is read-only.
@property (copy) NSString *kind;

// Specifies the minimum length of the experiment. Can be changed for a running
// experiment. This field may not be changed for an experiments whose status is
// ENDED.
@property (retain) NSNumber *minimumExperimentLengthInDays;  // intValue

// Experiment name. This field may not be changed for an experiment whose status
// is ENDED. This field is required when creating an experiment.
@property (copy) NSString *name;

// The metric that the experiment is optimizing. Valid values:
// "ga:goal(n)Completions", "ga:bounces", "ga:pageviews", "ga:timeOnSite",
// "ga:transactions", "ga:transactionRevenue". This field is required if status
// is "RUNNING" and servingFramework is one of "REDIRECT" or "API".
@property (copy) NSString *objectiveMetric;

// Whether the objectiveMetric should be minimized or maximized. Possible
// values: "MAXIMUM", "MINIMUM". Optional--defaults to "MAXIMUM". Cannot be
// specified without objectiveMetric. Cannot be modified when status is
// "RUNNING" or "ENDED".
@property (copy) NSString *optimizationType;

// Parent link for an experiment. Points to the view (profile) to which this
// experiment belongs.
@property (retain) GTLAnalyticsExperimentParentLink *parentLink;

// View (Profile) ID to which this experiment belongs. This field is read-only.
@property (copy) NSString *profileId;

// Why the experiment ended. Possible values: "STOPPED_BY_USER", "WINNER_FOUND",
// "EXPERIMENT_EXPIRED", "ENDED_WITH_NO_WINNER", "GOAL_OBJECTIVE_CHANGED".
// "ENDED_WITH_NO_WINNER" means that the experiment didn't expire but no winner
// was projected to be found. If the experiment status is changed via the API to
// ENDED this field is set to STOPPED_BY_USER. This field is read-only.
@property (copy) NSString *reasonExperimentEnded;

// Boolean specifying whether variations URLS are rewritten to match those of
// the original. This field may not be changed for an experiments whose status
// is ENDED.
@property (retain) NSNumber *rewriteVariationUrlsAsOriginal;  // boolValue

// Link for this experiment. This field is read-only.
@property (copy) NSString *selfLink;

// The framework used to serve the experiment variations and evaluate the
// results. One of:
// - REDIRECT: Google Analytics redirects traffic to different variation pages,
// reports the chosen variation and evaluates the results.
// - API: Google Analytics chooses and reports the variation to serve and
// evaluates the results; the caller is responsible for serving the selected
// variation.
// - EXTERNAL: The variations will be served externally and the chosen variation
// reported to Google Analytics. The caller is responsible for serving the
// selected variation and evaluating the results.
@property (retain) id servingFramework;

// The snippet of code to include on the control page(s). This field is
// read-only.
@property (copy) NSString *snippet;

// The starting time of the experiment (the time the status changed from
// READY_TO_RUN to RUNNING). This field is present only if the experiment has
// started. This field is read-only.
@property (retain) GTLDateTime *startTime;

// Experiment status. Possible values: "DRAFT", "READY_TO_RUN", "RUNNING",
// "ENDED". Experiments can be created in the "DRAFT", "READY_TO_RUN" or
// "RUNNING" state. This field is required when creating an experiment.
@property (copy) NSString *status;

// A floating-point number between 0 and 1. Specifies the fraction of the
// traffic that participates in the experiment. Can be changed for a running
// experiment. This field may not be changed for an experiments whose status is
// ENDED.
@property (retain) NSNumber *trafficCoverage;  // doubleValue

// Time the experiment was last modified. This field is read-only.
@property (retain) GTLDateTime *updated;

// Array of variations. The first variation in the array is the original. The
// number of variations may not change once an experiment is in the RUNNING
// state. At least two variations are required before status can be set to
// RUNNING.
@property (retain) NSArray *variations;  // of GTLAnalyticsExperimentVariationsItem

// Web property ID to which this experiment belongs. The web property ID is of
// the form UA-XXXXX-YY. This field is read-only.
@property (copy) NSString *webPropertyId;

// A floating-point number between 0 and 1. Specifies the necessary confidence
// level to choose a winner. This field may not be changed for an experiments
// whose status is ENDED.
@property (retain) NSNumber *winnerConfidenceLevel;  // doubleValue

// Boolean specifying whether a winner has been found for this experiment. This
// field is read-only.
@property (retain) NSNumber *winnerFound;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsExperimentParentLink
//

@interface GTLAnalyticsExperimentParentLink : GTLObject

// Link to the view (profile) to which this experiment belongs. This field is
// read-only.
@property (copy) NSString *href;

// Value is "analytics#profile". This field is read-only.
@property (copy) NSString *type;

@end


// ----------------------------------------------------------------------------
//
//   GTLAnalyticsExperimentVariationsItem
//

@interface GTLAnalyticsExperimentVariationsItem : GTLObject

// The name of the variation. This field is required when creating an
// experiment. This field may not be changed for an experiment whose status is
// ENDED.
@property (copy) NSString *name;

// Status of the variation. Possible values: "ACTIVE", "INACTIVE". INACTIVE
// variations are not served. This field may not be changed for an experiment
// whose status is ENDED.
@property (copy) NSString *status;

// The URL of the variation. This field may not be changed for an experiment
// whose status is RUNNING or ENDED.
@property (copy) NSString *url;

// Weight that this variation should receive. Only present if the experiment is
// running. This field is read-only.
@property (retain) NSNumber *weight;  // doubleValue

// True if the experiment has ended and this variation performed (statistically)
// significantly better than the original. This field is read-only.
@property (retain) NSNumber *won;  // boolValue

@end

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
//  GTLPredictionOutput.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Prediction API (prediction/v1.6)
// Description:
//   Lets you access a cloud hosted machine learning service that makes it easy
//   to build smart apps
// Documentation:
//   https://developers.google.com/prediction/docs/developer-guide
// Classes:
//   GTLPredictionOutput (0 custom class methods, 6 custom properties)
//   GTLPredictionOutputOutputMultiItem (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLPredictionOutputOutputMultiItem;

// ----------------------------------------------------------------------------
//
//   GTLPredictionOutput
//

@interface GTLPredictionOutput : GTLObject

// The unique name for the predictive model.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// What kind of resource this is.
@property (nonatomic, copy) NSString *kind;

// The most likely class label (Categorical models only).
@property (nonatomic, copy) NSString *outputLabel;

// A list of class labels with their estimated probabilities (Categorical models
// only).
@property (nonatomic, retain) NSArray *outputMulti;  // of GTLPredictionOutputOutputMultiItem

// The estimated regression value (Regression models only).
@property (nonatomic, copy) NSString *outputValue;

// A URL to re-request this resource.
@property (nonatomic, copy) NSString *selfLink;

@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionOutputOutputMultiItem
//

@interface GTLPredictionOutputOutputMultiItem : GTLObject

// The class label.
@property (nonatomic, copy) NSString *label;

// The probability of the class label.
@property (nonatomic, copy) NSString *score;

@end

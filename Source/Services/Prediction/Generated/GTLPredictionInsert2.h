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
//  GTLPredictionInsert2.h
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
//   GTLPredictionInsert2 (0 custom class methods, 11 custom properties)
//   GTLPredictionInsert2ModelInfo (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLPredictionInsert2ModelInfo;

// ----------------------------------------------------------------------------
//
//   GTLPredictionInsert2
//

@interface GTLPredictionInsert2 : GTLObject

// Insert time of the model (as a RFC 3339 timestamp).
@property (nonatomic, retain) GTLDateTime *created;

// The unique name for the predictive model.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// What kind of resource this is.
@property (nonatomic, copy) NSString *kind;

// Model metadata.
@property (nonatomic, retain) GTLPredictionInsert2ModelInfo *modelInfo;

// Type of predictive model (CLASSIFICATION or REGRESSION).
@property (nonatomic, copy) NSString *modelType;

// A URL to re-request this resource.
@property (nonatomic, copy) NSString *selfLink;

// Google storage location of the training data file.
@property (nonatomic, copy) NSString *storageDataLocation;

// Google storage location of the preprocessing pmml file.
@property (nonatomic, copy) NSString *storagePMMLLocation;

// Google storage location of the pmml model file.
@property (nonatomic, copy) NSString *storagePMMLModelLocation;

// Training completion time (as a RFC 3339 timestamp).
@property (nonatomic, retain) GTLDateTime *trainingComplete;

// The current status of the training job. This can be one of following:
// RUNNING; DONE; ERROR; ERROR: TRAINING JOB NOT FOUND
@property (nonatomic, copy) NSString *trainingStatus;

@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionInsert2ModelInfo
//

@interface GTLPredictionInsert2ModelInfo : GTLObject

// A number between 0.0 and 1.0, where 1.0 is 100% accurate. This is an
// estimate, based on the amount and quality of the training data, of the
// estimated prediction accuracy. You can use this is a guide to decide whether
// the results are accurate enough for your needs. This estimate will be more
// reliable if your real input data is similar to your training data
// (Categorical models only).
@property (nonatomic, copy) NSString *classificationAccuracy;

// Estimated accuracy of model taking utility weights into account (Categorical
// models only).
@property (nonatomic, copy) NSString *classWeightedAccuracy;

// An estimated mean squared error. The can be used to measure the quality of
// the predicted model (Regression models only).
@property (nonatomic, copy) NSString *meanSquaredError;

// Type of predictive model (CLASSIFICATION or REGRESSION).
@property (nonatomic, copy) NSString *modelType;

// Number of valid data instances used in the trained model.
@property (nonatomic, retain) NSNumber *numberInstances;  // longLongValue

// Number of class labels in the trained model (Categorical models only).
@property (nonatomic, retain) NSNumber *numberLabels;  // longLongValue

@end

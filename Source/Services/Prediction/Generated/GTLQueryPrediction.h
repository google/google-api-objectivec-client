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
//  GTLQueryPrediction.h
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
//   GTLQueryPrediction (8 custom class methods, 16 custom properties)
//   GTLPredictionHostedmodelsPredictInput (0 custom class methods, 1 custom properties)
//   GTLPredictionTrainedmodelsInsertTrainingInstancesItem (0 custom class methods, 2 custom properties)
//   GTLPredictionTrainedmodelsInsertUtilityItem (0 custom class methods, 0 custom properties)
//   GTLPredictionTrainedmodelsPredictInput (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLPredictionHostedmodelsPredictInput;
@class GTLPredictionTrainedmodelsInsertTrainingInstancesItem;
@class GTLPredictionTrainedmodelsInsertUtilityItem;
@class GTLPredictionTrainedmodelsPredictInput;

@interface GTLQueryPrediction : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (retain) NSArray *csvInstance;  // of any JSON type
@property (copy) NSString *hostedModelName;
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;
// "input" has different types for some query methods; see the documentation for
// the right type for each query method.
@property (retain) id input;
@property (assign) NSUInteger maxResults;
@property (copy) NSString *modelType;
@property (copy) NSString *output;
@property (copy) NSString *pageToken;
@property (copy) NSString *project;
@property (copy) NSString *sourceModel;
@property (copy) NSString *storageDataLocation;
@property (copy) NSString *storagePMMLLocation;
@property (copy) NSString *storagePMMLModelLocation;
@property (retain) NSArray *trainingInstances;  // of GTLPredictionTrainedmodelsInsertTrainingInstancesItem
@property (retain) NSArray *utility;  // of GTLPredictionTrainedmodelsInsertUtilityItem

#pragma mark -
#pragma mark "hostedmodels" methods
// These create a GTLQueryPrediction object.

// Method: prediction.hostedmodels.predict
// Submit input and request an output against a hosted model.
//  Required:
//   project: The project associated with the model.
//   hostedModelName: The name of a hosted model.
//  Optional:
//   input: Input to the model for a prediction.
//     Note: For this method, "input" should be of type
//     GTLPredictionHostedmodelsPredictInput.
//  Authorization scope(s):
//   kGTLAuthScopePrediction
// Fetches a GTLPredictionOutput.
+ (id)queryForHostedmodelsPredictWithProject:(NSString *)project
                             hostedModelName:(NSString *)hostedModelName;

#pragma mark -
#pragma mark "trainedmodels" methods
// These create a GTLQueryPrediction object.

// Method: prediction.trainedmodels.analyze
// Get analysis of the model and the data the model was trained on.
//  Required:
//   project: The project associated with the model.
//   identifier: The unique name for the predictive model.
//  Authorization scope(s):
//   kGTLAuthScopePrediction
// Fetches a GTLPredictionAnalyze.
+ (id)queryForTrainedmodelsAnalyzeWithProject:(NSString *)project
                                   identifier:(NSString *)identifier;

// Method: prediction.trainedmodels.delete
// Delete a trained model.
//  Required:
//   project: The project associated with the model.
//   identifier: The unique name for the predictive model.
//  Authorization scope(s):
//   kGTLAuthScopePrediction
+ (id)queryForTrainedmodelsDeleteWithProject:(NSString *)project
                                  identifier:(NSString *)identifier;

// Method: prediction.trainedmodels.get
// Check training status of your model.
//  Required:
//   project: The project associated with the model.
//   identifier: The unique name for the predictive model.
//  Authorization scope(s):
//   kGTLAuthScopePrediction
// Fetches a GTLPredictionInsert2.
+ (id)queryForTrainedmodelsGetWithProject:(NSString *)project
                               identifier:(NSString *)identifier;

// Method: prediction.trainedmodels.insert
// Train a Prediction API model.
//  Required:
//   project: The project associated with the model.
//  Optional:
//   identifier: The unique name for the predictive model.
//   modelType: Type of predictive model (classification or regression).
//   sourceModel: The Id of the model to be copied over.
//   storageDataLocation: Google storage location of the training data file.
//   storagePMMLLocation: Google storage location of the preprocessing pmml
//     file.
//   storagePMMLModelLocation: Google storage location of the pmml model file.
//   trainingInstances: Instances to train model on.
//   utility: A class weighting function, which allows the importance weights
//     for class labels to be specified (Categorical models only).
//  Authorization scope(s):
//   kGTLAuthScopePrediction
//   kGTLAuthScopePredictionDevstorageFullControl
//   kGTLAuthScopePredictionDevstorageReadOnly
//   kGTLAuthScopePredictionDevstorageReadWrite
// Fetches a GTLPredictionInsert2.
+ (id)queryForTrainedmodelsInsertWithProject:(NSString *)project;

// Method: prediction.trainedmodels.list
// List available models.
//  Required:
//   project: The project associated with the model.
//  Optional:
//   maxResults: Maximum number of results to return.
//   pageToken: Pagination token.
//  Authorization scope(s):
//   kGTLAuthScopePrediction
// Fetches a GTLPredictionList.
+ (id)queryForTrainedmodelsListWithProject:(NSString *)project;

// Method: prediction.trainedmodels.predict
// Submit model id and request a prediction.
//  Required:
//   project: The project associated with the model.
//   identifier: The unique name for the predictive model.
//  Optional:
//   input: Input to the model for a prediction.
//     Note: For this method, "input" should be of type
//     GTLPredictionTrainedmodelsPredictInput.
//  Authorization scope(s):
//   kGTLAuthScopePrediction
// Fetches a GTLPredictionOutput.
+ (id)queryForTrainedmodelsPredictWithProject:(NSString *)project
                                   identifier:(NSString *)identifier;

// Method: prediction.trainedmodels.update
// Add new data to a trained model.
//  Required:
//   project: The project associated with the model.
//   identifier: The unique name for the predictive model.
//  Optional:
//   csvInstance: The input features for this instance.
//   output: The generic output value - could be regression or class label.
//  Authorization scope(s):
//   kGTLAuthScopePrediction
// Fetches a GTLPredictionInsert2.
+ (id)queryForTrainedmodelsUpdateWithProject:(NSString *)project
                                  identifier:(NSString *)identifier;

@end

#pragma mark -
#pragma mark method parameter objects
// These object are used only to pass a collection of parameters to a
// method as a single item.

// ----------------------------------------------------------------------------
//
//   GTLPredictionHostedmodelsPredictInput
//

// Used for 'input' parameter on 'prediction.hostedmodels.predict'.

// Input to the model for a prediction.

@interface GTLPredictionHostedmodelsPredictInput : GTLObject

// A list of input features, these can be strings or doubles.
@property (retain) NSArray *csvInstance;  // of any JSON type

@end

// ----------------------------------------------------------------------------
//
//   GTLPredictionTrainedmodelsInsertTrainingInstancesItem
//

// Used for 'item' parameter on '(null)'.

@interface GTLPredictionTrainedmodelsInsertTrainingInstancesItem : GTLObject

// The input features for this instance.
@property (retain) NSArray *csvInstance;  // of any JSON type

// The generic output value - could be regression or class label.
@property (copy) NSString *output;

@end

// ----------------------------------------------------------------------------
//
//   GTLPredictionTrainedmodelsInsertUtilityItem
//

// Used for 'item' parameter on '(null)'.

// Class label (string).

@interface GTLPredictionTrainedmodelsInsertUtilityItem : GTLObject
// This object is documented as having more properties that are NSNumber
// (doubleValue). Use -additionalJSONKeys and -additionalPropertyForName: to get
// the list of properties and then fetch them; or -additionalProperties to fetch
// them all at once.
@end

// ----------------------------------------------------------------------------
//
//   GTLPredictionTrainedmodelsPredictInput
//

// Used for 'input' parameter on 'prediction.trainedmodels.predict'.

// Input to the model for a prediction.

@interface GTLPredictionTrainedmodelsPredictInput : GTLObject

// A list of input features, these can be strings or doubles.
@property (retain) NSArray *csvInstance;  // of any JSON type

@end

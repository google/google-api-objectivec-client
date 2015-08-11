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
//  GTLQueryPrediction.m
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

#import "GTLQueryPrediction.h"

#import "GTLPredictionAnalyze.h"
#import "GTLPredictionInsert2.h"
#import "GTLPredictionList.h"
#import "GTLPredictionOutput.h"

@implementation GTLQueryPrediction

@dynamic csvInstance, fields, hostedModelName, identifier, input, maxResults,
         modelType, output, pageToken, project, sourceModel,
         storageDataLocation, storagePMMLLocation, storagePMMLModelLocation,
         trainingInstances, utility;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"csvInstance" : [NSObject class],
    @"trainingInstances" : [GTLPredictionTrainedmodelsInsertTrainingInstancesItem class],
    @"utility" : [GTLPredictionTrainedmodelsInsertUtilityItem class]
  };
  return map;
}

#pragma mark - "hostedmodels" methods
// These create a GTLQueryPrediction object.

+ (instancetype)queryForHostedmodelsPredictWithProject:(NSString *)project
                                       hostedModelName:(NSString *)hostedModelName {
  NSString *methodName = @"prediction.hostedmodels.predict";
  GTLQueryPrediction *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.hostedModelName = hostedModelName;
  query.expectedObjectClass = [GTLPredictionOutput class];
  return query;
}

#pragma mark - "trainedmodels" methods
// These create a GTLQueryPrediction object.

+ (instancetype)queryForTrainedmodelsAnalyzeWithProject:(NSString *)project
                                             identifier:(NSString *)identifier {
  NSString *methodName = @"prediction.trainedmodels.analyze";
  GTLQueryPrediction *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.identifier = identifier;
  query.expectedObjectClass = [GTLPredictionAnalyze class];
  return query;
}

+ (instancetype)queryForTrainedmodelsDeleteWithProject:(NSString *)project
                                            identifier:(NSString *)identifier {
  NSString *methodName = @"prediction.trainedmodels.delete";
  GTLQueryPrediction *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.identifier = identifier;
  return query;
}

+ (instancetype)queryForTrainedmodelsGetWithProject:(NSString *)project
                                         identifier:(NSString *)identifier {
  NSString *methodName = @"prediction.trainedmodels.get";
  GTLQueryPrediction *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.identifier = identifier;
  query.expectedObjectClass = [GTLPredictionInsert2 class];
  return query;
}

+ (instancetype)queryForTrainedmodelsInsertWithProject:(NSString *)project {
  NSString *methodName = @"prediction.trainedmodels.insert";
  GTLQueryPrediction *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLPredictionInsert2 class];
  return query;
}

+ (instancetype)queryForTrainedmodelsListWithProject:(NSString *)project {
  NSString *methodName = @"prediction.trainedmodels.list";
  GTLQueryPrediction *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLPredictionList class];
  return query;
}

+ (instancetype)queryForTrainedmodelsPredictWithProject:(NSString *)project
                                             identifier:(NSString *)identifier {
  NSString *methodName = @"prediction.trainedmodels.predict";
  GTLQueryPrediction *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.identifier = identifier;
  query.expectedObjectClass = [GTLPredictionOutput class];
  return query;
}

+ (instancetype)queryForTrainedmodelsUpdateWithProject:(NSString *)project
                                            identifier:(NSString *)identifier {
  NSString *methodName = @"prediction.trainedmodels.update";
  GTLQueryPrediction *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.identifier = identifier;
  query.expectedObjectClass = [GTLPredictionInsert2 class];
  return query;
}

@end

#pragma mark - method parameter objects
// These object are used only to pass a collection of parameters to a
// method as a single item.

// ----------------------------------------------------------------------------
//
//   GTLPredictionHostedmodelsPredictInput
//

@implementation GTLPredictionHostedmodelsPredictInput
@dynamic csvInstance;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"csvInstance" : [NSObject class]
  };
  return map;
}

@end

// ----------------------------------------------------------------------------
//
//   GTLPredictionTrainedmodelsInsertTrainingInstancesItem
//

@implementation GTLPredictionTrainedmodelsInsertTrainingInstancesItem
@dynamic csvInstance, output;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"csvInstance" : [NSObject class]
  };
  return map;
}

@end

// ----------------------------------------------------------------------------
//
//   GTLPredictionTrainedmodelsInsertUtilityItem
//

@implementation GTLPredictionTrainedmodelsInsertUtilityItem

+ (Class)classForAdditionalProperties {
  return [NSNumber class];
}

@end

// ----------------------------------------------------------------------------
//
//   GTLPredictionTrainedmodelsPredictInput
//

@implementation GTLPredictionTrainedmodelsPredictInput
@dynamic csvInstance;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"csvInstance" : [NSObject class]
  };
  return map;
}

@end

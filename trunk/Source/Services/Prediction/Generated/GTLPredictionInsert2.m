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
//  GTLPredictionInsert2.m
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

#import "GTLPredictionInsert2.h"

// ----------------------------------------------------------------------------
//
//   GTLPredictionInsert2
//

@implementation GTLPredictionInsert2
@dynamic created, identifier, kind, modelInfo, modelType, selfLink,
         storageDataLocation, storagePMMLLocation, storagePMMLModelLocation,
         trainingComplete, trainingStatus;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:@"id"
                                forKey:@"identifier"];
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"prediction#training"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionInsert2ModelInfo
//

@implementation GTLPredictionInsert2ModelInfo
@dynamic classificationAccuracy, classWeightedAccuracy, meanSquaredError,
         modelType, numberInstances, numberLabels;
@end

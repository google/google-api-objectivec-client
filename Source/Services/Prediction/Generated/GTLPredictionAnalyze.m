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
//  GTLPredictionAnalyze.m
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
//   GTLPredictionAnalyze (0 custom class methods, 6 custom properties)
//   GTLPredictionAnalyzeDataDescription (0 custom class methods, 2 custom properties)
//   GTLPredictionAnalyzeErrorsItem (0 custom class methods, 0 custom properties)
//   GTLPredictionAnalyzeModelDescription (0 custom class methods, 3 custom properties)
//   GTLPredictionAnalyzeDataDescriptionFeaturesItem (0 custom class methods, 4 custom properties)
//   GTLPredictionAnalyzeDataDescriptionOutputFeature (0 custom class methods, 2 custom properties)
//   GTLPredictionAnalyzeModelDescriptionConfusionMatrix (0 custom class methods, 0 custom properties)
//   GTLPredictionAnalyzeModelDescriptionConfusionMatrixRowTotals (0 custom class methods, 0 custom properties)
//   GTLPredictionAnalyzeDataDescriptionFeaturesItemCategorical (0 custom class methods, 2 custom properties)
//   GTLPredictionAnalyzeDataDescriptionFeaturesItemNumeric (0 custom class methods, 3 custom properties)
//   GTLPredictionAnalyzeDataDescriptionFeaturesItemText (0 custom class methods, 1 custom properties)
//   GTLPredictionAnalyzeDataDescriptionOutputFeatureNumeric (0 custom class methods, 3 custom properties)
//   GTLPredictionAnalyzeDataDescriptionOutputFeatureTextItem (0 custom class methods, 2 custom properties)
//   GTLPredictionAnalyzeModelDescriptionConfusionMatrixConfusionMatrix (0 custom class methods, 0 custom properties)
//   GTLPredictionAnalyzeDataDescriptionFeaturesItemCategoricalValuesItem (0 custom class methods, 2 custom properties)

#import "GTLPredictionAnalyze.h"

#import "GTLPredictionInsert2.h"

// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyze
//

@implementation GTLPredictionAnalyze
@dynamic dataDescription, errors, identifier, kind, modelDescription, selfLink;

+ (NSDictionary *)propertyToJSONKeyMap {
  NSDictionary *map = @{
    @"identifier" : @"id"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"errors" : [GTLPredictionAnalyzeErrorsItem class]
  };
  return map;
}

+ (void)load {
  [self registerObjectClassForKind:@"prediction#analyze"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeDataDescription
//

@implementation GTLPredictionAnalyzeDataDescription
@dynamic features, outputFeature;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"features" : [GTLPredictionAnalyzeDataDescriptionFeaturesItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeErrorsItem
//

@implementation GTLPredictionAnalyzeErrorsItem

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeModelDescription
//

@implementation GTLPredictionAnalyzeModelDescription
@dynamic confusionMatrix, confusionMatrixRowTotals, modelinfo;
@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeDataDescriptionFeaturesItem
//

@implementation GTLPredictionAnalyzeDataDescriptionFeaturesItem
@dynamic categorical, index, numeric, text;
@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeDataDescriptionOutputFeature
//

@implementation GTLPredictionAnalyzeDataDescriptionOutputFeature
@dynamic numeric, text;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"text" : [GTLPredictionAnalyzeDataDescriptionOutputFeatureTextItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeModelDescriptionConfusionMatrix
//

@implementation GTLPredictionAnalyzeModelDescriptionConfusionMatrix

+ (Class)classForAdditionalProperties {
  return [GTLPredictionAnalyzeModelDescriptionConfusionMatrixConfusionMatrix class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeModelDescriptionConfusionMatrixRowTotals
//

@implementation GTLPredictionAnalyzeModelDescriptionConfusionMatrixRowTotals

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeDataDescriptionFeaturesItemCategorical
//

@implementation GTLPredictionAnalyzeDataDescriptionFeaturesItemCategorical
@dynamic count, values;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"values" : [GTLPredictionAnalyzeDataDescriptionFeaturesItemCategoricalValuesItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeDataDescriptionFeaturesItemNumeric
//

@implementation GTLPredictionAnalyzeDataDescriptionFeaturesItemNumeric
@dynamic count, mean, variance;
@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeDataDescriptionFeaturesItemText
//

@implementation GTLPredictionAnalyzeDataDescriptionFeaturesItemText
@dynamic count;
@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeDataDescriptionOutputFeatureNumeric
//

@implementation GTLPredictionAnalyzeDataDescriptionOutputFeatureNumeric
@dynamic count, mean, variance;
@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeDataDescriptionOutputFeatureTextItem
//

@implementation GTLPredictionAnalyzeDataDescriptionOutputFeatureTextItem
@dynamic count, value;
@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeModelDescriptionConfusionMatrixConfusionMatrix
//

@implementation GTLPredictionAnalyzeModelDescriptionConfusionMatrixConfusionMatrix

+ (Class)classForAdditionalProperties {
  return [NSString class];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLPredictionAnalyzeDataDescriptionFeaturesItemCategoricalValuesItem
//

@implementation GTLPredictionAnalyzeDataDescriptionFeaturesItemCategoricalValuesItem
@dynamic count, value;
@end

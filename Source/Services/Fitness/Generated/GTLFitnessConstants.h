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
//  GTLFitnessConstants.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Fitness (fitness/v1)
// Description:
//   Google Fit API
// Documentation:
//   https://developers.google.com/fit/rest/

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLDefines.h"
#else
  #import "GTLDefines.h"
#endif

// Authorization scope
// View your activity information in Google Fit
GTL_EXTERN NSString * const kGTLAuthScopeFitnessActivityRead;   // "https://www.googleapis.com/auth/fitness.activity.read"
// View and store your activity information in Google Fit
GTL_EXTERN NSString * const kGTLAuthScopeFitnessActivityWrite;  // "https://www.googleapis.com/auth/fitness.activity.write"
// View body sensor information in Google Fit
GTL_EXTERN NSString * const kGTLAuthScopeFitnessBodyRead;       // "https://www.googleapis.com/auth/fitness.body.read"
// View and store body sensor data in Google Fit
GTL_EXTERN NSString * const kGTLAuthScopeFitnessBodyWrite;      // "https://www.googleapis.com/auth/fitness.body.write"
// View your stored location data in Google Fit
GTL_EXTERN NSString * const kGTLAuthScopeFitnessLocationRead;   // "https://www.googleapis.com/auth/fitness.location.read"
// View and store your location data in Google Fit
GTL_EXTERN NSString * const kGTLAuthScopeFitnessLocationWrite;  // "https://www.googleapis.com/auth/fitness.location.write"

// GTLFitnessAggregateBucket - Type
GTL_EXTERN NSString * const kGTLFitnessAggregateBucket_Type_ActivitySegment;  // "activitySegment"
GTL_EXTERN NSString * const kGTLFitnessAggregateBucket_Type_ActivityType;  // "activityType"
GTL_EXTERN NSString * const kGTLFitnessAggregateBucket_Type_Session;  // "session"
GTL_EXTERN NSString * const kGTLFitnessAggregateBucket_Type_Time;  // "time"
GTL_EXTERN NSString * const kGTLFitnessAggregateBucket_Type_Unknown;  // "unknown"

// GTLFitnessDataSource - Type
GTL_EXTERN NSString * const kGTLFitnessDataSource_Type_Derived;  // "derived"
GTL_EXTERN NSString * const kGTLFitnessDataSource_Type_Raw;     // "raw"

// GTLFitnessDataTypeField - Format
GTL_EXTERN NSString * const kGTLFitnessDataTypeField_Format_FloatList;  // "floatList"
GTL_EXTERN NSString * const kGTLFitnessDataTypeField_Format_FloatPoint;  // "floatPoint"
GTL_EXTERN NSString * const kGTLFitnessDataTypeField_Format_Integer;  // "integer"
GTL_EXTERN NSString * const kGTLFitnessDataTypeField_Format_IntegerList;  // "integerList"
GTL_EXTERN NSString * const kGTLFitnessDataTypeField_Format_Map;  // "map"
GTL_EXTERN NSString * const kGTLFitnessDataTypeField_Format_String;  // "string"

// GTLFitnessDevice - Type
GTL_EXTERN NSString * const kGTLFitnessDevice_Type_ChestStrap;  // "chestStrap"
GTL_EXTERN NSString * const kGTLFitnessDevice_Type_Phone;       // "phone"
GTL_EXTERN NSString * const kGTLFitnessDevice_Type_Scale;       // "scale"
GTL_EXTERN NSString * const kGTLFitnessDevice_Type_Tablet;      // "tablet"
GTL_EXTERN NSString * const kGTLFitnessDevice_Type_Unknown;     // "unknown"
GTL_EXTERN NSString * const kGTLFitnessDevice_Type_Watch;       // "watch"

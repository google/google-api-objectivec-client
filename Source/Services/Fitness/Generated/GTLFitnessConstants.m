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
//  GTLFitnessConstants.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Fitness (fitness/v1)
// Description:
//   Google Fit API
// Documentation:
//   https://developers.google.com/fit/rest/

#import "GTLFitnessConstants.h"

// Authorization scope
NSString * const kGTLAuthScopeFitnessActivityRead  = @"https://www.googleapis.com/auth/fitness.activity.read";
NSString * const kGTLAuthScopeFitnessActivityWrite = @"https://www.googleapis.com/auth/fitness.activity.write";
NSString * const kGTLAuthScopeFitnessBodyRead      = @"https://www.googleapis.com/auth/fitness.body.read";
NSString * const kGTLAuthScopeFitnessBodyWrite     = @"https://www.googleapis.com/auth/fitness.body.write";
NSString * const kGTLAuthScopeFitnessLocationRead  = @"https://www.googleapis.com/auth/fitness.location.read";
NSString * const kGTLAuthScopeFitnessLocationWrite = @"https://www.googleapis.com/auth/fitness.location.write";

// GTLFitnessAggregateBucket - Type
NSString * const kGTLFitnessAggregateBucket_Type_ActivitySegment = @"activitySegment";
NSString * const kGTLFitnessAggregateBucket_Type_ActivityType  = @"activityType";
NSString * const kGTLFitnessAggregateBucket_Type_Session       = @"session";
NSString * const kGTLFitnessAggregateBucket_Type_Time          = @"time";
NSString * const kGTLFitnessAggregateBucket_Type_Unknown       = @"unknown";

// GTLFitnessDataSource - Type
NSString * const kGTLFitnessDataSource_Type_Derived = @"derived";
NSString * const kGTLFitnessDataSource_Type_Raw     = @"raw";

// GTLFitnessDataTypeField - Format
NSString * const kGTLFitnessDataTypeField_Format_FloatList   = @"floatList";
NSString * const kGTLFitnessDataTypeField_Format_FloatPoint  = @"floatPoint";
NSString * const kGTLFitnessDataTypeField_Format_Integer     = @"integer";
NSString * const kGTLFitnessDataTypeField_Format_IntegerList = @"integerList";
NSString * const kGTLFitnessDataTypeField_Format_Map         = @"map";
NSString * const kGTLFitnessDataTypeField_Format_String      = @"string";

// GTLFitnessDevice - Type
NSString * const kGTLFitnessDevice_Type_ChestStrap = @"chestStrap";
NSString * const kGTLFitnessDevice_Type_Phone      = @"phone";
NSString * const kGTLFitnessDevice_Type_Scale      = @"scale";
NSString * const kGTLFitnessDevice_Type_Tablet     = @"tablet";
NSString * const kGTLFitnessDevice_Type_Unknown    = @"unknown";
NSString * const kGTLFitnessDevice_Type_Watch      = @"watch";

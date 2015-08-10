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
//  GTLFitnessAggregateBy.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Fitness (fitness/v1)
// Description:
//   Google Fit API
// Documentation:
//   https://developers.google.com/fit/rest/
// Classes:
//   GTLFitnessAggregateBy (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLFitnessAggregateBy
//

// The specification of which data to aggregate.

@interface GTLFitnessAggregateBy : GTLObject

// A data source ID to aggregate. Mutually exclusive of dataTypeName. Only data
// from the specified data source ID will be included in the aggregation. The
// dataset in the response will have the same data source ID.
@property (nonatomic, copy) NSString *dataSourceId;

// The data type to aggregate. All data sources providing this data type will
// contribute data to the aggregation. The response will contain a single
// dataset for this data type name. The dataset will have a data source ID of
// derived:com.google.:com.google.android.gms:aggregated
@property (nonatomic, copy) NSString *dataTypeName;

@end

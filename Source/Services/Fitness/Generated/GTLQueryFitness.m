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
//  GTLQueryFitness.m
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
//   GTLQueryFitness (13 custom class methods, 23 custom properties)

#import "GTLQueryFitness.h"

#import "GTLFitnessAggregateBy.h"
#import "GTLFitnessAggregateResponse.h"
#import "GTLFitnessBucketByActivity.h"
#import "GTLFitnessBucketBySession.h"
#import "GTLFitnessBucketByTime.h"
#import "GTLFitnessDataset.h"
#import "GTLFitnessDataSource.h"
#import "GTLFitnessListDataSourcesResponse.h"
#import "GTLFitnessListSessionsResponse.h"
#import "GTLFitnessSession.h"

@implementation GTLQueryFitness

@dynamic aggregateBy, bucketByActivitySegment, bucketByActivityType,
         bucketBySession, bucketByTime, currentTimeMillis, dataSource, dataset,
         datasetId, dataSourceId, dataTypeName, endTime, endTimeMillis, fields,
         includeDeleted, limit, modifiedTimeMillis, pageToken, session,
         sessionId, startTime, startTimeMillis, userId;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map = @{
    @"dataSource" : @"data_source"
  };
  return map;
}

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"aggregateBy" : [GTLFitnessAggregateBy class],
    @"dataTypeName" : [NSString class]
  };
  return map;
}

#pragma mark -
#pragma mark "users.dataset" methods
// These create a GTLQueryFitness object.

+ (instancetype)queryForUsersDatasetAggregateWithUserId:(NSString *)userId {
  NSString *methodName = @"fitness.users.dataset.aggregate";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLFitnessAggregateResponse class];
  return query;
}

#pragma mark -
#pragma mark "users.dataSources" methods
// These create a GTLQueryFitness object.

+ (instancetype)queryForUsersDataSourcesCreateWithUserId:(NSString *)userId {
  NSString *methodName = @"fitness.users.dataSources.create";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLFitnessDataSource class];
  return query;
}

#pragma mark -
#pragma mark "users.dataSources.datasets" methods
// These create a GTLQueryFitness object.

+ (instancetype)queryForUsersDataSourcesDatasetsDeleteWithUserId:(NSString *)userId
                                                    dataSourceId:(NSString *)dataSourceId
                                                       datasetId:(NSString *)datasetId {
  NSString *methodName = @"fitness.users.dataSources.datasets.delete";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.dataSourceId = dataSourceId;
  query.datasetId = datasetId;
  return query;
}

+ (instancetype)queryForUsersDataSourcesDatasetsGetWithUserId:(NSString *)userId
                                                 dataSourceId:(NSString *)dataSourceId
                                                    datasetId:(NSString *)datasetId {
  NSString *methodName = @"fitness.users.dataSources.datasets.get";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.dataSourceId = dataSourceId;
  query.datasetId = datasetId;
  query.expectedObjectClass = [GTLFitnessDataset class];
  return query;
}

+ (instancetype)queryForUsersDataSourcesDatasetsPatchWithUserId:(NSString *)userId
                                                   dataSourceId:(NSString *)dataSourceId
                                                      datasetId:(NSString *)datasetId {
  NSString *methodName = @"fitness.users.dataSources.datasets.patch";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.dataSourceId = dataSourceId;
  query.datasetId = datasetId;
  query.expectedObjectClass = [GTLFitnessDataset class];
  return query;
}

#pragma mark -
#pragma mark "users.dataSources" methods
// These create a GTLQueryFitness object.

+ (instancetype)queryForUsersDataSourcesDeleteWithUserId:(NSString *)userId
                                            dataSourceId:(NSString *)dataSourceId {
  NSString *methodName = @"fitness.users.dataSources.delete";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.dataSourceId = dataSourceId;
  query.expectedObjectClass = [GTLFitnessDataSource class];
  return query;
}

+ (instancetype)queryForUsersDataSourcesGetWithUserId:(NSString *)userId
                                         dataSourceId:(NSString *)dataSourceId {
  NSString *methodName = @"fitness.users.dataSources.get";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.dataSourceId = dataSourceId;
  query.expectedObjectClass = [GTLFitnessDataSource class];
  return query;
}

+ (instancetype)queryForUsersDataSourcesListWithUserId:(NSString *)userId {
  NSString *methodName = @"fitness.users.dataSources.list";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLFitnessListDataSourcesResponse class];
  return query;
}

+ (instancetype)queryForUsersDataSourcesPatchWithUserId:(NSString *)userId
                                           dataSourceId:(NSString *)dataSourceId {
  NSString *methodName = @"fitness.users.dataSources.patch";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.dataSourceId = dataSourceId;
  query.expectedObjectClass = [GTLFitnessDataSource class];
  return query;
}

+ (instancetype)queryForUsersDataSourcesUpdateWithUserId:(NSString *)userId
                                            dataSourceId:(NSString *)dataSourceId {
  NSString *methodName = @"fitness.users.dataSources.update";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.dataSourceId = dataSourceId;
  query.expectedObjectClass = [GTLFitnessDataSource class];
  return query;
}

#pragma mark -
#pragma mark "users.sessions" methods
// These create a GTLQueryFitness object.

+ (instancetype)queryForUsersSessionsDeleteWithUserId:(NSString *)userId
                                            sessionId:(NSString *)sessionId {
  NSString *methodName = @"fitness.users.sessions.delete";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.sessionId = sessionId;
  return query;
}

+ (instancetype)queryForUsersSessionsListWithUserId:(NSString *)userId {
  NSString *methodName = @"fitness.users.sessions.list";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLFitnessListSessionsResponse class];
  return query;
}

+ (instancetype)queryForUsersSessionsUpdateWithUserId:(NSString *)userId
                                            sessionId:(NSString *)sessionId {
  NSString *methodName = @"fitness.users.sessions.update";
  GTLQueryFitness *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.sessionId = sessionId;
  query.expectedObjectClass = [GTLFitnessSession class];
  return query;
}

@end

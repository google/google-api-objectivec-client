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
//  GTLQueryBigquery.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   BigQuery API (bigquery/v2)
// Description:
//   A data platform for customers to create, manage, share and query data.
// Documentation:
//   https://cloud.google.com/bigquery/
// Classes:
//   GTLQueryBigquery (21 custom class methods, 23 custom properties)
//   GTLBigqueryTabledataInsertAllRowsItem (0 custom class methods, 2 custom properties)

#import "GTLQueryBigquery.h"

#import "GTLBigqueryDataset.h"
#import "GTLBigqueryDatasetList.h"
#import "GTLBigqueryDatasetReference.h"
#import "GTLBigqueryGetQueryResultsResponse.h"
#import "GTLBigqueryJob.h"
#import "GTLBigqueryJobCancelResponse.h"
#import "GTLBigqueryJobList.h"
#import "GTLBigqueryJsonObject.h"
#import "GTLBigqueryProjectList.h"
#import "GTLBigqueryQueryResponse.h"
#import "GTLBigqueryTable.h"
#import "GTLBigqueryTableDataInsertAllResponse.h"
#import "GTLBigqueryTableDataList.h"
#import "GTLBigqueryTableList.h"

@implementation GTLQueryBigquery

@dynamic all, allUsers, datasetId, defaultDataset, deleteContents, dryRun,
         fields, ignoreUnknownValues, jobId, kind, maxResults, pageToken,
         preserveNulls, projectId, projection, query, rows, skipInvalidRows,
         startIndex, stateFilter, tableId, timeoutMs, useQueryCache;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"rows" : [GTLBigqueryTabledataInsertAllRowsItem class],
    @"stateFilter" : [NSString class]
  };
  return map;
}

#pragma mark -
#pragma mark "datasets" methods
// These create a GTLQueryBigquery object.

+ (instancetype)queryForDatasetsDeleteWithProjectId:(NSString *)projectId
                                          datasetId:(NSString *)datasetId {
  NSString *methodName = @"bigquery.datasets.delete";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.datasetId = datasetId;
  return query;
}

+ (instancetype)queryForDatasetsGetWithProjectId:(NSString *)projectId
                                       datasetId:(NSString *)datasetId {
  NSString *methodName = @"bigquery.datasets.get";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.datasetId = datasetId;
  query.expectedObjectClass = [GTLBigqueryDataset class];
  return query;
}

+ (instancetype)queryForDatasetsInsertWithObject:(GTLBigqueryDataset *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"bigquery.datasets.insert";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLBigqueryDataset class];
  return query;
}

+ (instancetype)queryForDatasetsListWithProjectId:(NSString *)projectId {
  NSString *methodName = @"bigquery.datasets.list";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.expectedObjectClass = [GTLBigqueryDatasetList class];
  return query;
}

+ (instancetype)queryForDatasetsPatchWithObject:(GTLBigqueryDataset *)object
                                      projectId:(NSString *)projectId
                                      datasetId:(NSString *)datasetId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"bigquery.datasets.patch";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.projectId = projectId;
  query.datasetId = datasetId;
  query.expectedObjectClass = [GTLBigqueryDataset class];
  return query;
}

+ (instancetype)queryForDatasetsUpdateWithObject:(GTLBigqueryDataset *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"bigquery.datasets.update";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLBigqueryDataset class];
  return query;
}

#pragma mark -
#pragma mark "jobs" methods
// These create a GTLQueryBigquery object.

+ (instancetype)queryForJobsCancelWithProjectId:(NSString *)projectId
                                          jobId:(NSString *)jobId {
  NSString *methodName = @"bigquery.jobs.cancel";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.jobId = jobId;
  query.expectedObjectClass = [GTLBigqueryJobCancelResponse class];
  return query;
}

+ (instancetype)queryForJobsGetWithProjectId:(NSString *)projectId
                                       jobId:(NSString *)jobId {
  NSString *methodName = @"bigquery.jobs.get";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.jobId = jobId;
  query.expectedObjectClass = [GTLBigqueryJob class];
  return query;
}

+ (instancetype)queryForJobsGetQueryResultsWithProjectId:(NSString *)projectId
                                                   jobId:(NSString *)jobId {
  NSString *methodName = @"bigquery.jobs.getQueryResults";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.jobId = jobId;
  query.expectedObjectClass = [GTLBigqueryGetQueryResultsResponse class];
  return query;
}

+ (instancetype)queryForJobsInsertWithObject:(GTLBigqueryJob *)object
                            uploadParameters:(GTLUploadParameters *)uploadParametersOrNil {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"bigquery.jobs.insert";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.uploadParameters = uploadParametersOrNil;
  query.expectedObjectClass = [GTLBigqueryJob class];
  return query;
}

+ (instancetype)queryForJobsListWithProjectId:(NSString *)projectId {
  NSString *methodName = @"bigquery.jobs.list";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.expectedObjectClass = [GTLBigqueryJobList class];
  return query;
}

+ (instancetype)queryForJobsQueryWithProjectId:(NSString *)projectId
                                         query:(NSString *)query_param {
  NSString *methodName = @"bigquery.jobs.query";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.query = query_param;
  query.expectedObjectClass = [GTLBigqueryQueryResponse class];
  return query;
}

#pragma mark -
#pragma mark "projects" methods
// These create a GTLQueryBigquery object.

+ (instancetype)queryForProjectsList {
  NSString *methodName = @"bigquery.projects.list";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLBigqueryProjectList class];
  return query;
}

#pragma mark -
#pragma mark "tabledata" methods
// These create a GTLQueryBigquery object.

+ (instancetype)queryForTabledataInsertAllWithProjectId:(NSString *)projectId
                                              datasetId:(NSString *)datasetId
                                                tableId:(NSString *)tableId {
  NSString *methodName = @"bigquery.tabledata.insertAll";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.datasetId = datasetId;
  query.tableId = tableId;
  query.expectedObjectClass = [GTLBigqueryTableDataInsertAllResponse class];
  return query;
}

+ (instancetype)queryForTabledataListWithProjectId:(NSString *)projectId
                                         datasetId:(NSString *)datasetId
                                           tableId:(NSString *)tableId {
  NSString *methodName = @"bigquery.tabledata.list";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.datasetId = datasetId;
  query.tableId = tableId;
  query.expectedObjectClass = [GTLBigqueryTableDataList class];
  return query;
}

#pragma mark -
#pragma mark "tables" methods
// These create a GTLQueryBigquery object.

+ (instancetype)queryForTablesDeleteWithProjectId:(NSString *)projectId
                                        datasetId:(NSString *)datasetId
                                          tableId:(NSString *)tableId {
  NSString *methodName = @"bigquery.tables.delete";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.datasetId = datasetId;
  query.tableId = tableId;
  return query;
}

+ (instancetype)queryForTablesGetWithProjectId:(NSString *)projectId
                                     datasetId:(NSString *)datasetId
                                       tableId:(NSString *)tableId {
  NSString *methodName = @"bigquery.tables.get";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.datasetId = datasetId;
  query.tableId = tableId;
  query.expectedObjectClass = [GTLBigqueryTable class];
  return query;
}

+ (instancetype)queryForTablesInsertWithObject:(GTLBigqueryTable *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"bigquery.tables.insert";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLBigqueryTable class];
  return query;
}

+ (instancetype)queryForTablesListWithProjectId:(NSString *)projectId
                                      datasetId:(NSString *)datasetId {
  NSString *methodName = @"bigquery.tables.list";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.projectId = projectId;
  query.datasetId = datasetId;
  query.expectedObjectClass = [GTLBigqueryTableList class];
  return query;
}

+ (instancetype)queryForTablesPatchWithObject:(GTLBigqueryTable *)object
                                    projectId:(NSString *)projectId
                                    datasetId:(NSString *)datasetId
                                      tableId:(NSString *)tableId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"bigquery.tables.patch";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.projectId = projectId;
  query.datasetId = datasetId;
  query.tableId = tableId;
  query.expectedObjectClass = [GTLBigqueryTable class];
  return query;
}

+ (instancetype)queryForTablesUpdateWithObject:(GTLBigqueryTable *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"bigquery.tables.update";
  GTLQueryBigquery *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLBigqueryTable class];
  return query;
}

@end

#pragma mark -
#pragma mark method parameter objects
// These object are used only to pass a collection of parameters to a
// method as a single item.

// ----------------------------------------------------------------------------
//
//   GTLBigqueryTabledataInsertAllRowsItem
//

@implementation GTLBigqueryTabledataInsertAllRowsItem
@dynamic insertId, json;
@end

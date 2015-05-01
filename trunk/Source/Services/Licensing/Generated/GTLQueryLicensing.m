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
//  GTLQueryLicensing.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Enterprise License Manager API (licensing/v1)
// Description:
//   Licensing API to view and manage license for your domain.
// Documentation:
//   https://developers.google.com/google-apps/licensing/
// Classes:
//   GTLQueryLicensing (7 custom class methods, 7 custom properties)

#import "GTLQueryLicensing.h"

#import "GTLLicensingLicenseAssignment.h"
#import "GTLLicensingLicenseAssignmentInsert.h"
#import "GTLLicensingLicenseAssignmentList.h"

@implementation GTLQueryLicensing

@dynamic customerId, fields, maxResults, pageToken, productId, skuId, userId;

#pragma mark -
#pragma mark "licenseAssignments" methods
// These create a GTLQueryLicensing object.

+ (instancetype)queryForLicenseAssignmentsDeleteWithProductId:(NSString *)productId
                                                        skuId:(NSString *)skuId
                                                       userId:(NSString *)userId {
  NSString *methodName = @"licensing.licenseAssignments.delete";
  GTLQueryLicensing *query = [self queryWithMethodName:methodName];
  query.productId = productId;
  query.skuId = skuId;
  query.userId = userId;
  return query;
}

+ (instancetype)queryForLicenseAssignmentsGetWithProductId:(NSString *)productId
                                                     skuId:(NSString *)skuId
                                                    userId:(NSString *)userId {
  NSString *methodName = @"licensing.licenseAssignments.get";
  GTLQueryLicensing *query = [self queryWithMethodName:methodName];
  query.productId = productId;
  query.skuId = skuId;
  query.userId = userId;
  query.expectedObjectClass = [GTLLicensingLicenseAssignment class];
  return query;
}

+ (instancetype)queryForLicenseAssignmentsInsertWithObject:(GTLLicensingLicenseAssignmentInsert *)object
                                                 productId:(NSString *)productId
                                                     skuId:(NSString *)skuId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"licensing.licenseAssignments.insert";
  GTLQueryLicensing *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.productId = productId;
  query.skuId = skuId;
  query.expectedObjectClass = [GTLLicensingLicenseAssignment class];
  return query;
}

+ (instancetype)queryForLicenseAssignmentsListForProductWithProductId:(NSString *)productId
                                                           customerId:(NSString *)customerId {
  NSString *methodName = @"licensing.licenseAssignments.listForProduct";
  GTLQueryLicensing *query = [self queryWithMethodName:methodName];
  query.productId = productId;
  query.customerId = customerId;
  query.expectedObjectClass = [GTLLicensingLicenseAssignmentList class];
  return query;
}

+ (instancetype)queryForLicenseAssignmentsListForProductAndSkuWithProductId:(NSString *)productId
                                                                      skuId:(NSString *)skuId
                                                                 customerId:(NSString *)customerId {
  NSString *methodName = @"licensing.licenseAssignments.listForProductAndSku";
  GTLQueryLicensing *query = [self queryWithMethodName:methodName];
  query.productId = productId;
  query.skuId = skuId;
  query.customerId = customerId;
  query.expectedObjectClass = [GTLLicensingLicenseAssignmentList class];
  return query;
}

+ (instancetype)queryForLicenseAssignmentsPatchWithObject:(GTLLicensingLicenseAssignment *)object
                                                productId:(NSString *)productId
                                                    skuId:(NSString *)skuId
                                                   userId:(NSString *)userId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"licensing.licenseAssignments.patch";
  GTLQueryLicensing *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.productId = productId;
  query.skuId = skuId;
  query.userId = userId;
  query.expectedObjectClass = [GTLLicensingLicenseAssignment class];
  return query;
}

+ (instancetype)queryForLicenseAssignmentsUpdateWithObject:(GTLLicensingLicenseAssignment *)object
                                                 productId:(NSString *)productId
                                                     skuId:(NSString *)skuId
                                                    userId:(NSString *)userId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"licensing.licenseAssignments.update";
  GTLQueryLicensing *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.productId = productId;
  query.skuId = skuId;
  query.userId = userId;
  query.expectedObjectClass = [GTLLicensingLicenseAssignment class];
  return query;
}

@end

/* Copyright (c) 2011 Google Inc.
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
//  GTLQueryBooks.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://code.google.com/apis/books/docs/v1/getting_started.html
// Classes:
//   GTLQueryBooks (16 custom class methods, 23 custom properties)

#import "GTLQueryBooks.h"

#import "GTLBooksAnnotation.h"
#import "GTLBooksAnnotations.h"
#import "GTLBooksBookshelf.h"
#import "GTLBooksBookshelves.h"
#import "GTLBooksVolume.h"
#import "GTLBooksVolumes.h"

@implementation GTLQueryBooks

@dynamic annotationId, contentVersion, country, download, fields, filter,
         langRestrict, layerId, libraryRestrict, maxResults, orderBy, pageIds,
         pageToken, partner, printType, projection, q, shelf, showPreorders,
         source, startIndex, userId, volumeId;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[NSString class]
                                forKey:@"pageIds"];
  return map;
}

#pragma mark -
#pragma mark "bookshelves" methods
// These create a GTLQueryBooks object.

+ (id)queryForBookshelvesGetWithUserId:(NSString *)userId
                                 shelf:(NSString *)shelf {
  NSString *methodName = @"books.bookshelves.get";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.shelf = shelf;
  query.expectedObjectClass = [GTLBooksBookshelf class];
  return query;
}

+ (id)queryForBookshelvesListWithUserId:(NSString *)userId {
  NSString *methodName = @"books.bookshelves.list";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.expectedObjectClass = [GTLBooksBookshelves class];
  return query;
}

#pragma mark -
#pragma mark "bookshelves.volumes" methods
// These create a GTLQueryBooks object.

+ (id)queryForBookshelvesVolumesListWithUserId:(NSString *)userId
                                         shelf:(NSString *)shelf {
  NSString *methodName = @"books.bookshelves.volumes.list";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.userId = userId;
  query.shelf = shelf;
  query.expectedObjectClass = [GTLBooksVolumes class];
  return query;
}

#pragma mark -
#pragma mark "mylibrary.annotations" methods
// These create a GTLQueryBooks object.

+ (id)queryForMylibraryAnnotationsDeleteWithAnnotationId:(NSString *)annotationId {
  NSString *methodName = @"books.mylibrary.annotations.delete";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.annotationId = annotationId;
  return query;
}

+ (id)queryForMylibraryAnnotationsGetWithAnnotationId:(NSString *)annotationId {
  NSString *methodName = @"books.mylibrary.annotations.get";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.annotationId = annotationId;
  query.expectedObjectClass = [GTLBooksAnnotation class];
  return query;
}

+ (id)queryForMylibraryAnnotationsInsertWithObject:(GTLBooksAnnotation *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"books.mylibrary.annotations.insert";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLBooksAnnotation class];
  return query;
}

+ (id)queryForMylibraryAnnotationsList {
  NSString *methodName = @"books.mylibrary.annotations.list";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLBooksAnnotations class];
  return query;
}

+ (id)queryForMylibraryAnnotationsUpdateWithObject:(GTLBooksAnnotation *)object
                                      annotationId:(NSString *)annotationId {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"books.mylibrary.annotations.update";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.annotationId = annotationId;
  query.expectedObjectClass = [GTLBooksAnnotation class];
  return query;
}

#pragma mark -
#pragma mark "mylibrary.bookshelves" methods
// These create a GTLQueryBooks object.

+ (id)queryForMylibraryBookshelvesAddVolumeWithShelf:(NSString *)shelf
                                            volumeId:(NSString *)volumeId {
  NSString *methodName = @"books.mylibrary.bookshelves.addVolume";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.shelf = shelf;
  query.volumeId = volumeId;
  return query;
}

+ (id)queryForMylibraryBookshelvesClearVolumesWithShelf:(NSString *)shelf {
  NSString *methodName = @"books.mylibrary.bookshelves.clearVolumes";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.shelf = shelf;
  return query;
}

+ (id)queryForMylibraryBookshelvesGetWithShelf:(NSString *)shelf {
  NSString *methodName = @"books.mylibrary.bookshelves.get";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.shelf = shelf;
  query.expectedObjectClass = [GTLBooksBookshelf class];
  return query;
}

+ (id)queryForMylibraryBookshelvesList {
  NSString *methodName = @"books.mylibrary.bookshelves.list";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLBooksBookshelves class];
  return query;
}

+ (id)queryForMylibraryBookshelvesRemoveVolumeWithShelf:(NSString *)shelf
                                               volumeId:(NSString *)volumeId {
  NSString *methodName = @"books.mylibrary.bookshelves.removeVolume";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.shelf = shelf;
  query.volumeId = volumeId;
  return query;
}

#pragma mark -
#pragma mark "mylibrary.bookshelves.volumes" methods
// These create a GTLQueryBooks object.

+ (id)queryForMylibraryBookshelvesVolumesList {
  NSString *methodName = @"books.mylibrary.bookshelves.volumes.list";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLBooksVolumes class];
  return query;
}

#pragma mark -
#pragma mark "volumes" methods
// These create a GTLQueryBooks object.

+ (id)queryForVolumesGetWithVolumeId:(NSString *)volumeId {
  NSString *methodName = @"books.volumes.get";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.volumeId = volumeId;
  query.expectedObjectClass = [GTLBooksVolume class];
  return query;
}

+ (id)queryForVolumesListWithQ:(NSString *)q {
  NSString *methodName = @"books.volumes.list";
  GTLQueryBooks *query = [self queryWithMethodName:methodName];
  query.q = q;
  query.expectedObjectClass = [GTLBooksVolumes class];
  return query;
}

@end

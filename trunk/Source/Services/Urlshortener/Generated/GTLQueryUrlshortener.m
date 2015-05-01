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
//  GTLQueryUrlshortener.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   URL Shortener API (urlshortener/v1)
// Description:
//   Lets you create, inspect, and manage goo.gl short URLs
// Documentation:
//   https://developers.google.com/url-shortener/v1/getting_started
// Classes:
//   GTLQueryUrlshortener (3 custom class methods, 4 custom properties)

#import "GTLQueryUrlshortener.h"

#import "GTLUrlshortenerUrl.h"
#import "GTLUrlshortenerUrlHistory.h"

@implementation GTLQueryUrlshortener

@dynamic fields, projection, shortUrl, startToken;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map = @{
    @"startToken" : @"start-token"
  };
  return map;
}

#pragma mark -
#pragma mark "url" methods
// These create a GTLQueryUrlshortener object.

+ (instancetype)queryForUrlGetWithShortUrl:(NSString *)shortUrl {
  NSString *methodName = @"urlshortener.url.get";
  GTLQueryUrlshortener *query = [self queryWithMethodName:methodName];
  query.shortUrl = shortUrl;
  query.expectedObjectClass = [GTLUrlshortenerUrl class];
  return query;
}

+ (instancetype)queryForUrlInsertWithObject:(GTLUrlshortenerUrl *)object {
  if (object == nil) {
    GTL_DEBUG_ASSERT(object != nil, @"%@ got a nil object", NSStringFromSelector(_cmd));
    return nil;
  }
  NSString *methodName = @"urlshortener.url.insert";
  GTLQueryUrlshortener *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.expectedObjectClass = [GTLUrlshortenerUrl class];
  return query;
}

+ (instancetype)queryForUrlList {
  NSString *methodName = @"urlshortener.url.list";
  GTLQueryUrlshortener *query = [self queryWithMethodName:methodName];
  query.expectedObjectClass = [GTLUrlshortenerUrlHistory class];
  return query;
}

@end

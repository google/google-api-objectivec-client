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
//  GTLBooksLayerDictData.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://developers.google.com/books/docs/v1/getting_started
// Classes:
//   GTLBooksLayerDictData (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataCommon (0 custom class methods, 1 custom properties)
//   GTLBooksLayerDictDataDict (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictSource (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItem (0 custom class methods, 4 custom properties)
//   GTLBooksLayerDictDataDictWordsItemDerivativesItem (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItemExamplesItem (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItemSensesItem (0 custom class methods, 8 custom properties)
//   GTLBooksLayerDictDataDictWordsItemSource (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItemDerivativesItemSource (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItemExamplesItemSource (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItemSensesItemConjugationsItem (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItem (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItemSensesItemSource (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItem (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItem (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItemSource (0 custom class methods, 2 custom properties)
//   GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItemSource (0 custom class methods, 2 custom properties)

#import "GTLBooksLayerDictData.h"

// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictData
//

@implementation GTLBooksLayerDictData
@dynamic common, dict;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataCommon
//

@implementation GTLBooksLayerDictDataCommon
@dynamic title;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDict
//

@implementation GTLBooksLayerDictDataDict
@dynamic source, words;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLBooksLayerDictDataDictWordsItem class]
                                forKey:@"words"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictSource
//

@implementation GTLBooksLayerDictDataDictSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItem
//

@implementation GTLBooksLayerDictDataDictWordsItem
@dynamic derivatives, examples, senses, source;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLBooksLayerDictDataDictWordsItemDerivativesItem class], @"derivatives",
      [GTLBooksLayerDictDataDictWordsItemExamplesItem class], @"examples",
      [GTLBooksLayerDictDataDictWordsItemSensesItem class], @"senses",
      nil];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemDerivativesItem
//

@implementation GTLBooksLayerDictDataDictWordsItemDerivativesItem
@dynamic source, text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemExamplesItem
//

@implementation GTLBooksLayerDictDataDictWordsItemExamplesItem
@dynamic source, text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItem
//

@implementation GTLBooksLayerDictDataDictWordsItemSensesItem
@dynamic conjugations, definitions, partOfSpeech, pronunciation,
         pronunciationUrl, source, syllabification, synonyms;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      [GTLBooksLayerDictDataDictWordsItemSensesItemConjugationsItem class], @"conjugations",
      [GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItem class], @"definitions",
      [GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItem class], @"synonyms",
      nil];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSource
//

@implementation GTLBooksLayerDictDataDictWordsItemSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemDerivativesItemSource
//

@implementation GTLBooksLayerDictDataDictWordsItemDerivativesItemSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemExamplesItemSource
//

@implementation GTLBooksLayerDictDataDictWordsItemExamplesItemSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemConjugationsItem
//

@implementation GTLBooksLayerDictDataDictWordsItemSensesItemConjugationsItem
@dynamic type, value;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItem
//

@implementation GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItem
@dynamic definition, examples;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObject:[GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItem class]
                                forKey:@"examples"];
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemSource
//

@implementation GTLBooksLayerDictDataDictWordsItemSensesItemSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItem
//

@implementation GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItem
@dynamic source, text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItem
//

@implementation GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItem
@dynamic source, text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItemSource
//

@implementation GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItemSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItemSource
//

@implementation GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItemSource
@dynamic attribution, url;
@end

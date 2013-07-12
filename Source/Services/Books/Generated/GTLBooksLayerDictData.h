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
//  GTLBooksLayerDictData.h
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

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBooksLayerDictDataCommon;
@class GTLBooksLayerDictDataDict;
@class GTLBooksLayerDictDataDictSource;
@class GTLBooksLayerDictDataDictWordsItem;
@class GTLBooksLayerDictDataDictWordsItemDerivativesItem;
@class GTLBooksLayerDictDataDictWordsItemDerivativesItemSource;
@class GTLBooksLayerDictDataDictWordsItemExamplesItem;
@class GTLBooksLayerDictDataDictWordsItemExamplesItemSource;
@class GTLBooksLayerDictDataDictWordsItemSensesItem;
@class GTLBooksLayerDictDataDictWordsItemSensesItemConjugationsItem;
@class GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItem;
@class GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItem;
@class GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItemSource;
@class GTLBooksLayerDictDataDictWordsItemSensesItemSource;
@class GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItem;
@class GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItemSource;
@class GTLBooksLayerDictDataDictWordsItemSource;

// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictData
//

@interface GTLBooksLayerDictData : GTLObject
@property (retain) GTLBooksLayerDictDataCommon *common;
@property (retain) GTLBooksLayerDictDataDict *dict;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataCommon
//

@interface GTLBooksLayerDictDataCommon : GTLObject

// The display title and localized canonical name to use when searching for this
// entity on Google search.
@property (copy) NSString *title;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDict
//

@interface GTLBooksLayerDictDataDict : GTLObject

// The source, url and attribution for this dictionary data.
@property (retain) GTLBooksLayerDictDataDictSource *source;

@property (retain) NSArray *words;  // of GTLBooksLayerDictDataDictWordsItem
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictSource
//

@interface GTLBooksLayerDictDataDictSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItem
//

@interface GTLBooksLayerDictDataDictWordsItem : GTLObject
@property (retain) NSArray *derivatives;  // of GTLBooksLayerDictDataDictWordsItemDerivativesItem
@property (retain) NSArray *examples;  // of GTLBooksLayerDictDataDictWordsItemExamplesItem
@property (retain) NSArray *senses;  // of GTLBooksLayerDictDataDictWordsItemSensesItem

// The words with different meanings but not related words, e.g. "go" (game) and
// "go" (verb).
@property (retain) GTLBooksLayerDictDataDictWordsItemSource *source;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemDerivativesItem
//

@interface GTLBooksLayerDictDataDictWordsItemDerivativesItem : GTLObject
@property (retain) GTLBooksLayerDictDataDictWordsItemDerivativesItemSource *source;
@property (copy) NSString *text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemExamplesItem
//

@interface GTLBooksLayerDictDataDictWordsItemExamplesItem : GTLObject
@property (retain) GTLBooksLayerDictDataDictWordsItemExamplesItemSource *source;
@property (copy) NSString *text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItem
//

@interface GTLBooksLayerDictDataDictWordsItemSensesItem : GTLObject
@property (retain) NSArray *conjugations;  // of GTLBooksLayerDictDataDictWordsItemSensesItemConjugationsItem
@property (retain) NSArray *definitions;  // of GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItem
@property (copy) NSString *partOfSpeech;
@property (copy) NSString *pronunciation;
@property (copy) NSString *pronunciationUrl;
@property (retain) GTLBooksLayerDictDataDictWordsItemSensesItemSource *source;
@property (copy) NSString *syllabification;
@property (retain) NSArray *synonyms;  // of GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItem
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSource
//

@interface GTLBooksLayerDictDataDictWordsItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemDerivativesItemSource
//

@interface GTLBooksLayerDictDataDictWordsItemDerivativesItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemExamplesItemSource
//

@interface GTLBooksLayerDictDataDictWordsItemExamplesItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemConjugationsItem
//

@interface GTLBooksLayerDictDataDictWordsItemSensesItemConjugationsItem : GTLObject
@property (copy) NSString *type;
@property (copy) NSString *value;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItem
//

@interface GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItem : GTLObject
@property (copy) NSString *definition;
@property (retain) NSArray *examples;  // of GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItem
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemSource
//

@interface GTLBooksLayerDictDataDictWordsItemSensesItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItem
//

@interface GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItem : GTLObject
@property (retain) GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItemSource *source;
@property (copy) NSString *text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItem
//

@interface GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItem : GTLObject
@property (retain) GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItemSource *source;
@property (copy) NSString *text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItemSource
//

@interface GTLBooksLayerDictDataDictWordsItemSensesItemSynonymsItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItemSource
//

@interface GTLBooksLayerDictDataDictWordsItemSensesItemDefinitionsItemExamplesItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end

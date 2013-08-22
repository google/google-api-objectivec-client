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
//  GTLBooksDictlayerdata.h
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
//   GTLBooksDictlayerdata (0 custom class methods, 3 custom properties)
//   GTLBooksDictlayerdataCommon (0 custom class methods, 1 custom properties)
//   GTLBooksDictlayerdataDict (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictSource (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItem (0 custom class methods, 4 custom properties)
//   GTLBooksDictlayerdataDictWordsItemDerivativesItem (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItemExamplesItem (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItemSensesItem (0 custom class methods, 8 custom properties)
//   GTLBooksDictlayerdataDictWordsItemSource (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItemDerivativesItemSource (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItemExamplesItemSource (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItemSensesItemConjugationsItem (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItem (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItemSensesItemSource (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItem (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItem (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItemSource (0 custom class methods, 2 custom properties)
//   GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItemSource (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBooksDictlayerdataCommon;
@class GTLBooksDictlayerdataDict;
@class GTLBooksDictlayerdataDictSource;
@class GTLBooksDictlayerdataDictWordsItem;
@class GTLBooksDictlayerdataDictWordsItemDerivativesItem;
@class GTLBooksDictlayerdataDictWordsItemDerivativesItemSource;
@class GTLBooksDictlayerdataDictWordsItemExamplesItem;
@class GTLBooksDictlayerdataDictWordsItemExamplesItemSource;
@class GTLBooksDictlayerdataDictWordsItemSensesItem;
@class GTLBooksDictlayerdataDictWordsItemSensesItemConjugationsItem;
@class GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItem;
@class GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItem;
@class GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItemSource;
@class GTLBooksDictlayerdataDictWordsItemSensesItemSource;
@class GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItem;
@class GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItemSource;
@class GTLBooksDictlayerdataDictWordsItemSource;

// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdata
//

@interface GTLBooksDictlayerdata : GTLObject
@property (retain) GTLBooksDictlayerdataCommon *common;
@property (retain) GTLBooksDictlayerdataDict *dict;
@property (copy) NSString *kind;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataCommon
//

@interface GTLBooksDictlayerdataCommon : GTLObject

// The display title and localized canonical name to use when searching for this
// entity on Google search.
@property (copy) NSString *title;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDict
//

@interface GTLBooksDictlayerdataDict : GTLObject

// The source, url and attribution for this dictionary data.
@property (retain) GTLBooksDictlayerdataDictSource *source;

@property (retain) NSArray *words;  // of GTLBooksDictlayerdataDictWordsItem
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictSource
//

@interface GTLBooksDictlayerdataDictSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItem
//

@interface GTLBooksDictlayerdataDictWordsItem : GTLObject
@property (retain) NSArray *derivatives;  // of GTLBooksDictlayerdataDictWordsItemDerivativesItem
@property (retain) NSArray *examples;  // of GTLBooksDictlayerdataDictWordsItemExamplesItem
@property (retain) NSArray *senses;  // of GTLBooksDictlayerdataDictWordsItemSensesItem

// The words with different meanings but not related words, e.g. "go" (game) and
// "go" (verb).
@property (retain) GTLBooksDictlayerdataDictWordsItemSource *source;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemDerivativesItem
//

@interface GTLBooksDictlayerdataDictWordsItemDerivativesItem : GTLObject
@property (retain) GTLBooksDictlayerdataDictWordsItemDerivativesItemSource *source;
@property (copy) NSString *text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemExamplesItem
//

@interface GTLBooksDictlayerdataDictWordsItemExamplesItem : GTLObject
@property (retain) GTLBooksDictlayerdataDictWordsItemExamplesItemSource *source;
@property (copy) NSString *text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItem
//

@interface GTLBooksDictlayerdataDictWordsItemSensesItem : GTLObject
@property (retain) NSArray *conjugations;  // of GTLBooksDictlayerdataDictWordsItemSensesItemConjugationsItem
@property (retain) NSArray *definitions;  // of GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItem
@property (copy) NSString *partOfSpeech;
@property (copy) NSString *pronunciation;
@property (copy) NSString *pronunciationUrl;
@property (retain) GTLBooksDictlayerdataDictWordsItemSensesItemSource *source;
@property (copy) NSString *syllabification;
@property (retain) NSArray *synonyms;  // of GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItem
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSource
//

@interface GTLBooksDictlayerdataDictWordsItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemDerivativesItemSource
//

@interface GTLBooksDictlayerdataDictWordsItemDerivativesItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemExamplesItemSource
//

@interface GTLBooksDictlayerdataDictWordsItemExamplesItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemConjugationsItem
//

@interface GTLBooksDictlayerdataDictWordsItemSensesItemConjugationsItem : GTLObject
@property (copy) NSString *type;
@property (copy) NSString *value;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItem
//

@interface GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItem : GTLObject
@property (copy) NSString *definition;
@property (retain) NSArray *examples;  // of GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItem
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemSource
//

@interface GTLBooksDictlayerdataDictWordsItemSensesItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItem
//

@interface GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItem : GTLObject
@property (retain) GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItemSource *source;
@property (copy) NSString *text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItem
//

@interface GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItem : GTLObject
@property (retain) GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItemSource *source;
@property (copy) NSString *text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItemSource
//

@interface GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItemSource
//

@interface GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItemSource : GTLObject
@property (copy) NSString *attribution;
@property (copy) NSString *url;
@end

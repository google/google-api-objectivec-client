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
//  GTLBooksDictlayerdata.m
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

#import "GTLBooksDictlayerdata.h"

// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdata
//

@implementation GTLBooksDictlayerdata
@dynamic common, dict, kind;

+ (void)load {
  [self registerObjectClassForKind:@"books#dictlayerdata"];
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataCommon
//

@implementation GTLBooksDictlayerdataCommon
@dynamic title;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDict
//

@implementation GTLBooksDictlayerdataDict
@dynamic source, words;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"words" : [GTLBooksDictlayerdataDictWordsItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictSource
//

@implementation GTLBooksDictlayerdataDictSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItem
//

@implementation GTLBooksDictlayerdataDictWordsItem
@dynamic derivatives, examples, senses, source;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"derivatives" : [GTLBooksDictlayerdataDictWordsItemDerivativesItem class],
    @"examples" : [GTLBooksDictlayerdataDictWordsItemExamplesItem class],
    @"senses" : [GTLBooksDictlayerdataDictWordsItemSensesItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemDerivativesItem
//

@implementation GTLBooksDictlayerdataDictWordsItemDerivativesItem
@dynamic source, text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemExamplesItem
//

@implementation GTLBooksDictlayerdataDictWordsItemExamplesItem
@dynamic source, text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItem
//

@implementation GTLBooksDictlayerdataDictWordsItemSensesItem
@dynamic conjugations, definitions, partOfSpeech, pronunciation,
         pronunciationUrl, source, syllabification, synonyms;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"conjugations" : [GTLBooksDictlayerdataDictWordsItemSensesItemConjugationsItem class],
    @"definitions" : [GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItem class],
    @"synonyms" : [GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSource
//

@implementation GTLBooksDictlayerdataDictWordsItemSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemDerivativesItemSource
//

@implementation GTLBooksDictlayerdataDictWordsItemDerivativesItemSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemExamplesItemSource
//

@implementation GTLBooksDictlayerdataDictWordsItemExamplesItemSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemConjugationsItem
//

@implementation GTLBooksDictlayerdataDictWordsItemSensesItemConjugationsItem
@dynamic type, value;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItem
//

@implementation GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItem
@dynamic definition, examples;

+ (NSDictionary *)arrayPropertyToClassMap {
  NSDictionary *map = @{
    @"examples" : [GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItem class]
  };
  return map;
}

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemSource
//

@implementation GTLBooksDictlayerdataDictWordsItemSensesItemSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItem
//

@implementation GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItem
@dynamic source, text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItem
//

@implementation GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItem
@dynamic source, text;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItemSource
//

@implementation GTLBooksDictlayerdataDictWordsItemSensesItemSynonymsItemSource
@dynamic attribution, url;
@end


// ----------------------------------------------------------------------------
//
//   GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItemSource
//

@implementation GTLBooksDictlayerdataDictWordsItemSensesItemDefinitionsItemExamplesItemSource
@dynamic attribution, url;
@end

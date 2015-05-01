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
//  GTLBooksUsersettings.h
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
//   GTLBooksUsersettings (0 custom class methods, 2 custom properties)
//   GTLBooksUsersettingsNotesExport (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLBooksUsersettingsNotesExport;

// ----------------------------------------------------------------------------
//
//   GTLBooksUsersettings
//

@interface GTLBooksUsersettings : GTLObject

// Resource type.
@property (nonatomic, copy) NSString *kind;

// User settings in sub-objects, each for different purposes.
@property (nonatomic, retain) GTLBooksUsersettingsNotesExport *notesExport;

@end


// ----------------------------------------------------------------------------
//
//   GTLBooksUsersettingsNotesExport
//

@interface GTLBooksUsersettingsNotesExport : GTLObject
@property (nonatomic, copy) NSString *folderName;
@property (nonatomic, retain) NSNumber *isEnabled;  // boolValue
@end

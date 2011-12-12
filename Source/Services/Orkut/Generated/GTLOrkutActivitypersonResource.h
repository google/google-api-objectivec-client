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
//  GTLOrkutActivitypersonResource.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Orkut API (orkut/v2)
// Description:
//   Lets you manage activities, comments and badges in Orkut. More stuff coming
//   in time.
// Documentation:
//   http://code.google.com/apis/orkut/v2/reference.html
// Classes:
//   GTLOrkutActivitypersonResource (0 custom class methods, 6 custom properties)
//   GTLOrkutActivitypersonResourceImage (0 custom class methods, 1 custom properties)
//   GTLOrkutActivitypersonResourceName (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutActivitypersonResourceImage;
@class GTLOrkutActivitypersonResourceName;

// ----------------------------------------------------------------------------
//
//   GTLOrkutActivitypersonResource
//

@interface GTLOrkutActivitypersonResource : GTLObject

// The person's date of birth, represented as YYYY-MM-DD.
@property (copy) NSString *birthday;

// The person's gender. Values include "male", "female", and "other".
@property (copy) NSString *gender;

// The person's opensocial ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// The person's profile photo. This is adapted from Google+ and was originaly
// introduced as extra OpenSocial convenience fields.
@property (retain) GTLOrkutActivitypersonResourceImage *image;

// An object that encapsulates the individual components of a person's name.
@property (retain) GTLOrkutActivitypersonResourceName *name;

// The person's profile url. This is adapted from Google+ and was originaly
// introduced as extra OpenSocial convenience fields.
@property (copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLOrkutActivitypersonResourceImage
//

@interface GTLOrkutActivitypersonResourceImage : GTLObject

// The URL of the person's profile photo.
@property (copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLOrkutActivitypersonResourceName
//

@interface GTLOrkutActivitypersonResourceName : GTLObject

// The family name (last name) of this person.
@property (copy) NSString *familyName;

// The given name (first name) of this person.
@property (copy) NSString *givenName;

@end

/* Copyright (c) 2012 Google Inc.
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
//  GTLOrkutAuthorResource.h
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
//   GTLOrkutAuthorResource (0 custom class methods, 4 custom properties)
//   GTLOrkutAuthorResourceImage (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutAuthorResourceImage;

// ----------------------------------------------------------------------------
//
//   GTLOrkutAuthorResource
//

@interface GTLOrkutAuthorResource : GTLObject

// The name of the author, suitable for display.
@property (copy) NSString *displayName;

// Unique identifier of the person who posted the comment. This is the person's
// OpenSocial ID.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Image data about the author.
@property (retain) GTLOrkutAuthorResourceImage *image;

// The URL of the author who posted the comment [not yet implemented]
@property (copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLOrkutAuthorResourceImage
//

@interface GTLOrkutAuthorResourceImage : GTLObject

// A URL that points to a thumbnail photo of the author.
@property (copy) NSString *url;

@end

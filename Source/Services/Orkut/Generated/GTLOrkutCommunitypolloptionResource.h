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
//  GTLOrkutCommunitypolloptionResource.h
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
//   GTLOrkutCommunitypolloptionResource (0 custom class methods, 4 custom properties)
//   GTLOrkutCommunitypolloptionResourceImage (0 custom class methods, 1 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLOrkutCommunitypolloptionResourceImage;

// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunitypolloptionResource
//

@interface GTLOrkutCommunitypolloptionResource : GTLObject

// The option description.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (copy) NSString *descriptionProperty;

// Image data about the poll option. Field is omitted if no image exists.
@property (retain) GTLOrkutCommunitypolloptionResourceImage *image;

// The total number of votes that this option received.
@property (retain) NSNumber *numberOfVotes;  // intValue

// The poll option ID
@property (retain) NSNumber *optionId;  // intValue

@end


// ----------------------------------------------------------------------------
//
//   GTLOrkutCommunitypolloptionResourceImage
//

@interface GTLOrkutCommunitypolloptionResourceImage : GTLObject

// A URL that points to an image of the poll question.
@property (copy) NSString *url;

@end

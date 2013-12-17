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
//  GTLAdSenseAdStyle.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Management API (adsense/v1.4)
// Description:
//   Gives AdSense publishers access to their inventory and the ability to
//   generate reports
// Documentation:
//   https://developers.google.com/adsense/management/
// Classes:
//   GTLAdSenseAdStyle (0 custom class methods, 4 custom properties)
//   GTLAdSenseAdStyleColors (0 custom class methods, 5 custom properties)
//   GTLAdSenseAdStyleFont (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdSenseAdStyleColors;
@class GTLAdSenseAdStyleFont;

// ----------------------------------------------------------------------------
//
//   GTLAdSenseAdStyle
//

@interface GTLAdSenseAdStyle : GTLObject

// The colors which are included in the style. These are represented as six
// hexadecimal characters, similar to HTML color codes, but without the leading
// hash.
@property (retain) GTLAdSenseAdStyleColors *colors;

// The style of the corners in the ad.
@property (copy) NSString *corners;

// The font which is included in the style.
@property (retain) GTLAdSenseAdStyleFont *font;

// Kind this is, in this case adsense#adStyle.
@property (copy) NSString *kind;

@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseAdStyleColors
//

@interface GTLAdSenseAdStyleColors : GTLObject

// The color of the ad background.
@property (copy) NSString *background;

// The color of the ad border.
@property (copy) NSString *border;

// The color of the ad text.
@property (copy) NSString *text;

// The color of the ad title.
@property (copy) NSString *title;

// The color of the ad url.
@property (copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseAdStyleFont
//

@interface GTLAdSenseAdStyleFont : GTLObject

// The family of the font.
@property (copy) NSString *family;

// The size of the font.
@property (copy) NSString *size;

@end

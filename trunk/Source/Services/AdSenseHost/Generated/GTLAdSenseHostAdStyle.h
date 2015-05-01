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
//  GTLAdSenseHostAdStyle.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   AdSense Host API (adsensehost/v4.1)
// Description:
//   Gives AdSense Hosts access to report generation, ad code generation, and
//   publisher management capabilities.
// Documentation:
//   https://developers.google.com/adsense/host/
// Classes:
//   GTLAdSenseHostAdStyle (0 custom class methods, 4 custom properties)
//   GTLAdSenseHostAdStyleColors (0 custom class methods, 5 custom properties)
//   GTLAdSenseHostAdStyleFont (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLAdSenseHostAdStyleColors;
@class GTLAdSenseHostAdStyleFont;

// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAdStyle
//

@interface GTLAdSenseHostAdStyle : GTLObject

// The colors included in the style. These are represented as six hexadecimal
// characters, similar to HTML color codes, but without the leading hash.
@property (nonatomic, retain) GTLAdSenseHostAdStyleColors *colors;

// The style of the corners in the ad. Possible values are SQUARE,
// SLIGHTLY_ROUNDED and VERY_ROUNDED.
@property (nonatomic, copy) NSString *corners;

// The font which is included in the style.
@property (nonatomic, retain) GTLAdSenseHostAdStyleFont *font;

// Kind this is, in this case adsensehost#adStyle.
@property (nonatomic, copy) NSString *kind;

@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAdStyleColors
//

@interface GTLAdSenseHostAdStyleColors : GTLObject

// The color of the ad background.
@property (nonatomic, copy) NSString *background;

// The color of the ad border.
@property (nonatomic, copy) NSString *border;

// The color of the ad text.
@property (nonatomic, copy) NSString *text;

// The color of the ad title.
@property (nonatomic, copy) NSString *title;

// The color of the ad url.
@property (nonatomic, copy) NSString *url;

@end


// ----------------------------------------------------------------------------
//
//   GTLAdSenseHostAdStyleFont
//

@interface GTLAdSenseHostAdStyleFont : GTLObject

// The family of the font. Possible values are: ACCOUNT_DEFAULT_FAMILY,
// ADSENSE_DEFAULT_FAMILY, ARIAL, TIMES and VERDANA.
@property (nonatomic, copy) NSString *family;

// The size of the font. Possible values are: ACCOUNT_DEFAULT_SIZE,
// ADSENSE_DEFAULT_SIZE, SMALL, MEDIUM and LARGE.
@property (nonatomic, copy) NSString *size;

@end

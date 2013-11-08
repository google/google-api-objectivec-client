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
//  GTLYouTubeContentRating.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   YouTube Data API (youtube/v3)
// Description:
//   Programmatic access to YouTube features.
// Documentation:
//   https://developers.google.com/youtube/v3
// Classes:
//   GTLYouTubeContentRating (0 custom class methods, 19 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

// ----------------------------------------------------------------------------
//
//   GTLYouTubeContentRating
//

// Ratings schemes. The country-specific ratings are mostly for movies and
// shows.

@interface GTLYouTubeContentRating : GTLObject

// Rating system in Australia - Australian Classification Board
@property (copy) NSString *acbRating;

// British Board of Film Classification
@property (copy) NSString *bbfcRating;

// Rating system for French Canadian TV - Regie du cinema
@property (copy) NSString *catvfrRating;

// Rating system for Canadian TV - Canadian TV Classification System
@property (copy) NSString *catvRating;

// Rating system in India - Central Board of Film Certification
@property (copy) NSString *cbfcRating;

// Canadian Home Video Rating System
@property (copy) NSString *chvrsRating;

// Rating system in Brazil - Department of Justice, Rating, Titles and
// Qualification
@property (copy) NSString *djctqRating;

// Rating system in Japan - Eiga Rinri Kanri Iinkai
@property (copy) NSString *eirinRating;

// Rating system in France - French Minister of Culture
@property (copy) NSString *fmocRating;

// Rating system in Germany - Voluntary Self Regulation of the Movie Industry
@property (copy) NSString *fskRating;

// Rating system in Spain - Instituto de Cinematografia y de las Artes
// Audiovisuales
@property (copy) NSString *icaaRating;

// Rating system in South Korea - Korea Media Rating Board
@property (copy) NSString *kmrbRating;

// Rating system in Italy - Ministero dei Beni e delle Attivita Culturali e del
// Turismo
@property (copy) NSString *mibacRating;

// Motion Picture Association of America rating for the content.
@property (copy) NSString *mpaaRating;

// Rating system in New Zealand - Office of Film and Literature Classification
@property (copy) NSString *oflcRating;

// Rating system in Mexico - General Directorate of Radio, Television and
// Cinematography
@property (copy) NSString *rtcRating;

// Rating system in Russia
@property (copy) NSString *russiaRating;

// TV Parental Guidelines rating of the content.
@property (copy) NSString *tvpgRating;

// Internal YouTube rating.
@property (copy) NSString *ytRating;

@end

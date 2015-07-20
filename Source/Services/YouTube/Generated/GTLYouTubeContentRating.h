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
//   GTLYouTubeContentRating (0 custom class methods, 64 custom properties)

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
// shows. NEXT_ID: 65

@interface GTLYouTubeContentRating : GTLObject

// Rating system in Australia - Australian Classification Board
@property (nonatomic, copy) NSString *acbRating;

// Rating system for Italy - Autorit� per le Garanzie nelle Comunicazioni
@property (nonatomic, copy) NSString *agcomRating;

// Rating system for Chile - Asociaci�n Nacional de Televisi�n
@property (nonatomic, copy) NSString *anatelRating;

// British Board of Film Classification
@property (nonatomic, copy) NSString *bbfcRating;

// Rating system for Thailand - Board of Filmand Video Censors
@property (nonatomic, copy) NSString *bfvcRating;

// Rating system for Austria - Bundesministerium f�r Unterricht, Kunst und
// Kultur
@property (nonatomic, copy) NSString *bmukkRating;

// Rating system for French Canadian TV - Regie du cinema
@property (nonatomic, copy) NSString *catvfrRating;

// Rating system for Canadian TV - Canadian TV Classification System
@property (nonatomic, copy) NSString *catvRating;

// Rating system in India - Central Board of Film Certification
@property (nonatomic, copy) NSString *cbfcRating;

// Rating system for Chile - Consejo de Calificaci�n Cinematogr�fica
@property (nonatomic, copy) NSString *cccRating;

// Rating system for Portugal - Comiss�o de Classifica��o de Espect�culos
@property (nonatomic, copy) NSString *cceRating;

// Rating system for Switzerland - Switzerland Rating System
@property (nonatomic, copy) NSString *chfilmRating;

// Canadian Home Video Rating System
@property (nonatomic, copy) NSString *chvrsRating;

// Rating system for Belgium - Belgium Rating System
@property (nonatomic, copy) NSString *cicfRating;

// Rating system for Romania - CONSILIUL NATIONAL AL AUDIOVIZUALULUI - CNA
@property (nonatomic, copy) NSString *cnaRating;

// Rating system for France - Conseil sup�rieur de l?audiovisuel
@property (nonatomic, copy) NSString *csaRating;

// Rating system for Luxembourg - Commission de surveillance de la
// classification des films
@property (nonatomic, copy) NSString *cscfRating;

// Rating system for Czech republic - Czech republic Rating System
@property (nonatomic, copy) NSString *czfilmRating;

// Rating system in Brazil - Department of Justice, Rating, Titles and
// Qualification
@property (nonatomic, copy) NSString *djctqRating;

@property (nonatomic, retain) NSArray *djctqRatingReasons;  // of NSString

// Rating system for Estonia - Estonia Rating System
@property (nonatomic, copy) NSString *eefilmRating;

// Rating system for Egypt - Egypt Rating System
@property (nonatomic, copy) NSString *egfilmRating;

// Rating system in Japan - Eiga Rinri Kanri Iinkai
@property (nonatomic, copy) NSString *eirinRating;

// Rating system for Malaysia - Film Censorship Board of Malaysia
@property (nonatomic, copy) NSString *fcbmRating;

// Rating system for Hong kong - Office for Film, Newspaper and Article
// Administration
@property (nonatomic, copy) NSString *fcoRating;

// Rating system in France - French Minister of Culture
@property (nonatomic, copy) NSString *fmocRating;

// Rating system for South africa - Film & Publication Board
@property (nonatomic, copy) NSString *fpbRating;

// Rating system in Germany - Voluntary Self Regulation of the Movie Industry
@property (nonatomic, copy) NSString *fskRating;

// Rating system for Greece - Greece Rating System
@property (nonatomic, copy) NSString *grfilmRating;

// Rating system in Spain - Instituto de Cinematografia y de las Artes
// Audiovisuales
@property (nonatomic, copy) NSString *icaaRating;

// Rating system in Ireland - Irish Film Classification Office
@property (nonatomic, copy) NSString *ifcoRating;

// Rating system for Israel - Israel Rating System
@property (nonatomic, copy) NSString *ilfilmRating;

// Rating system for Argentina - Instituto Nacional de Cine y Artes
// Audiovisuales
@property (nonatomic, copy) NSString *incaaRating;

// Rating system for Kenya - Kenya Film Classification Board
@property (nonatomic, copy) NSString *kfcbRating;

// Rating system for Netherlands - Nederlands Instituut voor de Classificatie
// van Audiovisuele Media
@property (nonatomic, copy) NSString *kijkwijzerRating;

// Rating system in South Korea - Korea Media Rating Board
@property (nonatomic, copy) NSString *kmrbRating;

// Rating system for Indonesia - Lembaga Sensor Film
@property (nonatomic, copy) NSString *lsfRating;

// Rating system for Malta - Film Age-Classification Board
@property (nonatomic, copy) NSString *mccaaRating;

// Rating system for Denmark - The Media Council for Children and Young People
@property (nonatomic, copy) NSString *mccypRating;

// Rating system for Singapore - Media Development Authority
@property (nonatomic, copy) NSString *mdaRating;

// Rating system for Norway - Medietilsynet
@property (nonatomic, copy) NSString *medietilsynetRating;

// Rating system for Finland - Finnish Centre for Media Education and
// Audiovisual Media
@property (nonatomic, copy) NSString *mekuRating;

// Rating system in Italy - Ministero dei Beni e delle Attivita Culturali e del
// Turismo
@property (nonatomic, copy) NSString *mibacRating;

// Rating system for Colombia - MoC
@property (nonatomic, copy) NSString *mocRating;

// Rating system for Taiwan - Ministry of Culture - Tawan
@property (nonatomic, copy) NSString *moctwRating;

// Motion Picture Association of America rating for the content.
@property (nonatomic, copy) NSString *mpaaRating;

// Rating system for Philippines - MOVIE AND TELEVISION REVIEW AND
// CLASSIFICATION BOARD
@property (nonatomic, copy) NSString *mtrcbRating;

// Rating system for Poland - National Broadcasting Council
@property (nonatomic, copy) NSString *nbcplRating;

// Rating system for Maldives - National Bureau of Classification
@property (nonatomic, copy) NSString *nbcRating;

// Rating system for Bulgaria - National Film Centre
@property (nonatomic, copy) NSString *nfrcRating;

// Rating system for Nigeria - National Film and Video Censors Board
@property (nonatomic, copy) NSString *nfvcbRating;

// Rating system for Latvia - National Film Center of Latvia
@property (nonatomic, copy) NSString *nkclvRating;

// Rating system in New Zealand - Office of Film and Literature Classification
@property (nonatomic, copy) NSString *oflcRating;

// Rating system for Peru - Peru Rating System
@property (nonatomic, copy) NSString *pefilmRating;

// Rating system for Hungary - Rating Committee of the National Office of Film
@property (nonatomic, copy) NSString *rcnofRating;

// Rating system for Venezuela - SiBCI
@property (nonatomic, copy) NSString *resorteviolenciaRating;

// Rating system in Mexico - General Directorate of Radio, Television and
// Cinematography
@property (nonatomic, copy) NSString *rtcRating;

// Rating system for Ireland - Raidi� Teilif�s �ireann
@property (nonatomic, copy) NSString *rteRating;

// Rating system in Russia
@property (nonatomic, copy) NSString *russiaRating;

// Rating system for Slovakia - Slovakia Rating System
@property (nonatomic, copy) NSString *skfilmRating;

// Rating system for Iceland - SMAIS
@property (nonatomic, copy) NSString *smaisRating;

// Rating system for Sweden - Statens medier�d (National Media Council)
@property (nonatomic, copy) NSString *smsaRating;

// TV Parental Guidelines rating of the content.
@property (nonatomic, copy) NSString *tvpgRating;

// Internal YouTube rating.
@property (nonatomic, copy) NSString *ytRating;

@end

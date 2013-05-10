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
//  GTLClientLoginAuthentication.h
//

// GTLClientLoginAuthentication implements an authorizer for Google's
// ClientLogin protocol
//
// Protocol docs:
//   http://code.google.com/apis/accounts/docs/AuthForInstalledApps.html
//
// Sample usage:
//   GTLClientLoginAuthentication *auth = [GTLClientLoginAuthentication authenticationForService:@"print"
//                                                                                        source:@"myCompany-myApp-v1"];
//   auth.userEmail = @"test@example.com";
//   auth.password = @"password";
//
// Then set the auth object as the authorizer of a service object or a fetcher.

#import <Foundation/Foundation.h>

#if GTL_BUILT_AS_FRAMEWORK
#import "GTL/GTLDefines.h"
#import "GTL/GTMHTTPFetcher.h"
#else
#import "GTLDefines.h"
#import "GTMHTTPFetcher.h"
#endif

#undef _EXTERN
#undef _INITIALIZE_AS
#ifdef GTLCLIENTLOGINAUTHENTICATION_DEFINE_GLOBALS
#define _EXTERN
#define _INITIALIZE_AS(x) =x
#else
#define _EXTERN GTL_EXTERN
#define _INITIALIZE_AS(x)
#endif

_EXTERN NSString * const kGTLClientLoginErrorDomain  _INITIALIZE_AS(@"com.google.GTLClientLogin");

_EXTERN NSString * const kGTLClientLoginErrorRequestKey _INITIALIZE_AS(@"request");

enum {
  kGTLClientLoginErrorAuthorizationFailed = -1001
};

@interface GTLClientLoginAuthentication : NSObject <GTMFetcherAuthorizationProtocol> {
 @private
  NSString *serviceID_;
  NSString *source_;
  NSString *domain_;
  NSDictionary *additionalParams_;
  NSDictionary *customHeaders_;
  NSString *userEmail_;
  NSMutableData *password_;

  GTMHTTPFetcher *fetcher_;
  NSMutableArray *authorizationQueue_;

  NSString *token_;
  NSDate *tokenIssueDate_;
}

+ (GTLClientLoginAuthentication *)authenticationForService:(NSString *)serviceID
                                                    source:(NSString *)applicationID;

@property (retain, readwrite) NSString *userEmail;
@property (copy) NSString *password;

// Each service supporting ClientLogin has a serviceID string
@property (copy) NSString *serviceID;

// Each application should include a source (application ID) string of the form
// "companyName-applicationName-version"
@property (copy) NSString *source;

// The Domain should be nil to authenticate against www.google.com; it may be
//   localhost:n for unit testing to port n
@property (copy) NSString *domain;

// A dictionary with additional parameters for the post body.
//
// The params dictionary may be used to specify a captcha response, as in
//    if ([captchaToken length] > 0 && [captchaAnswer length] > 0) {
//      auth.additionalParams = [NSDictionary dictionaryWithObjectsAndKeys:
//                                        captchaToken, @"logintoken",
//                                        captchaAnswer, @"logincaptcha", nil];
//    }
@property (copy) NSDictionary *additionalParams;

// Custom headers to be added to the request; typically this is nil
@property (copy) NSDictionary *customHeaders;

// The authorization token, if sign-in is successful
@property (copy) NSString *token;

// The date the token was issued
@property (copy) NSDate *tokenIssueDate;

// Main authorization entry points
//
// These will fetch the token, if necessary, and add the access token to
// the request, then invoke the callback.
//
// The request argument may be nil to just force a fetch of the token, if the
// token is nil.

// The finish selector should have a signature matching
//   - (void)authentication:(GTLClientLoginAuthentication *)auth
//                  request:(NSMutableURLRequest *)request
//        finishedWithError:(NSError *)error;

- (void)authorizeRequest:(NSMutableURLRequest *)request
                delegate:(id)delegate
       didFinishSelector:(SEL)sel;

#if NS_BLOCKS_AVAILABLE
- (void)authorizeRequest:(NSMutableURLRequest *)request
       completionHandler:(void (^)(NSError *error))handler;
#endif

// Spin the run loop, discarding events, until the fetch has completed
//
// This is only for use in testing or in tools without a user interface.
- (void)waitForCompletionWithTimeout:(NSTimeInterval)timeoutInSeconds;

@end

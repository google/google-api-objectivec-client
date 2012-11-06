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
//  GTLClientLoginAuthentication.m
//

#define GTLCLIENTLOGINAUTHENTICATION_DEFINE_GLOBALS 1
#import "GTLClientLoginAuthentication.h"

#if GTL_BUILT_AS_FRAMEWORK
#import "GTL/GTLUtilities.h"
#else
#import "GTLUtilities.h"
#endif

@class GTLClientLoginAuthorizationArgs;

@interface GTLClientLoginAuthentication ()
@property (retain) GTMHTTPFetcher *fetcher;
@property (retain) NSMutableArray *authorizationQueue;

- (void)authorizeRequestArgs:(GTLClientLoginAuthorizationArgs *)args;
- (void)authorizeRequestImmediateArgs:(GTLClientLoginAuthorizationArgs *)args;

+ (NSDictionary *)dictionaryWithResponseData:(NSData *)data;
@end

// Internal utility class for wrapping requests needing authorization and their
// callbacks
@interface GTLClientLoginAuthorizationArgs : NSObject {
 @private
  NSMutableURLRequest *request_;
  id delegate_;
  SEL sel_;
  id completionHandler_;
  NSThread *thread_;
  NSError *error_;
}

@property (retain) NSMutableURLRequest *request;
@property (retain) id delegate;
@property (assign) SEL selector;
@property (copy) id completionHandler;
@property (retain) NSThread *thread;
@property (retain) NSError *error;

+ (GTLClientLoginAuthorizationArgs *)argsWithRequest:(NSMutableURLRequest *)req
                                            delegate:(id)delegate
                                            selector:(SEL)sel
                                   completionHandler:(id)completionHandler
                                              thread:(NSThread *)thread;
@end

// XorPlainMutableData is a simple way to keep passwords held in heap objects
// from being visible in memory dumps as plaintext
static void XorPlainMutableData(NSMutableData *mutableData) {

  // this helps avoid storing passwords on the heap in plaintext
  const unsigned char theXORValue = 0x95; // 0x95 = 0xb10010101

  unsigned char *dataPtr = [mutableData mutableBytes];
  NSUInteger length = [mutableData length];

  for (NSUInteger idx = 0; idx < length; idx++) {
    dataPtr[idx] ^= theXORValue;
  }
}

@implementation GTLClientLoginAuthorizationArgs

@synthesize request = request_,
            delegate = delegate_,
            selector = sel_,
            completionHandler = completionHandler_,
            thread = thread_,
            error = error_;

+ (GTLClientLoginAuthorizationArgs *)argsWithRequest:(NSMutableURLRequest *)req
                                            delegate:(id)delegate
                                            selector:(SEL)sel
                                   completionHandler:(id)completionHandler
                                              thread:(NSThread *)thread {
  GTLClientLoginAuthorizationArgs *obj;
  obj = [[[GTLClientLoginAuthorizationArgs alloc] init] autorelease];
  obj.request = req;
  obj.delegate = delegate;
  obj.selector = sel;
  obj.completionHandler = completionHandler;
  obj.thread = thread;
  return obj;
}

- (void)dealloc {
  self.request = nil;
  self.delegate = nil;
  self.selector = NULL;
  self.completionHandler = nil;
  self.thread = nil;
  self.error = nil;
  [super dealloc];
}
@end


@implementation GTLClientLoginAuthentication

@synthesize serviceID = serviceID_,
            source = source_,
            domain = domain_,
            additionalParams = additionalParams_,
            customHeaders = customHeaders_,
            fetcher = fetcher_,
            authorizationQueue = authorizationQueue_,
            token = token_,
            tokenIssueDate = tokenIssueDate_;

+ (GTLClientLoginAuthentication *)authenticationForService:(NSString *)serviceID
                                                    source:(NSString *)applicationID {
  GTLClientLoginAuthentication *auth;
  auth = [[[GTLClientLoginAuthentication alloc] init] autorelease];
  auth.serviceID = serviceID;
  auth.source = applicationID;
  return auth;
}

- (id)init {
  self = [super init];
  if (self) {
    authorizationQueue_ = [[NSMutableArray alloc] init];
  }
  return self;
}

- (NSString *)description {
  return [NSString stringWithFormat:@"%@ %p: {%@}",
          [self class], self, self.userEmail];
}

- (void)dealloc {
  [serviceID_ release];
  [source_ release];
  [domain_ release];
  [additionalParams_ release];
  [customHeaders_ release];
  [userEmail_ release];
  [password_ release];
  [fetcher_ release];
  [authorizationQueue_ release];
  [token_ release];
  [tokenIssueDate_ release];

  [super dealloc];
}

- (GTMHTTPFetcher *)clientLoginFetcher {
  NSString *userEmail = self.userEmail;
  NSString *password = self.password;

  GTL_DEBUG_ASSERT([userEmail length] > 0, @"Username missing");
  GTL_DEBUG_ASSERT([password length] > 0, @"Password missing");

  NSString *domain = self.domain;
  if ([domain length] == 0) {
    domain = @"www.google.com";
  }

  // Unit tests may authenticate to a server running locally with
  // a domain like "localhost:8080"
  NSString *scheme = [domain hasPrefix:@"localhost:"] ? @"http" : @"https";

  NSString *urlTemplate = @"%@://%@/accounts/ClientLogin";
  NSString *authURLString = [NSString stringWithFormat:urlTemplate,
                             scheme, domain];

  NSURL *authURL = [NSURL URLWithString:authURLString];

  NSMutableURLRequest *request;
  request = [NSMutableURLRequest requestWithURL:authURL
                                    cachePolicy:NSURLRequestReloadIgnoringCacheData
                                timeoutInterval:60];

  // Add custom request headers
  NSDictionary *headers = self.customHeaders;
  for (NSString *key in headers) {
    NSString *value = [headers objectForKey:key];
    [request setValue:value forHTTPHeaderField:key];
  }

  NSString *source = self.source;
  NSString *serviceID = self.serviceID;

  NSString *template = @"Email=%@&Passwd=%@&source=%@&service=%@&accountType=GOOGLE";
  NSString *postString = [NSString stringWithFormat:template,
                          [GTLUtilities stringByURLEncodingForURI:userEmail],
                          [GTLUtilities stringByURLEncodingForURI:password],
                          [GTLUtilities stringByURLEncodingForURI:source],
                          serviceID];

  // Add custom post body parameters to the post string; typically params is
  // nil, but it may have captcha token and answer
  NSDictionary *params = self.additionalParams;
  for (NSString *key in params) {
    NSString *value = [params objectForKey:key];
    NSString *encValue = [GTLUtilities stringByURLEncodingForURI:value];
    postString = [postString stringByAppendingFormat:@"&%@=%@",
                  key, encValue];
  }

  // We're avoiding +[NSURCredential credentialWithUser:password:persistence:]
  // because it fails to autorelease itself on OS X 10.4 .. 10.5.x
  // rdar://5596278
  NSURLCredential *cred;
  cred = [[[NSURLCredential alloc] initWithUser:userEmail
                                       password:password
                                    persistence:NSURLCredentialPersistenceForSession] autorelease];

  GTMHTTPFetcher* fetcher = [GTMHTTPFetcher fetcherWithRequest:request];
  fetcher.comment = @"ClientLogin";
  fetcher.postData = [postString dataUsingEncoding:NSUTF8StringEncoding];
  fetcher.credential = cred;
  fetcher.retryEnabled = YES;
  fetcher.maxRetryInterval = 15;

  return fetcher;
}

- (void)authorizeRequest:(NSMutableURLRequest *)request
                delegate:(id)delegate
       didFinishSelector:(SEL)sel {
  GTMAssertSelectorNilOrImplementedWithArgs(delegate, sel,
                                            @encode(GTLClientLoginAuthentication *),
                                            @encode(NSMutableURLRequest *),
                                            @encode(NSError *), 0);
  GTLClientLoginAuthorizationArgs *args;
  args = [GTLClientLoginAuthorizationArgs argsWithRequest:request
                                                 delegate:delegate
                                                 selector:sel
                                        completionHandler:nil
                                                   thread:[NSThread currentThread]];
  [self authorizeRequestArgs:args];
}

#if NS_BLOCKS_AVAILABLE
// Authorizing with a completion block
- (void)authorizeRequest:(NSMutableURLRequest *)request
       completionHandler:(void (^)(NSError *error))handler {

  GTLClientLoginAuthorizationArgs *args;
  args = [GTLClientLoginAuthorizationArgs argsWithRequest:request
                                                 delegate:nil
                                                 selector:NULL
                                        completionHandler:handler
                                                   thread:[NSThread currentThread]];
  [self authorizeRequestArgs:args];
}
#endif

- (void)authorizeRequestArgs:(GTLClientLoginAuthorizationArgs *)args {

  @synchronized(authorizationQueue_) {
    BOOL hasToken = ([self.token length] > 0);

    if (hasToken) {
      // If there's a token, ensure that it's not too old, which may happen
      // if this app has been running for weeks.
      //
      // Google services can pick their own expiration interval for ClientLogin
      // tokens, but the default and norm is 14 days.  We'll force a fresh
      // token fetch after 13 days.
      NSDate *issueDate = self.tokenIssueDate;
      if (issueDate) {
        NSTimeInterval interval = [issueDate timeIntervalSinceNow];
        const NSTimeInterval kExpirationInterval = 60 * 60 * 24 * 13;
        if (interval < - kExpirationInterval) {
          self.token = nil;
          hasToken = NO;
        }
      }
    }

    if (hasToken) {
      [self authorizeRequestImmediateArgs:args];
    } else {
      // Attempt to fetch the token now; once we have a token, we will
      // authorize the request and call back to the user
      if (self.fetcher == nil) {
        // There's not already a refresh pending
        GTMHTTPFetcher *fetcher = [self clientLoginFetcher];
        [fetcher beginFetchWithDelegate:self
                      didFinishSelector:@selector(authFetcher:finishedWithData:error:)];
        self.fetcher = fetcher;
      } else {
        // There is already a pending fetcher, so this request can wait in the
        // queue until it completes.
      }

      [authorizationQueue_ addObject:args];
    }
  }
}

- (void)authFetcher:(GTMHTTPFetcher *)fetcher
   finishedWithData:(NSData *)data
              error:(NSError *)error {
  @synchronized(authorizationQueue_) {
    self.fetcher = nil;

    NSDictionary *responseDict = [[self class] dictionaryWithResponseData:data];
    NSString *token = [responseDict objectForKey:@"Auth"];

    BOOL hasToken = ([token length] > 0);
    self.token = (hasToken ? token : nil);
    self.tokenIssueDate = (hasToken ? [NSDate date] : nil);

    // Swap in a new auth queue in case the callbacks try to immediately auth
    // another request
    NSArray *pendingAuthQueue = [NSArray arrayWithArray:authorizationQueue_];
    [authorizationQueue_ removeAllObjects];

    if (error != nil && [responseDict count] > 0) {
      // Show the caller the full error response
      error = [NSError errorWithDomain:[error domain]
                                  code:[error code]
                              userInfo:responseDict];
    }

    // Authorize and call back for all pending requests
    for (GTLClientLoginAuthorizationArgs *args in pendingAuthQueue) {
      if (!hasToken && args.error == nil) {
        args.error = error;
      }
      [self authorizeRequestImmediateArgs:args];
    }
  }
}

- (void)authorizeRequestImmediateArgs:(GTLClientLoginAuthorizationArgs *)args {
  // This authorization entry point never attempts to fetch the token,
  // but does call the completion routine
  NSMutableURLRequest *request = args.request;

  NSString *token = self.token;
  if ([token length] > 0) {
    if (request) {
      // Add the token to the authorization header
      NSString *value = [NSString stringWithFormat:@"GoogleLogin auth=%@",
                         token];
      [request setValue:value forHTTPHeaderField:@"Authorization"];
    }

    args.error = nil;
  } else if (args.error == nil) {
    NSDictionary *userInfo = nil;
    if (request) {
      userInfo = [NSDictionary dictionaryWithObject:request
                                             forKey:kGTLClientLoginErrorRequestKey];
    }
    args.error = [NSError errorWithDomain:kGTLClientLoginErrorDomain
                                     code:kGTLClientLoginErrorAuthorizationFailed
                                 userInfo:userInfo];
  }

  // Invoke any callbacks on the proper threads
  if (args.delegate) {
    NSThread *targetThread = args.thread;
    BOOL isSameThread = [targetThread isEqual:[NSThread currentThread]];

    [self performSelector:@selector(invokeCallbackArgs:)
                 onThread:targetThread
               withObject:args
            waitUntilDone:isSameThread];
  }
}

- (void)invokeCallbackArgs:(GTLClientLoginAuthorizationArgs *)args {
  // Invoke the callbacks
  NSError *error = args.error;

  id delegate = args.delegate;
  SEL sel = args.selector;
  if (delegate && sel) {
    NSMutableURLRequest *request = args.request;

    NSMethodSignature *sig = [delegate methodSignatureForSelector:sel];
    NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:sig];
    [invocation setSelector:sel];
    [invocation setTarget:delegate];
    [invocation setArgument:&self atIndex:2];
    [invocation setArgument:&request atIndex:3];
    [invocation setArgument:&error atIndex:4];
    [invocation invoke];
  }

#if NS_BLOCKS_AVAILABLE
  id handler = args.completionHandler;
  if (handler) {
    void (^authCompletionBlock)(NSError *) = handler;
    authCompletionBlock(error);
  }
#endif
}

- (void)stopAuthorization {
  [self.fetcher stopFetching];
  self.fetcher = nil;
}

- (void)stopAuthorizationForRequest:(NSURLRequest *)request {
  @synchronized(authorizationQueue_) {
    NSUInteger argIndex = 0;
    BOOL found = NO;
    for (GTLClientLoginAuthorizationArgs *args in authorizationQueue_) {
      if ([args request] == request) {
        found = YES;
        break;
      }
      argIndex++;
    }

    if (found) {
      [authorizationQueue_ removeObjectAtIndex:argIndex];

      // If the queue is now empty, go ahead and stop the fetcher.
      if ([authorizationQueue_ count] == 0) {
        [self stopAuthorization];
      }
    }
  }
}

- (BOOL)isAuthorizingRequest:(NSURLRequest *)request {
  BOOL wasFound = NO;
  @synchronized(authorizationQueue_) {
    for (GTLClientLoginAuthorizationArgs *args in authorizationQueue_) {
      if ([args request] == request) {
        wasFound = YES;
        break;
      }
    }
  }
  return wasFound;
}

- (BOOL)isAuthorizedRequest:(NSURLRequest *)request {
  NSString *authStr = [request valueForHTTPHeaderField:@"Authorization"];
  return ([authStr length] > 0);
}

- (void)waitForCompletionWithTimeout:(NSTimeInterval)timeoutInSeconds {
  // If there is a refresh fetcher pending, wait for it.
  //
  // This is only intended for unit test or for use in command-line tools.
  GTMHTTPFetcher *fetcher = self.fetcher;
  [fetcher waitForCompletionWithTimeout:timeoutInSeconds];
}

- (BOOL)primeForRefresh {
  if (self.userEmail == nil || self.password == nil) {
    // Cannot refresh without username and password
    return NO;
  }
  self.token = nil;
  self.tokenIssueDate = nil;
  return YES;
}

#pragma mark -

- (NSString *)userEmail {
  return userEmail_;
}

- (void)setUserEmail:(NSString *)str {
  BOOL isChanging = (userEmail_ != str
                     && (str == nil || ![userEmail_ isEqual:str]));
  if (isChanging) {
    self.token = nil;
  }

  [userEmail_ autorelease];
  userEmail_ = [str copy];
}

- (NSString *)password {
  if (password_) {
    XorPlainMutableData(password_);
    NSString *result = [[[NSString alloc] initWithData:password_
                                              encoding:NSUTF8StringEncoding] autorelease];
    XorPlainMutableData(password_);
    return result;
  }
  return nil;
}

- (void)setPassword:(NSString *)str {
  [password_ autorelease];

  if (str) {
    // Avoid holding the password in the heap in plaintext
    const char *utf8password = [str UTF8String];
    size_t passwordLength = strlen(utf8password);
    password_ = [[NSMutableData alloc] initWithBytes:utf8password
                                              length:passwordLength];
    XorPlainMutableData(password_);
  } else {
    password_ = nil;
  }
}

#pragma mark -

+ (NSDictionary *)dictionaryWithResponseData:(NSData *)data {
  // Build a dictionary from a response string of the form
  // "cat=fluffy \n dog=spot".
  NSString *str = [[[NSString alloc] initWithData:data
                                         encoding:NSUTF8StringEncoding] autorelease];
  if (str == nil) return nil;

  NSArray *allLines = [str componentsSeparatedByString:@"\n"];
  NSMutableDictionary *responseDict;

  responseDict = [NSMutableDictionary dictionaryWithCapacity:[allLines count]];

  for (NSString *line in allLines) {
    NSScanner *scanner = [NSScanner scannerWithString:line];
    NSString *key;
    NSString *value;

    if ([scanner scanUpToString:@"=" intoString:&key]
        && [scanner scanString:@"=" intoString:NULL]
        && [scanner scanUpToString:@"\n" intoString:&value]) {

      [responseDict setObject:value forKey:key];
    }
  }
  return responseDict;
}

@end

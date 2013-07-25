#if defined(__has_feature) && __has_feature(objc_arc)
#error "This file needs to be compiled with ARC disabled."
#endif

#import "HTTPFetcher/GTMGatherInputStream.m"
#import "HTTPFetcher/GTMMIMEDocument.m"
#import "HTTPFetcher/GTMReadMonitorInputStream.m"
#import "HTTPFetcher/GTMHTTPFetcher.m"
#import "HTTPFetcher/GTMHTTPFetcherLogging.m"
#import "HTTPFetcher/GTMHTTPFetcherService.m"
#import "HTTPFetcher/GTMHTTPFetchHistory.m"
#import "HTTPFetcher/GTMHTTPUploadFetcher.m"

#import "OAuth2/GTMOAuth2Authentication.m"
#import "OAuth2/GTMOAuth2SignIn.m"
#if TARGET_OS_IPHONE
  #import "OAuth2/Touch/GTMOAuth2ViewControllerTouch.m"
#elif TARGET_OS_MAC
  #import "OAuth2/Mac/GTMOAuth2WindowController.m"
#else
  #error Need Target Conditionals
#endif

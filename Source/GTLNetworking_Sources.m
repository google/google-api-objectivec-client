#import <TargetConditionals.h>
#import <AvailabilityMacros.h>

#if (!TARGET_OS_IPHONE && defined(MAC_OS_X_VERSION_10_11) && MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_11) \
    || (TARGET_OS_IPHONE && defined(__IPHONE_9_0) && __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_9_0)
  #ifndef GTM_USE_SESSION_FETCHER
    #define GTM_USE_SESSION_FETCHER 1
  #endif
#endif

#if GTM_USE_SESSION_FETCHER
  #if defined(__has_feature) && !__has_feature(objc_arc)
  #error "This file needs to be compiled with ARC enabled."
  #endif

  #undef GTMSESSION_BUILD_COMBINED_SOURCES
  #define GTMSESSION_BUILD_COMBINED_SOURCES 1

  #import "HTTPFetcher/GTMGatherInputStream.m"
  #import "HTTPFetcher/GTMMIMEDocument.m"
  #import "HTTPFetcher/GTMReadMonitorInputStream.m"
  #import "HTTPFetcher/GTMSessionFetcher.m"
  #import "HTTPFetcher/GTMSessionFetcherLogging.m"
  #import "HTTPFetcher/GTMSessionFetcherService.m"
  #import "HTTPFetcher/GTMSessionUploadFetcher.m"
#else
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
#endif

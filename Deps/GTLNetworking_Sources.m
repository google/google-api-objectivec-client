#import <TargetConditionals.h>
#import <AvailabilityMacros.h>

#if (!TARGET_OS_IPHONE && defined(MAC_OS_X_VERSION_10_11) && MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_11) \
    || (TARGET_OS_IPHONE && defined(__IPHONE_9_0) && __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_9_0)
  #ifndef GTM_USE_SESSION_FETCHER
    #define GTM_USE_SESSION_FETCHER 1
  #endif
#endif

#if !defined(GTM_USE_SESSION_FETCHER) || GTM_USE_SESSION_FETCHER
  #if defined(__has_feature) && !__has_feature(objc_arc)
  #error "This file needs to be compiled with ARC enabled."
  #endif

  #undef GTMSESSION_BUILD_COMBINED_SOURCES
  #define GTMSESSION_BUILD_COMBINED_SOURCES 1

  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wnullability-completeness"

  #import "gtm-session-fetcher/Source/GTMGatherInputStream.m"
  #import "gtm-session-fetcher/Source/GTMMIMEDocument.m"
  #import "gtm-session-fetcher/Source/GTMReadMonitorInputStream.m"
  #import "gtm-session-fetcher/Source/GTMSessionFetcher.m"
  #import "gtm-session-fetcher/Source/GTMSessionFetcherLogging.m"
  #import "gtm-session-fetcher/Source/GTMSessionFetcherService.m"
  #import "gtm-session-fetcher/Source/GTMSessionUploadFetcher.m"

  #pragma clang diagnostic pop
#else
  #error Umbrella networking source file only supports the SessionFetcher

  // #if defined(__has_feature) && __has_feature(objc_arc)
  // #error "This file needs to be compiled with ARC disabled."
  // #endif
  //
  // #import "gtm-http-fetcher/Source/GTMGatherInputStream.m"
  // #import "gtm-http-fetcher/Source/GTMMIMEDocument.m"
  // #import "gtm-http-fetcher/Source/GTMReadMonitorInputStream.m"
  // #import "gtm-http-fetcher/Source/GTMHTTPFetcher.m"
  // #import "gtm-http-fetcher/Source/GTMHTTPFetcherLogging.m"
  // #import "gtm-http-fetcher/Source/GTMHTTPFetcherService.m"
  // #import "gtm-http-fetcher/Source/GTMHTTPFetchHistory.m"
  // #import "gtm-http-fetcher/Source/GTMHTTPUploadFetcher.m"
#endif

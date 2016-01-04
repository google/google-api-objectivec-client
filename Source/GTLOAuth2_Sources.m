#import <TargetConditionals.h>
#import <AvailabilityMacros.h>

#if defined(__has_feature) && __has_feature(objc_arc)
#error "This file needs to be compiled with ARC disabled."
#endif

#if (!TARGET_OS_IPHONE && defined(MAC_OS_X_VERSION_10_11) && MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_11) \
|| (TARGET_OS_IPHONE && defined(__IPHONE_9_0) && __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_9_0)
  #ifndef GTM_USE_SESSION_FETCHER
    #define GTM_USE_SESSION_FETCHER 1
  #endif
#endif

#import "OAuth2/GTMOAuth2Authentication.m"
#import "OAuth2/GTMOAuth2SignIn.m"
#if TARGET_OS_IPHONE
  #import "OAuth2/Touch/GTMOAuth2ViewControllerTouch.m"
#elif TARGET_OS_MAC
  #import "OAuth2/Mac/GTMOAuth2WindowController.m"
#else
  #error Need Target Conditionals
#endif

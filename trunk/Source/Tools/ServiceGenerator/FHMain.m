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

// This tool attempts to generate as much as possible for services from the
// Google APIs Discovery Service documents.

#import <Foundation/Foundation.h>
#include <getopt.h>
#include <libgen.h>
#include <mach-o/dyld.h>
#include <unistd.h>

#import "GTLDiscovery.h"
#import "GTLUtilities.h"
#import "GTMHTTPFetcherLogging.h"

#import "FHGenerator.h"
#import "FHUtils.h"


typedef struct {
  const char *arg;
  const char *desc; // Gets wrapped when printed
} ArgInfo;

static ArgInfo requiredFlags[] = {
  { "--outputDir PATH",
      "The destination directory for writing the generated files."
  },
};

static ArgInfo optionalFlags[] = {
  { "--discoveryService URL",
    "Instead of discovery's default URL, use the specified URL as the location"
    " to send the JSON-RPC requests.  This is useful for running against a"
    " custom or prerelease server."
  },
  { "--apiLogDir DIR",
    "Write out a file into DIR for each JSON API description processed.  These"
    " can be useful for reporting bugs if generation fails with an error."
  },
  { "--httpLogDir PATH",
    "Turn on the HTTP fetcher logging and set it to write to PATH.  This"
    " can be useful for diagnosing errors on discovery fetches."
  },
  { "--generatePreferred",
    "Causes the list of services to be collected, and all preferred"
    " services to be generated."
  },
  {
    "--httpHeader NAME:VALUE",
    "Causes the given NAME/VALUE pair to be added as an HTTP header on *all*"
    " HTTP requests made by the generator.  Can be used repeatedly to"
    " provide additional header pairs."
  },
  {
    "--formattedName SERVICE:VERSION=NAME",
    "Causes the given SERVICE:VERSION pair to override its service name in"
    " files, classes, etc. with NAME.  If :VERSION is omitted"
    " the override is for any version of the service.  Can be used repeatedly"
    " to provide several maps when generating a few things in a single run."
  },
  { "--addServiceNameDir yes|no  Default: no",
    "Causes the generator to add a directory with the service name"
    " in the outputDir for the files. This is useful for generating"
    " multiple services."
  },
  { "--generatedDir yes|no  Default: no",
    "Causes a directory in outputDir called \"Generated\" to be"
    " created and used to contain the generated files."
  },
  { "--removeUnknownFiles yes|no  Default: no",
    "By default, the generator will report unknown files in the"
    " output directory, as commonly happens when classes go away"
    " in a new API version. This option causes the generator to also"
    " remove the unknown files."
  },
  { "--rootURLOverrides yes|no  Default: yes",
    "Causes any API root URL for a Google sandbox server to be replaced with"
    " the googleapis.com root instead."
  },
  { "--verbose",
    "Generate more verbose output.  Can be used more than once."
  },
};


static ArgInfo optionalArgs[] = {
  { "service:version",
      "The description of the given [service]/[version] pair is fetched and"
      " the files for it are generated.  When using --generatePreferred"
      " version can be '-' to skip generating the name service." },
  { "http[s]://url/to/rpc_description_json",
      "A URL to download containing the descripiton of a service to"
      " generate." },
  { "path/to/rpc_description.json",
      "The path to a text file containing the description of a service to"
      " generate." },
};

// Tool Exit codes:
//   0: Success
//  0x: Error during setup (args, etc.)
//  1x: Error in the data fetch
//  2x: Error while generating
//  3x: Error while writing out results

// Strings for plain/colored output.
static const char kERROR_Plain[]     = "ERROR:";
static const char kERROR_Colored[]   = "\033[1;31mERROR:\033[0m"; // bold+red
static const char kWARNING_Plain[]   = "WARNING:";
static const char kWARNING_Colored[] = "\033[1;35mWARNING:\033[0m"; // bold+magenta
static const char kINFO_Plain[]      = "INFO:";
static const char kINFO_Colored[]    = "\033[1;33mINFO:\033[0m"; // bold+yellow
static const char kEmBegin_COLORED[] = "\033[1m"; // bold
static const char kEmEnd_COLORED[]   = "\033[0m";

// Constants, updated in main, to get basic or color support.
static const char *kERROR            = kERROR_Plain;
static const char *kWARNING          = kWARNING_Plain;
static const char *kINFO             = kINFO_Plain;
static const char *kEmBegin          = "";
static const char *kEmEnd            = "";

typedef enum {
  FHMain_ParseArgs,
  FHMain_Directory,
  FHMain_Describe,
  FHMain_Wait,
  FHMain_Generate,
  FHMain_WriteFiles,
  FHMain_Done
} FHMainState;

@interface FHMain : NSObject

@property (assign) int argc;
@property (assign) char * const *argv;

- (id)initWithArgc:(int)argc argv:(char * const *)argv;
- (int)run;

@end

@interface FHMain ()

@property (copy) NSString *appName;
@property (copy) NSString *outputDir;
@property (copy) NSString *discoveryServiceURLString;
@property (copy) NSString *apiLogDir;
@property (copy) NSString *httpLogDir;
@property (assign) BOOL generatePreferred;
@property (assign) BOOL addServiceNameDir;
@property (assign) BOOL removeUnknownFiles;
@property (assign) BOOL includeGeneratedDir;
@property (assign) BOOL rootURLOverrides;
@property (assign) NSUInteger verboseLevel;
@property (retain) NSMutableDictionary *additionalHTTPHeaders;
@property (retain) NSMutableDictionary *formattedNames;

@property (retain) GTLServiceDiscovery *discoveryService;
@property (retain) NSMutableArray *apisToFetch;
@property (retain) NSMutableSet *apisToSkip;
@property (retain) NSMutableArray *collectedApis;
@property (retain) NSMutableDictionary *generatedData;

@property (assign) int numberOfActiveNetworkActions;
@property (assign) FHMainState state;
@property (assign) FHMainState postWaitState;
@property (assign) int status;

- (void)printUsage:(FILE *)outputFile;

- (BOOL)collectAPIFromURL:(NSURL *)url reportingName:(NSString *)reportingName;

- (void)stateParseArgs;
- (void)stateDirectory;
- (void)stateDescribe;
- (void)stateWait;
- (void)stateGenerate;
- (void)stateWriteFiles;

@end

// Compares two files allowing differences for the year.
static BOOL HaveFileStringsChanged(NSString *oldFile, NSString *newFile) {
  // If they are difference sizes, then clearly they are different.
  if ([oldFile length] != [newFile length]) {
    return YES;
  }

  // Exact match?  Yes-done.
  if ([oldFile isEqual:newFile]) {
    return NO;
  }

  // TODO: When moving to Lion, use NSRegularExpression to do this better.
  NSLocale *enUSLocale =
    [[[NSLocale alloc] initWithLocaleIdentifier:@"en_US"] autorelease];
  NSDateFormatter *formatter =
    [[[NSDateFormatter alloc] initWithDateFormat:@"%Y"
                            allowNaturalLanguage:NO] autorelease];
  [formatter setLocale:enUSLocale];
  NSString *yearStr = [formatter stringFromDate:[NSDate date]];

  NSString *matchLine =
    [NSString stringWithFormat:@"Copyright (c) %@ Google Inc.", yearStr];
  NSString *newTest = [newFile stringByReplacingOccurrencesOfString:matchLine
                                                         withString:@""];

  for (int aYear = 2010; aYear < 2020; ++aYear) {
    matchLine =
      [NSString stringWithFormat:@"Copyright (c) %d Google Inc.", aYear];
    NSString *oldTest = [oldFile stringByReplacingOccurrencesOfString:matchLine
                                                           withString:@""];
    if ([oldTest isEqual:newTest]) {
      return NO;
    }
  }

  return YES;
}

@implementation FHMain

@synthesize argc = argc_,
            argv = argv_;

@synthesize appName = appName_,
            outputDir = outputDir_,
            discoveryServiceURLString = discoveryServiceURLString_,
            apiLogDir = apiLogDir_,
            httpLogDir = httpLogDir_,
            generatePreferred = generatePreferred_,
            addServiceNameDir = addServiceNameDir_,
            removeUnknownFiles = removeUnknownFiles_,
            rootURLOverrides = rootURLOverrides_,
            includeGeneratedDir = includeGeneratedDir_,
            verboseLevel = verboseLevel_,
            additionalHTTPHeaders = additionalHTTPHeaders_,
            formattedNames = formattedNames_,
            discoveryService = discoveryService_,
            numberOfActiveNetworkActions = numberOfActiveNetworkActions_,
            apisToFetch = apisToFetch_,
            apisToSkip = apisToSkip_,
            collectedApis = collectedApis_,
            generatedData = generatedData_,
            state = state_,
            postWaitState = postWaitState_,
            status = status_;

- (id)initWithArgc:(int)argc argv:(char * const *)argv {
  self = [super init];
  if (self != nil) {
    argc_ = argc;
    argv_ = argv;
    appName_ = [[NSString alloc] initWithUTF8String:basename(self.argv[0])];
    additionalHTTPHeaders_ = [[NSMutableDictionary alloc] init];
    formattedNames_ = [[NSMutableDictionary alloc] init];
    apisToFetch_ = [[NSMutableArray alloc] init];
    apisToSkip_ = [[NSMutableSet alloc] init];
    collectedApis_ = [[NSMutableArray alloc] init];
    generatedData_ = [[NSMutableDictionary alloc] init];
    rootURLOverrides_ = YES;

    discoveryService_ = [[GTLServiceDiscovery alloc] init];
    // We aren't bundled, so add a good UA.
    discoveryService_.userAgent = @"com.google.ServiceGenerator";
  }
  return self;
}

- (void)dealloc {
  [appName_ release];
  [outputDir_ release];
  [discoveryServiceURLString_ release];
  [apiLogDir_ release];
  [httpLogDir_ release];

  [additionalHTTPHeaders_ release];
  [formattedNames_ release];

  [discoveryService_ release];
  [apisToFetch_ release];
  [apisToSkip_ release];
  [collectedApis_ release];
  [generatedData_ release];

  [super dealloc];
}

- (int)run {

  while (self.state != FHMain_Done) {
    NSAutoreleasePool *localPool = [[NSAutoreleasePool alloc] init];

    switch (self.state) {
      case FHMain_ParseArgs:
        [self stateParseArgs];
        break;
      case FHMain_Directory:
        [self stateDirectory];
        break;
      case FHMain_Describe:
        [self stateDescribe];
        break;
      case FHMain_Wait:
        [self stateWait];
        break;
      case FHMain_Generate:
        [self stateGenerate];
        break;
      case FHMain_WriteFiles:
        [self stateWriteFiles];
        break;
      case FHMain_Done:
        break;
    }

    [localPool drain];
  }

  return self.status;
}

- (void)printUsage:(FILE *)outputFile {
  fprintf(outputFile,
          "\nUsage: %s [FLAGS] [ARGS]\n",
          [self.appName UTF8String]);
  fprintf(outputFile, "\n");

  fprintf(outputFile, "  Requried Flags:\n\n");
  for (uint32_t idx = 0; idx < ARRAY_COUNT(requiredFlags); ++idx) {
    ArgInfo *info = &requiredFlags[idx];

    NSString *descStr = [NSString stringWithUTF8String:info->desc];
    NSString *wrapped = [FHUtils stringOfLinesFromString:descStr
                                              linePrefix:@"        "];
    fprintf(outputFile, "    %s\n", info->arg);
    fprintf(outputFile, "%s\n", [wrapped UTF8String]);
  }

  fprintf(outputFile, "  Optional Flags:\n\n");
  for (uint32_t idx = 0; idx < ARRAY_COUNT(optionalFlags); ++idx) {
    ArgInfo *info = &optionalFlags[idx];

    NSString *descStr = [NSString stringWithUTF8String:info->desc];
    NSString *wrapped = [FHUtils stringOfLinesFromString:descStr
                                              linePrefix:@"        "];
    fprintf(outputFile, "    %s\n", info->arg);
    fprintf(outputFile, "%s\n", [wrapped UTF8String]);
  }

  fprintf(outputFile, "  Arguments:\n\n");
  NSString *comment = @"Multiple arguments can be given on the command line.";
  NSString *wrappedComment = [FHUtils stringOfLinesFromString:comment
                                                   linePrefix:@"    "];
  fprintf(outputFile, "%s\n", [wrappedComment UTF8String]);
  for (uint32_t idx = 0; idx < ARRAY_COUNT(optionalArgs); ++idx) {
    ArgInfo *info = &optionalArgs[idx];

    NSString *descStr = [NSString stringWithUTF8String:info->desc];
    NSString *wrapped = [FHUtils stringOfLinesFromString:descStr
                                              linePrefix:@"        "];
    fprintf(outputFile, "    %s\n", info->arg);
    fprintf(outputFile, "%s\n", [wrapped UTF8String]);
  }

  self.status = 2;
  self.state = FHMain_Done;
}

- (BOOL)collectAPIFromURL:(NSURL *)url reportingName:(NSString *)reportingName {
  printf(" + Fetching %s\n", [reportingName UTF8String]);

  GTMHTTPFetcherService *fetcherService = self.discoveryService.fetcherService;
  GTMHTTPFetcher *fetcher = [fetcherService fetcherWithURL:url];
  fetcher.comment = [@"Fetching: " stringByAppendingString:reportingName];

  BOOL started = [fetcher beginFetchWithCompletionHandler:^(NSData *data, NSError *error) {
    self.numberOfActiveNetworkActions -= 1;

    if (error) {
      fprintf(stderr,
              "%s Failed to fetch the api description %s, error: %s\n",
              kERROR, [reportingName UTF8String],
              [[error description] UTF8String]);
      self.state = FHMain_Done;
      return;
    }

    NSError *err = nil;
    NSMutableDictionary *json = [GTLJSONParser objectWithData:data
                                                        error:&err];
    if (err != nil) {
      fprintf(stderr,
              "%s Failed to parse the api description %s, error: %s\n",
              kERROR, [reportingName UTF8String],
              [[err description] UTF8String]);
      self.state = FHMain_Done;
      return;
    }

    // Don't use a default class, a valid description will have a 'kind' to
    // create the right thing.
    GTLDiscoveryRpcDescription *api = (GTLDiscoveryRpcDescription *)
      [GTLObject objectForJSON:json
                  defaultClass:nil
                    surrogates:nil
                 batchClassMap:nil];

    if (![api isKindOfClass:[GTLDiscoveryRpcDescription class]]) {
      fprintf(stderr,
              "%s The api description doesn't appear to be a discovery rpc description\n",
              kERROR);
      self.state = FHMain_Done;
      return;
    }

    [self.collectedApis addObject:api];
    printf(" +-- Loaded: %s:%s\n", [api.name UTF8String], [api.version UTF8String]);
  }];
  if (started) {
    self.numberOfActiveNetworkActions += 1;
  } else {
    fprintf(stderr, "%s Failed to fetch the api description\n", kERROR);
    self.state = FHMain_Done;
    return NO;
  }

  return YES;
}

- (void)stateParseArgs {
  int generatePreferred;
  int showUsage;
  generatePreferred = 0;
  showUsage = 0;

  struct option longopts[] = {
    { "outputDir",          required_argument,  NULL,               'o' },
    { "discoveryService",   required_argument,  NULL,               'd' },
    { "apiLogDir",          required_argument,  NULL,               'a' },
    { "httpLogDir",         required_argument,  NULL,               'h' },
    { "generatePreferred",  no_argument,        &generatePreferred, 1 },
    { "httpHeader",         required_argument,  NULL,               'w' },
    { "formattedName",      required_argument,  NULL,               't' },
    { "addServiceNameDir",  required_argument,  NULL,               'x' },
    { "removeUnknownFiles", required_argument,  NULL,               'y' },
    { "rootURLOverrides",   required_argument,  NULL,               'u' },
    { "generatedDir",       required_argument,  NULL,               'z' },
    { "verbose",            no_argument,        NULL,               'v' },
    { "help",               no_argument,        &showUsage,         1 },
    { NULL,                 0,                  NULL,               0 }
  };

  int ch;
  while ((ch = getopt_long(self.argc, self.argv, "v", longopts, NULL)) != -1) {
    switch (ch) {
      case 'o':
        self.outputDir = [NSString stringWithUTF8String:optarg];
        break;
      case 'd':
        self.discoveryServiceURLString = [NSString stringWithUTF8String:optarg];
        break;
      case 'a':
        self.apiLogDir = [NSString stringWithUTF8String:optarg];
        break;
      case 'h':
        self.httpLogDir = [NSString stringWithUTF8String:optarg];
        break;
      case 'v':
        self.verboseLevel += 1;
        break;
      case 't': {
        NSString *asString = [NSString stringWithUTF8String:optarg];
        NSRange range = [asString rangeOfString:@"="];
        if (range.location == NSNotFound) {
          fprintf(stderr, "%s Invalid formattedName argument: %s.\n",
                  kERROR, optarg);
          [self printUsage:stderr];
          return;
        }
        NSString *key = [asString substringToIndex:range.location];
        NSString *value = [asString substringFromIndex:range.location + 1];
        [self.formattedNames setObject:value forKey:key];
      }
        break;
      case 'w': {
        NSString *asString = [NSString stringWithUTF8String:optarg];
        NSRange range = [asString rangeOfString:@":"];
        if (range.location == NSNotFound) {
          fprintf(stderr, "%s Invalid httpHeader argument: %s.\n",
                  kERROR, optarg);
          [self printUsage:stderr];
          return;
        }
        NSString *key = [asString substringToIndex:range.location];
        NSString *value = [asString substringFromIndex:range.location + 1];
        [self.additionalHTTPHeaders setObject:value forKey:key];
      }
        break;
      case 'x':
        self.addServiceNameDir = [FHUtils boolFromArg:optarg];
        break;
      case 'y':
        self.removeUnknownFiles = [FHUtils boolFromArg:optarg];
        break;
      case 'u':
        self.rootURLOverrides = [FHUtils boolFromArg:optarg];
        break;
      case 'z':
        self.includeGeneratedDir = [FHUtils boolFromArg:optarg];
        break;
      case 0:
        // Was a flag, nothing to do.
        break;
      case ':':
        // Missing argument
      case '?':
        // Unknown argument
      default:
        [self printUsage:stderr];
        return;
    }
  }
  self.argc -= optind;
  self.argv += optind;

  self.generatePreferred = generatePreferred;

  if (showUsage) {
    [self printUsage:stdout];
    // No error, they asked for usage.
    self.status = 0;
    return;
  }

  if ((self.argc == 0) && !self.generatePreferred) {
    // Need valid args.
    fprintf(stderr, "%s No argument(s) saying what to do.\n", kERROR);
    [self printUsage:stderr];
    return;
  }

  if ([self.outputDir length] == 0) {
    fprintf(stderr, "%s An output directory is required.\n", kERROR);
    [self printUsage:stderr];
    return;
  }

  // Make sure it is a full path for reporting.
  self.outputDir = [FHUtils fullPathWithPath:self.outputDir];

  // If we got empty, flip it to no value.
  if ([self.discoveryServiceURLString length] == 0) {
    self.discoveryServiceURLString = nil;
  }

  // Make sure output dir exists.
  NSFileManager *fm = [NSFileManager defaultManager];
  BOOL isDir = NO;
  if (![fm fileExistsAtPath:self.outputDir isDirectory:&isDir]) {
    // Doesn't exist, make it.
    NSError *err = nil;
    if (![FHUtils createDir:self.outputDir error:&err]) {
      fprintf(stderr, "%s Failed to make output directory, '%s'\n",
              kERROR,
              [[self.outputDir stringByAbbreviatingWithTildeInPath] UTF8String]);
      self.status = 3;
      self.state = FHMain_Done;
      return;
    }
  } else if (!isDir) {
    // It is a file, not a directory?!
    fprintf(stderr, "%s Output directory is actually a file, '%s'\n",
            kERROR,
            [[self.outputDir stringByAbbreviatingWithTildeInPath] UTF8String]);
    self.status = 4;
    self.state = FHMain_Done;
    return;
  }

  if (self.discoveryServiceURLString) {
    self.discoveryService.rpcURL =
      [NSURL URLWithString:self.discoveryServiceURLString];
  }

  if ([self.additionalHTTPHeaders count]) {
    self.discoveryService.additionalHTTPHeaders = self.additionalHTTPHeaders;
  }

  printf("===============================================================================\n");
  printf("Generation Settings:\n");

  printf("  Output Directory: %s\n",
         [[self.outputDir stringByAbbreviatingWithTildeInPath] UTF8String]);
  printf("  Discovery RPC URL: %s\n",
         [[self.discoveryService.rpcURL absoluteString] UTF8String]);

  // If an api log dir was provided, make sure it exists and use it.
  if ([self.apiLogDir length] > 0) {
    self.apiLogDir = [FHUtils fullPathWithPath:self.apiLogDir];
    NSString *shortApiLogDir = [self.apiLogDir stringByAbbreviatingWithTildeInPath];
    NSError *err = nil;
    if ([FHUtils createDir:self.apiLogDir error:&err]) {
      printf("  Api Log Dir: %s\n", [shortApiLogDir UTF8String]);
    } else {
      self.apiLogDir = nil;
      fprintf(stderr,
              "%s Failed to create api log dir (%s). NSError: %s\n",
              kERROR,
              [shortApiLogDir UTF8String], [[err description] UTF8String]);
    }
  }

  // If a http log dir was provided, make sure it exists, and turn on the
  // fetcher's logging support.
  if ([self.httpLogDir length] > 0) {
    self.httpLogDir = [FHUtils fullPathWithPath:self.httpLogDir];
    NSString *shortHTTPLogDir = [self.httpLogDir stringByAbbreviatingWithTildeInPath];
    NSError *err = nil;
    if ([FHUtils createDir:self.httpLogDir error:&err]) {
      [GTMHTTPFetcher setLoggingEnabled:YES];
      [GTMHTTPFetcher setLoggingDirectory:self.httpLogDir];
      printf("  HTTPFetcher Log Dir: %s\n", [shortHTTPLogDir UTF8String]);
    } else {
      fprintf(stderr,
              "%s Failed to create HTTPFetcher log dir (%s). NSError: %s\n",
              kERROR,
              [shortHTTPLogDir UTF8String], [[err description] UTF8String]);
    }
  }

  if (self.generatePreferred) {
    printf("  Generate Preferred Services: YES\n");
  }

  // Print any additional headers.
  NSDictionary *additionalHTTPHeaders = self.discoveryService.additionalHTTPHeaders;
  if ([additionalHTTPHeaders count]) {
    printf("  Additional HTTP Headers:\n");
    for (NSString *key in additionalHTTPHeaders) {
      NSString *val = [additionalHTTPHeaders objectForKey:key];
      printf("   + %s: %s\n", [key UTF8String], [val UTF8String]);
    }
  }

  // Print the flags.
  printf("  Flags:\n");
  printf("   + Use service name directory: %s\n", [FHUtils strFromBool:self.addServiceNameDir]);
  printf("   + Remove unknown files: %s\n", [FHUtils strFromBool:self.removeUnknownFiles]);
  printf("   + Add 'Generated' directory: %s\n", [FHUtils strFromBool:self.includeGeneratedDir]);
  printf("   + Allow rootURL overrides: %s\n", [FHUtils strFromBool:self.rootURLOverrides]);

  NSMutableArray *urlStringsToFetch = [NSMutableArray array];
  NSMutableArray *filesToLoad = [NSMutableArray array];

  // Process the args.
  self.state = FHMain_Generate;
  for (int i = 0; i < self.argc ; ++i) {
    NSString *arg = [NSString stringWithUTF8String:self.argv[i]];
    NSArray *splitArg = [arg componentsSeparatedByString:@":"];

    if ([arg hasPrefix:@"http://"] || [arg hasPrefix:@"https://"]) {

      // Treat it as an url and load it.
      [urlStringsToFetch addObject:arg];

    } else if ([splitArg count] == 2) {

      // Treat it as a service:version pair.
      NSString *apiName = [splitArg objectAtIndex:0];
      NSString *version = [splitArg objectAtIndex:1];
      if ([version isEqual:@"-"]) {
        [self.apisToSkip addObject:apiName];
      } else {
        NSArray *pair = [NSArray arrayWithObjects:apiName, version, nil];
        [self.apisToFetch addObject:pair];
      }
      self.state = FHMain_Describe;

    } else {

      // Treat it as a path and load it.
      NSString *fullPath = [FHUtils fullPathWithPath:arg];
      [filesToLoad addObject:fullPath];

    }
  }

  if ([urlStringsToFetch count] > 0) {
    printf("Loading API URLs(s):\n");
    for (NSString *urlString in urlStringsToFetch) {
      NSURL *asURL = [NSURL URLWithString:urlString];
      if (asURL == nil) {
        fprintf(stderr,
                "%s Failed to make an url out of %s\n",
                kERROR, [urlString UTF8String]);
        self.state = FHMain_Done;
        return;
      }
      if ([self collectAPIFromURL:asURL reportingName:urlString]) {
        if (self.state != FHMain_Wait) {
          self.postWaitState = self.state;
          self.state = FHMain_Wait;
        }
      } else {
        return;
      }
    }
  }

  if ([filesToLoad count] > 0) {
    printf("Loading API File(s):\n");
    for (NSString *fullPath in filesToLoad) {
      NSString *shortPath = [fullPath stringByAbbreviatingWithTildeInPath];
      NSURL *asURL = [NSURL fileURLWithPath:fullPath];
      if ([self collectAPIFromURL:asURL reportingName:shortPath]) {
        if (self.state != FHMain_Wait) {
          self.postWaitState = self.state;
          self.state = FHMain_Wait;
        }
      } else {
        return;
      }
    }
  }

  if (self.generatePreferred) {
    // Go into directory mode to kick things off (any directly listed
    // services in the args will happen on the generate state).
    self.state = FHMain_Directory;
  }

}

- (void)stateDirectory {
  printf("Requesting API Directory:\n");

  // Fetch the directory list.
  GTLQueryDiscovery *listingQuery = [GTLQueryDiscovery queryForApisList];
  listingQuery.preferred = YES;
  printf(" + Preferred only\n");
  [self.discoveryService executeQuery:listingQuery
                      completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {

      self.numberOfActiveNetworkActions -= 1;
      if (error) {
        fprintf(stderr, "%s Failed to fetch discovery listing, error: %s\n",
                kERROR,
                [[error description] UTF8String]);
        self.status = 11;
        self.state = FHMain_Done;
        self.postWaitState = FHMain_Done;
      } else {
        GTLDiscoveryDirectoryList *apiList = (GTLDiscoveryDirectoryList *)object;
        if (self.apiLogDir != nil) {
          NSString *filePath = [self.apiLogDir stringByAppendingPathComponent:@"DirectoryList.json"];
          NSError *writeErr = nil;
          if (![apiList.JSONString writeToFile:filePath
                                    atomically:YES
                                      encoding:NSUTF8StringEncoding
                                         error:&writeErr]) {
            fprintf(stderr,
                    "%s Failed to write directory list file at '%s'. Error: %s\n",
                    kWARNING,
                    [filePath UTF8String], [[writeErr description] UTF8String]);
          }
        }
        // Collect the server version pairs to describe.
        for (GTLDiscoveryDirectoryListItemsItem *listItem in apiList) {
          NSString *apiName = listItem.name;
          if ([self.apisToSkip containsObject:apiName]) {
            fprintf(stderr, " - %s Will skip '%s'.\n", kINFO, [apiName UTF8String]);
          } else {
            NSArray *pair =
              [NSArray arrayWithObjects:apiName, listItem.version, nil];
            [self.apisToFetch addObject:pair];
          }
        }
      }
    }];
  self.numberOfActiveNetworkActions += 1;

  self.state = FHMain_Wait;
  self.postWaitState = FHMain_Describe;
}

- (void)stateDescribe {
  printf("Requesting API(s):\n");

  GTLBatchQuery *batchQuery = [GTLBatchQuery batchQuery];

  // Stable order for the requests.
  NSArray *orderedPairs =
    [self.apisToFetch sortedArrayUsingComparator:
       ^NSComparisonResult(NSArray *pair1, NSArray *pair2) {
         NSComparisonResult result =
           [[pair1 objectAtIndex:0] compare:[pair2 objectAtIndex:0]];
         if (result == NSOrderedSame) {
           result = [[pair1 objectAtIndex:1] compare:[pair2 objectAtIndex:1]];
         }
         return result;
       }];

  // Create the queries.
  for (NSArray *pair in orderedPairs) {
    NSString *serviceName = [pair objectAtIndex:0];
    NSString *serviceVersion = [pair objectAtIndex:1];
    printf(" + %s(%s)\n",
           [serviceName UTF8String], [serviceVersion UTF8String]);

    GTLQueryDiscovery *query =
      [GTLQueryDiscovery queryForApisGetRpcWithApi:serviceName
                                           version:serviceVersion];
    query.completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
      if (error) {
        GTLErrorObject *errObj = [GTLErrorObject underlyingObjectForError:error];
        // If we got back a structured error object, then the query failed, so
        // report it.  If we don't get a structured error, it's likely a
        // networking error failing the whole batch, so don't report it here,
        // but do that on the batch completion handler.
        if (errObj) {
          fprintf(stderr,
                  "%s Failed to fetch a discovery document for '%s(%s)', error: %s.\n",
                  kERROR,
                  [serviceName UTF8String], [serviceVersion UTF8String],
                  [[errObj description] UTF8String]);
          self.status = 13;
          self.state = FHMain_Done;
          self.postWaitState = FHMain_Done;
        }
      } else {
        GTLDiscoveryRpcDescription *api = (GTLDiscoveryRpcDescription *)object;
        [self.collectedApis addObject:api];

        // If logging the API files, do it now so a fetch failure doesn't
        // prevent the other ones from being logged.
        if (self.apiLogDir != nil) {
          NSString *fileName = [NSString stringWithFormat:@"%@_%@.json",
                                api.name, api.version];
          NSString *filePath = [self.apiLogDir stringByAppendingPathComponent:fileName];
          NSError *writeErr = nil;
          if (![api.JSONString writeToFile:filePath
                                atomically:YES
                                  encoding:NSUTF8StringEncoding
                                     error:&writeErr]) {
            fprintf(stderr,
                    "%s Failed to write api file at '%s'. Error: %s\n",
                    kWARNING,
                    [filePath UTF8String], [[writeErr description] UTF8String]);
          }
        }
      }
    };
    [batchQuery addQuery:query];
  }

  // Send in the batch.
  [self.discoveryService executeQuery:batchQuery
                      completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
      self.numberOfActiveNetworkActions -= 1;
      // Per query handling is done above. The exception is if there is an error
      // here, it's probably a network error, so report it globally here.  Per
      // query failures (within the batch) were handled above (they show up
      // in the BatchResult, not as the error argument.)
      if (error) {
        fprintf(stderr,
                "%s Failed to fetch discovery documents, error: %s\n",
                kERROR, [[error description] UTF8String]);
        self.status = 12;
        self.state = FHMain_Done;
        self.postWaitState = FHMain_Done;
      }
    }];
  self.numberOfActiveNetworkActions += 1;

  self.state = FHMain_Wait;
  self.postWaitState = FHMain_Generate;
}

- (void)stateWait {
  // Wait for all active network actions to finish.
  NSDate* giveUpDate = [NSDate dateWithTimeIntervalSinceNow:30.0];
  while (self.numberOfActiveNetworkActions > 0 && [giveUpDate timeIntervalSinceNow] > 0) {
    NSAutoreleasePool *localPool = [[NSAutoreleasePool alloc] init];

    NSDate *stopDate = [NSDate dateWithTimeIntervalSinceNow:0.1];
    [[NSRunLoop currentRunLoop] runUntilDate:stopDate];

    [localPool drain];
  }

  if (self.numberOfActiveNetworkActions > 0) {
    self.status = 3;
    self.state = FHMain_Done;
    fprintf(stderr, "%s Timed out waiting for the server to come back.\n",
            kERROR);
  } else {
    self.state = self.postWaitState;
  }
}

- (void)stateGenerate {

  // Now process discovery documents.

  printf("Generating:\n");

  // Set the state to next be write files. This way, an error below will clear
  // the state.
  self.state = FHMain_WriteFiles;

  // Stable order for compares.
  NSArray *orderedAPIs =
    [self.collectedApis sortedArrayUsingComparator:
       ^NSComparisonResult(GTLDiscoveryRpcDescription *api1,
                           GTLDiscoveryRpcDescription *api2) {
         return [api1.name caseInsensitiveCompare:api2.name];
       }];

  for (GTLDiscoveryRpcDescription *api in orderedAPIs) {
    NSAutoreleasePool *localPool = [[NSAutoreleasePool alloc] init];

    printf(" + %s(%s)\n",
           [api.name UTF8String], [api.version UTF8String]);
    @try {
      // Apply any name override.
      NSString *formattedNameOverride = nil;
      NSString *apiVersion =
      [NSString stringWithFormat:@"%@:%@", api.name, api.version];
      formattedNameOverride = [formattedNames_ objectForKey:apiVersion];
      if (formattedNameOverride == nil) {
        formattedNameOverride = [formattedNames_ objectForKey:api.name];
      }

      FHGenerator *aGenerator = [FHGenerator generatorForApi:api
                                                verboseLevel:self.verboseLevel
                                       allowRootURLOverrides:self.rootURLOverrides
                                       formattedNameOverride:formattedNameOverride];

      NSDictionary *generatedFiles =
        [aGenerator generateFilesWithHandler:^(FHGeneratorHandlerMessageType msgType,
                                               NSString *message) {
          NSString *wrappedMessage;
          switch (msgType) {
            case kFHGeneratorHandlerMessageError:
              wrappedMessage = [message stringByReplacingOccurrencesOfString:@"\n" withString:@"\n  "];
              fprintf(stderr,"%s %s\n", kERROR, [wrappedMessage UTF8String]);
              self.status = 21;
              self.state = FHMain_Done;
              break;
            case kFHGeneratorHandlerMessageWarning:
              wrappedMessage = [message stringByReplacingOccurrencesOfString:@"\n" withString:@"\n      "];
              fprintf(stderr,"    %s %s\n", kWARNING, [wrappedMessage UTF8String]);
              break;
            case kFHGeneratorHandlerMessageInfo:
              wrappedMessage = [message stringByReplacingOccurrencesOfString:@"\n" withString:@"\n      "];
              fprintf(stderr,"    %s %s\n", kINFO, [wrappedMessage UTF8String]);
              break;
          }
        }];
      if (generatedFiles) {
        if ([self.generatedData objectForKey:aGenerator.formattedApiName] != nil) {
          NSString *err =
            [NSString stringWithFormat:@"Two APIs trying to use the same formatted name of %@, nothing will be written out.",
             aGenerator.formattedApiName];
          fprintf(stderr,"%s %s\n", kERROR, [err UTF8String]);
          if (self.status == 0) {
            self.status = 24;
          }
          self.state = FHMain_Done;
        } else {
          [self.generatedData setObject:generatedFiles
                                 forKey:aGenerator.formattedApiName];
        }
      } else {
        // If we didn't get any generated files, we should have gotten an error
        // callback also. But just to be safe, force out state.
        if (self.status == 0) {
          self.status = 23;
        }
        self.state = FHMain_Done;
      }
    }
    @catch (NSException * e) {
      fprintf(stderr,
              "%s Failure, exception: %s\n",
              kERROR, [[e description] UTF8String]);
      self.status = 22;
      self.state = FHMain_Done;
      break;
    }
    [localPool drain];
  }
}

- (void)stateWriteFiles {
  printf("Writing:\n");

  NSFileManager *fm = [NSFileManager defaultManager];

  BOOL didWriteAFile = NO;
  NSMutableSet *allFilesInDirs = [NSMutableSet set];
  NSMutableSet *allFilesGenerated = [NSMutableSet set];

  NSArray *allKeys = [self.generatedData allKeys];
  NSArray *sortedKeys =
    [allKeys sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];

  for (NSString *dirName in sortedKeys) {
    NSDictionary *filesDict = [self.generatedData objectForKey:dirName];

    NSString *dirToWriteTo = self.outputDir;

    if (self.addServiceNameDir) {
      // Make the subdirectory for the service.
      dirToWriteTo = [dirToWriteTo stringByAppendingPathComponent:dirName];
    }

    if (self.includeGeneratedDir) {
      // Put the files in a "Generated" subfolder.
      dirToWriteTo = [dirToWriteTo stringByAppendingPathComponent:@"Generated"];
    }

    // In case any subdirectories off outputDir were needed, make sure they all
    // exist.
    NSError *err = nil;
    if (![FHUtils createDir:dirToWriteTo error:&err]) {
      fprintf(stderr,
              "%s Failed to make the service directory in the output dir. "
              "NSError: %s\n", kERROR, [[err description] UTF8String]);
      self.status = 31;
      self.state = FHMain_Done;
      return;
    }

    // Write out the files (sort the names so .h/.m pairs get written together)
    NSArray *sortedNames =
      [[filesDict allKeys] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
    for (NSString *name in sortedNames) {
      NSString *body = [filesDict objectForKey:name];

      NSString *fullPath = [dirToWriteTo stringByAppendingPathComponent:name];
      [allFilesGenerated addObject:fullPath];
      NSString *existingFile = [NSString stringWithContentsOfFile:fullPath
                                                         encoding:NSUTF8StringEncoding
                                                            error:NULL];
      if (HaveFileStringsChanged(existingFile, body)) {
        NSError *writeErr = nil;
        if (![body writeToFile:fullPath
                    atomically:YES
                      encoding:NSUTF8StringEncoding
                         error:&writeErr]) {
          fprintf(stderr,
                  "%s Failed to write output file '%s'. Error: %s\n",
                  kERROR,
                  [fullPath UTF8String], [[writeErr description] UTF8String]);
          self.status = 32;
          self.state = FHMain_Done;
          return;
        }
        NSString *pathLeaf =
          [fullPath substringFromIndex:[self.outputDir length] + 1];
        fprintf(stdout, " %s+ %s (%lu bytes)%s%s\n",
                kEmBegin,
                [pathLeaf UTF8String],
                (unsigned long)[body length],
                (existingFile == nil ? " - NEW" : ""),
                kEmEnd);
        didWriteAFile = YES;
      }
    }

    // Collect the list of files there to report unknown files.
    NSError *listErr = nil;
    NSArray *fileNamesOnDisk = [fm contentsOfDirectoryAtPath:dirToWriteTo
                                                       error:&listErr];
    if (listErr != nil) {
      fprintf(stderr,
              "%s Failed to list output directory '%s'. Error: %s\n",
              kWARNING,
              [dirToWriteTo UTF8String], [[listErr description] UTF8String]);
    }
    for (NSString *fileName in fileNamesOnDisk) {
      NSString *fullPath = [dirToWriteTo stringByAppendingPathComponent:fileName];
      [allFilesInDirs addObject:fullPath];
    }
  }

  // Now the unknown files in the output dir(s).
  [allFilesInDirs minusSet:allFilesGenerated];
  NSArray *sortedUnknownFiles =
    [[allFilesInDirs allObjects] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
  for (NSString *fullPath in sortedUnknownFiles) {
    if (self.removeUnknownFiles) {
      NSError *removeErr = nil;
      if ([fm removeItemAtPath:fullPath error:&removeErr]) {
        fprintf(stdout, " %s+ %s - REMOVED%s\n",
                kEmBegin,
                [[fullPath substringFromIndex:[self.outputDir length] + 1] UTF8String],
                kEmEnd);
        didWriteAFile = YES;
      } else {
        fprintf(stderr,
                "%s Failed to remove stale output file '%s'. Error: %s\n",
                kWARNING,
                [fullPath UTF8String], [[removeErr description] UTF8String]);
      }
    } else {
      fprintf(stderr,
              " %s '%s' was in the output dir, and wasn't needed during generation.\n",
              kINFO,
              [[fullPath substringFromIndex:[self.outputDir length] + 1] UTF8String]);
    }
  }

  // In Directory based mode and using service directories, report any services
  // that seem to have gone away (deleteing seems a little risky here).
  if (self.generatePreferred && self.addServiceNameDir) {
    NSError *listingErr = nil;
    NSArray *fileNamesOnDisk = [fm contentsOfDirectoryAtPath:self.outputDir
                                                       error:&listingErr];
    if (listingErr != nil) {
      fprintf(stderr,
              "%s Failed to list output directory '%s'. Error: %s\n",
              kWARNING,
              [self.outputDir UTF8String], [[listingErr description] UTF8String]);
    }

    if (fileNamesOnDisk) {
      NSMutableArray *unexpectedNames =
        [NSMutableArray arrayWithArray:fileNamesOnDisk];
      NSArray *serviceDirectoryNames = [self.generatedData allKeys];
      [unexpectedNames removeObjectsInArray:serviceDirectoryNames];
      for (NSString *fileName in unexpectedNames) {
        BOOL isDir = NO;
        NSString *fullPath =
          [self.outputDir stringByAppendingPathComponent:fileName];
        // Only report on directories there, not files.
        if ([fm fileExistsAtPath:fullPath isDirectory:&isDir] && isDir) {
          fprintf(stderr,
                  " %s '%s' was in the output dir, and wasn't needed during generation.\n",
                  kINFO,
                  [fileName UTF8String]);
        }
      }
    }
  }

  if (!didWriteAFile) {
    fprintf(stdout,
            " %s- No changes from what is already on disk.%s\n",
            kEmBegin, kEmEnd);
  }

  self.state = FHMain_Done;
}

@end

int main (int argc, char * const *argv) {
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

  // If stdout/stderr are ttys and "color" is in the terminal, assume color
  // output will work.
  char *termCStr = getenv("TERM");
  int stdoutNum = fileno(stdout);
  int stderrNum = fileno(stderr);
  // NSTask sets NSUnbufferedIO. Check for it because that's yet another
  // sign output isn't really going to a TTY.
  // http://lists.apple.com/archives/cocoa-dev/2002/Oct/msg00665.html
  char *bufferedIO = getenv("NSUnbufferedIO");
  if ((stdoutNum >= 0) && (stderrNum >= 0) &&
      isatty(stdoutNum) && isatty(stderrNum) &&
      (termCStr != NULL) &&
      (strstr(termCStr, "color") != NULL) &&
      (bufferedIO == NULL)) {
    kERROR = kERROR_Colored;
    kWARNING = kWARNING_Colored;
    kINFO = kINFO_Colored;
    kEmBegin = kEmBegin_COLORED;
    kEmEnd = kEmEnd_COLORED;
  }

  FHMain *fh = [[[FHMain alloc] initWithArgc:argc argv:argv] autorelease];
  int status = [fh run];

  [pool drain];
  return status;
}

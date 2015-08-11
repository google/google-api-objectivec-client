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

#import "FHGenerator.h"
#import "FHUtils.h"
#import "GTLUtilities.h"

static NSString *kProjectPrefix         = @"GTL";
static NSString *kServiceBaseClass      = @"GTLService";
static NSString *kQueryBaseClass        = @"GTLQuery";
static NSString *kBaseObjectClass       = @"GTLObject";
static NSString *kCollectionObjectClass = @"GTLCollectionObject";
static NSString *kResultArrayClass      = @"GTLResultArray";
static NSString *kExternPrefix          = @"GTL_EXTERN";
static NSString *kFrameworkIncludeGate  = @"GTL_BUILT_AS_FRAMEWORK";

static NSString *kFatalGeneration = @"FatalGeneration";

static NSString *kResourceParameterName = @"resource";

static NSString *kWrappedMethodKey                = @"wrappedMethod";
static NSString *kWrappedSchemaKey                = @"wrappedSchema";
static NSString *kNameKey                         = @"name";
static NSString *kObjCNameKey                     = @"objcName";
static NSString *kForcedNameCommentKey            = @"forcedNameComment";
static NSString *kCapObjCNameKey                  = @"capObjCName";
static NSString *kUniqueParamsKey                 = @"uniqueParams";
static NSString *kUniqueRepeatedParamsKey         = @"uniqueRepeatedParams";
static NSString *kAllParamsKey                    = @"allParameters";
static NSString *kAllMethodsKey                   = @"allMethods";
static NSString *kEnumsMapKey                     = @"enumsMap";
static NSString *kAllSchemasKey                   = @"allSchemas";
static NSString *kGroupingPartsKey                = @"groupingParts";
static NSString *kObjCQueryForNameKey             = @"objcQueryForName";
static NSString *kSortedParametersKey             = @"sortedParameters";
static NSString *kSortedParametersWithResourceKey = @"sortedParametersWithResource";
static NSString *kTopLevelObjectSchemasKey        = @"topLevelObjectSchemas";
static NSString *kChildObjectSchemasKey           = @"childSchemas";
static NSString *kResolvedSchemaKey               = @"resolvedSchema";
static NSString *kSchemaObjCClassNameKey          = @"schemaObjCClassName";
static NSString *kWrappedGeneratorKey             = @"wrappedGenerator";
static NSString *kSkipRegisteringKindKey          = @"skipRegisteringKind";
static NSString *kOverloadedParameterTypeKey      = @"overloadedParameterType";
static NSString *kOverloadedParameterArrayItemKey = @"overloadedParameterArrayItem";
static NSString *kReturnsSchemaParameterKey       = @"returnsSchema";
static NSString *kAllMethodObjectParametersKey    = @"allMethodObjectParameters";
static NSString *kAllMethodObjectParameterRefsKey = @"allMethodObjectParameterRefs";
static NSString *kSameNamedParametersKey          = @"sameNamedParameters";
static NSString *kSameNamedRepeatedParametersKey  = @"sameNamedRepeatedParameters";
static NSString *kBuiltRPCUrlStringKey            = @"builtRPCUrlString";
static NSString *kIsItemsSchemaKey                = @"isItemsSchema";

typedef enum {
  kGenerateInterface = 1,
  kGenerateImplementation
} GeneratorMode;

// This is added so it can be called on Methods, Parameters, and Schema.
@interface GTLObject (FHGeneratorAdditions)
@property (readonly) NSString *errorReportingName;
@property (readonly) FHGenerator *generator;
@end

@interface GTLDiscoveryRpcDescription (FHGeneratorAdditions)
@property (readonly) NSArray *allMethods;
@property (readonly) NSArray *uniqueParameters;
@property (readonly) NSArray *uniqueRepeatedParameters;
@property (readonly) NSArray *allParameters;
@property (readonly) NSDictionary *enumsMap;
@property (readonly) NSArray *allSchemas;
@property (readonly) NSArray *topLevelObjectSchemas;
@property (readonly) NSArray *allMethodObjectParameters;
@property (readonly) NSArray *allMethodObjectParameterReferences;

- (BOOL)buildParameterLists:(void (^)(FHGeneratorHandlerMessageType msgType,
                                      NSString *message))messageHandler;
- (NSString *)builtRPCUrlString;
- (BOOL)likelyRESTOnlyAPI;
- (BOOL)isGoogleService;
- (BOOL)hasMediaUploadMethods;
@end

@interface GTLDiscoveryJsonSchema (FHGeneratorAdditions)
@property (readonly) NSString *name;
@property (readonly) NSString *objcName;
@property (readonly) NSString *capObjCName;
@property (readonly) NSString *forceNameComment;
@property (readonly) GTLDiscoveryJsonSchema *methodParam;
@property (readonly) GTLDiscoveryRpcMethod *method;
@property (readonly, getter=isParameter) BOOL parameter;
@property (readonly) GTLDiscoveryJsonSchema *parentSchema;
@property (readonly) NSString *fullSchemaName;
@property (readonly) NSString *objcClassName;
@property (readonly) NSArray *childObjectSchemas;
@property (readonly) GTLDiscoveryJsonSchema *resolvedSchema;
@property (readonly, getter=hasItemsArrayProperty) BOOL itemsArrayProperty;
@property (readonly) NSString *kindToRegister;
@property (readonly) NSString *rangeAndDefaultDescription;

- (GTLDiscoveryJsonSchema *)itemsSchemaResolving:(BOOL)resolving
                                           depth:(NSUInteger *)depth;

- (NSString *)constantNamed:(NSString *)name;

- (void)getObjectParamObjCType:(NSString **)objcType
                     asPointer:(BOOL *)asPointer
         objcPropertySemantics:(NSString **)objcPropertySemantics
                       comment:(NSString **)comment;

- (void)getQueryParamObjCType:(NSString **)objcType
                    asPointer:(BOOL *)asPointer
        objcPropertySemantics:(NSString **)objcPropertySemantics
                      comment:(NSString **)comment
               itemsClassName:(NSString **)itemsClassName;
@property (readonly) NSString *queryParamPseudoObjCType;
@end

@interface GTLDiscoveryRpcMethod (FHGeneratorAdditions)
@property (readonly) NSString *name;
@property (readonly) NSString *objcQueryForName;
@property (readonly) NSString *groupingName;
@property (readonly) GTLDiscoveryJsonSchema *request;
@property (readonly) NSArray *sortedParameters;
@property (readonly) NSArray *sortedParametersWithResource;
- (NSArray *)groupingParts;
@end

@interface GTLDiscoveryRpcMethodReturns (FHGeneratorAdditions)
@property (readonly) GTLDiscoveryJsonSchema *resolvedSchema;
@end

@interface FHGenerator () {
  NSString *formattedName_;
  NSPredicate *notRetainedPredicate_;
  NSPredicate *useCustomerGetterPredicate_;
}

@property (retain) NSMutableArray *warnings;
@property (retain) NSMutableArray *infos;

@property (readwrite, retain) GTLDiscoveryRpcDescription *api;
@property (readwrite, assign) NSUInteger verboseLevel;

@property (readonly) NSString *objcServiceClassName;
@property (readonly) NSString *objcQueryClassName;
@property (readonly) NSString *masterHeaderName;
@property (readonly) NSString *allSourcesSourceName;

@property (readonly) NSString *serviceHeader;
@property (readonly) NSString *serviceSource;

@property (readonly) NSString *queryHeader;
@property (readonly) NSString *querySource;

@property (readonly) NSString *constantsBase;
@property (readonly) NSString *constantsHeader;
@property (readonly) NSString *constantsSource;

- (NSString *)headerForSchema:(GTLDiscoveryJsonSchema *)schema;
- (NSString *)sourceForSchema:(GTLDiscoveryJsonSchema *)schema;

- (instancetype)initWithApi:(GTLDiscoveryRpcDescription *)api
               verboseLevel:(NSUInteger)verboseLevel
      allowRootURLOverrides:(BOOL)allowRootURLOverrides
      formattedNameOverride:(NSString *)formattedNameOverride
           skipIfLikelyREST:(BOOL)skipIfLikelyREST;

- (void)adornMethods:(GTLDiscoveryRpcDescriptionMethods *)methods;
- (void)adornSchema:(GTLDiscoveryJsonSchema *)schema
               name:(NSString *)schemaName
       parentSchema:(GTLDiscoveryJsonSchema *)parentSchema;
- (void)adornSchemas:(GTLObject *)schemas
        parentSchema:(GTLDiscoveryJsonSchema *)parentSchema;

- (NSString *)legalBlock;
- (NSString *)generatedInfo;
- (NSString *)serviceClassGeneratedInfo;
- (NSString *)queryClassesGeneratedInfo;
- (NSString *)schemaClassesGeneratedInfo:(GTLDiscoveryJsonSchema *)schema;
- (NSSet *)methodObjectTopLevelClassDeps;
- (NSString *)generateQueryMethodParametersBlockForMode:(GeneratorMode)mode;
- (NSString *)generateQueryClassForMode:(GeneratorMode)mode;
- (NSSet *)neededClassesForSchema:(GTLDiscoveryJsonSchema *)schema;
- (NSArray *)recursivelyNeededClassesForSchemaSorted:(GTLDiscoveryJsonSchema *)schema;
- (NSString *)generateObjectClassForSchema:(GTLDiscoveryJsonSchema *)schema
                                   forMode:(GeneratorMode)mode
                   includeClassDescription:(BOOL)includeClassDescription
                         extraClassComment:(NSString *)extraClassComment;
- (NSArray *)constantsBlocksForMode:(GeneratorMode)mode;
- (NSString *)authorizationScopeToConstant:(NSString *)scope;

- (NSString *)frameworkedImport:(NSString *)headerName;
- (void)addWarning:(NSString *)warningString;
- (void)addInfo:(NSString *)infoString;
@end

// Helper to get the objects of a dictionary out in a sorted order.
static NSArray *DictionaryObjectsSortedByKeys(NSDictionary *dict) {
  NSArray *allKeys = [dict allKeys];
  NSArray *sortedKeys =
    [allKeys sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
  NSArray *result = [dict objectsForKeys:sortedKeys
                          notFoundMarker:[NSNull null]];
  return result;
}

static NSString *ConstantName(NSString *grouping, NSString *name) {
  // Some constants are things like "@self", so remove the "@" for the name
  // we generated.
  if ([name hasPrefix:@"@"]) {
    name = [name substringFromIndex:1];
  }

  // Some services use enum values that are all caps. These end up looking
  // pretty bad, so if the name is all caps, we downcase it and hope that
  // ends up better.
  if ([name isEqual:[name uppercaseString]]) {
    name = [name lowercaseString];
  }

  NSString *formattedName = [FHUtils objcName:name shouldCapitalize:YES];
  NSString *result =
    [NSString stringWithFormat:@"k%@%@", grouping, formattedName];
  return result;
}

@implementation FHGenerator

@synthesize api = api_,
            verboseLevel = verboseLevel_,
            allowRootURLOverrides = allowRootURLOverrides_;

@synthesize warnings = warnings_,
            infos = infos_;

+ (instancetype)generatorForApi:(GTLDiscoveryRpcDescription *)api
                   verboseLevel:(NSUInteger)verboseLevel
          allowRootURLOverrides:(BOOL)allowRootURLOverrides
          formattedNameOverride:(NSString *)formattedNameOverride
               skipIfLikelyREST:(BOOL)skipIfLikelyREST {
  return [[[self alloc] initWithApi:api
                       verboseLevel:verboseLevel
              allowRootURLOverrides:allowRootURLOverrides
              formattedNameOverride:formattedNameOverride
                   skipIfLikelyREST:skipIfLikelyREST] autorelease];
}

- (instancetype)initWithApi:(GTLDiscoveryRpcDescription *)api
               verboseLevel:(NSUInteger)verboseLevel
      allowRootURLOverrides:(BOOL)allowRootURLOverrides
      formattedNameOverride:(NSString *)formattedNameOverride
           skipIfLikelyREST:(BOOL)skipIfLikelyREST {
  self = [super init];
  if (self != nil) {
    api_ = [api retain];
    verboseLevel_ = verboseLevel;
    allowRootURLOverrides_ = allowRootURLOverrides;
    formattedName_ = [formattedNameOverride copy];
    if (!api) {
      [self release];
      self = nil;
    } else {
      NSValue *generatorAsValue = [NSValue valueWithNonretainedObject:self];
      [self.api setProperty:generatorAsValue forKey:kWrappedGeneratorKey];

      // Support skipping general setup if the api is likely REST as it won't
      // be generated over in FHMain, and we don't need the warnings/errors that
      // could come from doing the setup.
      BOOL skipSetup = (skipIfLikelyREST && [self.api likelyRESTOnlyAPI]);
      if (!skipSetup) {
        // The discovery document is odd in that the names of things are the
        // keys in the dictionary, so the dict that is the item doesn't actually
        // have its name.  So run through the tree setting up the name as
        // a property so we have it.  While we're at it, also give resources
        // pointers to their parents.
        [self adornSchemas:self.api.schemas parentSchema:nil];
        [self adornMethods:self.api.methods];

        // Spin over the common parameters
        for (NSString *paramName in self.api.parameters.additionalProperties) {
          GTLDiscoveryJsonSchema *parameter =
            [self.api.parameters.additionalProperties objectForKey:paramName];
          [self adornSchema:parameter name:paramName parentSchema:nil];
          [parameter setProperty:[NSValue valueWithNonretainedObject:nil]
                          forKey:kWrappedMethodKey];

        } // Parameters Loop
      }

      // Anything that starts "new", "copy", or "mutableCopy" (and maybe continues
      // with a capital letter) can trip up a clang warning about not following
      // normal cocoa naming conventions, match them and add the directive
      // to tell the compiler what model to enforce.
      notRetainedPredicate_ =
        [NSPredicate predicateWithFormat:@"SELF matches %@",
         @"^(new|copy|mutableCopy)([A-Z].*)?"];

      // Anything that starts "init" (and maybe continues with a capital letter or
      // underscore) can trip up clang (as of Xcode 5's ARC support) into thinking
      // it is a init method and thus should return a object of the same type as
      // the class the method is on. This can be avoid by adding a custom getter
      // to tweak the actual method name.
      useCustomerGetterPredicate_ =
        [NSPredicate predicateWithFormat:@"SELF matches %@",
         @"^(init)([A-Z_].*)?"];
    }
  }
  return self;
}

- (void)dealloc {
  api_.userProperties = nil;
  [api_ release];
  [warnings_ release];
  [infos_ release];
  [formattedName_ release];

  [super dealloc];
}

- (void)adornMethods:(GTLDiscoveryRpcDescriptionMethods *)methods {
  NSValue *generatorAsValue = [NSValue valueWithNonretainedObject:self];

  // methods could be a GTLDiscoveryResourceMethods or GTLDiscoveryDescribeItemMethods

  // Spin over the methods
  for (NSString *methodName in methods.additionalProperties) {
    GTLDiscoveryRpcMethod *method =
      [methods.additionalProperties objectForKey:methodName];

    [method setProperty:methodName forKey:kNameKey];
    [method setProperty:generatorAsValue forKey:kWrappedGeneratorKey];

    [method.returns setProperty:generatorAsValue forKey:kWrappedGeneratorKey];
    [method.returns setProperty:[methodName stringByAppendingString:@"-Returns"]
                         forKey:kNameKey];
    [method.returns.resolvedSchema setProperty:@YES forKey:kReturnsSchemaParameterKey];

    // Spin over the parameters
    for (NSString *paramName in method.parameters.additionalProperties) {
      GTLDiscoveryJsonSchema *parameter =
        [method.parameters.additionalProperties objectForKey:paramName];

      [self adornSchema:parameter name:paramName parentSchema:nil];
      [parameter setProperty:[NSValue valueWithNonretainedObject:method]
                      forKey:kWrappedMethodKey];

    } // Parameters Loop
  } // Methods Loop
}

- (void)adornSchema:(GTLDiscoveryJsonSchema *)schema
               name:(NSString *)schemaName
       parentSchema:(GTLDiscoveryJsonSchema *)parentSchema {
  if (schema == nil) return;

  [schema setProperty:schemaName forKey:kNameKey];
  [schema setProperty:[NSValue valueWithNonretainedObject:parentSchema]
               forKey:kWrappedSchemaKey];
  [schema setProperty:[NSValue valueWithNonretainedObject:self]
               forKey:kWrappedGeneratorKey];

  [self adornSchemas:schema.properties parentSchema:schema];
  [self adornSchema:schema.items name:@"item" parentSchema:schema];
  [schema.items setProperty:@YES forKey:kIsItemsSchemaKey];

  // If the this schema's name ends in 's', drop it and use it for the
  // name of the subschema.  If the schema had properties, add "additions"
  // to the name to try to make them distinct.
  NSString *worker = schema.name;
  if ([worker hasSuffix:@"s"]) {
    worker = [worker substringToIndex:[worker length] - 1];
  }
  if ([schema.properties.additionalProperties count] != 0) {
    worker = [worker stringByAppendingString:@"Additions"];
  }

  [self adornSchema:schema.additionalPropertiesProperty
               name:worker
       parentSchema:schema];
}

- (void)adornSchemas:(GTLObject *)schemas
        parentSchema:(GTLDiscoveryJsonSchema *)parentSchema {

  // Schemas could be GTLDiscoveryRpcDescriptionSchemas or
  // GTLDiscoveryJsonSchemaProperties.
  for (NSString *schemaName in schemas.additionalProperties) {
    GTLDiscoveryJsonSchema *schema =
      [schemas.additionalProperties objectForKey:schemaName];
    [self adornSchema:schema
                 name:schemaName
         parentSchema:parentSchema];
  }
}

- (NSDictionary *)generateFilesWithHandler:(void (^)(FHGeneratorHandlerMessageType msgType,
                                                     NSString *message))messageHandler {
  if (!messageHandler) return nil;

  // Preflight as much as possible so multiple errors can be reported before
  // giving up.

  BOOL gotError = NO;

  NSArray *apiUnknowns = [self.api additionalJSONKeys];
  if (apiUnknowns != nil) {
    NSString *warning =
      [NSString stringWithFormat:@"service api has unexpected JSON %s: %@",
                                 ( [apiUnknowns count] > 1 ? "keys" : "key" ),
                                 [apiUnknowns componentsJoinedByString:@", "]];
    messageHandler(kFHGeneratorHandlerMessageWarning, warning);
  }

  // Sanity check anything on the service itself.
  if ([self.api likelyRESTOnlyAPI]) {
    NSString *str =
      [NSString stringWithFormat:@"This appears to be a REST only api, and can't be supported via JSON-RPC (rootUrl: \"%@\", rpcPath: \"%@\", older rpcUrl: \"%@\")",
       self.api.rootUrl, self.api.rpcPath, self.api.rpcUrl];
    messageHandler(kFHGeneratorHandlerMessageError, str);
    gotError = YES;
  } else if ([[self.api builtRPCUrlString] length] == 0) {
    NSString *str =
      [NSString stringWithFormat:@"Unable to determine RPC URL (rootUrl: \"%@\", rpcPath: \"%@\", older rpcUrl: \"%@\")",
       self.api.rootUrl, self.api.rpcPath, self.api.rpcUrl];
    messageHandler(kFHGeneratorHandlerMessageError, str);
    gotError = YES;
  }

  // Spin over the methods, checking for things that map to the same name
  NSMutableDictionary *worker = [NSMutableDictionary dictionary];
  NSArray *allUnorderedMethods = [self.api.methods.additionalProperties allValues];
  for (GTLDiscoveryRpcMethod *method in allUnorderedMethods) {
    GTLDiscoveryRpcMethod *previousMethod = [worker objectForKey:method.objcQueryForName];
    if (previousMethod) {
      NSString *errStr =
        [NSString stringWithFormat:@"Both '%@' and '%@' have the ObjC Query name '%@'",
         method.name, previousMethod.name, method.objcQueryForName];
      messageHandler(kFHGeneratorHandlerMessageError, errStr);
      gotError = YES;
    } else {
      [worker setObject:method forKey:method.objcQueryForName];
    }
  }

  // Build the allParameters and uniqueParamters lists, collecting warnings or
  // errors.
  if (![self.api buildParameterLists:messageHandler]) {
    gotError = YES;
  }

  NSMutableDictionary *kindMap = [NSMutableDictionary dictionary];
  for (GTLDiscoveryJsonSchema *schema in self.api.allSchemas) {
    NSArray *schemaUnknowns = [schema additionalJSONKeys];
    if (schemaUnknowns != nil) {
      NSString *warning =
        [NSString stringWithFormat:@"schema '%@(%@)' has unexpected JSON %s: %@",
                                   schema.name, schema.fullSchemaName,
                                   ( [schemaUnknowns count] > 1 ? "keys" : "key" ),
                                   [schemaUnknowns componentsJoinedByString:@", "]];
      messageHandler(kFHGeneratorHandlerMessageWarning, warning);
    }
    // Yuck.  For reasons I won't claim to fully understand, servers can have
    // templates that result in two different schema with the same 'kind'
    // value.  The way this happens, the server ends up giving them the same
    // name and putting counter ("2") on the schema id to give them different
    // IDs.  Try to trap this to make sure we only give one of them a +load
    // method so our runtime support can do its best to deal with it.
    // NOTE: I don't think the server has a defined behavior as to if the
    // numbered or unnumbered version is the better choice, so for now we
    // just pick the unnumbered one and hope for the best.
    // NOTE: As of Jan 2012, the server is merging schema, so this should not
    // be happening anymore.
    NSString *kindToRegister = schema.kindToRegister;
    if (kindToRegister != nil) {
      GTLDiscoveryJsonSchema *otherSchema =
        [kindMap objectForKey:kindToRegister];
      if (otherSchema == nil) {
        [kindMap setObject:schema forKey:kindToRegister];
      } else {
        [schema setProperty:@"skip" forKey:kSkipRegisteringKindKey];
        [otherSchema setProperty:@"skip" forKey:kSkipRegisteringKindKey];
        NSString *warning =
          [NSString stringWithFormat:@"schemas '%@(%@)' and '%@(%@)' have the the same kind (%@), won't create +load method for %@ or %@, but that's probably not right.",
                                     schema.name, schema.fullSchemaName,
                                     otherSchema.name, otherSchema.fullSchemaName,
                                     kindToRegister,
                                     schema.objcClassName, otherSchema.objcClassName];
        messageHandler(kFHGeneratorHandlerMessageWarning, warning);
      }
    }
  }

  for (GTLDiscoveryRpcMethod *method in self.api.allMethods) {
    NSArray *methodUnknowns = [method additionalJSONKeys];
    if (methodUnknowns != nil) {
      NSString *warning =
        [NSString stringWithFormat:@"method '%@' has unexpected JSON %s: %@",
                                   method.name,
                                   ( [methodUnknowns count] > 1 ? "keys" : "key" ),
                                   [methodUnknowns componentsJoinedByString:@", "]];
      messageHandler(kFHGeneratorHandlerMessageWarning, warning);
    }
    if ((verboseLevel_ > 0) && [method.supportsMediaDownload boolValue]) {
      NSString *info =
        [NSString stringWithFormat:@"method '%@' supports media download.",
         method.name];
      messageHandler(kFHGeneratorHandlerMessageInfo, info);
    }
  }

  for (GTLDiscoveryJsonSchema *parameter in self.api.allParameters) {
    NSArray *parameterUnknowns = [parameter additionalJSONKeys];
    if (parameterUnknowns != nil) {
      NSString *warning =
        [NSString stringWithFormat:@"parameter '%@' on method '%@' has unexpected JSON %s: %@",
                                   parameter.name,
                                   parameter.method.name,
                                   ( [parameterUnknowns count] > 1 ? "keys" : "key" ),
                                   [parameterUnknowns componentsJoinedByString:@", "]];
      messageHandler(kFHGeneratorHandlerMessageWarning, warning);
    }
  }

  // That's all the preflighting we can do. Any errors from here out are
  // thrown as NSExceptions.
  if (gotError) return nil;

  // Generate all the files...

  NSString *serviceHeader = self.serviceHeader;
  NSString *serviceSource = self.serviceSource;
  NSString *serviceFileNameBase = self.objcServiceClassName;

  NSString *queryHeader = self.queryHeader;
  NSString *querySource = self.querySource;
  NSString *queryFileNameBase = self.objcQueryClassName;

  NSMutableDictionary *result = [[@{
    [serviceFileNameBase stringByAppendingPathExtension:@"h"] : serviceHeader,
    [serviceFileNameBase stringByAppendingPathExtension:@"m"] : serviceSource,
    [queryFileNameBase stringByAppendingPathExtension:@"h"] : queryHeader,
    [queryFileNameBase stringByAppendingPathExtension:@"m"] : querySource,
  } mutableCopy] autorelease];

  for (GTLDiscoveryJsonSchema *schema in self.api.topLevelObjectSchemas) {
    NSString *objectClassFileNameBase = schema.objcClassName;

    NSString *objectClassHeader = [self headerForSchema:schema];
    NSString *objectClassSource = [self sourceForSchema:schema];

    [result setObject:objectClassHeader
               forKey:[objectClassFileNameBase stringByAppendingPathExtension:@"h"]];
    [result setObject:objectClassSource
               forKey:[objectClassFileNameBase stringByAppendingPathExtension:@"m"]];
  }

  NSString *constantsHeader = self.constantsHeader;
  NSString *constantsSource = self.constantsSource;
  NSString *constantsFileNameBase = self.constantsBase;
  if (constantsHeader != nil) {
    [result setObject:constantsHeader
               forKey:[constantsFileNameBase stringByAppendingPathExtension:@"h"]];
    [result setObject:constantsSource
               forKey:[constantsFileNameBase stringByAppendingPathExtension:@"m"]];
  }

  // Generate the service "master" header and "AllSources" source.

  NSString *masterHeaderName = self.masterHeaderName;
  NSString *allSourcesSourceName = self.allSourcesSourceName;

  NSMutableArray *headerParts = [NSMutableArray array];
  NSMutableArray *sourceParts = [NSMutableArray array];

  [headerParts addObject:[self legalBlock]];
  [sourceParts addObject:[self legalBlock]];

  NSString *nameBlock = [NSString stringWithFormat:@"//\n//  %@\n//\n",
                         masterHeaderName];
  [headerParts addObject:nameBlock];

  nameBlock =
    [NSString stringWithFormat:
      @"//\n"
      @"//  %@\n"
      @"//\n"
      @"// This file can be compiled into projects to avoid adding the individual\n"
      @"// source files for this service.\n"
      @"//\n", allSourcesSourceName];
  [sourceParts addObject:nameBlock];

  NSString *generatedInfo = [self generatedInfo];
  [headerParts addObject:generatedInfo];
  [sourceParts addObject:generatedInfo];

  if (constantsHeader != nil) {
    NSString *constantsInclude =
      [NSString stringWithFormat:@"#import \"%@.h\"\n", constantsFileNameBase];
    [headerParts addObject:constantsInclude];
  }
  if (constantsSource != nil) {
    NSString *constantsInclude =
      [NSString stringWithFormat:@"#import \"%@.m\"\n", constantsFileNameBase];
    [sourceParts addObject:constantsInclude];
  }

  NSMutableString *dataClassHeaderImports = [NSMutableString string];
  NSMutableString *dataClassSourceImports = [NSMutableString string];
  for (GTLDiscoveryJsonSchema *schema in self.api.topLevelObjectSchemas) {
    NSString *name = schema.objcClassName;
    [dataClassHeaderImports appendFormat:@"#import \"%@.h\"\n", name];
    [dataClassSourceImports appendFormat:@"#import \"%@.m\"\n", name];
  }
  if ([dataClassHeaderImports length]) {
    [headerParts addObject:dataClassHeaderImports];
  }
  if ([dataClassSourceImports length]) {
    [sourceParts addObject:dataClassSourceImports];
  }

  NSMutableString *queryAndServiceImport = [NSMutableString string];
  [queryAndServiceImport appendFormat:@"#import \"%@.h\"\n", queryFileNameBase];
  [queryAndServiceImport appendFormat:@"#import \"%@.h\"\n", serviceFileNameBase];
  [headerParts addObject:queryAndServiceImport];
  queryAndServiceImport = [NSMutableString string];
  [queryAndServiceImport appendFormat:@"#import \"%@.m\"\n", queryFileNameBase];
  [queryAndServiceImport appendFormat:@"#import \"%@.m\"\n", serviceFileNameBase];
  [sourceParts addObject:queryAndServiceImport];

  NSString *masterHeader = [headerParts componentsJoinedByString:@"\n"];
  NSString *allSourcesSource = [sourceParts componentsJoinedByString:@"\n"];

  [result setObject:masterHeader forKey:masterHeaderName];
  [result setObject:allSourcesSource forKey:allSourcesSourceName];

  // Report any infos/warnings added during generation.
  for (NSString *infoString in self.infos) {
    messageHandler(kFHGeneratorHandlerMessageInfo, infoString);
  }
  for (NSString *warningString in self.warnings) {
    messageHandler(kFHGeneratorHandlerMessageWarning, warningString);
  }

  return result;
}

- (NSString *)formattedApiName {
  if (formattedName_ == nil) {
    NSString *canonicalName = self.api.canonicalName;
    if ([canonicalName length] > 0) {
      // If there was a canonical name, remove the spaces and run it through
      // the objcName cleanup just to make sure there aren't any invalid
      // characters.
      NSString *worker =
        [canonicalName stringByReplacingOccurrencesOfString:@" "
                                                 withString:@""];
      formattedName_ = [[FHUtils objcName:worker
                         shouldCapitalize:YES
                       allowLeadingDigits:YES] retain];
    }
    if (formattedName_ == nil) {
      formattedName_ =
        [[FHUtils objcName:self.api.name shouldCapitalize:YES] retain];
    }
  }
  return formattedName_;
}

- (BOOL)likelyRESTOnlyAPI {
  return self.api.likelyRESTOnlyAPI;
}

- (NSString *)objcServiceClassName {
  NSString *result = [NSString stringWithFormat:@"%@Service%@",
                      kProjectPrefix, self.formattedApiName];
  return result;
}

- (NSString *)objcQueryClassName {
  NSString *result = [NSString stringWithFormat:@"%@Query%@",
                      kProjectPrefix, self.formattedApiName];
  return result;
}

- (NSString *)constantsBase {
  NSString *result = [NSString stringWithFormat:@"%@%@Constants",
                      kProjectPrefix, self.formattedApiName];
  return result;
}

- (NSString *)masterHeaderName {
  NSString *result = [NSString stringWithFormat:@"%@%@.h",
                      kProjectPrefix, self.formattedApiName];
  return result;
}

- (NSString *)allSourcesSourceName {
  NSString *result = [NSString stringWithFormat:@"%@%@_Sources.m",
                      kProjectPrefix, self.formattedApiName];
  return result;
}

// Generates the service class header body.
- (NSString *)serviceHeader {
  NSMutableArray *parts = [NSMutableArray array];

  [parts addObject:[self legalBlock]];

  NSString *nameBlock = [NSString stringWithFormat:@"//\n//  %@.h\n//\n",
                         self.objcServiceClassName];
  [parts addObject:nameBlock];

  NSString *generatedInfo = [self serviceClassGeneratedInfo];
  [parts addObject:generatedInfo];

  NSString *importServiceBase = [self frameworkedImport:kServiceBaseClass];
  [parts addObject:importServiceBase];

  NSString *interfaceDecl = [NSString stringWithFormat:@"@interface %@ : %@\n",
                             self.objcServiceClassName, kServiceBaseClass];
  [parts addObject:interfaceDecl];

  // No custom methods, it just overrides base methods.  Include a usage
  // message.
  [parts addObject:@"// No new methods\n"];
  NSMutableString *usageStr = [NSMutableString string];
  NSString *kUsageFormatString =
    @"Clients should create a standard query with any of the class methods in "
    @"%@.h.  The query can the be sent with GTLService's execute methods,";
  NSString *usagePreamble = [NSString stringWithFormat:kUsageFormatString,
                             self.objcQueryClassName];
  NSString *usagePreambleWrapped = [FHUtils stringOfLinesFromString:usagePreamble
                                                         linePrefix:@"// "];
  [usageStr appendString:usagePreambleWrapped];
  NSString *kUsageRest =
    @"//\n"
    @"//   - (GTLServiceTicket *)executeQuery:(GTLQuery *)query\n"
    @"//                    completionHandler:(void (^)(GTLServiceTicket *ticket,\n"
    @"//                                                id object, NSError *error))handler;\n"
    @"// or\n"
    @"//   - (GTLServiceTicket *)executeQuery:(GTLQuery *)query\n"
    @"//                             delegate:(id)delegate\n"
    @"//                    didFinishSelector:(SEL)finishedSelector;\n"
    @"//\n"
    @"// where finishedSelector has a signature of:\n"
    @"//\n"
    @"//   - (void)serviceTicket:(GTLServiceTicket *)ticket\n"
    @"//      finishedWithObject:(id)object\n"
    @"//                   error:(NSError *)error;\n"
    @"//\n"
    @"// The object passed to the completion handler or delegate method\n"
    @"// is a subclass of GTLObject, determined by the query method executed.\n";
  [usageStr appendString:kUsageRest];
  [parts addObject:usageStr];

  [parts addObject:@"@end\n"];

  return [parts componentsJoinedByString:@"\n"];
}

// Generates the service class source body.
- (NSString *)serviceSource {
  NSMutableArray *parts = [NSMutableArray array];

  [parts addObject:[self legalBlock]];

  NSString *nameBlock = [NSString stringWithFormat:@"//\n//  %@.m\n//\n",
                         self.objcServiceClassName];
  [parts addObject:nameBlock];

  NSString *generatedInfo = [self serviceClassGeneratedInfo];
  [parts addObject:generatedInfo];

  NSString *headerImport = [NSString stringWithFormat:@"#import \"%@\"\n",
                            self.masterHeaderName];
  [parts addObject:headerImport];

  NSString *interfaceDecl = [NSString stringWithFormat:@"@implementation %@\n",
                             self.objcServiceClassName];
  [parts addObject:interfaceDecl];

  // Add a debug initialize method to make sure all the needed classes are
  // compiled in.
  NSMutableString *initializeMethod = [NSMutableString string];
  [initializeMethod appendString:@"#if DEBUG\n"];
  NSString *comment =
    @"Method compiled in debug builds just to check that all the needed "
    @"support classes are present at link time.";
  NSString *wrappedComment = [FHUtils stringOfLinesFromString:comment
                                                   linePrefix:@"// "];
  [initializeMethod appendString:wrappedComment];
  [initializeMethod appendString:@"+ (NSArray *)checkClasses {\n"];
  [initializeMethod appendString:@"  NSArray *classes = @[\n"];
  [initializeMethod appendFormat:@"    [%@ class]", self.objcQueryClassName];
  for (GTLDiscoveryJsonSchema *schema in self.api.topLevelObjectSchemas) {
    [initializeMethod appendFormat:@",\n    [%@ class]", schema.objcClassName];
  }
  [initializeMethod appendString:@"\n  ];\n"];
  [initializeMethod appendString:@"  return classes;\n"];
  [initializeMethod appendString:@"}\n"];
  [initializeMethod appendString:@"#endif  // DEBUG\n"];

  [parts addObject:initializeMethod];

  NSString *rpcURLString = [self.api builtRPCUrlString];
  NSString *rpcUploadUrlString = nil;
  if ([self.api hasMediaUploadMethods]) {
    // There currently isn't any way to generate the media URL, so it is
    // hardcoded for Google services.
    if ([self.api isGoogleService]) {
      rpcUploadUrlString =
        [FHUtils URLString:@"https://www.googleapis.com/upload/rpc"
               addingParam:@"uploadType"
                     value:@"resumable"];
    } else {
      NSString *str =
        @"API supports media upload, but not a Google service; no rpcUploadURL is generated.";
      [self addWarning:str];
    }
  }
  NSString *rpcURLComment = nil;

  GTLDiscoveryJsonSchema *prettyPrintParameter =
    [self.api.parameters additionalPropertyForName:@"prettyPrint"];
  if (prettyPrintParameter) {
    // No matter what the default might be for prettyPrint, make sure it is
    // turned off to save wire bandwidth.
    rpcURLString = [FHUtils URLString:rpcURLString
                          addingParam:@"prettyPrint"
                                value:@"false"];
    rpcUploadUrlString = [FHUtils URLString:rpcUploadUrlString
                                addingParam:@"prettyPrint"
                                      value:@"false"];
    NSString *rawComment =
      @"Turn off prettyPrint for this service to save bandwidth (especially on"
      @" mobile).  The fetcher logging will pretty print.";
    rpcURLComment = [FHUtils stringOfLinesFromString:rawComment
                                          linePrefix:@"    // "];
  }

  // Provide -init to set the default values.
  NSMutableString *initMethod = [NSMutableString string];
  [initMethod appendString:@"- (instancetype)init {\n"];
  [initMethod appendString:@"  self = [super init];\n"];
  [initMethod appendString:@"  if (self) {\n"];
  [initMethod appendString:@"    // Version from discovery.\n"];
  [initMethod appendFormat:@"    self.apiVersion = @\"%@\";\n", self.api.version];
  [initMethod appendString:@"\n"];
  [initMethod appendString:@"    // From discovery.  Where to send JSON-RPC.\n"];
  if (rpcURLComment != nil) {
    [initMethod appendString:rpcURLComment];
  }
  [initMethod appendFormat:@"    self.rpcURL = [NSURL URLWithString:@\"%@\"];\n", rpcURLString];
  if (rpcUploadUrlString) {
    [initMethod appendFormat:@"    self.rpcUploadURL = [NSURL URLWithString:@\"%@\"];\n", rpcUploadUrlString];
  }
  if ([self.api.features containsObject:@"dataWrapper"]) {
    [initMethod appendString:@"\n"];
    [initMethod appendString:@"    // If REST queries are made, this service uses the 'data' wrapper on\n"];
    [initMethod appendString:@"    // results.\n"];
    [initMethod appendString:@"    self.isRESTDataWrapperRequired = YES;\n"];
  }
  [initMethod appendString:@"  }\n"];
  [initMethod appendString:@"  return self;\n"];
  [initMethod appendString:@"}\n"];
  [parts addObject:initMethod];

  [parts addObject:@"@end\n"];

  return [parts componentsJoinedByString:@"\n"];
}

// Generates the service's query header body.
- (NSString *)queryHeader {
  NSMutableArray *parts = [NSMutableArray array];

  [parts addObject:[self legalBlock]];

  NSString *nameBlock = [NSString stringWithFormat:@"//\n//  %@.h\n//\n",
                         self.objcQueryClassName];
  [parts addObject:nameBlock];

  NSString *generatedInfo = [self queryClassesGeneratedInfo];
  [parts addObject:generatedInfo];

  NSString *importQueryBase = [self frameworkedImport:kQueryBaseClass];
  [parts addObject:importQueryBase];

  // Forward declare the classes used in query methods.
  NSMutableSet *neededClasses = [NSMutableSet set];
  [neededClasses addObjectsFromArray:[self.api.allMethodObjectParameterReferences valueForKey:@"objcClassName"]];
  [neededClasses unionSet:[self methodObjectTopLevelClassDeps]];
  if ([neededClasses count] > 0) {
    // Sort to stablize the order.
    NSArray *sortedClassNames =
      [[neededClasses allObjects] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
    NSMutableString *classForwards = [NSMutableString string];
    for (NSString *name in sortedClassNames) {
      [classForwards appendFormat:@"@class %@;\n", name];
    }
    [parts addObject:classForwards];
  }

  NSString *queryClassStr = [self generateQueryClassForMode:kGenerateInterface];
  [parts addObject:queryClassStr];

  NSString *methodParameterObjStr =
    [self generateQueryMethodParametersBlockForMode:kGenerateInterface];
  if ([methodParameterObjStr length] > 0) {
    [parts addObject:methodParameterObjStr];
  }

  return [parts componentsJoinedByString:@"\n"];
}

// Generates the service's query header body.
- (NSString *)querySource {
  NSMutableArray *parts = [NSMutableArray array];

  [parts addObject:[self legalBlock]];

  NSString *nameBlock = [NSString stringWithFormat:@"//\n//  %@.m\n//\n",
                         self.objcQueryClassName];
  [parts addObject:nameBlock];

  NSString *generatedInfo = [self queryClassesGeneratedInfo];
  [parts addObject:generatedInfo];

  NSString *headerImport = [NSString stringWithFormat:@"#import \"%@.h\"\n",
                            self.objcQueryClassName];
  [parts addObject:headerImport];

  // Import the classes used in query methods (here we also need the return
  // classes for the expectedObjectType).
  NSMutableSet *neededClasses = [NSMutableSet set];
  [neededClasses addObjectsFromArray:[self.api.allMethodObjectParameterReferences valueForKey:@"objcClassName"]];
  for (GTLDiscoveryRpcMethod *method in self.api.allMethods) {
    GTLDiscoveryJsonSchema *returnsSchema = method.returns.resolvedSchema;
    if (returnsSchema) {
      [neededClasses addObject:returnsSchema.objcClassName];
    }
  }
  [neededClasses unionSet:[self methodObjectTopLevelClassDeps]];
  if ([neededClasses count] > 0) {
    // Sort to stablize the order.
    NSArray *sortedClassNames =
      [[neededClasses allObjects] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
    // Only need to import the top level ones as those are files.
    NSArray *topLevelSchemaNames =
      [self.api.topLevelObjectSchemas valueForKey:@"objcClassName"];
    NSMutableString *classImports = [NSMutableString string];
    for (NSString *name in sortedClassNames) {
      if ([topLevelSchemaNames containsObject:name]) {
        [classImports appendFormat:@"#import \"%@.h\"\n", name];
      }
    }
    if ([classImports length] > 0) {
      [parts addObject:classImports];
    }
  }

  NSString *queryClassStr = [self generateQueryClassForMode:kGenerateImplementation];
  [parts addObject:queryClassStr];

  NSString *methodParameterObjStr =
    [self generateQueryMethodParametersBlockForMode:kGenerateImplementation];
  if ([methodParameterObjStr length] > 0) {
    [parts addObject:methodParameterObjStr];
  }

  return [parts componentsJoinedByString:@"\n"];
}

// Generates the legal block for the top of each file.
- (NSString *)legalBlock {
  // Get the year consistently by forcing the locale.
  NSLocale *enUSLocale = [[[NSLocale alloc] initWithLocaleIdentifier:@"en_US"] autorelease];
  NSDateFormatter *formatter = [[[NSDateFormatter alloc] init] autorelease];
  [formatter setDateFormat:@"yyyy"];
  [formatter setLocale:enUSLocale];
  NSString *yearStr = [formatter stringFromDate:[NSDate date]];

  // Google services get copyrights and license, but other APIs just get a
  // generation note.
  NSString *result;
  if ([self.api isGoogleService]) {
    result =
      [NSString stringWithFormat:
       @"/* Copyright (c) %@ Google Inc.\n"
       @" *\n"
       @" * Licensed under the Apache License, Version 2.0 (the \"License\");\n"
       @" * you may not use this file except in compliance with the License.\n"
       @" * You may obtain a copy of the License at\n"
       @" *\n"
       @" *     http://www.apache.org/licenses/LICENSE-2.0\n"
       @" *\n"
       @" * Unless required by applicable law or agreed to in writing, software\n"
       @" * distributed under the License is distributed on an \"AS IS\" BASIS,\n"
       @" * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\n"
       @" * See the License for the specific language governing permissions and\n"
       @" * limitations under the License.\n"
       @" */\n",
       yearStr];
  } else {
    result =
      [NSString stringWithFormat:
       @"/* This file was generated by the ServiceGenerator.\n"
       @" * The ServiceGenerator is Copyright (c) %@ Google Inc.\n"
       @" */\n",
       yearStr];
  }

  return result;
}

- (NSString *)constantsHeader {
  NSDictionary *enumsMap = self.api.enumsMap;
  if (([enumsMap count] == 0) && (self.api.auth.oauth2.scopes == nil)) {
    return nil;
  }

  NSMutableArray *parts = [NSMutableArray array];

  [parts addObject:[self legalBlock]];

  NSString *nameBlock = [NSString stringWithFormat:@"//\n//  %@.h\n//\n",
                         self.constantsBase];
  [parts addObject:nameBlock];

  NSString *generatedInfo = [self generatedInfo];
  [parts addObject:generatedInfo];

  [parts addObject:@"#import <Foundation/Foundation.h>\n"];

  NSString *definesName =
    [NSString stringWithFormat:@"%@Defines", kProjectPrefix];
  NSString *definesImport = [self frameworkedImport:definesName];
  [parts addObject:definesImport];

  NSArray *blocks = [self constantsBlocksForMode:kGenerateInterface];
  [parts addObjectsFromArray:blocks];

  return [parts componentsJoinedByString:@"\n"];
}

- (NSString *)constantsSource {
  NSDictionary *enumsMap = self.api.enumsMap;
  if (([enumsMap count] == 0) && (self.api.auth.oauth2.scopes == nil)) {
    return nil;
  }

  NSMutableArray *parts = [NSMutableArray array];

  [parts addObject:[self legalBlock]];

  NSString *nameBlock = [NSString stringWithFormat:@"//\n//  %@.m\n//\n",
                         self.constantsBase];
  [parts addObject:nameBlock];

  NSString *generatedInfo = [self generatedInfo];
  [parts addObject:generatedInfo];

  NSString *headerInclude =
    [NSString stringWithFormat:@"#import \"%@.h\"\n", self.constantsBase];
  [parts addObject:headerInclude];

  NSArray *blocks = [self constantsBlocksForMode:kGenerateImplementation];
  [parts addObjectsFromArray:blocks];

  return [parts componentsJoinedByString:@"\n"];
}

- (NSString *)headerForSchema:(GTLDiscoveryJsonSchema *)schema {
  NSMutableArray *parts = [NSMutableArray array];

  [parts addObject:[self legalBlock]];

  NSString *nameBlock = [NSString stringWithFormat:@"//\n//  %@.h\n//\n",
                         schema.objcClassName];
  [parts addObject:nameBlock];

  NSString *generatedInfo = [self schemaClassesGeneratedInfo:schema];
  [parts addObject:generatedInfo];

  NSString *importObjectBase = [self frameworkedImport:kBaseObjectClass];
  [parts addObject:importObjectBase];

  // Forward-declare the classes needed by the schema so they can reference
  // each other (i.e.-tree structures, etc.)
  NSArray *sortedAllNeededClasses = [self recursivelyNeededClassesForSchemaSorted:schema];
  if ([sortedAllNeededClasses count] > 0) {
    NSMutableArray *subParts = [NSMutableArray array];
    for (NSString *className in sortedAllNeededClasses) {
      NSString *aLine = [NSString stringWithFormat:@"@class %@;\n", className];
      [subParts addObject:aLine];
    }
    [parts addObject:[subParts componentsJoinedByString:@""]];
  }

  NSMutableArray *classParts = [NSMutableArray array];

  // Main schema for file.
  NSString *objectClassStr = [self generateObjectClassForSchema:schema
                                                        forMode:kGenerateInterface
                                        includeClassDescription:YES
                                              extraClassComment:nil];
  [classParts addObject:objectClassStr];

  // Child schema.
  for (GTLDiscoveryJsonSchema *subSchema in schema.childObjectSchemas) {
    NSString *subObjectClassStr = [self generateObjectClassForSchema:subSchema
                                                             forMode:kGenerateInterface
                                             includeClassDescription:NO
                                                   extraClassComment:nil];
    [classParts addObject:subObjectClassStr];
  }

  // Two blank lines between classes.
  [parts addObject:[classParts componentsJoinedByString:@"\n\n"]];

  return [parts componentsJoinedByString:@"\n"];
}

- (NSString *)sourceForSchema:(GTLDiscoveryJsonSchema *)schema {
  NSMutableArray *parts = [NSMutableArray array];

  [parts addObject:[self legalBlock]];

  NSString *nameBlock = [NSString stringWithFormat:@"//\n//  %@.m\n//\n",
                         schema.objcClassName];
  [parts addObject:nameBlock];

  NSString *generatedInfo = [self schemaClassesGeneratedInfo:schema];
  [parts addObject:generatedInfo];

  NSString *headerImport = [NSString stringWithFormat:@"#import \"%@.h\"\n",
                            schema.objcClassName];
  [parts addObject:headerImport];

  // If any additional properties used classes that were top level schema, we
  // need to include their headers so things compile.
  // NOTE: really only need the ones used as additional properties or as items
  // in additonal properties, but that's a bit heaver to calculate.
  NSArray *sortedAllNeededClasses = [self recursivelyNeededClassesForSchemaSorted:schema];
  if ([sortedAllNeededClasses count] > 0) {
    NSArray *topLevelSchemaNames =
      [self.api.topLevelObjectSchemas valueForKey:@"objcClassName"];
    NSMutableArray *subParts = [NSMutableArray array];
    for (NSString *className in sortedAllNeededClasses) {
      if (![className isEqual:schema.objcClassName] &&
          [topLevelSchemaNames containsObject:className]) {
        NSString *aLine = [NSString stringWithFormat:@"#import \"%@.h\"\n", className];
        [subParts addObject:aLine];
      }
    }
    if ([subParts count] > 0) {
      [parts addObject:[subParts componentsJoinedByString:@""]];
    }
  }

  NSMutableArray *classParts = [NSMutableArray array];
  NSString *objectClassStr = [self generateObjectClassForSchema:schema
                                                        forMode:kGenerateImplementation
                                        includeClassDescription:NO
                                              extraClassComment:nil];
  [classParts addObject:objectClassStr];
  for (GTLDiscoveryJsonSchema *subSchema in schema.childObjectSchemas) {
    NSString *subObjectClassStr = [self generateObjectClassForSchema:subSchema
                                                             forMode:kGenerateImplementation
                                             includeClassDescription:NO
                                                   extraClassComment:nil];
    [classParts addObject:subObjectClassStr];
  }
  // Two blank lines between classes.
  [parts addObject:[classParts componentsJoinedByString:@"\n\n"]];

  return [parts componentsJoinedByString:@"\n"];
}

// Generates the summary info for any file off this service.
- (NSString *)generatedInfo {
  NSMutableArray *generatedInfo = [NSMutableArray array];

  // NOTE: Filed Google bug 3068923 to get some sort of marker about the
  // service 'release' so we could really map this to host side info.
  // Putting a date in here means every run produces diffs which isn't
  // very helpful.

  //NSDateFormatter *formatter = [[[NSDateFormatter alloc] init] autorelease];
  //[formatter setFormatterBehavior:NSDateFormatterBehavior10_4];
  //[formatter setDateFormat:@"yyyy-MM-dd"];
  //NSString *dateStr = [formatter stringFromDate:[NSDate date]];

  [generatedInfo addObject:@"// ----------------------------------------------------------------------------\n"];
  [generatedInfo addObject:@"// NOTE: This file is generated from Google APIs Discovery Service.\n"];
  //[generatedInfo addObject:@"// Generated:\n"];
  //NSString *generatedLine = [NSString stringWithFormat:@"//   %@\n", dateStr];
  //[generatedInfo addObject:generatedLine];
  [generatedInfo addObject:@"// Service:\n"];
  NSString *serviceLine = nil;
  if ([self.api.title length] > 0) {
    serviceLine = [NSString stringWithFormat:@"//   %@ (%@/%@)\n",
                   self.api.title,
                   self.api.name,
                   self.api.version];
  } else {
    serviceLine = [NSString stringWithFormat:@"//   %@/%@\n",
                   self.api.name,
                   self.api.version];
  }
  [generatedInfo addObject:serviceLine];

  NSString *serviceDescription = self.api.descriptionProperty;
  if ([serviceDescription length] > 0) {
    [generatedInfo addObject:@"// Description:\n"];
    NSString *wrappedServiceDescription = [FHUtils stringOfLinesFromString:serviceDescription
                                                                linePrefix:@"//   "];
    [generatedInfo addObject:wrappedServiceDescription];
  }
  NSString *serviceDocsLink = self.api.documentationLink;
  if ([serviceDocsLink length] > 0) {
    [generatedInfo addObject:@"// Documentation:\n"];
    NSString *linkLine =
      [NSString stringWithFormat:@"//   %@\n", serviceDocsLink];
    [generatedInfo addObject:linkLine];
  }

  NSString *result = [generatedInfo componentsJoinedByString:@""];
  return result;
}

// Generates a summary about the service class for the generated file comment
// in the service source/header.
- (NSString *)serviceClassGeneratedInfo {
  NSMutableString *result = [NSMutableString stringWithString:[self generatedInfo]];

  [result appendString:@"// Classes:\n"];
  NSString *classLine = [NSString stringWithFormat:@"//   %@ (0 custom class methods, 0 custom properties)\n",
                         self.objcServiceClassName];
  [result appendString:classLine];

  return result;
}

// Generates a summary about the query classes for the generated file comment
// in the query source/header.
- (NSString *)queryClassesGeneratedInfo {
  NSMutableString *result = [NSMutableString stringWithString:[self generatedInfo]];
  [result appendString:@"// Classes:\n"];
  NSString *classLine = [NSString stringWithFormat:@"//   %@ (%lu custom class methods, %lu custom properties)\n",
                         self.objcQueryClassName,
                         (unsigned long)[self.api.allMethods count],
                         (unsigned long)[self.api.uniqueParameters count]];
  [result appendString:classLine];

  // Method parameter objects
  NSArray *methodObjectParameters = self.api.allMethodObjectParameters;
  for (GTLDiscoveryJsonSchema *param in methodObjectParameters) {
    classLine = [NSString stringWithFormat:@"//   %@ (0 custom class methods, %lu custom properties)\n",
                 param.objcClassName,
                 (unsigned long)[param.properties.additionalProperties count]];
    [result appendString:classLine];
    // Any child schema/classes
    for (GTLDiscoveryJsonSchema *subSchema in param.childObjectSchemas) {
      classLine = [NSString stringWithFormat:@"//   %@ (0 custom class methods, %lu custom properties)\n",
                   subSchema.objcClassName,
                   (unsigned long)[subSchema.properties.additionalProperties count]];
      [result appendString:classLine];
    }
  }

  return result;
}

// Generates a summary about the schema classes for the generated file comment
// in the schema source/header.
- (NSString *)schemaClassesGeneratedInfo:(GTLDiscoveryJsonSchema *)schema {
  NSMutableString *result = [NSMutableString stringWithString:[self generatedInfo]];
  [result appendString:@"// Classes:\n"];

  // Main class
  NSString *classLine = [NSString stringWithFormat:@"//   %@ (0 custom class methods, %lu custom properties)\n",
                         schema.objcClassName,
                         (unsigned long)[schema.properties.additionalProperties count]];
  [result appendString:classLine];

  // Any child schema/classes
  for (GTLDiscoveryJsonSchema *subSchema in schema.childObjectSchemas) {
    classLine = [NSString stringWithFormat:@"//   %@ (0 custom class methods, %lu custom properties)\n",
                 subSchema.objcClassName,
                 (unsigned long)[subSchema.properties.additionalProperties count]];
    [result appendString:classLine];
  }

  return result;
}

- (NSSet *)methodObjectTopLevelClassDeps {
  NSMutableSet *worker = [NSMutableSet set];
  for (GTLDiscoveryJsonSchema *param in self.api.allMethodObjectParameters) {
    [worker addObjectsFromArray:[self recursivelyNeededClassesForSchemaSorted:param]];
  }
  if ([worker count]) {
    NSArray *topLevelSchemaNames =
        [self.api.topLevelObjectSchemas valueForKey:@"objcClassName"];
    [worker intersectSet:[NSSet setWithArray:topLevelSchemaNames]];
  }
  return worker;
}

- (NSString *)generateQueryMethodParametersBlockForMode:(GeneratorMode)mode {
  NSString *result = nil;

  // Query parameter objects
  NSArray *methodObjectParameters = self.api.allMethodObjectParameters;
  if ([methodObjectParameters count] > 0) {
    NSMutableArray *classesBlock = [NSMutableArray array];

    NSMutableString *sectionBlock = [NSMutableString string];
    [sectionBlock appendString:@"#pragma mark - method parameter objects\n"];
    [sectionBlock appendString:@"// These object are used only to pass a collection of parameters to a\n"];
    [sectionBlock appendString:@"// method as a single item.\n"];
    [classesBlock addObject:sectionBlock];

    for (GTLDiscoveryJsonSchema *param in methodObjectParameters) {
      NSMutableArray *aBlock = [NSMutableArray array];

      if (mode == kGenerateInterface) {
        // TODO: this is common with object class generation, it would be nice
        // to not repeat it.
        // Forward declare the classes needed by the schema so they can reference
        // each other (i.e.-tree structures, etc.)
        NSArray *sortedAllNeededClasses = [self recursivelyNeededClassesForSchemaSorted:param];
        if ([sortedAllNeededClasses count] > 0) {
          NSMutableArray *atClasses = [NSMutableArray array];
          NSArray *topLevelSchemaNames =
              [self.api.topLevelObjectSchemas valueForKey:@"objcClassName"];
          for (NSString *className in sortedAllNeededClasses) {
            if (![topLevelSchemaNames containsObject:className]) {
              NSString *aLine = [NSString stringWithFormat:@"@class %@;\n", className];
              [atClasses addObject:aLine];
            }
          }
          if ([atClasses count]) {
            [aBlock addObject:[atClasses componentsJoinedByString:@""]];
          }
        }
      }

      NSString *extraClassComment = nil;
      if (mode == kGenerateInterface) {
        GTLDiscoveryJsonSchema *methodParam = param.methodParam;
        extraClassComment =
          [NSString stringWithFormat:@"Used for '%@' parameter on '%@'.",
           methodParam.objcName, methodParam.method.name];
      }
      NSString *objectClassStr = [self generateObjectClassForSchema:param
                                                            forMode:mode
                                            includeClassDescription:(mode == kGenerateInterface)
                                                  extraClassComment:extraClassComment];
      [aBlock addObject:objectClassStr];

      // Child schema.
      for (GTLDiscoveryJsonSchema *subSchema in param.childObjectSchemas) {
        NSString *subObjectClassStr = [self generateObjectClassForSchema:subSchema
                                                                 forMode:mode
                                                 includeClassDescription:NO
                                                       extraClassComment:nil];
        [aBlock addObject:subObjectClassStr];
      }

      [classesBlock addObject:[aBlock componentsJoinedByString:@"\n"]];
    }

    result = [classesBlock componentsJoinedByString:@"\n"];
  }

  return result;
}

// Append "Param" to any name used as a local variable when generating the
// query method implementation to avoid duplication variables.
static NSString *MappedParamName(NSString *name) {
  NSString *result = name;

  if ([name isEqual:@"object"] ||
      [name isEqual:@"methodName"] ||
      [name isEqual:@"query"] ||
      [name isEqual:@"uploadParametersOrNil"]) {
    result = [name stringByAppendingString:@"_param"];
  }

  return result;
}

// Generates the the actual interface/implementation of a query class for the
// given service resource.
- (NSString *)generateQueryClassForMode:(GeneratorMode)mode {
  NSMutableArray *parts = [NSMutableArray array];
  NSMutableArray *subParts = [NSMutableArray array];

  NSString *atBlock;
  if (mode == kGenerateInterface) {
    atBlock = [NSString stringWithFormat:@"@interface %@ : %@\n",
               self.objcQueryClassName, kQueryBaseClass];
  } else {
    atBlock = [NSString stringWithFormat:@"@implementation %@\n",
               self.objcQueryClassName];
  }
  [parts addObject:atBlock];

  NSArray *uniqueParameters = self.api.uniqueParameters;
  if ([uniqueParameters count]) {
    // Write out the property support (QueryBase will fill them in at runtime).
    if (mode == kGenerateInterface) {
      NSMutableArray *commonParts = [NSMutableArray array];
      NSMutableArray *methodParts = [NSMutableArray array];
      for (GTLDiscoveryJsonSchema *param in uniqueParameters) {
        NSMutableArray *whichPart = methodParts;
        BOOL isCommonParam = (param.method == nil);
        if (isCommonParam) {
          whichPart = commonParts;
        }

        // Common parameters get descriptions since they aren't listed on
        // the actual query methods.
        if (isCommonParam) {
          if ([param.descriptionProperty length] > 0) {
            NSString *paramComment = [FHUtils stringOfLinesFromString:param.descriptionProperty
                                                           linePrefix:@"// "];
            [subParts addObject:paramComment];
          }
        }

        // If the ObjC name of a parameter was forced, include any comment
        // about that in the header with the @property declaration.
        NSString *forceObjCNameComment = param.forceNameComment;
        if (forceObjCNameComment != nil) {
          NSString *comment = [FHUtils stringOfLinesFromString:forceObjCNameComment
                                                    linePrefix:@"// "];
          [subParts addObject:comment];
        }

        NSString *objcType = nil, *objcPropertySemantics = nil;
        NSString *comment = nil;
        BOOL asPtr = NO;
        if ([param propertyForKey:kOverloadedParameterTypeKey] != nil) {
          objcType = @"id";
          objcPropertySemantics = @"retain";
          // NOTE: to report all the types here, when actually need to have
          // an easy way to get all of the different params with this name
          // on each query.
          NSString *overloadedComment =
          [NSString stringWithFormat:@"\"%@\" has different types for some query methods; see the documentation for the right type for each query method.",
             param.objcName];
          NSString *paramComment = [FHUtils stringOfLinesFromString:overloadedComment
                                                         linePrefix:@"// "];
          [subParts addObject:paramComment];
        } else {
          [param getQueryParamObjCType:&objcType
                             asPointer:&asPtr
                 objcPropertySemantics:&objcPropertySemantics
                               comment:&comment
                        itemsClassName:NULL];
        }
        if ([comment length] > 0) {
          comment = [@"  // " stringByAppendingString:comment];
        } else {
          comment = @"";
        }
        NSString *paramObjCName = param.objcName;
        NSString *extraAttributes = @"";
        if ([useCustomerGetterPredicate_ evaluateWithObject:paramObjCName]) {
          extraAttributes = [NSString stringWithFormat:@", getter=valueOf_%@", paramObjCName];
        }
        NSString *clangDirective = @"";
        if ((asPtr || [objcType isEqual:@"id"])
            && [notRetainedPredicate_ evaluateWithObject:paramObjCName]) {
          clangDirective = @" NS_RETURNS_NOT_RETAINED";
        }
        NSString *propertyLine = [NSString stringWithFormat:@"@property (nonatomic, %@%@) %@%@%@%@;%@\n",
                                  objcPropertySemantics, extraAttributes, objcType,
                                  (asPtr ? @" *" : @" "),
                                  paramObjCName,
                                  clangDirective,
                                  comment];
        [subParts addObject:propertyLine];

        [whichPart addObject:[subParts componentsJoinedByString:@""]];
        [subParts removeAllObjects];
      }

      if ([commonParts count] > 0) {
        [parts addObject:@"//\n// Parameters valid on all methods.\n//\n"];
        [parts addObject:[commonParts componentsJoinedByString:@"\n"]];
      }
      if ([methodParts count] > 0) {
        [methodParts insertObject:@"//\n// Method-specific parameters; see the comments below for more information.\n//\n"
                          atIndex:0];
        [parts addObject:[methodParts componentsJoinedByString:@""]];
      }
    } else {
      NSArray *uniqueParamsObjCNames = [uniqueParameters valueForKey:@"objcName"];
      NSString *asLines = [FHUtils stringOfLinesFromStrings:uniqueParamsObjCNames
                                            firstLinePrefix:@"@dynamic "
                                           extraLinesPrefix:@"         "
                                                linesSuffix:@","
                                             lastLineSuffix:@";"
                                              elementJoiner:@", "];
      [parts addObject:asLines];
    }

    if (mode == kGenerateImplementation) {

      // Keep a mapping for ObjC names to "wire" names for parameters that
      // had invalid characters.
      NSMutableDictionary *pairs = [NSMutableDictionary dictionary];
      for (GTLDiscoveryJsonSchema *param in uniqueParameters) {
        if (![param.name isEqual:param.objcName]) {
          [pairs setObject:param.name forKey:param.objcName];
        }
      }
      if ([pairs count] != 0) {
        NSString *methodImpl = [FHUtils classMapForMethodNamed:@"parameterNameMap"
                                                         pairs:pairs
                                                   quoteValues:YES];
        [parts addObject:methodImpl];
      }

      // For all repeated parameters, provide a mapping to the default class
      // contained within the array. We skip this if the param was overloaded
      // because it gets a generic object type instead.
      [pairs removeAllObjects];
      for (GTLDiscoveryJsonSchema *param in self.api.uniqueRepeatedParameters) {
        if (![param propertyForKey:kOverloadedParameterTypeKey]) {
          NSString *objcType = nil;
          NSString *itemsClassName = nil;
          [param getQueryParamObjCType:&objcType
                             asPointer:NULL
                 objcPropertySemantics:NULL
                               comment:NULL
                        itemsClassName:&itemsClassName];
          if ([itemsClassName isEqual:@"id"] ||
              ([param propertyForKey:kOverloadedParameterArrayItemKey] != nil)) {
            itemsClassName = @"NSObject";
          }
          NSString *getClassStr =
            [NSString stringWithFormat:@"[%@ class]", itemsClassName];
          [pairs setObject:getClassStr forKey:param.name];
        }
      }
      if ([pairs count] != 0) {
        NSString *methodImpl = [FHUtils classMapForMethodNamed:@"arrayPropertyToClassMap"
                                                         pairs:pairs
                                                   quoteValues:NO];
        [parts addObject:methodImpl];
      }

    }
  }

  NSArray *lastGrouping = nil;

  // List the methods in the groups to provide some structure to them.
  for (GTLDiscoveryRpcMethod *method in self.api.allMethods) {

    if (![lastGrouping isEqual:[method groupingParts]]) {
      lastGrouping = [method groupingParts];

      NSMutableString *sectionBlock = [NSMutableString string];

      if ([lastGrouping count] == 0) {
        [sectionBlock appendString:@"#pragma mark - Service level methods\n"];
      } else {
        [sectionBlock appendFormat:@"#pragma mark - \"%@\" methods\n",
         method.groupingName];
      }

      [sectionBlock appendFormat:@"// These create a %@ object.\n",
       self.objcQueryClassName];
      [subParts addObject:sectionBlock];
    }

    NSMutableString *methodStr = [NSMutableString string];

    if (mode == kGenerateInterface) {
      NSString *commentHeader = [NSString stringWithFormat:@"// Method: %@\n",
                                 method.name];
      [methodStr appendString:commentHeader];
      NSString *methodDescription = method.descriptionProperty;
      if (methodDescription) {
        NSString *descriptionComment =
          [FHUtils stringOfLinesFromString:methodDescription linePrefix:@"// "];
        [methodStr appendString:descriptionComment];
      }
      NSMutableString *requiredStr = [NSMutableString string];
      NSMutableString *optionalStr = [NSMutableString string];
      for (GTLDiscoveryJsonSchema *param in method.sortedParameters) {
        NSString *paramDesc = param.descriptionProperty;
        NSString *paramRangeDesc = param.rangeAndDefaultDescription;
        if ([paramRangeDesc length] > 0) {
          if ([paramDesc length] > 0) {
            paramDesc =
              [NSString stringWithFormat:@"%@ (%@)", paramDesc, paramRangeDesc];
          } else {
            paramDesc = paramRangeDesc;
          }
        }
        // If it isn't required, add a note to the description about the type
        // to be used for the property.
        if (![param.required boolValue] &&
            [param propertyForKey:kOverloadedParameterTypeKey]) {
          NSString *overloadNote =
            [NSString stringWithFormat:@"For this method, \"%@\" should be of type %@.",
             param.objcName, param.queryParamPseudoObjCType];
          if ([paramDesc length] > 0) {
            paramDesc = [NSString stringWithFormat:@"%@\nNote: %@",
                         paramDesc, overloadNote];
          } else {
            paramDesc = overloadNote;
          }
        }
        // If no description and optional, just list the type as a hint that
        // the param applies to this method.
        if (([paramDesc length] == 0) && ![param.required boolValue]) {
          paramDesc = param.queryParamPseudoObjCType;
        }
        if ([paramDesc length] > 0) {
          NSString *firstLinePrefix =
            [NSString stringWithFormat:@"//   %@: ", param.objcName];
          NSString *paramComment = [FHUtils stringOfLinesFromString:paramDesc
                                                    firstLinePrefix:firstLinePrefix
                                                   extraLinesPrefix:@"//     "
                                                        linesSuffix:@""
                                                     lastLineSuffix:@""
                                                      elementJoiner:@" "];
          if ([param.required boolValue]) {
            [requiredStr appendString:paramComment];
          } else {
            [optionalStr appendString:paramComment];
          }
        }
        NSArray *enumArray = param.enumProperty;
        if ([enumArray count] > 0) {
          if ([paramDesc length] == 0) {
            // There was no description, so add a simple comment to scope the
            // enums.
            NSString *paramComment =
              [NSString stringWithFormat:@"//   %@:\n", param.objcName];
            if ([param.required boolValue]) {
              [requiredStr appendString:paramComment];
            } else {
              [optionalStr appendString:paramComment];
            }
          }
          NSArray *enumDescriptions = param.enumDescriptions;
          for (NSUInteger x = 0; x < [enumArray count]; ++x) {
            NSString *enumValue = [enumArray objectAtIndex:x];
            NSString *enumDescription = nil;
            if (x < [enumDescriptions count]) {
              enumDescription = [enumDescriptions objectAtIndex:x];
            }
            if ([enumDescription length] == 0) {
              enumDescription = [NSString stringWithFormat:@"\"%@\"", enumValue];
            }
            NSString *firstLinePrefix =
              [NSString stringWithFormat:@"//      %@: ",
               [param constantNamed:enumValue]];
            NSString *enumLine = [FHUtils stringOfLinesFromString:enumDescription
                                                  firstLinePrefix:firstLinePrefix
                                                 extraLinesPrefix:@"//        "
                                                      linesSuffix:@""
                                                   lastLineSuffix:@""
                                                    elementJoiner:@" "];
            if ([param.required boolValue]) {
              [requiredStr appendString:enumLine];
            } else {
              [optionalStr appendString:enumLine];
            }
          }
        }
      }
      if ([requiredStr length]) {
        [methodStr appendString:@"//  Required:\n"];
        [methodStr appendString:requiredStr];
      }
      if ([optionalStr length]) {
        [methodStr appendString:@"//  Optional:\n"];
        [methodStr appendString:optionalStr];
      }
      if ([method.supportsMediaUpload boolValue]) {
        NSMutableString *mediaStr = [NSMutableString string];
        GTLDiscoveryRpcMethodMediaUpload *mediaUpload = method.mediaUpload;
        if (mediaUpload.maxSize) {
          [mediaStr appendFormat:@"//   Maximum size: %@\n", mediaUpload.maxSize];
        }
        if ([mediaUpload.accept count] > 0) {
          NSString *acceptStr =
            [FHUtils stringOfLinesFromStrings:mediaUpload.accept
                              firstLinePrefix:@"//   Accepted MIME type(s): "
                             extraLinesPrefix:@"//        "
                                  linesSuffix:@""
                               lastLineSuffix:@""
                                elementJoiner:@", "];
          [mediaStr appendString:acceptStr];
        }
        if ([mediaStr length] > 0) {
          [methodStr appendString:@"//  Upload Parameters:\n"];
          [methodStr appendString:mediaStr];
        }
      }
      NSArray *authScopes = method.scopes;
      if ([authScopes count] > 0) {
        [methodStr appendString:@"//  Authorization scope(s):\n"];
        NSMutableArray *scopeConstants =
          [NSMutableArray arrayWithCapacity:[authScopes count]];
        for (NSString *scope in authScopes) {
          NSString *scopeConstant = [self authorizationScopeToConstant:scope];
          [scopeConstants addObject:scopeConstant];
        }
        NSArray *sortedConstants =
          [scopeConstants sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
        for (NSString *scopeConstant in sortedConstants) {
          [methodStr appendFormat:@"//   %@\n", scopeConstant];
        }
      }
      GTLDiscoveryJsonSchema *returnsSchema = method.returns.resolvedSchema;
      if (returnsSchema) {
        [methodStr appendFormat:@"// Fetches a %@.\n", returnsSchema.objcClassName];
      }
    }

    NSString *initialLine = [NSString stringWithFormat:@"+ (instancetype)%@",
                             method.objcQueryForName];
    [methodStr appendString:initialLine];
    NSUInteger nameWidth = [initialLine length];
    BOOL needsWith = YES;

    BOOL doesQueryTakeObject = method.request != nil;
    if (doesQueryTakeObject) {
      GTLDiscoveryJsonSchema *requestSchema = method.request.resolvedSchema;
      [methodStr appendFormat:@"WithObject:(%@ *)object",
                              requestSchema.objcClassName];
      nameWidth += 10; // 'WithObject'
      needsWith = NO;
    }

    // Add any required parameters.
    BOOL hasRequiredParams = NO;
    for (GTLDiscoveryJsonSchema *param in method.sortedParameters) {
      if ([param.required boolValue]) {
        hasRequiredParams = YES;
        NSString *objcType = nil;
        BOOL asPtr = NO;
        [param getQueryParamObjCType:&objcType
                           asPointer:&asPtr
               objcPropertySemantics:NULL
                             comment:NULL
                      itemsClassName:NULL];
        if (needsWith) {
          NSString *capitalizeObjCName = param.capObjCName;
          NSString *name = param.objcName;
          [methodStr appendFormat:@"With%@:(%@%@)%@",
           capitalizeObjCName, objcType, (asPtr ? @" *" : @""),
           (mode == kGenerateInterface ? name : MappedParamName(name))];
          nameWidth += 4 + [capitalizeObjCName length]; // 'With%@'
        } else {
          // nameWidth is how much space should be used for the name to align
          // the colons.  If this parameter name is longer than that, it
          // doesn't get aligned.
          NSString *name = param.objcName;
          [methodStr appendFormat:@"\n%*s:(%@%@)%@",
           (int)nameWidth, [name UTF8String], objcType,
           (asPtr ? @" *" : @""),
           (mode == kGenerateInterface ? name : MappedParamName(name))];
        }
        needsWith = NO;
      }
    }

    BOOL supportsMediaUpload = [method.supportsMediaUpload boolValue];
    if (supportsMediaUpload) {
      if (needsWith) {
        [methodStr appendString:@"WithUploadParameters:(GTLUploadParameters *)uploadParametersOrNil"];
      } else {
        [methodStr appendFormat:@"\n%*s:(GTLUploadParameters *)uploadParametersOrNil",
         (int)nameWidth, "uploadParameters"];
      }
    }

    if (mode == kGenerateInterface) {
      // End the line.
      [methodStr appendString:@";\n"];
    } else {
      // End the line.
      [methodStr appendString:@" {\n"];

      // Fill in the function.

      // Make sure all required params are provided.
      if (doesQueryTakeObject || hasRequiredParams) {
        NSMutableArray *paramChecks = [NSMutableArray array];
        NSMutableArray *assertLines = [NSMutableArray array];

        if (doesQueryTakeObject) {
          [paramChecks addObject:@"object == nil"];
          [assertLines addObject:@"    GTL_DEBUG_ASSERT(object != nil, @\"%@ got a nil object\", NSStringFromSelector(_cmd));\n"];
        }

        // At this point we used to loop over the requiredParams and make sure
        // repeated ones didn't get empty arrays and that string parameters
        // weren't empty strings.  But the server will return errors for
        // missing/invalid things, so we dropped all client side checks and
        // just let the server enforce everything.

        if ([paramChecks count] > 1) {
          // If we'll have a list of checks, put parens on each so they are
          // slightly more readable.
          paramChecks = (NSMutableArray*)[FHUtils wrapStrings:paramChecks
                                                       prefix:@"("
                                                       suffix:@")"];
        }

        if ([paramChecks count] > 0) {
          // Now build the multiline "if (..) {"
          NSString *paramCheckStr = [FHUtils stringOfLinesFromStrings:paramChecks
                                                      firstLinePrefix:@"  if ("
                                                     extraLinesPrefix:@"      "
                                                          linesSuffix:@" ||"
                                                       lastLineSuffix:@") {"
                                                        elementJoiner:@" || "];
          [methodStr appendString:paramCheckStr];

          [methodStr appendString:[assertLines componentsJoinedByString:@""]];

          [methodStr appendString:@"    return nil;\n"];
          [methodStr appendString:@"  }\n"];
        }
      }

      [methodStr appendFormat:@"  NSString *methodName = @\"%@\";\n",
       method.name];
      [methodStr appendFormat:@"  %@ *query = [self queryWithMethodName:methodName];\n",
       self.objcQueryClassName];

      if (doesQueryTakeObject) {
        [methodStr appendString:@"  query.bodyObject = object;\n"];
      }

      // Handle required params.
      if (hasRequiredParams) {
        for (GTLDiscoveryJsonSchema *param in method.sortedParameters) {
          if ([param.required boolValue]) {
            NSString *name = param.objcName;
            NSString *nameAsValue = MappedParamName(name);
            if ([param propertyForKey:kOverloadedParameterTypeKey] != nil) {
              // The parameter is overloaded, so primitive types need to be
              // wrapped into objects.
              NSString *paramType = param.type;
              NSString *numberMethod = nil;
              if ([paramType isEqual:@"object"] ||
                  (param.repeated || [paramType isEqual:@"array"])) {
                // Nothing to do, already an object.
              } else if ([paramType isEqual:@"string"]) {
                // If it was a string, it might have a 64bit value in it (really
                // a number), so special case that.
                NSString *formatStr = param.format;
                if ([formatStr isEqual:@"int64"]) {
                  numberMethod = @"numberWithLongLong";
                } else if ([formatStr isEqual:@"uint64"]) {
                  numberMethod = @"numberWithUnsignedLongLong";
                } else {
                  // It was just a string, nothing to do, already an object
                }
              } else if ([paramType isEqual:@"number"]) {
                numberMethod = @"numberWithDouble";
              } else if ([paramType isEqual:@"integer"]) {
                // TODO: should we use 'format' to get the right method?  It
                // could matter from a range pov.
                numberMethod = @"numberWithInteger";
              } else if ([paramType isEqual:@"boolean"]) {
                numberMethod = @"numberWithBool";
              } else {
                [NSException raise:kFatalGeneration
                            format:@"Parameter '%@:%@' was overloaded, found a type of '%@', and don't how to map that to Objective-C",
                 param.method.name, param.name, paramType];
              }
              if (numberMethod != nil) {
                nameAsValue = [NSString stringWithFormat:@"[NSNumber %@:%@]",
                               numberMethod, nameAsValue];
              }
            }
            [methodStr appendFormat:@"  query.%@ = %@;\n", name, nameAsValue];
          }
        }
      }

      if (supportsMediaUpload) {
        [methodStr appendString:@"  query.uploadParameters = uploadParametersOrNil;\n"];
      }

      GTLDiscoveryJsonSchema *returnsSchema = method.returns.resolvedSchema;
      if (returnsSchema) {
        [methodStr appendFormat:@"  query.expectedObjectClass = [%@ class];\n",
         returnsSchema.objcClassName];
      }

      [methodStr appendString:@"  return query;\n}\n"];
    }

    // Add it to the array of subParts.
    [subParts addObject:methodStr];
  }
  NSString *allMethodsStr = [subParts componentsJoinedByString:@"\n"];
  [parts addObject:allMethodsStr];
  [subParts removeAllObjects];

  // Close it up.
  [parts addObject:@"@end\n"];

  return [parts componentsJoinedByString:@"\n"];
}

- (NSSet *)neededClassesForSchema:(GTLDiscoveryJsonSchema *)schema {
  NSMutableSet *result = [NSMutableSet set];

  // Any class can have properties that reference another class, this collects
  // the classes needed by the class generated from this schema.

  NSMutableArray *allProperties = [NSMutableArray array];

  NSArray *properties = DictionaryObjectsSortedByKeys(schema.properties.additionalProperties);
  if ([properties count] > 0) {
    [allProperties addObjectsFromArray:properties];
  }
  GTLDiscoveryJsonSchema *property = schema.additionalPropertiesProperty;
  if (property != nil) {
    [allProperties addObject:property];
  }
  property = [schema itemsSchemaResolving:YES depth:NULL];
  if (property != nil) {
    [allProperties addObject:property];
  }

  for (property in allProperties) {
    GTLDiscoveryJsonSchema *resolvedProperty = property.resolvedSchema;
    if ([resolvedProperty.type isEqual:@"object"]) {
      NSString *className = resolvedProperty.objcClassName;
      [result addObject:className];
    } else if ([resolvedProperty.type isEqual:@"array"]) {
      GTLDiscoveryJsonSchema *itemProperty =
          [resolvedProperty itemsSchemaResolving:YES depth:NULL];
      if ([itemProperty.type isEqual:@"object"]) {
        NSString *className = itemProperty.objcClassName;
        [result addObject:className];
      }
    }
  }

  return result;
}

- (NSArray *)recursivelyNeededClassesForSchemaSorted:(GTLDiscoveryJsonSchema *)schema {
  NSMutableSet *allNeededClasses = [NSMutableSet set];
  NSSet *neededClasses = [self neededClassesForSchema:schema];
  [allNeededClasses unionSet:neededClasses];
  for (GTLDiscoveryJsonSchema *subSchema in schema.childObjectSchemas) {
    neededClasses = [self neededClassesForSchema:subSchema];
    [allNeededClasses unionSet:neededClasses];
  }
  NSArray *sortedAllNeededClasses =
    [[allNeededClasses allObjects] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
  return sortedAllNeededClasses;
}

- (NSString *)generateObjectClassForSchema:(GTLDiscoveryJsonSchema *)schema
                                   forMode:(GeneratorMode)mode
                   includeClassDescription:(BOOL)includeClassDescription
                         extraClassComment:(NSString *)extraClassComment {
  NSMutableArray *parts = [NSMutableArray array];
  NSMutableArray *methodParts = [NSMutableArray array];

  NSString *schemaClassName = schema.objcClassName;
  BOOL isCollectionClass = schema.hasItemsArrayProperty;
  BOOL isTopLevelArrayResult = (([schema propertyForKey:kReturnsSchemaParameterKey] != nil)
                                && [schema.type isEqual:@"array"]);

  NSMutableString *classHeader = [NSMutableString string];
  [classHeader appendString:@"// ----------------------------------------------------------------------------\n"];
  [classHeader appendString:@"//\n"];
  [classHeader appendFormat:@"//   %@\n", schemaClassName];
  [classHeader appendString:@"//\n"];
  [classHeader appendString:@"\n"];
  if ([extraClassComment length] > 0) {
    NSString *wrapped =
      [FHUtils stringOfLinesFromString:extraClassComment linePrefix:@"// "];
    [classHeader appendString:wrapped];
    [classHeader appendString:@"\n"];
  }
  if ((mode == kGenerateInterface) && includeClassDescription) {
    // Top level schema get their class description above the class declaration
    // but schema for subobjects do not, instead their descriptions are inlined
    // on the property declaration where they are fetched since that better
    // leads developers through the object tree.
    NSString *schemaDescription = schema.descriptionProperty;
    if (schemaDescription) {
      NSString *wrappedDescription =
        [FHUtils stringOfLinesFromString:schemaDescription linePrefix:@"// "];
      [classHeader appendString:wrappedDescription];
      [classHeader appendString:@"\n"];
    }
  }
  if ((mode == kGenerateInterface)
      && (isCollectionClass || isTopLevelArrayResult)) {
    NSString *collectionNote =
      @"This class supports NSFastEnumeration over its \"items\" property. "
      @"It also supports -itemAtIndex: to retrieve individual objects from "
      @"\"items\".";
    NSString *wrappedNote =
      [FHUtils stringOfLinesFromString:collectionNote
                            linePrefix:@"// "];
    [classHeader appendString:wrappedNote];
    [classHeader appendString:@"\n"];
  }
  [parts addObject:classHeader];

  NSString *atBlock;
  if (mode == kGenerateInterface) {
    NSString *baseClass = kBaseObjectClass;
    if (isCollectionClass) {
      baseClass = kCollectionObjectClass;
    } else if (isTopLevelArrayResult) {
      baseClass = kResultArrayClass;
    }
    atBlock = [NSString stringWithFormat:@"@interface %@ : %@\n",
               schemaClassName, baseClass];
  } else {
    atBlock = [NSString stringWithFormat:@"@implementation %@\n",
               schemaClassName];
  }
  [parts addObject:atBlock];

  // For the rare cases where a method returns an array directly, generate a
  // special result object that just has -items to get the contents of the
  // array.  The rest of the logic after this block is basically a no-op as
  // there are no properties on this schema.
  if (isTopLevelArrayResult) {
    if (mode == kGenerateInterface) {
      NSString *objcType = nil, *objcPropertySemantics = nil, *comment = nil;
      BOOL asPtr = NO;
      [schema getObjectParamObjCType:&objcType
                           asPointer:&asPtr
               objcPropertySemantics:&objcPropertySemantics
                             comment:&comment];
      if (comment == nil) {
        comment = @"";
      } else {
        comment = [@"  // " stringByAppendingString:comment];
      }
      NSString *propertyLine = [NSString stringWithFormat:@"@property (nonatomic, %@, readonly) %@%@%@;%@\n",
                                objcPropertySemantics, objcType,
                                (asPtr ? @" *" : @" "),
                                @"items", comment];
      [parts addObject:propertyLine];
    } else {
      GTLDiscoveryJsonSchema *itemProperty =
        [schema itemsSchemaResolving:YES depth:NULL];
      NSString *objcType = nil;
      if (itemProperty == nil) {
        objcType = @"id";
      } else {
        [itemProperty getObjectParamObjCType:&objcType
                                   asPointer:NULL
                       objcPropertySemantics:NULL
                                     comment:NULL];
      }
      if ([objcType isEqual:@"id"]) {
        objcType = @"NSObject";
      }
      NSMutableString *itemsMethod = [NSMutableString string];
      [itemsMethod appendString:@"- (NSArray *)items {\n"];
      [itemsMethod appendFormat:@"  return [self itemsWithItemClass:[%@ class]];\n",
                                objcType];
      [itemsMethod appendString:@"}\n"];
      [methodParts addObject:itemsMethod];
    }
  }

  NSArray *properties = DictionaryObjectsSortedByKeys(schema.properties.additionalProperties);
  if ([properties count]) {
    // Write out the property support (GTLObject will fill them in at runtime).
    if (mode == kGenerateInterface) {
      // Put a blank line around any property that gets comments to make them
      // a little more readable.
      NSMutableArray *subParts = [NSMutableArray array];
      BOOL lastLineWasBlank = NO;
      for (GTLDiscoveryJsonSchema *property in properties) {
        BOOL hadComment = NO;
        NSString *propertyDescription = property.descriptionProperty;
        if (propertyDescription) {
          NSString *descriptionComment =
            [FHUtils stringOfLinesFromString:propertyDescription linePrefix:@"// "];
          if (!lastLineWasBlank) {
            [subParts addObject:@"\n"];
          }
          [subParts addObject:descriptionComment];
          hadComment = YES;
        }

        // If the ObjC name of a parameter was forced, include any comment
        // about that in the header with the @property declaration.
        NSString *forceObjCNameComment = property.forceNameComment;
        if (forceObjCNameComment != nil) {
          NSString *comment = [FHUtils stringOfLinesFromString:forceObjCNameComment
                                                    linePrefix:@"// "];
          if (!lastLineWasBlank && !hadComment) {
            [subParts addObject:@"\n"];
          }
          [subParts addObject:comment];
          hadComment = YES;
        }
        NSString *objcType = nil, *objcPropertySemantics = nil, *comment = nil;
        BOOL asPtr = NO;
        [property getObjectParamObjCType:&objcType
                               asPointer:&asPtr
                   objcPropertySemantics:&objcPropertySemantics
                                 comment:&comment];
        if (comment == nil) {
          comment = @"";
        } else {
          comment = [@"  // " stringByAppendingString:comment];
        }
        NSString *propertyObjCName = property.objcName;
        NSString *extraAttributes = @"";
        if ([useCustomerGetterPredicate_ evaluateWithObject:propertyObjCName]) {
          extraAttributes = [NSString stringWithFormat:@", getter=valueOf_%@", propertyObjCName];
        }
        NSString *clangDirective = @"";
        if ([notRetainedPredicate_ evaluateWithObject:propertyObjCName]) {
          clangDirective = @" NS_RETURNS_NOT_RETAINED";
        }
        NSString *propertyLine = [NSString stringWithFormat:@"@property (nonatomic, %@%@) %@%@%@%@;%@\n",
                                  objcPropertySemantics, extraAttributes, objcType,
                                  (asPtr ? @" *" : @" "),
                                  propertyObjCName, clangDirective, comment];
        [subParts addObject:propertyLine];
        if (hadComment) {
          [subParts addObject:@"\n"];
          lastLineWasBlank = YES;
        } else {
          lastLineWasBlank = NO;
        }
      }
      [parts addObject:[subParts componentsJoinedByString:@""]];
    } else {
      NSArray *propertiesObjCNames = [properties valueForKey:@"objcName"];
      NSString *asLines = [FHUtils stringOfLinesFromStrings:propertiesObjCNames
                                            firstLinePrefix:@"@dynamic "
                                           extraLinesPrefix:@"         "
                                                linesSuffix:@","
                                             lastLineSuffix:@";"
                                              elementJoiner:@", "];
      [parts addObject:asLines];
    }

    // Keep a mapping for ObjC names to "wire" names for parameters that
    // had invalid characters.
    if (mode == kGenerateImplementation) {
      NSMutableDictionary *pairs = [NSMutableDictionary dictionary];
      for (GTLDiscoveryJsonSchema *property in properties) {
        if (![property.name isEqual:property.objcName]) {
          [pairs setObject:property.name forKey:property.objcName];
        }
      }
      if ([pairs count] != 0) {
        NSString *methodImpl = [FHUtils classMapForMethodNamed:@"propertyToJSONKeyMap"
                                                         pairs:pairs
                                                   quoteValues:YES];
        [methodParts addObject:methodImpl];
      }
    }

    // For all array properties, provide a mapping to the default class
    // contained within the array.
    if (mode == kGenerateImplementation) {
      NSMutableDictionary *pairs = [NSMutableDictionary dictionary];
      for (GTLDiscoveryJsonSchema *property in properties) {
        GTLDiscoveryJsonSchema *resolvedProperty = property.resolvedSchema;
        if ([resolvedProperty.type isEqual:@"array"]) {
          GTLDiscoveryJsonSchema *itemProperty =
              [resolvedProperty itemsSchemaResolving:YES depth:NULL];
          NSString *objcType = nil;
          if (itemProperty == nil) {
            // A warning is already printed when the header was generated.
            objcType = @"id";
          } else {
            [itemProperty getObjectParamObjCType:&objcType
                                       asPointer:NULL
                           objcPropertySemantics:NULL
                                         comment:NULL];
          }
          if ([objcType isEqual:@"id"]) {
            objcType = @"NSObject";
          }
          NSString *getClassStr =
            [NSString stringWithFormat:@"[%@ class]", objcType];
          [pairs setObject:getClassStr forKey:property.name];
        }
      }
      if ([pairs count] != 0) {
        NSString *methodImpl = [FHUtils classMapForMethodNamed:@"arrayPropertyToClassMap"
                                                         pairs:pairs
                                                   quoteValues:NO];
        [methodParts addObject:methodImpl];
      }
    }
  }

  // Handle the 'kind' attribute for auto creating the right objects when
  // parsing.
  if (mode == kGenerateImplementation) {
    NSString *kindToRegister = schema.kindToRegister;
    if (kindToRegister != nil) {
      // Have we suppressed the registered kind?
      if ([schema propertyForKey:kSkipRegisteringKindKey] != nil) {
        NSMutableString *loadMethod = [NSMutableString string];
        [loadMethod appendFormat:@"// +load method not generated as another class also claims kind '%@'.\n",
         kindToRegister];
        [methodParts addObject:loadMethod];
      } else {
        NSMutableString *loadMethod = [NSMutableString string];
        [loadMethod appendString:@"+ (void)load {\n"];
        [loadMethod appendFormat:@"  [self registerObjectClassForKind:@\"%@\"];\n",
         kindToRegister];
        [loadMethod appendString:@"}\n"];
        [methodParts addObject:loadMethod];
      }
    }
  }

  // Handle additional properties.
  GTLDiscoveryJsonSchema *additionalProperties = schema.additionalPropertiesProperty.resolvedSchema;
  if (additionalProperties != nil) {
    BOOL isArray = NO;
    GTLDiscoveryJsonSchema *worker = additionalProperties;
    if ([additionalProperties.type isEqual:@"array"]) {
      // Pull the type from the items in the array instead.
      worker = [additionalProperties itemsSchemaResolving:YES depth:NULL];
      isArray = YES;
    }
    if (mode == kGenerateInterface) {
      NSString *objcType = nil, *comment = nil;
      [worker getObjectParamObjCType:&objcType
                           asPointer:NULL
               objcPropertySemantics:NULL
                             comment:&comment];
      if ([objcType isEqual:@"id"]) {
        objcType = @"of any JSON type";
      }
      if (comment == nil) {
        comment = @"";
      } else {
        comment = [NSString stringWithFormat:@" (%@)", comment];
      }
      NSString *commentStart =
        [NSString stringWithFormat:
          @"This object is documented as having more properties that are %@%@%@.",
          (isArray ? @"NSArrays of " : @""), objcType, comment];
      NSString *kCommentRemainder =
        @" Use -additionalJSONKeys and -additionalPropertyForName: to get the "
        @"list of properties and then fetch them; or -additionalProperties to "
        @"fetch them all at once.";
      NSString *commentString =
        [commentStart stringByAppendingString:kCommentRemainder];
      NSString *formattedComment = [FHUtils stringOfLinesFromString:commentString
                                                         linePrefix:@"// "];
      [parts addObject:formattedComment];
    } else {
      // Provide the class to hit object creation during parsing.
      NSString *objcType = nil;
      [worker getObjectParamObjCType:&objcType
                           asPointer:NULL
               objcPropertySemantics:NULL
                             comment:NULL];

      if ([objcType isEqual:@"id"]) {
        objcType = @"NSObject";
      }

      NSMutableString *method = [NSMutableString string];
      [method appendString:@"+ (Class)classForAdditionalProperties {\n"];
      [method appendFormat:@"  return [%@ class];\n", objcType];
      // [method appendFormat:@"  return [%@ class];\n", worker.objcClassName];
      [method appendString:@"}\n"];
      [methodParts addObject:method];
    }
  }

  if ([methodParts count]) {
    NSString *methodsBlock =
      [NSString stringWithFormat:@"\n%@\n",
       [methodParts componentsJoinedByString:@"\n"]];
    [parts addObject:methodsBlock];
  }

  // Close it up.
  [parts addObject:@"@end\n"];

  return [parts componentsJoinedByString:@""];
}

- (NSArray *)constantsBlocksForMode:(GeneratorMode)mode {
  NSMutableArray *result = [NSMutableArray array];

  NSString *beforeValue = @" // \"";
  NSString *afterValue = @"\"";
  NSString *externStr = [kExternPrefix stringByAppendingString:@" "];
  if (mode == kGenerateImplementation) {
    beforeValue = @"= @\"";
    afterValue = @"\";";
    externStr = @"";
  }

  GTLDiscoveryRpcDescriptionAuthOauth2Scopes *oauth2scopes = self.api.auth.oauth2.scopes;
  if (oauth2scopes != nil) {
    NSMutableDictionary *authScopesMap = [NSMutableDictionary dictionary];
    for (NSString *scope in oauth2scopes.additionalJSONKeys) {
      NSString *key = [self authorizationScopeToConstant:scope];
      [authScopesMap setObject:scope forKey:key];
    }

    NSMutableArray *subParts = [NSMutableArray array];
    NSString *commentLine = @"// Authorization scope\n";
    [subParts addObject:commentLine];

    NSArray *sortedNames =
      [[authScopesMap allKeys] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
    NSNumber *maxLenNum = [sortedNames valueForKeyPath:@"@max.length"];
    NSUInteger maxLen = [maxLenNum unsignedIntegerValue];
    if (mode == kGenerateInterface) {
      ++maxLen; // include the semicolon that goes on the name
    }
    NSUInteger maxCap = 45 - [externStr length];
    if (maxLen > maxCap) maxLen = maxCap;

    for (NSString *name in sortedNames) {
      NSString *scope = [authScopesMap objectForKey:name];
      if (mode == kGenerateInterface) {
        name = [name stringByAppendingString:@";"];
      }
      NSString *aScope =
        [NSString stringWithFormat:@"%@NSString * const %-*s %@%@%@\n",
         externStr,
         (int)maxLen, [name UTF8String],
         beforeValue, scope, afterValue];

      if (mode == kGenerateInterface) {
        GTLDiscoveryRpcDescriptionAuthOauth2ScopesScope *scopeInfo =
          [oauth2scopes additionalPropertyForName:scope];
        if ([scopeInfo.descriptionProperty length] > 0) {
          NSString *wrappedDescription =
            [FHUtils stringOfLinesFromString:scopeInfo.descriptionProperty
                                  linePrefix:@"// "];
          aScope = [wrappedDescription stringByAppendingString:aScope];
        }
      }
      [subParts addObject:aScope];
    }
    [result addObject:[subParts componentsJoinedByString:@""]];
  }

  NSDictionary *enumsMap = self.api.enumsMap;
  if ([enumsMap count] > 0) {
    NSArray *constantsGroups =
      [[enumsMap allKeys] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];

    NSMutableArray *subParts = [NSMutableArray array];
    for (NSString *constantsGroup in constantsGroups) {
      NSDictionary *enumGroup = [enumsMap objectForKey:constantsGroup];

      NSString *commentLine = [NSString stringWithFormat:@"// %@\n", constantsGroup];
      [subParts addObject:commentLine];

      NSArray *names =
        [[enumGroup allKeys] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
      NSNumber *maxLenNum = [names valueForKeyPath:@"@max.length"];
      NSUInteger maxLen = [maxLenNum unsignedIntegerValue];
      if (mode == kGenerateInterface) {
        ++maxLen; // include the semicolon that goes on the name
      }
      NSUInteger maxCap = 45 - [externStr length];
      if (maxLen > maxCap) maxLen = maxCap;

      for (NSString *name in names) {
        NSString *value = [enumGroup objectForKey:name];
        if (mode == kGenerateInterface) {
          name = [name stringByAppendingString:@";"];
        }
        NSString *line =
          [NSString stringWithFormat:@"%@NSString * const %-*s %@%@%@\n",
           externStr,
           (int)maxLen, [name UTF8String],
           beforeValue, value, afterValue];
        [subParts addObject:line];
      }
      [result addObject:[subParts componentsJoinedByString:@""]];
      [subParts removeAllObjects];
    }
  }

  return result;
}


// Generates a constant name out of the scope by using the leaf of the scope
// string and the service name.
- (NSString *)authorizationScopeToConstant:(NSString *)scope {
  NSString *result = nil;

  NSString *prefix = [NSString stringWithFormat:@"k%@AuthScope%@",
                      kProjectPrefix, self.formattedApiName];

  NSString *scopeName;
  NSRange lastSlash = [scope rangeOfString:@"/" options:NSBackwardsSearch];
  if (lastSlash.location != NSNotFound) {
    scopeName = [scope substringFromIndex:(lastSlash.location + 1)];
  } else {
    scopeName = scope;
  }
  NSString *lowerScopeName = [scopeName lowercaseString];
  NSString *lowerApiName = [self.api.name lowercaseString];
  if (([scopeName length] == 0) || [lowerScopeName isEqual:lowerApiName]) {
    // Leaf was just service name, nothing to add to the scope constant.
    result = prefix;
  } else {
    lowerApiName = [lowerApiName stringByAppendingString:@"."];
    if ([lowerScopeName hasPrefix:lowerApiName]) {
      // Starts with ServiceName., stop that and use the rest.
      scopeName = [scopeName substringFromIndex:[lowerApiName length]];
    }
    NSString *formattedScopeName =
      [FHUtils objcName:scopeName shouldCapitalize:YES];
    result = [prefix stringByAppendingString:formattedScopeName];
  }

  return result;
}

- (NSString *)frameworkedImport:(NSString *)headerName {
  NSMutableString *result = [NSMutableString string];
  [result appendFormat:@"#if %@\n", kFrameworkIncludeGate];
  [result appendFormat:@"  #import \"%@/%@.h\"\n", kProjectPrefix, headerName];
  [result appendString:@"#else\n"];
  [result appendFormat:@"  #import \"%@.h\"\n", headerName];
  [result appendString:@"#endif\n"];
  return result;
}

- (void)addWarning:(NSString *)warningString {
  NSMutableArray *warnings = self.warnings;
  if (!warnings) {
    warnings = [NSMutableArray array];
    self.warnings = warnings;
  }
  if (![warnings containsObject:warningString]) {
    [warnings addObject:warningString];
  }
}

- (void)addInfo:(NSString *)infoString {
  NSMutableArray *infos = self.infos;
  if (!infos) {
    infos = [NSMutableArray array];
    self.infos = infos;
  }
  if (![infos containsObject:infoString]) {
    [infos addObject:infoString];
  }
}

@end

@implementation GTLObject (FHGeneratorAdditions)

- (NSString *)errorReportingName {
  NSString *result = [self propertyForKey:kNameKey];
  return result;
}

- (FHGenerator *)generator {
  FHGenerator *result =
      [[self propertyForKey:kWrappedGeneratorKey] nonretainedObjectValue];
  NSAssert(result != nil,
           @"attempt to use generator when it wasn't set for object: %@",
           self);
  return result;
}

@end

@implementation GTLDiscoveryRpcDescription (FHGeneratorAdditions)

// Methods sorted by their ObjC query name.
- (NSArray *)allMethods {
  NSArray *result = [self propertyForKey:kAllMethodsKey];
  if (result == nil) {
    NSMutableDictionary *allMethodsDict = [NSMutableDictionary dictionary];
    NSArray *allUnorderedMethods = [self.methods.additionalProperties allValues];
    for (GTLDiscoveryRpcMethod *method in allUnorderedMethods) {
      [allMethodsDict setObject:method forKey:method.objcQueryForName];
    }
    // Return them sorted for stable iteration.
    result = DictionaryObjectsSortedByKeys(allMethodsDict);
    [self setProperty:result forKey:kAllMethodsKey];
  }
  return result;
}

// Builds the union of all parameters from all methods of this
// service. Keeps a unique set as well as the complete set.
- (BOOL)buildParameterLists:(void (^)(FHGeneratorHandlerMessageType msgType,
                                      NSString *message))messageHandler {
  BOOL result = YES;

  NSMutableArray *allParams = [NSMutableArray array];
  NSMutableDictionary *uniqueParamsDict = [NSMutableDictionary dictionary];
  NSMutableDictionary *uniqueRepeatedParamsDict = [NSMutableDictionary dictionary];
  NSMutableArray *commonParams = [NSMutableArray array];

  // Common parameters are listed at the service level; they apply to all
  // methods.  However, there are some that come back from discovery that
  // don't make sense at the method level for the GTL library, so we filter
  // those out.
  NSArray *commonParamsToSkip = @[
     @"alt", // GTL only supports JSON
     @"key", // GTL handles the API key on the service, per method is need in
             //   the ObjectiveC use case.
     @"oauth_token", // GTL handles this on the service.
     @"prettyPrint", // No needed, GTL Logging pretty prints for the developer.
     @"userIp", // Not needed for client software, only needed for servers
                // making request on behalf of lots of users.
     @"quotaUser", // Another form of userIp.
  ];

  NSArray *allCommonParams = DictionaryObjectsSortedByKeys(self.parameters.additionalProperties);
  for (GTLDiscoveryJsonSchema *param in allCommonParams) {
    if ([commonParamsToSkip containsObject:param.name]) {
      continue;
    }
    [commonParams addObject:param];
    [allParams addObject:param];
    [uniqueParamsDict setObject:param forKey:param.name];
    if (param.repeated || [param.type isEqual:@"array"]) {
      [uniqueRepeatedParamsDict setObject:param forKey:param.name];
    }
  }

  for (GTLDiscoveryRpcMethod *method in self.allMethods) {
    NSArray *methodParameters = DictionaryObjectsSortedByKeys(method.parameters.additionalProperties);
    for (GTLDiscoveryJsonSchema *param in methodParameters) {
      // The ObjC library lists the object that goes with the methods
      // independently, so keep it out of the parameters lists.
      if ([param.name isEqual:kResourceParameterName]) {
        continue;
      }

      [allParams addObject:param];
      GTLDiscoveryJsonSchema *previousParam = [uniqueParamsDict objectForKey:param.name];
      if (previousParam) {
        // NOTE: Since parameters on methods are merged up to the query class,
        // they all need to have the same type.

        // Each param keeps a reference to all the other params with the same
        // name so they can easily all be found. (NSPointerArray to avoid
        // retain cycles).
        NSPointerArray *sameNamed =
          [previousParam propertyForKey:kSameNamedParametersKey];
        if (!sameNamed) {
          sameNamed = [NSPointerArray weakObjectsPointerArray];
          [previousParam setProperty:sameNamed forKey:kSameNamedParametersKey];
          [sameNamed addPointer:previousParam];
        }
        [sameNamed addPointer:param];
        [param setProperty:sameNamed forKey:kSameNamedParametersKey];

        NSString *objcType1 = nil, *objcType2 = nil;
        NSString *itemsClassName1 = nil, *itemsClassName2 = nil;
        [param.resolvedSchema getQueryParamObjCType:&objcType1
                                          asPointer:NULL
                              objcPropertySemantics:NULL
                                            comment:NULL
                                     itemsClassName:&itemsClassName1];
        [previousParam.resolvedSchema getQueryParamObjCType:&objcType2
                                                  asPointer:NULL
                                      objcPropertySemantics:NULL
                                                    comment:NULL
                                             itemsClassName:&itemsClassName2];
        // TODO(TVL): the second warning here about itemClass (repeated/arrays)
        // can also fire with a 'null' type if one instance is a basic type
        // and the other is array of something.  Contacts was hitting this.
        if (![objcType1 isEqual:objcType2]) {
          // Mark the parameters to be overloaded to handle multiple types.
          for (GTLDiscoveryJsonSchema *sameNamedParam in sameNamed) {
            [sameNamedParam setProperty:@YES forKey:kOverloadedParameterTypeKey];
          }
        } else {
          // If the previous was overloaded, we have to mark this new one as
          // overloaded also.
          if ([previousParam propertyForKey:kOverloadedParameterTypeKey]) {
            [param setProperty:@YES forKey:kOverloadedParameterTypeKey];
          }
        }

        if (param.repeated || [param.type isEqual:@"array"]) {
          GTLDiscoveryJsonSchema *previousRepeatedParam =
            [uniqueRepeatedParamsDict objectForKey:param.name];
          if (previousRepeatedParam) {
            // Like sameNamed above, track the same named repeateds.
            NSPointerArray *sameRepeatedNamed =
              [previousRepeatedParam propertyForKey:kSameNamedRepeatedParametersKey];
            if (!sameRepeatedNamed) {
              sameRepeatedNamed = [NSPointerArray weakObjectsPointerArray];
              [previousRepeatedParam setProperty:sameRepeatedNamed
                                          forKey:kSameNamedRepeatedParametersKey];
              [sameRepeatedNamed addPointer:previousRepeatedParam];
            }
            [sameRepeatedNamed addPointer:param];
            [param setProperty:sameRepeatedNamed forKey:kSameNamedRepeatedParametersKey];

            [previousRepeatedParam.resolvedSchema getQueryParamObjCType:&objcType2
                                                      asPointer:NULL
                                          objcPropertySemantics:NULL
                                                        comment:NULL
                                                 itemsClassName:&itemsClassName2];
            if (![itemsClassName1 isEqual:itemsClassName2]) {
              // Mark the parameters to be overloaded to handle multiple types.
              for (GTLDiscoveryJsonSchema *sameNamedRepeatedParam in sameRepeatedNamed) {
                [sameNamedRepeatedParam setProperty:@YES forKey:kOverloadedParameterArrayItemKey];
              }
            } else {
              // If the previous was overloaded, we have to mark this new one as
              // overloaded also.
              if ([previousRepeatedParam propertyForKey:kOverloadedParameterArrayItemKey]) {
                [param setProperty:@YES forKey:kOverloadedParameterArrayItemKey];
              }
            }
          } else {
            [uniqueRepeatedParamsDict setObject:param forKey:param.name];
          }
        }

        // NOTE: Default values can be different for methods, so those aren't
        // checked.

        // NOTE: Don't do any checks on enums or patterns. It is valid for
        // there to be different enum values for different methods even
        // though the parameter is named the same.
      } else {
        [uniqueParamsDict setObject:param forKey:param.name];
        if (param.repeated || [param.type isEqual:@"array"]) {
          [uniqueRepeatedParamsDict setObject:param forKey:param.name];
        }
      }
    }  // for(param in methodParameters)

    // Make sure everyting listed in parameterOrder is actually listed as a
    // parameter.
    NSArray *paramOrder = method.parameterOrder;
    if ([paramOrder count]) {
      NSMutableArray *unknownParams =
        [NSMutableArray arrayWithArray:paramOrder];
      NSArray *allParamNames = [method.parameters.additionalProperties allKeys];
      [unknownParams removeObjectsInArray:allParamNames];
      if ([unknownParams count]) {
        NSString *errStr =
          [NSString stringWithFormat:@"Method '%@' has a parameterOrder which includes unknown parameter(s): %@",
           method.name, [unknownParams componentsJoinedByString:@", "]];
        messageHandler(kFHGeneratorHandlerMessageError, errStr);
        result = NO;
      }
    }
  }  // for (method in self.allMethods)

  // Save them sorted for stable iteration.
  NSArray *sortedNames = [[uniqueParamsDict allKeys] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
  NSArray *uniqueParams = [uniqueParamsDict objectsForKeys:sortedNames
                                            notFoundMarker:[NSNull null]];

  for (GTLDiscoveryJsonSchema *param in uniqueParams) {
    if ([param propertyForKey:kOverloadedParameterTypeKey] != nil) {
      NSPointerArray *sameNamed = [param propertyForKey:kSameNamedParametersKey];
      NSMutableDictionary *typeToNames = [NSMutableDictionary dictionary];
      for (GTLDiscoveryJsonSchema *aParam in sameNamed) {
        NSString *paramType = aParam.queryParamPseudoObjCType;
        NSMutableArray *names = typeToNames[paramType];
        if (names == nil) {
          names = [NSMutableArray array];
          typeToNames[paramType] = names;
        }
        [names addObject:aParam.method.name];
      }
      NSMutableString *msgStr =
        [NSMutableString stringWithFormat:@"Will make parameter '%@' support anything, it has multiple types between methods:",
         param.name];
      for (NSString *paramType in typeToNames) {
        NSArray *names = typeToNames[paramType];
        [msgStr appendFormat:@"\n        %@:", paramType];
        for (NSString *name in names) {
          [msgStr appendFormat:@"\n            %@", name];
        }
      }
      messageHandler(kFHGeneratorHandlerMessageInfo, msgStr);
    }
  }

  // Save them sorted for stable iteration.
  sortedNames =
    [[uniqueRepeatedParamsDict allKeys] sortedArrayUsingSelector:@selector(caseInsensitiveCompare:)];
  NSArray *uniqueRepeatedParams = [uniqueRepeatedParamsDict objectsForKeys:sortedNames
                                                            notFoundMarker:[NSNull null]];

  for (GTLDiscoveryJsonSchema *param in uniqueRepeatedParams) {
    // If it is generally overload, nothing special is reported as it was covered above.
    if ([param propertyForKey:kOverloadedParameterTypeKey] != nil) {
      continue;
    }

    if ([param propertyForKey:kOverloadedParameterArrayItemKey] != nil) {
      NSPointerArray *sameNamed = [param propertyForKey:kSameNamedRepeatedParametersKey];
      NSMutableDictionary *typeToNames = [NSMutableDictionary dictionary];
      for (GTLDiscoveryJsonSchema *aParam in sameNamed) {
        NSString *paramType = aParam.queryParamPseudoObjCType;
        NSMutableArray *names = typeToNames[paramType];
        if (names == nil) {
          names = [NSMutableArray array];
          typeToNames[paramType] = names;
        }
        [names addObject:aParam.method.name];
      }
      NSMutableString *msgStr =
        [NSMutableString stringWithFormat:@"Will make repeated parameter '%@' support NSArrays of anything, it has multiple item types between methods:",
         param.name];
      for (NSString *paramType in typeToNames) {
        NSArray *names = typeToNames[paramType];
        [msgStr appendFormat:@"\n        %@:", paramType];
        for (NSString *name in names) {
          [msgStr appendFormat:@"\n            %@", name];
        }
      }
      messageHandler(kFHGeneratorHandlerMessageInfo, msgStr);
    }
  }

  // Check for collisions on objc names.
  NSMutableDictionary *objcParamNamesDict = [NSMutableDictionary dictionary];
  for (GTLDiscoveryJsonSchema *param in uniqueParams) {
    NSString *objcName = param.objcName;
    NSMutableArray *paramsWithName = objcParamNamesDict[objcName];
    if (paramsWithName == nil) {
      paramsWithName = [NSMutableArray array];
      objcParamNamesDict[objcName] = paramsWithName;
    }
    [paramsWithName addObject:param];
  }
  for (NSString *objcName in objcParamNamesDict) {
    NSArray *paramsWithName = objcParamNamesDict[objcName];
    if (paramsWithName.count == 1) {
      continue;  // No collisions.
    }
    // Collect all the params that collide on this objcName to provide a complete message.
    NSMutableDictionary *paramNamesToLocation = [NSMutableDictionary dictionary];
    for (GTLDiscoveryJsonSchema *param in paramsWithName) {
      NSArray *sameNamed;
      if ([param propertyForKey:kSameNamedParametersKey] != nil) {
        sameNamed = [[param propertyForKey:kSameNamedParametersKey] allObjects];
      } else {
        sameNamed = @[ param ];
      }
      for (GTLDiscoveryJsonSchema *param2 in sameNamed) {
        NSString *reportName = (param2.method == nil ? @"As common parameter" : param2.method.name);
        NSMutableArray *names = paramNamesToLocation[param2.name];
        if (names == nil) {
          names = [NSMutableArray array];
          paramNamesToLocation[param2.name] = names;
        }
        [names addObject:reportName];
      }
    }
    NSMutableString *errStr =
        [NSMutableString stringWithFormat:@"Collision for Query object Objective C property name '%@':",
         objcName];
    for (NSString *paramName in paramNamesToLocation) {
      NSArray *names = paramNamesToLocation[paramName];
      [errStr appendFormat:@"\n        parameter '%@' on:", paramName];
      for (NSString *name in names) {
        [errStr appendFormat:@"\n            %@", name];
      }
    }
    messageHandler(kFHGeneratorHandlerMessageError, errStr);
    result = NO;
  }

  [self setProperty:uniqueParams forKey:kUniqueParamsKey];
  [self setProperty:uniqueRepeatedParams forKey:kUniqueRepeatedParamsKey];
  [self setProperty:allParams forKey:kAllParamsKey];

  return result;
}

- (NSArray *)uniqueParameters {
  // buildParameterLists: gets called to compute this.
  NSArray *result = [self propertyForKey:kUniqueParamsKey];
  return result;
}

- (NSArray *)uniqueRepeatedParameters {
  // buildParameterLists: gets called to compute this.
  NSArray *result = [self propertyForKey:kUniqueRepeatedParamsKey];
  return result;
}

- (NSArray *)allParameters {
  // buildParameterLists: gets called to compute this.
  NSArray *result = [self propertyForKey:kAllParamsKey];
  return result;
}

// Returns a dictionary keyed by the "grouping" where the objects are the
// values keyed by the constant name. i.e. --
//   { 'scope': {
//       'kGTLServiceScopeSpam': '@spam',
//       'kGTLServiceScopeBlah': '@blah'
//      }
//   }
- (NSDictionary *)enumsMap {
  NSDictionary *result = [self propertyForKey:kEnumsMapKey];
  if (result == nil) {
    NSMutableDictionary *worker = [NSMutableDictionary dictionary];

    // Note: schemas also have an enumDescriptions property, we don't do
    // anything with it when reporting the enums in the constants files. The
    // only place that seems to set them is the for the query parameters,
    // and we report the enums & comments on the query methods instead.

    // Values from query parameters
    for (GTLDiscoveryRpcMethod *method in self.allMethods) {
      NSArray *methodParameters = DictionaryObjectsSortedByKeys(method.parameters.additionalProperties);
      for (GTLDiscoveryJsonSchema *param in methodParameters) {
        NSArray *enumProperty = param.enumProperty;
        if ([enumProperty count] > 0) {
          // Only expecting strings at this point.
          if (![param.type isEqual:@"string"]) {
            [NSException raise:kFatalGeneration
                        format:@"Collecting enum values, '%@' on method '%@' is type %@ (instead of string)",
             param.name, param.method.name, param.type];
          }
          // Merge in these values
          NSString *groupName = [NSString stringWithFormat:@"%@ - %@",
                                 self.generator.objcQueryClassName,
                                 param.capObjCName];
          NSMutableDictionary *groupMap = [worker objectForKey:groupName];
          if (groupMap == nil) {
            groupMap = [NSMutableDictionary dictionary];
            [worker setObject:groupMap forKey:groupName];
          }
          for (NSString *enumValue in enumProperty) {
            NSString *constName = [param constantNamed:enumValue];
            [groupMap setObject:enumValue forKey:constName];
          }
        }
      }
    }

    // Check all the schemes for enums.
    for (GTLDiscoveryJsonSchema *schema in self.allSchemas) {
      NSArray *enumProperty = schema.enumProperty;
      if ([enumProperty count] > 0) {
        if (![schema.type isEqual:@"string"]) {
          [NSException raise:kFatalGeneration
                      format:@"Collecting enum values, '%@'is type %@ (instead of string)",
           schema.fullSchemaName, schema.type];
        }
        // We want to group it by the property/field the thing is hung on. The
        // catch is arrays (of arrays)*, we don't want to use the "item" schema
        // so need to walk up and find the right parent schema.
        //   schema - has the enum
        //   parentScheme - will be where to scope it
        //   propertySchema - will be what to group it as
        GTLDiscoveryJsonSchema *parentSchema = schema.parentSchema;
        GTLDiscoveryJsonSchema *propertySchema = schema;
        while ([[propertySchema propertyForKey:kIsItemsSchemaKey] boolValue]) {
          propertySchema = parentSchema;
          parentSchema = parentSchema.parentSchema;
        }
        NSString *groupBase = parentSchema.objcClassName;
        NSString *groupLeaf = propertySchema.capObjCName;
        if (parentSchema == nil || propertySchema == nil) {
          // If we failed to find parent schemas to make the grouping, use
          // [service] [schema].  This happens when something has a root schema
          // that is just the string type, and the reference it from other
          // places.
          groupBase = [NSString stringWithFormat:@"%@%@",
                       kProjectPrefix,
                       self.generator.formattedApiName];
          groupLeaf = schema.capObjCName;
        }
        NSString *groupName = [NSString stringWithFormat:@"%@ - %@",
                               groupBase, groupLeaf];
        NSString *groupPrefix = [NSString stringWithFormat:@"%@_%@_",
                                 groupBase, groupLeaf];
        if ([worker objectForKey:groupName]) {
          [NSException raise:kFatalGeneration
                      format:@"Collecting enum values, %@ needed group name '%@', but it is already in use.",
           schema.fullSchemaName, groupName];
        }
        NSMutableDictionary *groupMap = [NSMutableDictionary dictionary];
        [worker setObject:groupMap forKey:groupName];
        for (NSString *enumValue in enumProperty) {
          NSString *constName = ConstantName(groupPrefix, enumValue);
          [groupMap setObject:enumValue forKey:constName];
        }
      }
    }

    result = worker;
    [self setProperty:result forKey:kEnumsMapKey];
  }
  return result;
}

- (NSArray *)allSchemas {
  NSArray *result = [self propertyForKey:kAllSchemasKey];
  if (result == nil) {

    // Make sure the id's match the keys they are under for the top level.
    // Have to skip over a top level that is purely a references for mapping
    // method request/returns schema to real schema.

    for (NSString *name in self.schemas.additionalProperties) {
      GTLDiscoveryJsonSchema *schema =
        [self.schemas.additionalProperties objectForKey:name];
      if ([schema.xRef length] == 0) {
        if (![name isEqual:schema.identifier]) {
          [NSException raise:kFatalGeneration
                      format:@"Looking at allSchema, mismatch between id and name: '%@' vs '%@'",
                            name, schema.identifier];
        }
      }
    }

    // We don't have to crawl the tree to find all of the schema, but they can be
    // nested.

    NSMutableArray *worker = [NSMutableArray array];
    NSArray *schemas = DictionaryObjectsSortedByKeys(self.schemas.additionalProperties);
    if ([schemas count] > 0) {
      [worker addObjectsFromArray:schemas];
    }
    NSUInteger idx = 0;
    while (idx < [worker count]) {
      GTLDiscoveryJsonSchema *schema = [worker objectAtIndex:idx];
      NSArray *subSchemas = DictionaryObjectsSortedByKeys(schema.properties.additionalProperties);
      if ([subSchemas count] > 0) {
        [worker addObjectsFromArray:subSchemas];
      }
      GTLDiscoveryJsonSchema *itemsSchema = schema.items;
      if (itemsSchema) {
        [worker addObject:itemsSchema];
      }
      GTLDiscoveryJsonSchema *additionalPropsSchema = schema.additionalPropertiesProperty;
      if (additionalPropsSchema) {
        [worker addObject:additionalPropsSchema];
      }
      ++idx;
    }

    result = [NSArray arrayWithArray:worker];
    [self setProperty:result forKey:kAllSchemasKey];
  }
  return result;
}

- (NSArray *)topLevelObjectSchemas {
  NSArray *result = [self propertyForKey:kTopLevelObjectSchemasKey];
  if (result == nil) {

    // NOTE: We want this list in a stable order, but we can't simply sort the
    // keys and then iterate because when we turn them into class names we
    // sometimes have to strip prefixes (service names, etc.).  Instead we
    // sort by the objc class name after collecting them.

    NSMutableDictionary *worker = [NSMutableDictionary dictionary];
    for (GTLDiscoveryJsonSchema *schema in [self.schemas.additionalProperties allValues]) {
      NSString *schemaType = schema.type;
      if ([schemaType isEqual:@"object"]) {
        [worker setObject:schema forKey:schema.objcClassName];
      } else if ([schemaType isEqual:@"array"]) {
        // If an array is a return result, need to generate a stub object to
        // use.
        if ([schema propertyForKey:kReturnsSchemaParameterKey] != nil) {
          [worker setObject:schema forKey:schema.objcClassName];
        }
        // Don't resolve items, should end on an object or a ref (no type).
        GTLDiscoveryJsonSchema *itemsSchema =
            [schema itemsSchemaResolving:NO depth:NULL];
        if ([itemsSchema.type isEqual:@"object"]) {
          [worker setObject:itemsSchema forKey:itemsSchema.objcClassName];
        }
      }
    }

    result = DictionaryObjectsSortedByKeys(worker);
    [self setProperty:result forKey:kTopLevelObjectSchemasKey];
  }
  return result;
}

// These are schema inlined in the method parameters themselves (ie- not $refs)
- (NSArray *)allMethodObjectParameters {
  NSArray *result = [self propertyForKey:kAllMethodObjectParametersKey];
  if (result == nil) {
    NSMutableArray *worker = [NSMutableArray array];

    for (GTLDiscoveryRpcMethod *method in self.allMethods) {
      for (GTLDiscoveryJsonSchema *param in method.sortedParametersWithResource) {
        NSString *schemaType = param.type;
        if ([schemaType isEqual:@"object"]) {
          [worker addObject:param];
        } else if ([schemaType isEqual:@"array"]) {
          GTLDiscoveryJsonSchema *paramItems =
            [param itemsSchemaResolving:NO depth:NULL];
          if ([paramItems.type isEqual:@"object"]) {
            [worker addObject:paramItems];
          }
        }
      }
    }

    result = [NSArray arrayWithArray:worker];
    [self setProperty:result forKey:kAllMethodObjectParametersKey];
  }
  return result;
}

// These are resolved schema references in the method parameters (refs or
// inline).
- (NSArray *)allMethodObjectParameterReferences {
  NSArray *result = [self propertyForKey:kAllMethodObjectParameterRefsKey];
  if (result == nil) {
    NSMutableArray *worker = [NSMutableArray array];

    for (GTLDiscoveryRpcMethod *method in self.allMethods) {
      for (GTLDiscoveryJsonSchema *param in method.sortedParametersWithResource) {
        GTLDiscoveryJsonSchema *resolvedParam = param.resolvedSchema;
        NSString *schemaType = resolvedParam.type;
        if ([schemaType isEqual:@"object"]) {
          [worker addObject:resolvedParam];
        } else if ([schemaType isEqual:@"array"]) {
          GTLDiscoveryJsonSchema *paramItems =
            [resolvedParam itemsSchemaResolving:YES depth:NULL];
          if ([paramItems.type isEqual:@"object"]) {
            [worker addObject:paramItems];
          }
        }
      }
    }

    result = [NSArray arrayWithArray:worker];
    [self setProperty:result forKey:kAllMethodObjectParameterRefsKey];
  }
  return result;
}

- (NSString *)builtRPCUrlString {
  NSString *result = [self propertyForKey:kBuiltRPCUrlStringKey];
  if (result == nil) {
    FHGenerator *generator = self.generator;

    NSString *rootUrlString = self.rootUrl;
    NSString *rpcPathString = self.rpcPath;
    BOOL didOverride = NO;
    if (([rootUrlString length] > 0) && ([rpcPathString length] > 0)) {
      if (generator.allowRootURLOverrides
          && [rootUrlString hasSuffix:@".sandbox.google.com/"]) {
        NSString *str =
          [NSString stringWithFormat:@"API rootUrl (%@) seems to be a Google test system, overriding with googleapis, use --rootURLOverrides NO to disable.",
           rootUrlString];
        [generator addInfo:str];
        rootUrlString = @"https://www.googleapis.com/";
        didOverride = YES;
      }
      NSURL *baseURL = [NSURL URLWithString:rootUrlString];
      NSURL *builtURL = [NSURL URLWithString:rpcPathString relativeToURL:baseURL];
      result = [builtURL absoluteString];
    }
    if (![result length]) {
      // Fall back to the older rpc URL if need be.
      result = self.rpcUrl;
      if ([result length]) {
        NSString *str =
          [NSString stringWithFormat:@"API didn't have a rootUrl and/or rpcPath ('%@' & '%@'), using old rpcUrl (%@).",
           rootUrlString, rpcPathString, result];
        [generator addWarning:str];
      } else {
        result = nil;  // Avoid storing empty string.
      }
    } else if (!didOverride) {
      // Warn if the old and new values differ.
      if (self.rpcUrl && ![result isEqual:self.rpcUrl]) {
        NSString *infoStr =
          [NSString stringWithFormat:@"calculated API endpoint is different than the old value ('%@' vs '%@').",
           result, self.rpcUrl];
        [generator addInfo:infoStr];
      }
    }
    [self setProperty:result forKey:kBuiltRPCUrlStringKey];
  }
  return result;
}

- (BOOL)likelyRESTOnlyAPI {
  // Like the logic in -builtRPCUrlString...
  // If we have a rootUrl & rpcPath, it isn't a OnePlatofrm REST only api.
  if (([self.rootUrl length] != 0) && ([self.rpcPath length] != 0)) {
    return NO;
  }
  // or, if we have the older rpcUrl, it also isn't REST only.
  if ([self.rpcUrl length] != 0) {
    return NO;
  }
  // Without one of those two, we can't make a rpc url for the service, so assume it is REST only.
  return YES;
}

- (BOOL)isGoogleService {
  // If the ownerDomain is google.com, it is a google service.
  if ([self.ownerDomain isEqual:@"google.com"]) {
    return YES;
  }
  // ownerDomain got added along the way, before that existed we figured this out
  // by looking at the URL for the service. So still use that as a fallback check
  // if ownerDomain wasn't a google.com match.
  NSString *rpcUrlString = [self builtRPCUrlString];
  NSURL *rpcURL = [NSURL URLWithString:rpcUrlString];
  NSString *rpcURLHost = [rpcURL host];
  BOOL result = ([rpcURLHost hasSuffix:@".googleapis.com"] ||
                 [rpcURLHost hasSuffix:@".google.com"]);
  return result;
}

- (BOOL)hasMediaUploadMethods {
  for (GTLDiscoveryRpcMethod *method in self.allMethods) {
    if ([[method supportsMediaUpload] boolValue]) {
      return YES;
    }
  }
  return NO;
}

@end

@implementation GTLDiscoveryJsonSchema (FHGeneratorAdditions)

- (NSString *)name {
  NSString *result = [self propertyForKey:kNameKey];
  return result;
}

typedef enum {
  kTypeQuery,
  kTypeObject,
} EQueryOrObject;

static NSDictionary *OverrideMap(EQueryOrObject queryOrObject,
                                 NSDictionary **outCommentMap) {
  static NSDictionary *objectReserved = nil;
  static NSDictionary *objectReservedComments = nil;
  static NSDictionary *queryReserved = nil;
  static NSDictionary *queryReservedComments = nil;
  if (objectReserved == nil) {
    NSString *langReserved[] = {
    // Objective C "keywords" that aren't in C/C++
    // From http://stackoverflow.com/questions/1873630/reserved-keywords-in-objective-c
      @"id",
      @"super",
      @"in",
      @"out",
      @"inout",
      @"bycopy",
      @"byref",
      @"oneway",
      @"self",
      @"nil",
      // C/C++ keywords (Incl C++ 0x11)
      // From http://en.cppreference.com/w/cpp/keywords
      @"and",
      @"alignas",
      @"alignof",
      @"asm",
      @"auto",
      @"bitand",
      @"bitor",
      @"bool",
      @"break",
      @"case",
      @"catch",
      @"char",
      @"compl",
      @"const",
      @"constexpr",
      @"continue",
      @"decltype",
      @"default",
      @"delete",
      @"double",
      @"else",
      @"enum",
      @"explicit",
      @"export",
      @"extern ",
      @"false",
      @"float",
      @"for",
      @"friend",
      @"goto",
      @"if",
      @"inline",
      @"int",
      @"long",
      @"mutable",
      @"namespace",
      @"new",
      @"noexcept",
      @"not",
      @"nullptr",
      @"operator",
      @"or",
      @"private",
      @"protected",
      @"public",
      @"register",
      @"return",
      @"short",
      @"signed",
      @"sizeof",
      @"static",
      @"struct",
      @"switch",
      @"template",
      @"this",
      @"throw",
      @"true",
      @"try",
      @"typedef",
      @"typeid",
      @"typename",
      @"union",
      @"unsigned",
      @"using",
      @"virtual",
      @"void",
      @"volatile",
      @"while",
      @"xor",
      // C99 keywords
      // From http://publib.boulder.ibm.com/infocenter/lnxpcomp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8l.doc%2Flanguage%2Fref%2Fkeyw.htm
      @"restrict",
    };
    // NSObject methods
    NSString *nsobjectReserved[] = {
      @"description",
      @"debugDescription",
      @"finalize",
      @"hash",
      @"dealloc",
      @"init",
      @"class",
      @"superclass",
      @"retain",
      @"release",
      @"autorelease",
      @"retainCount",
      @"zone",
      @"isProxy",
      @"classForCoder",
      // Foundation protocol methods.
      @"copy",
      @"copyWithZone",
      @"mutableCopy",
      @"mutableCopyWithZone",
      @"new",
    };
    // GTLObject methods
    NSString *gtlObjectReserved[] = {
      @"JSON",
      @"JSONString",
      @"surrogates",
      @"userProperties",
      @"additionalJSONKeys",
      @"additionalProperties",
      @"userData",
      @"fieldsDescription",
    };
    // GTLQuery methods
    NSString *gtlQueryReserved[] = {
      @"isBatchQuery",
      @"shouldSkipAuthorization",
      @"executionDidStop",
      @"additionalHTTPHeaders",
      @"uploadParameters",
      @"methodName",
      @"JSON",
      @"bodyObject",
      @"requestID",
      @"urlQueryParameters",
      @"expectedObjectClass",
      @"completionBlock",
    };

    NSMutableDictionary *builderMappings = [NSMutableDictionary dictionary];
    NSMutableDictionary *builderComments = [NSMutableDictionary dictionary];

    // Add in the common mappings first.
    for (size_t i = 0; i < ARRAY_COUNT(langReserved); ++i) {
      NSString *word = langReserved[i];
      NSString *reason =
        [NSString stringWithFormat:@"Remapped to '%@Property' to avoid language reserved word '%@'.",
         word, word];
      [builderMappings setObject:[word stringByAppendingString:@"Property"]
                          forKey:word];
      [builderComments setObject:reason forKey:word];
    }
    for (size_t i = 0; i < ARRAY_COUNT(nsobjectReserved); ++i) {
      NSString *word = nsobjectReserved[i];
      NSString *reason =
        [NSString stringWithFormat:@"Remapped to '%@Property' to avoid NSObject's '%@'.",
         word, word];
      [builderMappings setObject:[word stringByAppendingString:@"Property"]
                          forKey:word];
      [builderComments setObject:reason forKey:word];
    }
    // Map etag to be nicer, but it doesn't need any reason in the comments.
    [builderMappings setObject:@"ETag" forKey:@"etag"];
    // We remap "id" to identifier, so we also have to remap "identifier".
    [builderMappings setObject:@"identifier" forKey:@"id"];
    [builderMappings setObject:@"identifierProperty" forKey:@"identifier"];
    [builderComments setObject:@"identifier property maps to 'id' in JSON (to avoid Objective C's 'id')."
                        forKey:@"id"];
    [builderComments setObject:@"identifierProperty property maps to 'identifier' in the JSON ('identifier' is reserved for remapping 'id')."
                        forKey:@"identifier"];

    // Now make a second set of builders for adding the things reserved on
    // Query vs. Object.
    NSMutableDictionary *builderMappings2 =
      [NSMutableDictionary dictionaryWithDictionary:builderMappings];
    NSMutableDictionary *builderComments2 =
      [NSMutableDictionary dictionaryWithDictionary:builderComments];

    // GTLObject specific
    for (size_t i = 0; i < ARRAY_COUNT(gtlObjectReserved); ++i) {
      NSString *word = gtlObjectReserved[i];
      NSString *reason =
        [NSString stringWithFormat:@"Remapped to '%@Property' to avoid GTLObject's '%@'.",
         word, word];
      [builderMappings setObject:[word stringByAppendingString:@"Property"]
                          forKey:word];
      [builderComments setObject:reason forKey:word];
    }

    // GTLQuery specific
    for (size_t i = 0; i < ARRAY_COUNT(gtlQueryReserved); ++i) {
      NSString *word = gtlQueryReserved[i];
      NSString *reason =
        [NSString stringWithFormat:@"Remapped to '%@Property' to avoid GTLQuery's '%@'.",
         word, word];
      [builderMappings2 setObject:[word stringByAppendingString:@"Property"]
                           forKey:word];
      [builderComments2 setObject:reason forKey:word];
    }

    objectReserved = [builderMappings copy];
    objectReservedComments = [builderComments copy];
    queryReserved = [builderMappings2 copy];
    queryReservedComments = [builderComments2 copy];
  }

  NSDictionary *result;
  NSDictionary *comments;
  switch (queryOrObject) {
    case kTypeQuery:
      result = queryReserved;
      comments = queryReservedComments;
      break;

    case kTypeObject:
      result = objectReserved;
      comments = objectReservedComments;
      break;
  }
  if (outCommentMap) *outCommentMap = comments;
  return result;
}

static NSString *OverrideName(NSString *name, EQueryOrObject queryOrObject,
                              NSString **outComment) {
  NSDictionary *comments = nil;
  NSDictionary *map = OverrideMap(queryOrObject, &comments);
  NSString *result = [map objectForKey:name];
  if (result && outComment) {
    *outComment = [comments objectForKey:name];
  }
  // No override. Return the name to simplify the flow for callers.
  if (result == nil) result = name;
  return result;
}

- (NSString *)objcName {
  NSString *result = [self propertyForKey:kObjCNameKey];
  if (result == nil) {
    result = [FHUtils objcName:self.name shouldCapitalize:NO];
    NSString *comment = nil;
    result = OverrideName(result,
                          ( self.isParameter ? kTypeQuery : kTypeObject ),
                          &comment);
    [self setProperty:result forKey:kObjCNameKey];
    if (comment) {
      [self setProperty:comment forKey:kForcedNameCommentKey];
    }
  }
  return result;
}

- (NSString *)forceNameComment {
  // Call objcName to make sure the value is set.
  (void)[self objcName];
  NSString *result = [self propertyForKey:kForcedNameCommentKey];
  return result;
}

// Helper to get the capitalized Objective-C form of the name.
- (NSString *)capObjCName {
  NSString *result = [self propertyForKey:kCapObjCNameKey];
  if (result == nil) {
    // We just use objcName and then capitalize the first letter. This way
    // all name overrides/checks are handled in one place.
    result = self.objcName;
    result = [[[result substringToIndex:1] uppercaseString] stringByAppendingString:[result substringFromIndex:1]];
    [self setProperty:result forKey:kCapObjCNameKey];
  }
  return result;
}

// The direct parameter off a method that is the parent/grandparent of
// any child schema.
- (GTLDiscoveryJsonSchema *)methodParam {
  GTLDiscoveryJsonSchema *parent = self;
  while (parent.parentSchema != nil) {
    parent = parent.parentSchema;
  }
  return parent;
}

- (GTLDiscoveryRpcMethod *)method {
  GTLDiscoveryRpcMethod *result =
    [[self.methodParam propertyForKey:kWrappedMethodKey] nonretainedObjectValue];
  return result;
}

- (BOOL)isParameter {
  // Only valid on the top most schema, simply check if the method is set.
  BOOL result = (self.method != nil);
  return result;
}

- (NSString *)errorReportingName {
  return self.fullSchemaName;
}

- (GTLDiscoveryJsonSchema *)parentSchema {
  GTLDiscoveryJsonSchema *result =
      [[self propertyForKey:kWrappedSchemaKey] nonretainedObjectValue];
  return result;
}

- (NSArray *)fullSchemaPath:(BOOL)formatted
             foldArrayItems:(BOOL)foldArrayItems {
  NSMutableArray *builder = [NSMutableArray array];

  FHGenerator *generator = self.generator;
  BOOL wasArray = NO;
  GTLDiscoveryJsonSchema *walker = self;
  while (walker != nil) {
    NSString *name = walker.name;
    GTLDiscoveryJsonSchema *parent = walker.parentSchema;
    BOOL isArray = [parent.type isEqual:@"array"];

    // Should it be formatted or not?
    if (formatted) {
      // The top level schema (no parent) can have poor names when they also
      // don't have a 'kind' for the server to go off of.  For this case, we
      // try to fix up some of the common bad things.
      if ((parent == nil) &&
          !walker.isParameter &&
          ([walker kindToRegister] == nil)) {

        NSString *initialName = name;

        // Use a loop so the order of things doesn't matter.  One correction per
        // cycle of the loop.
        while (1) {
          // Use lowercase so things only have to be checked in one case.
          NSString *lowerName = [name lowercaseString];
          NSUInteger nameLen = [name length];

          // We used to do some fixup for trailing version numbers (with and
          // without the '.' in the number), but that appears to no longer
          // be needed and as some apis have evolved they actually have real
          // reasons to have "V2" at the end of their scheme names.

          // Trailing 'json'
          if ([lowerName hasSuffix:@"json"] && nameLen != 4) {
            name = [name substringToIndex:nameLen - 4];
            continue;
          }

          // Service name on type (we add it ourselves).
          NSString *apiName = [generator.formattedApiName lowercaseString];
          if ([lowerName hasPrefix:apiName] && nameLen != [apiName length]) {
            name = [name substringFromIndex:[apiName length]];
            continue;
          }

          // Nothing changed, out of here...
          break;
        }

        if ((generator.verboseLevel > 0) && (initialName != name)) {
          // Yes, we might do this more than once, but addWarning dedupes for
          // us.
          NSString *infoStr =
            [NSString stringWithFormat:@"schema '%@' has a poor name and no 'kind', using '%@'.",
             walker.name, name];
          [generator addInfo:infoStr];
        }
      }

      // Format the name.
      name = [FHUtils objcName:name shouldCapitalize:YES];
    }

    // foldArrayItems allows the class names to avoid ending up like
    // "...ItemItem" for arrays of arrays.  This ends up with only one
    // instance of "Item" being there.
    if (foldArrayItems && wasArray && isArray) {
      [builder removeObjectAtIndex:0];
    }

    // Now it is usable...
    [builder insertObject:name atIndex:0];

    // If this is a parameter, its name is just the name on the method and
    // that might not result in something unique.  So we have to pull the
    // actual method name in also to help make sure it is unique.
    if ((parent == nil) && walker.isParameter) {
      NSArray *nameParts = [walker.method.name componentsSeparatedByString:@"."];
      if ([nameParts count] < 2) {
        [NSException raise:kFatalGeneration
                    format:@"Got an rpcMethod (%@) with fewer than two segments",
         walker.method.name];
      }
      // Drop the service name.
      nameParts = [nameParts subarrayWithRange:NSMakeRange(1, [nameParts count] - 1)];
      NSUInteger insertIndex = 0;
      for (NSString *namePart in nameParts) {
        if (formatted) {
          namePart = [FHUtils objcName:namePart shouldCapitalize:YES];
        }
        [builder insertObject:namePart atIndex:insertIndex++];
      }
    }

    // Up to the parent
    walker = parent;
    wasArray = isArray;
  }

  return builder;
}

- (NSString *)fullSchemaName {
  NSArray *parts = [self fullSchemaPath:NO foldArrayItems:NO];
  NSString *result = [parts componentsJoinedByString:@"."];
  return result;
}

- (NSString *)objcClassName {
  // Always use the resolved schema so we get real names.
  GTLDiscoveryJsonSchema *resolvedSchema = self.resolvedSchema;

  NSString *result = [resolvedSchema propertyForKey:kSchemaObjCClassNameKey];
  if (result == nil) {
    NSArray *parts = [resolvedSchema fullSchemaPath:YES foldArrayItems:YES];
    NSString *fullName = [parts componentsJoinedByString:@""];

    result = [NSString stringWithFormat:@"%@%@%@",
              kProjectPrefix, self.generator.formattedApiName, fullName];

    [resolvedSchema setProperty:result forKey:kSchemaObjCClassNameKey];
  }
  return result;
}

- (NSArray *)childObjectSchemas {
  NSArray *result = [self propertyForKey:kChildObjectSchemasKey];
  if (result == nil) {

    NSMutableArray *worker = [NSMutableArray array];

    [worker addObject:self];
    NSUInteger idx = 0;
    while (idx < [worker count]) {
      // properties...
      GTLDiscoveryJsonSchema *schema = [worker objectAtIndex:idx];

      // All of the properties that are objects or an array of objects count.

      NSArray *schemas = DictionaryObjectsSortedByKeys(schema.properties.additionalProperties);
      for (GTLDiscoveryJsonSchema *subSchema in schemas) {
        if ([subSchema.type isEqual:@"object"]) {
          [worker addObject:subSchema];
        } else if ([subSchema.type isEqual:@"array"]) {
          GTLDiscoveryJsonSchema *itemsSchema =
              [subSchema itemsSchemaResolving:NO depth:NULL];
          if ([itemsSchema.type isEqual:@"object"]) {
            [worker addObject:itemsSchema];
          }
        }
      }

      // If the additonalProperties are objects or arrays of objects, they count.

      GTLDiscoveryJsonSchema *additionalPropsSchema = schema.additionalPropertiesProperty;
      if ([additionalPropsSchema.type isEqual:@"object"]) {
        [worker addObject:additionalPropsSchema];
      } else if ([additionalPropsSchema.type isEqual:@"array"]) {
        GTLDiscoveryJsonSchema *itemsSchema =
            [additionalPropsSchema itemsSchemaResolving:NO depth:NULL];
        if ([itemsSchema.type isEqual:@"object"]) {
          [worker addObject:itemsSchema];
        }
      }
      ++idx;
    }

    // Drop self (added at the start) in getting the result.
    result = [worker subarrayWithRange:NSMakeRange(1, [worker count] - 1)];
    [self setProperty:result forKey:kChildObjectSchemasKey];
  }
  return result;
}

// Helper to resolve any $ref to the real schema definition.
- (GTLDiscoveryJsonSchema *)resolvedSchema {
  GTLDiscoveryJsonSchema *result = [self propertyForKey:kResolvedSchemaKey];
  if (result == nil) {
    GTLDiscoveryRpcDescription *api = self.generator.api;
    result = self;
    NSString *schemaReference;
    while ((schemaReference = result.xRef) != nil) {
      GTLDiscoveryJsonSchema *schema =
        [api.schemas.additionalProperties objectForKey:schemaReference];
      if (schema != nil) {
        result = schema;
      } else {
        [NSException raise:kFatalGeneration
                    format:@"Resolving schema '%@', referenced an undefined schema '%@'",
                           self.fullSchemaName, schemaReference];

      }
    }

    [self setProperty:result forKey:kResolvedSchemaKey];
  }
  return result;
}

// Helper to check if the object has an "items" property that is an array
// and the object for this schema should be treated as a collection.
- (BOOL)hasItemsArrayProperty {
  BOOL result = NO;

  GTLDiscoveryJsonSchema *property =
    [self.properties additionalPropertyForName:@"items"];
  if ([property.type isEqual:@"array"]) {
    result = YES;
  }
  return result;
}

// Helper to extract the "kind" that this schema should be registered with for
// +load method.
- (NSString *)kindToRegister {
  NSString *result = nil;

  // Pull the kind schema, and check that it is the right type and has a
  // value.
  GTLDiscoveryJsonSchema *property =
    [self.properties additionalPropertyForName:@"kind"];
  if ([property.type isEqual:@"string"] &&
      [property.defaultProperty length] > 0) {
    result = property.defaultProperty;
  }
  return result;
}

// Helper to generate a comment about the range and/or default value for
// the parameter.
- (NSString *)rangeAndDefaultDescription {
  NSString *result = nil;

  NSString *paramMin = self.minimum;
  NSString *paramMax = self.maximum;
  NSString *paramDefault = self.defaultProperty;

  // We don't worry about min/max being reversed or equal. Hopefully (like
  // everything else) the discovery information makes sense...

  BOOL hasMinMax = ([paramMin length] > 0 && [paramMax length] > 0);
  BOOL hasDefault = ([paramDefault length] > 0);

  if (hasDefault) {
    // If there is a default, handle the enums by showing the enum constant
    // name instead of the raw value.
    NSArray *enumValues = self.enumProperty;
    if ([enumValues count] > 0) {
      // Hopefully if there is an enum, it has the default value so there
      // is a constant for it. But in case it doesn't, just quote the value.
      if ([enumValues containsObject:paramDefault]) {
        paramDefault = [self constantNamed:paramDefault];
      } else {
        paramDefault = [NSString stringWithFormat:@"\"%@\"", paramDefault];
      }
    }
  }

  if (hasMinMax && hasDefault) {
    result = [NSString stringWithFormat:@"%@..%@, default %@",
              paramMin, paramMax, paramDefault];
  } else if (hasMinMax) {
    result = [NSString stringWithFormat:@"%@..%@", paramMin, paramMax];
  } else if (hasDefault) {
    result = [NSString stringWithFormat:@"Default %@", paramDefault];
  }

  return result;
}

// Fetching the item's schema even if it is nested (array inside of array...),
// resolving controls if it also resolves the schema references along the way.
- (GTLDiscoveryJsonSchema *)itemsSchemaResolving:(BOOL)resolving
                                           depth:(NSUInteger *)depth {
  GTLDiscoveryJsonSchema *worker = self;
  NSUInteger counter = 0;

  do {
    ++counter;
    worker = worker.items;
    if (resolving) {
      worker = worker.resolvedSchema;
    }
  } while ([worker.type isEqual:@"array"]);

  if (depth) {
    *depth = counter;
  }
  return worker;
}

- (NSString *)constantNamed:(NSString *)name {
  NSString *group = [NSString stringWithFormat:@"%@%@%@",
                     kProjectPrefix,
                     self.generator.formattedApiName,
                     self.capObjCName];
  NSString *result = ConstantName(group, name);
  return result;
}

#pragma mark Mapping from Schema to object/query parameters

typedef struct {
  NSString *objcType;
  BOOL      asPointer;
  NSString *objcPropertySemantics;
  NSString *comment;
} FHTypeInfo;

typedef struct {
  NSString   *type;
  NSString   *format;
  FHTypeInfo  objectTypeInfo;  // When it has to be a pointer.
  FHTypeInfo  podTypeInfo;  // When it can be a plain old data type.
} FHTypeFormatMapping;

// Special marker for objcType to fetch the class from the "item" instead of
// the hardcoded value.
#define kUseItemsClass @"ITEMS_CLASS"

static FHTypeFormatMapping kObjectParameterMappings[] = {
  // http://code.google.com/apis/discovery/v1/reference.html#type-and-format-summary
  { @"any", nil,             { @"id", NO, @"retain", nil },
                             { @"id", NO, @"retain", nil } },

  { @"array", nil,           { @"NSArray", YES, @"retain", nil },
                             { @"NSArray", YES, @"retain", nil } },

  { @"boolean", nil,         { @"NSNumber", YES, @"retain", @"boolValue" },
                             { @"BOOL", NO, @"assign", nil } },

  { @"integer", @"int32",    { @"NSNumber", YES, @"retain", @"intValue" },
                             { @"NSInteger", NO, @"assign", nil } },
  { @"integer", @"uint32",   { @"NSNumber", YES, @"retain", @"unsignedIntValue" },
                             { @"NSUInteger", NO, @"assign", nil } },

  { @"number", @"double",    { @"NSNumber", YES, @"retain", @"doubleValue" },
                             { @"double", NO, @"assign", nil } },
  { @"number", @"float",     { @"NSNumber", YES, @"retain", @"floatValue" },
                             { @"float", NO, @"assign", nil } },

  { @"object", nil,          { kUseItemsClass, YES, @"retain", nil },
                             { kUseItemsClass, YES, @"retain", nil } },

  { @"string", @"byte",      { @"NSString", YES, @"copy", @"GTLBase64 can encode/decode (probably web-safe format)" },
                             { @"NSString", YES, @"copy", @"GTLBase64 can encode/decode (probably web-safe format)" } },
  { @"string", @"date",      { @"GTLDateTime", YES, @"retain", @"Date only (yyyy-mm-dd)"},
                             { @"GTLDateTime", YES, @"retain", @"Date only (yyyy-mm-dd)"} },
  { @"string", @"date-time", { @"GTLDateTime", YES, @"retain", nil },
                             { @"GTLDateTime", YES, @"retain", nil }},
  { @"string", @"int64",     { @"NSNumber", YES, @"retain", @"longLongValue" },
                             { @"long long", NO, @"assign", nil } },
  { @"string", @"uint64",    { @"NSNumber", YES, @"retain", @"unsignedLongLongValue" },
                             { @"unsigned long long", NO, @"assign", nil } },
  { @"string", nil,          { @"NSString", YES, @"copy", nil },
                             { @"NSString", YES, @"copy", nil } },
};

static FHTypeInfo *LookupTypeInfo(NSString *typeString,
                                  NSString *formatString,
                                  BOOL asObject) {
  // Find the match in the table
  for (uint32_t idx = 0; idx < ARRAY_COUNT(kObjectParameterMappings); ++idx) {
    if (GTL_AreEqualOrBothNil(kObjectParameterMappings[idx].type, typeString) &&
        GTL_AreEqualOrBothNil(kObjectParameterMappings[idx].format, formatString)) {
      if (asObject) {
        return &(kObjectParameterMappings[idx].objectTypeInfo);
      } else {
        return &(kObjectParameterMappings[idx].podTypeInfo);
      }
    }
  }

  return nil;
}

- (void)getObjectParamObjCType:(NSString **)objcType
                     asPointer:(BOOL *)asPointer
         objcPropertySemantics:(NSString **)objcPropertySemantics
                       comment:(NSString **)comment {
  // NOTE: Here we are creating data objects.  Objects need to support values
  // being unset.  That means we need to wrap ints, bools, etc. in NSNumber so
  // nil can mean unset.

  // Resolve the schema to get real types let everything else uses
  // the references to get local names.
  GTLDiscoveryJsonSchema *resolvedSchema = self.resolvedSchema;

  NSString *schemaType = resolvedSchema.type;
  NSString *schemaFormat = resolvedSchema.format;

  // Look it up...
  FHTypeInfo *typeInfo = LookupTypeInfo(schemaType, schemaFormat, YES);
  if (typeInfo == nil) {
    [NSException raise:kFatalGeneration
                format:@"Looking at schema '%@', found a type/format pair of '%@/%@', and don't how to map that to Objective-C",
     resolvedSchema.fullSchemaName, schemaType, schemaFormat];
  }

  if ([typeInfo->objcType isEqual:kUseItemsClass]) {
    *objcType = resolvedSchema.objcClassName;
  } else {
    *objcType = typeInfo->objcType;
  }

  if (asPointer) *asPointer = typeInfo->asPointer;
  if (objcPropertySemantics) *objcPropertySemantics = typeInfo->objcPropertySemantics;

  if (comment) {
    *comment = typeInfo->comment;

    // Arrays get special comments that are built up based on the items.
    if ([schemaType isEqual:@"array"]) {
      NSString *builder = nil;
      NSUInteger depth = 0;
      GTLDiscoveryJsonSchema *itemsSchema =
          [resolvedSchema itemsSchemaResolving:YES depth:&depth];
      NSString *itemsObjCType = nil, *itemsComment = nil;
      if (itemsSchema == nil) {
        itemsObjCType = @"id";
        FHGenerator *generator = self.generator;
        NSString *msg =
          [NSString stringWithFormat:@"Schema %@ is array but lacks items, assuming \"any\".",
                                     [self fullSchemaName]];
        [generator addWarning:msg];
      } else {
        [itemsSchema getObjectParamObjCType:&itemsObjCType
                                  asPointer:NULL
                      objcPropertySemantics:NULL
                                    comment:&itemsComment];
      }
      if ([itemsObjCType isEqual:@"id"]) {
        builder = @"of any JSON type";
      } else {
        if ([itemsComment length] > 0) {
          builder = [NSString stringWithFormat:@"of %@ (%@)",
                     itemsObjCType, itemsComment];
        } else {
          builder = [NSString stringWithFormat:@"of %@", itemsObjCType];
        }
      }
      // Provide info when it is array of array...
      while (depth-- > 1) {
        builder = [@"of NSArray " stringByAppendingString:builder];
      }
      // Now use the comment.
      *comment = builder;
    }
  }
}

- (void)getQueryParamObjCType:(NSString **)objcType
                    asPointer:(BOOL *)asPointer
        objcPropertySemantics:(NSString **)objcPropertySemantics
                      comment:(NSString **)comment
               itemsClassName:(NSString **)itemsClassName {

  // NOTE: This is on Parameters, meaning we're query objects.  Since we get
  // default values and we don't need to communicate the "removal" of some
  // property, we can use raw NSInteger, BOOL, etc. for the values.

  // Resolve the schema to get real types. Let everything else use
  // the references to get local names.
  GTLDiscoveryJsonSchema *resolvedSchema = self.resolvedSchema;

  NSString *paramType = resolvedSchema.type;
  NSString *paramFormat = resolvedSchema.format;

  // TODO: remove use of 'repeated' when all arrays use type:array.
  // TODO: when everything uses type:array, might be able to merge this with
  //       the schema method and simply have a flag that says if we can use
  //       POD types vs. objects.

  // Repeating means it's an array.  But when schemas are inlined, it could
  // also be type 'array'.  So pick them off, and figure out the type/format
  // to look up for the items within the array.
  if (resolvedSchema.repeated || [paramType isEqual:@"array"]) {

    *objcType = @"NSArray";
    if (asPointer) *asPointer = YES;
    if (objcPropertySemantics) *objcPropertySemantics = @"retain";

    NSUInteger depth = 1;
    GTLDiscoveryJsonSchema *itemsSchema = resolvedSchema;

    if ([paramType isEqual:@"array"]) {
      // type 'array' means pull the info off the item (like objects).
      itemsSchema = [resolvedSchema itemsSchemaResolving:YES depth:&depth];
      if (itemsSchema == nil) {
        paramType = @"any";
        paramFormat = nil;
        FHGenerator *generator = self.generator;
        NSString *msg =
          [NSString stringWithFormat:@"Schema %@ is array but lacks items, assuming \"any\".",
                                     [self fullSchemaName]];
        [generator addWarning:msg];
      } else {
        paramType = itemsSchema.type;
        paramFormat = itemsSchema.format;
      }
    }

    // Look up the item info.
    FHTypeInfo *typeInfo = LookupTypeInfo(paramType, paramFormat, YES);
    if (typeInfo == nil) {
      [NSException raise:kFatalGeneration
                  format:@"Looking at parameter '%@:%@', found a repeating type/format pair of '%@/%@', and don't how to map that to Objective-C",
       self.method.name, self.name, paramType, paramFormat];
    }

    NSString *localItemsClassName = typeInfo->objcType;
    if ([localItemsClassName isEqual:kUseItemsClass]) {
      if (resolvedSchema == itemsSchema) {
        [NSException raise:kFatalGeneration
                    format:@"Looking at parameter '%@:%@', found a repeating object, currently can't generate class names for those correctly.",
         self.method.name, self.name];
      }
      localItemsClassName = itemsSchema.objcClassName;
    }

    if (itemsClassName) *itemsClassName = localItemsClassName;

    if (comment) {
      NSString *builder = nil;
      if ([localItemsClassName isEqual:@"id"]) {
        builder = @"of any JSON type";
      } else {
        if ([typeInfo->comment length] > 0) {
          builder = [NSString stringWithFormat:@"of %@ (%@)",
                     localItemsClassName, typeInfo->comment];
        } else {
          builder = [NSString stringWithFormat:@"of %@", localItemsClassName];
        }
      }
      // Provide info when it is array of array...
      while (depth-- > 1) {
        builder = [@"of NSArray " stringByAppendingString:builder];
      }
      // Off it goes
      *comment = builder;
    }

  } else {

    // Look it up
    FHTypeInfo *typeInfo = LookupTypeInfo(paramType, paramFormat, NO);
    if (typeInfo == nil) {
      [NSException raise:kFatalGeneration
                  format:@"Looking at parameter '%@:%@', found a type/format pair of '%@/%@', and don't how to map that to Objective-C",
       self.method.name, self.name, paramType, paramFormat];
    }

    if ([typeInfo->objcType isEqual:kUseItemsClass]) {
      *objcType = resolvedSchema.objcClassName;
    } else {
      *objcType = typeInfo->objcType;
    }

    if (asPointer) *asPointer = typeInfo->asPointer;
    if (objcPropertySemantics) *objcPropertySemantics = typeInfo->objcPropertySemantics;
    if (comment) *comment = typeInfo->comment;
    if (itemsClassName) *itemsClassName = nil;

  }

}

// Helper to make a string that sorta is the objc type for a param.
- (NSString *)queryParamPseudoObjCType {
  NSString *paramType = nil;
  NSString *itemsClassName = nil;
  [self getQueryParamObjCType:&paramType
                    asPointer:NULL
        objcPropertySemantics:NULL
                      comment:NULL
               itemsClassName:&itemsClassName];
  if ([itemsClassName length]) {
    paramType = [paramType stringByAppendingFormat:@"<%@>", itemsClassName];
  }
  return paramType;
}

@end

@implementation GTLDiscoveryRpcMethod (FHGeneratorAdditions)

- (NSString *)name {
  NSString *result = [self propertyForKey:kNameKey];
  return result;
}

- (NSString *)objcQueryForName {
  NSString *result = [self propertyForKey:kObjCQueryForNameKey];
  if (result == nil) {
    NSArray *worker = [self.name componentsSeparatedByString:@"."];
    if ([worker count] < 2) {
      [NSException raise:kFatalGeneration
                  format:@"Got an rpcMethod (%@) with fewer than two segments",
       self.name];
    }
    // Drop the service name and use the rest.
    worker = [worker subarrayWithRange:NSMakeRange(1, [worker count] - 1)];
    NSMutableString *builder = [NSMutableString string];
    for (NSString *part in worker) {
      NSString *capPart = [FHUtils objcName:part shouldCapitalize:YES];
      [builder appendString:capPart];
    }

    result = [NSString stringWithFormat:@"queryFor%@", builder];

    [self setProperty:result forKey:kObjCQueryForNameKey];
  }
  return result;
}

- (NSString *)groupingName {
  NSArray *parts = [self groupingParts];
  NSString *result = [parts componentsJoinedByString:@"."];
  return result;
}

- (GTLDiscoveryJsonSchema *)request {
  // The request object is the parameter named 'resource'.
  GTLDiscoveryJsonSchema *result =
    [self.parameters.additionalProperties objectForKey:kResourceParameterName];
  return result;
}

// Sorted by parameterOrder first, and then alphabetical for the rest. This
// list removes the "resource" parameter since the library special cases it.
- (NSArray *)sortedParameters {
  NSArray *result = [self propertyForKey:kSortedParametersKey];
  if (result == nil) {
    // sortedParametersWithResource will calculate and save the value.
    (void)self.sortedParametersWithResource;
    result = [self propertyForKey:kSortedParametersKey];
  }
  return result;
}

// Sorted by parameterOrder first, and then alphabetical for the rest.  This
// list does NOT remove the "resource" parameter.
- (NSArray *)sortedParametersWithResource {
  NSArray *result = [self propertyForKey:kSortedParametersWithResourceKey];
  if (result == nil) {
    NSDictionary *paramsDict = self.parameters.additionalProperties;
    NSArray *allKeys = [paramsDict allKeys];

    NSArray *paramOrder = self.parameterOrder;
    NSMutableArray *remainingKeys = [NSMutableArray arrayWithArray:allKeys];
    if ([paramOrder count] > 0) {
      [remainingKeys removeObjectsInArray:paramOrder];
    }
    [remainingKeys sortUsingSelector:@selector(caseInsensitiveCompare:)];

    NSArray *allOrderedKeys;
    if ([paramOrder count] > 0) {
      allOrderedKeys = [paramOrder arrayByAddingObjectsFromArray:remainingKeys];
    } else {
      allOrderedKeys = remainingKeys;
    }

    // Calculate the value for sortedParameters and save it.
    NSMutableArray *worker = [NSMutableArray arrayWithArray:allOrderedKeys];
    [worker removeObject:kResourceParameterName];
    NSArray *sortedParameters = [paramsDict objectsForKeys:worker
                                            notFoundMarker:[NSNull null]];
    [self setProperty:sortedParameters forKey:kSortedParametersKey];

    // Calculate the result and save it.
    result = [paramsDict objectsForKeys:allOrderedKeys
                         notFoundMarker:[NSNull null]];
    [self setProperty:result forKey:kSortedParametersWithResourceKey];
  }
  return result;
}

- (NSArray *)groupingParts {
  NSArray *result = [self propertyForKey:kGroupingPartsKey];
  if (result == nil) {
    NSArray *worker = [self.name componentsSeparatedByString:@"."];
    if ([worker count] < 2) {
      [NSException raise:kFatalGeneration
                  format:@"Got an rpcMethod (%@) with fewer than two segments",
                         self.name];
    }
    // Drop the service name and actual verb to get the grouping.
    result = [worker subarrayWithRange:NSMakeRange(1, [worker count] - 2)];
    [self setProperty:result forKey:kGroupingPartsKey];
  }
  return result;
}

@end

@implementation GTLDiscoveryRpcMethodReturns (FHGeneratorAdditions)

- (GTLDiscoveryJsonSchema *)resolvedSchema {
  // These aren't real schema, so look up their references (and resolve them).
  GTLDiscoveryJsonSchema *result = [self propertyForKey:kResolvedSchemaKey];
  if (result == nil) {
    GTLDiscoveryJsonSchema *schema =
      [self.generator.api.schemas.additionalProperties objectForKey:self.xRef];
    if (schema != nil) {
      result = schema.resolvedSchema;
    } else {
      [NSException raise:kFatalGeneration
                  format:@"Resolving schema '%@', referenced an undefined schema '%@'",
       [self propertyForKey:kNameKey], self.xRef];
    }

    [self setProperty:result forKey:kResolvedSchemaKey];
  }
  return result;
}

@end

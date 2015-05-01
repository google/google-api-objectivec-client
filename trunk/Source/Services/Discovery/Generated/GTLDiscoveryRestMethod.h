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
//  GTLDiscoveryRestMethod.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   APIs Discovery Service (discovery/v1)
// Description:
//   Lets you discover information about other Google APIs, such as what APIs
//   are available, the resource and method details for each API.
// Documentation:
//   https://developers.google.com/discovery/
// Classes:
//   GTLDiscoveryRestMethod (0 custom class methods, 15 custom properties)
//   GTLDiscoveryRestMethodMediaUpload (0 custom class methods, 3 custom properties)
//   GTLDiscoveryRestMethodParameters (0 custom class methods, 0 custom properties)
//   GTLDiscoveryRestMethodRequest (0 custom class methods, 2 custom properties)
//   GTLDiscoveryRestMethodResponse (0 custom class methods, 1 custom properties)
//   GTLDiscoveryRestMethodMediaUploadProtocols (0 custom class methods, 2 custom properties)
//   GTLDiscoveryRestMethodMediaUploadProtocolsResumable (0 custom class methods, 2 custom properties)
//   GTLDiscoveryRestMethodMediaUploadProtocolsSimple (0 custom class methods, 2 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLDiscoveryJsonSchema;
@class GTLDiscoveryRestMethodMediaUpload;
@class GTLDiscoveryRestMethodMediaUploadProtocols;
@class GTLDiscoveryRestMethodMediaUploadProtocolsResumable;
@class GTLDiscoveryRestMethodMediaUploadProtocolsSimple;
@class GTLDiscoveryRestMethodParameters;
@class GTLDiscoveryRestMethodRequest;
@class GTLDiscoveryRestMethodResponse;

// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethod
//

@interface GTLDiscoveryRestMethod : GTLObject

// Description of this method.
// Remapped to 'descriptionProperty' to avoid NSObject's 'description'.
@property (nonatomic, copy) NSString *descriptionProperty;

// Whether this method requires an ETag to be specified. The ETag is sent as an
// HTTP If-Match or If-None-Match header.
@property (nonatomic, retain) NSNumber *etagRequired;  // boolValue

// HTTP method used by this method.
@property (nonatomic, copy) NSString *httpMethod;

// A unique ID for this method. This property can be used to match methods
// between different versions of Discovery.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Media upload parameters.
@property (nonatomic, retain) GTLDiscoveryRestMethodMediaUpload *mediaUpload;

// Ordered list of required parameters, serves as a hint to clients on how to
// structure their method signatures. The array is ordered such that the
// "most-significant" parameter appears first.
@property (nonatomic, retain) NSArray *parameterOrder;  // of NSString

// Details for all parameters in this method.
@property (nonatomic, retain) GTLDiscoveryRestMethodParameters *parameters;

// The URI path of this REST method. Should be used in conjunction with the
// basePath property at the api-level.
@property (nonatomic, copy) NSString *path;

// The schema for the request.
@property (nonatomic, retain) GTLDiscoveryRestMethodRequest *request;

// The schema for the response.
@property (nonatomic, retain) GTLDiscoveryRestMethodResponse *response;

// OAuth 2.0 scopes applicable to this method.
@property (nonatomic, retain) NSArray *scopes;  // of NSString

// Whether this method supports media downloads.
@property (nonatomic, retain) NSNumber *supportsMediaDownload;  // boolValue

// Whether this method supports media uploads.
@property (nonatomic, retain) NSNumber *supportsMediaUpload;  // boolValue

// Whether this method supports subscriptions.
@property (nonatomic, retain) NSNumber *supportsSubscription;  // boolValue

// Indicates that downloads from this method should use the download service URL
// (i.e. "/download"). Only applies if the method supports media download.
@property (nonatomic, retain) NSNumber *useMediaDownloadService;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodMediaUpload
//

@interface GTLDiscoveryRestMethodMediaUpload : GTLObject

// MIME Media Ranges for acceptable media uploads to this method.
@property (nonatomic, retain) NSArray *accept;  // of NSString

// Maximum size of a media upload, such as "1MB", "2GB" or "3TB".
@property (nonatomic, copy) NSString *maxSize;

// Supported upload protocols.
@property (nonatomic, retain) GTLDiscoveryRestMethodMediaUploadProtocols *protocols;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodParameters
//

@interface GTLDiscoveryRestMethodParameters : GTLObject
// This object is documented as having more properties that are
// GTLDiscoveryJsonSchema. Use -additionalJSONKeys and
// -additionalPropertyForName: to get the list of properties and then fetch
// them; or -additionalProperties to fetch them all at once.
@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodRequest
//

@interface GTLDiscoveryRestMethodRequest : GTLObject

// Schema ID for the request schema.
@property (nonatomic, copy) NSString *xRef;

// parameter name.
@property (nonatomic, copy) NSString *parameterName;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodResponse
//

@interface GTLDiscoveryRestMethodResponse : GTLObject

// Schema ID for the response schema.
@property (nonatomic, copy) NSString *xRef;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodMediaUploadProtocols
//

@interface GTLDiscoveryRestMethodMediaUploadProtocols : GTLObject

// Supports the Resumable Media Upload protocol.
@property (nonatomic, retain) GTLDiscoveryRestMethodMediaUploadProtocolsResumable *resumable;

// Supports uploading as a single HTTP request.
@property (nonatomic, retain) GTLDiscoveryRestMethodMediaUploadProtocolsSimple *simple;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodMediaUploadProtocolsResumable
//

@interface GTLDiscoveryRestMethodMediaUploadProtocolsResumable : GTLObject

// True if this endpoint supports uploading multipart media.
@property (nonatomic, retain) NSNumber *multipart;  // boolValue

// The URI path to be used for upload. Should be used in conjunction with the
// basePath property at the api-level.
@property (nonatomic, copy) NSString *path;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodMediaUploadProtocolsSimple
//

@interface GTLDiscoveryRestMethodMediaUploadProtocolsSimple : GTLObject

// True if this endpoint supports upload multipart media.
@property (nonatomic, retain) NSNumber *multipart;  // boolValue

// The URI path to be used for upload. Should be used in conjunction with the
// basePath property at the api-level.
@property (nonatomic, copy) NSString *path;

@end

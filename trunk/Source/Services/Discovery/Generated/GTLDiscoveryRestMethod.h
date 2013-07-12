/* Copyright (c) 2013 Google Inc.
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
//   GTLDiscoveryRestMethod (0 custom class methods, 14 custom properties)
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
@property (copy) NSString *descriptionProperty;

// Whether this method requires an ETag to be specified. The ETag is sent as an
// HTTP If-Match or If-None-Match header.
@property (retain) NSNumber *etagRequired;  // boolValue

// HTTP method used by this method.
@property (copy) NSString *httpMethod;

// A unique ID for this method. This property can be used to match methods
// between different versions of Discovery.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (copy) NSString *identifier;

// Media upload parameters.
@property (retain) GTLDiscoveryRestMethodMediaUpload *mediaUpload;

// Ordered list of required parameters, serves as a hint to clients on how to
// structure their method signatures. The array is ordered such that the
// "most-significant" parameter appears first.
@property (retain) NSArray *parameterOrder;  // of NSString

// Details for all parameters in this method.
@property (retain) GTLDiscoveryRestMethodParameters *parameters;

// The URI path of this REST method. Should be used in conjunction with the
// basePath property at the api-level.
@property (copy) NSString *path;

// The schema for the request.
@property (retain) GTLDiscoveryRestMethodRequest *request;

// The schema for the response.
@property (retain) GTLDiscoveryRestMethodResponse *response;

// OAuth 2.0 scopes applicable to this method.
@property (retain) NSArray *scopes;  // of NSString

// Whether this method supports media downloads.
@property (retain) NSNumber *supportsMediaDownload;  // boolValue

// Whether this method supports media uploads.
@property (retain) NSNumber *supportsMediaUpload;  // boolValue

// Whether this method supports subscriptions.
@property (retain) NSNumber *supportsSubscription;  // boolValue

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodMediaUpload
//

@interface GTLDiscoveryRestMethodMediaUpload : GTLObject

// MIME Media Ranges for acceptable media uploads to this method.
@property (retain) NSArray *accept;  // of NSString

// Maximum size of a media upload, such as "1MB", "2GB" or "3TB".
@property (copy) NSString *maxSize;

// Supported upload protocols.
@property (retain) GTLDiscoveryRestMethodMediaUploadProtocols *protocols;

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
@property (copy) NSString *xRef;

// parameter name.
@property (copy) NSString *parameterName;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodResponse
//

@interface GTLDiscoveryRestMethodResponse : GTLObject

// Schema ID for the response schema.
@property (copy) NSString *xRef;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodMediaUploadProtocols
//

@interface GTLDiscoveryRestMethodMediaUploadProtocols : GTLObject

// Supports the Resumable Media Upload protocol.
@property (retain) GTLDiscoveryRestMethodMediaUploadProtocolsResumable *resumable;

// Supports uploading as a single HTTP request.
@property (retain) GTLDiscoveryRestMethodMediaUploadProtocolsSimple *simple;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodMediaUploadProtocolsResumable
//

@interface GTLDiscoveryRestMethodMediaUploadProtocolsResumable : GTLObject

// True if this endpoint supports uploading multipart media.
@property (retain) NSNumber *multipart;  // boolValue

// The URI path to be used for upload. Should be used in conjunction with the
// basePath property at the api-level.
@property (copy) NSString *path;

@end


// ----------------------------------------------------------------------------
//
//   GTLDiscoveryRestMethodMediaUploadProtocolsSimple
//

@interface GTLDiscoveryRestMethodMediaUploadProtocolsSimple : GTLObject

// True if this endpoint supports upload multipart media.
@property (retain) NSNumber *multipart;  // boolValue

// The URI path to be used for upload. Should be used in conjunction with the
// basePath property at the api-level.
@property (copy) NSString *path;

@end

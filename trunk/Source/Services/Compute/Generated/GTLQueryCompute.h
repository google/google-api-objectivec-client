/* Copyright (c) 2012 Google Inc.
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
//  GTLQueryCompute.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Compute Engine API (compute/v1beta12)
// Description:
//   API for the Google Compute Engine service.
// Documentation:
//   https://developers.google.com/compute/docs/reference/v1beta12
// Classes:
//   GTLQueryCompute (39 custom class methods, 18 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLComputeAccessConfig;
@class GTLComputeDisk;
@class GTLComputeFirewall;
@class GTLComputeImage;
@class GTLComputeInstance;
@class GTLComputeMetadata;
@class GTLComputeNetwork;
@class GTLComputeSnapshot;

@interface GTLQueryCompute : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
// "accessConfig" has different types for some query methods; see the
// documentation for the right type for each query method.
@property (retain) id accessConfig;
@property (copy) NSString *disk;
@property (copy) NSString *filter;
@property (copy) NSString *firewall;
@property (copy) NSString *image;
@property (copy) NSString *instance;
@property (copy) NSString *kernel;
@property (copy) NSString *machineType;
@property (assign) NSUInteger maxResults;
@property (retain) GTLComputeMetadata *metadata;
@property (copy) NSString *network;
@property (copy) NSString *networkInterface;
@property (copy) NSString *operation;
@property (copy) NSString *pageToken;
@property (copy) NSString *project;
@property (copy) NSString *snapshot;
// Remapped to 'zoneProperty' to avoid NSObject's 'zone'.
@property (copy) NSString *zoneProperty;

#pragma mark -
#pragma mark "disks" methods
// These create a GTLQueryCompute object.

// Method: compute.disks.delete
// Deletes the specified persistent disk resource.
//  Required:
//   project: Name of the project scoping this request.
//   disk: Name of the persistent disk resource to delete.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForDisksDeleteWithProject:(NSString *)project
                                disk:(NSString *)disk;

// Method: compute.disks.get
// Returns the specified persistent disk resource.
//  Required:
//   project: Name of the project scoping this request.
//   disk: Name of the persistent disk resource to return.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeDisk.
+ (id)queryForDisksGetWithProject:(NSString *)project
                             disk:(NSString *)disk;

// Method: compute.disks.insert
// Creates a persistent disk resource in the specified project using the data
// included in the request.
//  Required:
//   project: Name of the project scoping this request.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForDisksInsertWithObject:(GTLComputeDisk *)object
                            project:(NSString *)project;

// Method: compute.disks.list
// Retrieves the list of persistent disk resources contained within the
// specified project.
//  Required:
//   project: Name of the project scoping this request.
//  Optional:
//   filter: Optional. Filter expression for filtering listed resources.
//   maxResults: Optional. Maximum count of results to be returned. Maximum and
//     default value is 100.
//   pageToken: Optional. Tag returned by a previous list request truncated by
//     maxResults. Used to continue a previous list request.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeDiskList.
+ (id)queryForDisksListWithProject:(NSString *)project;

#pragma mark -
#pragma mark "firewalls" methods
// These create a GTLQueryCompute object.

// Method: compute.firewalls.delete
// Deletes the specified firewall resource.
//  Required:
//   project: Name of the project scoping this request.
//   firewall: Name of the firewall resource to delete.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForFirewallsDeleteWithProject:(NSString *)project
                                firewall:(NSString *)firewall;

// Method: compute.firewalls.get
// Returns the specified firewall resource.
//  Required:
//   project: Name of the project scoping this request.
//   firewall: Name of the firewall resource to return.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeFirewall.
+ (id)queryForFirewallsGetWithProject:(NSString *)project
                             firewall:(NSString *)firewall;

// Method: compute.firewalls.insert
// Creates a firewall resource in the specified project using the data included
// in the request.
//  Required:
//   project: Name of the project scoping this request.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForFirewallsInsertWithObject:(GTLComputeFirewall *)object
                                project:(NSString *)project;

// Method: compute.firewalls.list
// Retrieves the list of firewall resources available to the specified project.
//  Required:
//   project: Name of the project scoping this request.
//  Optional:
//   filter: Optional. Filter expression for filtering listed resources.
//   maxResults: Optional. Maximum count of results to be returned. Maximum and
//     default value is 100.
//   pageToken: Optional. Tag returned by a previous list request truncated by
//     maxResults. Used to continue a previous list request.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeFirewallList.
+ (id)queryForFirewallsListWithProject:(NSString *)project;

// Method: compute.firewalls.patch
// Updates the specified firewall resource with the data included in the
// request. This method supports patch semantics.
//  Required:
//   project: Name of the project scoping this request.
//   firewall: Name of the firewall resource to update.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForFirewallsPatchWithObject:(GTLComputeFirewall *)object
                               project:(NSString *)project
                              firewall:(NSString *)firewall;

// Method: compute.firewalls.update
// Updates the specified firewall resource with the data included in the
// request.
//  Required:
//   project: Name of the project scoping this request.
//   firewall: Name of the firewall resource to update.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForFirewallsUpdateWithObject:(GTLComputeFirewall *)object
                                project:(NSString *)project
                               firewall:(NSString *)firewall;

#pragma mark -
#pragma mark "images" methods
// These create a GTLQueryCompute object.

// Method: compute.images.delete
// Deletes the specified image resource.
//  Required:
//   project: Name of the project scoping this request.
//   image: Name of the image resource to delete.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForImagesDeleteWithProject:(NSString *)project
                                image:(NSString *)image;

// Method: compute.images.get
// Returns the specified image resource.
//  Required:
//   project: Name of the project scoping this request.
//   image: Name of the image resource to return.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeImage.
+ (id)queryForImagesGetWithProject:(NSString *)project
                             image:(NSString *)image;

// Method: compute.images.insert
// Creates an image resource in the specified project using the data included in
// the request.
//  Required:
//   project: Name of the project scoping this request.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
//   kGTLAuthScopeComputeDevstorageReadOnly
// Fetches a GTLComputeOperation.
+ (id)queryForImagesInsertWithObject:(GTLComputeImage *)object
                             project:(NSString *)project;

// Method: compute.images.list
// Retrieves the list of image resources available to the specified project.
//  Required:
//   project: Name of the project scoping this request.
//  Optional:
//   filter: Optional. Filter expression for filtering listed resources.
//   maxResults: Optional. Maximum count of results to be returned. Maximum and
//     default value is 100.
//   pageToken: Optional. Tag returned by a previous list request truncated by
//     maxResults. Used to continue a previous list request.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeImageList.
+ (id)queryForImagesListWithProject:(NSString *)project;

#pragma mark -
#pragma mark "instances" methods
// These create a GTLQueryCompute object.

// Method: compute.instances.addAccessConfig
// Adds an access config to an instance's network interface.
//  Required:
//   project: Project name.
//   instance: Instance name.
//   networkInterface: Network interface name.
//  Optional:
//   accessConfig: For this method, "accessConfig" should be of type
//     GTLComputeAccessConfig.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForInstancesAddAccessConfigWithProject:(NSString *)project
                                         instance:(NSString *)instance
                                 networkInterface:(NSString *)networkInterface;

// Method: compute.instances.delete
// Deletes the specified instance resource.
//  Required:
//   project: Name of the project scoping this request.
//   instance: Name of the instance resource to delete.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForInstancesDeleteWithProject:(NSString *)project
                                instance:(NSString *)instance;

// Method: compute.instances.deleteAccessConfig
// Deletes an access config from an instance's network interface.
//  Required:
//   project: Project name.
//   instance: Instance name.
//   accessConfig: Access config name.
//   networkInterface: Network interface name.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForInstancesDeleteAccessConfigWithProject:(NSString *)project
                                            instance:(NSString *)instance
                                        accessConfig:(NSString *)accessConfig
                                    networkInterface:(NSString *)networkInterface;

// Method: compute.instances.get
// Returns the specified instance resource.
//  Required:
//   project: Name of the project scoping this request.
//   instance: Name of the instance resource to return.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeInstance.
+ (id)queryForInstancesGetWithProject:(NSString *)project
                             instance:(NSString *)instance;

// Method: compute.instances.insert
// Creates an instance resource in the specified project using the data included
// in the request.
//  Required:
//   project: Name of the project scoping this request.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForInstancesInsertWithObject:(GTLComputeInstance *)object
                                project:(NSString *)project;

// Method: compute.instances.list
// Retrieves the list of instance resources contained within the specified
// project.
//  Required:
//   project: Name of the project scoping this request.
//  Optional:
//   filter: Optional. Filter expression for filtering listed resources.
//   maxResults: Optional. Maximum count of results to be returned. Maximum and
//     default value is 100.
//   pageToken: Optional. Tag returned by a previous list request truncated by
//     maxResults. Used to continue a previous list request.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeInstanceList.
+ (id)queryForInstancesListWithProject:(NSString *)project;

#pragma mark -
#pragma mark "kernels" methods
// These create a GTLQueryCompute object.

// Method: compute.kernels.get
// Returns the specified kernel resource.
//  Required:
//   project: Name of the project scoping this request.
//   kernel: Name of the kernel resource to return.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeKernel.
+ (id)queryForKernelsGetWithProject:(NSString *)project
                             kernel:(NSString *)kernel;

// Method: compute.kernels.list
// Retrieves the list of kernel resources available to the specified project.
//  Required:
//   project: Name of the project scoping this request.
//  Optional:
//   filter: Optional. Filter expression for filtering listed resources.
//   maxResults: Optional. Maximum count of results to be returned. Maximum and
//     default value is 100.
//   pageToken: Optional. Tag returned by a previous list request truncated by
//     maxResults. Used to continue a previous list request.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeKernelList.
+ (id)queryForKernelsListWithProject:(NSString *)project;

#pragma mark -
#pragma mark "machineTypes" methods
// These create a GTLQueryCompute object.

// Method: compute.machineTypes.get
// Returns the specified machine type resource.
//  Required:
//   project: Name of the project scoping this request.
//   machineType: Name of the machine type resource to return.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeMachineType.
+ (id)queryForMachineTypesGetWithProject:(NSString *)project
                             machineType:(NSString *)machineType;

// Method: compute.machineTypes.list
// Retrieves the list of machine type resources available to the specified
// project.
//  Required:
//   project: Name of the project scoping this request.
//  Optional:
//   filter: Optional. Filter expression for filtering listed resources.
//   maxResults: Optional. Maximum count of results to be returned. Maximum and
//     default value is 100.
//   pageToken: Optional. Tag returned by a previous list request truncated by
//     maxResults. Used to continue a previous list request.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeMachineTypeList.
+ (id)queryForMachineTypesListWithProject:(NSString *)project;

#pragma mark -
#pragma mark "networks" methods
// These create a GTLQueryCompute object.

// Method: compute.networks.delete
// Deletes the specified network resource.
//  Required:
//   project: Name of the project scoping this request.
//   network: Name of the network resource to delete.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForNetworksDeleteWithProject:(NSString *)project
                                network:(NSString *)network;

// Method: compute.networks.get
// Returns the specified network resource.
//  Required:
//   project: Name of the project scoping this request.
//   network: Name of the network resource to return.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeNetwork.
+ (id)queryForNetworksGetWithProject:(NSString *)project
                             network:(NSString *)network;

// Method: compute.networks.insert
// Creates a network resource in the specified project using the data included
// in the request.
//  Required:
//   project: Name of the project scoping this request.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForNetworksInsertWithObject:(GTLComputeNetwork *)object
                               project:(NSString *)project;

// Method: compute.networks.list
// Retrieves the list of network resources available to the specified project.
//  Required:
//   project: Name of the project scoping this request.
//  Optional:
//   filter: Optional. Filter expression for filtering listed resources.
//   maxResults: Optional. Maximum count of results to be returned. Maximum and
//     default value is 100.
//   pageToken: Optional. Tag returned by a previous list request truncated by
//     maxResults. Used to continue a previous list request.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeNetworkList.
+ (id)queryForNetworksListWithProject:(NSString *)project;

#pragma mark -
#pragma mark "operations" methods
// These create a GTLQueryCompute object.

// Method: compute.operations.delete
// Deletes the specified operation resource.
//  Required:
//   project: Name of the project scoping this request.
//   operation: Name of the operation resource to delete.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
+ (id)queryForOperationsDeleteWithProject:(NSString *)project
                                operation:(NSString *)operation;

// Method: compute.operations.get
// Retrieves the specified operation resource.
//  Required:
//   project: Name of the project scoping this request.
//   operation: Name of the operation resource to return.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeOperation.
+ (id)queryForOperationsGetWithProject:(NSString *)project
                             operation:(NSString *)operation;

// Method: compute.operations.list
// Retrieves the list of operation resources contained within the specified
// project.
//  Required:
//   project: Name of the project scoping this request.
//  Optional:
//   filter: Optional. Filter expression for filtering listed resources.
//   maxResults: Optional. Maximum count of results to be returned. Maximum and
//     default value is 100.
//   pageToken: Optional. Tag returned by a previous list request truncated by
//     maxResults. Used to continue a previous list request.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeOperationList.
+ (id)queryForOperationsListWithProject:(NSString *)project;

#pragma mark -
#pragma mark "projects" methods
// These create a GTLQueryCompute object.

// Method: compute.projects.get
// Returns the specified project resource.
//  Required:
//   project: Name of the project resource to retrieve.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeProject.
+ (id)queryForProjectsGetWithProject:(NSString *)project;

// Method: compute.projects.setCommonInstanceMetadata
// Sets metadata common to all instances within the specified project using the
// data included in the request.
//  Required:
//   project: Name of the project scoping this request.
//  Optional:
//   metadata: GTLComputeMetadata
//  Authorization scope(s):
//   kGTLAuthScopeCompute
+ (id)queryForProjectsSetCommonInstanceMetadataWithProject:(NSString *)project;

#pragma mark -
#pragma mark "snapshots" methods
// These create a GTLQueryCompute object.

// Method: compute.snapshots.delete
// Deletes the specified persistent disk snapshot resource.
//  Required:
//   project: Name of the project scoping this request.
//   snapshot: Name of the persistent disk snapshot resource to delete.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForSnapshotsDeleteWithProject:(NSString *)project
                                snapshot:(NSString *)snapshot;

// Method: compute.snapshots.get
// Returns the specified persistent disk snapshot resource.
//  Required:
//   project: Name of the project scoping this request.
//   snapshot: Name of the persistent disk snapshot resource to return.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeSnapshot.
+ (id)queryForSnapshotsGetWithProject:(NSString *)project
                             snapshot:(NSString *)snapshot;

// Method: compute.snapshots.insert
// Creates a persistent disk snapshot resource in the specified project using
// the data included in the request.
//  Required:
//   project: Name of the project scoping this request.
//  Authorization scope(s):
//   kGTLAuthScopeCompute
// Fetches a GTLComputeOperation.
+ (id)queryForSnapshotsInsertWithObject:(GTLComputeSnapshot *)object
                                project:(NSString *)project;

// Method: compute.snapshots.list
// Retrieves the list of persistent disk snapshot resources contained within the
// specified project.
//  Required:
//   project: Name of the project scoping this request.
//  Optional:
//   filter: Optional. Filter expression for filtering listed resources.
//   maxResults: Optional. Maximum count of results to be returned. Maximum and
//     default value is 100.
//   pageToken: Optional. Tag returned by a previous list request truncated by
//     maxResults. Used to continue a previous list request.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeSnapshotList.
+ (id)queryForSnapshotsListWithProject:(NSString *)project;

#pragma mark -
#pragma mark "zones" methods
// These create a GTLQueryCompute object.

// Method: compute.zones.get
// Returns the specified zone resource.
//  Required:
//   project: Name of the project scoping this request.
//   zoneProperty: Name of the zone resource to return.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeZone.
+ (id)queryForZonesGetWithProject:(NSString *)project
                     zoneProperty:(NSString *)zoneProperty;

// Method: compute.zones.list
// Retrieves the list of zone resources available to the specified project.
//  Required:
//   project: Name of the project scoping this request.
//  Optional:
//   filter: Optional. Filter expression for filtering listed resources.
//   maxResults: Optional. Maximum count of results to be returned. Maximum and
//     default value is 100.
//   pageToken: Optional. Tag returned by a previous list request truncated by
//     maxResults. Used to continue a previous list request.
//  Authorization scope(s):
//   kGTLAuthScopeComputeReadonly
// Fetches a GTLComputeZoneList.
+ (id)queryForZonesListWithProject:(NSString *)project;

@end

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
//  GTLQueryCompute.m
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Compute Engine API (compute/v1beta14)
// Description:
//   API for the Google Compute Engine service.
// Documentation:
//   https://developers.google.com/compute/docs/reference/v1beta14
// Classes:
//   GTLQueryCompute (48 custom class methods, 23 custom properties)

#import "GTLQueryCompute.h"

#import "GTLComputeAccessConfig.h"
#import "GTLComputeAttachedDisk.h"
#import "GTLComputeDeprecationStatus.h"
#import "GTLComputeDisk.h"
#import "GTLComputeDiskList.h"
#import "GTLComputeFirewall.h"
#import "GTLComputeFirewallList.h"
#import "GTLComputeImage.h"
#import "GTLComputeImageList.h"
#import "GTLComputeInstance.h"
#import "GTLComputeInstanceList.h"
#import "GTLComputeKernel.h"
#import "GTLComputeKernelList.h"
#import "GTLComputeMachineType.h"
#import "GTLComputeMachineTypeList.h"
#import "GTLComputeMetadata.h"
#import "GTLComputeNetwork.h"
#import "GTLComputeNetworkList.h"
#import "GTLComputeOperation.h"
#import "GTLComputeOperationList.h"
#import "GTLComputeProject.h"
#import "GTLComputeSerialPortOutput.h"
#import "GTLComputeSnapshot.h"
#import "GTLComputeSnapshotList.h"
#import "GTLComputeTags.h"
#import "GTLComputeZone.h"
#import "GTLComputeZoneList.h"

@implementation GTLQueryCompute

@dynamic accessConfig, deprecated, deviceName, disk, fields, filter, firewall,
         firewallResource, image, instance, kernel, machineType, maxResults,
         metadata, network, networkInterface, operation, pageToken, project,
         snapshot, sourceImage, tags, zoneProperty;

+ (NSDictionary *)parameterNameMap {
  NSDictionary *map =
    [NSDictionary dictionaryWithObjectsAndKeys:
      @"access_config", @"accessConfig",
      @"firewall_resource", @"firewallResource",
      @"network_interface", @"networkInterface",
      @"zone", @"zoneProperty",
      nil];
  return map;
}

#pragma mark -
#pragma mark "disks" methods
// These create a GTLQueryCompute object.

+ (id)queryForDisksDeleteWithProject:(NSString *)project
                        zoneProperty:(NSString *)zoneProperty
                                disk:(NSString *)disk {
  NSString *methodName = @"compute.disks.delete";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.disk = disk;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForDisksGetWithProject:(NSString *)project
                     zoneProperty:(NSString *)zoneProperty
                             disk:(NSString *)disk {
  NSString *methodName = @"compute.disks.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.disk = disk;
  query.expectedObjectClass = [GTLComputeDisk class];
  return query;
}

+ (id)queryForDisksInsertWithProject:(NSString *)project
                        zoneProperty:(NSString *)zoneProperty {
  NSString *methodName = @"compute.disks.insert";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForDisksListWithProject:(NSString *)project
                      zoneProperty:(NSString *)zoneProperty {
  NSString *methodName = @"compute.disks.list";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.expectedObjectClass = [GTLComputeDiskList class];
  return query;
}

#pragma mark -
#pragma mark "firewalls" methods
// These create a GTLQueryCompute object.

+ (id)queryForFirewallsDeleteWithProject:(NSString *)project
                                firewall:(NSString *)firewall {
  NSString *methodName = @"compute.firewalls.delete";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.firewall = firewall;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForFirewallsGetWithProject:(NSString *)project
                             firewall:(NSString *)firewall {
  NSString *methodName = @"compute.firewalls.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.firewall = firewall;
  query.expectedObjectClass = [GTLComputeFirewall class];
  return query;
}

+ (id)queryForFirewallsInsertWithProject:(NSString *)project {
  NSString *methodName = @"compute.firewalls.insert";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForFirewallsListWithProject:(NSString *)project {
  NSString *methodName = @"compute.firewalls.list";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeFirewallList class];
  return query;
}

+ (id)queryForFirewallsPatchWithProject:(NSString *)project
                               firewall:(NSString *)firewall {
  NSString *methodName = @"compute.firewalls.patch";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.firewall = firewall;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForFirewallsUpdateWithProject:(NSString *)project
                                firewall:(NSString *)firewall {
  NSString *methodName = @"compute.firewalls.update";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.firewall = firewall;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

#pragma mark -
#pragma mark "globalOperations" methods
// These create a GTLQueryCompute object.

+ (id)queryForGlobalOperationsDeleteWithProject:(NSString *)project
                                      operation:(NSString *)operation {
  NSString *methodName = @"compute.globalOperations.delete";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.operation = operation;
  return query;
}

+ (id)queryForGlobalOperationsGetWithProject:(NSString *)project
                                   operation:(NSString *)operation {
  NSString *methodName = @"compute.globalOperations.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.operation = operation;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForGlobalOperationsListWithProject:(NSString *)project {
  NSString *methodName = @"compute.globalOperations.list";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeOperationList class];
  return query;
}

#pragma mark -
#pragma mark "images" methods
// These create a GTLQueryCompute object.

+ (id)queryForImagesDeleteWithProject:(NSString *)project
                                image:(NSString *)image {
  NSString *methodName = @"compute.images.delete";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.image = image;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForImagesDeprecateWithProject:(NSString *)project
                                   image:(NSString *)image {
  NSString *methodName = @"compute.images.deprecate";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.image = image;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForImagesGetWithProject:(NSString *)project
                             image:(NSString *)image {
  NSString *methodName = @"compute.images.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.image = image;
  query.expectedObjectClass = [GTLComputeImage class];
  return query;
}

+ (id)queryForImagesInsertWithProject:(NSString *)project {
  NSString *methodName = @"compute.images.insert";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForImagesListWithProject:(NSString *)project {
  NSString *methodName = @"compute.images.list";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeImageList class];
  return query;
}

#pragma mark -
#pragma mark "instances" methods
// These create a GTLQueryCompute object.

+ (id)queryForInstancesAddAccessConfigWithProject:(NSString *)project
                                     zoneProperty:(NSString *)zoneProperty
                                         instance:(NSString *)instance
                                 networkInterface:(NSString *)networkInterface {
  NSString *methodName = @"compute.instances.addAccessConfig";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.instance = instance;
  query.networkInterface = networkInterface;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForInstancesAttachDiskWithProject:(NSString *)project
                                zoneProperty:(NSString *)zoneProperty
                                    instance:(NSString *)instance {
  NSString *methodName = @"compute.instances.attachDisk";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.instance = instance;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForInstancesDeleteWithProject:(NSString *)project
                            zoneProperty:(NSString *)zoneProperty
                                instance:(NSString *)instance {
  NSString *methodName = @"compute.instances.delete";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.instance = instance;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForInstancesDeleteAccessConfigWithProject:(NSString *)project
                                        zoneProperty:(NSString *)zoneProperty
                                            instance:(NSString *)instance
                                        accessConfig:(NSString *)accessConfig
                                    networkInterface:(NSString *)networkInterface {
  NSString *methodName = @"compute.instances.deleteAccessConfig";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.instance = instance;
  query.accessConfig = accessConfig;
  query.networkInterface = networkInterface;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForInstancesDetachDiskWithProject:(NSString *)project
                                zoneProperty:(NSString *)zoneProperty
                                    instance:(NSString *)instance
                                  deviceName:(NSString *)deviceName {
  NSString *methodName = @"compute.instances.detachDisk";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.instance = instance;
  query.deviceName = deviceName;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForInstancesGetWithProject:(NSString *)project
                         zoneProperty:(NSString *)zoneProperty
                             instance:(NSString *)instance {
  NSString *methodName = @"compute.instances.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.instance = instance;
  query.expectedObjectClass = [GTLComputeInstance class];
  return query;
}

+ (id)queryForInstancesGetSerialPortOutputWithProject:(NSString *)project
                                         zoneProperty:(NSString *)zoneProperty
                                             instance:(NSString *)instance {
  NSString *methodName = @"compute.instances.getSerialPortOutput";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.instance = instance;
  query.expectedObjectClass = [GTLComputeSerialPortOutput class];
  return query;
}

+ (id)queryForInstancesInsertWithProject:(NSString *)project
                            zoneProperty:(NSString *)zoneProperty {
  NSString *methodName = @"compute.instances.insert";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForInstancesListWithProject:(NSString *)project
                          zoneProperty:(NSString *)zoneProperty {
  NSString *methodName = @"compute.instances.list";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.expectedObjectClass = [GTLComputeInstanceList class];
  return query;
}

+ (id)queryForInstancesSetMetadataWithProject:(NSString *)project
                                 zoneProperty:(NSString *)zoneProperty
                                     instance:(NSString *)instance {
  NSString *methodName = @"compute.instances.setMetadata";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.instance = instance;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForInstancesSetTagsWithProject:(NSString *)project
                             zoneProperty:(NSString *)zoneProperty
                                 instance:(NSString *)instance {
  NSString *methodName = @"compute.instances.setTags";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.instance = instance;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

#pragma mark -
#pragma mark "kernels" methods
// These create a GTLQueryCompute object.

+ (id)queryForKernelsGetWithProject:(NSString *)project
                             kernel:(NSString *)kernel {
  NSString *methodName = @"compute.kernels.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.kernel = kernel;
  query.expectedObjectClass = [GTLComputeKernel class];
  return query;
}

+ (id)queryForKernelsListWithProject:(NSString *)project {
  NSString *methodName = @"compute.kernels.list";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeKernelList class];
  return query;
}

#pragma mark -
#pragma mark "machineTypes" methods
// These create a GTLQueryCompute object.

+ (id)queryForMachineTypesGetWithProject:(NSString *)project
                             machineType:(NSString *)machineType {
  NSString *methodName = @"compute.machineTypes.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.machineType = machineType;
  query.expectedObjectClass = [GTLComputeMachineType class];
  return query;
}

+ (id)queryForMachineTypesListWithProject:(NSString *)project {
  NSString *methodName = @"compute.machineTypes.list";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeMachineTypeList class];
  return query;
}

#pragma mark -
#pragma mark "networks" methods
// These create a GTLQueryCompute object.

+ (id)queryForNetworksDeleteWithProject:(NSString *)project
                                network:(NSString *)network {
  NSString *methodName = @"compute.networks.delete";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.network = network;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForNetworksGetWithProject:(NSString *)project
                             network:(NSString *)network {
  NSString *methodName = @"compute.networks.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.network = network;
  query.expectedObjectClass = [GTLComputeNetwork class];
  return query;
}

+ (id)queryForNetworksInsertWithProject:(NSString *)project {
  NSString *methodName = @"compute.networks.insert";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForNetworksListWithProject:(NSString *)project {
  NSString *methodName = @"compute.networks.list";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeNetworkList class];
  return query;
}

#pragma mark -
#pragma mark "projects" methods
// These create a GTLQueryCompute object.

+ (id)queryForProjectsGetWithProject:(NSString *)project {
  NSString *methodName = @"compute.projects.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeProject class];
  return query;
}

+ (id)queryForProjectsSetCommonInstanceMetadataWithProject:(NSString *)project {
  NSString *methodName = @"compute.projects.setCommonInstanceMetadata";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

#pragma mark -
#pragma mark "snapshots" methods
// These create a GTLQueryCompute object.

+ (id)queryForSnapshotsDeleteWithProject:(NSString *)project
                                snapshot:(NSString *)snapshot {
  NSString *methodName = @"compute.snapshots.delete";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.snapshot = snapshot;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForSnapshotsGetWithProject:(NSString *)project
                             snapshot:(NSString *)snapshot {
  NSString *methodName = @"compute.snapshots.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.snapshot = snapshot;
  query.expectedObjectClass = [GTLComputeSnapshot class];
  return query;
}

+ (id)queryForSnapshotsInsertWithProject:(NSString *)project {
  NSString *methodName = @"compute.snapshots.insert";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForSnapshotsListWithProject:(NSString *)project {
  NSString *methodName = @"compute.snapshots.list";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeSnapshotList class];
  return query;
}

#pragma mark -
#pragma mark "zoneOperations" methods
// These create a GTLQueryCompute object.

+ (id)queryForZoneOperationsDeleteWithProject:(NSString *)project
                                 zoneProperty:(NSString *)zoneProperty
                                    operation:(NSString *)operation {
  NSString *methodName = @"compute.zoneOperations.delete";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.operation = operation;
  return query;
}

+ (id)queryForZoneOperationsGetWithProject:(NSString *)project
                              zoneProperty:(NSString *)zoneProperty
                                 operation:(NSString *)operation {
  NSString *methodName = @"compute.zoneOperations.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.operation = operation;
  query.expectedObjectClass = [GTLComputeOperation class];
  return query;
}

+ (id)queryForZoneOperationsListWithProject:(NSString *)project
                               zoneProperty:(NSString *)zoneProperty {
  NSString *methodName = @"compute.zoneOperations.list";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.expectedObjectClass = [GTLComputeOperationList class];
  return query;
}

#pragma mark -
#pragma mark "zones" methods
// These create a GTLQueryCompute object.

+ (id)queryForZonesGetWithProject:(NSString *)project
                     zoneProperty:(NSString *)zoneProperty {
  NSString *methodName = @"compute.zones.get";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.zoneProperty = zoneProperty;
  query.expectedObjectClass = [GTLComputeZone class];
  return query;
}

+ (id)queryForZonesListWithProject:(NSString *)project {
  NSString *methodName = @"compute.zones.list";
  GTLQueryCompute *query = [self queryWithMethodName:methodName];
  query.project = project;
  query.expectedObjectClass = [GTLComputeZoneList class];
  return query;
}

@end

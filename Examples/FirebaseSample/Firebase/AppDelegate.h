//
//  AppDelegate.h
//  Firebase
//
//  Created by Dmitriy Groschovskiy on 16/09/2016.
//  Copyright © 2016 Google, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end


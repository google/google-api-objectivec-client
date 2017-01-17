//
//  ViewController.m
//  Firebase
//
//  Created by Dmitriy Groschovskiy on 16/09/2016.
//  Copyright © 2016 Google, Inc. All rights reserved.
//

#import "ViewController.h"
#import <GoogleSignIn/GoogleSignIn.h>

@import Firebase;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [[FIRAuth auth] addAuthStateDidChangeListener:^(FIRAuth *_Nonnull auth, FIRUser *_Nullable user) {
        if (user != nil) {
            NSLog(@"User is signed in");
        } else {
            NSLog(@"No user is signed in");
        }
    }];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (IBAction)authWithFirebaseDBAccount:(id)sender {
    [[FIRAuth auth] signInWithEmail:_username.text password:_password.text completion:^(FIRUser *user, NSError *error) {
        if (error != nil) {
            NSLog(@"You successful auth in Firebase");
        } else {
            NSLog(@"%@", error.localizedDescription);
        }
    }];
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString *, id> *)options {
    return [[GIDSignIn sharedInstance] handleURL:url sourceApplication:options[UIApplicationOpenURLOptionsSourceApplicationKey] annotation:options[UIApplicationOpenURLOptionsAnnotationKey]];
}

- (void)signIn:(GIDSignIn *)signIn didSignInForUser:(GIDGoogleUser *)user withError:(NSError *)error {
    if (error == nil) {
        // ...
    } else {
        NSLog(@"%@", error.localizedDescription);
    }
}

- (void)signOut {
    NSError *error;
    [[FIRAuth auth] signOut:&error];
    if (!error) {
        NSLog(@"Sign-out succeeded");
    }
}

@end

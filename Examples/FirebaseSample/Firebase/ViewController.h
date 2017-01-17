//
//  ViewController.h
//  Firebase
//
//  Created by Dmitriy Groschovskiy on 16/09/2016.
//  Copyright © 2016 Google, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GoogleSignIn/GoogleSignIn.h>

@interface ViewController : UIViewController <GIDSignInUIDelegate>

@property (weak, nonatomic) IBOutlet UITextField *username;
@property (weak, nonatomic) IBOutlet UITextField *password;

@end


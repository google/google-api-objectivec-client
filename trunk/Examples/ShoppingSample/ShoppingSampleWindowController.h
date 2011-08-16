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

//
//  ShoppingSampleWindowController.h
//

#import <Cocoa/Cocoa.h>

#import "GTLShopping.h"

@interface ShoppingSampleWindowController : NSWindowController {
 @private
  // IBOutlets - main window
  NSButton *searchButton_;
  NSTextField *searchField_;

  NSPopUpButton *rankingPopup_;

  NSTableView *productsTable_;
  NSImageView *productsImageView_;
  NSProgressIndicator *productsProgressIndicator_;
  NSTextView *productsResultTextField_;
  NSButton *productsCancelButton_;

  // IBOutlets - client ID sheet
  NSButton *accessKeyButton_;
  NSTextField *accessKeyRequiredTextField_;
  NSWindow *accessKeySheet_;
  NSTextField *accessKeyField_;

  // property storage
  GTLShoppingProducts *products_;
  GTLServiceTicket *productsTicket_;
  NSError *productsFetchError_;

  NSString *currentImageURLString_;
  GTMHTTPFetcher *pendingImageFetcher_;
}

// Main UI
@property (retain, nonatomic) IBOutlet NSButton *searchButton;
@property (retain, nonatomic) IBOutlet NSTextField *searchField;
@property (retain, nonatomic) IBOutlet NSPopUpButton *rankingPopup;

@property (retain, nonatomic) IBOutlet NSTableView *productsTable;
@property (retain, nonatomic) IBOutlet NSImageView *productsImageView;
@property (retain, nonatomic) IBOutlet NSProgressIndicator *productsProgressIndicator;
@property (retain, nonatomic) IBOutlet NSTextView *productsResultTextField;
@property (retain, nonatomic) IBOutlet NSButton *productsCancelButton;

// Client ID sheet
@property (retain, nonatomic) IBOutlet NSButton *accessKeyButton;
@property (retain, nonatomic) IBOutlet NSTextField *accessKeyRequiredTextField;
@property (retain, nonatomic) IBOutlet NSWindow *accessKeySheet;
@property (retain, nonatomic) IBOutlet NSTextField *accessKeyField;

+ (ShoppingSampleWindowController *)sharedWindowController;

// Main UI
- (IBAction)searchProductsClicked:(id)sender;
- (IBAction)rankByClicked:(id)sender;
- (IBAction)cancelProductsFetchClicked:(id)sender;

// Access Key
- (IBAction)APIKeyClicked:(id)sender;
- (IBAction)APIKeyDoneClicked:(id)sender;
- (IBAction)APIConsoleClicked:(id)sender;

- (IBAction)loggingCheckboxClicked:(id)sender;
@end

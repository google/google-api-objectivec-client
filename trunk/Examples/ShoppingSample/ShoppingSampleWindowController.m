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
//  ShoppingSampleWindowController.m
//

#import "ShoppingSampleWindowController.h"

#import "GTL/GTMOAuth2WindowController.h"
#import "GTL/GTMHTTPFetcherLogging.h"
#import "GTL/GTLUtilities.h"

@interface ShoppingSampleWindowController ()

// Product table properties
@property (retain, nonatomic) GTLShoppingProducts *products;
@property (retain, nonatomic) GTLServiceTicket *productsTicket;
@property (retain, nonatomic) NSError *productsFetchError;

@property (retain, nonatomic) NSString *currentImageURLString;
@property (retain, nonatomic) GTMHTTPFetcher *pendingImageFetcher;

// Other properties
@property (retain, nonatomic, readonly) GTLServiceShopping *shoppingService;

- (void)updateUI;
- (void)updateSelectedProductImage;
- (GTLShoppingProduct *)selectedProduct;
- (void)searchProducts;
@end


@implementation ShoppingSampleWindowController

@synthesize searchButton = searchButton_,
  searchField = searchField_,
  rankingPopup = rankingPopup_,
  productsTable = productsTable_,
  productsImageView = productsImageView_,
  productsProgressIndicator = productsProgressIndicator_,
  productsResultTextField = productsResultTextField_,
  productsCancelButton = productsCancelButton_,
  accessKeyButton = accessKeyButton_,
  accessKeyRequiredTextField = accessKeyRequiredTextField_,
  accessKeySheet = accessKeySheet_,
  accessKeyField = accessKeyField_;

@synthesize products = products_,
  productsTicket = productsTicket_,
  productsFetchError = productsFetchError_,
  currentImageURLString = currentImageURLString_,
  pendingImageFetcher = pendingImageFetcher_;

+ (ShoppingSampleWindowController *)sharedWindowController {
  static ShoppingSampleWindowController* gWindowController = nil;
  if (!gWindowController) {
    gWindowController = [[ShoppingSampleWindowController alloc] init];
  }
  return gWindowController;
}


- (id)init {
  return [self initWithWindowNibName:@"ShoppingSampleWindow"];
}

- (void)awakeFromNib {
  // Set the result text fields to have a distinctive color and mono-spaced font
  [self.productsResultTextField setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [self.productsResultTextField setFont:resultTextFont];

  NSString *accessKey = [self.accessKeyField stringValue];
  self.shoppingService.APIKey = accessKey;

  [self updateUI];
}

- (void)dealloc {
  // IBOutlets
  self.searchButton = nil;
  self.searchField = nil;
  self.rankingPopup = nil;
  self.productsTable = nil;
  self.productsImageView = nil;
  self.productsProgressIndicator = nil;
  self.productsResultTextField = nil;
  self.productsCancelButton = nil;
  self.accessKeyButton = nil;
  self.accessKeyRequiredTextField = nil;
  self.accessKeySheet = nil;
  self.accessKeyField = nil;

  self.products = nil;
  self.productsTicket = nil;
  self.productsFetchError = nil;
  self.currentImageURLString = nil;

  [self.pendingImageFetcher stopFetching];
  self.pendingImageFetcher = nil;

  [super dealloc];
}

#pragma mark -

- (void)updateUI {
  // Products table
  [self.productsTable reloadData];

  if (self.productsTicket != nil) {
    [self.productsProgressIndicator startAnimation:self];
    [self.productsCancelButton setEnabled:YES];
  } else {
    [self.productsProgressIndicator stopAnimation:self];
    [self.productsCancelButton setEnabled:NO];
  }

  // Display the selected product item, or the fetch error
  GTLShoppingProduct *selectedItem = [self selectedProduct];
  NSString *resultStr = @"";
  NSError *fetchError = self.productsFetchError;
  if (fetchError != nil) {
    resultStr = [fetchError description];
  } else {
    if (selectedItem) {
      resultStr = [selectedItem description];
    }
  }
  [self.productsResultTextField setString:resultStr];

  [self updateSelectedProductImage];

  // Enable buttons
  BOOL hasSearchTerm = ([[self.searchField stringValue] length] > 0);
  [self.searchButton setEnabled:hasSearchTerm];
  [self.rankingPopup setEnabled:hasSearchTerm];

  // Show or hide the text indicating that the developer key is needed
  BOOL hasAccessKey = [[self.accessKeyField stringValue] length] > 0;
  [self.accessKeyRequiredTextField setHidden:hasAccessKey];
}

- (void)updateSelectedProductImage {
  // Find the thumbnail URL for the selected product
  GTLShoppingProduct *selectedItem = [self selectedProduct];
  NSArray *images = selectedItem.product.images;
  if ([images count] > 0) {
    GTLShoppingModelProductImagesItem *imageItem = [images objectAtIndex:0];
    NSArray *thumbnails = imageItem.thumbnails;
    if ([thumbnails count] > 0) {
      GTLShoppingModelProductImagesItemThumbnailsItem *thumbnail = [thumbnails objectAtIndex:0];
      NSString *thumbnailLink = thumbnail.link;

      // Compare the URL to the one for the image currently displayed
      if (!GTL_AreEqualOrBothNil(self.currentImageURLString, thumbnailLink)) {
        // The URLs are different; remove the old image and fetch the new image
        self.productsImageView.image = nil;
        self.currentImageURLString = thumbnailLink;

        [self.pendingImageFetcher stopFetching];

        GTMHTTPFetcherService *fetcherService = self.shoppingService.fetcherService;
        GTMHTTPFetcher *fetcher = [fetcherService fetcherWithURLString:thumbnailLink];
        self.pendingImageFetcher = fetcher;

        [fetcher beginFetchWithCompletionHandler:^(NSData *data, NSError *error) {
          // Fetcher callback
          if (error == nil) {
            // Display the fetched image
            NSImage *image = [[[NSImage alloc] initWithData:data] autorelease];
            self.productsImageView.image = image;
          } else {
            NSLog(@"error %@ fetching product image %@",
                  error, fetcher.mutableRequest);
          }
          self.pendingImageFetcher = nil;
        }];
      }
    }
  }
}


#pragma mark IBActions

- (IBAction)searchProductsClicked:(id)sender {
  [self searchProducts];
}

- (IBAction)rankByClicked:(id)sender {
  [self searchProducts];
}

- (IBAction)cancelProductsFetchClicked:(id)sender {
  [self.productsTicket cancelTicket];
  self.productsTicket = nil;

  [self updateUI];
}

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://code.google.com/apis/console"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMHTTPFetcher setLoggingEnabled:[sender state]];
}

#pragma mark -

// Get a service object with the current authorization
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information (such as cookies and cached fetch results.)

- (GTLServiceShopping *)shoppingService {

  static GTLServiceShopping* service = nil;
  if (!service) {
    service = [[GTLServiceShopping alloc] init];

    // Have the service object set tickets to retry temporary error conditions
    // automatically
    service.retryEnabled = YES;
  }
  return service;
}

- (GTLShoppingProduct *)selectedProduct {
  int rowIndex = [self.productsTable selectedRow];
  if (rowIndex > -1) {
    GTLShoppingProduct *item = [self.products itemAtIndex:rowIndex];
    return item;
  }
  return nil;
}

#pragma mark Fetch the products list

- (void)searchProducts {
  self.products = nil;
  self.productsFetchError = nil;

  NSString *queryTerm = [self.searchField stringValue];
  NSString *rankBy = [self.rankingPopup titleOfSelectedItem];

  GTLQueryShopping *query = [GTLQueryShopping queryForProductsListWithSource:@"public"];
  query.q = queryTerm;
  query.rankBy = rankBy;
  query.thumbnails = @"64:*";
  query.country = @"US";
  self.productsTicket = [self.shoppingService executeQuery:query
                                         completionHandler:^(GTLServiceTicket *ticket, id object, NSError *error) {
                                           // Save the returned object and error
                                           self.products = object;
                                           self.productsFetchError = error;
                                           self.productsTicket = nil;

                                           [self updateUI];
                                         }];
  [self updateUI];
}

#pragma mark Access key sheet

// Developer API key sheet
//
// Sample apps need this sheet to ask for the developer API key
//
// Your application will just hardcode the API key string
// into the source rather than ask the user for them.
//
// The key is obtained from the API Console,
// https://code.google.com/apis/console
//

- (IBAction)APIKeyClicked:(id)sender {
  // show the sheet for developers to enter client ID and client secret
  [NSApp beginSheet:self.accessKeySheet
     modalForWindow:[self window]
      modalDelegate:self
     didEndSelector:@selector(accessKeySheetDidEnd:returnCode:contextInfo:)
        contextInfo:NULL];
}

- (IBAction)APIKeyDoneClicked:(id)sender {
  [NSApp endSheet:self.accessKeySheet returnCode:NSOKButton];

  self.shoppingService.APIKey = [self.accessKeyField stringValue];
}

- (void)accessKeySheetDidEnd:(NSWindow *)sheet returnCode:(NSInteger)returnCode contextInfo:(void *)contextInfo {
  [sheet orderOut:self];

  [self updateUI];
}

#pragma mark Text field delegate methods

- (void)controlTextDidChange:(NSNotification *)note {
  [self updateUI]; // enabled/disable buttons
}

#pragma mark TableView delegate and data source methods

- (void)tableViewSelectionDidChange:(NSNotification *)notification {
  [self updateUI];
}

// Table view data source methods
- (int)numberOfRowsInTableView:(NSTableView *)tableView {
  NSArray *items = self.products.items;
  return [items count];
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(int)row {
  GTLShoppingProduct *item = [self.products itemAtIndex:row];
  NSString *resultStr = item.product.title;
  return resultStr;
}

@end

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
//  BloggerSampleWindowController.m
//

#import "BloggerSampleWindowController.h"

#import "GTL/GTLUtilities.h"
#import "GTL/GTMHTTPFetcherLogging.h"

@interface BloggerSampleWindowController ()

@property (readonly) GTLServiceBlogger *bloggerService;

@property (retain) GTLBloggerBlogList *blogList;
@property (retain) GTLServiceTicket *blogListTicket;
@property (retain) NSError *blogListFetchError;

@property (retain) GTLBloggerPostList *postList;
@property (retain) GTLServiceTicket *postListTicket;
@property (retain) NSError *postListFetchError;

@property (retain) GTLServiceTicket *editPostTicket;

- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel;

- (void)updateUI;
- (void)displayAlert:(NSString *)title format:(NSString *)format, ...;

- (void)fetchBlogList;
- (void)fetchPostListForSelectedBlog;

- (GTLBloggerBlog *)selectedBlog;

@end

// Keychain item name for saving the user's authentication information
NSString *const kKeychainItemName = @"BloggerSample: Google Blogger";

@implementation BloggerSampleWindowController

@synthesize blogList = blogList_,
            blogListTicket = blogListTicket_,
            blogListFetchError = blogListFetchError_,
            postList = postList_,
            postListTicket = postListTicket_,
            postListFetchError = postListFetchError_,
            editPostTicket = editPostTicket_;

+ (BloggerSampleWindowController *)sharedWindowController {
  static BloggerSampleWindowController* gWindowController = nil;
  if (!gWindowController) {
    gWindowController = [[BloggerSampleWindowController alloc] init];
  }
  return gWindowController;
}

- (id)init {
  return [self initWithWindowNibName:@"BloggerSampleWindow"];
}

- (void)awakeFromNib {
  // Load the OAuth token from the keychain, if it was previously saved.
  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  GTMOAuth2Authentication *auth;
  auth = [GTMOAuth2WindowController authForGoogleFromKeychainForName:kKeychainItemName
                                                            clientID:clientID
                                                        clientSecret:clientSecret];
  self.bloggerService.authorizer = auth;

  // Set the result text fields to have a distinctive color and mono-spaced font
  [blogListResultTextView_ setTextColor:[NSColor darkGrayColor]];
  [postListResultTextView_ setTextColor:[NSColor darkGrayColor]];

  NSFont *resultTextFont = [NSFont fontWithName:@"Monaco" size:9];
  [blogListResultTextView_ setFont:resultTextFont];
  [postListResultTextView_ setFont:resultTextFont];

  [self updateUI];
}

- (void)dealloc {
  [blogList_ release];
  [blogListTicket_ release];
  [blogListFetchError_ release];

  [postList_ release];
  [postListTicket_ release];
  [postListFetchError_ release];

  [editPostTicket_ release];

  [super dealloc];
}

#pragma mark -

- (NSString *)signedInUsername {
  // Get the email address of the signed-in user.
  GTMOAuth2Authentication *auth = self.bloggerService.authorizer;
  BOOL isSignedIn = auth.canAuthorize;
  if (isSignedIn) {
    return auth.userEmail;
  } else {
    return nil;
  }
}

- (BOOL)isSignedIn {
  NSString *name = [self signedInUsername];
  return (name != nil);
}

#pragma mark IBActions

- (IBAction)signInClicked:(id)sender {
  if (![self isSignedIn]) {
    // Sign in
    [self runSigninThenInvokeSelector:@selector(updateUI)];
  } else {
    // Sign out
    GTLServiceBlogger *service = self.bloggerService;

    [GTMOAuth2WindowController removeAuthFromKeychainForName:kKeychainItemName];
    service.authorizer = nil;
    [self updateUI];
  }
}

- (IBAction)getBlogListClicked:(id)sender {
  if (![self isSignedIn]) {
    [self runSigninThenInvokeSelector:@selector(fetchBlogList)];
  } else {
    [self fetchBlogList];
  }
}

- (IBAction)cancelBlogFetchClicked:(id)sender {
  [self.blogListTicket cancelTicket];
  self.blogListTicket = nil;

  [self updateUI];
}

- (IBAction)cancelPostFetchClicked:(id)sender {
  [self.postListTicket cancelTicket];
  self.postListTicket = nil;

  [self.editPostTicket cancelTicket];
  self.editPostTicket = nil;

  [self updateUI];
}

- (IBAction)addPostClicked:(id)sender {
  [self addAPost];
}

- (IBAction)updatePostClicked:(id)sender {
  [self updateSelectedPost];
}

- (IBAction)deletePostClicked:(id)sender {
  GTLBloggerPost *selectedPost = [self selectedPost];

  NSBeginAlertSheet(@"Delete", nil, @"Cancel", nil,
                    [self window], self,
                    @selector(deletePostSheetDidEnd:returnCode:contextInfo:),
                    nil, nil, @"Delete \"%@\"?", selectedPost.title);
}

- (void)deletePostSheetDidEnd:(NSWindow *)sheet
                   returnCode:(int)returnCode
                  contextInfo:(void *)contextInfo {
  if (returnCode == NSAlertDefaultReturn) {
    [self deleteSelectedPost];
  }
}

- (IBAction)deleteAllPostsClicked:(id)sender {
  GTLBloggerBlog *selectedBlog = [self selectedBlog];

  NSBeginAlertSheet(@"Delete", nil, @"Cancel", nil,
                    [self window], self,
                    @selector(deleteAllPostsSheetDidEnd:returnCode:contextInfo:),
                    nil, nil, @"Permanently delete ALL posts for blog \"%@\"?",
                    selectedBlog.name);
}

- (void)deleteAllPostsSheetDidEnd:(NSWindow *)sheet
                       returnCode:(int)returnCode
                      contextInfo:(void *)contextInfo {
  if (returnCode == NSAlertDefaultReturn) {
    [self deleteAllPosts];
  }
}

- (IBAction)APIConsoleClicked:(id)sender {
  NSURL *url = [NSURL URLWithString:@"https://code.google.com/apis/console"];
  [[NSWorkspace sharedWorkspace] openURL:url];
}

- (IBAction)loggingCheckboxClicked:(id)sender {
  [GTMHTTPFetcher setLoggingEnabled:[sender state]];
}

#pragma mark -

// Get a service object with the current username/password
//
// A "service" object handles networking tasks.  Service objects
// contain user authentication information as well as networking
// state information (such as cookies and the "last modified" date for
// fetched data.)

- (GTLServiceBlogger *)bloggerService {
  static GTLServiceBlogger *service = nil;

  if (!service) {
    service = [[GTLServiceBlogger alloc] init];

    // Have the service object set tickets to fetch consecutive pages
    // of the feed so we do not need to manually fetch them.
    service.shouldFetchNextPages = YES;

    // Have the service object set tickets to retry temporary error conditions
    // automatically.
    service.retryEnabled = YES;
  }
  return service;
}

- (GTLBloggerBlog *)selectedBlog {
  int rowIndex = [blogListTable_ selectedRow];
  if (rowIndex > -1) {
    GTLBloggerBlog *item = [self.blogList itemAtIndex:rowIndex];
    return item;
  }
  return nil;
}

- (GTLBloggerPost *)selectedPost {
  int rowIndex = [postListTable_ selectedRow];
  if (rowIndex > -1) {
    GTLBloggerPost *item = [self.postList itemAtIndex:rowIndex];
    return item;
  }
  return nil;
}

- (void)setPostEditFieldsFromSelectedPost {
  GTLBloggerPost *selectedPost = [self selectedPost];
  if (selectedPost) {
    [postTitleField_ setStringValue:selectedPost.title];
    [postBodyField_ setStringValue:selectedPost.content];
  } else {
    [postTitleField_ setStringValue:@""];
    [postBodyField_ setStringValue:@""];
  }
}

- (void)clearPostEditFields {
  [postTitleField_ setStringValue:@""];
  [postBodyField_ setStringValue:@""];
}

#pragma mark Fetch Blog List

- (void)fetchBlogList {
  self.blogList = nil;
  self.blogListFetchError = nil;

  GTLServiceBlogger *service = self.bloggerService;

  GTLQueryBlogger *query = [GTLQueryBlogger queryForBlogsListByUserWithUserId:@"self"];

  self.blogListTicket = [service executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                GTLBloggerBlogList *blogList, NSError *error) {
     // Callback
     self.blogList = blogList;
     self.blogListFetchError = error;
     self.blogListTicket = nil;

     [self updateUI];
   }];

  [self updateUI];
}

#pragma mark Fetch Blog Post List

- (void)fetchPostListForSelectedBlog {
  GTLServiceBlogger *service = self.bloggerService;

  GTLBloggerBlog *selectedBlog = [self selectedBlog];
  NSString *blogID = [selectedBlog.identifier stringValue];
  GTLQueryBlogger *query = [GTLQueryBlogger queryForPostsListWithBlogId:blogID];

  self.postListTicket = [service executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                GTLBloggerPostList *postList, NSError *error) {
      // Callback
      self.postList = postList;
      self.postListFetchError = error;
      self.postListTicket = nil;

      [self setPostEditFieldsFromSelectedPost];
      [self updateUI];
    }];

  [self updateUI];
}

#pragma mark Add a Post

- (void)addAPost {
  GTLServiceBlogger *service = self.bloggerService;

  GTLBloggerBlog *selectedBlog = [self selectedBlog];
  NSString *blogID = [selectedBlog.identifier stringValue];


  GTLBloggerPost *newPost = [GTLBloggerPost object];
  newPost.title = [postTitleField_ stringValue];
  newPost.content = [postBodyField_ stringValue];


  GTLQueryBlogger *query = [GTLQueryBlogger queryForPostsInsertWithObject:newPost
                                                                   blogId:blogID];
  self.editPostTicket = [service executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                GTLBloggerPost *post, NSError *error) {
      // Callback
      self.editPostTicket = nil;
      if (error == nil) {
        [self displayAlert:@"Post Added"
                    format:@"Added \"%@\"", post.title];
        [self clearPostEditFields];
        [self updateUI];
        [self fetchPostListForSelectedBlog];
      } else {
        [self displayAlert:@"Error"
                    format:@"%@", error];
        [self updateUI];
      }
    }];
}

#pragma mark Update a Post

- (void)updateSelectedPost {
  GTLBloggerPost *selectedPost = [self selectedPost];
  if (selectedPost) {
    GTLServiceBlogger *service = self.bloggerService;

    GTLBloggerBlog *selectedBlog = [self selectedBlog];
    NSString *blogID = [selectedBlog.identifier stringValue];
    NSString *postID = [selectedPost.identifier stringValue];
    NSString *oldTitle = selectedPost.title;

    GTLBloggerPost *patchObject = [GTLBloggerPost object];
    patchObject.title = [postTitleField_ stringValue];
    patchObject.content = [postBodyField_ stringValue];


    GTLQueryBlogger *query = [GTLQueryBlogger queryForPostsPatchWithObject:patchObject
                                                                    blogId:blogID
                                                                     postId:postID];
    self.editPostTicket = [service executeQuery:query
                              completionHandler:^(GTLServiceTicket *ticket,
                                                  GTLBloggerPostList *postList, NSError *error) {
      // Callback
      self.editPostTicket = nil;
      if (error == nil) {
        [self displayAlert:@"Post Updated"
                    format:@"Updated \"%@\"", oldTitle];
        [self clearPostEditFields];
        [self updateUI];
        [self fetchPostListForSelectedBlog];
      } else {
        [self displayAlert:@"Error"
                    format:@"%@", error];
        [self updateUI];
      }
    }];
  }
}

#pragma mark Delete a Post

- (void)deleteSelectedPost {
  GTLBloggerPost *selectedPost = [self selectedPost];
  if (selectedPost) {
    GTLServiceBlogger *service = self.bloggerService;

    GTLBloggerBlog *selectedBlog = [self selectedBlog];
    NSString *blogID = [selectedBlog.identifier stringValue];
    NSString *postID = [selectedPost.identifier stringValue];

    GTLQueryBlogger *query = [GTLQueryBlogger queryForPostsDeleteWithBlogId:blogID
                                                                     postId:postID];
    self.editPostTicket = [service executeQuery:query
                              completionHandler:^(GTLServiceTicket *ticket,
                                                  id unusedObj, NSError *error) {
      // Callback
      self.editPostTicket = nil;
      if (error == nil) {
        [self displayAlert:@"Post Deleted"
                    format:@"Deleted \"%@\"", selectedPost.title];
        [self updateUI];
        [self setPostEditFieldsFromSelectedPost];
        [self fetchPostListForSelectedBlog];
      } else {
        [self displayAlert:@"Error"
                    format:@"%@", error];
        [self updateUI];
      }
    }];
  }
}

#pragma mark Delete All Posts

- (void)deleteAllPosts {
  GTLBloggerBlog *selectedBlog = [self selectedBlog];
  NSString *blogID = [selectedBlog.identifier stringValue];

  // Make a batch with a delete query for every post in the blog.
  //
  // http://code.google.com/p/google-api-objectivec-client/wiki/Introduction#Batch_Operations

  GTLBatchQuery *batchQuery = [GTLBatchQuery batchQuery];
  for (GTLBloggerPost *post in self.postList) {
    NSString *postID = [post.identifier stringValue];
    GTLQueryBlogger *query = [GTLQueryBlogger queryForPostsDeleteWithBlogId:blogID
                                                                     postId:postID];
    [batchQuery addQuery:query];
  }

  GTLServiceBlogger *service = self.bloggerService;
  self.editPostTicket = [service executeQuery:batchQuery
                            completionHandler:^(GTLServiceTicket *ticket,
                                                GTLBatchResult *batchResult, NSError *error) {
    // Callback
    self.editPostTicket = nil;
    if (error == nil) {
      // Execute succeeded: step through the query successes
      // and failures in the result.
      NSDictionary *successes = batchResult.successes;
      NSDictionary *failures = batchResult.failures;

      [self displayAlert:@"Delete All Complete"
                  format:@"Deleted %u posts (%u errors)",
       [successes count], [failures count]];

      [self fetchPostListForSelectedBlog];
    } else {
      // Here, error is non-nil so execute failed: no success or failure
      // results were obtained from the server.
      [self displayAlert:@"Error"
                  format:@"%@", error];
      [self updateUI];
    }
  }];
}

#pragma mark Sign In

- (void)runSigninThenInvokeSelector:(SEL)signInDoneSel {
  // Applications should have client ID and client secret strings
  // hardcoded into the source, but the sample application asks the
  // developer for the strings.
  NSString *clientID = [clientIDField_ stringValue];
  NSString *clientSecret = [clientSecretField_ stringValue];

  if ([clientID length] == 0 || [clientSecret length] == 0) {
    // Remind the developer that client ID and client secret are needed
    [clientIDButton_ performSelector:@selector(performClick:)
                          withObject:self
                          afterDelay:0.5];
    return;
  }

  // Show the OAuth 2 sign-in controller
  NSBundle *frameworkBundle = [NSBundle bundleForClass:[GTMOAuth2WindowController class]];
  GTMOAuth2WindowController *windowController;
  windowController = [GTMOAuth2WindowController controllerWithScope:kGTLAuthScopeBlogger
                                                           clientID:clientID
                                                       clientSecret:clientSecret
                                                   keychainItemName:kKeychainItemName
                                                     resourceBundle:frameworkBundle];

  [windowController signInSheetModalForWindow:[self window]
                            completionHandler:^(GTMOAuth2Authentication *auth,
                                                NSError *error) {
    // Callback
    if (error == nil) {
      self.bloggerService.authorizer = auth;
      if (signInDoneSel) {
        [self performSelector:signInDoneSel];
      }
    } else {
      self.blogListFetchError = error;
      [self updateUI];
    }
  }];
}

#pragma mark UI

- (void)updateUI {
  BOOL isSignedIn = [self isSignedIn];
  NSString *username = [self signedInUsername];
  [signedInButton_ setTitle:(isSignedIn ? @"Sign Out" : @"Sign In")];
  [signedInField_ setStringValue:(isSignedIn ? username : @"No")];

  //
  // Blog list table
  //
  [blogListTable_ reloadData];

  if (self.blogListTicket != nil) {
    [blogListProgressIndicator_ startAnimation:self];
    [blogListCancelButton_ setEnabled:YES];
  } else {
    [blogListProgressIndicator_ stopAnimation:self];
    [blogListCancelButton_ setEnabled:NO];
  }

  // Get the description of the selected item, or the feed fetch error.
  NSString *resultStr = @"";

  if (self.blogListFetchError) {
    // Display the error.
    resultStr = [self.blogListFetchError description];
  } else {
    // Display the selected item.
    GTLBloggerBlog *item = [self selectedBlog];
    if (item) {
      resultStr = [item description];
    }
  }
  [blogListResultTextView_ setString:resultStr];

  //
  // Blog post table
  //
  [postListTable_ reloadData];

  if (self.postListTicket != nil || self.editPostTicket != nil) {
    [postListProgressIndicator_ startAnimation:self];
    [postListCancelButton_ setEnabled:YES];
  } else {
    [postListProgressIndicator_ stopAnimation:self];
    [postListCancelButton_ setEnabled:NO];
  }

  // Get the description of the selected item, or the feed fetch error.
  resultStr = @"";

  if (self.postListFetchError) {
    // Display the error.
    resultStr = [self.postListFetchError description];
  } else {
    // Display the selected item.
    GTLBloggerPost *item = [self selectedPost];
    if (item) {
      resultStr = [item description];
    }
  }
  [postListResultTextView_ setString:resultStr];

  // Enable buttons.
  BOOL isBlogSelected = ([self selectedBlog] != nil);
  BOOL isPostSelected = ([self selectedPost] != nil);

  BOOL hasTitleEditText = ([[postTitleField_ stringValue] length] > 0);
  BOOL hasBodyEditText = ([[postBodyField_ stringValue] length] > 0);
  BOOL hasAllEditText = hasTitleEditText && hasBodyEditText;

  [addPostButton_ setEnabled:(isBlogSelected && hasAllEditText)];
  [updatePostButton_ setEnabled:(isPostSelected && hasAllEditText)];
  [deletePostButton_ setEnabled:isPostSelected];
  [deleteAllPostsButton_ setEnabled:isBlogSelected];

  [postTitleField_ setEnabled:isBlogSelected];
  [postBodyField_ setEnabled:isBlogSelected];

  // Show or hide the text indicating that the client ID or client secret are
  // needed.
  BOOL hasClientIDStrings = [[clientIDField_ stringValue] length] > 0
    && [[clientSecretField_ stringValue] length] > 0;
  [clientIDRequiredTextField_ setHidden:hasClientIDStrings];
}

- (void)displayAlert:(NSString *)title format:(NSString *)format, ... {
  NSString *result = format;
  if (format) {
    va_list argList;
    va_start(argList, format);
    result = [[[NSString alloc] initWithFormat:format
                                     arguments:argList] autorelease];
    va_end(argList);
  }
  NSBeginAlertSheet(title, nil, nil, nil, [self window], nil, nil,
                    nil, nil, result);
}

#pragma mark Client ID Sheet

// Client ID and Client Secret Sheet
//
// Sample apps need this sheet to ask for the client ID and client secret
// strings.
//
// Your application will just hardcode the client ID and client secret strings
// into the source rather than ask the user for them.
//
// The string values are obtained from the API Console,
// https://code.google.com/apis/console

- (IBAction)clientIDClicked:(id)sender {
  // Show the sheet for developers to enter their client ID and client secret
  [NSApp beginSheet:clientIDSheet_
     modalForWindow:[self window]
      modalDelegate:self
     didEndSelector:@selector(clientIDSheetDidEnd:returnCode:contextInfo:)
        contextInfo:NULL];
}

- (IBAction)clientIDDoneClicked:(id)sender {
  [NSApp endSheet:clientIDSheet_ returnCode:NSOKButton];
}

- (void)clientIDSheetDidEnd:(NSWindow *)sheet
                 returnCode:(NSInteger)returnCode
                contextInfo:(void *)contextInfo {
  [sheet orderOut:self];
  [self updateUI];
}

#pragma mark Text field delegate methods

- (void)controlTextDidChange:(NSNotification *)note {
  [self updateUI];  // enable and disable buttons
}

#pragma mark TableView delegate and data source methods

- (void)tableViewSelectionDidChange:(NSNotification *)notification {
  // The blog selection changed.
  if ([notification object] == blogListTable_) {
    [self fetchPostListForSelectedBlog];
  } else {
    [self setPostEditFieldsFromSelectedPost];
    [self updateUI];
  }
}

- (int)numberOfRowsInTableView:(NSTableView *)tableView {
  if (tableView == blogListTable_) {
    return [self.blogList.items count];
  } else {
    return [self.postList.items count];
  }
}

- (id)tableView:(NSTableView *)tableView
objectValueForTableColumn:(NSTableColumn *)tableColumn
            row:(int)row {
  if (tableView == blogListTable_) {
    GTLBloggerBlog *item = [self.blogList itemAtIndex:row];
    NSString *title = item.name;
    return title;
  } else {
    GTLBloggerPost *item = [self.postList itemAtIndex:row];
    NSString *title = item.title;
    return title;
  }
}

@end

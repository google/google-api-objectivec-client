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

#import <XCTest/XCTest.h>

#import "GTLService.h"
#import "GTMHTTPFetcherTestServer.h"

#import "GTLTasksTasks.h"
#import "GTLTasksTask.h"

#ifdef GTL_TARGET_NAMESPACE
#define PREFIXED_CLASSNAME(classname) \
  [NSString stringWithFormat:@"%s_%@", GTL_TARGET_NAMESPACE_STRING, classname]
#else
#define PREFIXED_CLASSNAME(classname) classname
#endif // GTL_TARGET_NAMESPACE

//
// Simple authorizer class for testing
//

@interface GTLTestAuthorizer : NSObject <GTMFetcherAuthorizationProtocol> {
  NSString *value_;
  NSError *error_;
}
// the value string will be added to the authorization header, like
// Authorization: OAuth value
+ (GTLTestAuthorizer *)authorizerWithValue:(NSString *)value;

@property (copy) NSString *value;
@property (retain) NSError *error;
@end

//
// Minimal Tasks query class for test cases below
//

@interface GTLQueryTasksTest : GTLQuery
@property (assign) NSInteger maxResults;
@property (retain) NSString *pageToken;
@property (retain) NSString *task;
@property (retain) NSString *tasklist;
@property (retain) NSString *fields;
@property (assign) BOOL showCompleted;
@property (assign) BOOL showDeleted;
@property (assign) BOOL showHidden;
@end

@implementation GTLQueryTasksTest
@dynamic maxResults, pageToken, task, tasklist, fields, showCompleted,
         showDeleted, showHidden;

+ (id)queryForTasksListWithTasklist:(NSString *)tasklist {
  NSString *methodName = @"tasks.tasks.list";
  GTLQueryTasksTest *query = [self queryWithMethodName:methodName];
  query.tasklist = tasklist;
  query.expectedObjectClass = [GTLTasksTasks class];
  return query;
}

+ (id)queryForTasksUpdateWithObject:(GTLTasksTask *)object
                           tasklist:(NSString *)tasklist
                               task:(NSString *)task {
  if (object == nil) {
    return nil;
  }
  NSString *methodName = @"tasks.tasks.update";
  GTLQueryTasksTest *query = [self queryWithMethodName:methodName];
  query.bodyObject = object;
  query.tasklist = tasklist;
  query.task = task;
  query.expectedObjectClass = [GTLTasksTask class];
  return query;
}

+ (id)queryForTasksDeleteWithTasklist:(NSString *)tasklist
                                 task:(NSString *)task {
  NSString *methodName = @"tasks.tasks.delete";
  GTLQueryTasksTest *query = [self queryWithMethodName:methodName];
  query.tasklist = tasklist;
  query.task = task;
  return query;
}


+ (id)queryForTasksGetWithTasklist:(NSString *)tasklist
                              task:(NSString *)task {
  NSString *methodName = @"tasks.tasks.get";
  GTLQueryTasksTest *query = [self queryWithMethodName:methodName];
  query.tasklist = tasklist;
  query.task = task;
  query.expectedObjectClass = [GTLTasksTask class];
  return query;
}

@end

//
// Subclasses for testing surrogates
//

@interface MyTasks : GTLTasksTasks
@property (readonly) NSString *malaprop;
@end

@interface MyTask : GTLTasksTask
@property (readonly) NSString *mondegreen;
@end



@interface GTLServiceTest : XCTestCase {
  // setup/teardown ivars
  GTMHTTPFetcherTestServer *testServer_;
  BOOL isServerRunning_;

  // notification counters
  int parseStartedCount_;
  int parseStoppedCount_;
}

@end

@interface GTLServiceTest ()
- (void)service:(GTLService *)service
  waitForTicket:(GTLServiceTicket *)ticket;
- (void)parseStateChanged:(NSNotification *)note;
@end

@implementation GTLServiceTest

static const NSTimeInterval kTimeoutInterval = 10.0;

// Files available in Tests folder
static NSString *const kRESTValidFileName = @"Task1.rest.txt";
static NSString *const kRESTErrorFileName = @"Task1.rest.txt?status=499";

static NSString *const kRPCValidName = @"Task1.rpc";
static NSString *const kRPCInvalidName = @"TaskError1.rpc";
static NSString *const kRPCDeleteName = @"TaskDelete1.rpc";
static NSString *const kRPCEmptyName = @"TaskEmpty1.rpc";

// Token paging
static NSString *const kRPCPageAName = @"TaskPage1a.rpc"; // page token request
static NSString *const kRPCPageBName = @"TaskPage1b.rpc"; // page token response
// Indexed paging
static NSString *const kRPCPageCName = @"TaskPage1c.rpc"; // start index request
static NSString *const kRPCPageDName = @"TaskPage1d.rpc"; // start index response
// Batch
static NSString *const kBatchRPCName = @"TaskBatch1.rpc";
// Batch with paging
static NSString *const kBatchRPCPageAName = @"TaskBatchPage1a.rpc";
static NSString *const kBatchRPCPageBName = @"TaskBatchPage1b.rpc";

- (NSString *)docRootPath {
  // find a test file
  NSBundle *testBundle = [NSBundle bundleForClass:[self class]];
  XCTAssertNotNil(testBundle);

  NSString *docPath = [testBundle pathForResource:kRESTValidFileName
                                           ofType:nil];
  XCTAssertNotNil(docPath);

  // use the directory of the test file as the root directory for our server
  NSString *docFolder = [docPath stringByDeletingLastPathComponent];
  return docFolder;
}

- (void)setUp {
  NSString *docRoot = [self docRootPath];

  testServer_ = [[GTMHTTPFetcherTestServer alloc] initWithDocRoot:docRoot];
  isServerRunning_ = (testServer_ != nil);

  XCTAssertTrue(isServerRunning_,
               @">>> http test server failed to launch; skipping"
               " fetcher tests\n");

  // install observers for fetcher notifications
  NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
  [nc addObserver:self selector:@selector(parseStateChanged:) name:kGTLServiceTicketParsingStartedNotification object:nil];
  [nc addObserver:self selector:@selector(parseStateChanged:) name:kGTLServiceTicketParsingStoppedNotification object:nil];

  parseStartedCount_ = 0;
  parseStoppedCount_ = 0;
}

- (void)tearDown {
  [testServer_ stopServer];
  [testServer_ release];
  testServer_ = nil;

  isServerRunning_ = NO;
}

#pragma mark Notification callbacks

- (void)parseStateChanged:(NSNotification *)note {
  if ([[note name] isEqual:kGTLServiceTicketParsingStartedNotification]) {
    ++parseStartedCount_;

    XCTAssertTrue(parseStartedCount_ == parseStoppedCount_ + 1,
                 @"parse notification imbalance: starts=%d stops=%d",
                 parseStartedCount_,
                 parseStoppedCount_);
  } else {
    ++parseStoppedCount_;

    XCTAssertTrue(parseStartedCount_ == parseStoppedCount_,
                 @"parse notification imbalance: starts=%d stops=%d",
                 parseStartedCount_,
                 parseStoppedCount_);
  }

}
#pragma mark Tests

- (void)testServiceRESTFetch {

  if (!isServerRunning_) return;

  GTLService *service = [[[GTLService alloc] init] autorelease];

  GTLServiceCompletionHandler completionBlock;
  GTLServiceTicket *ticket;
  NSURL *feedURL;

  //
  // test:  download feed
  //

  feedURL = [testServer_ localURLForFile:kRESTValidFileName];
  completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    GTLTasksTasks *feed = object;

    //
    // test items array
    //
    XCTAssertEqual([feed.items count], (NSUInteger) 2,
                   @"wrong feed items");

    GTLTasksTask *item = feed[0];
    NSString *className = NSStringFromClass([item class]);
    NSString *expectedName = PREFIXED_CLASSNAME(@"GTLTasksTask");

    XCTAssertEqualObjects(expectedName, className, @"object member error");

    // test date/time member
    XCTAssertEqualObjects(item.updated.RFC3339String, @"2011-04-29T22:14:47.779Z",
                         @"GTLDateTime member error");

    // test string member
    XCTAssertEqualObjects(item.title, @"task one",
                         @"NSString member error");

    XCTAssertEqualObjects(className, expectedName,
                         @"object member error");
  };

  ticket = [service fetchObjectWithURL:feedURL
                     completionHandler:completionBlock];
  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");

  //
  // test fetch error
  //
  feedURL = [testServer_ localURLForFile:kRESTErrorFileName];

  completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    NSDictionary *userInfo = [error userInfo];
    GTLErrorObject *errObj = userInfo[kGTLStructuredErrorKey];

    XCTAssertNil(object, @"unexpected object on error");
    XCTAssertEqualObjects(errObj.message, @"Server Status 499",
                         @"error message");
    XCTAssertEqual([errObj.code intValue], 499,
                   @"error code");
  };

  ticket = [service fetchObjectWithURL:feedURL
                     completionHandler:completionBlock];
  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");

  //
  // test parse notifications
  //
  XCTAssertEqual(parseStartedCount_, 1, @"Parse count wrong");

}

- (void)testServiceRPCFetch {

  // test:  fetch single query, with valid authorization
  //
  // tests for files "Task1.request.txt" and "Task1.response.txt"

  if (!isServerRunning_) return;

  GTLService *service = [[[GTLService alloc] init] autorelease];
  service.rpcURL = [testServer_ localURLForFile:kRPCValidName];
  service.apiVersion = @"v1";

  service.authorizer = [GTLTestAuthorizer authorizerWithValue:@"catpaws"];

  GTLServiceCompletionHandler completionBlock;

  completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    GTLTasksTasks *tasks = object;

    XCTAssertNil(error, @"fetch error %@", error);
    XCTAssertEqual((NSUInteger) 2, [tasks.items count], @"item count");

    GTLTasksTask *item = tasks[0];
    NSString *className = NSStringFromClass([item class]);
    NSString *expectedName = PREFIXED_CLASSNAME(@"GTLTasksTask");

    XCTAssertEqualObjects(expectedName, className, @"object member error");

    // test members
    XCTAssertEqualObjects(@"task one", item.title, @"NSString member error");
    XCTAssertEqualObjects(@"2011-04-29T22:14:47.779Z",
                         item.updated.RFC3339String, @"Date");
  };

  GTLQueryTasksTest *query = [GTLQueryTasksTest queryForTasksListWithTasklist:@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDow"];

  query.showCompleted = YES;
  query.showHidden = NO;
  query.showDeleted = NO;
  query.requestID = @"gtl_12";

  // test adding http headers to the query
  query.additionalHTTPHeaders = @{ @"X-Feline": @"Fluffy",
                                   @"X-Canine": @"Spot" };

  // tell the test server to look for an oauth authorization header
  query.urlQueryParameters = @{ @"oauth2": @"catpaws" };

  GTLServiceTicket *ticket = [service executeQuery:query
                                 completionHandler:completionBlock];

  NSString *headerValue = [ticket.objectFetcher.mutableRequest valueForHTTPHeaderField:@"X-Feline"];
  XCTAssertEqualObjects(headerValue, @"Fluffy", @"query http headers");

  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");

  //
  // test: fetch single query with error returned
  //
  // tests for files "TaskError1.request.txt" and "TaskError1.response.txt"

  service.rpcURL = [testServer_ localURLForFile:kRPCInvalidName];

  completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    XCTAssertNil(object, @"fetch object %@", object);
    XCTAssertNotNil(error, @"fetch error missing");

    GTLErrorObject *errorObj = [[error userInfo] objectForKey:kGTLStructuredErrorKey];
    NSString *className = NSStringFromClass([errorObj class]);
    NSString *expectedName = PREFIXED_CLASSNAME(@"GTLErrorObject");
    XCTAssertEqualObjects(expectedName, className, @"error class name");

    XCTAssertEqualObjects(@"Invalid Value", errorObj.message, @"message");
    XCTAssertEqual(400, [errorObj.code intValue], @"error code");

    GTLErrorObjectData *errData = [errorObj.data lastObject];
    XCTAssertEqualObjects(@"global", errData.domain, @"domain");
    XCTAssertEqualObjects(@"invalid", errData.reason, @"reason");
    XCTAssertEqualObjects(@"Invalid Value", errData.message, @"message");
  };

  query = [GTLQueryTasksTest queryForTasksListWithTasklist:@"abcd"];
  query.requestID = @"gtl_4";

  ticket = [service executeQuery:query
               completionHandler:completionBlock];
  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");

  //
  // test: fetch single valid query with invalid auth
  //
  completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    XCTAssertEqual((NSInteger) 401, [error code], @"auth should not match");
  };

  query = [GTLQueryTasksTest queryForTasksListWithTasklist:@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDow"];

  query.showCompleted = YES;
  query.showHidden = NO;
  query.showDeleted = NO;
  query.requestID = @"gtl_12";

  // tell the test server to look for an oauth authorization header
  query.urlQueryParameters = @{ @"oauth2": @"dogpaws" };

  ticket = [service executeQuery:query
               completionHandler:completionBlock];
  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");

  //
  // test: delete an item, expect an empty response as nil
  //
  completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    XCTAssertNil(object);
  };

  service.rpcURL = [testServer_ localURLForFile:kRPCDeleteName];
  query = [GTLQueryTasksTest queryForTasksDeleteWithTasklist:@"MTQwNzM4MjM0NzE2NDExMDgxOTM6MDow"
                                                        task:@"MTQwNzM4MjM0NzE2NDExMDgxOTM6MDoz"];
  query.requestID = @"gtl_5";
  ticket = [service executeQuery:query
               completionHandler:completionBlock];
  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");

  //
  // test: fetch with fields that should lead to an empty item, expect an empty
  // response as a bare object instance
  //
  completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    XCTAssertTrue([object isKindOfClass:[GTLTasksTasks class]],
                 @"%@", [object class]);
    XCTAssertNil([object JSON], @"%@", [object JSON]);
  };

  service.rpcURL = [testServer_ localURLForFile:kRPCEmptyName];
  query = [GTLQueryTasksTest queryForTasksListWithTasklist:@"MTQwNzM4MjM0NzE2NDExMDgxOTM6MDow"];
  query.requestID = @"gtl_7";
  query.fields = @"";
  ticket = [service executeQuery:query
               completionHandler:completionBlock];
  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");
}

- (void)testServiceRPCSurrogates {

  // test:  fetch single query with surrogate objects instantiated
  //
  // tests for files "Task1.request.txt" and
  //                 "Task1.response.txt"

  if (!isServerRunning_) return;

  GTLService *service = [[[GTLService alloc] init] autorelease];
  service.rpcURL = [testServer_ localURLForFile:kRPCValidName];
  service.apiVersion = @"v1";

  // declare the surrogates we want instantiated
  service.surrogates = @{ (id<NSCopying>)[GTLTasksTask class] : [MyTask class],
                          (id<NSCopying>)[GTLTasksTasks class] : [MyTasks class] };

  GTLServiceCompletionHandler completionBlock;

  completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    MyTasks *tasks = object;

    XCTAssertNil(error, @"fetch error %@", error);

    // top-level object
    NSString *className = NSStringFromClass([tasks class]);
    NSString *expectedName = @"MyTasks";
    XCTAssertEqualObjects(expectedName, className, @"surrogate 1");

    XCTAssertEqualObjects(tasks.ETag, @"\"5DpO54-Ji94EiKCRzWvdF06jkVo/CrrTnTzqLPnIghISZ2cNonnjkqs\"", @"etag");
    XCTAssertEqualObjects(tasks.malaprop, @"fire distinguisher", @"subclass");

    // internal object
    MyTask *task = [tasks itemAtIndex:0];

    className = NSStringFromClass([task class]);
    expectedName = @"MyTask";
    XCTAssertEqualObjects(className, expectedName, @"surrogate 2");

    XCTAssertEqualObjects(task.identifier, @"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDoy",
                         @"id");
    XCTAssertEqualObjects(task.mondegreen, @"crimean river", @"subclass");
  };


  GTLQueryTasksTest *query = [GTLQueryTasksTest queryForTasksListWithTasklist:@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDow"];
  query.showCompleted = YES;
  query.showHidden = NO;
  query.showDeleted = NO;
  query.requestID = @"gtl_12";

  GTLServiceTicket *ticket = [service executeQuery:query
                                 completionHandler:completionBlock];
  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");
}

- (void)testServiceRPCPagedFetch {

  //
  // Test token-based paging
  //
  // tests for files "TaskPage1a.request.txt" and "TaskPage1a.response.txt"
  //   and for the page 1b versions

  if (!isServerRunning_) return;

  GTLService *service = [[[GTLService alloc] init] autorelease];
  service.rpcURL = [testServer_ localURLForFile:kRPCPageAName];
  service.apiVersion = @"v1";
  service.shouldFetchNextPages = YES;

  GTLServiceCompletionHandler completionBlock;

  completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    GTLTasksTasks *tasks = object;

    XCTAssertNil(error, @"fetch error %@", error);

    // we should have four items, two from each page
    XCTAssertEqual([tasks.items count], (NSUInteger) 4, @"item count");

    // test item class
    GTLTasksTask *item1 = tasks[0];
    NSString *className = NSStringFromClass([item1 class]);
    NSString *expectedName = PREFIXED_CLASSNAME(@"GTLTasksTask");
    XCTAssertEqualObjects(expectedName, className, @"object member error");

    // test members of items from each page
    XCTAssertEqualObjects(@"task one", item1.title, @"NSString member error");

    GTLTasksTask *item4 = tasks[3];
    XCTAssertEqualObjects(@"task four", item4.title, @"NSString member error");
  };

  GTLQueryTasksTest *query = [GTLQueryTasksTest queryForTasksListWithTasklist:@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDow"];
  query.requestID = @"gtl_17";
  query.maxResults = 2;

  GTLServiceTicket *ticket = [service executeQuery:query
                                 completionHandler:completionBlock];

  // this executeQuery: invocation creates the first fetcher, getting
  // the first page of the response.  We'll change the rpc URL now
  // so when the automatic fetch of the second page occurs later, it
  // will fetch the page B file
  service.rpcURL = [testServer_ localURLForFile:kRPCPageBName];

  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");

  //
  // Test indexed-based paging (relying on the task categories at
  // the bottom of this file)
  //
  service.rpcURL = [testServer_ localURLForFile:kRPCPageCName];
  query = [GTLQueryTasksTest queryForTasksListWithTasklist:@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDow"];
  query.requestID = @"gtl_18";
  query.maxResults = 2;

  ticket = [service executeQuery:query
               completionHandler:completionBlock];

  service.rpcURL = [testServer_ localURLForFile:kRPCPageDName];

  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");
}

- (void)testServiceRPCBatchFetch {
  
  // test:  fetch query batch
  //
  // tests for files "TaskBatch1.request.txt" and "TaskBatch1.response.txt"
  
  if (!isServerRunning_) return;
  
  GTLService *service = [[[GTLService alloc] init] autorelease];
  service.rpcURL = [testServer_ localURLForFile:kBatchRPCName];
  service.apiVersion = @"v1";
  
  GTLServiceCompletionHandler completionBlock;
  
  completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    GTLBatchResult *batchResult = object;
    
    // we expect the first batch item to succeed, the second to fail,
    // the third to succeed but return an empty object, which shows up
    // as an NSNull
    NSDictionary *successes = batchResult.successes;
    XCTAssertEqual((NSUInteger) 2, [successes count], @"success count");
    
    NSDictionary *failures = batchResult.failures;
    XCTAssertEqual((NSUInteger) 1, [failures count], @"failure count");
    
    // successful item
    GTLTasksTask *item = successes[@"gtl_19"];
    NSString *className = NSStringFromClass([item class]);
    NSString *expectedName = PREFIXED_CLASSNAME(@"GTLTasksTask");
    XCTAssertEqualObjects(expectedName, className, @"result class error");
    
    XCTAssertEqualObjects(@"tasks#task", item.kind, @"kind field");
    XCTAssertEqualObjects(@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDox", item.identifier, @"id");
    XCTAssertEqualObjects(@"2011-05-03T23:14:20.735Z",
                         item.updated.RFC3339String, @"date");
    
    // failed item
    GTLErrorObject *errorObj = failures[@"gtl_18"];
    className = NSStringFromClass([errorObj class]);
    expectedName = PREFIXED_CLASSNAME(@"GTLErrorObject");
    XCTAssertEqualObjects(expectedName, className, @"error object");
    
    XCTAssertEqual(400, [errorObj.code intValue], @"error code");
    XCTAssertEqualObjects(@"Invalid Value", errorObj.message, @"error message");
    
    GTLErrorObjectData *errData = [errorObj.data lastObject];
    XCTAssertEqualObjects(@"invalid", errData.reason, @"error reason");
  };

  // make a batch with two queries
  __block NSMutableArray *queriesToCallBack = [NSMutableArray array];

  GTLTasksTask *task1 = [GTLTasksTask object];
  task1.identifier = @"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDox";
  task1.status = @"needsAction";
  task1.title = @"task one";
  task1.identifier = @"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDox";
  GTLQueryTasksTest *query1 = [GTLQueryTasksTest queryForTasksUpdateWithObject:task1
                                                                      tasklist:@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDow"
                                                                          task:@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDox"];
  query1.requestID = @"gtl_19";
  query1.completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    // Remove this query from the list
    XCTAssertTrue([queriesToCallBack containsObject:query1], @"callback list");
    [queriesToCallBack removeObject:query1];
  };
  [queriesToCallBack addObject:query1];

  GTLTasksTask *task2 = [GTLTasksTask object];
  task2.status = @"needsAction";
  task2.title = @"task two";
  task2.identifier = @"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDoy";
  GTLQueryTasksTest *query2 = [GTLQueryTasksTest queryForTasksUpdateWithObject:task2
                                                                      tasklist:@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDow"
                                                                          task:@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDoy"];
  query2.requestID = @"gtl_18";
  query2.completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    // Remove this query from the list
    XCTAssertTrue([queriesToCallBack containsObject:query2], @"callback list");
    [queriesToCallBack removeObject:query2];
  };
  [queriesToCallBack addObject:query2];

  GTLQueryTasksTest *query3 = [GTLQueryTasksTest queryForTasksDeleteWithTasklist:@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDow"
                                                                            task:@"MDg0NTg2OTA1ODg4OTI3MzgyMzQ6NDoz"];
  query3.requestID = @"gtl_20";
  query3.completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {
    XCTAssertEqual(object, [NSNull null]);
    // Remove this query from the list
    XCTAssertTrue([queriesToCallBack containsObject:query3], @"callback list");
    [queriesToCallBack removeObject:query3];
  };
  [queriesToCallBack addObject:query3];

  GTLBatchQuery *batchQuery = [GTLBatchQuery batchQuery];
  [batchQuery addQuery:query1];
  [batchQuery addQuery:query2];
  [batchQuery addQuery:query3];

  GTLServiceTicket *ticket = [service executeQuery:batchQuery
                                 completionHandler:completionBlock];
  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");

  XCTAssertEqual([queriesToCallBack count], (NSUInteger) 0,
                 @"queries not called back");
  XCTAssertNil(query2.completionBlock, @"Query callback not cleared");
}

- (void)testServiceRPCPagedBatchFetch {
  // Test token-based paging on queries in a batch fetch
  //
  // This tests for files "TaskBatchPage1a.request.txt" and
  // "TaskBatchPage1a.response.txt", and for the page 1b request
  // and response

  if (!isServerRunning_) return;

  GTLService *service = [[[GTLService alloc] init] autorelease];
  service.rpcURL = [testServer_ localURLForFile:kBatchRPCPageAName];
  service.apiVersion = @"v1";
  service.shouldFetchNextPages = YES;

  // Query for one item
  GTLQueryTasksTest *query1 = [GTLQueryTasksTest queryForTasksGetWithTasklist:@"MTQwNzM4MjM0NzE2NDExMDgxOTM6MDow"
                                                                         task:@"MTQwNzM4MjM0NzE2NDExMDgxOTM6MDoz"];
  query1.requestID = @"gtl_4";

  // Query for pages of items
  GTLQueryTasksTest *query2 = [GTLQueryTasksTest queryForTasksListWithTasklist:@"MTQwNzM4MjM0NzE2NDExMDgxOTM6MDow"];
  query2.requestID = @"gtl_3";
  query2.showCompleted = YES;
  query2.showHidden = NO;
  query2.showDeleted = NO;
  query2.maxResults = 2;

  GTLBatchQuery *batchQuery = [GTLBatchQuery batchQuery];
  [batchQuery addQuery:query1];
  [batchQuery addQuery:query2];

  GTLServiceCompletionHandler completionBlock;
  completionBlock = ^(GTLServiceTicket *ticket, id object, NSError *error) {

    XCTAssertNil(error, @"fetch error %@ %@", error, [error userInfo]);
    GTLBatchResult *result = object;

    NSDictionary *successes = result.successes;
    NSDictionary *failures = result.failures;

    XCTAssertEqual([successes count], (NSUInteger) 2, @"success count");
    XCTAssertEqual([failures count], (NSUInteger) 0, @"failures count");

    GTLTasksTask *task = [successes objectForKey:[query1 requestID]];
    XCTAssertEqualObjects(task.title, @"Wash", @"task title");

    GTLTasksTasks *taskCollection = [successes objectForKey:[query2 requestID]];
    XCTAssertEqual([taskCollection.items count], (NSUInteger) 4,
                   @"collection count");

    GTLTasksTask *item0 = [taskCollection itemAtIndex:0];
    GTLTasksTask *item3 = [taskCollection itemAtIndex:3];
    XCTAssertEqualObjects(item0.title, @"task uno", @"first task");
    XCTAssertEqualObjects(item3.title, @"task cuatro", @"last task");
    XCTAssertEqualObjects(item3.notes, @"Notez", @"last task");
  };

  GTLServiceTicket *ticket = [service executeQuery:batchQuery
                                 completionHandler:completionBlock];

  // this executeQuery: invocation creates the first fetcher, getting
  // the first page of the response.  We'll change the rpc URL now
  // so when the automatic fetch of the second page occurs later, it
  // will fetch the page B file
  service.rpcURL = [testServer_ localURLForFile:kBatchRPCPageBName];

  [self service:service waitForTicket:ticket];
  XCTAssertTrue(ticket.hasCalledCallback, @"callback skipped");
}

- (void)service:(GTLService *)service waitForTicket:(GTLServiceTicket *)ticket {
  [service waitForTicket:ticket
                 timeout:kTimeoutInterval
           fetchedObject:NULL
                   error:NULL];
}

@end

#pragma mark -

//
// Simple authorizer object for testing - implementation
//

@implementation GTLTestAuthorizer
@synthesize value = value_,
            error = error_;

+ (GTLTestAuthorizer *)authorizerWithValue:(NSString *)value {
  GTLTestAuthorizer *obj = [[[[self class] alloc] init] autorelease];
  obj.value = value;
  return obj;
}

- (void)dealloc {
  [value_ release];
  [error_ release];
  [super dealloc];
}

- (NSString *)authorizationValue {
  NSString *str = [NSString stringWithFormat:@"Bearer %@", value_];
  return str;
}

- (void)authorizeRequest:(NSMutableURLRequest *)request
                delegate:(id)delegate
       didFinishSelector:(SEL)sel {
  NSString *str = [self authorizationValue];
  [request setValue:str forHTTPHeaderField:@"Authorization"];

  NSMethodSignature *sig = [delegate methodSignatureForSelector:sel];
  NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:sig];
  [invocation setSelector:sel];
  [invocation setTarget:delegate];
  [invocation setArgument:&self atIndex:2];
  [invocation setArgument:&request atIndex:3];
  [invocation setArgument:&error_ atIndex:4];
  [invocation invoke];
}

- (void)stopAuthorization {
}

- (void)stopAuthorizationForRequest:(NSURLRequest *)request {
}

- (BOOL)isAuthorizingRequest:(NSURLRequest *)request {
  return NO;
}

- (BOOL)isAuthorizedRequest:(NSURLRequest *)request {
  NSString *requestValue = [request valueForHTTPHeaderField:@"Authorization"];
  NSString *str = [self authorizationValue];
  return GTL_AreEqualOrBothNil(requestValue, str);
}

- (NSString *)userEmail {
  return @"test@example.com";
}
@end

#pragma mark -

//
// Subclasses for testing surrogates
//

@implementation MyTasks
- (NSString *)malaprop {
 return @"fire distinguisher";
}
@end

@implementation MyTask
- (NSString *)mondegreen {
  return @"crimean river";
}
@end

//
// Categories to add indexed-based paging to Tasks for our unit test
//

@interface GTLTasksTasks (UnitTestAdditions)
@property (retain) NSNumber *nextStartIndex;
@end

@implementation GTLTasksTasks (UnitTestAdditions)
@dynamic nextStartIndex;
@end

@interface GTLQueryTasksTest (UnitTestAdditions)
@property (assign) NSUInteger startIndex;
@end

@implementation GTLQueryTasksTest (UnitTestAdditions)
@dynamic startIndex;
@end

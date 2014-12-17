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
//  EditACLWindowController.m
//

#import "EditACLWindowController.h"

@implementation EditACLWindowController

- (id)init {
  return [self initWithWindowNibName:@"EditACLWindow"];
}

- (void)awakeFromNib {
  if (rule_) {
    // Copy data from the ACL entry to our dialog's controls
    NSString *scopeType = rule_.scope.type;
    NSString *scopeValue = rule_.scope.value;
    NSString *roleValue = rule_.role;

    if (scopeType) [scopeTypeField_ setStringValue:scopeType];
    if (scopeValue) [scopeValueField_ setStringValue:scopeValue];
    if (roleValue) [roleValueField_ setStringValue:roleValue];

    // Add standard calendar roles to the combo box's menu
    NSArray *items = [NSArray arrayWithObjects:
                      kGTLCalendarMinAccessRoleOwner,
                      kGTLCalendarMinAccessRoleWriter,
                      kGTLCalendarMinAccessRoleReader,
                      kGTLCalendarMinAccessRoleFreeBusyReader,
                      nil];
    [roleValueField_ addItemsWithObjectValues:items];
  }
}

- (void)dealloc {
  [rule_ release];
  [super dealloc];
}

- (GTLCalendarAclRule *)rule {
  // Copy from our dialog's controls into a copy of the original object
  NSString *scopeType = [scopeTypeField_ stringValue];
  NSString *scopeValue = [scopeValueField_ stringValue];
  NSString *roleValue = [roleValueField_ stringValue];

  GTLCalendarAclRule *rule;
  if (rule_) {
    rule = [[rule_ copy] autorelease];
  } else {
    rule = [GTLCalendarAclRule object];
  }

  rule.role = roleValue;
  rule.scope.value = scopeValue;
  rule.scope.type = scopeType;

  return rule;
}

#pragma mark -

- (void)runModalForWindow:(NSWindow *)window
                  ACLRule:(GTLCalendarAclRule *)rule
        completionHandler:(void (^)(NSInteger returnCode, GTLCalendarAclRule *rule))handler {
  completionHandler_ = [handler copy];
  rule_ = [rule retain];

  [window beginSheet:[self window] completionHandler:nil];

  [self retain];
}

- (void)sheetDidEnd:(NSWindow *)sheet
         returnCode:(int)returnCode
        contextInfo:(void  *)contextInfo {
}

- (void)closeDialogWithReturnCode:(NSInteger)returnCode {
  // Call the handler to say we're done
  if (completionHandler_) {
    completionHandler_(returnCode, [self rule]);

    [completionHandler_ release];
    completionHandler_ = nil;
  }

  NSWindow *sheet = [self window];
  NSWindow *parent = [sheet sheetParent];
  [parent endSheet:sheet];
}

- (IBAction)saveButtonClicked:(id)sender {
  [self closeDialogWithReturnCode:NSModalResponseOK];
}

- (IBAction)cancelButtonClicked:(id)sender {
  [self closeDialogWithReturnCode:NSModalResponseCancel];
}

@end

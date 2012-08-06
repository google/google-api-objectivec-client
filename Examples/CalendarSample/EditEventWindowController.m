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
//  EditEventWindowController.m
//

#import "EditEventWindowController.h"

@implementation EditEventWindowController

- (id)init {
  return [self initWithWindowNibName:@"EditEventWindow"];
}

- (void)awakeFromNib {
  if (event_) {
    // Copy data from the event to our dialog's controls
    NSString *title = event_.summary;
    NSString *desc = event_.descriptionProperty;

    GTLDateTime *startTime = event_.start.dateTime;
    GTLDateTime *endTime = event_.end.dateTime;

    // Events may provide a list of reminders to override the calendar's
    // default reminders
    BOOL shouldUseDefaultReminders = [event_.reminders.useDefault boolValue];

    NSString *reminderMinutesStr = @"";
    NSString *reminderMethod = nil;
    if (!shouldUseDefaultReminders) {
      NSArray *reminders = event_.reminders.overrides;
      if ([reminders count] > 0) {
        GTLCalendarEventReminder *reminder = [reminders objectAtIndex:0];
        reminderMinutesStr = [reminder.minutes stringValue];
        reminderMethod = reminder.method;
      }
    }

    if (title) [titleField_ setStringValue:title];
    if (desc) [descriptionField_ setStringValue:desc];

    if (startTime) {
      [startDatePicker_ setDateValue:[startTime date]];
      [startDatePicker_ setTimeZone:[startTime timeZone]];
    }
    if (endTime) {
      [endDatePicker_ setDateValue:[endTime date]];
      [endDatePicker_ setTimeZone:[endTime timeZone]];
    }

    [reminderMatrix_ selectCellWithTag:(shouldUseDefaultReminders ? 0 : 1)];
    [reminderMinutesField_ setStringValue:reminderMinutesStr];
    [reminderMethodPopup_ selectItemWithTitle:reminderMethod];
  }
}

- (void)dealloc {
  [event_ release];
  [super dealloc];
}

#pragma mark -

- (GTLCalendarEvent *)event {
  // Copy from our dialog's controls into a copy of the original event
  NSString *title = [titleField_ stringValue];
  NSString *desc = [descriptionField_ stringValue];
  NSString *reminderMinStr = [reminderMinutesField_ stringValue];
  NSString *reminderMethod = [[reminderMethodPopup_ selectedItem] title];
  BOOL shouldUseDefaultReminders = ([[reminderMatrix_ selectedCell] tag] == 0);

  GTLCalendarEvent *newEvent;
  if (event_) {
    newEvent = [[event_ copy] autorelease];
  } else {
    newEvent = [GTLCalendarEvent object];
  }

  newEvent.summary = title;
  newEvent.descriptionProperty = desc;

  // Times
  //
  // For all-day events, use the GTLDateTime method +dateTimeForAllDayWithDate:
  GTLDateTime *startDateTime = [GTLDateTime dateTimeWithDate:[startDatePicker_ dateValue]
                                                    timeZone:[startDatePicker_ timeZone]];
  GTLDateTime *endDateTime = [GTLDateTime dateTimeWithDate:[endDatePicker_ dateValue]
                                                  timeZone:[endDatePicker_ timeZone]];
  newEvent.start.dateTime = startDateTime;
  newEvent.end.dateTime = endDateTime;

  // Reminders
  newEvent.reminders = [GTLCalendarEventReminders object];
  newEvent.reminders.useDefault = [NSNumber numberWithBool:shouldUseDefaultReminders];
  if (!shouldUseDefaultReminders) {
    GTLCalendarEventReminder *reminder = [GTLCalendarEventReminder object];
    reminder.minutes = [NSNumber numberWithInt:[reminderMinStr intValue]];
    reminder.method = reminderMethod;

    newEvent.reminders.overrides = [NSArray arrayWithObject:reminder];
  }
  return newEvent;
}

- (void)runModalForWindow:(NSWindow *)window
                    event:(GTLCalendarEvent *)event
        completionHandler:(void (^)(NSInteger returnCode, GTLCalendarEvent *event))handler {
  completionHandler_ = [handler copy];
  event_ = [event retain];

  [NSApp beginSheet:[self window]
     modalForWindow:window
      modalDelegate:self
     didEndSelector:@selector(sheetDidEnd:returnCode:contextInfo:)
        contextInfo:nil];

  [self retain];
}

- (void)sheetDidEnd:(NSWindow *)sheet returnCode:(int)returnCode  contextInfo:(void  *)contextInfo {

}

- (void)closeDialogWithReturnCode:(NSInteger)returnCode {
  // Call the handler to say we're done
  if (completionHandler_) {
    completionHandler_(returnCode, [self event]);

    [completionHandler_ release];
    completionHandler_ = nil;
  }

  [[self window] orderOut:self];
  [NSApp endSheet:[self window]];
  [self autorelease];
}

- (IBAction)saveButtonClicked:(id)sender {
  [self closeDialogWithReturnCode:NSOKButton];
}

- (IBAction)cancelButtonClicked:(id)sender {
  [self closeDialogWithReturnCode:NSCancelButton];
}

@end

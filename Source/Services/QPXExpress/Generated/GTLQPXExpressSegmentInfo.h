/* Copyright (c) 2015 Google Inc.
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
//  GTLQPXExpressSegmentInfo.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   QPX Express API (qpxExpress/v1)
// Description:
//   Lets you find the least expensive flights between an origin and a
//   destination.
// Documentation:
//   http://developers.google.com/qpx-express
// Classes:
//   GTLQPXExpressSegmentInfo (0 custom class methods, 11 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLQPXExpressFlightInfo;
@class GTLQPXExpressLegInfo;

// ----------------------------------------------------------------------------
//
//   GTLQPXExpressSegmentInfo
//

// Details of a segment of a flight; a segment is one or more consecutive legs
// on the same flight. For example a hypothetical flight ZZ001, from DFW to OGG,
// would have one segment with two legs: DFW to HNL (leg 1), HNL to OGG (leg 2),
// and DFW to OGG (legs 1 and 2).

@interface GTLQPXExpressSegmentInfo : GTLObject

// The booking code or class for this segment.
@property (nonatomic, copy) NSString *bookingCode;

// The number of seats available in this booking code on this segment.
@property (nonatomic, retain) NSNumber *bookingCodeCount;  // intValue

// The cabin booked for this segment.
@property (nonatomic, copy) NSString *cabin;

// In minutes, the duration of the connection following this segment.
@property (nonatomic, retain) NSNumber *connectionDuration;  // intValue

// The duration of the flight segment in minutes.
@property (nonatomic, retain) NSNumber *duration;  // intValue

// The flight this is a segment of.
@property (nonatomic, retain) GTLQPXExpressFlightInfo *flight;

// An id uniquely identifying the segment in the solution.
// identifier property maps to 'id' in JSON (to avoid Objective C's 'id').
@property (nonatomic, copy) NSString *identifier;

// Identifies this as a segment object. A segment is one or more consecutive
// legs on the same flight. For example a hypothetical flight ZZ001, from DFW to
// OGG, could have one segment with two legs: DFW to HNL (leg 1), HNL to OGG
// (leg 2). Value: the fixed string qpxexpress#segmentInfo.
@property (nonatomic, copy) NSString *kind;

// The legs composing this segment.
@property (nonatomic, retain) NSArray *leg;  // of GTLQPXExpressLegInfo

// The solution-based index of a segment in a married segment group. Married
// segments can only be booked together. For example, an airline might report a
// certain booking code as sold out from Boston to Pittsburgh, but as available
// as part of two married segments Boston to Chicago connecting through
// Pittsburgh. For example content of this field, consider the round-trip flight
// ZZ1 PHX-PHL ZZ2 PHL-CLT ZZ3 CLT-PHX. This has three segments, with the two
// outbound ones (ZZ1 ZZ2) married. In this case, the two outbound segments
// belong to married segment group 0, and the return segment belongs to married
// segment group 1.
@property (nonatomic, copy) NSString *marriedSegmentGroup;

// Whether the operation of this segment remains subject to government approval.
@property (nonatomic, retain) NSNumber *subjectToGovernmentApproval;  // boolValue

@end

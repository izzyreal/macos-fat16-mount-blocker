//
//  Arbitrator.h
//  DiskArbitrator
//
//  Created by Aaron Burghardt on 1/10/10.
//  Copyright 2010 Aaron Burghardt. All rights reserved.
//

#ifdef __OBJC__
    #import <Cocoa/Cocoa.h>
#endif

#define SafeCFRelease(v) if (v) { CFRelease(v); }

#import <Cocoa/Cocoa.h>
#import <DiskArbitration/DiskArbitration.h>

// Mount Modes
#define MM_BLOCK	0
#define MM_READONLY	1


@interface Arbitrator : NSObject 

@property (retain) NSMutableSet *disks;
@property (readonly) NSSet *wholeDisks;
@property BOOL isActivated;
@property NSInteger mountMode;
@property (readonly) NSString *dissenterMessage;

- (BOOL)registerSession;
- (void)unregisterSession;
- (BOOL)registerApprovalSession;
- (void)unregisterApprovalSession;

- (BOOL)activate;
- (void)deactivate;

@end

DADissenterRef DiskMountApprovalCallback(DADiskRef disk, void *arbitrator);

extern NSString * const ArbitratorIsEnabled;
extern NSString * const ArbitratorMountMode;

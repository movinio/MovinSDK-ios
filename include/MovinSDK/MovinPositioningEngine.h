//
// MovinPositioningEngine.h
// MovinSDK
//
// Copyright © 2017 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>
#import "MovinPositioner.h"

@class FloorPosition;
@class MovinMap;
@class MovinBeaconScanner;

/**
 * Represents an engine for determining the position of the device.
 */
@interface MovinPositioningEngine : MovinPositioner

/**
 * Initializes the MovinPositioningEngine, which will download the required positioning database if and will fallback to
 * online positioning if offline positioning is not available. Initialization will start automatically if the
 * positioning engine is started without calling initialize.
 */
- (void)initialize;

/**
 * Gets the heading the device is oriented at in radians based on True North.
 *
 * @return The angle between True North and the device orientation in radians.
 */
- (double)getHeading;

/**
 * Returns whether or not the MovinPositioningEngine has yet been initialized.
 */
- (BOOL)isInitialized;

/**
 * This class should not be manually initialized.
 * :nodoc:
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

@end

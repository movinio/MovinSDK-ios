//
//  MovinRangedBeacon.h
//  libMovinSDK
//
//  Created by Movin Software on 07/03/16.
//  Copyright © 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class MovinBeacon;
@class BeaconIdentifier;

/**
 * @class MovinRangedBeacon
 * @brief Represents a ranging result of a single beacon.
 */
@interface MovinRangedBeacon : NSObject

/**
 * @brief Gets the associated MovinBeacon of this ranged beacon. Can be nil.
 */
@property(readonly, nullable) MovinBeacon* beacon;
/**
 * @brief Gets the estimated distance in meters of the device to this beacon.
 */
@property(readonly) double distance;
/**
 * @brief Gets the signal strength in dBm with which this beacon was measured.
 */
@property(readonly) int rssi;
/**
 * @brief Gets the CLProximity of this beacon, this is one of IMMEDIATE, NEAR, FAR or UNKNOWN.
 */
@property(readonly) CLProximity proximity;
/**
 * @brief Gets the beacon specific data, UUID, Major and Minor. Also accessible through the beacon property if that is not nil.
 */
@property(readonly, nonnull) BeaconIdentifier* beaconIdentifier;

/**
 * @brief Initializes a new MovinRangedBeacon.
 * @param beacon The corresponding MovinBeacon.
 * @param distance The distance in meters. This is the accuracy parameter of a CLBeacon.
 * @param rssi The RSSI at which the beacon was measured in dBm.
 * @param proximity The CLProximity of the beacon
 * @param beaconIdentifier The BeaconIdentifier, consisting of its UUID, Major and Minor.
 */
- (nonnull id)initWithMovinBeacon:(nullable MovinBeacon*)beacon
                      andDistance:(double)distance
                          andRssi:(int)rssi
                     andProximity:(CLProximity)proximity
              andBeaconIdentifier:(nonnull BeaconIdentifier*)beaconIdentifier;

@end

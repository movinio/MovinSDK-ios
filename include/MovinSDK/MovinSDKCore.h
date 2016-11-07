//
//  MovinSDK.m
//  MovinSDK
//
//  Created by Movin Software on 26/04/15.
//  Copyright (c) 2015 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MovinCacheProtocol;
@class MovinMap;
@class MovinBeaconScanner;
@class MovinTileStyle;

/**
 * @typedef MovinService
 * @brief A list of the Movin services.
 */
typedef enum MovinService {
    /// Undefined
            MovinServiceUndefined = 0,
    /// Positioning
            MovinServicePositioning = 1,
    /// Turn by turn
            MovinServiceTurnByTurn = 2,
    /// Proximity
            MovinServiceProximity = 4,
    /// Trigger
            MovinServiceTrigger = 8,
    /// Routing
            MovinServiceRouting = 16,
    /// Data
            MovinServiceData = 32
} MovinService;

/**
 * @typedef MovinCacheableData
 * @abstact A list of Movin data types which can be cached.
 */
typedef enum MovinCacheableData {
    /// Data used by the MovinPositioningEngine.
    MovinCacheableDataPositioning = 1,
    /// Data provided by MovinMap, such as buildings and entities.
    MovinCacheableDataMapData = 2,
    /// Tiles provided by the MovinTileProvider.
    MovinCacheableDataTiles = 4,
    /// Images provided by the MovinImageProvider.
    MovinCacheableDataImages = 8,
    /// Data used by the MovinRoutingManager.
    MovinCacheableDataRouting = 16,
    /// Beacon data provided by MovinMap and used by MovinBeaconScanner.
    MovinCacheableDataBeacons = 32,
    /// All cachable data types
    MovinCacheableDataAll = 63
} MovinCacheableData;

// Handler for async requests
typedef void(^DownloadDataCallback)(BOOL success, NSError* _Nullable error);

/**
 * @class MovinSDK
 * @brief Represents the entry point of MovinSDK.
 */
@interface MovinSDK : NSObject

/**
 * @brief Initializes the MovinSDK, which validates the given customer and apikey. The device will be checked for compatibility with Bluetooth Low Energy and some primary components are initialized.
 * @param customer The customer name, provided by Movin
 * @param apikey The apikey associated with this customer, either provided by Movin or generated in the Movin portal
 * @param callback The block called once the initialization finished. Provides a boolean whether it has succeeded and if it has not succeeded an NSError containing the error which occurred.
 * @code
 * [MovinSDK initWithCustomer:@"<customer_name>"
 *                  andApikey:@"<apikey>"
 *                andCallback:^(BOOL success, NSError* error) {
 *    if(success) {
 *        NSLog(@"Succesfully initialized the SDK!");
 *    } else {
 *        NSLog(@"Error initializing the SDK: %@", [error localizedDescription]);
 *    }
 * }];
 * @endcode
 */
+ (void)initWithCustomer:(nonnull NSString*)customer
               andApikey:(nonnull NSString*)apikey
             andCallback:(nullable void (^)(BOOL success, NSError* _Nullable error))callback;

/**
 * @brief Resets the state of the MovinSDK.
 */
+ (void)reset;

/**
 * @brief Returns the singleton instance of MovinBeaconScanner.
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred. An error may
 * occur if the SDK has not yet been initialized or if bluetooth is not available.
 * @return The singleton instance of MovinBeaconScanner.
 */
+ (nullable MovinBeaconScanner*)getBeaconScanner:(NSError* _Nullable* _Nullable)error;

/**
 * @brief Returns a collection of available maps.
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return A collection of available maps.
 */
+ (nullable NSArray<MovinMap*>*)getMaps:(NSError* _Nullable* _Nullable)error;

/**
 * @brief Returns a MovinMap object with the specified id. If the specified id is not available an error is set.
 * @param id The identifier of the map.
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return A MovinMap object with the specified id. If the specified id is not available an error is set.
 */
+ (nullable MovinMap*)getMapWithId:(nonnull NSString*)id
                          andError:(NSError* _Nullable* _Nullable)error;

/**
 * @brief Returns a collection of available styles.
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return A collection of available styles.
 */
+ (nullable NSArray<MovinTileStyle*>*)getStyles:(NSError* _Nullable* _Nullable)error;

/**
 * @brief Returns a MovinTileStyle object with the specified name. If the specified name is not available an error
 * is set.
 * @param name The name of the style.
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return A MovinTileStyle object with the specified name. If the specified id is not available an error is set.
 */
+ (nullable MovinTileStyle*)getStyleWithName:(nonnull NSString*)name
                                    andError:(NSError* _Nullable* _Nullable)error;

/**
 * @brief Returns whether or not the MovinSDK has already been initialized or not.
 */
+ (BOOL)isInitialized;

/**
 * @brief Checks if the given service is supported by both the device and apikey rights.
 * @param service The service to check for.
 * @return Whether or not the service is supported.
 */
+ (BOOL)getServiceSupported:(MovinService)service;

/**
 * @brief Clears the cached files stored by the Movin SDK.
 */
+ (void)clearCache;

/**
 * @brief Sets the cache protocol for the specified data types.
 * @param types The types for which to set the cache protocol.
 * @param cacheProtocol The cache protocol.
 * @code
 * [MovinSDK setCacheProtocolForTypes:MovinCacheableDataPositioning|MovinCacheableDataMapData [MovinCacheProtocol default]]
 * @endcode
 * @warning This method can only be used when the SDK has not yet been initialized.
 */
+ (void)setCacheProtocolForTypes:(MovinCacheableData)types
                              to:(nonnull MovinCacheProtocol*)cacheProtocol;

/**
 * @brief Gets a value indicating whether caching has been enabled fo the specified data type.
 * @return Whether or not caching has been enabled for the specified data type.
 */
+ (nonnull MovinCacheProtocol*)getCacheProtocolForType:(MovinCacheableData)type;

/**
 * @brief Sets a value indicating whether the analytics service should be enabled.
 * @param toggle A value indicating whether the analytics service should be enabled.
 */
+ (void)setAnalyticsEnabled:(BOOL)toggle;

/**
 * @brief Returns the version number of the Movin SDK.
 * @return The version number of the Movin SDK.
 */
+ (unsigned int)getVersion;

/**
 * @brief Returns the version string of the Movin SDK.
 * @return The version string of the Movin SDK.
 */
+ (nonnull NSString*)getVersionString;
@end

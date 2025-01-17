//
// MovinSDKCore.h
// MovinSDK
//
// Copyright © 2017 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MovinCacheProtocol;
@class MovinMap;
@class MovinBeaconScanner;
@class MovinTileStyle;
@class MovinI18N;

/**
 * A list of the Movin services.
 */
typedef NS_OPTIONS(NSUInteger, MovinService) {
    /// No specific service.
            MovinServiceUndefined = (0),
    /// Positioning service.
            MovinServicePositioning = (1 << 0),
    /// (DEPRECATED) Turn by turn service.
            MovinServiceTurnByTurn = (1 << 1),
    /// (DEPRECATED) Proximity service.
            MovinServiceProximity = (1 << 2),
    /// (DEPRECATED) Trigger service.
            MovinServiceTrigger = (1 << 3),
    /// Routing service.
            MovinServiceRouting = (1 << 4),
    /// Data services.
            MovinServiceData = (1 << 5),
};

/**
 * A list of Movin data types which can be cached.
 */
typedef NS_OPTIONS(NSUInteger, MovinCacheableData) {
    /// Data used by the MovinPositioningEngine.
            MovinCacheableDataPositioning = (1 << 0),
    /// Data provided by MovinMap, such as buildings and entities.
            MovinCacheableDataMapData = (1 << 1),
    /// Tiles provided by the MovinTileProvider.
            MovinCacheableDataTiles = (1 << 2),
    /// Images provided by the MovinImageProvider.
            MovinCacheableDataImages = (1 << 3),
    /// (RESERVED) Data used by the routing system.
            MovinCacheableDataRouting = (1 << 4),
    /// Beacon data provided by MovinMap and used by MovinBeaconScanner.
            MovinCacheableDataBeacons = (1 << 5),
    /// Translation information.
            MovinCacheableDataTranslations = (1 << 6),
    /// All cacheable data types.
            MovinCacheableDataAll = (1 << 7) - 1
};

/**
 * Handler for download requests. A value indicating whether the download was successful is provided together with an
 * error value. The error value is set when the success value is NO.
 */
typedef void(^DownloadDataCallback)(BOOL success, NSError* _Nullable error);

/**
 * Handler for server version response.
 */
typedef void(^ServerVersionCallback)(NSString* _Nullable version);

/**
 * Represents the entry point of MovinSDK.
 */
@interface MovinSDK : NSObject

/**
 * Initializes the MovinSDK, which validates the given customer and apikey. The device will be checked for compatibility with Bluetooth Low Energy and some primary components are initialized.
 *
 * @param customer The customer name, provided by Movin
 * @param apikey The API key associated with this customer, either provided by Movin or generated in the Movin portal
 * @param callback The block called once the initialization finished. Provides a boolean whether it has succeeded and if it has not succeeded an NSError containing the error which occurred.
 *
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
 * Sets the hostname for the MovinSDK.
 */
+ (void)setHostName:(nonnull NSString*)hostName;

/**
 * Resets the state of the MovinSDK.
 */
+ (void)reset;

/**
 * Returns the singleton instance of MovinBeaconScanner.
 *
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred. An error may
 * occur if the SDK has not yet been initialized or if bluetooth is not available.
 * @return The singleton instance of MovinBeaconScanner.
 */
+ (nullable MovinBeaconScanner*)getBeaconScanner:(NSError* _Nullable* _Nullable)error;

/**
 * Returns a collection of available maps.
 *
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return A collection of available maps.
 */
+ (nullable NSArray<MovinMap*>*)getMaps:(NSError* _Nullable* _Nullable)error;

/**
 * Returns a MovinMap object with the specified id. If the specified id is not available an error is set.
 *
 * @param id The identifier of the map.
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return A MovinMap object with the specified id. If the specified id is not available an error is set.
 */
+ (nullable MovinMap*)getMapWithId:(nonnull NSString*)id
                          andError:(NSError* _Nullable* _Nullable)error;

/**
 * Returns a collection of available styles.
 *
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return A collection of available styles.
 */
+ (nullable NSArray<MovinTileStyle*>*)getStyles:(NSError* _Nullable* _Nullable)error;

/**
 * Returns a MovinTileStyle object with the specified name. If the specified name is not available an error
 * is set.
 *
 * @param name The name of the style.
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return A MovinTileStyle object with the specified name. If the specified id is not available an error is set.
 */
+ (nullable MovinTileStyle*)getStyleWithName:(nonnull NSString*)name
                                    andError:(NSError* _Nullable* _Nullable)error;

/**
 * Returns a shared MovinI18N object for internationalization of routing and maps.
 *
 * @param error A pointer to a NSError object. This error will be given a value if an error has occurred.
 * @return A shared MovinI18N object.
 */
+ (nullable MovinI18N*)getInternationalizationWithError:(NSError* _Nullable* _Nullable)error;

/**
 * Returns whether or not the MovinSDK has already been initialized or not.
 */
+ (BOOL)isInitialized;

/**
 * Checks if the given service is supported by both the device and apikey rights.
 *
 * @param service The service to check for.
 * @return Whether or not the service is supported.
 */
+ (BOOL)getServiceSupported:(MovinService)service;

/**
 * Clears the cached files stored by the Movin SDK.
 */
+ (void)clearCache;

/**
 * Sets the cache protocol for the specified data types.
 *
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
 * Gets the cache protocol for the specified data type.
 *
 * @return The cache protocol for the specified data type.
 */
+ (nonnull MovinCacheProtocol*)getCacheProtocolForType:(MovinCacheableData)type;

/**
 * Sets a value indicating whether the analytics service should be enabled.
 *
 * @param toggle A value indicating whether the analytics service should be enabled.
 */
+ (void)setAnalyticsEnabled:(BOOL)toggle;

/**
 * Sets a value indicating how many entities will be rendered inside the maps viewport
 * After max has been reached no more entities will be loaded. Be aware of the performance
 * penalty for rendering too many entities at once
 *
 * @param max A value indicating whether the analytics service should be enabled.
 */
+ (void)setMaxEntitiesInViewport:(NSInteger)max;

/**
 * Gets a value indicating how many entities will be rendered inside the maps viewport.
*/
+ (NSInteger)getMaxEntitiesInViewport;

/**
 * Returns the version number of the Movin SDK.
 *
 * @return The version number of the Movin SDK.
 */
+ (unsigned int)getVersion;

/**
 * Returns the version string of the Movin SDK.
 *
 * @return The version string of the Movin SDK.
 */
+ (nonnull NSString*)getVersionString;

/**
 * Gets the version of the server.
 *
 * @param callback The callback called when the version was retrieved.
 */
+ (void)getServerVersionWithCallback:(nonnull ServerVersionCallback)callback;

@end

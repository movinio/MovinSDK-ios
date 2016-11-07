//
// Created by Tim Potze on 05/07/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MovinMap;
@class MovinMapLayer;
@class MovinMapStyle;

/**
 * @class MovinTileManifest
 * @brief Represents the tile manifest.
 */
@interface MovinTileManifest : NSObject
/**
 * @brief Gets the version number of the latest tile package.
 */
@property int version;
/**
 * Gets the map of which this tile manifest represents the tiles.
 */
@property(nullable, readonly, weak) MovinMap* map;
/**
 * @brief Gets the available map layers for the map tiles.
 */
@property(nonnull, readonly) NSDictionary<NSString*, MovinMapLayer*>* layers;
/**
 * @brief Gets the available map styles for the map tiles.
 */
@property(nonnull, readonly) NSDictionary<NSString*, MovinMapStyle*>* styles;

/**
 * @brief Gets the default layer.
 */
@property(nonnull, readonly) MovinMapLayer* defaultLayer;

/**
 * @brief Gets the default style.
 */
@property(nonnull, readonly) MovinMapStyle* defaultStyle;

/**
 * @brief Initializes a new MovinTileManifest object with the specified version, map, layers and styles.
 * @param version The version number of the latest tile package.
 * @param map The map of which the tile manifest represents the tiles.
 * @param layers The available map layers.
 * @param styles The available map styles.
 * @return A MovinTileManifest object with the specified version, map, layers and styles.
 */
- (nonnull id)initWithVersion:(int)version
               andMap:(nonnull MovinMap*)map
            andLayers:(nonnull NSDictionary<NSString*, MovinMapLayer*>*)layers
            andStyles:(nonnull NSDictionary<NSString*, MovinMapStyle*>*)styles;
@end
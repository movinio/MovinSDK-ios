//
// Created by Tim Potze on 02/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GeoShape.h"

@class GeoLatLng;

/**
 * @class GeoMultiPoint
 * @brief Represents a collection of geographical points.
 */
@interface GeoMultiPoint : GeoShape
/**
 * @brief Contains the points of this collection.
 */
@property(readonly, nonnull) NSArray<GeoLatLng*>* points;

/**
 * @brief Initializes a GeoMultiPoint with the specified points.
 * @param points The points to initialize the collection with.
 * @return A GeoMultiPoint object containing the specified collection of points.
 */
- (nonnull id)initWithPoints:(nonnull NSArray<GeoLatLng*>*)points;

/**
 * @brief Returns a value indicating whether this instance and the specified GeoMultiPoint.
 * @param multiPoint The other GeoMultiPoint.
 * @return YES if the values are equal, NO otherwise.
 */
- (BOOL)isEqualToMultiPoint:(nonnull GeoMultiPoint*)multiPoint;
@end
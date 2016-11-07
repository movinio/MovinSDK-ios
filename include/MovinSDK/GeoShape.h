//
// Created by Tim Potze on 08/03/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GeoLineString;
@class GeoAABB;
@class GeoLatLng;

/**
 * @class GeoShape
 * @brief Represents a geographical shape.
 */
@interface GeoShape : NSObject <NSCopying>
/**
 * @brief Gets the bounding box which fits around this instance.
 */
@property(readonly, nonnull) GeoAABB* boundingBox;

/**
 * @brief Gets the lines which define this shape. These lines will be used to check for intersections with
 * other shapes.
 */
- (nullable NSArray<GeoLineString*>*)linesForIntersect;

/**
 * @brief Gets the points which define this shape. These points will be used to check for intersections with
 * other shapes.
 */
- (nullable NSArray<GeoLatLng*>*)pointsForIntersect;

/**
 * @brief Returns a value indicating whether the specified shape intersects with this instance.
 * @param shape The shape to check with.
 * @return YES if the shape intersects with this instance; NO otherwise.
 */
- (BOOL)intersectsWithShape:(nonnull GeoShape*)shape;

/**
 * @brief Returns a value indicating whether the specified point is located within the boundaries of this shape.
 * @param point The point for which to check whether it's inside the boundaries of this shape.
 * @return YES if the point is located within the boundaries of this shape; NO otherwise.
 */
- (BOOL)containsPoint:(nonnull GeoLatLng*)point;

/**
 * @brief Returns a value indicating whether the specified shape is completely encased within the boundaries of this shape.
 * @param shape The shape for which to check whether it's inside the boundaries of this shape.
 * @return YES if the shape is located within the boundaries of this shape; NO otherwise.
 */
- (BOOL)containsShape:(nonnull GeoShape*)shape;

/**
 * @brief Returns a value indicating whether the specified line intersects with this shape.
 * @param start The starting point of the line.
 * @param end The end point of the line.
 * @return YES if the line intersects with this shape; NO otherwise.
 */
- (BOOL)intersectsWithLineFrom:(nonnull GeoLatLng*)start
                            to:(nonnull GeoLatLng*)end;
@end
//
// Created by Tim Potze on 26/09/16.
// Copyright (c) 2016 Movin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MovinDataObject.h"

@class MovinTileStyleRule;
@class MovinEntitySubType;
@class MovinTileStyle;

/**
 * @class MovinTileStyleLayer
 * @brief Represents a single layer in a tile style.
 */
@interface MovinTileStyleLayer : MovinDataObject
/**
 * @brief Gets the sub type this layer contains the rules of.
 */
@property(readonly) MovinEntitySubType* subType;
/**
 * @brief Gets the rules associated with this layer.
 */
@property(readonly) NSArray<MovinTileStyleRule*>* rules;
@end
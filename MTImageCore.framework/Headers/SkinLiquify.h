//
//  SkinLiquify.h
//  MTDSP
//
//  Created by  on 12-5-31.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface SkinLiquify : NSObject

//半径
- (void) setRadius:(int) nRadius;

/*
 *  设置力度
 *  当处理函数的type为0时，即眼睛放大的时候，nIntensity小于0为缩小，大于0为放大
 */
- (void) setIntensity:(int) nIntensity;

//初始化图片数据
- (void) setImage:(unsigned char*) pData
            width:(int) width
           height:(int) height;
- (void) setOralImage:(unsigned char*) pOralData
            destImage:(unsigned char*) pDestData
                width:(int) width
               height:(int) height;

/*  处理函数
 *  nType为0为眼睛放大，2为瘦脸瘦身
 *  pValues为四个值，第一个和第二个为起始点的百分比，第三个和第四个为终点的百分比
 */
- (void) procImageType:(int) nType
                values:(CGFloat*) pValues;
@end

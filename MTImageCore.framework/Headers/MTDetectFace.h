//
//  MTDetectFace.h
//  MTDSP
//
//  Created by aidy on 13-10-23.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreImage/CoreImage.h>
#import "MTFaceFeature.h"
@interface MTDetectFace : NSObject
//设置检测的类型   nDetectMode为0表示实时检测，1表示low，2表示high
- (void) setDetectMode:(int) nDetectMode;
//进行人脸检测，返回MTFaceFeature的数组，y有进行变换
- (NSArray *)featuresInImage:(UIImage *)pImage;
//根据方向进行人脸检测，y没有进行变换
- (NSArray *)featuresInImage:(CIImage *)image options:(NSDictionary *)options;
//最大的脸
- (CGRect) faceRect;
//最大脸的左眼位置
- (CGPoint) leftEye;
//最大脸的右眼位置
- (CGPoint) rightEye;
//最大脸的嘴巴位置
- (CGPoint) mouth;

@end



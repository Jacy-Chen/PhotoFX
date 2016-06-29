//
//  FaceDetectorAndSkin.h
//  MYXJ
//
//  Created by aidy on 12-11-6.
//  Copyright (c) 2012年 Meitu. All rights reserved.
//  自动瘦脸瘦身与皮肤优化的方案处理

#import <Foundation/Foundation.h>
#import <CoreImage/CoreImage.h>
#import <UIKit/UIKit.h>
#import "MTFacePPDetect.h"
@interface FaceDetectorAndSkin : NSObject
{

}

//初始化图片数据并根据bIsAuto来确定是否进行瘦脸瘦身
- (UIImage*) FaceSkinInitImageData:(UIImage*) aImage isAutoSlimAndZoomEye:(BOOL) bIsAuto;
/*
 *  bIsAuto YES为自动瘦脸，NO为不自动瘦脸
 *  bIsAutoFleckCleaner YES为自动祛痘祛斑，NO为不自动祛痘祛斑
 *  fAlpha为高级色的透明度，默认为0.5，范围是0.0-1.0之间
 */
- (UIImage*) FaceSkinInitImageData:(UIImage*) aImage
              isAutoSlimAndZoomEye:(BOOL) bIsAuto
                isAutoFleckCleaner:(BOOL) bIsAutoFleckCleaner
                             alpha:(float) fAlpha;


- (unsigned char*) getImageData;
//释放内存
- (void) ReleaseMemory;
//美肤处理
-(unsigned char*) skinProcess:(BOOL) isNight
             isRemoveBlackEye:(BOOL) isRemoveBlackEye
                 isAdjustTune:(BOOL) isAdjustTune
               isMouthProcess:(BOOL) isMouthProcess;
//- (UIImage*) imageProcWithSkin;
/*
 *  美肤处理，增加夜间拍照模式的接口
 *  isNight为YES表示开启夜间模式，为NO表示关闭夜间模式
 *  isRemoveBlackEye为YES表示开启消除黑眼圈
 *  fAlpha为美颜的透明度
 *  colorAlpha为调色的透明度
 *  isProcessNose为是否鼻子高光处理
 *  isAdjustTune为YES表示开启高级色
 *  isMouthProcess为YES表示开启润唇
 *  isHaveBokeh为YES表示开启虚化功能
 *  isMouthProcess为YES表示开启润唇功能，NO表示关闭润唇功能
 *  realFaceRect为实时虚化得到的最大的人脸区域，如果是导入图片的话，则传递CGRectZero
 */

- (UIImage*) imageProcWithSkin:(BOOL) isNight
              isRemoveBlackEye:(BOOL) isRemoveBlackEye
                         alpha:(CGFloat) fAlpha
                 isProcessNose:(BOOL) isProcessNose
                  isAdjustTune:(BOOL) isAdjustTune
                isMouthProcess:(BOOL) isMouthProcess
                   isHaveBokeh:(BOOL) isHaveBokeh
                  realFaceRect:(CGRect) realFaceRect;

- (UIImage*) imageProcWithSkin:(BOOL) isNight
              isRemoveBlackEye:(BOOL) isRemoveBlackEye
                         alpha:(CGFloat) fAlpha
                    colorAlpha:(CGFloat)colorAlpha
                 isProcessNose:(BOOL) isProcessNose
                  isAdjustTune:(BOOL) isAdjustTune
                isMouthProcess:(BOOL) isMouthProcess
                   isHaveBokeh:(BOOL) isHaveBokeh
                  realFaceRect:(CGRect) realFaceRect;

- (UIImage*) FaceSkinInitImageDataWithImage:(UIImage*) aImage
                                     detect:(MTFacePPDetect*) detect
                       isAutoSlimAndZoomEye:(BOOL) bIsAuto
                         isAutoFleckCleaner:(BOOL) bIsAutoFleckCleaner
                                      alpha:(float)fAlpha;
- (int) getFaceAvgColorGray;

@end

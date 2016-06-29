//
//  MTFacePPDetect.h
//  MTDSP
//
//  Created by aidy on 13-10-23.
//
//  系统的和face++的人脸检测+39个点

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "faceppapi.h"


@interface MTFacePPDetect : NSObject
//进行单个人脸检测+39个点的，模拟器没有39个点
- (int) detect:(UIImage*) image;
//进行nMaxFace个人脸检测+39个点的，模拟器没有39个点
- (int) detect:(UIImage*) image
       maxFace:(int) nMaxFace;
//手动设置人脸区域
- (void) setDetectImage:(UIImage*) aImage
               faceRect:(CGRect) faceRect;
//获取最大脸
- (CGRect) faceRect;
- (CGPoint) leftEye;
- (CGPoint) rightEye;
- (CGPoint) mouth;
- (NSMutableArray*) landmarksArray;
- (void) landmarks:(CGPoint*) pts;

- (void) get83Point:(CGPoint*) pts;
- (void) set83Point:(CGPoint*) pts;
- (void) get83Point:(CGPoint*) pts faceIndex:(int)nIndex;
- (void) set83Point:(CGPoint*) pts faceIndex:(int)nIndex;
//格式为0x,0y,1x,1y,2x,2y,3x,3y......82x,82y
- (NSString*) stringWith83Point;


- (CGRect) getFaceMaxRect;
- (NSMutableArray*) getAllFaceRect;

- (void) GetFaceInfo:(FACEPP_FACEINFO*) faceInfo;
- (int) faceCount;
- (int) GetFaceMaxRectIndex;
- (void) getAllFacePoint:(CGPoint*) pts;
/*
 *  美妆校正眉毛的点
 */
- (void) MakingUpAdjustEyeBrowPoint;

- (void) getFaceAllInfo:(CGPoint*) pts
                 nIndex:(int) nIndex;
@end



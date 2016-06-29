//
//  ImagePublic.h


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#define MT_ALPHALOCATION kCGImageAlphaPremultipliedFirst//ARGB

@interface UIImage (ImageData)


/************************************
 *UIImage数据转换
 ***********************************/
//UIImage to ARGB
- (unsigned char*) ARGBData;

//ARGB to UIImage
+ (UIImage*) imageWithARGBData:(unsigned char*) data withSize:(CGSize) size;
+ (UIImage*) imageWithARGBData:(unsigned char*)data withWidth:(int) width withHeight:(int) height;

//RGBA to UIImage
+ (UIImage*) imageWithRGBAData:(unsigned char*) data withSize:(CGSize) size;
+ (UIImage*) imageWithRGBAData:(unsigned char*)data withWidth:(int) width withHeight:(int) height;



- (UIImage*) imageWithWidth:(CGFloat) width withHeight:(CGFloat) height;

//根据比例来放缩图片
- (UIImage*) imageWithScale:(CGFloat) scale;
- (UIImage*) imageWithScaleWidth:(CGFloat) scaleWidth withScaleHeight:(CGFloat) scaleHeight;
//限制最长边的大小为nMaxLen
- (UIImage*) imageWithMaxLength:(int) nMaxLen;
//限制最长边的大小为nMaxLen
- (UIImage*) imageWithMaxLength:(int) nMaxLen withUIImageOrientation:(UIImageOrientation)imageOrientation;
- (UIImage*) imageWithScaleWidth:(CGFloat) scaleWidth withScaleHeight:(CGFloat) scaleHeight withUIImageOrientation:(UIImageOrientation)imageOrientation;

#pragma mark 1:1
//1:1裁剪
- (UIImage*) imageWithSquare;
- (UIImage*) imageWithSquareWithUIImageOrientation:(UIImageOrientation)imageOrientation;
//图片和裁剪区域都根据方向来校正
- (UIImage*) imageWithSquareAndRotationWithUIImageOrientation:(UIImageOrientation)imageOrientation withOffset:(CGFloat) fOffset;
//图片为正的，裁剪区域根据传递方向校正
- (UIImage*) imageWithSquareWithUIImageOrientation:(UIImageOrientation)imageOrientation withOffset:(CGFloat) fOffset;



#pragma mark 缩略图

- (UIImage*) thumbnailWithSize:(CGSize)size withIsCut:(BOOL)bCut;
#pragma mark 正常叠加模式
- (UIImage*) blendWithImage:(UIImage*) blendImage alpha:(CGFloat) alpha;
- (UIImage*) blendWithImage:(UIImage*) blendImage rect:(CGRect) rect;





@end

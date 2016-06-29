//
//  UIImage+Process.h


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ImageCore.h"
#import "UIImage+ImageData.h"
#import "FaceDetectorAndSkin.h"

@interface UIImage (Process)




/*
 *  裁剪
 *  rectCut为裁剪的区域
 */
- (UIImage*) processWithCut:(CGRect) rectCut;

/*
 *  旋转
 * 
 */
- (UIImage*) processWithRotationUpAndDown;
- (UIImage*) processWithRotationLeftAndRight;
- (UIImage*) processWithRotationClockLeft;//逆时针旋转
- (UIImage*) processWithRotationClockRight;//顺时针旋转
/*  调色
 *
 *  pValues第一个为brightValue亮度值，第二个为contrastValue对比度值，第三个为saturateconst饱和度
 *  如果有第四个参数则是曝光度的值
 *  nValueCount为pValues的参数个数
 */
- (UIImage*) processWithColorMixing:(CGFloat*) pValues
                         valueCount:(int) nValueCount;

/*  特效
 *
 *  nIndex为特效的编号,在plist里显示
 */
- (UIImage*) processWithStylize:(int) nIndex;

- (UIImage*) processWithStylize:(int) nIndex withAlpha:(CGFloat) fAlpha;




/*  美容
 *
 *  strSavePath为保存的临时文件路径
 *  pValues第一个参数为模糊半径，第二个参数为透明度，第三个参数为美白的index值，第四个参数为肤色的index值
 */
- (UIImage*) processWithSkinValues:(CGFloat*) pValues withSavePath:(NSString*) strSavePath;

- (UIImage*) ImageProcessWithMYXJSkin:(CGFloat*) pValues
                         withSavePath:(NSString*) strSavePath
                       withSkinObject:(FaceDetectorAndSkin*)pObject;

/*
 *  美容算法（使用自拍的算法）
 *  fSkinAlpha为自拍算法的透明度，范围从0.0-1.0
 *
 */
- (UIImage*) ImageProcessWithSelfieSkin:(CGFloat)fSkinAlpha;

/*
 *  肤色调整
 *  nSkinColorValue 参数范围为[0.0，1.0]，默认为0.5
 *  nWhitenValue    参数范围为[0,10]，默认为0
 *
 */
- (UIImage*) ImageProcessWithSkinColor:(CGFloat) nSkinColorValue
                             whitening:(CGFloat) nWhitenValue;


/*  锐化
 *
 *  depth为锐化度，pGaussData为高斯模糊的数据
 */
- (UIImage*) processWithSharp:(CGFloat) depth gaussData:(unsigned char**) pGaussData;

- (UIImage*) processWithSharp:(CGFloat)depth;

/*  高斯模糊
 *
 *  nBlurLength为高斯模糊的半径
 */
- (UIImage*) processWithGaussBlur:(int) nBlurLength;


/*  睫毛膏
 *  pValues第一个参数为模糊半径，第二个参数为力度（0-10），默认为5
 */
- (UIImage*) processWithMascara:(CGFloat*)pValues;

/*
 *  马赛克算法   2.3.0版本添加
 *  nBlock马赛克的块
 *  
 */
- (UIImage*) processWithMosaic:(int) nBlock ;
- (UIImage*) processWithMosaic:(int) nBlock texture:(UIImage*) pTextureImage;


/*
 *  绘制，alpha层的混合
 */
- (UIImage*) processWithNormal:(UIImage*) pUpImage
                         alpha:(CGFloat) fAlpha;

/*
 *  根据人脸框返回图像的平均颜色
 *  返回四个参数，参数1为是否有人脸，1表示有人脸，0表示无人脸；参数2为红色通道的平均色；参数3为绿色通道的平均色；参数4为蓝色通道的平均色
 */
- (int*) processWithAverageColorWithFaceRect:(CGRect) rectFace;
@end

/*
 *
 *
 */




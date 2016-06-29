//
//  ImageCore.h


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ImageCore : NSObject
#pragma mark 调色
/*  调色，调整亮度、对比度、饱和度、曝光度
 *
 *  pValues:
 *  第一个为brightValue亮度值[-100,100]
 *  第二个为contrastValue对比度值[-100,100]
 *  第三个为saturateconst饱和度[-50,50]
 *  第四个参数为曝光度[-100,100]
 */
+ (void) ImageProcessWithColorMixing:(unsigned char*) pData
                               width:(int) width
                              height:(int) height
                              values:(CGFloat*) pValues
                          valueCount:(int) nValueCount;
#pragma mark 特效
/*  特效
 *  nIndex为特效的ID编号，详细见特效编号文档
 *  fAlpha为特效的透明度[0.0,1.0]
 */
+ (void) ImageProcessWithStylize:(unsigned char*) pData
                           width:(int) width
                          height:(int) height
                           index:(int) nIndex;

+ (void) ImageProcessWithStylize:(unsigned char*) pData
                           width:(int) width
                          height:(int) height
                           index:(int) nIndex
                           alpha:(CGFloat) fAlpha;
#pragma mark 美容
/*  美容
 *
 *  strSavePath为保存的临时文件路径
 *  pValues第一个参数为磨皮的模糊半径(默认12)，第二个参数为磨皮的透明度，
 *  第三个参数为美白的index值，第四个参数为肤色的index值
 *  第五个参数为自然美肤的高斯模糊半径2.0.1版本添加
 */
+ (void) ImageProcessWithSkin:(unsigned char*) pData
                        width:(int) width
                       height:(int) height
                     savePath:(NSString*) strSavePath
                       values:(CGFloat*) pValues;

/*
 *  磨皮功能的效果
 *
 */
+ (void) ImageProcessWithSelfieSkin:(unsigned char*) pData
                              width:(int) nWidth
                             height:(int) nHeight
                          skinAlpha:(CGFloat)fSkinAlpha;
/*
 *  自然美肤    2.0.1版本添加
 *  nRadius为高斯模糊的半径
 *
 */
+ (void) ImageProcessWithNatureSmooth:(unsigned char*) pData
                                width:(int)nWidth
                               height:(int)nHeight
                               radius:(int) nRadius;
#pragma mark 肤色
/*
 *  肤色调整+美白
 *  nSkinColorValue范围为0.0-1.0，默认为0.5
 *  nWhitenValue范围为0-10，默认为5
 */
+ (void) ImageProcessWithSkinColor:(unsigned char*) pData
                             width:(int) nWidth
                            height:(int) nHeight
                         skinColor:(float) nSkinColorValue
                         whitening:(float) nWhitenValue;
#pragma mark 锐化
/*  锐化
 *
 *  depth为锐化的数量[0.0,1.0]，pDataSharp为高斯模糊的数据
 */
+ (void) ImageProcessWithSharp:(unsigned char*) pData
                         width:(int) width
                        height:(int) height
                         depth:(CGFloat)depth
                     gaussData:(unsigned char**) pGaussData;

+ (void) ImageProcessWithSharp:(unsigned char*) pData
                         width:(int) width
                        height:(int) height
                         depth:(CGFloat)depth;
/*  锐化的模糊
 *
 */
+ (void) ImageProcessWithSharpGaussBlur:(unsigned char*) pData
                                  width:(int) width
                                 height:(int) height;
#pragma mark 高斯模糊
/*  高斯模糊
 *
 *  nRadius为高斯模糊的半径
 */
+ (void) ImageProcessWithGaussBlur:(unsigned char*) pData
                             width:(int) width
                            height:(int) height
                            radius:(int) nRadius;

/*  stack模糊
 *
 *  radius为半径
 */
+ (void) ImageProcessWithStackBlur:(unsigned char *)pData 
                             width:(int)width 
                            height:(int)height 
                            radius:(int)radius;
#pragma mark 祛痘祛斑
/*  祛痘祛斑
 *
 *  pData为图片的ARGB数据
 *  pMaskData为mask层，需要改变的区域为有颜色的，而不需要改变的都为0
 */
+ (void) ImageProcessWithInpaint:(unsigned char*) pData
                           width:(int) width
                          height:(int) height
                            mask:(unsigned char*) pMaskData;
/*  自动祛痘祛斑
 *
 *  pData为图片的ARGB数据
 *  rectFace为识别到的人脸的区域
 */
/*
 + (void) ImageProcessWithAutoInpaint:(unsigned char*) pData
 width:(int) width
 height:(int) height
 rectFace:(CGRect) rectFace;
 */
+ (void) ImageProcessWithAutoInpaint:(unsigned char*) pData
                               width:(int) width
                              height:(int) height
                            rectFace:(CGRect) rectFace
                           landmarks:(NSMutableArray*) landmarksArray;
#pragma mark 消除黑眼圈
/*  消除黑圆圈
 *  pMaskData为涂抹的区域的数据
 *  pValues第一个参数和第二个参数为涂抹区域在图片的起点nx,ny/
 *  第三个参数和第四个参数为涂抹区域的宽和高
 */
+ (void) ImageProcessWithRemoveBlackCircle:(unsigned char*) pData
                                     width:(int)nWidth
                                    height:(int)nHeight
                                      mask:(unsigned char*) pMaskData
                                    values:(CGFloat*)pValues;
/*
 *  自动消除黑圆圈
 *  rectFace    人脸区域
 *  ptLeftEye   左眼
 *  ptRightEye  右眼
 *  fMixAlpha   混合的百分比
 */
+ (void) ImageProcessWithAutoRemoveBlackCircle:(unsigned char *)pData
                                         width:(int)nWidth
                                        height:(int)nHeight
                                      faceRect:(CGRect)rectFace
                                     landmarks:(NSMutableArray*) landmarksArray
                                         alpha:(CGFloat) fMixAlpha;
+ (void) ImageProcessWithAutoRemoveBlackCircle:(unsigned char *)pData
                                         width:(int)nWidth
                                        height:(int)nHeight
                                      faceRect:(CGRect)rectFace
                                    interPoint:(void*) pInterPoint
                                         alpha:(CGFloat) fMixAlpha;
#pragma mark 亮眼
/*  睫毛膏
 *  pValues第一个参数为模糊半径，第二个参数为力度（0-10），默认为5
 */
+ (void) ImageProcessWithMascara:(unsigned char *)pData 
                           width:(int)width 
                          height:(int)height
                          values:(CGFloat*)pValues;
/*  涂抹混合
 *  pMaskData为涂抹的区域的数据
 *  pValues第一个参数和第二个参数为涂抹区域在图片的起点nx,ny/
 *  第三个参数和第四个参数为涂抹区域的宽和高
 *  第五个参数为羽化半径,第六个参数为混合的百分比
 */
+ (void) ImageProcessWithAlphaMix:(unsigned char*) pOralData
                            width:(int)nWidth
                           height:(int)nHeight
                          mixData:(unsigned char*) pMixData
                             mask:(unsigned char*) pMaskData
                           values:(CGFloat*)pValues;

/*
 *  自动亮眼功能
 *  rectFace    人脸区域
 *  ptLeftEye   左眼
 *  ptRightEye  右眼
 *  fMixAlpha   混合的百分比
 */
+ (void) ImageProcessWithAutoMascara:(unsigned char *)pData
                               width:(int)nWidth
                              height:(int)nHeight
                            faceRect:(CGRect)rectFace
                             leftEye:(CGPoint)ptLeftEye
                            rightEye:(CGPoint)ptRightEye
                               alpha:(CGFloat) fMixAlpha;

+ (void) ImageProcessWithAutoMascara:(unsigned char *)pData
                               width:(int)nWidth
                              height:(int)nHeight
                           landmarks:(NSMutableArray*) landmarksArray
                               alpha:(CGFloat) fMixAlpha;
+ (void) ImageProcessWithAutoMascara:(unsigned char *)pData
                               width:(int)nWidth
                              height:(int)nHeight
                          interPoint:(void*) pInterPoint
                               alpha:(CGFloat) fMixAlpha;

#pragma mark 马赛克
/*
 *  马赛克算法   2.3.0版本添加
 *  nBlock马赛克的块
 *  
 */
+ (void) ImageProcessWithMosaic:(unsigned char*) pData
                          width:(int) nWidth
                         height:(int) nHeight
                          block:(int) nBlock;
#pragma mark 实时测光
/*
 *  实时测光
 *  faceRect为人脸的区域
 *  返回检测到的平均亮度阈值
 */
+ (unsigned char) ImageProcessWithAverageThread:(unsigned char*) pData
                                          width:(int)nWidth
                                         height:(int)nHeight
                                       faceRect:(CGRect) faceRect;

#pragma mark 眼睛放大
/*
 *  自动眼睛放大算法
 *  faceRect    人脸的区域
 *  ptLeftEye   左眼的点
 *  ptRightEye  右眼的点
 *  fMixAlpha   透明度
 *  strAutoZoomEyeFile  眼睛放大的配置文件
 *  landmarksArray 为人脸的关键点
 *  fMixAlpha为透明度值[0.0，1.0]
 */
+ (void) ImageProcessWithAutoZoomEyes:(unsigned char*) pDestData
                              srcData:(unsigned char*) pSrcData
                                width:(int) nWidth
                               height:(int) nHeight
                             faceRect:(CGRect) faceRect
                              leftEye:(CGPoint) ptLeftEye
                             rightEye:(CGPoint) ptRightEye
                                alpha:(CGFloat) fMixAlpha
                             filePath:(NSString*) strAutoZoomEyeFile;

+ (void) ImageProcessWithAutoZoomEyes:(unsigned char*) pDestData
                                width:(int) nWidth
                               height:(int) nHeight
                            landmarks:(NSMutableArray*) landmarksArray
                                alpha:(CGFloat) fMixAlpha;
+ (void) ImageProcessWithAutoZoomEyes:(unsigned char*) pDestData
                                width:(int) nWidth
                               height:(int) nHeight
                           interPoint:(void*) pInterPoint
                                alpha:(CGFloat) fMixAlpha;
#pragma mark 瘦脸
/*
 *  自动瘦脸瘦身算法
 *  faceRect    人脸的区域
 *  fMixAlpha   透明度
 *  strAutoSlimFile 瘦脸瘦身的配置文件
 *  landmarksArray 为人脸的关键点
 *  fMixAlpha为透明度值[0.0，1.0]
 */
+ (void) ImageProcessWithAutoSlim:(unsigned char*) pDestData
                          srcData:(unsigned char*) pSrcData
                            width:(int) nWidth
                           height:(int) nHeight
                         faceRect:(CGRect) faceRect
                            alpha:(CGFloat) fMixAlpha
                         filePath:(NSString*) strAutoSlimFile;

+ (void) ImageProcessWithAutoSlim:(unsigned char*) pDestData
                            width:(int) nWidth
                           height:(int) nHeight
                        landmarks:(NSMutableArray*) landmarksArray
                            alpha:(CGFloat) fMixAlpha;
+ (void) ImageProcessWithAutoSlim:(unsigned char*) pDestData
                            width:(int) nWidth
                           height:(int) nHeight
                       interPoint:(void*) pInterPoint
                            alpha:(CGFloat) fMixAlpha;
#pragma mark 美白牙齿
/*
 *  美白牙齿
 *  landmarksArray为face++83点
 *  fMixAlpha参数范围0.0-1.0，默认为0.4f
 */
+ (void) ImageProcessWithTeethWhite:(unsigned char*) pDestData
                              width:(int) nWidth
                             height:(int) nHeight
                          landmarks:(NSMutableArray*) landmarksArray
                              alpha:(CGFloat) fMixAlpha;
+ (void) ImageProcessWithTeethWhite:(unsigned char*) pData
                              width:(int) width
                             height:(int) height
                         interPoint:(void*) pInterPoint
                              alpha:(float) fMixAlpha;
#pragma mark 去噪
/*
 *  多图去噪
 *  _images为图片jpeg数据
 *
 */
+ (UIImage*) ImageProcessWithWswe123dfsliels:(NSArray*) _images;


#pragma mark
#pragma mark 混合模式
/*
 *  根据mask来做正常混合
 *  pResultData为上层图像数据，大小为宽x高x4
 *  pOralData为下层图像数据，大小为宽x高x4
 *  pMaskData为透明度图像数据，大小为宽x高
 */
+ (void) ImageProcessWithNormal:(unsigned char*) pResultData
                       oralData:(unsigned char*) pOralData
                       maskData:(unsigned char*) pMaskData
                          width:(int) nWidth
                         height:(int) nHeight;
/*
 *  根据mask来做正常混合
 *  pResultData为上层图像数据，大小为宽x高x4
 *  pOralData为下层图像数据，大小为宽x高x4
 *  pMaskData为透明度图像数据，大小为宽x高x4
 */
+ (void) ImageProcessWithNormal:(unsigned char*) pResultData
                       oralData:(unsigned char*) pOralData
                      mask4Data:(unsigned char*) pMask4Data
                          width:(int) nWidth
                         height:(int) nHeight;
+ (void) ImageProcessWithNormal:(unsigned char*) pResultData
                       oralData:(unsigned char*) pOralData
                          width:(int) nWidth
                         height:(int) nHeight
                          alpha:(float) fMixingAlpha;
#pragma mark
#pragma mark 各种mask

/*
 *  获取皮肤的mask
 *  pMaskData为图片的肤色mask，大小为宽x高
 *  pOralData为图片的原始数据，大小为宽x高x4
 *  faceRect为人脸的区域
 *
 */
+ (void) ImageProcessWithSkinMask:(unsigned char*) pMaskData
                         oralData:(unsigned char*) pOralData
                            width:(int) nWidth
                           height:(int) nHeight
                         faceRect:(CGRect) faceRect;

/*
 *  获取脸部mask，去掉眼镜、眉毛和嘴巴外的整个图片mask,nBlurRadius为模糊的半径，landmarksArray为83个关键点，isFlip为YES，上下翻转
 */
+ (void) ImageProcessWithCalEyeMouthEyeBrowMask:(unsigned char*) pMaskData
                                          width:(int) nWidth
                                         height:(int) nHeight
                                     blurRadius:(int) nBlurRadius
                               landmarks83Array:(NSMutableArray*) landmarksArray;

+ (void) ImageProcessWithCalEyeMouthEyeBrowMask:(unsigned char*) pMaskData
                                          width:(int) nWidth
                                         height:(int) nHeight
                                     blurRadius:(int) nBlurRadius
                               landmarks83Array:(NSMutableArray*) landmarksArray
                                         isFlip:(BOOL) isFlip;

@end

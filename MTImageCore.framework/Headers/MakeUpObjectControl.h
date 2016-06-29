



#import <UIKit/UIKit.h>

@interface MakeUpObjectControl : NSObject {

}

/*
 *  释放所有对象的内存
 */
- (void) releaseMakeUpObjectControl;
/*
 *  释放GL的内存
 */
- (void) clear;
/*
 *  检测是否有人脸，0为没有人脸
 */
- (int) detectImage:(UIImage*) image;
/*
 *  设置人脸的位置
 */
- (void) setDetectImage:(UIImage*) aImage
                leftEye:(CGPoint) leftEye
               rightEye:(CGPoint) rightEye
                  mouth:(CGPoint) mouth;
/*
 *  获取人脸的点的数据，用于传递给服务器
 */
- (NSString*) stringWith83Point;
/*
 *  初始化图片
 *  isSlim              是否瘦脸和眼睛放大
 *  isRemoveBlackEye    是否消除黑眼圈
 *  isBokehProcess      是否背景虚化
 */
- (void) setImage:(UIImage*) image
           isSlim:(BOOL) isSlim
   isBokehProcess:(BOOL) isBokehProcess;

/*
 *  获取化妆后的图片
 *  nBeautyAlpha[0,100],nMakingUpAlpha[0,100]
 */
- (UIImage*) processWithBeautyAlpha:(int) nBeautyAlpha
                      makingUpAlpha:(int) nMakingUpAlpha;
/*
 *  获取微调后点后的效果
 */
- (UIImage*) processWithBeautyPointManage;
/*
 *  设置化妆的配置文件和素材包的路径
 */
- (int) setMakingUpDictionary:(NSDictionary*) dict path:(NSString*) strPacketPath;
/*
 *  设置face++的83个点
 */
//- (void) set83LandmarkPoint:(NSDictionary*) dict;


/*
 *  设置调整完的83点
 */
- (void) set83LandmarkPoint:(CGPoint*) ptLandmarks faceIndex:(int)nIndex;
- (void) get83LandmarkPoint:(CGPoint*) ptLandmarks faceIndex:(int)nIndex;

/*
 *  最大人脸占图片的百分比
 */
- (CGRect) getFaceMaxRect;

/*
 *  是否暗环境,是返回YES,否则返回NO
 */
- (BOOL) isLowLight;
@end



//
//  ToolCosmeticSelector.h
//  MTDSP
//
//  Created by aidy on 13-10-22.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface ToolCosmeticSelector : NSObject
//初始化
- (id) initWithImage:(UIImage*) aImage;

/*
 *  执行效果
 *	eLevel
 *  0:不处理
 *  1:极度
 *  2:普通
 *  3:轻度
 *
 *  eFilter
 *  0:
 *  1:红润
 *  2:梦幻
 *  3:甜美
 *  4:白皙
 *  5:自然
 *  6:柔嫩
 *  7:阳光
 *  8:清新
 *  9:清晰
 *  10:暖暖
 *  11:冷艳
 *  12:紫色
 *  13:清茶
 *  14:微光
 */
- (UIImage*) run:(UIImage*) aImage
      eLevelType:(int) eLevel
     eFilterType:(int) eFilter;
@end

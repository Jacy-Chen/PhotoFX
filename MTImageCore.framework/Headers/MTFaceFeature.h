//
//  MTFaceFeature.h
//  MTDSP
//
//  Created by aidy on 13-10-23.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface MTFaceFeature : NSObject
{
	CGRect bounds;
	BOOL hasLeftEyePosition;
	CGPoint leftEyePosition;
	BOOL hasRightEyePosition;
	CGPoint rightEyePosition;
    BOOL hasMouthPosition;
	CGPoint mouthPosition;
}
@property (assign, nonatomic) CGRect bounds;
@property (assign, nonatomic) BOOL hasLeftEyePosition;
@property (assign, nonatomic) CGPoint leftEyePosition;
@property (assign, nonatomic) BOOL hasRightEyePosition;
@property (assign, nonatomic) CGPoint rightEyePosition;
@property (assign, nonatomic) BOOL hasMouthPosition;
@property (assign, nonatomic) CGPoint mouthPosition;
@end

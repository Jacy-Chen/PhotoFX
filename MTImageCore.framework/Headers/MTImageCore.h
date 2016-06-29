
#ifndef MTIMAGE_Core_H
#define MTIMAGE_Core_H

#define     MYXJ_VERSION         "3.5.0"



#import "ImageCore.h"
#import "UIImage+ImageData.h"
#import "UIImage+Process.h"
#import "ToolCosmeticSelector.h"

#import "SkinLiquify.h"
#import "FaceDetectorAndSkin.h"
#import "MTFacePPDetect.h"


#undef IOS_SAFE_DELETE_ARRAY
#define IOS_SAFE_DELETE_ARRAY(x) if((x)!=NULL){delete[] (x); (x)=NULL;}

#define IOS_MT_ALPHA	0
#define IOS_MT_RED		1
#define IOS_MT_GREEN	2
#define IOS_MT_BLUE     3
#endif
/*
 *
 *
 */
//
//  ViewController.h
//  photoFX
//
//  Created by Zexi Chen on 10/14/15.
//  Copyright © 2015 Jacy Chen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Parse/Parse.h>
//#import <MTImageCore/ToolCosmeticSelector.h>


@interface ViewController : UIViewController <UINavigationBarDelegate, UINavigationControllerDelegate,  UIImagePickerControllerDelegate, UIActionSheetDelegate>{
    
    UIImage *originImage;
}

@property(nonatomic, weak) IBOutlet UIImageView *selectedImageView;
@property(nonatomic, weak) IBOutlet UIBarButtonItem *filterButton;
@property(nonatomic, weak) IBOutlet UIBarButtonItem *saveButton;

- (IBAction)photoFromAlbum;
- (IBAction)photoFromCamera;
- (IBAction)applyImageFilter:(id)sender;
- (IBAction)saveImageToAlbum;


@end


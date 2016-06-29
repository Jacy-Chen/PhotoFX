//
//  ViewController.m
//  photoFX
//
//  Created by Zexi Chen on 10/14/15.
//  Copyright © 2015 Jacy Chen. All rights reserved.
//

#import "ViewController.h"
#import <AWSCore/AWSCore.h>
#import <AWSS3/AWSS3.h>
#import <AWSSQS/AWSSQS.h>
#import <AWSSNS/AWSSNS.h>
#import <AWSCognito/AWSCognito.h>
#import "GPUImage.h"
#import "MTImageCore/ImageCore.h"



@interface ViewController ()

@end

@implementation ViewController
@synthesize selectedImageView, filterButton, saveButton;


#pragma mark - Life Cycle
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.saveButton.enabled = NO;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Actions

- (IBAction)photoFromAlbum
{
    UIImagePickerController *photoPicker = [[UIImagePickerController alloc] init];
    photoPicker.delegate = self;
    photoPicker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    
    [self presentViewController:photoPicker animated:YES completion:NULL];
    
}

- (IBAction)photoFromCamera
{
    //it can alse be implemented by the AVFoundation
    UIImagePickerController *photoPicker = [[UIImagePickerController alloc] init];
    
    photoPicker.delegate = self;
    photoPicker.sourceType = UIImagePickerControllerSourceTypeCamera;
//    [saveButton setEnabled:YES];
    [self presentViewController:photoPicker animated:YES completion:NULL];
    
}

- (IBAction)saveImageToAlbum
{
//    //Proctice: ----->   To upload the Image into Parse and AWS S3
//    // Convert to JPEG with 50% quality
//    NSData * data = UIImageJPEGRepresentation(originImage, 0.5f);
//    PFFile *imageFile = [PFFile fileWithName:@"Image.jpg" data:data];
//    
//    // Save the image to Parse
//    [imageFile saveInBackgroundWithBlock:^(BOOL succeeded, NSError *error) {
//        if (!error) {
//            // The image has now been uploaded to Parse. Associate it with a new object
//            PFObject* newPhotoObject = [PFObject objectWithClassName:@"PhotoObject"];
//            [newPhotoObject setObject:imageFile forKey:@"image"];
//            
//            [newPhotoObject saveInBackgroundWithBlock:^(BOOL succeeded, NSError *error) {
//                if (!error) {
//                    NSLog(@"Saved");
//                }
//                else{
//                    // Error
//                    NSLog(@"Error: %@ %@", error, [error userInfo]);
//                }
//            }];
//        }
//    }];
////
//    
//    //image you want to upload
//    NSString * dateKey = @"photoImage";
//    UIImage* imageToUpload = originImage;
//    
//    //convert uiimage to
//    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
//    NSString *filePath = [[paths objectAtIndex:0] stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.png", dateKey]];
//    
//    [UIImagePNGRepresentation(imageToUpload) writeToFile:filePath atomically:YES];
//    
//    NSURL* fileUrl = [NSURL fileURLWithPath:filePath];
//    
//    //upload the image
//     NSString *const S3BucketName = @"photo-zexi";
//    AWSS3TransferManager *transferManager = [AWSS3TransferManager defaultS3TransferManager];
//    AWSS3TransferManagerUploadRequest *uploadRequest = [AWSS3TransferManagerUploadRequest new];
//    uploadRequest.body = fileUrl;
//    uploadRequest.bucket = S3BucketName;
//    uploadRequest.key = @"photoImage.png";
//    uploadRequest.contentType = @"image/png";
//    
//    [[[AWSS3TransferManager defaultS3TransferManager] upload:uploadRequest] continueWithBlock:^id(AWSTask *task) {
//        
//        if (task.error) {
//            
//            if ([task.error.domain isEqualToString:AWSS3TransferManagerErrorDomain]) {
//                
//                switch (task.error.code) {
//                    case AWSS3TransferManagerErrorUnknown:
//                        NSLog(@"Upload task error : AWSS3TransferManagerErrorUnknown");
//                        break;
//                        
//                    case AWSS3TransferManagerErrorCancelled:
//                        NSLog(@"Upload task error : AWSS3TransferManagerErrorCancelled");
//                        break;
//                        
//                    case AWSS3TransferManagerErrorPaused:
//                        NSLog(@"Upload task error : AWSS3TransferManagerErrorPaused");
//                        break;
//                        
//                    case AWSS3TransferManagerErrorCompleted:
//                        NSLog(@"Upload task error : AWSS3TransferManagerErrorCompleted");
//                        break;
//                        
//                    case AWSS3TransferManagerErrorInternalInConsistency:
//                        NSLog(@"Upload task error : AWSS3TransferManagerErrorInternalInConsistency");
//                        break;
//                        
//                    case AWSS3TransferManagerErrorMissingRequiredParameters:
//                        NSLog(@"Upload task error : AWSS3TransferManagerErrorMissingRequiredParameters");
//                        break;
//                        
//                    case AWSS3TransferManagerErrorInvalidParameters:
//                        NSLog(@"Upload task error : AWSS3TransferManagerErrorInvalidParameters");
//                        break;
//                        
//                    default:
//                        NSLog(@"Upload domain error : [%@]", task.error);
//                        break;
//                }
//            } else {
//                NSLog(@"Upload failed : [%@]", task.error);
//            }
//        }
//        
//        if (task.result) {
//            NSLog(@"Uploaded success - check bucket : %@", task.result);
//        }
//        return nil;
//    }];
    
    
    //--> Save the Image into local device folder
    UIImageWriteToSavedPhotosAlbum(self.selectedImageView.image, self, @selector(image:didFinishSavingWithError:contextInfo:), nil);
    
}

- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo
{
    NSString *alertTitle;
    NSString *alertMessage;
    
    if(!error)
    {
        alertTitle   = @"Image Saved";
        alertMessage = @"Image saved to photo album successfully.";
    }
    else
    {
        alertTitle   = @"Error";
        alertMessage = @"Unable to save to photo album.";
    }
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:alertTitle
                                                    message:alertMessage
                                                   delegate:self
                                          cancelButtonTitle:@"Okay"
                                          otherButtonTitles:nil];
    [alert show];
}


- (IBAction)applyImageFilter:(id)sender{
//    UIBarButtonItem * tmp = (UIBarButtonItem *)sender;
//    if (tmp == filterButton
//        && [tmp.title isEqualToString: @"Parse"]) {
//        [tmp setTitle:@"S3"];
//    }
//    else {
//        [tmp setTitle:@"Parse"];
//    }
    
    UIActionSheet *filterActionSheet = [[UIActionSheet alloc] initWithTitle:@"Select Filter"
                                                                   delegate:self
                                                          cancelButtonTitle:@"Cancel"
                                                     destructiveButtonTitle:nil
                                                          otherButtonTitles:@"Grayscale", @"Sepia", @"Sketch", @"Pixellate", @"Color Invert", @"Toon", @"Pinch Distort", @"None", nil];
    
    [filterActionSheet showFromBarButtonItem:sender animated:YES];

}


- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    GPUImageFilter *selectedFilter;
    
    switch (buttonIndex) {
        case 0:
            selectedFilter = [[GPUImageGrayscaleFilter alloc] init];
            break;
        case 1:
            selectedFilter = [[GPUImageSepiaFilter alloc] init];
            break;
        case 2:
            selectedFilter = [[GPUImageSketchFilter alloc] init];
            break;
        case 3:
            selectedFilter = [[GPUImagePixellateFilter alloc] init];
            break;
        case 4:
            selectedFilter = [[GPUImageColorInvertFilter alloc] init];
            break;
        case 5:
            selectedFilter = [[GPUImageToonFilter alloc] init];
            break;
        case 6:
            selectedFilter = [[GPUImagePinchDistortionFilter alloc] init];
            break;
        case 7:
            selectedFilter = [[GPUImageFilter alloc] init];
            break;
        default:
            break;
    }
    
    UIImage *filteredImage = [selectedFilter imageByFilteringImage:originImage];
    [self.selectedImageView setImage:filteredImage];
}



#pragma mark - Delegate

//get image from imagePicker
- (void)imagePickerController:(UIImagePickerController *)photoPicker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
    self.saveButton.enabled = YES;
    self.filterButton.enabled = YES;
    
    originImage = [info valueForKey:UIImagePickerControllerOriginalImage];

    
    [self.selectedImageView setImage:originImage];
    [self.selectedImageView clipsToBounds];
    
    [photoPicker dismissModalViewControllerAnimated:YES];
}


@end

#import <UIKit/UIKit.h>

@interface CustomTextInputView : UIView <UIKeyInput>

@property(nonatomic, strong) NSMutableString *text; // 入力されたテキスト

@end

#import <UIKit/UIKit.h>
#include "../hspwnd_dish.h" // HSP3 のオブジェクト管理用ヘッダー

@interface InputBoxHelper : NSObject <UITextFieldDelegate>

@property(nonatomic, strong) UITextField *textField;
@property(nonatomic, copy) void (^onTextInput)(const char *text);
@property(nonatomic, assign) HSPOBJINFO *currentInputBox; // アクティブな InputBox

+ (instancetype)sharedInstance;

- (void)showKeyboardFor:(HSPOBJINFO *)info;
- (void)closeKeyboard;

@end

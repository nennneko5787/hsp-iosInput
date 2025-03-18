#import <UIKit/UIKit.h>

@interface CustomTextInputView : UIView <UIKeyInput>
@property (nonatomic, strong) NSMutableString *text;
@end

@implementation CustomTextInputView

- (instancetype)init {
    self = [super init];
    if (self) {
        _text = [NSMutableString string];
    }
    return self;
}

- (void)insertText:(NSString *)text {
    [self.text appendString:text];
}

- (void)deleteBackward {
    if (self.text.length > 0) {
        [self.text deleteCharactersInRange:NSMakeRange(self.text.length - 1, 1)];
    }
}

- (BOOL)hasText {
    return self.text.length > 0;
}

// キーボード入力を受け付けるために必要
- (BOOL)canBecomeFirstResponder {
    return YES;
}

@end

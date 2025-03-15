#import "InputBoxHelper.h"

@implementation InputBoxHelper

+ (instancetype)sharedInstance {
    static InputBoxHelper *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[InputBoxHelper alloc] init];
    });
    return sharedInstance;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        [self setupTextField];
    }
    return self;
}

- (void)setupTextField {
    self.textField = [[UITextField alloc] initWithFrame:CGRectZero];
    self.textField.delegate = self;
    self.textField.keyboardType = UIKeyboardTypeDefault;
    self.textField.autocorrectionType = UITextAutocorrectionTypeNo;
    self.textField.hidden = YES;

    [self.textField addTarget:self action:@selector(textFieldDidChange:) forControlEvents:UIControlEventEditingChanged];

    UIToolbar *toolbar = [[UIToolbar alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, 40)];
    UIBarButtonItem *doneButton = [[UIBarButtonItem alloc] initWithTitle:@"完了"
                                                                   style:UIBarButtonItemStyleDone
                                                                  target:self
                                                                  action:@selector(closeKeyboard)];
    toolbar.items = @[doneButton];
    self.textField.inputAccessoryView = toolbar;

    UIWindow *window = [UIApplication sharedApplication].keyWindow;
    [window addSubview:self.textField];
}

- (void)showKeyboardFor:(HSPOBJINFO *)info {
    self.currentInputBox = info;
    [self.textField becomeFirstResponder];
}

- (void)closeKeyboard {
    [self.textField resignFirstResponder];
}

- (void)textFieldDidChange:(UITextField *)textField {
    if (self.currentInputBox == NULL) return;

    Hsp3ObjInput *edit = (Hsp3ObjInput *)self.currentInputBox->btnset;
    if (edit == NULL) return;

    edit->tpos.setString([textField.text UTF8String]);
    edit->tpos.setCaret();

    Object_SendSetVar(self.currentInputBox, HSPVAR_FLAG_STR, [textField.text UTF8String]);
}

@end

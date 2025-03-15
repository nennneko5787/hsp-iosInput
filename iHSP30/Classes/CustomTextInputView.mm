@implementation CustomTextInputView

- (instancetype)init {
    self = [super init];
    if (self) {
        _text = [NSMutableString string];
    }
    return self;
}

- (void)insertText:(NSString *)text {
    [self.text appendString:text]; // テキストを追加
    [self setNeedsDisplay]; // 再描画
}

- (void)deleteBackward {
    if (self.text.length > 0) {
        [self.text deleteCharactersInRange:NSMakeRange(self.text.length - 1, 1)]; // 末尾を削除
        [self setNeedsDisplay]; // 再描画
    }
}

- (BOOL)hasText {
    return self.text.length > 0;
}

- (void)drawRect:(CGRect)rect {
    [super drawRect:rect];
    // テキストの表示処理
    [self.text drawInRect:rect withAttributes:nil]; // 必要に応じてカスタムフォントを設定
}

@end

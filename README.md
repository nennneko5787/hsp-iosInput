# hsp-iosInput

このリポジトリは、**HSP3Dish iOS 版**でキーボードを表示する命令を追加するテストです。

動作確認: <https://x.com/Fng1Popn/status/1901972482267250704>

## How To Build

[HSP3Dish for iOS のビルドテスト](https://github.com/nennneko5787/hsp-iosBuildTest2) とほぼ同じ手順なのでそちらを御覧ください  
違うのは`iHSP30`フォルダの中身です

## 追加される命令

- `devcontrol "open_keyboard"` - キーボードを表示します
- `devinfo p1, "keyboard_text"` - p1 に指定した文字列型変数にキーボードの内容を代入します
- `devcontrol "close_keyboard"` - キーボードを閉じます

> [!NOTE]
> 現時点では、input 命令を置き換えていません。  
> また、テキストの選択・コピー・ペーストは行えません。

## サンプルコード

```hsp
#include "hsp3dish.as"

	objsize 300, 60
    pos 10, 10
	button gosub "キーボード表示", *openKeyBoard
    objId = stat

	repeat
    devinfo text, "keyboard_text"

    redraw 0
        if (text == "") {
            objprm objId, "キーボード表示"
        } else {
            objprm objId, text
        }
    redraw 1

    stick key

    if (key & 256) {
        devcontrol "close_keyboard"
    }

    await (1000 / 60)
	loop

*openKeyBoard
    devcontrol "open_keyboard"
    return

```

## Q & A

### Q. このコードを使っても、ビルドがうまくいきません。

A. [@Fng1Popn](https://x.com/Fng1Popn) か Discord `@nennneko5787` まで連絡してください。

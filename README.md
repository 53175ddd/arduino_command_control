# arduino command control

English follows Japanese

## コマンド

Arduino IDE のシリアルモニタから操作します

使用例：`led 1 on`

### `led` コマンド

| argument 1 | descriptions |
|----|----|
| `1`, `a`, `A` | プログラム上で `LED_1` として定義された一番目の LED を選択します |
| `2`, `b`, `B` | プログラム上で `LED_2` として定義された二番目の LED を選択します |
| `3`, `c`, `C` | プログラム上で `LED_3` として定義された三番目の LED を選択します |

| argument 2 | descriptions |
|----|----|
| `on`, `high`, `1` | 選択された LED を点灯させます |
| `off`, `low`, `0` | 選択された LED を消灯させます |

## Commands

Operate from the serial monitor of the Arduino IDE.

How To Use：`led 1 on`

### "led" command

| argument 1 | descriptions |
|----|----|
| `1`, `a`, `A` | select first LED that defined as `LED_1` in the program |
| `2`, `b`, `B` | select second LED that defined as `LED_3` in the program |
| `3`, `c`, `C` | select third LED that defined as `LED_2` in the program |

| argument 2 | descriptions |
|----|----|
| `on`, `high`, `1` | turn on the selected LED |
| `off`, `low`, `0` | turn off the selected LED |

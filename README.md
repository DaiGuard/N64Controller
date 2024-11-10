# N64 Controller for ESP32

Nintendo64コントローラをESP32で読み取るのためのパッケージ

N64は250kHzボーレートで通信使、`1`は1µs LOW, 3µs HIGH、`0`は3µs LOW, 1µs HIGHで表現されます。
そのままの通信プロトコルが存在しないので1250kHzの`UART`を利用して通信を行う

N64 2ビット分をUART 8ビットで下記表に合わせて表現する

| N64 | UART |
| --- | ---  |
| 0b00 | 0x08 |
| 0b01 | 0xe8 |
| 0b10 | 0x0f |
| 0b11 | 0xEF |

![image](https://github.com/user-attachments/assets/6e782ba5-2db1-4006-9d85-72744ea07360)

## 接続方法

N64コントローラは1線式半二重シリアルプロトコルを使用しています。
それに対応するため、画像のように`TX`にダイオードを挟んで`RX`と合わせて接続する

![image](https://github.com/user-attachments/assets/c4cb93f5-1f1e-4608-b97d-f25487db966b)

![image](https://github.com/user-attachments/assets/83a9f5d3-5add-4575-aeeb-9239a3bcbf45)

ESP32-DevkitにはUARTで使用できるシリアルが3つ存在するが、SerialはUSBシリアルと共用しているため、USBを使用する場合は使用することができない

|         | RX  | TX  |
| ---     | --- | --- |
| Serial  | 3   | 1   |
| Serial1 | 9   | 10  |
| Serial2 | 16  | 17  |

##　使い方

### 初期設定

`n64_protocol.cpp`上の`#define N64Serial`に使用するシリアルアダプタを設定する

```cpp
// デフォルト
#define N64Serial Serial2

// 変更例
// シリアル0を使用する場合
#define N64Serial Serial
// シリアル1を使用する場合
#define N64Serial Serial1
// シリアル2を使用する場合
#define N64Serial Serial2
```

### 準備コマンド

- *** ステータス(0x00) ***

```cpp
/**
 * @brief ステータスコマンド送信
 * 
 * @param data レスポンスデータ格納バッファ(必要3バイト)
 * @return size_t 
 */
size_t N64_readStatus(uint8_t* data);
```

- *** ポール(0x01) ***

```cpp
/**
 * @brief ポーリングコマンド送信
 * 
 * @param data レスポンスデータ格納バッファ(必要3バイト)
 * @return size_t 
 */
size_t N64_readPoll(uint8_t* data);
```

- *** 読み取り(x02) ***

- *** 書き込み(0x03) ***

- *** リセット(0xFF) ***


## 参考リンク

[N64 Controller](https://www.qwertymodo.com/hardware-projects/n64/n64-controller)
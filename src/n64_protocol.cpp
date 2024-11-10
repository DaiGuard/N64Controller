#include "n64_controller.h"

#include <Arduino.h>
#include <stdint.h>
#include <stddef.h>


#define N64Serial Serial2

/**
 * @brief N64コマンド通信
 * 
 * @param cmd コマンド
 * @param data レスポンスデータ格納バッファ
 * @param size レスポンスデータ格納バッファサイズ
 * @return size_t レスポンスデータサイズ
 */
size_t N64_translate(const uint8_t* cmd, uint8_t* data, int size)
{
  // コマンド送信
  noInterrupts();
  N64Serial.write(cmd, 5);
  interrupts();

  // レスポンスデータ受信
  size_t ret = N64Serial.readBytes(data, size*4+4+1);  

  return ret;  
}

/**
 * @brief ステータスコマンド送信
 * 
 * @param data レスポンスデータ格納バッファ(必要3バイト)
 * @return size_t 
 */
size_t N64_readStatus(uint8_t* data)
{
  return N64_translate(STATUS_CMD, data, 3);
}

/**
 * @brief ポーリングコマンド送信
 * 
 * @param data レスポンスデータ格納バッファ(必要3バイト)
 * @return size_t 
 */
size_t N64_readPoll(uint8_t* data)
{
  return N64_translate(POLL_CMD, data, 4);
}

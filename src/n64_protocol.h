#ifndef __N64_PROTOCOL__
#define __N64_PROTOCOL__

#include <stddef.h>
#include <stdint.h>

/**
 * @brief N64コマンド通信
 * 
 * @param cmd コマンド
 * @param data レスポンスデータ格納バッファ
 * @param size レスポンスデータ格納バッファサイズ
 * @return size_t レスポンスデータサイズ
 */
size_t N64_translate(const uint8_t* cmd, uint8_t* data, int size);

/**
 * @brief ステータスコマンド送信
 * 
 * @param data レスポンスデータ格納バッファ(必要3バイト)
 * @return size_t 
 */
size_t N64_readStatus(uint8_t* data);

/**
 * @brief ポーリングコマンド送信
 * 
 * @param data レスポンスデータ格納バッファ(必要3バイト)
 * @return size_t 
 */
size_t N64_readPoll(uint8_t* data);


#endif
#ifndef __N64_PARSER__
#define __N64_PARSER__

struct n64_stick_and_button;

/**
 * @brief レスポンスデータのコントローラ入力値変換
 * 
 * @param data レスポンスデータ
 * @param input コントローラ入力値
 */
void N64_parseStickAndButton(uint8_t* data, struct n64_stick_and_button* input);

#endif
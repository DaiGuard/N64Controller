#include "n64_controller.h"


/**
 * @brief レスポンスデータのコントローラ入力値変換
 * 
 * @param data レスポンスデータ
 * @param input コントローラ入力値
 */
void N64_parseStickAndButton(uint8_t* data, N64StickAndButton* input)
{
    input->btn_A = (data[4] >> 4 & 0x0f) >= 0x09;
    input->btn_B = (data[5] & 0x0f) > 0x0c;
    input->btn_Z = (data[5] >> 4 & 0x0f) > 0x0c;
    input->btn_START = (data[6] & 0x0f) > 0x0c;
    input->btn_DU = (data[6] >> 4 & 0x0f) > 0x0c;
    input->btn_DD = (data[7] & 0x0f) > 0x0c;
    input->btn_DL = (data[7] >> 4 & 0x0f) > 0x0c;
    input->btn_DR = (data[8] & 0x0f) > 0x0c;
    input->btn_L = (data[9] >> 4 & 0x0f) > 0x0c;
    input->btn_R = (data[10] & 0x0f) > 0x0c;
    input->btn_CU = (data[10] >> 4 & 0x0f) > 0x0c;
    input->btn_CD = (data[11] & 0x0f) > 0x0c;
    input->btn_CL = (data[11] >> 4 & 0x0f) > 0x0c;
    input->btn_CR = (data[12] & 0x0f) > 0x0c;

    int8_t analog_X = 0x00;
    analog_X |= (data[12] >> 4 & 0x0f) > 0x0c ? 0x80 : 0x00;
    analog_X |= (data[13] & 0x0f) > 0x0c      ? 0x40 : 0x00;
    analog_X |= (data[13] >> 4 & 0x0f) > 0x0c ? 0x20 : 0x00;
    analog_X |= (data[14] & 0x0f) > 0x0c      ? 0x10 : 0x00;
    analog_X |= (data[14] >> 4 & 0x0f) > 0x0c ? 0x08 : 0x00;
    analog_X |= (data[15] & 0x0f) > 0x0c      ? 0x04 : 0x00;
    analog_X |= (data[15] >> 4 & 0x0f) > 0x0c ? 0x02 : 0x00;
    analog_X |= (data[16] & 0x0f) > 0x0c      ? 0x01 : 0x00;
    input->analog_X = analog_X;

    int8_t analog_Y = 0x00;
    analog_Y |= (data[16] >> 4 & 0x0f) > 0x0c ? 0x80 : 0x00;
    analog_Y |= (data[17] & 0x0f) > 0x0c      ? 0x40 : 0x00;
    analog_Y |= (data[17] >> 4 & 0x0f) > 0x0c ? 0x20 : 0x00;
    analog_Y |= (data[18] & 0x0f) > 0x0c      ? 0x10 : 0x00;
    analog_Y |= (data[18] >> 4 & 0x0f) > 0x0c ? 0x08 : 0x00;
    analog_Y |= (data[19] & 0x0f) > 0x0c      ? 0x04 : 0x00;
    analog_Y |= (data[19] >> 4 & 0x0f) > 0x0c ? 0x02 : 0x00;
    analog_Y |= (data[20] & 0x0f) > 0x0c      ? 0x01 : 0x00;
    input->analog_Y = analog_Y;
}
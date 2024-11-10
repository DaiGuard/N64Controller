#ifndef __N64_CONTROLLER__
#define __N64_CONTROLLER__

#include "n64_command.h"
#include "n64_protocol.h"
#include "n64_parser.h"

#include <HardwareSerial.h>


/**
 * @brief N64コントローラ入力値
 * 
 */
typedef struct n64_stick_and_button {
    bool btn_A;
    bool btn_B;
    bool btn_Z;

    bool btn_START;

    bool btn_DU;
    bool btn_DD;
    bool btn_DL;
    bool btn_DR;

    bool btn_L;
    bool btn_R;

    bool btn_CU;
    bool btn_CD;
    bool btn_CL;
    bool btn_CR;

    int8_t analog_X;
    int8_t analog_Y;
} N64StickAndButton;


#endif
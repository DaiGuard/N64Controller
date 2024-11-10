#ifndef __N64_COMMAND__
#define __N64_COMMAND__

#include <stdint.h>

#define N64_B00 0x08
#define N64_B01 0xe8
#define N64_B10 0x0f
#define N64_B11 0xef
#define N64_END 0xfc

/**
 * @brief ステータスコマンド 0x00
 * 
 */
const uint8_t STATUS_CMD[5] = {
  N64_B00,
  N64_B00,
  N64_B00,
  N64_B00,
  N64_END
};

/**
 * @brief POLLコマンド 0x01
 * 
 */
const uint8_t POLL_CMD[5] = {
  N64_B00,
  N64_B00,
  N64_B00,
  N64_B01,
  N64_END
};

/**
 * @brief READコマンド 0x02
 * 
 */
const uint8_t READ_CMD[5] = {
  N64_B00,
  N64_B00,
  N64_B00,
  N64_B10,
  N64_END
};

/**
 * @brief WRITEコマンド 0x03
 * 
 */
const uint8_t WRITE_CMD[5] = {
  N64_B00,
  N64_B00,
  N64_B00,
  N64_B11,
  N64_END
};

/**
 * @brief RESETコマンド 0xff
 * 
 */
const uint8_t RESET_CMD[5] = {
  N64_B11,
  N64_B11,
  N64_B11,
  N64_B11,
  N64_END
};

#endif
#ifndef CRC_BUFFER_H
#define CRC_BUFFER_H

#include <stdint.h>

typedef uint8_t crc_buffer_7;
typedef uint16_t crc_buffer_16;

/*
* Calculates the CRC7 for the received data and outputs the last byte of the message
* frame by sp (7 bits of crc7 + '1'). Number of protected bits - 40 or 120
*/
uint8_t
crc_buffer_calculate_crc_7(crc_buffer_7* buffer, uint8_t* data, const uint8_t data_length);

//#define FIRST_PART_OF_CRC_16
//#define SECOND_PART_OF_CRC_16

/*
* Calculates the CRC16 for the received data and outputs the two bytes of CRC16. 
* Number of protected bits - up to 16384
*/
uint16_t
crc_buffer_calculate_crc_16(crc_buffer_16* buffer, uint8_t* data, const uint16_t data_length);

#endif

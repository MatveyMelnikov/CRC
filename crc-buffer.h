#ifndef CRC_BUFFER_H
#define CRC_BUFFER_H

#include <stdint.h>

typedef struct
{
	uint8_t buffer;
	uint8_t index;
} crc_buffer;

void
crc_buffer_reset(crc_buffer* buffer, uint8_t firstDataByte);

uint8_t
crc_buffer_calculate_crc(crc_buffer* buffer, uint8_t* data, const uint8_t data_length);

#endif

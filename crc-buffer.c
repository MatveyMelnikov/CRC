#include "crc-buffer.h"
#include <stdbool.h>

void
crc_buffer_reset(crc_buffer* buffer, uint8_t firstDataByte)
{
	buffer->buffer = firstDataByte ^ 0xff;
}

uint8_t
crc_buffer_calculate_crc(crc_buffer* buffer, uint8_t* data, const uint8_t data_length)
{
	buffer->buffer = 0x0;

	for (uint8_t i = 0; i < data_length * 8; i++)
	{
		bool inputBit = *(data + (i / 8)) & (1 << (7 - (i % 8)));
		inputBit ^= (bool)(buffer->buffer & (1 << 6));

		buffer->buffer <<= 1;
		buffer->buffer ^= (inputBit << 3);
		buffer->buffer |= inputBit;
	}

	return (buffer->buffer << 1) | 1;
}

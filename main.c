#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "crc-buffer.h"

void
print_byte(uint8_t byte)
{
	for (int8_t i = 7; i >= 0; i--)
		printf("%u", (bool)(byte & (1 << i)));
	printf("\n");
}

int
main()
{
	crc_buffer buffer = { 0 };
	uint8_t data[3][5] = {
		{ 0x40, 0x00, 0x00, 0x00, 0x00 },
		{ 0x51, 0x00, 0x00, 0x00, 0x00 },
		{ 0x11, 0x00, 0x00, 0x09, 0x00 }
	};
	
	for (uint8_t i = 0; i < 3; i++)
	{
		print_byte(crc_buffer_calculate_crc(&buffer, data[i], 5));
	}

	return 0;
}
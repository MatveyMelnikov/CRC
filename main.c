#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "crc-buffer.h"

#define CRC7_DATA_SIZE 5
#define CRC16_DATA_SIZE 512

void
print_byte(uint8_t byte)
{
	for (int8_t i = 7; i >= 0; i--)
		printf("%u", (bool)(byte & (1 << i)));
	printf("\n");
}

void
print_word(uint16_t word)
{
	for (int8_t i = 15; i >= 0; i--)
		printf("%u", (bool)(word & (1 << i)));
	printf("\n");
}

void
test_crc_7()
{
	crc_buffer_7 buffer;
	// CMD0, CMD17, Responese of CMD17
	uint8_t test_data[3][CRC7_DATA_SIZE] = {
		{ 0x40, 0x00, 0x00, 0x00, 0x00 },
		{ 0x51, 0x00, 0x00, 0x00, 0x00 },
		{ 0x11, 0x00, 0x00, 0x09, 0x00 }
	};
	uint8_t data_reference[3] = { 0x95, 0x55, 0x67 };

	printf("Test CRC7:\n");
	for (uint8_t i = 0; i < 3; i++)
	{
		uint8_t result = crc_buffer_calculate_crc_7(
			&buffer,
			test_data[i],
			CRC7_DATA_SIZE
		);
		print_byte(result);
		assert(result == data_reference[i]);
	}
	printf("\n");
}

void test_crc_16()
{
	crc_buffer_16 buffer;
	uint8_t test_data[CRC16_DATA_SIZE]; // 512 bytes with 0xFF data
	uint16_t data_reference = 0x7FA1;

	memset(&test_data, 0xFF, CRC16_DATA_SIZE);

	uint16_t result = crc_buffer_calculate_crc_16(
		&buffer,
		test_data,
		CRC16_DATA_SIZE
	).i16;

	printf("Test CRC16:\n");
	print_word(result);
	printf("\n");

	assert(result == data_reference);
}

int
main()
{
	test_crc_7();

	test_crc_16();

	return 0;
}
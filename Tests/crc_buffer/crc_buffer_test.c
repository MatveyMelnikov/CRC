#include "unity_fixture.h"
#include "crc_buffer.h"
#include <string.h>

TEST_GROUP(crc_buffer);

// static crc_buffer buffer = 0x0U;
#define CRC7_DATA_SIZE 5U
#define CRC16_DATA_SIZE 512U

TEST_SETUP(crc_buffer)
{
}

TEST_TEAR_DOWN(crc_buffer)
{
}

TEST(crc_buffer, crc_7_multiple_data_success)
{
    uint8_t test_data[3][CRC7_DATA_SIZE] = {
		{ 0x40, 0x00, 0x00, 0x00, 0x00 },
		{ 0x51, 0x00, 0x00, 0x00, 0x00 },
		{ 0x11, 0x00, 0x00, 0x09, 0x00 }
	};
	uint8_t data_reference[3] = { 0x95, 0x55, 0x67 };

	for (uint8_t i = 0; i < 3; i++)
	{
		uint8_t result = crc_buffer_calculate_crc_7(
			test_data[i],
			CRC7_DATA_SIZE
		);
		TEST_ASSERT_EQUAL_HEX8(result, data_reference[i]);
	}
}

TEST(crc_buffer, crc_16_ff_success)
{
    uint8_t test_data[CRC16_DATA_SIZE]; // 512 bytes with 0xFF data

	memset(test_data, 0xFF, CRC16_DATA_SIZE);

	crc_16_result result = crc_buffer_calculate_crc_16(
		test_data,
		CRC16_DATA_SIZE
	);

	TEST_ASSERT_EQUAL_HEX16(result.i16, 0x7FA1U);
}

TEST(crc_buffer, crc_16_test_bytes_order)
{
    uint8_t test_data[CRC16_DATA_SIZE]; // 512 bytes with 0xFF data

	memset(test_data, 0xFF, CRC16_DATA_SIZE);

	crc_16_result result = crc_buffer_calculate_crc_16(
		test_data,
		CRC16_DATA_SIZE
	);

	TEST_ASSERT_EQUAL_HEX8(0xA1U, result.i8[0]);
    TEST_ASSERT_EQUAL_HEX8(0x7FU, result.i8[1]);
}

TEST(crc_buffer, calculate_crc16_after_crc7)
{
    uint8_t test_data_crc_16[CRC16_DATA_SIZE]; // 512 bytes with 0xFF data
	uint8_t test_data_crc_7[CRC7_DATA_SIZE] = { 
		0x40, 0x00, 0x00, 0x00, 0x00
	};

	memset(test_data_crc_16, 0xFF, CRC16_DATA_SIZE);

	uint8_t result_crc_7 = crc_buffer_calculate_crc_7(
		test_data_crc_7,
		CRC7_DATA_SIZE
	);
	TEST_ASSERT_EQUAL_HEX8(result_crc_7, 0x95U);

	crc_16_result result_crc_16 = crc_buffer_calculate_crc_16(
		test_data_crc_16,
		CRC16_DATA_SIZE
	);

	TEST_ASSERT_EQUAL_HEX16(result_crc_16.i16, 0x7FA1U);
}

#include "unity_fixture.h"

TEST_GROUP_RUNNER(crc_buffer)
{
    RUN_TEST_CASE(crc_buffer, crc_7_multiple_data_success);
    RUN_TEST_CASE(crc_buffer, crc_16_ff_success);
    RUN_TEST_CASE(crc_buffer, crc_16_test_bytes_order);
    RUN_TEST_CASE(crc_buffer, calculate_crc16_after_crc7);
}

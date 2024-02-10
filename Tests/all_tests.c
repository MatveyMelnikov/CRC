#include "unity_fixture.h"

static void run_all_tests()
{
	RUN_TEST_GROUP(crc_buffer);
}

int main(int argc, char *argv[])
{
	return UnityMain(argc, argv, run_all_tests);
}

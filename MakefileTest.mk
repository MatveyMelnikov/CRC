CC = gcc
FLAGS = -std=c99
BUILD_DIR = $(UNITY_DIR)/build
TARGET = $(BUILD_DIR)/tests.out
SYMBOLS=-DTEST -DUNITY_SUPPORT_64
TESTS_DIR = Tests

INCLUDES += \
-I$(UNITY_DIR)/src \
-I$(UNITY_DIR)/extras/fixture/src \
-I$(UNITY_DIR)/extras/memory/src

SOURCES += \
$(UNITY_DIR)/src/unity.c \
$(UNITY_DIR)/extras/fixture/src/unity_fixture.c \
$(UNITY_DIR)/extras/memory/src/unity_memory.c \
$(TESTS_DIR)/all_tests.c \
$(TESTS_DIR)/crc_buffer/crc_buffer_test.c \
$(TESTS_DIR)/crc_buffer/crc_buffer_test_runner.c

OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.c=.o)))

all: $(TARGET)

vpath %.c $(dir $(SOURCES))

$(BUILD_DIR)/%.o: %.c
	$(CC) $(FLAGS) $(SYMBOLS) -MD $(INCLUDES) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(TARGET)

.PHONY = start
start: $(TARGET)
	echo ---Start tests:
	./$(TARGET) -v # -v - print tests

.PHONY = clean
clean:
	rm -f $(BUILD_DIR)/*

-include $(TEST_OBJECTS:.o=.d)

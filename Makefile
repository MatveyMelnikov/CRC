CC = gcc
FLAGS = -std=c99 -Wall -pedantic
BUILD_DIR = build
TARGET = $(BUILD_DIR)/crc_buffer.out
UNITY_DIR = External/Unity-2.5.2
# Choosing between production build and tests
TESTS = Y

# Common code files
# Main files are specified separately for tests and production code
INCLUDES = \
-IInc
SOURCES = \
Src/crc_buffer.c

ifeq ($(TESTS), Y)
include MakefileTest.mk
# else
# include MakefileProduction.mk
endif

CC = gcc
CFLAGS = -Wall -Wextra -g

PROJECT_NAME = unittests
SRC_DIR = .
BUILD_DIR = ../build-tests

LIB_DIR = $(SRC_DIR)/lib
BIN_DIR = $(BUILD_DIR)/bin
OUT_DIR = $(BUILD_DIR)/out
OUT_LIB_DIR = $(OUT_DIR)/lib

APP_BUILD_DIR = ../build
APP_SRC_DIR = ../src
APP_SRC_LIB_DIR = $(APP_SRC_DIR)/lib
APP_OUT_LIB_DIR = $(APP_BUILD_DIR)/out/lib

SRCS = $(wildcard $(SRC_DIR)/*.c)
SRCS_LIB = $(wildcard $(LIB_DIR)/*.c)
APP_SRCS_LIB = $(wildcard $(APP_SRC_LIB_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OUT_DIR)/%.o, $(SRCS))
OBJS_LIB = $(patsubst $(LIB_DIR)/%.c, $(OUT_LIB_DIR)/%.o, $(SRCS_LIB))
APP_OBJS_LIB = $(patsubst $(APP_SRC_LIB_DIR)/%.c, $(APP_OUT_LIB_DIR)/%.o, $(APP_SRCS_LIB))

TARGET = $(BIN_DIR)/$(PROJECT_NAME)

.PHONY: all clean
all: $(TARGET)

$(TARGET): $(OBJS) $(OBJS_LIB) | $(BIN_DIR)
	$(CC) $(OBJS) $(OBJS_LIB) $(APP_OBJS_LIB) -o $@

$(OUT_LIB_DIR)/%.o: $(LIB_DIR)/%.c | $(OUT_LIB_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OUT_DIR) $(OUT_LIB_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

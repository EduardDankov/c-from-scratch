CC = gcc
CFLAGS = -Wall -Wextra -g

PROJECT_NAME = c-from-scratch
SRC_DIR = .
BUILD_DIR = build
LIB_DIR = lib
BIN_DIR = ../$(BUILD_DIR)/bin
OUT_DIR = ../$(BUILD_DIR)/out
OUT_LIB_DIR = $(OUT_DIR)/$(LIB_DIR)

SRCS = $(wildcard $(SRC_DIR)/*.c)
SRCS_LIB = $(wildcard $(SRC_DIR)/$(LIB_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OUT_DIR)/%.o, $(SRCS))
OBJS_LIB = $(patsubst $(SRC_DIR)/$(LIB_DIR)/%.c, $(OUT_LIB_DIR)/%.o, $(SRCS_LIB))

TARGET = $(BIN_DIR)/$(PROJECT_NAME)

.PHONY: all clean
all: $(TARGET)

$(TARGET): $(OBJS) $(OBJS_LIB) | $(BIN_DIR)
	$(CC) $(OBJS) $(OBJS_LIB) -o $@

$(OUT_LIB_DIR)/%.o: $(SRC_DIR)/$(LIB_DIR)/%.c | $(OUT_LIB_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OUT_DIR) $(OUT_LIB_DIR):
	mkdir -p $@

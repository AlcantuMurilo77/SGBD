BIN = bin/sgb
TEST_BIN = bin/test

SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O0 -g -fsanitize=address,undefined -Iinclude src/log.c -o bin/sgb

SRC = ${SRC_DIR}/main.c
TEST_SRC = ${TEST_DIR}/test_main.c


build: $(BIN)

$(BIN): $(SRC)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

run: build
	./${BIN}

test: ${TEST_BIN}
	./${TEST_BIN}

$(TEST_BIN): $(TEST_SRC)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BIN_DIR)

.PHONY: build run test clean

format:
	find src include tests -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -i {} + 
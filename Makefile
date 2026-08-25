CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c17 -g

INCLUDES = -Iinclude

SOURCES = \
	src/main.c \
	src/process.c \
	src/scheduler.c \
	src/memory.c \
	src/concurrency.c \
	src/compiler.c \
	src/network.c \
	src/hypervisor.c

PROGRAM = nexus

TEST_PROCESS = test_process

TEST_MEMORY = test_memory

TEST_COMPILER = test_compiler


all: $(PROGRAM)


$(PROGRAM): $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) -o $(PROGRAM)


run: $(PROGRAM)
	./$(PROGRAM)


$(TEST_PROCESS): tests/test_process.c src/process.c
	$(CC) $(CFLAGS) $(INCLUDES) tests/test_process.c src/process.c -o $(TEST_PROCESS)


$(TEST_MEMORY): tests/test_memory.c src/memory.c
	$(CC) $(CFLAGS) $(INCLUDES) tests/test_memory.c src/memory.c -o $(TEST_MEMORY)


$(TEST_COMPILER): tests/test_compiler.c src/compiler.c
	$(CC) $(CFLAGS) $(INCLUDES) tests/test_compiler.c src/compiler.c -o $(TEST_COMPILER)


test: $(TEST_PROCESS) $(TEST_MEMORY) $(TEST_COMPILER)
	./$(TEST_PROCESS)
	./$(TEST_MEMORY)
	./$(TEST_COMPILER)


clean:
	rm -f $(PROGRAM) \
	$(TEST_PROCESS) \
	$(TEST_MEMORY) \
	$(TEST_COMPILER)


.PHONY: all run test clean
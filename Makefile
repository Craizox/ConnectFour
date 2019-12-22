CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99 -pedantic
OBJS = $(addprefix src/, main.o)
BIN = power4

all: $(BIN)

debug: CFLAGS += -g -fsanitize=address
debug: all

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(BIN) $(OBJS)

.PHONY: clean all debug

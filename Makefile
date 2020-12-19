CC := gcc
CFLAGS := -Wall -g
LDFLAGS := -lm
TARGET := main

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
	rm -f $^
%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(TARGET) *.o

.PHONY: all clean

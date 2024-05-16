CC = gcc
CFLAGS = -Wall -Wextra -pedantic
LDFLAGS =

TARGET = mp3_player
SRCS = mp3_player.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    $(RM) $(TARGET) $(OBJS)

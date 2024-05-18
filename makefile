# Define the compiler
CC = gcc

# Define the flags
CFLAGS = -Wall -Wextra -pedantic -std=c11

# Define the target executable
TARGET = player

# Define the source files
SRCS = mplayer.c

# Define the installation directory
PREFIX = /usr/local

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

install: $(TARGET)
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all install uninstall clean


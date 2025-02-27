# defining the command line arguments, using gcc as the compiler,
# with the -Wall, -g, and -lm flags.
# defines the name of the final executable that is compiled from the source code
CC = gcc
CFLAGS = -Wall -g -save-temps -pedantic
LFLAGS = -lm
TARGET = out
SRCS = driver.c functions.c
HDRS = functions.h
OBJS = $(SRCS:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c functions.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET) 1 2

clean:
	rm -f $(TARGET) *.o *.i *.s

# explicit dependencies for object files
driver.o: functions.h
functions.o: functions.h
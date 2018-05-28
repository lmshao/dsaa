CC = g++
LD = g++

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %cpp, %o, $(SRCS))
FLAGS = -std=c++11

TARGET = DSAA

.PHONY:all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $@ $^

%o:%cpp
	$(CC) -c $^ $(FLAGS)

clean:
	rm -f $(OBJS) $(TARGET)

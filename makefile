CFLAGS = -g -Wall
CC = c++

all: main

main: main.cpp
	$(CC) $(CFLAGS) -o main main.cpp clock.cpp

clean:
	rm –f ./main

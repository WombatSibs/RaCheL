CFLAGS = -g -Wall
CC = g++

all: main

main: main.cpp
	$(CC) $(CFLAGS) -o main main.cpp clock.cpp files.cpp -lwiringPi

clean:
	rm -f ./main

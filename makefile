CFLAGS = -g -Wall
CC = c++

all: main

main: main.cpp
	$(CC) $(CFLAGS) -o main main.cpp clock.cpp hardwareSwitch.cpp files.cpp

clean:
	rm –f ./main

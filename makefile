CFLAGS = -g -Wall
CC = c++

all: main

main: main.cpp
	$(CC) $(CFLAGS) -o main main.cpp clock.cpp gui.cpp -lGL -lglut

clean:
	rm –f ./main

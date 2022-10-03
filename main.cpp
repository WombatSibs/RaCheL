#include "main.h"

int main(int argc, char **argv) {
	std::cout<<"Chess Clock Thingy\n";

	wiringPiSetup();
	pinMode(2, INPUT);

	chessClock(argv);	//the actual clock
	return EXIT_SUCCESS;
	
}

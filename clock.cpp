#include "clock.h"

bool whoseTurn = false;

void signalHandler(int sigNum) {	//change whose turn it is (SIGUSR1)
	whoseTurn = !whoseTurn;
}

int chessClock(void) {

	//TODO: get values for black and white times
	
	//TODO: calculate new values
	
	signal(SIGUSR1, signalHandler);

	return EXIT_SUCCESS;
}

int countdown(float time) {
	return time - TIME_STEP;
}


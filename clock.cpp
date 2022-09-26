#include "clock.h"

bool whoseTurn = false;

void signalHandler(int sigNum) {	//change whose turn it is (SIGUSR1)
	whoseTurn = !whoseTurn;
}

int chessClock(void) {

	//TODO: get values for black and white times
	
	signal(SIGUSR1, signalHandler);

	while(true) {
		switch(whoseTurn) {
			case 0:
				break;
			case 1:
				break;
		}
	}

	return EXIT_SUCCESS;
}

int countdown(float time) {
	return time - TIME_STEP;
}


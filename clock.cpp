#include "clock.h"

bool whoseTurn = false;

void signalHandler(int sigNum) {	//change whose turn it is (SIGUSR1)
	whoseTurn = !whoseTurn;
}

int countdown(float time) {
	return time - TIME_STEP;
}

int chessClock(void) {
	double blackTime = 0;
	double whiteTime = 0;
	
	//TODO: get values for black and white times
	
	signal(SIGUSR1, signalHandler);

	while(blackTime > 0 && whiteTime > 0) {
		switch(whoseTurn) {
			case 0:	//white's turn
				countdown(whiteTime);
				break;
			case 1: //black's turn
				countdown(blackTime);
				break;
		}
	}

	return EXIT_SUCCESS;
}

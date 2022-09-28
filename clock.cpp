#include "clock.h"

bool whoseTurn = false;
double blackTime = 0;
double whiteTime = 0;
double increment = 0;

void signalHandler(int sigNum) {	//change whose turn it is (SIGUSR1)
	whoseTurn = !whoseTurn;

	if(whoseTurn == 0) {		//if black moved, add time to white
		blackTime += increment;
	} else {
		whiteTime += increment;
	}
}

int countdown(float time) {		//decrease time by TIME_STEP
	return time - TIME_STEP;
}

int chessClock(pid_t childPID) {
	double mutualTime = 0;	
	struct timespec sec, nsec = {ZERO_SEC, ONE_MILLISEC};

//	getTimeAndIncrement(&mutualTime, &increment);	//set time as defined somewhere else I guess
//	blackTime = mutualTime;
//	whiteTime = mutualTime;
	
	signal(SIGUSR1, signalHandler);	//receive signals by the switch

	while(blackTime > 0 && whiteTime > 0) {
		switch(whoseTurn) {
			case 0:	//white's turn
				countdown(whiteTime);
				break;
			case 1: //black's turn
				countdown(blackTime);
				break;
		}
		nanosleep(&sec, &nsec);	//1 millisecond?
	}

	kill(childPID, SIGTERM);	//send SIGTERM to child process (infanticide)

	//TODO: Do something with winner or something

	return EXIT_SUCCESS;
}

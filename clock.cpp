#include "clock.h"

bool whoseTurn = false;
double blackTime = 0;
double whiteTime = 0;
double increment = 0;

void signalHandler(int sigNum) {	//change whose turn it is (SIGUSR1)
	whoseTurn = !whoseTurn;

	if(whoseTurn == 0) {		//if white's turn, add time to black
		blackTime += increment;
		std::cout << "black: " << blackTime << std::endl;
	} else {
		whiteTime += increment;
		std::cout << "white: " << whiteTime << std::endl;
	}	
}

int countdown(double *time) {		//decrease time by TIME_STEP
	*time -= TIME_STEP;
	return EXIT_SUCCESS;
}

int chessClock(pid_t childPID) {
	double mutualTime = 0;
	struct timespec nsec = {ZERO_SEC, ONE_MILLISEC};
        std::cout << "TEST" << '\n';
        string mode = getMode();
        std::cout << mode << '\n';
	int getTime = getTimeAndIncrement(mode, &mutualTime, &increment);	//set time as defined somewhere else I guess
	if (getTime == 0) {
		blackTime = mutualTime;
		whiteTime = mutualTime;
	} else {
            cerr << "[ERROR] could not get time" << endl;
            kill(childPID, SIGTERM);
            return EXIT_FAILURE;
        }
	std::cout << "time: " << mutualTime << std::endl;
	std::cout << "increment: " << increment << std::endl;
	
	//signal(SIGUSR1, signalHandler);	//receive signals by the switch

	while(blackTime > 0 && whiteTime > 0) {
		switch(whoseTurn) {
			case 0:	//white's turn
				countdown(&whiteTime);
				//std::cout << "white: " << whiteTime << std::endl;
				break;
			case 1: //black's turn
				countdown(&blackTime);
				//std::cout << "black: " << blackTime << std::endl;
				break;
		}
		nanosleep(&nsec, NULL);	//1 millisecond?
	}

	kill(childPID, SIGTERM);	//send SIGTERM to child process (infanticide)

	//TODO: Do something with winner or something

	return EXIT_SUCCESS;
}

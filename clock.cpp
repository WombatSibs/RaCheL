#include "clock.h"


int countdown(double *time) {		//decrease time by TIME_STEP
	*time -= TIME_STEP;
	return EXIT_SUCCESS;
}

int chessClock(char **argv) {
	bool gpioInput = 0;
	bool fileInput = 0;	//TODO: add space bar as second option for switch
	bool prevGpioInput = 0;
	bool prevFileInput = 0;
	bool whoseTurn = 0;
	double whiteTime = 0;
	double blackTime = 0;
	double increment = 0;
	double mutualTime = 0;
	struct timespec nsec = {ZERO_SEC, ONE_MILLISEC};
	ifstream switchMode;

        string mode = getMode();
	int getTime = getTimeAndIncrement(mode, &mutualTime, &increment);	//set time as defined somewhere else I guess
	if (getTime == 0) {
		blackTime = mutualTime;
		whiteTime = mutualTime;
	} else {
            cerr << "[ERROR] could not get time" << endl;
            return EXIT_FAILURE;
        }

	while(blackTime > 0 && whiteTime > 0) {	//repeat until timeout
		switchMode.open("io/switch_value");

		gpioInput = digitalRead(2);	//update switch value variables
		switchMode >> fileInput;

		if(gpioInput != prevGpioInput || fileInput != prevFileInput) {	//switch is pressed, other player's turn
			whoseTurn = !whoseTurn;

			if(whoseTurn == 0) {	//if white's turn, black gets increment and vice versa
				blackTime += increment;
			} else {
				whiteTime += increment;
			}
		}

		switch(whoseTurn) {
			case 0:	//white's turn
				countdown(&whiteTime);
				break;
			case 1: //black's turn
				countdown(&blackTime);
				break;
		}
		writeTimes(whiteTime, blackTime);
		nanosleep(&nsec, NULL);	//1 millisecond? (i think)
		
		prevGpioInput = gpioInput;
		prevFileInput = fileInput;

		cout << "\rWhite: " << whiteTime << "\tBlack: " << blackTime;

		switchMode.close();
	}
	cout << endl;


	if(whiteTime <= 0) {
		cout << "\aBlack won!" << endl;
	} else {
		cout << "\aWhite won!" << endl;
	}

	return EXIT_SUCCESS;
}

#include "hardwareSwitch.h"

bool sendable = false;

void allowSignals(int sigNum) {
	sendable = true;
}

int hardwareSwitch() {	//dummy switch
	bool gpioInput = 0;
	struct timespec nsec = {1, 10000000};

	signal(SIGUSR2, allowSignals);

	wiringPiSetup();
	pinMode(0, INPUT);

	while(sendable) {
		if(gpioInput != digitalRead(0)) {
			kill(getppid(), SIGUSR1);
			//nanosleep(&nsec, NULL);
		}
	}

	return EXIT_SUCCESS;
}

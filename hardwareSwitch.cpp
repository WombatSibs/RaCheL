#include "hardwareSwitch.h"

bool sendable = false;

void allowSignals(int sigNum) {
	sendable = true;
}

int hardwareSwitch() {	//dummy switch
	struct timespec nsec = {1, 10000000};

	signal(SIGUSR2, allowSignals);

	while(true) {
		if(sendable) {
			kill(getppid(), SIGUSR1);
			nanosleep(&nsec, NULL);
		}
	}

	return EXIT_SUCCESS;
}

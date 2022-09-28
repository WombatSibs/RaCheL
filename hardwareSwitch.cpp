#include "hardwareSwitch.h"

int hardwareSwitch() {	//dummy switch
	struct timespec nsec = {1, 10000000};
	while(true) {
		kill(getppid(), SIGUSR1);
		nanosleep(&nsec, NULL);
	}

	return EXIT_SUCCESS;
}

#include "hardwareSwitch.h"


bool sendable = false;

void allowSignals(int sigNum) {
	sendable = true;
}

int hardwareSwitch() {	//dummy switch
	bool gpioInput = 0;
	bool fileInput = 0;
	bool prevGpioInput = 0;
	bool prevFileInput = 0;
	struct timespec nsec = {1, 10000000};

	ifstream switchMode;
	switchMode.open("io/switch_value");

	if(switchMode.is_open()) {
		switchMode >> fileInput;
	} else {
		cerr << "[ERROR]: File not found!" << endl;
		return EXIT_FAILURE;
	}

	signal(SIGUSR2, allowSignals);

//	wiringPiSetup();
//	pinMode(0, INPUT);

	while(sendable) {
		//gpioInput = digitalRead(0);
		switchMode >> fileInput;
		if(fileInput != prevFileInput || gpioInput != prevGpioInput) {
			kill(getppid(), SIGUSR1);
			nanosleep(&nsec, NULL);
		}
		prevGpioInput = gpioInput;
		prevFileInput = fileInput;
	}

	return EXIT_SUCCESS;
}

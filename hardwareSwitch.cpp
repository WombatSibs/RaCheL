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

	cout << "1" << endl;

	while(!sendable) {
		signal(SIGUSR2, allowSignals);
	}

//	wiringPiSetup();
//	pinMode(2, INPUT);

	cout << "2" << endl;

	while(sendable) {
		switchMode.open("io/switch_value");

		gpioInput = digitalRead(2);
		switchMode >> fileInput;

		cout << gpioInput << endl;

		if(fileInput != prevFileInput || gpioInput != prevGpioInput) {
			kill(getppid(), SIGUSR1);
			nanosleep(&nsec, NULL);
		}
		prevGpioInput = gpioInput;
		prevFileInput = fileInput;

		switchMode.close();
	}

	return EXIT_SUCCESS;
}

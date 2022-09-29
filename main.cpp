#include "main.h"

int main(int argc, char **argv) {
	std::cout<<"Chess Clock Thingy\n";

        std::string modetest;
        modetest = getMode();
        std::cout << modetest << '\n';

	pid_t pid = fork();
	switch(pid) {
		case 0:		//switch
			hardwareSwitch();
			return EXIT_SUCCESS;
		default:	//clock
			//glutInit(&argc, argv);
			//createWindow();
			//glutMainLoop();
			chessClock(pid);	//the actual clock
			wait(NULL);
			return EXIT_SUCCESS;
	}
}

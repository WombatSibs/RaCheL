#include "main.h"

int main(int argc, char **argv) {
	std::cout<<"Chess Clock Thingy\n";

	pid_t pid = fork();
	switch(pid) {
		case 0:		//switch
			std::cout<<"child\n";
			return EXIT_SUCCESS;
		default:	//clock
			//glutInit(&argc, argv);
			//createWindow();
			//glutMainLoop();
			chessClock(pid);	//the actual clock
			wait(NULL);
			std::cout<<"parent\n";
			return EXIT_SUCCESS;
	}
}

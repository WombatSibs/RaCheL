#include "main.h"

int main() {
	std::cout<<"Chess Clock Thingy\n";

	pid_t pid = fork();
	switch(pid) {
		case 0:		//switch
			std::cout<<"child\n";
			return EXIT_SUCCESS;
		default:	//clock 
			chessClock(pid);	//the actual clock
			wait(NULL);
			std::cout<<"parent\n";
			return EXIT_SUCCESS;
	}
}

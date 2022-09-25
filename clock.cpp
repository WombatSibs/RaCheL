#include <iostream>

int countdown(float initial, int increment) {
	while(initial) {
		initial -= 0.001;
		nanosleep(1000000);
	}

	return initial;
}

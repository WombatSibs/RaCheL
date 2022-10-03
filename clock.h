#include <iostream>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fstream>
#include <wiringPi.h>

#include "files.h"

using namespace std;

#define TIME_STEP 0.001

enum {ZERO_SEC = 0, ONE_MILLISEC = 1000000};

int chessClock(char **argv);

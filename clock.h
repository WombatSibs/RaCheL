#include <iostream>
#include <signal.h>
#include <time.h>

#include "files.h"

#define TIME_STEP 0.001

enum {ZERO_SEC = 0, ONE_MILLISEC = 1000000};

int chessClock(pid_t childPID);

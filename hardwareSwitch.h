#include <iostream>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fstream>
extern "C" {
#include <wiringPi.h>
}

using namespace std;

int hardwareSwitch();

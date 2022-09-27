#include <iostream>
#include <fstream>


int listenSwitch()
{
    std :: ifstream switchfile ("dev/switch_value");
    int switch_value = 0;
    switchfile >> switch_value; //read("switch_value");
    return switch_value;
}

int getTime()
{
    double name[2];
    
}

int main()
{
    int switch_value;
    switch_value = listenSwitch();
    std :: cout << switch_value;
}


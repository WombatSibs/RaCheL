#include "files.h"

int listenSwitch() // reads value of switch (0 or 1) from file 'switch_value'
{
    int switch_value = 0;
    ifstream switchfile;
    switchfile.open("io/switch_value");
    if (switchfile.is_open())
    { 
        switchfile >> switch_value; //read("switch_value");
    } else {
        cout << "[ERROR]: Could not open file 'switch_value'" << endl;
    }
    switchfile.close();
    return switch_value;
}

string getMode() // reads name of mode from file 'current_mode'
{
    string mode;
    ifstream current_mode_file;
    current_mode_file.open("io/current_mode");		//TODO: ERROR!!!
    cout << "vor if" << endl;
    if (current_mode_file.is_open())
    { 
        cout << "in if" << endl;
        current_mode_file >> mode; //read("switch_value");
    } else {
        cerr << "[ERROR]: Could not open file 'current_mode'" << endl;
        return NULL;
    }
    current_mode_file.close();
    return mode;
}

int writeTimes(double white, double black) // writes out the times for white and black into the files 'white_time' and 'black_time'
{
    ofstream white_time_file;
    ofstream black_time_file;

    white_time_file << white;
    black_time_file << black;

    white_time_file.close();
    black_time_file.close();
    return EXIT_SUCCESS;
}

int getTimeAndIncrement(string mode, double* time, double* increment) // checks if reads from file 'possible_modes' and ???
{
    cout << "Anfang getTimeAndIncrement" << endl;
    string line;
    ifstream modes_file;
    bool found_mode;

    modes_file.open("io/possible_modes");
    cout << "nach oeffnen" << endl;

    if (modes_file.is_open())
    {
        cout << "anfang anfang if" << endl;
        string possible_mode;
        string h_str;
        string m_str;
        string s_str;
        double hours;
        double minutes;
        double seconds;

        cout << "Anfang if" << endl;

        getline(modes_file, line);  // ignore first line 
        cout << "erste ignorierte Zeile: " << line << endl;
        while (modes_file >> possible_mode) //getline(modes_file, line))
        {
            cout << "Anfang while" << endl;
            getline(modes_file, h_str, ':');
            getline(modes_file, m_str, ':');
            getline(modes_file, s_str, ' ');
            modes_file >> *increment;
            cout << "read possible mode: " << possible_mode << endl;
            cout << "read possible time: " << h_str << ':' << m_str << ':' << s_str << '\n';
            if (possible_mode == mode)
            {
                found_mode = true;
                hours = stod(h_str);
                minutes = stod(m_str);
                seconds = stod(s_str);
                *time = 60 * 60 * hours + 60 * minutes + seconds;
                break;
            }
            cout << "time matching chosen mode in seconds: " << time << '\n';
            cout << "increment: " << increment << endl;
        }
    } else {
        cerr << "[ERROR]: Could not open file 'possible_modes'" << endl;
	return EXIT_FAILURE;
    }
    if (!found_mode)
    {
        cout << "[WARNING]: Specified mode not defined in 'possible_modes'" << endl;
    }
    modes_file.close();
    return EXIT_SUCCESS;
}

// just for testing:
/*int main()
{
    double time;
    double increment;
    string name = getMode();
    int switch_value;
    switch_value = listenSwitch();
    cout << "Switch value: " << switch_value << endl;
    getTimeAndIncrement(name, &time, &increment);
    cout << "Time in Seconds: " << time << endl;
    cout << "Increment in Seconds: " << increment << endl;
}
*/


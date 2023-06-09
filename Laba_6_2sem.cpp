#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

enum LogLevel
{
    INFO,
    DEBUG,
    ERROR
};

class Logger
{
private:
    LogLevel level;
    string filename;
    bool fI;
    bool fD;
    bool fE;

    string getTimestamp()
    {
        time_t now = std::time(nullptr);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%d.%m.%Y %H:%M:%S", localtime(&now));
        return std::string(timestamp);
    }

public:
    Logger(string filename = "log.txt")
    {
        this->filename = filename;
    }

    void log(bool fI, bool fD, bool fE, string message)
    {
        ofstream logFile(filename, ios::app);
        if (level >= this->level)
        {
            string timestamp = getTimestamp();

            if (fI == 1)
            {
                string logMessage = "[INFO][" + timestamp + "]" + message;
                cout << "[INFO][" << timestamp.substr(11) << "]" << message << endl;
                logFile << logMessage << endl;
            }
            if (fD == 1)
            {
                string logMessage = "[DEBUG][" + timestamp + "]" + message;
                cout << "[DEBUG][" << timestamp.substr(11) << "]" << message << endl;
                logFile << logMessage << endl;
            }
            if (fE == 1)
            {
                string logMessage = "[ERROR][" + timestamp + "]" + message;
                cout << "[ERROR][" << timestamp.substr(11) << "]" << message << endl;
                logFile << logMessage << endl;
            }
        }
        logFile.close();
    }

    void setLevel(LogLevel level)
    {
        this->level = level;
    }

    void setFilename(string filename)
    {
        this->filename = filename;
    }
};

int main()
{
    bool fI, fD, fE, a = 0, b = 0;
    cout << "Write turn on or off Info, Debug, Error" << endl;
    cin >> fI;
    cin >> fD;
    cin >> fE;
    Logger logger("log.txt");

    logger.log(fI, a, b, "Print message 'Hello World'");
    logger.log(a, fD, b, "Program is running");
    logger.log(a, b, fE, "This is an error message");

    return 0;
}
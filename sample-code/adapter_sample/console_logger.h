#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H

#include <string>

using namespace std;

class ConsoleLogger
{
public:
    ConsoleLogger() {}
    virtual ~ConsoleLogger() {}
    virtual void LogError(string message);
    virtual void LogInfo(string message);
};

#endif

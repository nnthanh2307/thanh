#ifndef SERIAL_LOGGER_H
#define SERIAL_LOGGER_H
#include <string>

using namespace std;

class SerialLogger
{
public:
    virtual ~SerialLogger() {}
    void error(string message);
    void info(string message);
};

#endif

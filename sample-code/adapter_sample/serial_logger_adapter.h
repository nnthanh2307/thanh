#include "console_logger.h"
#include "serial_logger.h"

#include <string>

using namespace std;

class SerialLoggerAdapter : public ConsoleLogger
{
private:
    SerialLogger *_logger;

public:
    SerialLoggerAdapter(SerialLogger *logger): _logger(logger) {}

    ~SerialLoggerAdapter()  {
        delete _logger;
    }
    void LogError(string message);
    void LogInfo(string message);
};

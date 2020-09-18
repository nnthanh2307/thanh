#ifndef CLIENT_H
#define CLIENT_H

#include "console_logger.h"

class Client
{
private:
    ConsoleLogger *_logger;
public:
    Client(ConsoleLogger *logger): _logger(logger) {
    }

    ~Client() {
        delete _logger;
    }

    void sampleMethod();
};
#endif


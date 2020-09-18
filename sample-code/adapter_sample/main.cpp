#include "client.h"
#include "console_logger.h"
#include "serial_logger.h"
#include "serial_logger_adapter.h"
#include <iostream>
using namespace std;

int main(int argc, char*argv[]) {
    ConsoleLogger *clogger = new ConsoleLogger();
    Client *client = new Client(clogger);

    client->sampleMethod();

    // Use new serial log
    SerialLogger *slogger = new SerialLogger();
    SerialLoggerAdapter *sloggerAdapter = new SerialLoggerAdapter(slogger);
    Client *newclient = new Client(sloggerAdapter);

    newclient->sampleMethod();

    delete client;
    delete newclient;

    return 0;
}

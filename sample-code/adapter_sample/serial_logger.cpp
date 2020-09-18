#include "serial_logger.h"

#include <iostream>

void SerialLogger::info(string message) {
    cout << "[SERIAL][INFO]" << message << endl;
}
void SerialLogger::error(string message) {
    cout << "[SERIAL][ERROR]" << message << endl;
}

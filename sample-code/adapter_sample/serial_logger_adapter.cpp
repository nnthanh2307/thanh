#include "serial_logger_adapter.h"
#include <iostream>

void SerialLoggerAdapter::LogError(string message) {
    _logger->error(message);
}

void SerialLoggerAdapter::LogInfo(string message) {
    _logger->info(message);
}

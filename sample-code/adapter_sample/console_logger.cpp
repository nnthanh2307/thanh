#include "console_logger.h"

#include <iostream>

void ConsoleLogger::LogError(string message) {
    cout << "[CONSOLE][ERROR]" << message << endl;
}
void ConsoleLogger::LogInfo(string message) {
    cout << "[CONSOLE][INFO]" << message << endl;
}

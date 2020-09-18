#include <iostream>
#include "client.h"

void Client::sampleMethod()
{
    try
    {
        // some code
        _logger->LogInfo("This is a log message.");
    }
    catch (const std::exception &ex)
    {
        _logger->LogError(ex.what());
    }
}

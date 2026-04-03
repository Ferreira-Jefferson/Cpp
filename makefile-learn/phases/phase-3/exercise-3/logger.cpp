#include "logger.hpp"
#include <iostream>

Logger::Logger(const std::string& prefix) : _prefix(prefix) {}

void Logger::log(const std::string& msg) const
{
    std::cout << "[" << _prefix << "] " << msg << std::endl;
}

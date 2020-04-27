//
// Created by andrey on 4/27/20.
//

#include "iostream"
#include "Logger.h"

std::string Logger::getCurrentTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

void Logger::info(std::string message) {
    std::cout << getCurrentTime() << " : " << message << std::endl;
}

//
// Created by andrey on 4/27/20.
//

#ifndef CPP_LOGGER_H
#define CPP_LOGGER_H


#include <string>

class Logger {
    std::string getCurrentTime();

public:
    void info(std::string message);

};


#endif //CPP_LOGGER_H

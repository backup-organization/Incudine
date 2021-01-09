#ifndef IGNITE_LOG_H
#define IGNITE_LOG_H

#include <ostream>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

class Log {
    Log();
public:
    static auto getLogger() -> Log*;
    auto getPath() -> std::string;
    auto write(const std::string& toWrite) -> Log*;
    auto write(uintptr_t toWrite, bool hex) -> Log*;
    auto write(void* toWrite, bool hex) -> Log*;
    auto writeLine(const std::string &toWrite) -> Log*;
    auto writeLine() -> Log*;
};

#endif /* IGNITE_LOG_H */

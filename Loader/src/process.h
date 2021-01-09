#ifndef IGNITE_PROCESS_H
#define IGNITE_PROCESS_H

#include <iostream>
#include <windows.h>
#include <TlHelp32.h>

class process {
public:
    static auto getPID(const std::string& name) -> DWORD;
};

#endif //IGNITE_PROCESS_H

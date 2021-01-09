#ifndef IGNITE_LOADLIB_H
#define IGNITE_LOADLIB_H

#include <iostream>
#include <windows.h>
#include "process.h"

class loadlib {
public:
    static auto inject(const std::string& image, const DWORD& target) -> bool;
};


#endif //IGNITE_LOADLIB_H

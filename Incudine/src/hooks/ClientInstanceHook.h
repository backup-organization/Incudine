#ifndef INCUDINE_CLIENTINSTANCEHOOK_H
#define INCUDINE_CLIENTINSTANCEHOOK_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include "polyhook2/Detour/x64Detour.hpp"
#include "polyhook2/CapstoneDisassembler.hpp"
#include "../bridge/ClientInstance.h"
#include "../util/IMem.h"
#include "../util/SigInfo.h"

class ClientInstanceHook {
public:
    static auto hook() -> HRESULT;
private:
    static inline uint64_t clientInstanceOriginal = 0;
    static auto clientInstanceCallback(uintptr_t clientInstance, char param_2) -> int;
};


#endif //INCUDINE_CLIENTINSTANCEHOOK_H
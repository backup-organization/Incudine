#ifndef INCUDINE_KEYHOOK_H
#define INCUDINE_KEYHOOK_H

#include <iostream>
#include <windows.h>
#include <polyhook2/Detour/x64Detour.hpp>
#include <polyhook2/CapstoneDisassembler.hpp>
#include "../util/IMem.h"
#include "../util/InputUtils.h"

class KeyHook {
public:
    static auto hook() -> HRESULT;
private:
    static inline uint64_t keyPressOriginal = 0;
    static auto keyPressCallback(int vKey, int state) -> int;
};


#endif //INCUDINE_KEYHOOK_H

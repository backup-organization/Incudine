#ifndef IGNITE_MOUSEHOOK_H
#define IGNITE_MOUSEHOOK_H

#include <iostream>
#include <windows.h>
#include <polyhook2/Detour/x64Detour.hpp>
#include <polyhook2/CapstoneDisassembler.hpp>
#include "../util/IMem.h"
#include "../util/InputUtils.h"

class MouseHook {
public:
    static auto hook() -> HRESULT;
private:
    static inline uint64_t mouseInputOriginal = 0;
    static auto mouseHookCallback(UINT64 param_1, int action, UINT64 param_3, UINT64 param_4, UINT64 param_5, short param_6, short param_7, byte param_8) -> int;
};


#endif //IGNITE_MOUSEHOOK_H

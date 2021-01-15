#ifndef INCUDINE_MOUSEHOOK_H
#define INCUDINE_MOUSEHOOK_H

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
    static auto __fastcall mouseHookCallback(uintptr_t mouseItem, char button, bool isDown, short mouseX, short mouseY, short locX, short locY, char param_8) -> int;
};


#endif //INCUDINE_MOUSEHOOK_H

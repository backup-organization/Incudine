#include "MouseHook.h"


auto __fastcall MouseHook::mouseHookCallback(uintptr_t mouseItem, char button, bool isDown, short mouseX, short mouseY, short locX, short locY, char param_8) -> int {
    InputUtils::setButtonState(button, isDown);
    return PLH::FnCast(mouseInputOriginal, &mouseHookCallback)(mouseItem, button, isDown, mouseX, mouseY, locX, locY, param_8);
}

auto MouseHook::hook() -> HRESULT  {
    Log::getLogger()->writeLine("Installing mouse hook...");
    long long mouseInputAddr = IMem::findSig("48 8B ?? ?? 89 ?? ?? ?? 89 ?? ?? ?? 89 ?? ?? 57 41 ?? 41 ?? 41 ?? 41 ?? 48 83 ?? ?? 44");

    if (!mouseInputAddr) {
        return E_FAIL;
    }

    PLH::CapstoneDisassembler dis(PLH::Mode::x64);
    PLH::x64Detour detourHook((char*)mouseInputAddr, (char*)&mouseHookCallback, &mouseInputOriginal, dis);

    if (!detourHook.hook()) {
        return E_FAIL;
    }

    Log::getLogger()->writeLine("Mouse hook success");
    return S_OK;
}
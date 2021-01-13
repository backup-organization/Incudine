#include "KeyHook.h"

auto KeyHook::keyPressCallback(int vKey, int state) -> int {
    InputUtils::setKeyState((char)vKey, (bool)state);
    return PLH::FnCast(keyPressOriginal, &keyPressCallback)(vKey, state);
}

auto KeyHook::hook() -> HRESULT {
    Log::getLogger()->writeLine("Installing key hook...");
    long long keyHookAddr = IMem::findSig("89 ?? ?? ?? 57 48 83 ?? ?? 8B 05 ?? ?? ?? ?? 8B")-1;

    if (!keyHookAddr) {
        return E_FAIL;
    }

    PLH::CapstoneDisassembler dis(PLH::Mode::x64);
    PLH::x64Detour detourHook((char*)keyHookAddr, (char*)&keyPressCallback, &keyPressOriginal, dis);

    if (!detourHook.hook()) {
        return E_FAIL;
    }

    Log::getLogger()->writeLine("Key hook success");
    return S_OK;
}

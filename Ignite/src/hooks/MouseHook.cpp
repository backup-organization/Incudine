#include "MouseHook.h"


auto MouseHook::mouseHookCallback(UINT64 param_1, int action, UINT64 param_3, UINT64 param_4, UINT64 param_5, short param_6, short param_7, byte param_8) -> int {
    bool isDown = (bool)param_7;
    InputUtils::setButtonState(action, isDown);
    return PLH::FnCast(mouseInputOriginal, &mouseHookCallback)(param_1, action, param_3, param_4, param_5, param_6, param_7, param_8);
}

auto MouseHook::hook() -> HRESULT  {
    long long mouseInputAddr = IMem::findSig("48 8B ?? ?? 89 ?? ?? ?? 89 ?? ?? ?? 89 ?? ?? 57 41 ?? 41 ?? 41 ?? 41 ?? 48 83 ?? ?? 44");

    if (!mouseInputAddr) {
        return E_FAIL;
    }

    PLH::CapstoneDisassembler dis(PLH::Mode::x64);
    PLH::x64Detour detourHook((char*)mouseInputAddr, (char*)&mouseHookCallback, &mouseInputOriginal, dis);

    if (!detourHook.hook()) {
        return E_FAIL;
    }

    return S_OK;
}
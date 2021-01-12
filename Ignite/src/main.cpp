#include <windows.h>
#include "util/Log.h"
#include "util/IMem.h"
#include "hooks/ClientInstanceHook.h"
#include "hooks/KeyHook.h"
#include "hooks/MouseHook.h"
#include "hooks/UIContextHook.h"
#include "modules/ModuleManager.h"

auto startIgnite() -> int {
    Log::getLogger()->writeLine("Loading Ignite...");

    ClientInstanceHook::hook();
    KeyHook::hook();
    MouseHook::hook();
    UIContextHook::hook();

    ModuleManager::getModuleManager();

    Log::getLogger()->write("ClientInstance*: ")->write(IMem::getClientInstance()->getAddress(), true)->writeLine();
    Log::getLogger()->write("GuiData*: ")->write(IMem::getClientInstance()->getGuiData()->getAddress(), true)->writeLine();
    Log::getLogger()->write("LocalPlayer*: ")->write(IMem::getClientInstance()->getLocalPlayer()->getAddress(), true)->writeLine();
    return 0;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD callReason, LPVOID lpReserved) {
    switch(callReason) {
        case DLL_PROCESS_ATTACH:
            CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)startIgnite, hModule, 0, nullptr);
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}
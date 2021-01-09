#include "loadlib.h"

auto loadlib::inject(const std::string& image, const DWORD& target) -> bool {
    const auto LoadLibraryA = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
    if(!LoadLibraryA) {
        OutputDebugStringA("Failed to get LoadLibraryA");
        return false;
    }

    const auto hProc = OpenProcess(PROCESS_ALL_ACCESS, false, target);
    if(!hProc) {
        OutputDebugStringA("Failed to get process handle");
        return false;
    }

    const auto remote = VirtualAllocEx(hProc, nullptr, strlen(image.c_str()), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if(!remote) {
        OutputDebugStringA("Failed to allocate memory in address space");
        return false;
    }

    if(!WriteProcessMemory(hProc, remote, image.c_str(), strlen(image.c_str()), nullptr)) {
        OutputDebugStringA("Failed to WriteProcessMemory");
        return false;
    }

    if(!CreateRemoteThread(hProc, nullptr, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryA, (LPVOID)remote, NULL, nullptr)) {
        OutputDebugStringA("Failed to CreateRemoteThread");
        return false;
    }
    return true;
}

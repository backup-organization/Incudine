#include "IMem.h"

auto IMem::getModuleBase() -> long long {
    return (long long)GetModuleHandleA(nullptr);
}

auto IMem::getModuleBaseHandle() -> HMODULE {
    return GetModuleHandleA(nullptr);
}

auto IMem::getBaseModuleSize() -> long long {
    MODULEINFO info;
    GetModuleInformation(GetCurrentProcess(), getModuleBaseHandle(), &info, sizeof(info));
    return info.SizeOfImage;
}

auto IMem::getBaseModuleEnd() -> long long {
    return getModuleBase() + getBaseModuleSize();
}

auto IMem::findSig(const char* pattern) -> uintptr_t {
    return findSig(getModuleBase(), getBaseModuleEnd(), pattern);
}
auto IMem::findSig(long long rangeStart, long long rangeEnd, const char* pattern) -> uintptr_t {
    const char* pat = pattern;
    long long firstMatch = 0;
    for (long long pCur = rangeStart; pCur < rangeEnd; pCur++) {
        if (!*pat) return firstMatch;
        if (*(PBYTE)pat == '\?' || *(BYTE*)pCur == getByte(pat)) {
            if (!firstMatch) firstMatch = pCur;
            if (!pat[2]) return firstMatch;
            if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?') pat += 3;
            else pat += 2;
        } else {
            pat = pattern;
            firstMatch = 0;
        }
    }
    return 0;
}

auto IMem::unprotectMem(void* addr, int len) -> void {
    DWORD curProtection;
    VirtualProtect(addr, len, PAGE_EXECUTE_READWRITE, &curProtection);
}

auto IMem::setClientInstance(struct ClientInstance* instance) -> void {
    clientInstance = instance;
}
auto IMem::getClientInstance() -> struct ClientInstance* {
    return clientInstance;
}
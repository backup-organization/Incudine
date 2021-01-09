#include "process.h"

auto process::getPID(const std::string& name) -> DWORD {
    DWORD pid = 0;
    PROCESSENTRY32 processInfo;
    processInfo.dwSize = sizeof(PROCESSENTRY32);

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if(snapshot == INVALID_HANDLE_VALUE)
        return 0;

    Process32First(snapshot, &processInfo);
    if(name == processInfo.szExeFile) {
        CloseHandle(snapshot);
        pid = processInfo.th32ProcessID;
    }

    while(Process32Next(snapshot, &processInfo)) {
        if(name == processInfo.szExeFile) {
            CloseHandle(snapshot);
            pid = processInfo.th32ProcessID;
        }
    }
    return pid;
}
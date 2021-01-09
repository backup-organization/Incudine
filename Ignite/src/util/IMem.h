#ifndef IGNITE_IMEM_H
#define IGNITE_IMEM_H

#define INRANGE(x,a,b)	(x >= a && x <= b)
#define getBits( x )	(INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )	(getBits(x[0]) << 4 | getBits(x[1]))

#include <Windows.h>
#include <Psapi.h>

#include "../bridge/ClientInstance.h"

class IMem {
    static inline struct ClientInstance* clientInstance = nullptr;
public:
    static auto findSig(const char* pattern) -> uintptr_t;
    static auto findSig(long long rangeStart, long long rangeEnd, const char* pattern) -> uintptr_t;
    static auto getModuleBase() -> long long;
    static auto getModuleBaseHandle() -> HMODULE;
    static auto getBaseModuleSize() -> long long;
    static auto getBaseModuleEnd() -> long long;
    static auto unprotectMem(void* addr, int len) -> void;
    static auto setClientInstance(uintptr_t clientInstance) -> void;
    static auto getClientInstance() -> struct ClientInstance*;
};


#endif //IGNITE_IMEM_H

#include "ClientInstanceHook.h"
#include "../util/Log.h"

std::vector<SigInfo*>* signatures;

auto ClientInstanceHook::clientInstanceCallback_1_16_201_2(uintptr_t theInstance, char param_2) -> int {
    IMem::setClientInstance(theInstance);
    return PLH::FnCast(clientInstanceOriginal, &clientInstanceCallback_1_16_201_2)(theInstance, param_2);
}
auto __fastcall ClientInstanceHook::clientInstanceCallback_1_12_1_1(uintptr_t theInstance, uintptr_t param_2) -> int {
    IMem::setClientInstance(theInstance);
    return PLH::FnCast(clientInstanceOriginal, &clientInstanceCallback_1_12_1_1)(theInstance, param_2);
}

auto ClientInstanceHook::hook() -> HRESULT {
    signatures = new std::vector<SigInfo*>();
    signatures->push_back(new SigInfo(new std::string("89 ?? ?? ?? 57 48 83 ?? ?? ?? 29 ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? 48 ?? ?? 48 8B ?? 48 8B ?? ?? ?? ?? ?? ?? ?? 48"), -1)); //1.12.1.1
    signatures->push_back(new SigInfo(new std::string("48 8B ?? 55 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? C7 ?? ?? ?? ?? ?? ?? ?? 89 ?? ?? ?? 89 ?? ?? ?? 89 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 44 0F ?? ?? 48 8B ?? 45"), 0)); //Version unspecified
    signatures->push_back(new SigInfo(new std::string("89 ?? ?? ?? ?? 89 ?? ?? ?? ?? 89 ?? ?? ?? 55 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 44 0F ?? ?? 48 8B ?? 45"), -1)); //1.16.201.2

    long long clientInstanceHookAddr = 0;
    int index = 0;
    while(clientInstanceHookAddr == 0) {
        if(index > signatures->size()) {
            Log::getLogger()->writeLine("ClientInstanceHook All signatures failed");
            return E_FAIL;
        }
        SigInfo* info = signatures->at(index);
        std::string* sig = info->signature;
        int offset = info->offset;

        clientInstanceHookAddr = IMem::findSig(sig->c_str());
        if(clientInstanceHookAddr != 0) {
            clientInstanceHookAddr += offset;
        }
        index++;
    }

    Log::getLogger()->write("ClientInstanceHook Signature ")->write(index, false)->writeLine(" success")->write("Client Instance Hook Addr: ")->write(clientInstanceHookAddr, true)->writeLine();

    signatures->clear();
    delete signatures;

    Log::getLogger()->writeLine("Cleaned up signature memory");

    PLH::CapstoneDisassembler dis(PLH::Mode::x64);
    SupportedVersion version = VersionUtils::getVersion();
    switch(version) {
    case MC_1_12_1_1:
        PLH::x64Detour detourHook((char*)clientInstanceHookAddr, (char*)&clientInstanceCallback_1_12_1_1, &clientInstanceOriginal, dis);
        break;
    default:
        PLH::x64Detour detourHook((char*)clientInstanceHookAddr, (char*)&clientInstanceCallback_1_16_201_2, &clientInstanceOriginal, dis);
        break;
    }

    Log::getLogger()->writeLine("Created detour hook instance");

    if (!detourHook.hook()) {
        Log::getLogger()->write("ClientInstanceHook hook failure");
        return E_FAIL;
    }

    Log::getLogger()->write("ClientInstanceHook success");

    return S_OK;
}
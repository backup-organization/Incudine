#include "ClientInstanceHook.h"
#include "../util/Log.h"

std::vector<SigInfo*>* signatures;

auto ClientInstanceHook::clientInstanceCallback(uintptr_t theInstance, char param_2) -> int {
    IMem::setClientInstance(theInstance);
    //Log::getLogger()->write("Client instance address: ")->write((uintptr_t)theInstance, true)->writeLine("");
    return PLH::FnCast(clientInstanceOriginal, &clientInstanceCallback)(theInstance, param_2);
}

auto ClientInstanceHook::hook() -> HRESULT {
    signatures = new std::vector<SigInfo*>();
    signatures->push_back(new SigInfo(new std::string("89 ?? ?? ?? ?? 89 ?? ?? ?? ?? 89 ?? ?? ?? 55 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 44 0F ?? ?? 48 8B ?? 45"), -1));
    signatures->push_back(new SigInfo(new std::string("48 8B ?? 55 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? C7 ?? ?? ?? ?? ?? ?? ?? 89 ?? ?? ?? 89 ?? ?? ?? 89 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 44 0F ?? ?? 48 8B ?? 45"), 0));

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
    PLH::x64Detour detourHook((char*)clientInstanceHookAddr, (char*)&clientInstanceCallback, &clientInstanceOriginal, dis);

    Log::getLogger()->writeLine("Created detour hook instance");

    if (!detourHook.hook()) {
        Log::getLogger()->write("ClientInstanceHook hook failure");
        return E_FAIL;
    }

    Log::getLogger()->write("ClientInstanceHook success");

    return S_OK;
}
#ifndef INCUDINE_CLIENTINSTANCE_H
#define INCUDINE_CLIENTINSTANCE_H

#include "DynamicStruct.h"
#include "LocalPlayer.h"
#include "GuiData.h"
#include "../util/VersionUtils.h"

struct ClientInstance : DynamicStruct {
    GuiData* guiData = nullptr;
    LocalPlayer* localPlayer = nullptr;

    ClientInstance(uintptr_t address) : DynamicStruct("ClientInstance", 0) {
        this->setAddress(address);
        SupportedVersion version = VersionUtils::getVersion();
        this->addVirtual(new DynamicMethod("getLocalPlayer", 23));
        switch(version) {
        case MC_1_12_1_1:
            this->addVirtual(new DynamicMethod("getGuiData", 181));
            break;
        default:
            this->addVirtual(new DynamicMethod("getGuiData", 194));
            break;
        }
    };

    auto getLocalPlayer() -> LocalPlayer* {
        DynamicMethod* getLP = (DynamicMethod*)this->get("getLocalPlayer");
        uintptr_t(__fastcall** theFn)(uintptr_t) = (uintptr_t(__fastcall**)(uintptr_t))getLP->asVoid();
        if(!localPlayer)
            localPlayer = new LocalPlayer();
        localPlayer->setAddress((*theFn)(this->getAddress()));
        return localPlayer;
    }
    auto getGuiData() -> GuiData* {
        DynamicMethod* getGD = (DynamicMethod*)this->get("getGuiData");
        uintptr_t(__fastcall** theFn)(uintptr_t) = (uintptr_t(__fastcall**)(uintptr_t))getGD->asVoid();
        if(!guiData)
            guiData = new GuiData();
        guiData->setAddress((*theFn)(this->getAddress()));
        return guiData;
    }
};

#endif /* INCUDINE_CLIENTINSTANCE_H */

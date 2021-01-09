#ifndef IGNITE_CLIENTINSTANCE_H
#define IGNITE_CLIENTINSTANCE_H

#include "DynamicStruct.h"
#include "LocalPlayer.h"
#include "GuiData.h"

struct ClientInstance : DynamicStruct {
    GuiData* guiData = nullptr;
    LocalPlayer* localPlayer = nullptr;

    ClientInstance(uintptr_t address) : DynamicStruct("ClientInstance") {
        this->setAddress(address);
        this->addVirtual(new DynamicMethod("getLocalPlayer"), 23);
        this->addVirtual(new DynamicMethod("getGuiData"), 194);
    };

    auto getLocalPlayer() -> LocalPlayer* {
        DynamicMethod* getLP = (DynamicMethod*)this->get("getLocalPlayer");
        uintptr_t(__fastcall** theFn)(uintptr_t)  = (uintptr_t(__fastcall**)(uintptr_t))getLP->asVoid();
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

#endif /* IGNITE_CLIENTINSTANCE_H */

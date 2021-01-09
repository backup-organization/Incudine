#ifndef IGNITE_CLIENTINSTANCE_H
#define IGNITE_CLIENTINSTANCE_H

#include "DynamicStruct.h"
#include "LocalPlayer.h"
#include "GuiData.h"

struct ClientInstance : DynamicStruct {
    ClientInstance(uintptr_t address) : DynamicStruct("ClientInstance", address) {
        this->addVirtual("getLocalPlayer", 23);
        this->addVirtual("getGuiData", 194);
    };

    auto getLocalPlayer() -> LocalPlayer* {
        DynamicMethod* getLP = (DynamicMethod*)this->get("getLocalPlayer");
        void*(* theFn)()  = (void*(*)())getLP->asVoid();
        return (LocalPlayer*)theFn();
    }
    auto getGuiData() -> GuiData* {
        DynamicMethod* getGD = (DynamicMethod*)this->get("getGuiData");
        void*(* theFn)()  = (void*(*)())getGD->asVoid();
        return (GuiData*)theFn();
    }
};

#endif /* IGNITE_CLIENTINSTANCE_H */

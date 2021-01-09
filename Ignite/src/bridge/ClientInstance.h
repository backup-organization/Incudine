#ifndef IGNITE_CLIENTINSTANCE_H
#define IGNITE_CLIENTINSTANCE_H

#include "DynamicStruct.h"
#include "LocalPlayer.h"

struct ClientInstance : DynamicStruct {
    ClientInstance(uintptr_t address) : DynamicStruct("ClientInstance", address) {
        this->addVirtual("getLocalPlayer", 23);
    };

    auto getLocalPlayer() -> LocalPlayer* {
        DynamicMethod* getLP = (DynamicMethod*)this->get("getLocalPlayer");
        void*(* theFn)()  = (void*(*)())getLP->asVoid();
        return (LocalPlayer*)theFn();
    }
};

#endif /* IGNITE_CLIENTINSTANCE_H */

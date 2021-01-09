#ifndef IGNITE_ACTOR_H
#define IGNITE_ACTOR_H

#include "DynamicStruct.h"

struct Actor : DynamicStruct {
    Actor(uintptr_t address) : DynamicStruct("Actor", address) {

    };
    Actor(std::string structName, uintptr_t address) : DynamicStruct(structName, address) {
        
    };
};

#endif /* IGNITE_ACTOR_H */

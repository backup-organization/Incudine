#ifndef INCUDINE_ACTOR_H
#define INCUDINE_ACTOR_H

#include "DynamicStruct.h"

struct Actor : DynamicStruct {
    Actor() : DynamicStruct("Actor", 0) {

    };
    Actor(std::string structName) : DynamicStruct(structName, 0) {
        
    };
};

#endif /* INCUDINE_ACTOR_H */

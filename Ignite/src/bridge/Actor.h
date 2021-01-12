#ifndef IGNITE_ACTOR_H
#define IGNITE_ACTOR_H

#include "DynamicStruct.h"

struct Actor : DynamicStruct {
    Actor() : DynamicStruct("Actor", 0) {

    };
    Actor(std::string structName) : DynamicStruct(structName, 0) {
        
    };
};

#endif /* IGNITE_ACTOR_H */

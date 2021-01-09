#ifndef IGNITE_ACTOR_H
#define IGNITE_ACTOR_H

#include "DynamicStruct.h"

struct Actor : DynamicStruct {
    Actor() : DynamicStruct("Actor") {

    };
    Actor(std::string structName) : DynamicStruct(structName) {
        
    };
};

#endif /* IGNITE_ACTOR_H */

#ifndef IGNITE_MOB_H
#define IGNITE_MOB_H

#include "Actor.h"

struct Mob : Actor {
    Mob(uintptr_t address) : Actor("Mob", address) {

    };
    Mob(std::string structName, uintptr_t address) : Actor(structName, address) {

    };
};

#endif /* IGNITE_MOB_H */

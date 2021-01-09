#ifndef IGNITE_MOB_H
#define IGNITE_MOB_H

#include "Actor.h"

struct Mob : Actor {
    Mob() : Actor("Mob") {

    };
    Mob(std::string structName) : Actor(structName) {

    };
};

#endif /* IGNITE_MOB_H */

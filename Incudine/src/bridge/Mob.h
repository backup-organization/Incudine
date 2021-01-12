#ifndef INCUDINE_MOB_H
#define INCUDINE_MOB_H

#include "Actor.h"

struct Mob : Actor {
    Mob() : Actor("Mob") {

    };
    Mob(std::string structName) : Actor(structName) {

    };
};

#endif /* INCUDINE_MOB_H */

#ifndef IGNITE_PLAYER_H
#define IGNITE_PLAYER_H

#include "Mob.h"

struct Player : Mob {
    Player(uintptr_t address) : Mob("Player", address) {

    };
    Player(std::string structName, uintptr_t address) : Mob(structName, address) {

    };
};

#endif /* IGNITE_PLAYER_H */

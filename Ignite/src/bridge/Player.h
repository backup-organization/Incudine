#ifndef IGNITE_PLAYER_H
#define IGNITE_PLAYER_H

#include "Mob.h"

struct Player : Mob {
    Player() : Mob("Player") {

    };
    Player(std::string structName) : Mob(structName) {

    };
};

#endif /* IGNITE_PLAYER_H */

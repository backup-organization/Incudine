#ifndef INCUDINE_PLAYER_H
#define INCUDINE_PLAYER_H

#include "Mob.h"

struct Player : Mob {
    Player() : Mob("Player") {

    };
    Player(std::string structName) : Mob(structName) {

    };
};

#endif /* INCUDINE_PLAYER_H */

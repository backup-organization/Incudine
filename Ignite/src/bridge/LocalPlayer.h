#ifndef IGNITE_LOCALPLAYER_H
#define IGNITE_LOCALPLAYER_H

#include "Player.h"

struct LocalPlayer : Player {
    LocalPlayer(uintptr_t address) : Player("LocalPlayer", address) {

    };
    LocalPlayer(std::string structName, uintptr_t address) : Player(structName, address) {

    };
};

#endif /* IGNITE_LOCALPLAYER_H */

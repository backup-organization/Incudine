#ifndef IGNITE_LOCALPLAYER_H
#define IGNITE_LOCALPLAYER_H

#include "Player.h"

struct LocalPlayer : Player {
    LocalPlayer() : Player("LocalPlayer") {

    };
    LocalPlayer(std::string structName) : Player(structName) {

    };
};

#endif /* IGNITE_LOCALPLAYER_H */

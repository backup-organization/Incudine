#ifndef INCUDINE_LOCALPLAYER_H
#define INCUDINE_LOCALPLAYER_H

#include "Player.h"

struct LocalPlayer : Player {
    LocalPlayer() : Player("LocalPlayer") {

    };
    LocalPlayer(std::string structName) : Player(structName) {

    };
};

#endif /* INCUDINE_LOCALPLAYER_H */

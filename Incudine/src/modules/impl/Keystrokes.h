#ifndef INCUDINE_KEYSTROKES_H
#define INCUDINE_KEYSTROKES_H

#include "../Module.h"
#include "../../util/IMem.h"
#include "../../util/InputUtils.h"
#include "../../bridge/ClientInstance.h"
#include "../../bridge/GuiData.h"

class Keystrokes : public Module {
public:
    Keystrokes();
private:
    static inline Color textColor_BG = Color(1,1,1,1);
    static inline Color backGround_BG = Color(0,0,0,0);
    static inline Color textColor_FG = Color(0,0,0,1);
    static inline Color backGround_FG = Color(1,1,1,0);
    auto onDraw() -> void override;
    auto drawKey(char key, Vector2 loc, float scale) -> void;
    auto drawButton(char button, Vector2 loc, float scale) -> void;
    static inline float transitions[0xFF];
    static inline int transitionId = 0;
    static inline ClientInstance* ci = IMem::getClientInstance();
};

#endif /* INCUDINE_KEYSTROKES_H */

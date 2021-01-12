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
    static void onDraw();
    static void drawKey(char key, Vector2 loc, float scale);
    static inline float transitions[0xFF];
    static inline int transitionId = 0;
    static inline ClientInstance* ci = IMem::getClientInstance();
};

#endif /* INCUDINE_KEYSTROKES_H */

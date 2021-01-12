#ifndef INCUDINE_INPUTUTILS_H
#define INCUDINE_INPUTUTILS_H

#include "../util/IMath.h"
#include "../util/IMem.h"
#include "../bridge/GuiData.h"
#include "../bridge/ClientInstance.h"

class InputUtils {
    static inline bool downKeys[0xFF];
    static inline bool downButtons[0xFF];
public:
    static auto getMouseLoc() -> Vector2;
    static auto isKeyDown(char key) -> bool;
    static auto setKeyState(char key, bool down) -> void;
    static auto isButtonDown(char mbutton) -> bool;
    static auto setButtonState(char mbutton, bool down) -> void;
    static auto clearButtons() -> void;
};

#endif /* INCUDINE_INPUTUTILS_H */

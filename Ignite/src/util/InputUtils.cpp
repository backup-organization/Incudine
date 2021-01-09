#include "InputUtils.h"

auto InputUtils::getMouseLoc() -> Vector2 {
    return IMem::getClientInstance()->getGuiData()->getMouseLoc();
}

auto InputUtils::isKeyDown(char key) -> bool {
    return downKeys[key];
}
auto InputUtils::setKeyState(char key, bool down) -> void {
    downKeys[key] = down;
}

auto InputUtils::isButtonDown(char mbutton) -> bool {
    return downButtons[mbutton];
}
auto InputUtils::setButtonState(char mbutton, bool down) -> void {
    downButtons[mbutton] = down;
}
auto InputUtils::clearButtons() -> void {
    for(int i = 0; i<0xFF; i++) {
        downButtons[i] = false;
    }
}
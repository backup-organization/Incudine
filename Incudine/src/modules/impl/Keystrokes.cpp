#include "Keystrokes.h"

auto Keystrokes::drawKey(char key, Vector2 loc, float scale) -> void {
    transitionId++;
    float alphaValue = transitions[transitionId];
    std::string keyStr = std::string(1, key);
    float width = RenderUtils::getTextWidth(keyStr, scale);
    Vector4 textBgRect = Vector4(loc.x-(5*scale), loc.y-(5*scale), loc.x+width+(4*scale), loc.y+width+(6*scale));
    RenderUtils::fillBox(textBgRect, backGround_BG);
    Color textColor = textColor_BG;
    if(InputUtils::isKeyDown(key)) {
        if(alphaValue < 1.0f) {
            transitions[transitionId]+=0.01f;
        }
        textColor = textColor_FG;
    }
    else {
        if(alphaValue > 0.0f) {
            transitions[transitionId]-=0.01f;
        }
    }
    RenderUtils::fillBox(textBgRect, backGround_FG, alphaValue);
    RenderUtils::drawText(keyStr, loc, textColor, scale);
}
auto Keystrokes::drawButton(char button, Vector2 loc, float scale) -> void {
    std::string buttonName;
    switch(button) {
    case 1:
        buttonName = "LMB";
        break;
    case 2:
        buttonName = "RMB";
        break;
    default:
        buttonName = "";
        break;
    }
    ClientInstance* ci = IMem::getClientInstance();
    
    transitionId++;
    float alphaValue = transitions[transitionId];

    std::string btnStr = buttonName+": "; //+cps;
    float width = RenderUtils::getTextWidth(btnStr, scale);
    Vector4 textBgRect = Vector4(loc.x-(5*scale), loc.y-(5*scale), loc.x+width+(18*scale), loc.y+(14*scale));
    Color textColor = textColor_BG;
    RenderUtils::fillBox(textBgRect, backGround_BG);
    RenderUtils::drawText(btnStr, loc, textColor, scale);

    if(InputUtils::isButtonDown(button)) {
        if(alphaValue < 1.0f) {
            transitions[transitionId]+=0.01f;
        }
        textColor = textColor_FG;
    }
    else {
        if(alphaValue > 0.0f) {
            transitions[transitionId]-=0.01f;
        }
    }

    RenderUtils::fillBox(textBgRect, backGround_FG, alphaValue);
    RenderUtils::drawText(btnStr, loc, textColor, scale);
}

auto Keystrokes::onDraw() -> void {
    if(this->isEnabled()) {
        transitionId = 0;
        ClientInstance* ci = IMem::getClientInstance();

        Vector2 resolution = ci->getGuiData()->getScaledResolution();
        Vector2 wloc = Vector2(100, resolution.y-100);
        Vector2 aloc = Vector2(65, resolution.y-60);
        Vector2 sloc = Vector2(100, resolution.y-60);
        Vector2 dloc = Vector2(135, resolution.y-60);
        drawKey('W', wloc, 2.0f);
        drawKey('A', aloc, 2.0f);
        drawKey('S', sloc, 2.0f);
        drawKey('D', dloc, 2.0f);
        Vector2 lmbloc = Vector2(60, resolution.y-25);
        Vector2 rmbloc = Vector2(113, resolution.y-25);
        drawButton((char)1, lmbloc, 1.0f);
        drawButton((char)2, rmbloc, 1.0f);
    }
}

Keystrokes::Keystrokes() : Module("Keystrokes") {
}
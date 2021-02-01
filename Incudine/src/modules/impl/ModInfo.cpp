#include "ModInfo.h"

void ModInfo::onDraw() {
    //RenderUtils::drawText("Keystrokes", Vector2(10, 10), Color());
    ClientInstance* ci = IMem::getClientInstance();
    float width = RenderUtils::getTextWidth("Incudine", 1.0f);
    GuiData* gd = ci->getGuiData();
    Vector2 scaledRes = gd->getScaledResolution();
    Vector2 loc = scaledRes - Vector2(width, 10);
    RenderUtils::drawText("Incudine", loc, Color(1,1,0,1));
}

ModInfo::ModInfo() : Module("ModInfo") {
}
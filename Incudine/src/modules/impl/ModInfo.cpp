#include "ModInfo.h"

void ModInfo::onDraw() {
    //RenderUtils::drawText("Keystrokes", Vector2(10, 10), Color());
    float width = RenderUtils::getTextWidth("Incudine", 1.0f);
    Log::getLogger()->write("Got width: ")->write(width, false)->writeLine();
    Vector2 loc = ci->getGuiData()->getScaledResolution() - Vector2(width, 10);
    Log::getLogger()->writeLine("Calculated text location");
    RenderUtils::drawText("Incudine", loc, Color(1,1,0,1));
    Log::getLogger()->writeLine("Drawn text");
}

ModInfo::ModInfo() : Module("ModInfo") {
    this->onRender(onDraw);
}
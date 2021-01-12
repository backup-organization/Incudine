#include "ModInfo.h"

void ModInfo::onDraw() {
    //RenderUtils::drawText("Keystrokes", Vector2(10, 10), Color());
    ClientInstance* ci = IMem::getClientInstance();
    float width = RenderUtils::getTextWidth("Incudine", 1.0f);
    Log::getLogger()->write("Got width: ")->write(width)->writeLine();
    GuiData* gd = ci->getGuiData();
    Log::getLogger()->write("Got gui data in draw");
    Vector2 scaledRes = gd->getScaledResolution();
    Log::getLogger()->write("Got scaled res X: ")->write(scaledRes.x)->write(" Y: ")->write(scaledRes.y)->writeLine();
    Vector2 loc = scaledRes - Vector2(width, 10);
    Log::getLogger()->writeLine("Calculated text location");
    RenderUtils::drawText("Incudine", loc, Color(1,1,0,1));
    Log::getLogger()->writeLine("Drawn text");
}

ModInfo::ModInfo() : Module("ModInfo") {
    this->onRender(onDraw);
}
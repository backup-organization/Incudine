#include "ModInfo.h"
#include "../../util/IMem.h"
#include "../../bridge/GuiData.h"

void ModInfo_onDraw() {
    //RenderUtils::drawText("Keystrokes", Vector2(10, 10), Color());
    ClientInstance* ci = IMem::getClientInstance();
    float width = RenderUtils::getTextWidth("Ignite", 1.0f);
    Vector2 loc = ci->getGuiData()->getScaledResolution() - Vector2(width, 10);
    RenderUtils::drawText("Ignite", loc, Color(1,1,0,1));
}

ModInfo::ModInfo() : Module("ModInfo") {
    this->onRender(ModInfo_onDraw);
}
#include "ModGui.h"

auto ModGui::onDraw() -> void {
    if(this->isEnabled()) {
        
    }
}
ModGui::ModGui() : Module("ModGui") {
    this->setEnabled(true);
}
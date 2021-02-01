#ifndef INCUDINE_MODGUI_H
#define INCUDINE_MODGUI_H

#include "../Module.h"

class ModGui : public Module {
public:
    ModGui::ModGui();
private:
    auto onDraw() -> void override;
};

#endif /* INCUDINE_MODGUI_H */

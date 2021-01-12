#ifndef INCUDINE_MODINFO_H
#define INCUDINE_MODINFO_H

#include "../Module.h"
#include "../../util/IMem.h"
#include "../../bridge/GuiData.h"

class ModInfo : public Module {
public:
    ModInfo();
private:
    static void onDraw();
    static inline ClientInstance* ci = IMem::getClientInstance();
};

#endif /* INCUDINE_MODINFO_H */

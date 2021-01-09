#ifndef IGNITE_MODINFO_H
#define IGNITE_MODINFO_H

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

#endif /* IGNITE_MODINFO_H */

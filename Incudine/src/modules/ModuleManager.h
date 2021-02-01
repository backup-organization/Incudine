#ifndef INCUDINE_MODULEMANAGER_H
#define INCUDINE_MODULEMANAGER_H

#include "Manager.h"
#include "Module.h"
#include "../util/RenderUtils.h"

#include "impl/Keystrokes.h"
#include "impl/ModInfo.h"
#include "impl/ModGui.h"

class ModuleManager : public Manager<Module>{
    static inline ModuleManager* moduleManager;
    static auto onDraw() -> void {
        for(auto module : *moduleManager->getItems()) {
            module->onDraw();
        }
    }
    ModuleManager() : Manager<Module>("Modules") {
        this->addItem(new Keystrokes());
        this->addItem(new ModInfo());
        this->addItem(new ModGui());

        RenderUtils::onRender(onDraw);
    }
public:
    static auto getModuleManager() -> ModuleManager* {
        if(!moduleManager) {
            moduleManager = new ModuleManager();
        }
        return moduleManager;
    }
};

#endif /* INCUDINE_MODULEMANAGER_H */

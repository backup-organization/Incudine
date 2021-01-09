#ifndef IGNITE_MODULEMANAGER_H
#define IGNITE_MODULEMANAGER_H

#include "Manager.h"
#include "Module.h"

#include "impl/Keystrokes.h"
#include "impl/ModInfo.h"

class ModuleManager : public Manager<Module>{
    static inline ModuleManager* moduleManeger;
    ModuleManager() : Manager<Module>("Modules") {
        this->addItem(new Keystrokes());
        this->addItem(new ModInfo());
    }
public:
    static ModuleManager* getModuleManager() {
        if(!moduleManeger) {
            moduleManeger = new ModuleManager();
        }
        return moduleManeger;
    }
};

#endif /* IGNITE_MODULEMANAGER_H */

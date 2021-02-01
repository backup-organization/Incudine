#ifndef INCUDINE_MODULE_H
#define INCUDINE_MODULE_H

#include "Item.h"
#include "Renderable.h"

class Module : public Item, public Renderable {
    bool enabled = false;
public:
    Module(std::string name) : Item(name), Renderable() {
        
    }

    virtual auto isEnabled() -> bool {
        return this->enabled;
    }
    virtual auto setEnabled(bool enabled) -> void {
        this->enabled = enabled;
    }

};

#endif /* INCUDINE_MODULE_H */

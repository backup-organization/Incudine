#ifndef IGNITE_MODULE_H
#define IGNITE_MODULE_H

#include "Item.h"
#include "Renderable.h"

class Module : public Item, public Renderable {
public:
    Module(std::string name) : Item(name), Renderable() {
        
    }
};

#endif /* IGNITE_MODULE_H */

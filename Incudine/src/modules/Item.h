#ifndef INCUDINE_ITEM_H
#define INCUDINE_ITEM_H

#include <string>

class Item {
    std::string name;
public:
    Item(std::string name) {
        this->name = name;
    };
    auto getName() -> std::string {
        return this->name;
    };
};

#endif /* INCUDINE_ITEM_H */

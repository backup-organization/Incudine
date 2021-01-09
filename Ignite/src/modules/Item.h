#ifndef IGNITE_ITEM_H
#define IGNITE_ITEM_H

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

#endif /* IGNITE_ITEM_H */

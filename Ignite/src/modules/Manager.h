#ifndef IGNITE_MANAGER_H
#define IGNITE_MANAGER_H

#include <vector>
#include <string>
#include "Item.h"

template <typename T>
class Manager : public Item
{
private:
    std::vector<T*>* dataVec;
public:
    Manager<T>(std::string name) : Item(name) {
        dataVec = new std::vector<T*>();
    }
    auto getItems() -> std::vector<T*>* {
        return this->dataVec;
    }
    void addItem(T* toAdd) {
        this->dataVec->push_back(toAdd);
    }
};

#endif /* IGNITE_MANAGER_H */

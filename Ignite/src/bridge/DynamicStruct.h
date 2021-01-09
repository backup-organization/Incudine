#ifndef IGNITE_DYNAMICSTRUCT_H
#define IGNITE_DYNAMICSTRUCT_H

#include <vector>
#include <string>

struct DynamicField {
    std::string fieldName;
    int offset;
};

struct DynamicStruct {
    std::vector<DynamicStruct*>* fields;
    std::vector<void*>* virtualFunctions;
    std::vector<void*>* functions;
    DynamicStruct(void* address) {
        fields = new std::vector<DynamicStruct*>();
        virtualFunctions = new std::vector<void*>();
        functions = new std::vector<void*>();
    };

    void addField(std::string fieldName, int offset) {

    }
};

#endif /* IGNITE_DYNAMICSTRUCT_H */

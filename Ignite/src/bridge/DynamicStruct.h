#ifndef IGNITE_DYNAMICSTRUCT_H
#define IGNITE_DYNAMICSTRUCT_H

#include <vector>
#include <string>
#include "../util/Log.h"

struct DynamicStruct;
struct DynamicField;


struct DynamicObject {
    std::string name;
    uintptr_t address;

    DynamicObject(std::string name) {
        this->name = name;
    };
    auto getName() -> std::string {
        return this->name;
    };
    auto asVoid() -> void* {
        return (void*)this->address;
    }
    auto setAddress(uintptr_t address) -> void {
        this->address = address;
    }
    auto getAddress() -> uintptr_t {
        return this->address;
    }
};

struct DynamicField : DynamicObject {
    DynamicField(std::string fieldName) : DynamicObject(fieldName) {
    };
    auto asStruct() -> DynamicStruct* {
        return (DynamicStruct*)this;
    };
};

struct DynamicMethod : DynamicObject {
    DynamicMethod(std::string methodName) : DynamicObject(methodName) {
    }
};

struct DynamicStruct : DynamicObject {
    std::vector<DynamicField*>* fields;
    std::vector<DynamicMethod*>* virtualFunctions;
    std::vector<DynamicMethod*>* functions;
    DynamicStruct(std::string structName) : DynamicObject(structName) {
        fields = new std::vector<DynamicField*>();
        virtualFunctions = new std::vector<DynamicMethod*>();
        functions = new std::vector<DynamicMethod*>();
    };

    auto addField(DynamicField* theField, uintptr_t offset) -> void {
        theField->setAddress(this->getAddress()+offset);
        this->fields->push_back(theField);
    };
    auto addVirtual(DynamicMethod* theMethod, uintptr_t offset) -> void {
        uintptr_t newAddr = (*((uintptr_t*)this->getAddress()))+(8*offset);
        theMethod->setAddress(newAddr);
        this->virtualFunctions->push_back(theMethod);
    };
    auto addFunction(DynamicMethod* theMethod, uintptr_t address) -> void {
        theMethod->setAddress(address);
        this->functions->push_back(theMethod);
    };

    auto get(std::string name) -> DynamicObject* {
        for(auto field : *fields) {
            if(field->getName()==name) {
                return field;
            }
        }
        for(auto function : *virtualFunctions) {
            if(function->getName()==name) {
                return function;
            }
        }
        for(auto function : *functions) {
            if(function->getName()==name) {
                return function;
            }
        }
        Log::getLogger()->write("Failed to find dynamic object \"")->write(name)->writeLine("\"");
        return nullptr;
    };
};

#endif /* IGNITE_DYNAMICSTRUCT_H */

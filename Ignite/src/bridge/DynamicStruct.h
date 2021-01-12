#ifndef IGNITE_DYNAMICSTRUCT_H
#define IGNITE_DYNAMICSTRUCT_H

#include <vector>
#include <string>
#include "../util/Log.h"

struct DynamicStruct;


struct DynamicObject {
    std::string name;
    uintptr_t address;
    uintptr_t offset;

    DynamicObject(std::string name, uintptr_t offset) {
        this->name = name;
        this->offset = offset;
    };
    auto getName() -> std::string {
        return this->name;
    };
    auto asVoid() -> void* {
        return (void*)this->getAddress();
    }
    auto setAddress(uintptr_t address) -> void {
        this->address = address;
    }
    auto getAddress() -> uintptr_t {
        return this->address;
    }
    auto setOffset(uintptr_t offset) -> void {
        this->offset = offset;
    }
    auto getOffset() -> uintptr_t {
        return this->offset;
    }
};

struct DynamicField : DynamicObject {
    DynamicField(std::string fieldName, uintptr_t offset) : DynamicObject(fieldName, offset) {
    };
    auto asStruct() -> DynamicStruct* {
        return (DynamicStruct*)this;
    };
};

struct DynamicMethod : DynamicObject {
    DynamicMethod(std::string methodName, uintptr_t offset) : DynamicObject(methodName, offset) {
    }
};

struct DynamicStruct : DynamicObject {
    std::vector<DynamicField*>* fields;
    std::vector<DynamicMethod*>* virtualFunctions;
    std::vector<DynamicMethod*>* functions;
    DynamicStruct(std::string structName, uintptr_t offset) : DynamicObject(structName, offset) {
        fields = new std::vector<DynamicField*>();
        virtualFunctions = new std::vector<DynamicMethod*>();
        functions = new std::vector<DynamicMethod*>();
    };

    auto addField(DynamicField* theField) -> void {
        theField->setAddress(this->getAddress()+offset);
        this->fields->push_back(theField);
    };
    auto addVirtual(DynamicMethod* theMethod) -> void {
        uintptr_t newAddr = (*((uintptr_t*)this->getAddress()))+(8*offset);
        theMethod->setAddress(newAddr);
        this->virtualFunctions->push_back(theMethod);
    };
    auto addFunction(DynamicMethod* theMethod) -> void {
        theMethod->setAddress(address);
        this->functions->push_back(theMethod);
    };

    auto get(std::string name) -> DynamicObject* {
        for(auto field : *fields) {
            if(field->getName()==name) {
                field->setAddress(this->getAddress()+field->getOffset());
                return field;
            }
        }
        for(auto function : *virtualFunctions) {
            if(function->getName()==name) {
                uintptr_t newAddr = (*((uintptr_t*)this->getAddress()))+(8*function->getOffset());
                function->setAddress(newAddr);
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

#ifndef IGNITE_DYNAMICSTRUCT_H
#define IGNITE_DYNAMICSTRUCT_H

#include <vector>
#include <string>

struct DynamicStruct;
struct DynamicField;


struct DynamicObject {
    std::string name;
    uintptr_t address;

    DynamicObject(std::string name, uintptr_t address) {
        this->name = name;
    };
    std::string getName() {
        return this->name;
    };
};

struct DynamicField : DynamicObject {
    DynamicField(std::string fieldName, uintptr_t address) : DynamicObject(fieldName, address) {
    };
    auto asStruct() -> DynamicStruct* {
        return (DynamicStruct*)this;
    };
};

struct DynamicMethod : DynamicObject {
    DynamicMethod(std::string methodName, uintptr_t address) : DynamicObject(methodName, address) {
    }
    auto asVoid() -> void* {
        return (void*)this->address;
    }
};

struct DynamicStruct : DynamicObject {
    std::vector<DynamicField*>* fields;
    std::vector<DynamicMethod*>* virtualFunctions;
    std::vector<DynamicMethod*>* functions;
    DynamicStruct(std::string structName, uintptr_t address) : DynamicObject(structName, address) {
        fields = new std::vector<DynamicField*>();
        virtualFunctions = new std::vector<DynamicMethod*>();
        functions = new std::vector<DynamicMethod*>();
    };

    auto addField(std::string fieldName, uintptr_t offset) -> void {
        this->fields->push_back(new DynamicField(fieldName, this->address+offset));
    };
    auto addVirtual(std::string methodName, uintptr_t offset) -> void {
        this->virtualFunctions->push_back(new DynamicMethod(methodName, (*((uintptr_t*)this->address))+(8*offset)));
    };
    auto addFunction(std::string methodName, uintptr_t address) -> void {
        this->functions->push_back(new DynamicMethod(methodName, address));
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
        return nullptr;
    };
};

#endif /* IGNITE_DYNAMICSTRUCT_H */

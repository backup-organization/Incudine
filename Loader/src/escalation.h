#ifndef IGNITE_ESCALATION_H
#define IGNITE_ESCALATION_H

#include <iostream>
#include <windows.h>
#include <Aclapi.h>
#include <sddl.h>

class escalation {
public:
    static auto escalation::elevate(const std::string& file) -> bool;
};


#endif //IGNITE_ESCALATION_H

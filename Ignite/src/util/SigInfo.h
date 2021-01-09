#ifndef IGNITE_SIGINGO_H
#define IGNITE_SIGINGO_H

#include <string>
struct SigInfo {
    std::string* signature;
    int offset;

    SigInfo(std::string* signature, int offset) {
        this->signature = signature;
        this->offset = offset;
    };
    ~SigInfo() {
        delete signature;
    }
};

#endif /* IGNITE_SIGINGO_H */

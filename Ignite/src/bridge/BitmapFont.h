#ifndef IGNITE_BITMAPFONT_H
#define IGNITE_BITMAPFONT_H

#include "DynamicStruct.h"

struct BitmapFont : DynamicStruct {
    BitmapFont(uintptr_t address) : DynamicStruct(address) {

    };
};

#endif /* IGNITE_BITMAPFONT_H */

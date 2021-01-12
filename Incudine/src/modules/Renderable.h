#ifndef INCUDINE_RENDERABLE_H
#define INCUDINE_RENDERABLE_H

#include "../util/RenderUtils.h"

class Renderable
{
public:
    void onRender(void(onDraw)()) {
        RenderUtils::onRender(onDraw);
    }
};

#endif /* INCUDINE_RENDERABLE_H */

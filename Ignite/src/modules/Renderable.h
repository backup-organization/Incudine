#ifndef IGNITE_RENDERABLE_H
#define IGNITE_RENDERABLE_H

#include "../util/RenderUtils.h"

class Renderable
{
public:
    void onRender(void(onDraw)()) {
        RenderUtils::onRender(onDraw);
    }
};

#endif /* IGNITE_RENDERABLE_H */

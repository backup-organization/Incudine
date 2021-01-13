#ifndef INCUDINE_RENDERUTILS_H
#define INCUDINE_RENDERUTILS_H

#include <string>
#include <vector>
#include "IMath.h"
#include "../bridge/Color.h"
#include "../bridge/RectangleArea.h"
#include "../bridge/TextMeasureData.h"
#include "../bridge/CaretMeasureData.h"
#include "../bridge/MinecraftUIRenderContext.h"
#include "../bridge/BitmapFont.h"
#include "../bridge/ClientInstance.h"

class RenderUtils {
    static inline BitmapFont* cachedFont = nullptr;
    static inline MinecraftUIRenderContext* context;
    static inline std::vector<void(*)()> drawFuncs;
public:
    static auto setContext(uintptr_t context) -> void;
    static auto getContext() -> MinecraftUIRenderContext*;
    static auto setCachedFont(BitmapFont* context) -> void;
    static auto getCachedFont() -> BitmapFont*;

    static auto onRender(void(listenFunc)()) -> void;
    static auto invokeDraws() -> void;

    static auto drawText(std::string text, Vector2& position, Color& color) -> void;
    static auto drawText(std::string text, Vector2& position, Color& color, float scale) -> void;
    static auto getTextWidth(std::string text, float scale) -> float;
    static auto fillBox(Vector4& box, Color& color) -> void;
    static auto fillBox(Vector4& box, Color& color, float alpha) -> void;
};

#endif /* INCUDINE_RENDERUTILS_H */

#include "RenderUtils.h"

auto RenderUtils::setContext(uintptr_t context) -> void {
    if(!RenderUtils::context)
        RenderUtils::context = new MinecraftUIRenderContext();
    RenderUtils::context->setAddress(context);
    
}
auto RenderUtils::getContext() -> MinecraftUIRenderContext* {
    return context;
}
auto RenderUtils::setCachedFont(BitmapFont* cachedFont) -> void {
    if(!RenderUtils::cachedFont)
        RenderUtils::cachedFont = cachedFont;
}
auto RenderUtils::getCachedFont() -> BitmapFont* {
    return cachedFont;
}

auto RenderUtils::onRender(void(listenFunc)()) -> void {
    drawFuncs.push_back(listenFunc);
}
auto RenderUtils::invokeDraws() -> void {
    for(auto draw : drawFuncs) {
        draw();
    }
}

auto RenderUtils::drawText(std::string text, Vector2& position, Color& color) -> void {
    RenderUtils::drawText(text, position, color, 1.0f);
}
auto RenderUtils::drawText(std::string text, Vector2& position, Color& color, float scale) -> void {
    if(cachedFont) {
        RenderUtils::getContext()->drawText(cachedFont, &RectangleArea(position), &text, &color, 1.0f, &TextMeasureData(scale), &CaretMeasureData());
        RenderUtils::getContext()->flushText();
    }
}
auto RenderUtils::getTextWidth(std::string text, float scale) -> float {
    if(cachedFont) {
        return RenderUtils::getContext()->getLineLength(cachedFont, &text, scale);
    }
    return 0.0f;
}
auto RenderUtils::fillBox(Vector4& box, Color& color) -> void {
    RenderUtils::getContext()->fillRectangle(&Vector4(box.x, box.z, box.y, box.w), &color, 1.0f);
}
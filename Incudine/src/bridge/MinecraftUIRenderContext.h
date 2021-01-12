#ifndef INCUDINE_MINECRAFTUIRENDERCONTEXT_H
#define INCUDINE_MINECRAFTUIRENDERCONTEXT_H

#include "DynamicStruct.h"
#include "BitmapFont.h"
#include "RectangleArea.h"
#include "Color.h"
#include "TextMeasureData.h"
#include "CaretMeasureData.h"

struct MinecraftUIRenderContext : DynamicStruct {
    MinecraftUIRenderContext() : DynamicStruct("MinecraftUIRenderContext", 0) {
        this->addVirtual(new DynamicMethod("getLineLength", 1));
        this->addVirtual(new DynamicMethod("drawText", 5));
        this->addVirtual(new DynamicMethod("flushText", 6));
        this->addVirtual(new DynamicMethod("drawRectangle", 12));
        this->addVirtual(new DynamicMethod("fillRectangle", 13));
    };

    auto getLineLength(BitmapFont* font, std::string& text, float size) -> float {
        DynamicMethod* theFunc = (DynamicMethod*)this->get("getLineLength");
        float(__fastcall** theFn)(uintptr_t, BitmapFont*, std::string*, float, bool) = (float(__fastcall**)(uintptr_t, BitmapFont*, std::string*, float, bool))theFunc->asVoid();
        return (*theFn)(this->getAddress(), font, &text, size, false);
    }
    auto drawText(BitmapFont* font, RectangleArea& rect, std::string& text, Color& color, float alpha, TextMeasureData& measureData, CaretMeasureData& caretData) -> void {
        Log::getLogger()->writeLine("Starting text draw");
        DynamicMethod* theFunc = (DynamicMethod*)this->get("drawText");
        void(__fastcall** theFn)(uintptr_t, BitmapFont*, RectangleArea*, std::string*, Color*, float, class TextAlignment*, TextMeasureData*, CaretMeasureData*)  = (void(__fastcall**)(uintptr_t, BitmapFont*, RectangleArea*, std::string*, Color*, float, class TextAlignment*, TextMeasureData*, CaretMeasureData*))theFunc->asVoid();
        (*theFn)(this->getAddress(), font, &rect, &text, &color, alpha, nullptr, &measureData, &caretData);
        Log::getLogger()->writeLine("Finished text draw");
    }
    auto flushText() -> void {
        Log::getLogger()->writeLine("Starting text flush");
        DynamicMethod* theFunc = (DynamicMethod*)this->get("flushText");
        void(__fastcall** theFn)(uintptr_t, float)  = (void(__fastcall**)(uintptr_t, float))theFunc->asVoid();
        (*theFn)(this->getAddress(), 0);
        Log::getLogger()->writeLine("flushed text");
    }
    auto drawRectangle(Vector4& positions, Color& color, float alpha, int width) -> void {
        DynamicMethod* theFunc = (DynamicMethod*)this->get("drawRectangle");
        void(__fastcall** theFn)(uintptr_t, Vector4*, Color*, float, int)  = (void(__fastcall**)(uintptr_t, Vector4*, Color*, float, int))theFunc->asVoid();
        (*theFn)(this->getAddress(), &positions, &color, alpha, width);
    }
    auto fillRectangle(Vector4& positions, Color& color, float alpha) -> void {
        DynamicMethod* theFunc = (DynamicMethod*)this->get("fillRectangle");
        void(__fastcall** theFn)(uintptr_t, Vector4*, Color*, float)  = (void(__fastcall**)(uintptr_t, Vector4*, Color*, float))theFunc->asVoid();
        (*theFn)(this->getAddress(), &positions, &color, alpha);
    }
};

#endif /* INCUDINE_MINECRAFTUIRENDERCONTEXT_H */

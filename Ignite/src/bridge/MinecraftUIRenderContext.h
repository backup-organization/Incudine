#ifndef IGNITE_MINECRAFTUIRENDERCONTEXT_H
#define IGNITE_MINECRAFTUIRENDERCONTEXT_H

#include "DynamicStruct.h"
#include "BitmapFont.h"
#include "RectangleArea.h"
#include "Color.h"
#include "TextMeasureData.h"
#include "CaretMeasureData.h"

struct MinecraftUIRenderContext : DynamicStruct {
    MinecraftUIRenderContext() : DynamicStruct("MinecraftUIRenderContext") {
        this->addVirtual(new DynamicMethod("getLineLength"), 1);
        this->addVirtual(new DynamicMethod("drawText"), 5);
        this->addVirtual(new DynamicMethod("flushText"), 6);
        this->addVirtual(new DynamicMethod("drawRectangle"), 12);
        this->addVirtual(new DynamicMethod("fillRectangle"), 13);
    };

    auto getLineLength(BitmapFont* font, std::string* text, float size) -> float {
        DynamicMethod* theFunc = (DynamicMethod*)this->get("getLineLength");
        float(* theFn)(BitmapFont*, std::string*, float, bool)  = (float(*)(BitmapFont*, std::string*, float, bool))theFunc->asVoid();
        return theFn(font, text, size, false);
    }
    auto drawText(BitmapFont* font, RectangleArea* rect, std::string* text, Color* color, float alpha, TextMeasureData* measureData, CaretMeasureData* caretData) -> void {
        DynamicMethod* theFunc = (DynamicMethod*)this->get("drawText");
        void(* theFn)(BitmapFont*, RectangleArea*, std::string*, Color*, float, class TextAlignment*, TextMeasureData*, CaretMeasureData*)  = (void(*)(BitmapFont*, RectangleArea*, std::string*, Color*, float, class TextAlignment*, TextMeasureData*, CaretMeasureData*))theFunc->asVoid();
        theFn(font, rect, text, color, alpha, nullptr, measureData, caretData);
    }
    auto flushText() -> void {
        DynamicMethod* theFunc = (DynamicMethod*)this->get("drawText");
        void(* theFn)(float)  = (void(*)(float))theFunc->asVoid();
        theFn(0);
    }
    auto drawRectangle(Vector4* positions, Color* color, float alpha, int width) -> void {
        DynamicMethod* theFunc = (DynamicMethod*)this->get("drawRectangle");
        void(* theFn)(Vector4*, Color*, float, int)  = (void(*)(Vector4*, Color*, float, int))theFunc->asVoid();
        theFn(positions, color, alpha, width);
    }
    auto fillRectangle(Vector4* positions, Color* color, float alpha) -> void {
        DynamicMethod* theFunc = (DynamicMethod*)this->get("fillRectangle");
        void(* theFn)(Vector4*, Color*, float)  = (void(*)(Vector4*, Color*, float))theFunc->asVoid();
        theFn(positions, color, alpha);
    }
};

#endif /* IGNITE_MINECRAFTUIRENDERCONTEXT_H */

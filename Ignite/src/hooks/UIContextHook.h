#ifndef IGNITE_UICONTEXTHOOK_H
#define IGNITE_UICONTEXTHOOK_H

#include <iostream>
#include <windows.h>
#include <polyhook2/Detour/x64Detour.hpp>
#include <polyhook2/CapstoneDisassembler.hpp>
#include "../bridge/Color.h"
#include "../bridge/RectangleArea.h"
#include "../bridge/TextMeasureData.h"
#include "../bridge/CaretMeasureData.h"
#include "../bridge/MinecraftUIRenderContext.h"
#include "../bridge/BitmapFont.h"
#include "../util/IMem.h"
#include "../util/Log.h"
#include "../util/RenderUtils.h"
#include "../util/SigInfo.h"

class UIContextHook {
public:
    static auto hook() -> HRESULT;
private:
    static inline uint64_t renderOriginal = 0;
    static inline uint64_t textOriginal = 0;
    static auto renderCallback(uint64_t a1, uintptr_t renderContext) -> int;
    static auto textCallback(uintptr_t renderContext, class BitmapFont* font, class RectangleArea* rect, std::string* text, class Color* color, float alpha, class TextAlignment* alignment, class TextMeasureData* measureData, class CaretMeasureData* caretData) -> int;
};


#endif //IGNITE_UICONTEXTHOOK_H

#include "UIContextHook.h"


auto UIContextHook::renderCallback(uint64_t a1, MinecraftUIRenderContext* renderContext) -> int {
    RenderUtils::setContext(renderContext);

    RenderUtils::invokeDraws();

    return PLH::FnCast(renderOriginal, &renderCallback)(a1, renderContext);
}
auto UIContextHook::textCallback(MinecraftUIRenderContext* renderContext, class BitmapFont* font, class RectangleArea* rect, std::string* text, class Color* color, float alpha, class TextAlignment* alignment, class TextMeasureData* measureData, class CaretMeasureData* caretData) -> int {
    if(!RenderUtils::getCachedFont())
        RenderUtils::setCachedFont(font);
    return PLH::FnCast(textOriginal, &textCallback)(renderContext, font, rect, text, color, alpha, alignment, measureData, caretData);
}

auto UIContextHook::hook() -> HRESULT {

    //UI context
    uintptr_t uiContextAddr = 0;
    {
        std::vector<SigInfo*>* uicontext_signatures;
        uicontext_signatures = new std::vector<SigInfo*>();
        uicontext_signatures->push_back(new SigInfo(new std::string("48 8B ?? ?? 89 ?? ?? 55 56 57 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? 29 ?? ?? ?? 29 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 4C 8B ?? ?? 89 ?? ?? ?? 4C"), 0));
        uicontext_signatures->push_back(new SigInfo(new std::string("48 8B ?? 55 56 57 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? C7 ?? ?? ?? ?? ?? ?? ?? 89 ?? ?? ?? 29 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? ?? 89 ?? ?? ?? 4C 8B ?? ?? 89 ?? ?? ?? 33"), 0));
        int index = 0;
        while(uiContextAddr == 0) {
            if(index > uicontext_signatures->size()) {
                Log::getLogger()->writeLine("UIContextHook All signatures failed");
                return E_FAIL;
            }
            SigInfo* info = uicontext_signatures->at(index);
            std::string* sig = info->signature;
            int offset = info->offset;

            uiContextAddr = IMem::findSig(sig->c_str());
            if(uiContextAddr != 0) {
                uiContextAddr += offset;
            }
            index++;
        }
    }
    //Text draw
    uintptr_t uiContextTextAddr = 0;
    {
        std::vector<SigInfo*>* uitext_signatures;
        uitext_signatures = new std::vector<SigInfo*>();
        uitext_signatures->push_back(new SigInfo(new std::string("89 ?? ?? ?? 55 56 57 48 83 ?? ?? 4C ?? ?? ?? ?? ?? ?? ?? 48"), -1));
        uitext_signatures->push_back(new SigInfo(new std::string("89 ?? ?? ?? ?? 89 ?? ?? ?? 57 48 83 ?? ?? 48 ?? ?? ?? 4C 8B ?? 48 ?? ?? ?? ?? ?? ?? ?? 48"), -1));
        int index = 0;
        while(uiContextTextAddr == 0) {
            if(index > uitext_signatures->size()) {
                Log::getLogger()->writeLine("UIContextHook TextDraw All signatures failed");
                return E_FAIL;
            }
            SigInfo* info = uitext_signatures->at(index);
            std::string* sig = info->signature;
            int offset = info->offset;

            uiContextTextAddr = IMem::findSig(sig->c_str());
            if(uiContextTextAddr != 0) {
                uiContextTextAddr += offset;
            }
            index++;
        }
    }

    Log::getLogger()->write("UIContextFuncAddr: ")->write(uiContextAddr, true)->writeLine("");
    Log::getLogger()->write("UIDrawTextFuncAddr: ")->write(uiContextTextAddr, true)->writeLine("");

    PLH::CapstoneDisassembler dis(PLH::Mode::x64);
    PLH::x64Detour renderDetourHook((char*)uiContextAddr, (char*)&renderCallback, &renderOriginal, dis);
    if (!renderDetourHook.hook()) {
        Log::getLogger()->writeLine("The render ui hook failed");
        return E_FAIL;
    }
    PLH::x64Detour drawTextDetourHook((char*)uiContextTextAddr, (char*)&textCallback, &textOriginal, dis);
    if (!drawTextDetourHook.hook()) {
        Log::getLogger()->writeLine("The draw text hook failed");
        return E_FAIL;
    }

    Log::getLogger()->writeLine("Hook success!");
    return S_OK;
}

#ifndef INCUDINE_GUIDATA_H
#define INCUDINE_GUIDATA_H

#include "DynamicStruct.h"
#include "../util/IMath.h"

struct GuiData : DynamicStruct {
    GuiData() : DynamicStruct("GuiData", 0) {
        this->addField(new DynamicField("resolution", 0x18));
        this->addField(new DynamicField("scaledResolution", 0x28));
        this->addField(new DynamicField("guiSize", 0x30));
        this->addField(new DynamicField("guiScale", 0x38));
        this->addField(new DynamicField("mouseX", 0x52));
        this->addField(new DynamicField("mouseY", 0x54));
        this->addField(new DynamicField("isWorldLoaded", 0x56));
        this->addField(new DynamicField("heldItemSlot", 0x58));
        this->addField(new DynamicField("heldItemName", 0x94));
    };

    auto getResolution() -> Vector2 {
        DynamicField* theField = (DynamicField*)this->get("resolution");
        Vector2* theVec = (Vector2*)theField->asVoid();
        return *theVec;
    };
    auto getScaledResolution() -> Vector2 {
        DynamicField* theField = (DynamicField*)this->get("scaledResolution");
        Vector2 theVec = *((Vector2*)theField->asVoid());
        return theVec;
    };
	auto getGuiSize() -> double {
        DynamicField* theField = (DynamicField*)this->get("guiSize");
        double* theVal = (double*)theField->asVoid();
        return *theVal;
    };
    auto getGuiScale() -> float {
        DynamicField* theField = (DynamicField*)this->get("guiScale");
        float* theVal = (float*)theField->asVoid();
        return *theVal;
    };
	auto getMouseX() -> short {
		DynamicField* theField = (DynamicField*)this->get("mouseX");
        short* theVal = (short*)theField->asVoid();
        return *theVal;
	}
	auto getMouseY() -> short {
		DynamicField* theField = (DynamicField*)this->get("mouseY");
        short* theVal = (short*)theField->asVoid();
        return *theVal;
	}
	auto getMouseLoc() -> Vector2 {
		return Vector2(this->getMouseX(), this->getMouseY());
	}
};

#endif /* INCUDINE_GUIDATA_H */

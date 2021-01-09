#ifndef IGNITE_GUIDATA_H
#define IGNITE_GUIDATA_H

#include "DynamicStruct.h"
#include "../util/IMath.h"

struct GuiData : DynamicStruct {
    GuiData(uintptr_t address) : DynamicStruct("GuiData", address) {
        this->addField("resolution", 0x18);
        this->addField("scaledResolution", 0x28);
        this->addField("guiSize", 0x30);
        this->addField("guiScale", 0x38);
        this->addField("mouseX", 0x52);
        this->addField("mouseY", 0x54);
        this->addField("isWorldLoaded", 0x56);
        this->addField("heldItemSlot", 0x58);
        this->addField("heldItemName", 0x94);
    };

    auto getResolution() -> Vector2 {
        DynamicField* theField = (DynamicField*)this->get("resolution");
        Vector2* theVec = (Vector2*)theField->asVoid();
        return *theVec;
    };
    auto getScaledResolution() -> Vector2 {
        DynamicField* theField = (DynamicField*)this->get("scaledResolution");
        Vector2* theVec = (Vector2*)theField->asVoid();
        return *theVec;
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

#endif /* IGNITE_GUIDATA_H */

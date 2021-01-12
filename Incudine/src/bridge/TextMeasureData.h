#ifndef INCUDINE_TEXTMEASUREDATA_H
#define INCUDINE_TEXTMEASUREDATA_H
struct TextMeasureData {
    float scale;

    TextMeasureData() {
        this->scale = 1.0f;
    }
    TextMeasureData(float scale) {
        this->scale = scale;
    }
};
#endif /* INCUDINE_TEXTMEASUREDATA_H */

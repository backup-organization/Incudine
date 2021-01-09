#ifndef IGNITE_TEXTMEASUREDATA_H
#define IGNITE_TEXTMEASUREDATA_H
struct TextMeasureData {
    float scale;

    TextMeasureData() {
        this->scale = 1.0f;
    }
    TextMeasureData(float scale) {
        this->scale = scale;
    }
};
#endif /* IGNITE_TEXTMEASUREDATA_H */

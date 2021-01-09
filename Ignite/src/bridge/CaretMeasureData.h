#ifndef IGNITE_CARETMEASUREDATA_H
#define IGNITE_CARETMEASUREDATA_H
struct CaretMeasureData {
    int a;
    bool b;

    CaretMeasureData() {
        CaretMeasureData(0xFFFFFFFF, false);
    };
    CaretMeasureData(int param_1, bool param_2) {
        this->a = param_1;
        this->b = param_2;
    };
};
#endif /* IGNITE_CARETMEASUREDATA_H */

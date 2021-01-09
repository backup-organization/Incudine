#ifndef IGNITE_COLOR_H
#define IGNITE_COLOR_H
struct Color {
    float r;
    float g;
    float b;
    float a;

    Color() {
        this->r = 1.0f;
        this->g = 1.0f;
        this->b = 1.0f;
        this->a = 1.0f;
    };
    Color(float r, float g, float b, float a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    };
};
#endif /* IGNITE_COLOR_H */

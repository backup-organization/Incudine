#ifndef INCUDINE_COLOR_H
#define INCUDINE_COLOR_H
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


    auto getRed() -> float {
        return this->r;
    }
    auto getGreen() -> float {
        return this->g;
    }
    auto getBlue() -> float {
        return this->b;
    }
    auto getAlpha() -> float {
        return this->a;
    }

    auto setRed(float r) -> void {
        this->r = r;
    }
    auto setGreen(float g) -> void {
        this->g = g;
    }
    auto setBlue(float b) -> void {
        this->b = b;
    }
    auto setAlpha(float a) -> void {
        this->a = a;
    }
};
#endif /* INCUDINE_COLOR_H */

#ifndef INCUDINE_RECTANGLEAREA_H
#define INCUDINE_RECTANGLEAREA_H

#include "../util/IMath.h"

struct RectangleArea {
    float x;
    float w;
    float y;
    float h;

    RectangleArea(){
        this->x = 0;
        this->y = 0;
        this->w = 100;
        this->h = 100;
    };
    RectangleArea(float x, float y){
        this->x = x;
        this->y = y;
        this->w = this->x + 100;
        this->h = this->y + 100;
    };
    RectangleArea(Vector2 vec2){
        this->x = vec2.x;
        this->y = vec2.y;
        this->w = this->x + 100;
        this->h = this->y + 100;
    };
    RectangleArea(float x, float y, float w, float h){
        this->x = x;
        this->y = y;
        this->w = this->x + w;
        this->h = this->y + h;
    };
};
#endif /* INCUDINE_RECTANGLEAREA_H */

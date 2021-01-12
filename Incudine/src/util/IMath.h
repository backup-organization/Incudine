#ifndef INCUDINE_IMATH_H
#define INCUDINE_IMATH_H

struct Vector2 {
    union {
        struct {
            float x, y;
        };
        float arr[2]{};
    };
    Vector2() { x = y = 0; }
    Vector2(float x, float y) {
        this->x = x;
        this->y = y;
    }
    Vector2 operator+(Vector2 toAdd) const {
        float newX = x + toAdd.x;
        float newY = y + toAdd.y;
        return Vector2(newX, newY);
    }
    Vector2 operator-(Vector2 toSub) const {
        float newX = x - toSub.x;
        float newY = y - toSub.y;
        return Vector2(newX, newY);
    }
};

struct Vector3 {
    union {
        struct {
            float x, y, z;
        };
        float arr[3]{};
    };
    Vector3() { x = y = z = 0; }
    Vector3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector3 operator+(Vector3 toAdd) const {
        float newX = x + toAdd.x;
        float newY = y + toAdd.y;
        float newZ = z + toAdd.z;
        return Vector3(newX, newY, newZ);
    }
    Vector3 operator-(Vector3 toSub) const {
        float newX = x - toSub.x;
        float newY = y - toSub.y;
        float newZ = z - toSub.z;
        return Vector3(newX, newY, newZ);
    }
};

struct Vector3i {
    union {
        struct {
            int x, y, z;
        };
        int arr[3];
    };
};

struct Vector4 {
    union{
        struct {
            float x, y, z, w;
        };
        float arr[4]{};
    };
    Vector4(float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
    float* toArr() {
        return arr;
    }
    Vector4 operator+(Vector4 toAdd) const {
        float newX = x + toAdd.x;
        float newY = y + toAdd.y;
        float newZ = z + toAdd.z;
        float newW = w + toAdd.w;
        return Vector4(newX, newY, newZ, newW);
    }
    [[nodiscard]] bool contains(float px, float py) const {
        return x < px && y < py && z > px && w > py;
    }
    [[nodiscard]] bool contains(Vector2 point) const {
        return x < point.x && y < point.y && z > point.x && w > point.y;
    }
};


#endif //INCUDINE_IMATH_H
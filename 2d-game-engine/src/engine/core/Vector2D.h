#pragma once

#include <math.h>
#include "../utils/InternalConstants.h"

struct Vector2D {
public:
    float x, y;

    Vector2D(float x, float y);

    static Vector2D down;
    static Vector2D half;
    static Vector2D left;
    static Vector2D one;
    static Vector2D right;
    static Vector2D up;
    static Vector2D zero;
    static float distance(const Vector2D& a, const Vector2D& b);

    void set(float x, float y);
    float magnitude() const;
    float dotProduct(const Vector2D& other);
    Vector2D normalized();
    float distance(const Vector2D& other);
    float angleInRadians(const Vector2D& other);
    float angleInDegrees(const Vector2D& other);
    float toRadians();
    float toDegrees();

    Vector2D operator+(const Vector2D& other);
    Vector2D operator-(const Vector2D& other);
    Vector2D operator*(const float multiplier);
    Vector2D operator/(const float divider);
    bool operator==(const Vector2D& other);
};


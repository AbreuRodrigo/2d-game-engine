#include "Vector2D.h"

Vector2D Vector2D::down = { 0, -1 };
Vector2D Vector2D::half = { 0.5f, 0.5f };
Vector2D Vector2D::left = { -1, 0 };
Vector2D Vector2D::one = { 1, 1 };
Vector2D Vector2D::right = { 1, 0 };
Vector2D Vector2D::up = { 0, 1 };
Vector2D Vector2D::zero = { 0, 0 };

Vector2D::Vector2D(float x, float y)
{
    set(x, y);
};

void Vector2D::set(float x, float y)
{
    this->x = x;
    this->y = y;
};

float Vector2D::magnitude() const
{
    return sqrtf(x * x + y * y);
};

float Vector2D::dotProduct(const Vector2D& other)
{
    return x * other.x + y * other.y;
};

Vector2D Vector2D::normalized()
{
    float m = magnitude();
    return Vector2D(x / m, y / m);
};

float Vector2D::angleInRadians(const Vector2D& other)
{
    return acosf(dotProduct(other) / (magnitude() * other.magnitude()));
};

float Vector2D::angleInDegrees(const Vector2D& other)
{
    return angleInRadians(other) * 180.f / Math::PI;
};

float Vector2D::toRadians()
{
    return atan2f(y, x);
};

float Vector2D::toDegrees()
{
    return atan2f(y, x) * 180.f / Math::PI;
};

float Vector2D::distance(const Vector2D& a, const Vector2D& b)
{
    return sqrtf(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
};

float Vector2D::distance(const Vector2D& other)
{
    return Vector2D::distance(*this, other);
};

Vector2D Vector2D::operator+(const Vector2D& other)
{
    return Vector2D(x + other.x, y + other.y);
};

Vector2D Vector2D::operator-(const Vector2D& other)
{
    return Vector2D(x - other.x, y - other.y);
};

Vector2D Vector2D::operator*(const float multiplier)
{
    return Vector2D(x * multiplier, y * multiplier);
};

Vector2D Vector2D::operator/(const float divider)
{
    return Vector2D(x / divider, y / divider);
};

bool Vector2D::operator==(const Vector2D& other)
{
    return x == other.x && y == other.y;
};
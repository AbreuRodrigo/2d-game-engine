#include "Color.h"

const Color Color::red = Color(255, 0, 0, 255);
const Color Color::green = Color(0, 255, 0, 255);
const Color Color::blue = Color(0, 0, 255, 255);
const Color Color::white = Color(255, 255, 255, 255);
const Color Color::black = Color(0, 0, 0, 255);
const Color Color::yellow = Color(255, 255, 0, 255);
const Color Color::magenta = Color(255, 0, 255, 255);
const Color Color::cyan = Color(0, 255, 255, 255);
const Color Color::orange = Color(255, 128, 0, 255);
const Color Color::gray = Color(128, 128, 128, 255);
const Color Color::cornFlowerBlue = Color(100, 149, 237, 255);

//---------------------------------------------------------------------------------------------------------------------
Color::Color(int red, int green, int blue, int alpha) : r(red), g(green), b(blue), a(alpha) { };
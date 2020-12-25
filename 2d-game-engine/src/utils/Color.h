#pragma once

struct Color
{
public:
    int r, g, b, a;

    const static Color red;
    const static Color green;
    const static Color blue;
    const static Color white;
    const static Color yellow;
    const static Color black;
    const static Color gray;
    const static Color magenta;
    const static Color cyan;
    const static Color orange;
    const static Color cornFlowerBlue;

    Color(int red, int green, int blue, int alpha);
};
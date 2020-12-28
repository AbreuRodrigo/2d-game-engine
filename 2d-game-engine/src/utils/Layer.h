#pragma once
#include <string>

class Layer
{
private:
    int index;
    std::string label;

public:
    Layer(int index, std::string label);

    int getIndex() const;
    std::string getLabel() const;
};
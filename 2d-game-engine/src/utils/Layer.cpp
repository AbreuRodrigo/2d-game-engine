#include "Layer.h"

Layer::Layer(int index, std::string label)
{
    this->index = index;
    this->label = label;
};

int Layer::getIndex() const
{
    return index;
};

std::string Layer::getLabel() const
{
    return label;
};
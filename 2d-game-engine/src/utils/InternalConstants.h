#pragma once

#include <string>

class LayerLabel
{
public:
    static const std::string TILEMAP;
    static const std::string DEFAULT;
    static const std::string PLAYER;
    static const std::string ENEMY;
    static const std::string VEGETATION;
    static const std::string PROJECTILE;
    static const std::string GUI;
};

inline const std::string LayerLabel::DEFAULT = "Default";
inline const std::string LayerLabel::TILEMAP = "TileMap";
inline const std::string LayerLabel::PLAYER = "Player";
inline const std::string LayerLabel::ENEMY = "Enemy";
inline const std::string LayerLabel::VEGETATION = "Vegetation";
inline const std::string LayerLabel::PROJECTILE = "Projectile";
inline const std::string LayerLabel::GUI = "GUI";

class Math
{
public:
    static const float PI;
};

inline const float Math::PI = 3.14159265358979323846f;
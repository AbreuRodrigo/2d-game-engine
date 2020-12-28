#pragma once

#include <string>

class LayerLabel
{
public:
    static std::string const TILEMAP;
    static std::string const DEFAULT;
    static std::string const PLAYER;
    static std::string const ENEMY;
    static std::string const VEGETATION;
    static std::string const PROJECTILE;
    static std::string const GUI;
};

inline const std::string LayerLabel::DEFAULT = "Default";
inline const std::string LayerLabel::TILEMAP = "TileMap";
inline const std::string LayerLabel::PLAYER = "Player";
inline const std::string LayerLabel::ENEMY = "Enemy";
inline const std::string LayerLabel::VEGETATION = "Vegetation";
inline const std::string LayerLabel::PROJECTILE = "Projectile";
inline const std::string LayerLabel::GUI = "GUI";
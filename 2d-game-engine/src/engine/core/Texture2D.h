#pragma once

#include <iostream>
#include <SDL.h>
#include <string>

struct Texture2D {
protected:
    std::string filePath = "";
    SDL_Texture* textureReference = nullptr;
    SDL_Rect rect {0, 0, 0, 0};
    SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;
    Uint32 format = 0;
public:
    std::string getFilePath() const;
    SDL_Texture* getTextureReference() const;
    SDL_Rect getRect() const;
    SDL_RendererFlip getFlip() const;
    Uint32 getFormat() const;

    Texture2D(std::string filePath);
    ~Texture2D();
};


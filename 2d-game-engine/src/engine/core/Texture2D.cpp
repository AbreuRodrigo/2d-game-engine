#include "Texture2D.h"

#include <SDL_image.h>
#include "../systems/GameSystem.h"

//---------------------------------------------------------------------------------------------------------------------
std::string Texture2D::getFilePath() const {
    return this->filePath;
};

//---------------------------------------------------------------------------------------------------------------------
SDL_Texture* Texture2D::getTextureReference() const {
    return this->textureReference;
};

//---------------------------------------------------------------------------------------------------------------------
SDL_Rect Texture2D::getRect() const{
    return this->rect;
};

//---------------------------------------------------------------------------------------------------------------------
SDL_RendererFlip Texture2D::getFlip() const {
    return this->flip;
};

//---------------------------------------------------------------------------------------------------------------------
Uint32 Texture2D::getFormat() const {
    return this->format;
};

//---------------------------------------------------------------------------------------------------------------------
Texture2D::Texture2D(std::string filePath) {
    if (filePath.empty()) {
        std::cerr << "The filePath for a Texture2D cannot be empty or null." << std::endl;
        return;
    }

    SDL_Surface* surface = IMG_Load(filePath.c_str());
    this->textureReference = SDL_CreateTextureFromSurface(GameSystem::getRenderer(), surface);
    SDL_FreeSurface(surface);

    SDL_QueryTexture(this->textureReference, &format, nullptr, &this->rect.w, &this->rect.h);
};

//---------------------------------------------------------------------------------------------------------------------
Texture2D::~Texture2D() {    
};
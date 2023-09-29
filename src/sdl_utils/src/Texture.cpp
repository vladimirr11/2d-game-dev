// Corresponding header
#include "sdl_utils/Texture.h"

// C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_ttf.h>

// Own includes
#include "utils/drawing/Color.h"
#include "utils/error/HandleError.h"

static SDL_Renderer* gRendererPtr = nullptr;

int32_t Texture::createSurfaceFromFile(const std::string& filePath, SDL_Surface*& outSurfice) {
    outSurfice = IMG_Load(filePath.c_str());

    if (outSurfice == nullptr) {
        std::cerr << "In Texture::createSurfaceFromFile() - IMG_Load() failed. Reason: "
                  << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int32_t Texture::createTextureFromFile(const std::string& filePath, SDL_Texture*& outSurface) {
    SDL_Surface* tempSurface = nullptr;

    handleError(createSurfaceFromFile(filePath, tempSurface));
    handleError(createTextureFromSurface(tempSurface, outSurface));

    return EXIT_SUCCESS;
}

int32_t Texture::createTextureFromSurface(SDL_Surface*& surface, SDL_Texture*& outTexture) {
    outTexture = SDL_CreateTextureFromSurface(gRendererPtr, surface);

    if (outTexture == nullptr) {
        std::cerr << "In Texture::createTextureFromSurface() - SDL_CreateTextureFromSurface() "
                     "failed. Reason: "
                  << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    freeSurface(surface);

    return EXIT_SUCCESS;
}

int32_t Texture::createTextureFromText(const std::string& text, const Color& color, TTF_Font* font,
                                       SDL_Texture*& outTexture, int32_t& outTextWidth,
                                       int32_t& outTextHeight) {
    const SDL_Color* sdlColor = reinterpret_cast<const SDL_Color*>(&color.rgba);

    SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), *sdlColor);
    if (textSurface == nullptr) {
        std::cerr
            << "In Texture::createTextureFromText() - TTF_RenderText_Blended() failed. Reason: "
            << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    outTextWidth = textSurface->w;
    outTextHeight = textSurface->h;

    handleError(Texture::createTextureFromSurface(textSurface, outTexture));

    return EXIT_SUCCESS;
}

void Texture::freeSurface(SDL_Surface*& outSurface) {
    if (outSurface) {
        SDL_FreeSurface(outSurface);
        outSurface = nullptr;
    }
}

void Texture::freeTexture(SDL_Texture*& outTexture) {
    if (outTexture) {
        SDL_DestroyTexture(outTexture);
        outTexture = nullptr;
    }
}

void Texture::setRenderer(SDL_Renderer* renderer) { gRendererPtr = renderer; }

int32_t Texture::setTextureBlendMode(SDL_Texture* texture, const BlendMode blendMode) {
    handleError(SDL_SetTextureBlendMode(texture, static_cast<SDL_BlendMode>(blendMode)));
    return EXIT_SUCCESS;
}

int32_t Texture::setTextureAlpha(SDL_Texture* texture, const int32_t alpha) {
    if (ZERO_OPACITY > alpha || FULL_OPACITY > alpha) {
        std::cerr << "In Texture::setTextureAlpha() invalid alpha value: " << alpha << " provided."
                  << std::endl;
        return EXIT_FAILURE;
    }

    handleError(SDL_SetTextureAlphaMod(texture, static_cast<uint8_t>(alpha)));

    return EXIT_SUCCESS;
}

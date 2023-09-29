#ifndef TEXTURE_H
#define TEXTURE_H

// C++ system includes
#include <string>

// Own includes
#include "utils/drawing/DrawParams.h"

// Forward declarations
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;
struct Color;
typedef struct _TTF_Font TTF_Font;

struct Texture {
    Texture() = delete;

    ~Texture();

    static int32_t createSurfaceFromFile(const std::string& filePath, SDL_Surface*& outSurface);

    static int32_t createTextureFromFile(const std::string& filePath, SDL_Texture*& outTexture);
    static int32_t createTextureFromSurface(SDL_Surface*& surface, SDL_Texture*& outTexture);
    static int32_t createTextureFromText(const std::string& text, const Color& color,
                                         TTF_Font* font, SDL_Texture*& outTexture,
                                         int32_t& outTextWidth, int32_t& outTextHeight);

    static void freeSurface(SDL_Surface*& outSurface);
    static void freeTexture(SDL_Texture*& outTexture);

    static void setRenderer(SDL_Renderer* renderer);

    static int32_t setTextureBlendMode(SDL_Texture* texture, const BlendMode blendMode);
    static int32_t setTextureAlpha(SDL_Texture* texture, const int32_t alpha);
};

#endif  // !TEXTURE_H

#ifndef TEXTCONTAINER_H
#define TEXTCONTAINER_H

// C++ system includes
#include <vector>

// Own includes
#include "sdl_utils/config/TextContainerCfg.h"

// Forward declarations
struct SDL_Texture;
struct Color;
typedef struct _TTF_Font TTF_Font;

class TextContainer {
public:
    int32_t createText(const std::string& text, const Color& color, int32_t fontId, int32_t& outTextId,
                    int32_t& outTextWidth, int32_t& outTextHeight);

    int32_t reloadText(const std::string& text, const Color& color, int32_t fontId, int32_t textId,
                    int32_t& outTextWidth, int32_t& outTextHeight);

    int32_t unloadText(int32_t textId);

    SDL_Texture* getTextTexture(int32_t textId) const;

protected:
    int32_t init(const TextContainerConfig& cfg);
    void deinit();

private:
    void occupyFreeSlotIndex(int32_t& outIndex, SDL_Texture* texture);
    void freeSlotIndex(int32_t index);

private:
    std::vector<SDL_Texture*> _textures;
    std::unordered_map<int32_t, TTF_Font*> _fonts;
};

#endif  // !TEXTCONTAINER_H

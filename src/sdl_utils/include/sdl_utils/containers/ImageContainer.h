#ifndef IMAGECONTAINER_H
#define IMAGECONTAINER_H

// Own includes
#include "sdl_utils/config/ImageContainerCfg.h"
#include "utils/drawing/Rectangle.h"

// Forward declarations
struct SDL_Texture;

class ImageContainer {
public:
    SDL_Texture* getImageTexture(int32_t rsrcId) const;

    Rectangle getImageFrame(int32_t rsrcId) const;

protected:
    int32_t init(const ImageContainerConfig& imageCfg);

    void deinit();

private:
    int32_t loadSingleResource(const ImageConfig& resourceCfg, int32_t resourceId);

private:
    std::unordered_map<int32_t, SDL_Texture*> _textures;
    std::unordered_map<int32_t, Rectangle> _textureFrames;
};

#endif  // !IMAGECONTAINER_H

#ifndef IMAGECONTAINER_H
#define IMAGECONTAINER_H

// Own includes
#include "sdl_utils/config/ImageContainerCfg.h"
#include "utils/drawing/Rectangle.h"

// Forward declarations
struct SDL_Texture;

using Frames = std::vector<Rectangle>;

class ImageContainer {
public:
    SDL_Texture* getImageTexture(const int32_t imageResId) const;
    const Frames& getImageFrames(const int32_t imageResId) const;

protected:
    int32_t init(const ImageContainerConfig& imageCfg);
    void deinit();

private:
    int32_t loadSingleResource(const ImageConfig& resourceCfg, const int32_t imageResId);

private:
    std::unordered_map<int32_t, SDL_Texture*> _textures;
    std::unordered_map<int32_t, Frames> _textureFrames;
};

#endif  // !IMAGECONTAINER_H

// Corresponding header
#include "sdl_utils/containers/ImageContainer.h"

// C++ system includes
#include <iostream>

// Own includes
#include "sdl_utils/Texture.h"
#include "utils/error/HandleError.h"

static const Frames EMPTY_FRAMES{Rectangle::ZERO};

int32_t ImageContainer::init(const ImageContainerConfig& cfg) {
    for (const auto& [resId, elem] : cfg.imageConfigs) {
        handleError(loadSingleResource(elem, resId));
    }
    return EXIT_SUCCESS;
}

void ImageContainer::deinit() {
    for (auto& [_, texturePtr] : _textures) {
        Texture::freeTexture(texturePtr);
    }
}

SDL_Texture* ImageContainer::getImageTexture(const int32_t imageResId) const {
    const auto it = _textures.find(imageResId);
    if (it == _textures.end()) {
        std::cerr
            << "Invalid image ID requested in ImageContainer::getImageTexture(). ID provided - "
            << imageResId << std::endl;
        return nullptr;
    }
    return it->second;
}

const Frames& ImageContainer::getImageFrames(const int32_t imageResId) const {
    const auto it = _textureFrames.find(imageResId);
    if (it == _textureFrames.end()) {
        std::cerr << "Invalid image ID requested in ImageContainer::getImageFrame(). ID provided - "
                  << imageResId << std::endl;
        return EMPTY_FRAMES;
    }
    return it->second;
}

int32_t ImageContainer::loadSingleResource(const ImageConfig& imageCfg, const int32_t imageResId) {
    SDL_Texture* texture = nullptr;
    handleError(Texture::createTextureFromFile(imageCfg.location, texture));

    _textures[imageResId] = texture;
    _textureFrames[imageResId] = imageCfg.frames;

    return EXIT_SUCCESS;
}

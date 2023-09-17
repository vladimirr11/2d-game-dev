// Corresponding header
#include "sdl_utils/containers/ImageContainer.h"

// C++ system includes
#include <iostream>

// Own includes
#include "sdl_utils/Texture.h"

static const Frames EMPTY_FRAMES{Rectangle::ZERO};

int32_t ImageContainer::init(const ImageContainerCfg& cfg) {
    for (const auto& pair : cfg.imageConfigs) {
        const int32_t resId = pair.first;
        const auto& elem = pair.second;

        if (loadSingleResource(elem, resId) != EXIT_SUCCESS) {
            std::cerr << "In ImageContainer::init() loadSingleResource() failed for file: "
                      << elem.location << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

void ImageContainer::deinit() {
    for (auto& pair : _textures) {
        Texture::freeTexture(pair.second);
    }
}

SDL_Texture* ImageContainer::getImageTexture(int32_t rsrcId) const {
    const auto it = _textures.find(rsrcId);
    if (it == _textures.end()) {
        std::cerr << "Invalid rsrcId in ImageContainer::getImageTexture() " << rsrcId
                  << "requested." << std::endl;
        return nullptr;
    }

    return it->second;
}

const Frames& ImageContainer::getImageFrame(int32_t rsrcId) const {
    const auto it = _textureFrames.find(rsrcId);
    if (it == _textureFrames.end()) {
        std::cerr << "Invalid rsrcId in ImageContainer::getImageFrame() " << rsrcId << "requested."
                  << "Returning EMPTY_FRAMES." << std::endl;
        return EMPTY_FRAMES;
    }

    return it->second;
}

int32_t ImageContainer::loadSingleResource(const ImageConfig& resourceCfg, int32_t resourceId) {
    SDL_Texture* texture = nullptr;

    if (Texture::createTextureFromFile(resourceCfg.location, texture) != EXIT_SUCCESS) {
        std::cerr << "Texture::createTextureFromFile failed for file: " << resourceCfg.location
                  << std::endl;
        return EXIT_FAILURE;
    }
    _textures[resourceId] = texture;
    _textureFrames[resourceId] = resourceCfg.frames;

    return EXIT_SUCCESS;
}

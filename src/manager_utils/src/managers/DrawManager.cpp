// Corresponding header
#include "manager_utils/managers/DrawManager.h"

// C++ system includes
#include <iostream>

// Own includes
#include "manager_utils/managers/config/DrawManagerCfg.h"
#include "manager_utils/managers/ResourceManager.h"
#include "utils/drawing/DrawParams.h"
#include "utils/error/HandleError.h"

DrawManager* gDrawManager = nullptr;

int32_t DrawManager::init(const DrawManagerConfig& drawManagerCfg) {
    handleError(_window.init(drawManagerCfg.windowConfig));
    handleError(_renderer.init(_window.getWindow()));

    _maxFrames = drawManagerCfg.maxFrameRate;

    return EXIT_SUCCESS;
}

void DrawManager::deinit() {
    _renderer.deinit();
    _window.deinit();
}

void DrawManager::process() {}

void DrawManager::clearScreen() { _renderer.clearScreen(); }

void DrawManager::finishFrame() { _renderer.finishFrame(); }

void DrawManager::addDrawCommand(const DrawParams& drawParams) {
    SDL_Texture* texture = getTextureInternal(drawParams);
    _renderer.renderTexture(texture, drawParams);
}

void DrawManager::setWidgetBlendMode(const DrawParams& drawParams, const BlendMode blendMode) {
    SDL_Texture* texture = getTextureInternal(drawParams);
    _renderer.setWidgetBlendMode(texture, blendMode);
}

void DrawManager::setWidgetOpacity(const DrawParams& drawParams, const int32_t opacity) {
    if (drawParams.widgetType == WidgetType::IMAGE) {
        return;
    }

    SDL_Texture* texture = getTextureInternal(drawParams);
    _renderer.setWidgetOpacity(texture, opacity);
}

SDL_Texture* DrawManager::getTextureInternal(const DrawParams& drawParams) const {
    if (drawParams.widgetType == WidgetType::TEXT) {
        return gResourceManager->getTextTexture(drawParams.rsrcId);
    } else if (drawParams.widgetType == WidgetType::IMAGE) {
        return gResourceManager->getImageTexture(drawParams.rsrcId);
    } else {
        std::cerr << "In DrawManager::getTextureInternal() recieved unsupported WidgetType - "
                  << static_cast<int32_t>(drawParams.widgetType) << " for resourceId - "
                  << drawParams.rsrcId << std::endl;
    }

    return nullptr;
}

int64_t DrawManager::getMaxFrameRate() const { return _maxFrames; }

int32_t DrawManager::getActiveWidgets() const { return _renderer.getActiveWidgets(); }

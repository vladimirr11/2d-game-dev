#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

// Own includes
#include "manager_utils/managers/ManagerBase.h"
#include "sdl_utils/Renderer.h"
#include "sdl_utils/MonitorWindow.h"

// Forward declarations
struct DrawManagerConfig;
struct SDL_Texture;

class DrawManager : public ManagerBase {
public:
    DrawManager() = default;

    DrawManager(const DrawManager& other) = delete;
    DrawManager(DrawManager&& other) = delete;
    DrawManager& operator=(const DrawManager& other) = delete;
    DrawManager& operator=(DrawManager&& other) = delete;

    int32_t init(const DrawManagerConfig& drawManagerCfg);

    void process() final;
    void deinit() final;

    void clearScreen();
    void finishFrame();

    void addDrawCommand(const DrawParams& drawParams);

    void setWidgetBlendMode(const DrawParams& drawParams, const BlendMode blendMode);
    void setWidgetOpacity(const DrawParams& drawParams, const int32_t opacity);

    int64_t getMaxFrameRate() const;

private:
    SDL_Texture* getTextureInternal(const DrawParams& drawParams) const;

private:
    MonitorWindow _window;
    Renderer _renderer;
    int64_t _maxFrames{0};
};

extern DrawManager* gDrawManager;

#endif  // !DRAWMANAGER_H

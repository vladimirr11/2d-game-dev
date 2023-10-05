#ifndef RENDERER_H
#define RENDERER_H

// Own includes
#include "utils/drawing/DrawParams.h"

// Forward declarations
struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Window;

class Renderer {
public:
    Renderer() = default;

    Renderer(const Renderer& other) = delete;
    Renderer(Renderer&& other) = delete;
    Renderer& operator=(const Renderer& other) = delete;
    Renderer& operator=(Renderer&& other) = delete;

    int32_t init(SDL_Window* window);
    void deinit();
    void clearScreen();
    void renderTexture(SDL_Texture* texture, const DrawParams& drawParams);
    void finishFrame();

    void setWidgetBlendMode(SDL_Texture* texture, BlendMode blendMode);
    void setWidgetOpacity(SDL_Texture* texture, int32_t opacity);

    int32_t getActiveWidgets() const;

private:
    void drawImage(const DrawParams& drawParams, SDL_Texture* texture);
    void drawText(const DrawParams& drawParams, SDL_Texture* texture);
    void drawTextureInternal(const DrawParams& drawParams, SDL_Texture* texture);

private:
    SDL_Renderer* _sdlRenderer = nullptr;
    int32_t _activeWidgets{};
};

#endif  // !RENDERER_H

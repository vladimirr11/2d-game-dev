#ifndef MONITORWINDOW_H
#define MONITORWINDOW_H

// Own includes
#include "sdl_utils/config/MonitorWindowCfg.h"

// Forward declarations
struct SDL_Window;
struct SDL_Surface;

class MonitorWindow {
public:
    ~MonitorWindow();

    MonitorWindow() = default;
    MonitorWindow(const MonitorWindow& other) = delete;
    MonitorWindow(MonitorWindow&& other) = delete;

    MonitorWindow& operator=(const MonitorWindow& other) = delete;
    MonitorWindow& operator=(MonitorWindow&& other) = delete;

    int32_t init(const MonitorWindowConfig& cfg);
    void deinit();
    void updateWindowSurface();
    SDL_Window* getWindow();

private:
    SDL_Window* _window = nullptr;
};

#endif  // !MONITORWINDOW_H

#ifndef MONITORWINDOWCFG_H
#define MONITORWINDOWCFG_H

// C++ system includes
#include <string>

// Own includes
#include "utils/drawing/Point.h"

enum WindowFlags {
    WINDOW_SHOWN = 4,              // SDL_WINDOW_SHOWN
    WINDOW_FULLSCREEN_MODE = 4097  // SDL_WINDOW_FULLSCREEN_MODE
};

struct MonitorWindowCfg {
    std::string windowName;
    Point windowPos = Point::UNDEFINED;
    int32_t windowWidth = 0;
    int32_t windowHeight = 0;
    WindowFlags windowFlags = WINDOW_SHOWN;
};

#endif  // !MONITORWINDOWCFG_H

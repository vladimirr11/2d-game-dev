#ifndef DRAWMANAGERCFG_H
#define DRAWMANAGERCFG_H

// Own includes
#include "sdl_utils/config/MonitorWindowCfg.h"

struct DrawManagerConfig {
    MonitorWindowConfig windowConfig;
    int64_t maxFrameRate;
};

#endif  // !DRAWMANAGERCFG_H

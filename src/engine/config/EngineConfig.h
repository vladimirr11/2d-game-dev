#ifndef ENGINECONFIG_H
#define ENGINECONFIG_H

// C++ system includes
#include <cstdint>

// Own includes
#include "sdl_utils/config/ImageContainerCfg.h"
#include "sdl_utils/config/MonitorWindowCfg.h"
#include "sdl_utils/config/TextContainerCfg.h"
#include "game/config/GameConfig.h"

struct EngineConfig {
    MonitorWindowCfg windowConfig;
    ImageContainerConfig imageContainerCfg;
    TextContainerCfg textContainerCfg;
    GameConfig gameCfg;
};

#endif  // !ENGINECONFIG_H

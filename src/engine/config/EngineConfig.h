#ifndef ENGINECONFIG_H
#define ENGINECONFIG_H

// C++ system includes
#include <cstdint>

// Own includes
#include "game/config/GameConfig.h"
#include "manager_utils/managers/config/ManagerHandlerCfg.h"

struct EngineConfig {
    ManagerHandlerCfg managerHandlerCfg;
    GameConfig gameCfg;
};

#endif  // !ENGINECONFIG_H

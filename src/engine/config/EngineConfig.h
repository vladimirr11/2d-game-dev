#ifndef ENGINECONFIG_H
#define ENGINECONFIG_H

// Own includes
#include "game/config/GameConfig.h"
#include "manager_utils/managers/config/ManagerHandlerCfg.h"

struct EngineConfig {
    ManagerHandlerConfig managerHandlerCfg;
    GameConfig gameCfg;
    int32_t debugConsoleFontId;
};

#endif  // !ENGINECONFIG_H

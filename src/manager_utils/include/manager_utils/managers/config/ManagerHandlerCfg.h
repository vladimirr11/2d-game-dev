#ifndef MANAGERHANDLERCFG_H
#define MANAGERHANDLERCFG_H

// Own includes
#include "manager_utils/managers/config/DrawManagerCfg.h"
#include "manager_utils/managers/config/ResourceManagerCfg.h"

struct ManagerHandlerConfig {
    DrawManagerConfig drawManagerCfg;
    ResourceManagerConfig resourceManagerCfg;
};

#endif  // !MANAGERHANDLERCFG_H

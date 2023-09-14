#ifndef ENGINECONFIGLOADER_H
#define ENGINECONFIGLOADER_H

// Own includes
#include "engine/config/EngineConfig.h"

struct EngineConfigLoader {
    EngineConfigLoader() = delete;
    ~EngineConfigLoader() = default;

    static EngineConfig loadConfig();
};

#endif  // !ENGINECONFIGLOADER_H

#ifndef ENGINECONFIGLOADER_H
#define ENGINECONFIGLOADER_H

// Own includes
#include "engine/config/EngineConfig.h"

class EngineConfigLoader {
public:
    EngineConfigLoader() = delete;
    ~EngineConfigLoader() = default;

    static EngineConfig loadConfig();
};

#endif  // !ENGINECONFIGLOADER_H

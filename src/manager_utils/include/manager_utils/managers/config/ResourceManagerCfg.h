#ifndef RESOURCEMANAGERCFG_H
#define RESOURCEMANAGERCFG_H

// Own includes
#include "sdl_utils/config/TextContainerCfg.h"
#include "sdl_utils/config/ImageContainerCfg.h"

struct ResourceManagerConfig {
    ImageContainerConfig imageContainerCfg;
    TextContainerCfg textContainerCfg;
};

#endif  // !RESOURCEMANAGERCFG_H

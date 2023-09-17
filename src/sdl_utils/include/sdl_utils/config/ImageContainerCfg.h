#ifndef IMAGECONTAINERCFG_H
#define IMAGECONTAINERCFG_H

// C++ system includes
#include <unordered_map>
#include <string>
#include <vector>

// Own includes
#include "utils/drawing/Rectangle.h"

struct ImageConfig {
    std::string location;
    std::vector<Rectangle> frames;
};

struct ImageContainerCfg {
    std::unordered_map<int32_t, ImageConfig> imageConfigs;
};

#endif  // !IMAGECONTAINERCFG_H

#ifndef IMAGECONTAINERCFG_H
#define IMAGECONTAINERCFG_H

// C++ system includes
#include <string>
#include <unordered_map>
#include <vector>

// Own includes
#include "utils/drawing/Rectangle.h"

struct ImageConfig {
    std::string location;
    std::vector<Rectangle> frames;
};

struct ImageContainerConfig {
    std::unordered_map<int32_t, ImageConfig> imageConfigs;
};

#endif  // !IMAGECONTAINERCFG_H

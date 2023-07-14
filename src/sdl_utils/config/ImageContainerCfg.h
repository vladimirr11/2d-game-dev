#ifndef IMAGECONTAINERCFG_H
#define IMAGECONTAINERCFG_H

// C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

struct ImageConfig {
    std::string location;
    int32_t width = 0;
    int32_t height = 0;
};

struct ImageContainerConfig {
    std::unordered_map<int32_t, ImageConfig> imageConfigs;
};

#endif  // !IMAGECONTAINERCFG_H

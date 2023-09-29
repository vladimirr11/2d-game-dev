#ifndef TEXTCONTAINERCFG_H
#define TEXTCONTAINERCFG_H

// C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

struct FontConfig {
    std::string location;
    int32_t fontSize = 0;
};

struct TextContainerConfig {
    std::unordered_map<int32_t, FontConfig> textConfigs;
};

#endif  // !TEXTCONTAINERCFG_H

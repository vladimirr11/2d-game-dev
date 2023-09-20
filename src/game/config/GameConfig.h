#ifndef GAMECONFIG_H
#define GAMECONFIG_H

// C++ system includes
#include <cstdint>
#include <unordered_map>
#include <string>

struct GameConfig {
    int32_t runningGirlId;
    int32_t wheelId;
    int32_t startButtonId;
    int32_t stopButtonId;
    int32_t textFontId;
    int32_t wheelRotationTimerId;
    int32_t scaleWheelId;
    int32_t runningGirlTimerId;
};

#endif  // !GAMECONFIG_H

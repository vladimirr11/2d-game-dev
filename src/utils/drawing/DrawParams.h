#ifndef DRAWPARAMS_H
#define DRAWPARAMS_H

// C++ system includes
#include <cstdint>

// Own includes
#include "utils/drawing/Point.h"

inline constexpr auto RESOURCE_ID = -1;
inline constexpr int32_t FULL_OPACITY = 255;
inline constexpr int32_t ZERO_OPACITY = 0;

enum class BlendMode : uint8_t {
    NONE = 0,   // value for SDL_BLENDMODE_NONE
    BLEND = 1,  // value for SDL_BLENDMODE_BLEND
    ADD = 2,    // value for SDL_BLENDMODE_ADD
    MOD = 4     // value for SDL_BLENDMODE_MODE
};

struct DrawParams {
    Point pos = Point::UNDEFINED;
    // Draw dimensions of the texture
    int32_t width = 0;
    int32_t height = 0;
    int32_t opacity = FULL_OPACITY;
    // unique resourceId
    int32_t rsrcId = RESOURCE_ID;
    BlendMode blendMode = BlendMode::NONE;
};

#endif  // !DRAWPARAMS_H

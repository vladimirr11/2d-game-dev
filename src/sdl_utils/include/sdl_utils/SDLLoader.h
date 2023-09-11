#ifndef SDLLOADER_H
#define SDLLOADER_H

// C++ system includes
#include <cstdint>

struct SDLLoader {
    SDLLoader() = delete;
    ~SDLLoader() = default;

    static int32_t init();
    static void deinit();
};

#endif  // !SDLLOADER_H

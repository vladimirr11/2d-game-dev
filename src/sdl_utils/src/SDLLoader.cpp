// Corresponding headers
#include "sdl_utils/SDLLoader.h"

// C++ system includes
#include <iostream>

// Third-party includes
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

// Own includes
#include "utils/error/HandleError.h"

int32_t SDLLoader::init() {
    handleError(TTF_Init());

    handleError(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO));

    constexpr int32_t imgFlags = IMG_INIT_PNG;
    handleError(!(IMG_Init(imgFlags) & imgFlags));

    handleError(Mix_OpenAudio(44100,               // sound frequency
                              MIX_DEFAULT_FORMAT,  // sample format
                              2,                   // stereo hardware channels
                              2048));

    return EXIT_SUCCESS;
}

void SDLLoader::deinit() {
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}

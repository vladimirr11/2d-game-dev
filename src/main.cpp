// C++ system headers
#include <iostream>

#define SDL_MAIN_HANDLED

// Own includes
#include "sdl_utils/SDLLoader.h"
#include "utils/error/HandleError.h"
#include "engine/Engine.h"
#include "engine/EngineConfigLoader.h"

static int32_t runEngine() {
    Engine engine;

    handleError(engine.init(EngineConfigLoader::loadConfig()));

    engine.start();

    engine.deinit();

    return EXIT_SUCCESS;
}

int32_t main([[maybe_unused]] int32_t argc, [[maybe_unused]] char* argv[]) {
    handleError(SDLLoader::init());

    handleError(runEngine());

    SDLLoader::deinit();

    return EXIT_SUCCESS;
}

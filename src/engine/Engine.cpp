// Corresponding header
#include "engine/Engine.h"

// C++ system includes
#include <iostream>

// Own includes
#include "sdl_utils/Texture.h"
#include "utils/thread/ThreadUtils.h"
#include "utils/time/Time.h"
#include "utils/error/HandleError.h"
#include "engine/EngineConfigLoader.h"
#include "manager_utils/managers/DrawManager.h"
#include "manager_utils/managers/TimerManager.h"

int32_t Engine::init(const EngineConfig& cfg) {
    handleError(_managerHandler.init(cfg.managerHandlerCfg));
    handleError(_event.init());
    handleError(_game.init(cfg.gameCfg));
    handleError(_debugConsole.init(cfg.managerHandlerCfg.drawManagerCfg.maxFrameRate,
                                   cfg.debugConsoleFontId));

    gTimerManager->onInitEnd();

    return EXIT_SUCCESS;
}

void Engine::deinit() {
    _game.deinit();
    _event.deinit();
    _managerHandler.deinit();
}

void Engine::start() { mainLoop(); }

void Engine::mainLoop() {
    Time time;

    while (true) {
        time.getElapsed();
        const bool shouldExit = processFrame();
        if (shouldExit) {
            break;
        }

        const auto elapsedTime = time.getElapsed().toMicroseconds();
        if (_debugConsole.isActive() && elapsedTime != 0) {
            _debugConsole.update(elapsedTime, gTimerManager->getActiveTimersCount());
        }

        limitFPS(elapsedTime);
    }
}

void Engine::drawFrame() {
    gDrawManager->clearScreen();

    _game.draw();

    if (_debugConsole.isActive()) {
        _debugConsole.draw();
    }

    gDrawManager->finishFrame();
}

bool Engine::processFrame() {
    _managerHandler.process();

    while (_event.pollEvent()) {
        if (_event.checkForExit()) {
            return true;
        }

        handleEvent();
    }

    drawFrame();

    return false;
}

void Engine::handleEvent() {
    _game.handleEvent(_event);
    _debugConsole.handleEvent(_event);
}

void Engine::limitFPS(const int64_t microsecToSleepFor) {
    constexpr int64_t microsecInSecond = 1'000'000;
    const int64_t microsecPerFrame = microsecInSecond / gDrawManager->getMaxFrameRate();
    const int64_t sleepFor = microsecPerFrame - microsecToSleepFor;

    if (sleepFor > 0) {
        Threading::sleepFor(sleepFor);
    }
}

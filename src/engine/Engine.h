#ifndef ENGINE_H
#define ENGINE_H

// Own includes
#include "game/Game.h"
#include "sdl_utils/InputEvent.h"
#include "manager_utils/managers/ManagerHandler.h"
#include "manager_utils/debug/DebugConsole.h"

// Forward declarations
struct EngineConfig;

class Engine {
public:
    int32_t init(const EngineConfig& cfg);
    void deinit();
    void start();

private:
    void mainLoop();
    void drawFrame();
    bool processFrame();
    void handleEvent();
    void limitFPS(const int64_t microsecToSleepFor);

private:
    ManagerHandler _managerHandler;
    InputEvent _event;
    Game _game;
    DebugConsole _debugConsole;
};

#endif  // !ENGINE_H

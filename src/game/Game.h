#ifndef GAME_H
#define GAME_H

// Own includes
#include "game/config/GameConfig.h"
#include "game/entities/Hero.h"
#include "game/entities/Wheel.h"
#include "game/proxies/GameProxy.h"
#include "game/buttons/WheelButton.h"
#include "manager_utils/drawing/Image.h"
#include "manager_utils/drawing/Text.h"

// Forward declarations
struct InputEvent;

class Game : public GameProxy {
public:
    int32_t init(const GameConfig& gameCfg);
    void deinit();
    void draw();
    void handleEvent(const InputEvent& event);

private:
    void onButtonPressed(int32_t buttonId) final;

    enum ButtonIndxs { WHEEL_START_BUTTON_IDX, WHEEL_STOP_BUTTON_IDX, WHEEL_BUTTONS_COUNT };

private:
    Hero _hero;
    Wheel _wheel;
    WheelButton _wheelButtons[WHEEL_BUTTONS_COUNT];
};

#endif  // !GAME_H

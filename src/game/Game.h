#ifndef GAME_H
#define GAME_H

// Own includes
#include "game/config/GameConfig.h"
#include "manager_utils/drawing/Image.h"
#include "manager_utils/drawing/Text.h"

// Forward declarations
struct InputEvent;

class Game {
public:
    int32_t init(const GameConfig& gameCfg);

    void deinit();

    void draw();

    void handleEvent(const InputEvent& event);

private:
    void setMousePosText(const Point& mousePos);

private:
    Text _mousePosText;
};

#endif  // !GAME_H

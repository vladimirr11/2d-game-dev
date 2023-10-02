#ifndef GAMEBOARDANIMATOR_H
#define GAMEBOARDANIMATOR_H

// C++ system includes
#include <cstdint>

// Own includes
#include "manager_utils/drawing/Image.h"

// Forward declarations
class GameProxy;

class GameBoardAnimator {
public:
    int32_t init(GameProxy* gameProxy, Image* boardImage);
    void startAnim(const int32_t playerId);

private:
    void onAnimEnd();

private:
    GameProxy* _gameProxy = nullptr;
    Image* _boardImage = nullptr;
    int32_t _currRotation{0};
    WidgetFlip _targetFlipType = WidgetFlip::NONE;
};

#endif  // !GAMEBOARDANIMATOR_H

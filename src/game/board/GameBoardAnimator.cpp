// Corresponding header
#include "game/board/GameBoardAnimator.h"

// C++ system headers
#include <iostream>

// Own components headers
#include "game/proxies/GameProxy.h"
#include "game/chess_defines/ChessDefines.h"

namespace {
constexpr int32_t ROTATION_STEP = 180;
}

int32_t GameBoardAnimator::init(GameProxy* gameProxy, Image* boardImage) {
    if (gameProxy == nullptr) {
        std::cerr << "In GameBoardAnimator::init() nullptr provided for GameProxy." << std::endl;
        return EXIT_FAILURE;
    }
    _gameProxy = gameProxy;

    if (boardImage == nullptr) {
        std::cerr << "In GameBoardAnimator::init() nullptr provided for board image." << std::endl;
        return EXIT_FAILURE;
    }
    _boardImage = boardImage;
    _boardImage->setRotationCenter(
        Point(_boardImage->getWidth() / 2, _boardImage->getHeight() / 2));

    return EXIT_SUCCESS;
}

void GameBoardAnimator::startAnim(int32_t playerId) {
    if (playerId == WHITE_PLAYER_ID) {
        _currRotation = ROTATION_STEP;
        _targetFlipType = WidgetFlip::HORIZONTAL_AND_VERTICAL;
    } else {
        _currRotation = 0;
        _targetFlipType = WidgetFlip::NONE;
    }

    onAnimEnd();
}

void GameBoardAnimator::onAnimEnd() {
    _boardImage->setRotation(_currRotation);
    _gameProxy->setWidgetFlipType(_targetFlipType);
}

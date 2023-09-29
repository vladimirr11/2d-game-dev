// Corresponding header
#include "game/board/ChessBoard.h"

// C++ system includes
#include <iostream>

// Own includes
#include "game/utility/BoardUtils.h"
#include "utils/error/HandleError.h"

ChessBoard::~ChessBoard() {
    if (isTimerActive(_blinkTimerId)) {
        stopTimer(_blinkTimerId);
    }
}

int32_t ChessBoard::init(const int32_t chessBoardImageId, const int32_t targetId,
                         const int32_t moveSelectorResId, const int32_t blinkTimerId) {
    _chessBoardImage.create(chessBoardImageId);
    _targetImage.create(targetId);
    _targetImage.hide();

    handleError(_moveSelector.init(moveSelectorResId));

    _blinkTimerId = blinkTimerId;

    return EXIT_SUCCESS;
}

void ChessBoard::draw() {
    _chessBoardImage.draw();
    _targetImage.draw();
    _moveSelector.draw();
}

void ChessBoard::onPieceSelected(const BoardPosition& boardPos,
                                 const std::vector<TileData>& moveTiles) {
    _currMoveTiles = moveTiles;
    _moveSelector.markTiles(_currMoveTiles);

    _targetImage.show();
    _targetImage.setPosition(BoardUtils::getAbsPos(boardPos));

    startTimer(600, _blinkTimerId, TimerType::PULSE);
}

void ChessBoard::onPieceReleased() {
    _moveSelector.unmarkTiles();
    _currMoveTiles.clear();
    _targetImage.hide();

    if (isTimerActive(_blinkTimerId)) {
        stopTimer(_blinkTimerId);
    }
}

bool ChessBoard::isMoveAllowed(const BoardPosition& pos) const {
    for (const auto& moveTile : _currMoveTiles) {
        if (moveTile.boardPos == pos) {
            if (moveTile.tileType == TileType::MOVE || moveTile.tileType == TileType::TAKE) {
                return true;
            }
        }
    }

    return false;
}

void ChessBoard::onTimeout(int32_t timerId) {
    if (_blinkTimerId == timerId) {
        _targetImage.isVisible() ? _targetImage.hide() : _targetImage.show();
    } else {
        std::cerr << "ChessBoard::onTimeout() received unsupported timerId." << std::endl;
    }
}

// Corresponding header
#include "game/chess_pieces/PieceHandler.h"

// C++ system includes
#include <iostream>

// Own includes
#include "sdl_utils/InputEvent.h"
#include "game/utility/BoardUtils.h"
#include "game/proxies/GameBoardProxy.h"
#include "game/proxies/GameProxy.h"
#include "utils/error/HandleError.h"

int32_t PieceHandler::init(GameBoardProxy* gameBoardProxy, GameProxy* gameProxy,
                           int32_t whitePiecesResourceId, int32_t blackPiecesResourceId,
                           int32_t unfinishedPieceFontId) {
    if (gameBoardProxy == nullptr) {
        std::cerr << "In PieceHandler::init() nullptr provided for GameBoardProxy." << std::endl;
        return EXIT_FAILURE;
    }
    _gameBoardProxy = gameBoardProxy;

    if (gameProxy == nullptr) {
        std::cerr << "In PieceHandler::init() nullptr provided for GameProxy." << std::endl;
        return EXIT_FAILURE;
    }
    _gameProxy = gameProxy;

    handleError(PieceHandlerPopulator::populate(gameProxy, whitePiecesResourceId,
                                                blackPiecesResourceId, unfinishedPieceFontId,
                                                _piecesArr));

    return EXIT_SUCCESS;
}

void PieceHandler::draw() {
    for (auto& playerPieces : _piecesArr) {
        for (auto& piece : playerPieces) {
            piece->draw();
        }
    }
}

void PieceHandler::handleEvent(const InputEvent& event) {
    _isPieceSelected ? handleSelectedPieceEvent(event) : handleReleasedPieceEvent(event);
}

void PieceHandler::handleSelectedPieceEvent(const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::TOUCH_RELEASE) {
        return;
    }

    if (!BoardUtils::isInsideBoard(event.pointPos)) {
        return;
    }

    const BoardPosition boardPos = BoardUtils::getBoardPos(event.pointPos);
    if (!_gameBoardProxy->isMoveAllowed(boardPos)) {
        return;
    }

    _isPieceSelected = false;

    movePiece(boardPos);
}

void PieceHandler::setCurrentPlayerId(const int32_t currPlayerId) { _currPlayerId = currPlayerId; }

void PieceHandler::promotePiece([[maybe_unused]] PieceType pieceType) {}

void PieceHandler::setWidgetFlipType(WidgetFlip flipType) {
    for (auto& playerPieces : _piecesArr) {
        for (auto& piece : playerPieces) {
            piece->setWidgetFlipType(flipType);
        }
    }
}

void PieceHandler::handleReleasedPieceEvent(const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::TOUCH_RELEASE) {
        return;
    }

    int32_t pieceCounter = 0;
    for (const auto& playerPieces : _piecesArr[_currPlayerId]) {
        if (playerPieces->containsEvent(event)) {
            _selectedPieceId = pieceCounter;
            _isPieceSelected = true;

            const auto moveTile =
                _piecesArr[_currPlayerId][_selectedPieceId]->getMoveTiles(_piecesArr);

            _gameBoardProxy->onPieceSelected(BoardUtils::getBoardPos(event.pointPos), moveTile);

            return;
        }
        ++pieceCounter;
    }
}

void PieceHandler::movePiece(const BoardPosition& boardPos) {
    _piecesArr[_currPlayerId][_selectedPieceId]->setBoardPos(boardPos);
    const auto opponentId =
        BoardUtils::getOpponentId(_piecesArr[_currPlayerId][_selectedPieceId]->getPlayerId());

    int32_t collisionIdx = -1;
    if (BoardUtils::checkCollision(boardPos, _piecesArr[opponentId], collisionIdx)) {
        _piecesArr[opponentId].erase(_piecesArr[opponentId].begin() + collisionIdx);
    }

    _gameBoardProxy->onPieceReleased();
    _gameProxy->onGameTurnFinished();
}

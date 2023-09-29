// Corresponding header
#include "game/chess_pieces/PieceHandler.h"

// C++ system includes
#include <iostream>

// Own includes
#include "sdl_utils/InputEvent.h"
#include "game/utility/BoardUtils.h"
#include "game/proxies/GameBoardProxy.h"
#include "utils/error/HandleError.h"

int32_t PieceHandler::init(GameBoardProxy* gameBoardProxy, int32_t whitePiecesResourceId,
                           int32_t blackPiecesResourceId, int32_t unfinishedPieceFontId) {
    if (gameBoardProxy == nullptr) {
        std::cerr << "In PieceHandler::init() nullptr provided for GameBoardProxy." << std::endl;
        return EXIT_FAILURE;
    }

    handleError(PieceHandlerPopulator::populate(
        whitePiecesResourceId, blackPiecesResourceId, unfinishedPieceFontId, _piecesArr));

    _gameBoardProxy = gameBoardProxy;

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

void PieceHandler::handleReleasedPieceEvent(const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::TOUCH_RELEASE) {
        return;
    }

    int32_t currPlayerId = WHITE_PLAYER_ID;
    for (const auto& playerPieces : _piecesArr) {
        for (size_t i = 0; i < playerPieces.size(); i++) {
            if (playerPieces[i]->containsEvent(event)) {
                _selectedPieceId = (int32_t)i;
                _selectedPiecePlayerId = currPlayerId;

                _isPieceSelected = true;

                const auto moveTile =
                    _piecesArr[_selectedPiecePlayerId][_selectedPieceId]->getMoveTiles(_piecesArr);

                _gameBoardProxy->onPieceSelected(BoardUtils::getBoardPos(event.pointPos), moveTile);

                return;
            }
        }

        currPlayerId++;
    }
}

void PieceHandler::movePiece(const BoardPosition& boardPos) {
    _piecesArr[_selectedPiecePlayerId][_selectedPieceId]->setBoardPos(boardPos);
    const auto opponentId = BoardUtils::getOpponentId(
        _piecesArr[_selectedPiecePlayerId][_selectedPieceId]->getPlayerId());

    int32_t collisionIdx = -1;
    if (BoardUtils::checkCollision(boardPos, _piecesArr[opponentId], collisionIdx)) {
        _piecesArr[opponentId].erase(_piecesArr[opponentId].begin() + collisionIdx);
    }

    _gameBoardProxy->onPieceReleased();
}

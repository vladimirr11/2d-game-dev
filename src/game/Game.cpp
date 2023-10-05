// Corresponding header
#include "game/Game.h"

// C++ system includes
#include <iostream>

// Own includes
#include "sdl_utils/InputEvent.h"
#include "game/chess_defines/ChessDefines.h"
#include "utils/error/HandleError.h"

int32_t Game::init(const GameConfig& gameCfg) {
    handleError(_chessBoard.init(gameCfg.chessBoardId, gameCfg.targetId,
                                 gameCfg.moveTilesResourceId, gameCfg.blinkTargetTimerId));

    handleError(_pieceHandler.init(static_cast<GameBoardProxy*>(&_chessBoard), this,
                                   gameCfg.whitePiecesId, gameCfg.blackPiecesId,
                                   gameCfg.unfinishedPieceFontId));

    handleError(_piecePromotionPanel.init(gameCfg.piecePromotionPanelConfig, this));

    return EXIT_SUCCESS;
}

void Game::deinit() {}

void Game::draw() {
    _chessBoard.draw();
    _pieceHandler.draw();
    _piecePromotionPanel.draw();
}

void Game::handleEvent(InputEvent& event) {
    if (_piecePromotionPanel.isActive()) {
        _piecePromotionPanel.handleEvent(event);
        return;
    }

    _pieceHandler.handleEvent(event);
}

void Game::onGameTurnFinished() {
    _gameLogic.finishTurn();
    _pieceHandler.setCurrentPlayerId(_gameLogic.getActivePlayerId());
}

void Game::onPawnPromotion() { _piecePromotionPanel.activate(_gameLogic.getActivePlayerId()); }

void Game::promotePieceType(PieceType pieceType) {
    std::cout << "Recieved piece promotion for piece type " << static_cast<int32_t>(pieceType)
              << std::endl;

    // TODO finish implementation of promotePiece()
    _pieceHandler.promotePiece(pieceType);
}

// void Game::setWidgetFlipType([[maybe_unused]] WidgetFlip flipType) {
//     // _inputInverter.setBoardFlipType(flipType);
// }
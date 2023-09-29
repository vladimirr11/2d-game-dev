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

    handleError(_pieceHandler.init(static_cast<GameBoardProxy*>(&_chessBoard),
                                   gameCfg.whitePiecesId, gameCfg.blackPiecesId,
                                   gameCfg.unfinishedPieceFontId));
    return EXIT_SUCCESS;
}

void Game::deinit() {}

void Game::draw() {
    _chessBoard.draw();
    _pieceHandler.draw();
}

void Game::handleEvent(const InputEvent& event) { _pieceHandler.handleEvent(event); }

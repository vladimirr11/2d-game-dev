#ifndef GAME_H
#define GAME_H

// Own includes
#include "game/config/GameConfig.h"
#include "game/board/ChessBoard.h"
#include "game/chess_pieces/types/ChessPiece.h"
#include "game/chess_pieces/PieceHandler.h"
#include "manager_utils/drawing/Image.h"

// Forward declarations
struct InputEvent;

class Game {
public:
    int32_t init(const GameConfig& gameCfg);
    void deinit();
    void draw();
    void handleEvent(const InputEvent& event);

private:
    ChessBoard _chessBoard;
    PieceHandler _pieceHandler;
};

#endif  // !GAME_H

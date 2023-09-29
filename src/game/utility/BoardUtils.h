#ifndef BOARDUTILS_H
#define BOARDUTILS_H

// Own includes
#include "game/utility/BoardPos.h"
#include "utils/drawing/Point.h"
#include "game/chess_pieces/types/ChessPiece.h"

struct BoardUtils {
    static BoardPosition getBoardPos(const Point& absPos);
    static Point getAbsPos(const BoardPosition& boardPos);

    static bool isInsideBoard(const BoardPosition& boardPos);
    static bool isInsideBoard(const Point& absPos);

    static int32_t getOpponentId(const int32_t activePlayerId);

    static BoardPosition getAdjacentPos(const Direction dir, const BoardPosition& currPos);

    static bool checkCollision(const BoardPosition& selectedPos,
                               const ChessPiece::PlayerPiecesVec& pieces,
                               int32_t& outCollisionRelativeId);

    static TileType getTileType(const BoardPosition& boardPos,
                                const ChessPiece::PlayerPiecesVec& playerPieces,
                                const ChessPiece::PlayerPiecesVec& enemyPieces);
};

#endif  // !BOARDUTILS_H

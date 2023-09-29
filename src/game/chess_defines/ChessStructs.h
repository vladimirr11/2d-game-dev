#ifndef CHESSSTRUCTS_H
#define CHESSSTRUCTS_H

// C++ system includes
#include <cstdint>
#include <vector>

// Own includes
#include "game/chess_defines/ChessDefines.h"
#include "game/utility/BoardPos.h"

struct TileData {
    BoardPosition boardPos;
    TileType tileType = TileType::MOVE;
};

using MoveDirectionVec = std::vector<BoardPosition>;

#endif  // !CHESSSTRUCTS_H

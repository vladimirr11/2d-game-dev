#ifndef PAWN_H
#define PAWN_H

// C++ system includes
#include <unordered_map>

// Own includes
#include "game/chess_pieces/types/ChessPiece.h"

class Pawn : public ChessPiece {
public:
    std::vector<TileData> getMoveTiles(const PlayersActivePieces& activePieces) const final;

private:
    std::unordered_map<Direction, MoveDirectionVec> getWhitePlayerBoardMoves() const;
    std::unordered_map<Direction, MoveDirectionVec> getBlackPlayerBoardMoves() const;

    std::vector<TileData> getWhitePlayerMoveTiles(const PlayersActivePieces& activePieces) const;
    std::vector<TileData> getBlackPlayerMoveTiles(const PlayersActivePieces& activePieces) const;
};

#endif  // !PAWN_H

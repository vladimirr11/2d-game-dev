#ifndef ROOK_H
#define ROOK_H

// Own includes
#include "game/chess_pieces/types/ChessPiece.h"

class Rook : public ChessPiece {
public:
    std::vector<TileData> getMoveTiles(const PlayersActivePieces& activePieces) const final;

private:
    std::vector<MoveDirectionVec> getBoardMoves() const;
};

#endif  // !ROOK_H

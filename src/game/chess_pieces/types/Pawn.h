#ifndef PAWN_H
#define PAWN_H

// C++ system includes
#include <unordered_map>

// Own includes
#include "game/chess_pieces/types/ChessPiece.h"

// Forward declarations
struct GameProxy;

class Pawn : public ChessPiece {
public:
    Pawn(GameProxy* gameProxy);

    std::vector<TileData> getMoveTiles(const PlayersActivePieces& activePieces) const final;

    void setBoardPos(const BoardPosition& boardPos) final;

private:
    std::unordered_map<Direction, MoveDirectionVec> getWhitePlayerBoardMoves() const;
    std::unordered_map<Direction, MoveDirectionVec> getBlackPlayerBoardMoves() const;

    std::vector<TileData> getWhitePlayerMoveTiles(const PlayersActivePieces& activePieces) const;
    std::vector<TileData> getBlackPlayerMoveTiles(const PlayersActivePieces& activePieces) const;

private:
    GameProxy* _gameProxy = nullptr;
};

#endif  // !PAWN_H

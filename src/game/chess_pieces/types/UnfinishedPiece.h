#ifndef UNFINISHEDPIECE_H
#define UNFINISHEDPIECE_H

// C++ system includes
#include <vector>

// Own includes
#include "game/chess_pieces/types/ChessPiece.h"
#include "manager_utils/drawing/Text.h"

class UnfinishedPiece : public ChessPiece {
public:
    int32_t init(const ChessPieceConfig& chessPieceCfg) final;
    void draw() final;
    void setBoardPos(const BoardPosition& boardPos) final;
    std::vector<TileData> getMoveTiles(const PlayersActivePieces& activePieces) const final;

private:
    Text _notReadyText;
};

#endif  // !UNFINISHEDPIECE_H

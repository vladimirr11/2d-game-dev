#ifndef PIECEHANDLERPOPULATOR_H
#define PIECEHANDLERPOPULATOR_H

// Own includes
#include "game/chess_defines/ChessDefines.h"
#include "game/chess_pieces/types/ChessPiece.h"

class PieceHandlerPopulator {
public:
    PieceHandlerPopulator() = delete;

    ~PieceHandlerPopulator() = default;

    static int32_t populate(const int32_t whitePiecesResId, const int32_t blackPiecesResId,
                            const int32_t unfinishedPieceFontId,
                            std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT>& outPiecesArr);
};

#endif  // !PIECEHANDLERPOPULATOR_H

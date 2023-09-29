#ifndef PIECEHANDLER_H
#define PIECEHANDLER_H

// C++ system includes
#include <cstdint>
#include <array>
#include <vector>

// Own includes
#include "game/chess_defines/ChessDefines.h"
#include "game/chess_pieces/types/ChessPiece.h"
#include "game/chess_pieces/PieceHandlerPopulator.h"

// Forward declarations
struct GameBoardProxy;

class PieceHandler {
public:
    int32_t init(GameBoardProxy* gameBoardProxy, int32_t whitePiecesResourceId,
                 int32_t blackPiecesResourceId, int32_t unfinishedPieceFontId);
    void draw();
    void handleEvent(const InputEvent& event);

private:
    void handleSelectedPieceEvent(const InputEvent& event);
    void handleReleasedPieceEvent(const InputEvent& event);
    void movePiece(const BoardPosition& boardPos);

private:
    std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT> _piecesArr;
    int32_t _selectedPieceId = 0;
    int32_t _selectedPiecePlayerId = 0;
    bool _isPieceSelected = false;
    GameBoardProxy* _gameBoardProxy;
};

#endif  // !PIECEHANDLER_H

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
#include "game/proxies/GameProxy.h"

// Forward declarations
struct InputEvent;
struct GameBoardProxy;
struct GameProxy;

class PieceHandler {
public:
    int32_t init(GameBoardProxy* gameBoardProxy, GameProxy* gameProxy,
                 int32_t whitePiecesResourceId, int32_t blackPiecesResourceId,
                 int32_t unfinishedPieceFontId);
    void draw();
    void handleEvent(const InputEvent& event);

    void setCurrentPlayerId(const int32_t currPlayerId);

    void promotePiece(PieceType pieceType);

    void setWidgetFlipType(WidgetFlip flipType);

private:
    void handleSelectedPieceEvent(const InputEvent& event);
    void handleReleasedPieceEvent(const InputEvent& event);
    void movePiece(const BoardPosition& boardPos);

private:
    std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT> _piecesArr;
    int32_t _selectedPieceId = 0;
    int32_t _currPlayerId = 0;
    bool _isPieceSelected = false;
    GameBoardProxy* _gameBoardProxy = nullptr;
    GameProxy* _gameProxy = nullptr;
};

#endif  // !PIECEHANDLER_H

#ifndef CHESSPIECE_H
#define CHESSPIECE_H

// C++ system includes
#include <array>
#include <vector>
#include <memory>

// Own includes
#include "manager_utils/drawing/Image.h"
#include "game/chess_defines/ChessDefines.h"
#include "game/chess_defines/ChessStructs.h"
#include "game/utility/BoardPos.h"

// Forward declarations
struct InputEvent;

struct ChessPieceConfig {
    BoardPosition boardPos{};
    int32_t playerId{};
    int32_t chessPieceResourceId = INVALID_RESOURCE_ID;
    PieceType pieceType = PieceType::UNKNOWN;
    int32_t unfinishedPieceFontId{};
};

class ChessPiece {
public:
    using PlayerPiecesVec = std::vector<std::unique_ptr<ChessPiece>>;

protected:
    using PlayersActivePieces = std::array<PlayerPiecesVec, PLAYERS_COUNT>;

public:
    virtual ~ChessPiece() = default;

    virtual int32_t init(const ChessPieceConfig& chessPieceCfg);

    virtual void draw();

    virtual void setBoardPos(const BoardPosition& boardPos);

    virtual std::vector<TileData> getMoveTiles(const PlayersActivePieces& activePieces) const = 0;

    bool containsEvent(const InputEvent& event) const;

    BoardPosition getBoardPos() const;

    int32_t getPlayerId() const;

    void setWidgetFlipType(WidgetFlip flipType);

protected:
    Image _pieceImg;
    BoardPosition _boardPos;
    int32_t _playerId;
    PieceType _pieceType;
};

#endif  // !CHESSPIECE_H

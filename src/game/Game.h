#ifndef GAME_H
#define GAME_H

// Own includes
#include "game/config/GameConfig.h"
#include "game/board/ChessBoard.h"
#include "game/chess_pieces/types/ChessPiece.h"
#include "game/chess_pieces/PieceHandler.h"
#include "manager_utils/drawing/Image.h"
#include "game/logic/GameLogic.h"
#include "game/proxies/GameProxy.h"
#include "game/panels/PiecePromotionPanel.h"

// Forward declarations
struct InputEvent;

class Game : public GameProxy {
public:
    int32_t init(const GameConfig& gameCfg);
    void deinit();
    void draw();
    void handleEvent(InputEvent& event);

private:
    void onGameTurnFinished() final;
    void onPawnPromotion() final;
    void promotePieceType(PieceType pieceType) final;
    // void setWidgetFlipType(WidgetFlip flipType) final;

private:
    ChessBoard _chessBoard;
    PieceHandler _pieceHandler;
    GameLogic _gameLogic;
    PiecePromotionPanel _piecePromotionPanel;
};

#endif  // !GAME_H

#ifndef GAMEPROXY_H
#define GAMEPROXY_H

// Own headers
#include "game/chess_defines/ChessDefines.h"

class GameProxy {
public:
    virtual ~GameProxy() = default;

    virtual void onGameTurnFinished() = 0;
    virtual void onPawnPromotion() = 0;
    virtual void promotePieceType(PieceType pieceType) = 0;
    virtual void setWidgetFlipType(WidgetFlip flipType) = 0;
};

#endif  // !GAMEPROXY_H

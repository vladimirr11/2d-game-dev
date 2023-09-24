#ifndef GAMEBOARDPROXY_H
#define GAMEBOARDPROXY_H

// Own includes
#include "game/utility/BoardPos.h"

class GameBoardProxy {
public:
    virtual ~GameBoardProxy() = default;
    virtual void onPieceSelected(const BoardPosition& boardPos) = 0;
    virtual void onPieceReleased() = 0;
};

#endif  // !GAMEBOARDPROXY_H

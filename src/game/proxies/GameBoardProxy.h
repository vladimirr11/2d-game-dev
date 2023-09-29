#ifndef GAMEBOARDPROXY_H
#define GAMEBOARDPROXY_H

// C++ system includes
#include <cstdint>
#include <vector>

// Own includes
#include "game/utility/BoardPos.h"
#include "game/chess_defines/ChessStructs.h"

class GameBoardProxy {
public:
    virtual ~GameBoardProxy() = default;

    virtual void onPieceSelected(const BoardPosition& boardPos,
                                 const std::vector<TileData>& moveTiles) = 0;

    virtual void onPieceReleased() = 0;
 
    virtual bool isMoveAllowed(const BoardPosition& pos) const = 0;
};

#endif  // !GAMEBOARDPROXY_H

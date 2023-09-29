#ifndef MOVESELECTOR_H
#define MOVESELECTOR_H

// C++ system includes
#include <cstdint>
#include <array>

// Own includes
#include "game/chess_defines/ChessStructs.h"
#include "manager_utils/drawing/Image.h"

class MoveSelector {
public:
    int32_t init(const int32_t resourceId);
    void draw();
    void markTiles(const std::vector<TileData>& markedTiles);
    void unmarkTiles();

public:
    enum InternalDefines { MAX_ACTIVE_TILES = 28 };
    std::array<Image, MAX_ACTIVE_TILES> _tileImages;
    size_t _activeTiles{0};
};

#endif  // !MOVESELECTOR_H

// Corresponding header
#include "game/board/MoveSelector.h"

// C++ system includes
#include <iostream>

// Own includes
#include "game/utility/BoardUtils.h"

int32_t MoveSelector::init(int32_t resourceId) {
    for (auto& image : _tileImages) {
        image.create(resourceId);
    }

    return EXIT_SUCCESS;
}

void MoveSelector::draw() {
    for (size_t i = 0; i < _activeTiles; i++) {
        _tileImages[i].draw();
    }
}

void MoveSelector::markTiles(const std::vector<TileData>& markedTiles) {
    _activeTiles = markedTiles.size();
    
    for (size_t i = 0; i < _activeTiles; i++) {
        _tileImages[i].setPosition(BoardUtils::getAbsPos(markedTiles[i].boardPos));
        _tileImages[i].setFrame(static_cast<int32_t>(markedTiles[i].tileType));
    }
}

void MoveSelector::unmarkTiles() { _activeTiles = 0; }

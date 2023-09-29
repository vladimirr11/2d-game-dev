// Corresponding header
#include "game/chess_pieces/types/UnfinishedPiece.h"

// C++ system includes
#include <iostream>
#include <array>

// Own includes
#include "game/utility/BoardUtils.h"
#include "utils/error/HandleError.h"

int32_t UnfinishedPiece::init(const ChessPieceConfig& chessPieceCfg) {
    handleError(ChessPiece::init(chessPieceCfg));

    const auto pieceAbsPos = BoardUtils::getAbsPos(_boardPos);
    _notReadyText.create("!", chessPieceCfg.unfinishedPieceFontId, Colors::RED, pieceAbsPos);

    return EXIT_SUCCESS;
}

void UnfinishedPiece::draw() {
    ChessPiece::draw();
    _notReadyText.draw();
}

void UnfinishedPiece::setBoardPos(const BoardPosition& boardPos) {
    ChessPiece::setBoardPos(boardPos);
    const auto pieceAbsPos = BoardUtils::getAbsPos(_boardPos);
    _notReadyText.setPosition(pieceAbsPos);
}

std::vector<TileData> UnfinishedPiece::getMoveTiles(
    [[maybe_unused]] const PlayersActivePieces& activePieces) const {
    return std::vector<TileData>{};
}

// Corresponding header
#include "game/chess_pieces/types/Rook.h"

// C++ system includes
#include <iostream>

// Own includes
#include "game/utility/BoardUtils.h"

std::vector<TileData> Rook::getMoveTiles(const PlayersActivePieces& activePieces) const {
    std::vector<TileData> rookMoveTiles;

    const int32_t opponentId = BoardUtils::getOpponentId(_playerId);

    const std::vector<MoveDirectionVec> boardMoves = getBoardMoves();
    for (const auto& moveDir : boardMoves) {
        if (moveDir.empty()) {
            continue;
        }

        for (const auto& boardPos : moveDir) {
            const TileType tileType = BoardUtils::getTileType(boardPos, activePieces[_playerId],
                                                              activePieces[opponentId]);
            TileData tileData;
            tileData.boardPos = boardPos;
            tileData.tileType = tileType;

            rookMoveTiles.push_back(tileData);

            if (tileType != TileType::MOVE) {
                break;
            }
        }
    }

    return rookMoveTiles;
}

std::vector<MoveDirectionVec> Rook::getBoardMoves() const {
    constexpr auto allowedDirs = 4;
    constexpr std::array<Direction, allowedDirs> rookDirs{UP, RIGHT, DOWN, LEFT};

    constexpr int32_t maxRookMoves = 7;
    std::vector<MoveDirectionVec> boardMoves(allowedDirs);

    BoardPosition futurePos;
    for (int32_t dirIdx = 0; dirIdx < allowedDirs; dirIdx++) {
        boardMoves[dirIdx].reserve(maxRookMoves);
        futurePos = _boardPos;
        futurePos = BoardUtils::getAdjacentPos(rookDirs[dirIdx], futurePos);
        while (BoardUtils::isInsideBoard(futurePos)) {
            boardMoves[dirIdx].push_back(futurePos);
            futurePos = BoardUtils::getAdjacentPos(rookDirs[dirIdx], futurePos);
        }
    }

    return boardMoves;
}

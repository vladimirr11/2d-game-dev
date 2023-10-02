// Corresponding header
#include "game/chess_pieces/types/Pawn.h"

// C++ system includes
#include <iostream>

// Own includes
#include "game/utility/BoardUtils.h"
#include "game/proxies/GameProxy.h"

Pawn::Pawn(GameProxy* gameProxy) : _gameProxy(gameProxy) {}

std::vector<TileData> Pawn::getMoveTiles(const PlayersActivePieces& activePieces) const {
    if (_playerId == WHITE_PLAYER_ID) {
        return getWhitePlayerMoveTiles(activePieces);
    }

    return getBlackPlayerMoveTiles(activePieces);
}

void Pawn::setBoardPos(const BoardPosition& boardPos) {
    ChessPiece::setBoardPos(boardPos);

    if (_playerId == WHITE_PLAYER_ID && _boardPos.boardRow == WHITE_PLAYER_END_PAWN_ROW)
        _gameProxy->onPawnPromotion();
    else if (_playerId == BLACK_PLAYER_ID && _boardPos.boardRow == BLACK_PLAYER_END_PAWN_ROW)
        _gameProxy->onPawnPromotion();
}

std::unordered_map<Direction, MoveDirectionVec> Pawn::getWhitePlayerBoardMoves() const {
    // allowed move directions { UP_LEFT, UP, UP_RIGHT }
    std::unordered_map<Direction, MoveDirectionVec> wpBoardMovesMap;

    BoardPosition wpFuturePos = BoardUtils::getAdjacentPos(UP_LEFT, _boardPos);
    if (BoardUtils::isInsideBoard(wpFuturePos)) {
        wpBoardMovesMap[UP_LEFT].emplace_back(wpFuturePos);
    }

    wpFuturePos = BoardUtils::getAdjacentPos(UP_RIGHT, _boardPos);
    if (BoardUtils::isInsideBoard(wpFuturePos)) {
        wpBoardMovesMap[UP_RIGHT].emplace_back(wpFuturePos);
    }

    wpFuturePos = BoardUtils::getAdjacentPos(UP, _boardPos);
    wpBoardMovesMap[UP].emplace_back(wpFuturePos);

    // do the double pawn move
    if (WHITE_PLAYER_START_PAWN_ROW == _boardPos.boardRow) {
        wpFuturePos = BoardUtils::getAdjacentPos(UP, wpFuturePos);
        wpBoardMovesMap[UP].emplace_back(wpFuturePos);
    }

    return wpBoardMovesMap;
}

std::unordered_map<Direction, MoveDirectionVec> Pawn::getBlackPlayerBoardMoves() const {
    // allowed move directions { DOWN_LEFT, DOWN, DOWN_RIGHT }
    std::unordered_map<Direction, MoveDirectionVec> bpBoardMovesMap;

    BoardPosition bpFuturePos = BoardUtils::getAdjacentPos(DOWN_LEFT, _boardPos);
    if (BoardUtils::isInsideBoard(bpFuturePos)) {
        bpBoardMovesMap[DOWN_LEFT].emplace_back(bpFuturePos);
    }

    bpFuturePos = BoardUtils::getAdjacentPos(DOWN_RIGHT, _boardPos);
    if (BoardUtils::isInsideBoard(bpFuturePos)) {
        bpBoardMovesMap[DOWN_RIGHT].emplace_back(bpFuturePos);
    }

    bpFuturePos = BoardUtils::getAdjacentPos(DOWN, _boardPos);
    bpBoardMovesMap[DOWN].emplace_back(bpFuturePos);

    // do the double pawn move
    if (BLACK_PLAYER_START_PAWN_ROW == _boardPos.boardRow) {
        bpFuturePos = BoardUtils::getAdjacentPos(DOWN, bpFuturePos);
        bpBoardMovesMap[DOWN].emplace_back(bpFuturePos);
    }

    return bpBoardMovesMap;
}

std::vector<TileData> Pawn::getWhitePlayerMoveTiles(const PlayersActivePieces& activePieces) const {
    const std::unordered_map<Direction, MoveDirectionVec> wpBoardMovesMap =
        getWhitePlayerBoardMoves();

    std::vector<TileData> moveTiles;
    moveTiles.reserve(wpBoardMovesMap.size());

    const int32_t opponentId = BoardUtils::getOpponentId(_playerId);

    auto it = wpBoardMovesMap.find(UP);
    if (it != wpBoardMovesMap.end()) {
        for (const auto& pos : it->second) {
            const auto tileType =
                BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);
            // if first possible move is TAKE or GUARD - second move will be impossible
            if (tileType != TileType::MOVE) {
                break;
            }

            TileData tileData;
            tileData.boardPos = pos;
            tileData.tileType = tileType;

            moveTiles.push_back(tileData);
        }
    }

    constexpr auto diagonalMovesCnt = 2;
    const std::array<Direction, diagonalMovesCnt> diagonalMoves{UP_LEFT, UP_RIGHT};

    for (const Direction move : diagonalMoves) {
        it = wpBoardMovesMap.find(move);
        if (it != wpBoardMovesMap.end()) {
            for (const auto& pos : it->second) {
                const auto tileType =
                    BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);
                if (tileType != TileType::MOVE) {
                    TileData tileData;
                    tileData.boardPos = pos;
                    tileData.tileType = tileType;

                    moveTiles.push_back(tileData);
                }
            }
        }
    }

    return moveTiles;
}

std::vector<TileData> Pawn::getBlackPlayerMoveTiles(const PlayersActivePieces& activePieces) const {
    const std::unordered_map<Direction, MoveDirectionVec> bpBoardMovesMap =
        getBlackPlayerBoardMoves();

    std::vector<TileData> moveTiles;
    moveTiles.reserve(bpBoardMovesMap.size());

    const int32_t opponentId = BoardUtils::getOpponentId(_playerId);

    std::unordered_map<Direction, MoveDirectionVec>::const_iterator it = bpBoardMovesMap.find(DOWN);
    if (it != bpBoardMovesMap.end()) {
        for (const auto& pos : it->second) {
            const auto tileType =
                BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);
            // if first possible move is TAKE or GUARD - second move will be impossible
            if (tileType != TileType::MOVE) {
                break;
            }

            TileData tileData;
            tileData.boardPos = pos;
            tileData.tileType = tileType;

            moveTiles.push_back(tileData);
        }
    }

    constexpr auto diagonalMovesCnt = 2;
    const std::array<Direction, diagonalMovesCnt> diagonalMoves{DOWN_LEFT, DOWN_RIGHT};

    for (const Direction move : diagonalMoves) {
        it = bpBoardMovesMap.find(move);
        if (it != bpBoardMovesMap.end()) {
            for (const auto& pos : it->second) {
                const auto tileType =
                    BoardUtils::getTileType(pos, activePieces[_playerId], activePieces[opponentId]);
                if (tileType != TileType::MOVE) {
                    TileData tileData;
                    tileData.boardPos = pos;
                    tileData.tileType = tileType;

                    moveTiles.push_back(tileData);
                }
            }
        }
    }

    return moveTiles;
}

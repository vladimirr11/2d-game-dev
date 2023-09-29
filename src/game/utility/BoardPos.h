#ifndef BOARDPOS_H
#define BOARDPOS_H

// C++ system includes
#include <cstdint>

struct BoardPosition {
    BoardPosition() = default;

    BoardPosition(int32_t inputRow, int32_t inputCol) : boardRow(inputRow), boardCol(inputCol) {}

    bool operator==(const BoardPosition& other) const {
        return boardRow == other.boardRow && boardCol == other.boardCol;
    }

    bool operator!=(const BoardPosition& other) const { return !operator==(other); }

    int32_t boardRow{};
    int32_t boardCol{};
};

#endif  // !BOARDPOS_H

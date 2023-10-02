#ifndef PIECEPROMOTIONBUTTONCFG_H
#define PIECEPROMOTIONBUTTONCFG_H

// C++ system includes
#include <cstdint>
#include <functional>

// Own includes
#include "game/chess_defines/ChessDefines.h"
#include "utils/drawing/Point.h"

struct PiecePromotionButtonConfig {
    std::function<void(PieceType)> onButtonClickedCallback;  // capture the method by lambda
    Point backgrPos;
    int32_t buttonBackgrId;
    int32_t buttonWhitePieceResId;
    int32_t buttonBlackPieceResId;
    int32_t backgrWidth = 0;
    int32_t backgrHeight = 0;
    int32_t width = 0;
    int32_t height = 0;
    PieceType pieceType;
};

#endif  // !PIECEPROMOTIONBUTTONCFG_H

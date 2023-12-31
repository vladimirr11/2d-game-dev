#ifndef GAMECONFIG_H
#define GAMECONFIG_H

// C++ system includes
#include <cstdint>

// Own includes
#include "game/panels/config/PiecePromotionPanelCfg.h"

struct GameConfig {
    PiecePromotionPanelConfig piecePromotionPanelConfig;
    int32_t whitePiecesId;
    int32_t blackPiecesId;
    int32_t chessBoardId;
    int32_t targetId;
    int32_t moveTilesResourceId;
    int32_t unfinishedPieceFontId;
    int32_t blinkTargetTimerId;
};

#endif  // !GAMECONFIG_H

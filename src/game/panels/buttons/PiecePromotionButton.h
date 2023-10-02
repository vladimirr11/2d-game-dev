#ifndef PIECEPROMOTIONBUTTON_H
#define PIECEPROMOTIONBUTTON_H

// C++ system includes
#include <cstdint>

// Own includes
#include "manager_utils/input/ButtonBase.h"
#include "game/panels/config/PiecePromotionButtonCfg.h"

// Forward declarations
struct InputEvent;

class PiecePromotionButton : public ButtonBase {
public:
    int32_t init(const PiecePromotionButtonConfig& cfg);
    void draw() final;
    void handleEvent(const InputEvent& event) final;
    void activate(const int32_t activePlayerId);

private:
    Image _backgrImage;
    PiecePromotionButtonConfig _cfg;
};

#endif  // !PIECEPROMOTIONBUTTON_H

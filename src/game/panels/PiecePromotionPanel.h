#ifndef PIECEPROMOTIONPANEL_H
#define PIECEPROMOTIONPANEL_H

// C++ system includes
#include <cstdint>
#include <array>

// Own includes
#include "game/panels/buttons/PiecePromotionButton.h"
#include "game/panels/config/PiecePromotionPanelCfg.h"

// Forward declarations
struct GameProxy;
struct InputEvent;

class PiecePromotionPanel {
public:
    int32_t init(const PiecePromotionPanelConfig& cfg, GameProxy* gameProxy);
    void handleEvent(const InputEvent& event);
    void draw();
    void activate(const int32_t playerId);
    bool isActive() const;

private:
    void onButtonClicked(PieceType pieceType);

private:
    enum InternalDefines { BUTTONS_COUNT = 4 };
    std::array<PiecePromotionButton, BUTTONS_COUNT> _promotionButtons;
    GameProxy* _gameProxy = nullptr;
    bool _isActive = false;
};

#endif  // !PIECEPROMOTIONPANEL_H

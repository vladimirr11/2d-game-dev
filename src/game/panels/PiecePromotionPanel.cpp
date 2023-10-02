// Corresponding header
#include "game/panels/PiecePromotionPanel.h"

// C++ system includes
#include <iostream>

// Own includes
#include "game/proxies/GameProxy.h"
#include "sdl_utils/InputEvent.h"
#include "utils/error/HandleError.h"

int32_t PiecePromotionPanel::init(const PiecePromotionPanelConfig& cfg, GameProxy* gameProxy) {
    if (gameProxy == nullptr) {
        std::cerr << "In PiecePromotionPanel::init() nullptr provided for GameProxy." << std::endl;
        return EXIT_FAILURE;
    }
    _gameProxy = gameProxy;

    PiecePromotionButtonConfig buttonConfig;
    buttonConfig.onButtonClickedCallback = [this](PieceType pieceType) {
        onButtonClicked(pieceType);
    };
    buttonConfig.buttonBackgrId = cfg.buttonBackgrResId;
    buttonConfig.buttonWhitePieceResId = cfg.whitePiecesResId;
    buttonConfig.buttonBlackPieceResId = cfg.blackPiecesResId;
    buttonConfig.backgrWidth = cfg.buttonBackgrWidth;
    buttonConfig.backgrHeight = cfg.buttonBackgrHeight;
    buttonConfig.width = cfg.buttonWidth;
    buttonConfig.height = cfg.buttonHeight;

    constexpr std::array<PieceType, BUTTONS_COUNT> pieceTypes{PieceType::QUEEN, PieceType::ROOK,
                                                              PieceType::BISHOP, PieceType::KNIGHT};

    constexpr int32_t buttonOffset = 50;
    const int32_t startX =
        (cfg.gameBoardWidth - (BUTTONS_COUNT * (cfg.buttonWidth + buttonOffset))) / 2;

    buttonConfig.backgrPos.y = (cfg.gameBoardHeight - cfg.buttonHeight) / 2;

    for (int32_t i = 0; i < BUTTONS_COUNT; ++i) {
        buttonConfig.pieceType = pieceTypes[i];
        buttonConfig.backgrPos.x = startX + (i * (cfg.buttonWidth + buttonOffset));
        handleError(_promotionButtons[i].init(buttonConfig));
    }

    return EXIT_SUCCESS;
}

void PiecePromotionPanel::handleEvent(const InputEvent& event) {
    for (auto& button : _promotionButtons) {
        if (button.isInputUnlocked() && button.containsEvent(event)) {
            button.handleEvent(event);
            break;
        }
    }
}

void PiecePromotionPanel::draw() {
    if (!_isActive)
        return;
    for (auto& button : _promotionButtons) button.draw();
}

void PiecePromotionPanel::activate(const int32_t playerId) {
    _isActive = true;
    for (auto& button : _promotionButtons) button.activate(playerId);
}

bool PiecePromotionPanel::isActive() const { return _isActive; }

void PiecePromotionPanel::onButtonClicked(PieceType pieceType) {
    _isActive = false;
    _gameProxy->promotePieceType(pieceType);
}
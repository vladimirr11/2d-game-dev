// Corresponding header
#include "game/panels/buttons/PiecePromotionButton.h"

// Own includes
#include "sdl_utils/InputEvent.h"

int32_t PiecePromotionButton::init(const PiecePromotionButtonConfig& cfg) {
    _cfg = cfg;
    _backgrImage.create(cfg.buttonBackgrId, cfg.backgrPos);

    return EXIT_SUCCESS;
}

void PiecePromotionButton::draw() {
    _backgrImage.draw();
    ButtonBase::draw();
}

void PiecePromotionButton::handleEvent(const InputEvent& event) {
    if (event.typeTouchEvent == TouchEvent::TOUCH_PRESS) {
        _backgrImage.setFrame(CLICKED);
    } else if (event.typeTouchEvent == TouchEvent::TOUCH_RELEASE) {
        _backgrImage.setFrame(UNCLICKED);
        _cfg.onButtonClickedCallback(_cfg.pieceType);
    }
}

void PiecePromotionButton::activate(const int32_t activePlayerId) {
    const auto resId = (activePlayerId == WHITE_PLAYER_ID) ? _cfg.buttonWhitePieceResId
                                                           : _cfg.buttonBlackPieceResId;
    const int32_t xyDelta = (_backgrImage.getWidth() - _cfg.width) / 2;
    const Point buttonPos =
        Point(_backgrImage.getPosition().x + xyDelta, _backgrImage.getPosition().y + xyDelta);

    if (isCreated())
        ButtonBase::destroy();

    ButtonBase::create(resId, buttonPos);
    ButtonBase::setFrame(static_cast<int32_t>(_cfg.pieceType));
}

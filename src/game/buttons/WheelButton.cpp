// Corresponding header
#include "game/buttons/WheelButton.h"

// C++ system includes
#include <iostream>

// Own includes
#include "sdl_utils/InputEvent.h"
#include "game/proxies/GameProxy.h"

int32_t WheelButton::init(GameProxy* gameProxy, int32_t buttonId) {
    if (gameProxy == nullptr) {
        std::cerr << "nullptr provided for GameProxy in WheelButton::init()!" << std::endl;
        return EXIT_FAILURE;
    }

    _gameProxy = gameProxy;
    _buttonId = buttonId;

    return EXIT_SUCCESS;
}

void WheelButton::handleEvent(const InputEvent& event) {
    if (event.typeTouchEvent == TouchEvent::TOUCH_PRESS) {
        setFrame(CLICKED);
    } else if (event.typeTouchEvent == TouchEvent::TOUCH_RELEASE) {
        setFrame(UNCLICKED);
        _gameProxy->onButtonPressed(_buttonId);
    }
}

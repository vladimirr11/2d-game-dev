// Corresponding headers
#include "sdl_utils/InputEvent.h"

// C++ system includes
#include <cstring>
#include <iostream>

// Third-party includes
#include <SDL_events.h>

int32_t InputEvent::init() {
    _sdlEvent = new SDL_Event();
    memset(_sdlEvent, 0, sizeof(SDL_Event));

    if (!_sdlEvent) {
        std::cerr << "In InputEvent::init() - SDL_Event() failed to allocate memory." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void InputEvent::deinit() {
    if (_sdlEvent) {
        delete _sdlEvent;
        _sdlEvent = nullptr;
    }
}

bool InputEvent::pollEvent() {
    if (SDL_PollEvent(_sdlEvent) == 0) {  // no event
        return false;
    }

    SDL_GetMouseState(&pointPos.x, &pointPos.y);
    setEventTypeInternal();

    return true;
}

bool InputEvent::checkForExit() const {
    return (_sdlEvent->type == EventType::QUIT) ||
           (typeTouchEvent == TouchEvent::KEYBOARD_PRESS && key == Keyboard::KEY_ESCAPE);
}

void InputEvent::setEventTypeInternal() {
    switch (_sdlEvent->type) {
    case EventType::KEYBOARD_PRESS:
        key = _sdlEvent->key.keysym.sym;
        mouseButton = Mouse::UNKNOWN;
        typeTouchEvent = TouchEvent::KEYBOARD_PRESS;
        break;

    case EventType::KEYBOARD_RELEASE:
        key = _sdlEvent->key.keysym.sym;
        mouseButton = Mouse::UNKNOWN;
        typeTouchEvent = TouchEvent::KEYBOARD_RELEASE;
        break;

    case EventType::MOUSE_PRESS:
        key = Keyboard::KEY_UNKNOWN;
        mouseButton = _sdlEvent->button.button;
        typeTouchEvent = TouchEvent::TOUCH_PRESS;
        break;

    case EventType::FINGER_PRESS:
        key = Keyboard::KEY_UNKNOWN;
        mouseButton = _sdlEvent->button.button;
        typeTouchEvent = TouchEvent::TOUCH_PRESS;
        break;

    case EventType::MOUSE_RELEASE:
        key = Keyboard::KEY_UNKNOWN;
        mouseButton = _sdlEvent->button.button;
        typeTouchEvent = TouchEvent::TOUCH_RELEASE;
        break;

    case EventType::FINGER_RELEASE:
        key = Keyboard::KEY_UNKNOWN;
        mouseButton = Mouse::UNKNOWN;
        typeTouchEvent = TouchEvent::TOUCH_RELEASE;
        break;

    // X is pressed on the window (or CTRL-C signal is sent)
    case EventType::QUIT:
        key = Keyboard::KEY_UNKNOWN;
        mouseButton = Mouse::UNKNOWN;
        typeTouchEvent = TouchEvent::UNKNOWN;
        break;

    default:
        key = Keyboard::KEY_UNKNOWN;
        mouseButton = Mouse::UNKNOWN;
        typeTouchEvent = TouchEvent::UNKNOWN;
        break;
    }
}

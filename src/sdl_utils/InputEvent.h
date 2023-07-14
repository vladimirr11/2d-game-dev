#ifndef INPUTEVENT_H
#define INPUTEVENT_H

// C++ system includes
#include <cstdint>

// Own includes
#include "utils/drawing/Point.h"
#include "utils/input/EventDefines.h"

// Forward declarations
union SDL_Event;

class InputEvent {
public:
    int32_t init();

    void deinit();

    bool pollEvent();

    bool checkForExitRequest() const;

public:
    Point pointPos = Point::UNDEFINED;
    int32_t key = Keyboard::KEY_UNKNOWN;
    uint32_t mouseButton = Mouse::UNKNOWN;
    TouchEvent typeTouchEvent = TouchEvent::UNKNOWN;

private:
    void setEventTypeInternal();

private:
    SDL_Event* _sdlEvent = nullptr;
};

#endif  // !INPUTEVENT_H

#ifndef INPUTEVENT_H
#define INPUTEVENT_H

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
    bool checkForExit() const;

private:
    void setEventTypeInternal();

public:
    Point pointPos = Point::UNDEFINED;
    int32_t key = Keyboard::KEY_UNKNOWN;
    uint32_t mouseButton = Mouse::UNKNOWN;
    TouchEvent typeTouchEvent = TouchEvent::UNKNOWN;

private:
    SDL_Event* _sdlEvent = nullptr;
};

#endif  // !INPUTEVENT_H

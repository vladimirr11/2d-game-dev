// Corresponding header
#include "manager_utils/debug/DebugConsole.h"

// C++ system includes
#include <iostream>
#include <string>

// Own includes
#include "sdl_utils/InputEvent.h"

int32_t DebugConsole::init(const int64_t maxFrames, const int32_t fontId) {
    _maxFrames = maxFrames;

    Point textPos = Point(0, 40);
    _debugConsoleTexts[FPS_TEXT_IDX].create("0", fontId, Colors::GREEN, textPos);

    textPos.y += 40;
    _debugConsoleTexts[ACTIVE_TIMER_IDX].create("0", fontId, Colors::GREEN, textPos);

    textPos.y += 40;
    _debugConsoleTexts[ACTIVE_WIDGETS_IDX].create("0", fontId, Colors::GREEN, textPos);

    return EXIT_SUCCESS;
}

void DebugConsole::handleEvent(const InputEvent& event) {
    if (event.typeTouchEvent != TouchEvent::KEYBOARD_PRESS) {
        return;
    }

    if (event.key == Keyboard::KEY_A) {
        _isActive = !_isActive;
    }
}

void DebugConsole::update(const int64_t elapsedMicrosec, const size_t activeTimers) {
    constexpr int64_t microsecInSecond = 1'000'000;
    int64_t currFps = microsecInSecond / elapsedMicrosec;
    if (currFps > _maxFrames) {
        currFps = _maxFrames;
    }

    std::string textContent = "FPS: ";
    textContent.append(std::to_string(currFps));

    _debugConsoleTexts[FPS_TEXT_IDX].setText(textContent);

    textContent = "Active Timers: ";
    textContent.append(std::to_string(activeTimers));

    _debugConsoleTexts[ACTIVE_TIMER_IDX].setText(textContent);
}

void DebugConsole::draw() {
    for (int32_t i = 0; i < DEBUG_TEXTS_COUNTS; i++) {
        _debugConsoleTexts[i].draw();
    }
}

void DebugConsole::updateActiveWidgets(const int32_t activeWidgets) {
    std::string textContent = "Active Widgets: ";
    textContent.append(std::to_string(activeWidgets));
    _debugConsoleTexts[ACTIVE_WIDGETS_IDX].setText(textContent);
}

bool DebugConsole::isActive() const { return _isActive; }

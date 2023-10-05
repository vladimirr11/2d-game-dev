#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H

// Own includes
#include "manager_utils/drawing/Text.h"

// Forward declarations
class InputEvent;

enum DebugTextIds { FPS_TEXT_IDX, ACTIVE_TIMER_IDX, ACTIVE_WIDGETS_IDX, DEBUG_TEXTS_COUNTS };

class DebugConsole {
public:
    int32_t init(const int64_t maxFrames, const int32_t fontId);
    void handleEvent(const InputEvent& event);
    void update(const int64_t elapsedMicroseconds, const size_t activeTimers);
    void draw();
    void updateActiveWidgets(const int32_t activeWidgets);
    bool isActive() const;

private:
    Text _debugConsoleTexts[DEBUG_TEXTS_COUNTS];
    int64_t _maxFrames = 0;      // used to determine the current FPS
    int32_t _updateCounter = 0;  // used for skipping turns
    bool _isActive = false;
};

#endif  // !DEBUGCONSOLE_H

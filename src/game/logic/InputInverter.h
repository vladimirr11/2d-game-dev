#ifndef INPUTINVERTER_H
#define INPUTINVERTER_H

// Own components headers
#include "utils/drawing/DrawParams.h"

// Forward declarations
class InputEvent;

class InputInverter {
public:
    int32_t init(const int32_t boardWidth, const int32_t boardHeight);

    void setBoardFlipType(WidgetFlip flipType);

    void invertEvent(InputEvent& inputEvent);

private:
    int32_t _boardWidth{0};
    int32_t _boardHeight{0};
    WidgetFlip _flipType = WidgetFlip::NONE;
};

#endif  // !INPUTINVERTER_H

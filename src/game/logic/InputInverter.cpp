// Corresponding header
#include "game/logic/InputInverter.h"

// C++ system includes
#include <cstdlib>

// Own components headers
#include "sdl_utils/InputEvent.h"

int32_t InputInverter::init(const int32_t boardWidth, const int32_t boardHeight) {
    _boardWidth = boardWidth;
    _boardHeight = boardHeight;
    return EXIT_SUCCESS;
}

void InputInverter::setBoardFlipType(WidgetFlip flipType) { _flipType = flipType; }

void InputInverter::invertEvent(InputEvent& inputEvent) {
    switch (_flipType) {
    case WidgetFlip::HORIZONTAL:
        inputEvent.pointPos.x = _boardWidth - inputEvent.pointPos.x;
        break;

    case WidgetFlip::VERTICAL:
        inputEvent.pointPos.y = _boardHeight - inputEvent.pointPos.y;
        break;

    case WidgetFlip::HORIZONTAL_AND_VERTICAL:
        inputEvent.pointPos.x = _boardWidth - inputEvent.pointPos.x;
        inputEvent.pointPos.y = _boardHeight - inputEvent.pointPos.y;
        break;

    case WidgetFlip::NONE:
        break;
    default:
        break;
    }
}
// Corresponding header
#include "utils/drawing/DrawParams.h"

// C++ system includes
#include <iostream>

void DrawParams::reset() {
    pos = Point::UNDEFINED;
    width = 0;
    height = 0;
    opacity = FULL_OPACITY;
    rsrcId = RESOURCE_ID;
    widgetType = WidgetType::UNKNOWN;
}

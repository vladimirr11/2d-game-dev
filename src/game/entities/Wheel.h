#ifndef WHEEL_H
#define WHEEL_H

// Own includes
#include "manager_utils/drawing/Image.h"

// Forward declarations
struct InputEvent;

class Wheel {
public:
    int32_t init(int32_t wheelResourceId);
    void draw();
    void handleEvent(const InputEvent& event);

private:
    Image _wheelImage;
};

#endif  // !WHEEL_H

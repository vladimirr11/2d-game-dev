#ifndef IMAGE_H
#define IMAGE_H

// Own includes
#include "manager_utils/drawing/Widget.h"

class Image : public Widget {
public:
    ~Image();

    void create(int32_t resourceId, const Point& pos = Point::ZERO);

    void destroy();
};

#endif  // !IMAGE_H

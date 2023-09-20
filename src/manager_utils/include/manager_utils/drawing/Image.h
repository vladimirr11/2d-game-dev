#ifndef IMAGE_H
#define IMAGE_H

// Own includes
#include "manager_utils/drawing/Widget.h"

class Image : public Widget {
public:
    ~Image();

    void create(int32_t resourceId, const Point& pos = Point::ZERO);
    void destroy();

    void setFrame(int32_t frameIdx);
    void setNextFrame();
    void setPrevFrame();

    int32_t getFrame() const;

private:
    int32_t _currFrame{0};
    int32_t _maxFrames{0};
    bool _isDestroyed = false;
};

#endif  // !IMAGE_H

#ifndef WIDGET_H
#define WIDGET_H

// Own includes
#include "utils/drawing/DrawParams.h"

class Widget {
public:
    void draw();

    void reset();

    void setFlipType(WidgetFlip flipType);

    void setRotation(double angle);
    double getRotation() const;

    void rotateRight(double delta);
    void rotateLeft(double delta);

    void setRotationCenter(const Point& rotationCenter);

    void setPosition(const Point& pos);
    void setPosition(int32_t x, int32_t y);

    void setOpacity(int32_t opacity);

    void setWidth(int32_t width);
    void setHeight(int32_t height);

    int32_t getWidth() const;
    int32_t getHeight() const;

    int32_t getOpacity() const;

    Point getPosition() const;

    void activateAlphaModulation();
    void deactivateAlphaModulation();

    void show();
    void hide();

    void moveRight(int32_t delta);
    void moveLeft(int32_t delta);
    void moveUp(int32_t delta);
    void moveDown(int32_t delta);

    bool containsPoint(const Point& pos) const;

    bool isVisible() const;

    bool isCreated() const;

protected:
    DrawParams _drawParams;
    bool _isCreated = false;
    bool _isVisible = true;
    bool _isAlphaModulationEnabled = false;
};

#endif  // !WIDGET_H

// Corresponding header
#include "manager_utils/drawing/Image.h"

// C++ system includes
#include <iostream>

// Own includes
#include "manager_utils/managers/ResourceManager.h"

Image::~Image() {
    if (_isCreated) {
        destroy();
    }
}

void Image::create(int32_t resourceId, const Point& pos) {
    if (_isCreated) {
        std::cerr << "Image::create() was called on image with resourceId " << resourceId
                  << " that was already created." << std::endl;
        return;
    }

    const Frames& imageFrames = gResourceManager->getImageFrames(resourceId);
    
    _maxFrames = static_cast<int32_t>(imageFrames.size());
    
    const Rectangle& firstFrame = imageFrames.front();

    _drawParams.frameRect = firstFrame;
    _drawParams.rsrcId = resourceId;
    _drawParams.width = firstFrame.w;
    _drawParams.height = firstFrame.h;
    _drawParams.pos = pos;
    _drawParams.widgetType = WidgetType::IMAGE;

    _isCreated = true;
}

void Image::destroy() {
    if (!_isCreated) {
        std::cerr << "Image::destroy() was called on image that was not created." << std::endl;
        return;
    }

    _isCreated = false;

    Widget::reset();
}

void Image::setFrame(const int32_t frameIdx) {
    if (0 > frameIdx || frameIdx >= _maxFrames) {
        std::cerr << "In Image::setFrame() trying to set invalid frameIdx: " << frameIdx
                  << " for image with resourceId " << _drawParams.rsrcId << std::endl;
        return;
    }

    const Frames& frames = gResourceManager->getImageFrames(_drawParams.rsrcId);
    _drawParams.frameRect = frames[frameIdx];
    _currFrame = frameIdx;
}

void Image::setNextFrame() {
    _currFrame++;
    if (_currFrame == _maxFrames) {
        _currFrame = 0;
    }

    const Frames& frames = gResourceManager->getImageFrames(_drawParams.rsrcId);
    _drawParams.frameRect = frames[_currFrame];
}

void Image::setPrevFrame() {
    _currFrame--;
    if (_currFrame == -1) {
        _currFrame = _maxFrames - 1;
    }

    const Frames& frames = gResourceManager->getImageFrames(_drawParams.rsrcId);
    _drawParams.frameRect = frames[_currFrame];
}

int32_t Image::getFrame() const { return _currFrame; }

// Corresponding header
#include "manager_utils/drawing/Text.h"

// C++ system includes
#include <iostream>

// Own includes
#include "manager_utils/managers/ResourceManager.h"

Text::~Text() { destroy(); }

void Text::create(const std::string& text, const int32_t fontId, const Color& color,
                  const Point& pos) {
    if (_isCreated) {
        std::cerr << "Text::create() was called with fontId " << fontId
                  << " that was already created." << std::endl;
        return;
    }

    gResourceManager->createText(text, color, fontId, _drawParams.rsrcId, _drawParams.width,
                                 _drawParams.height);

    _drawParams.frameRect.x = 0;
    _drawParams.frameRect.y = 0;
    _drawParams.frameRect.w = _drawParams.width;
    _drawParams.frameRect.h = _drawParams.height;
    _drawParams.pos = pos;
    _drawParams.widgetType = WidgetType::TEXT;

    _textContent = text;
    _color = color;
    _fontId = fontId;
    _isCreated = true;
}

void Text::destroy() {
    if (!_isCreated) {
        std::cerr << "Text::destroy() was called on text that was not created." << std::endl;
        return;
    }

    _isCreated = false;

    if (gResourceManager) {
        gResourceManager->unloadText(_drawParams.textId);
    }

    Widget::reset();
}

void Text::setText(const std::string& text) {
    if (text == _textContent) {
        return;
    }

    _textContent = text;
    gResourceManager->createText(text, _color, _fontId, _drawParams.rsrcId, _drawParams.width,
                                 _drawParams.height);

    _drawParams.frameRect.w = _drawParams.width;
    _drawParams.frameRect.h = _drawParams.height;
}

void Text::setColor(const Color& color) {
    if (color == _color) {
        return;
    }

    _color = color;
    gResourceManager->createText(_textContent, color, _fontId, _drawParams.rsrcId,
                                 _drawParams.width, _drawParams.height);
}

std::string Text::getTextContent() const { return _textContent; }

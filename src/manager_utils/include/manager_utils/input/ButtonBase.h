#ifndef BUTTONBASE_H
#define BUTTONBASE_H

// Own includes
#include "manager_utils/drawing/Image.h"

// Forward declarations
struct InputEvent;

enum ButtonStates { UNCLICKED, CLICKED, DISABLED };

class ButtonBase : public Image {
public:
    virtual ~ButtonBase() = default;

    virtual void handleEvent(const InputEvent& event) = 0;

    virtual void draw();

    void destroy();

    void lockInput();
    void unlockInput();

    bool isInputUnlocked() const;

    bool containsEvent(const InputEvent& event) const;

private:
    bool _isInputUnlocked = true;
};

#endif  // !BUTTONBASE_H

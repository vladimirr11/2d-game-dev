#ifndef GAMEPROXY_H
#define GAMEPROXY_H

// C++ system includes
#include <cstdint>

class GameProxy {
public:
    virtual ~GameProxy() = default;
    virtual void onButtonPressed(int32_t buttonId) = 0;
};

#endif  // !GAMEPROXY_H

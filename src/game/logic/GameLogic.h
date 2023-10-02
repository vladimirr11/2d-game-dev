#ifndef GAMELOGIC_H
#define GAMELOGIC_H

// C++ system includes
#include <cstdint>

class GameLogic {
public:
    GameLogic();

    int32_t getActivePlayerId() const;
    
    void finishTurn();

private:
    int32_t _activePlayerId;
};

#endif  // !GAMELOGIC_H

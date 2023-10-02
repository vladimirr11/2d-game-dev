// Corresponding header
#include "game/logic/GameLogic.h"

// Own includes
#include "game/chess_defines/ChessDefines.h"

GameLogic::GameLogic() : _activePlayerId(WHITE_PLAYER_ID) {}

int32_t GameLogic::getActivePlayerId() const { return _activePlayerId; }

void GameLogic::finishTurn() {
    if (_activePlayerId == WHITE_PLAYER_ID)
        _activePlayerId = BLACK_PLAYER_ID;
    else
        _activePlayerId = WHITE_PLAYER_ID;
}

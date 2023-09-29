#ifndef CHESSBOARD_H
#define CHESSBOARD_H

// C++ system includes
#include <cstdint>

// Own includes
#include "manager_utils/drawing/Image.h"
#include "manager_utils/timer/TimerClient.h"
#include "game/board/MoveSelector.h"
#include "game/proxies/GameBoardProxy.h"

class ChessBoard : public GameBoardProxy, public TimerClient {
public:
    ~ChessBoard();

    int32_t init(const int32_t chessBoardImageId, const int32_t targetId,
                 const int32_t moveSelectorResourceId, const int32_t blinkTimerId);
    
    void draw();

private:
    // GameBoardProxy
    void onPieceSelected(const BoardPosition& boardPos,
                         const std::vector<TileData>& moveTiles) final;
    void onPieceReleased() final;
    bool isMoveAllowed(const BoardPosition& pos) const final;

    // TimerClient
    void onTimeout(int32_t timerId) final;

private:
    Image _chessBoardImage;
    Image _targetImage;
    int32_t _blinkTimerId{};
    std::vector<TileData> _currMoveTiles;
    MoveSelector _moveSelector;
};

#endif  // !CHESSBOARD_H

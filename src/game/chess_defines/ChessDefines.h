#ifndef CHESSDEFINES_H
#define CHESSDEFINES_H

// C++ system includes
#include <cstdint>

enum PlayerId { WHITE_PLAYER_ID = 0, BLACK_PLAYER_ID, PLAYERS_COUNT };

enum class PieceType : uint8_t { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, UNKNOWN };

#endif  // !CHESSDEFINES_H

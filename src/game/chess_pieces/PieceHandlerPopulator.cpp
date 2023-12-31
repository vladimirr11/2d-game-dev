// Corresponding header
#include "game/chess_pieces/PieceHandlerPopulator.h"

// C++ system includes
#include <iostream>

// Own includes
#include "game/chess_pieces/types/UnfinishedPiece.h"
#include "game/chess_pieces/types/Rook.h"
#include "game/chess_pieces/types/Pawn.h"
#include "game/chess_defines/ChessDefines.h"
#include "utils/error/HandleError.h"

static constexpr auto STARTING_PIECES_COUNT = 16;
static constexpr auto PAWNS_COUNT = 8;

static std::unique_ptr<ChessPiece> createPiece(PieceType pieceType, GameProxy* gameProxy) {
    switch (pieceType) {
    case PieceType::ROOK:
        return std::make_unique<Rook>();
    case PieceType::PAWN:
        return std::make_unique<Pawn>(gameProxy);
    case PieceType::KING:
    case PieceType::QUEEN:
    case PieceType::BISHOP:
    case PieceType::KNIGHT:
        return std::make_unique<UnfinishedPiece>();
        break;

    default:
        std::cerr << "createPiece() received unsupported PieceType - "
                  << static_cast<int32_t>(pieceType) << std::endl;
    }

    return nullptr;
}

static int32_t populateWhitePieces(GameProxy* gameProxy, const int32_t whitePiecesResourceId,
                                   const int32_t unfinishedPieceFontId,
                                   ChessPiece::PlayerPiecesVec& whitePieces) {
    whitePieces.reserve(STARTING_PIECES_COUNT);

    ChessPieceConfig pieceCfg;
    pieceCfg.boardPos.boardRow = WHITE_PLAYER_START_PAWN_ROW;
    pieceCfg.playerId = WHITE_PLAYER_ID;
    pieceCfg.chessPieceResourceId = whitePiecesResourceId;
    pieceCfg.pieceType = PieceType::PAWN;
    pieceCfg.unfinishedPieceFontId = unfinishedPieceFontId;

    for (auto i = 0; i < PAWNS_COUNT; i++) {
        whitePieces.push_back(createPiece(pieceCfg.pieceType, gameProxy));
        pieceCfg.boardPos.boardCol = i;
        handleError(whitePieces[i]->init(pieceCfg));
    }

    constexpr PieceType nonPawnPieces[PAWNS_COUNT] = {
        PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN,
        PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK};

    pieceCfg.boardPos.boardRow = WHITE_PLAYER_START_PAWN_ROW + 1;
    for (auto i = PAWNS_COUNT; i < STARTING_PIECES_COUNT; i++) {
        pieceCfg.boardPos.boardCol = i - PAWNS_COUNT;
        pieceCfg.pieceType = nonPawnPieces[i - PAWNS_COUNT];
        whitePieces.push_back(createPiece(pieceCfg.pieceType, gameProxy));
        handleError(whitePieces[i]->init(pieceCfg));
    }

    return EXIT_SUCCESS;
}

static int32_t populateBlackPieces(GameProxy* gameProxy, int32_t blackPiecesResourceId,
                                   int32_t unfinishedPieceFontId,
                                   ChessPiece::PlayerPiecesVec& blackPieces) {
    blackPieces.reserve(STARTING_PIECES_COUNT);

    ChessPieceConfig pieceCfg;
    pieceCfg.boardPos.boardRow = BLACK_PLAYER_START_PAWN_ROW;
    pieceCfg.playerId = BLACK_PLAYER_ID;
    pieceCfg.chessPieceResourceId = blackPiecesResourceId;
    pieceCfg.pieceType = PieceType::PAWN;
    pieceCfg.unfinishedPieceFontId = unfinishedPieceFontId;

    for (int32_t i = 0; i < PAWNS_COUNT; i++) {
        blackPieces.push_back(createPiece(pieceCfg.pieceType, gameProxy));

        pieceCfg.boardPos.boardCol = i;
        handleError(blackPieces[i]->init(pieceCfg));
    }

    constexpr PieceType nonPawnPieces[PAWNS_COUNT] = {
        PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN,
        PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK};

    pieceCfg.boardPos.boardRow = BLACK_PLAYER_START_PAWN_ROW - 1;
    for (auto i = PAWNS_COUNT; i < STARTING_PIECES_COUNT; i++) {
        pieceCfg.boardPos.boardCol = i - PAWNS_COUNT;
        pieceCfg.pieceType = nonPawnPieces[i - PAWNS_COUNT];

        blackPieces.push_back(createPiece(pieceCfg.pieceType, gameProxy));
        handleError(blackPieces[i]->init(pieceCfg));
    }

    return EXIT_SUCCESS;
}

int32_t PieceHandlerPopulator::populate(
    GameProxy* gameProxy, const int32_t whitePiecesResId, const int32_t blackPiecesResId,
    const int32_t unfinishedPieceFontId,
    std::array<ChessPiece::PlayerPiecesVec, PLAYERS_COUNT>& outPiecesArr) {
    ChessPiece::PlayerPiecesVec& whitePieces = outPiecesArr[WHITE_PLAYER_ID];
    handleError(
        populateWhitePieces(gameProxy, whitePiecesResId, unfinishedPieceFontId, whitePieces));

    ChessPiece::PlayerPiecesVec& blackPieces = outPiecesArr[BLACK_PLAYER_ID];
    handleError(
        populateBlackPieces(gameProxy, blackPiecesResId, unfinishedPieceFontId, blackPieces));

    return EXIT_SUCCESS;
}

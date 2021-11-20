#ifndef CHESS_V2_KNIGHT_H
#define CHESS_V2_KNIGHT_H

#include "Piece.h"

class Knight : public Piece {

public:
    Knight() = default;
    explicit Knight(char color);
    std::vector<Square> getTargetSquares(const Square& start, const std::array<std::array<Piece*, 8>, 8>& board, char startColor, char oppositeColor, const Move& lastMove) override;
    int getPieceType() const override;
};

#endif //CHESS_V2_KNIGHT_H

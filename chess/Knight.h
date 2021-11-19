#ifndef CHESS_V2_KNIGHT_H
#define CHESS_V2_KNIGHT_H

#include "Piece.h"

class Knight : public Piece {

public:
    Knight() = default;
    explicit Knight(char color);
    std::vector<Square> getTargetSquares(const Square& start) override;
    int getPieceType() const override;
};

#endif //CHESS_V2_KNIGHT_H

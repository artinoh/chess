#ifndef CHESS_V2_BISHOP_H
#define CHESS_V2_BISHOP_H

#include "Piece.h"

class Bishop : public Piece {

public:
    Bishop() = default;
    explicit Bishop(char color);
    std::vector<Square> getTargetSquares(const Square& start) override;
    int getPieceType() const override;
};


#endif //CHESS_V2_BISHOP_H

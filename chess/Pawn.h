#ifndef CHESS_V2_PAWN_H
#define CHESS_V2_PAWN_H

#include "Piece.h"


class Pawn : public Piece {

public:
    Pawn() = default;
    explicit Pawn(char color);
    std::vector<Square> getTargetSquares(const Square& start) override;
    int getPieceType() const override;
};


#endif //CHESS_V2_PAWN_H

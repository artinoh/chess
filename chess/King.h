#ifndef CHESS_V2_KING_H
#define CHESS_V2_KING_H

#include "Piece.h"

class King : public Piece {

public:
    King() = default;
    explicit King(char color);
    std::vector<Square> getTargetSquares(const Square& start) override;
    int getPieceType() const override;
};


#endif //CHESS_V2_KING_H

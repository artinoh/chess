#ifndef CHESS_V2_ROOK_H
#define CHESS_V2_ROOK_H

#include "Piece.h"

class Rook : public Piece {

public:
    Rook() = default;
    explicit Rook(char color);
    std::vector<Square> getTargetSquares(const Square& start) override;
    int getPieceType() const override;
};


#endif //CHESS_V2_ROOK_H

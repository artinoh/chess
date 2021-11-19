#ifndef CHESS_V2_QUEEN_H
#define CHESS_V2_QUEEN_H

#include "Piece.h"

class Queen : public Piece {

public:
    Queen() = default;
    explicit Queen(char color);
    std::vector<Square> getTargetSquares(const Square& start) override;
    int getPieceType() const override;
};


#endif //CHESS_V2_QUEEN_H

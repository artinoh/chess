#ifndef CHESS_V2_KING_H
#define CHESS_V2_KING_H

#include "Piece.h"

class King : public Piece {

public:
    King() = default;
    explicit King(char color);
    King(char color, int inRow, int inCol);
    std::vector<Square> getTargetSquares(const Square& start, const std::array<std::array<Piece*, 8>, 8>& board, char startColor, char oppositeColor, const Move& lastMove) override;
    int getPieceType() const override;

private:
    bool squareIsInBounds(const Square& square);
};


#endif //CHESS_V2_KING_H

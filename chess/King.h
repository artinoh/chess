#ifndef CHESS_V2_KING_H
#define CHESS_V2_KING_H

#include "Piece.h"

class King : public Piece {

public:
    King() = default;
    explicit King(char color);
private:
    int getPieceType() const override;
    std::vector<Square> getTargetSquares(const Square& start, const std::array<std::array<Piece*, 8>, 8>& board, char startColor, char oppositeColor, const Move& lastMove) override;
};


#endif //CHESS_V2_KING_H

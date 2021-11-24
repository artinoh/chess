#ifndef CHESS_V2_ROOK_H
#define CHESS_V2_ROOK_H

#include "Piece.h"

class Rook : public Piece {

public:
    Rook() = default;
    explicit Rook(char color);
private:
    std::vector<Square> getTargetSquares(const Square& start, const std::array<std::array<Piece*, 8>, 8>& board, char startColor, char oppositeColor, const Move& lastMove) override;
    int getPieceType() const override;
};


#endif //CHESS_V2_ROOK_H

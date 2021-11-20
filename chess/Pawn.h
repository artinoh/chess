#ifndef CHESS_V2_PAWN_H
#define CHESS_V2_PAWN_H

#include "Piece.h"


class Pawn : public Piece {
private:
    bool hasDoubleMoved = false;


public:
    Pawn() = default;
    explicit Pawn(char color);
    std::vector<Square> getTargetSquares(const Square& start, const std::array<std::array<Piece*, 8>, 8>& board, char startColor, char oppositeColor, const Move& lastMove) override;
    int getPieceType() const override;
    void setHasDoubledMoved();
    bool getHasDoubleMoved() const;

};


#endif //CHESS_V2_PAWN_H

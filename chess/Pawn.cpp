#include "Pawn.h"

Pawn::Pawn(char color) {
    this->color = color;
}

std::vector<Square> Pawn::getTargetSquares(const Square &start) {
    return std::vector<Square>();
}

int Pawn::getPieceType() const {
    return PAWN;
}

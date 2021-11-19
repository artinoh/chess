#include "Rook.h"

Rook::Rook(char color) {
    this->color = color;
}

std::vector<Square> Rook::getTargetSquares(const Square &start) {
    return std::vector<Square>();
}

int Rook::getPieceType() const {
    return ROOK;
}

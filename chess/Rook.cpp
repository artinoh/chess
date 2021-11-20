#include "Rook.h"

Rook::Rook(char color) {
    this->color = color;
}

int Rook::getPieceType() const {
    return ROOK;
}

std::vector<Square> Rook::getTargetSquares(const Square &start, const std::array<std::array<Piece *, 8>, 8> &board, char startColor, char oppositeColor, const Move& lastMove) {
    return {};
}

#include "King.h"

King::King(char color) {
    this->color = color;
}

int King::getPieceType() const {
    return KING;
}

std::vector<Square> King::getTargetSquares(const Square &start, const std::array<std::array<Piece *, 8>, 8> &board, char startColor, char oppositeColor, const Move& lastMove) {
    return {};
}

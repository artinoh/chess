#include "King.h"

King::King(char color) {
    this->color = color;
}

std::vector<Square> King::getTargetSquares(const Square &start) {
    return std::vector<Square>();
}

int King::getPieceType() const {
    return KING;
}

//
// Created by Gamer on 11/18/2021.
//

#include "Queen.h"

Queen::Queen(char color) {
    this->color = color;
}

int Queen::getPieceType() const {
    return QUEEN;
}

std::vector<Square> Queen::getTargetSquares(const Square &start, const std::array<std::array<Piece *, 8>, 8> &board, char startColor, char oppositeColor, const Move& lastMove) {
    return {};
}

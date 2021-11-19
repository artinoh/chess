//
// Created by Gamer on 11/18/2021.
//

#include "Bishop.h"

Bishop::Bishop(char color) {
    this->color = color;
}

int Bishop::getPieceType() const {
    return BISHOP;
}

std::vector<Square> Bishop::getTargetSquares(const Square &start, const std::array<std::array<Piece *, 8>, 8> &board, char startColor, char oppositeColor) {
    return {};
}

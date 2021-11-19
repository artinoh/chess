//
// Created by Gamer on 11/18/2021.
//

#include "Bishop.h"

Bishop::Bishop(char color) {
    this->color = color;
}

std::vector<Square> Bishop::getTargetSquares(const Square &start) {
    return std::vector<Square>();
}

int Bishop::getPieceType() const {
    return BISHOP;
}

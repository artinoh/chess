//
// Created by Gamer on 11/18/2021.
//

#include "Queen.h"

Queen::Queen(char color) {
    this->color = color;
}

std::vector<Square> Queen::getTargetSquares(const Square &start) {
    return std::vector<Square>();
}

int Queen::getPieceType() const {
    return QUEEN;
}

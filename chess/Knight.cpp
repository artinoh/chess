//
// Created by Gamer on 11/18/2021.
//

#include "Knight.h"

Knight::Knight(char color) {
    this->color = color;
}

std::vector<Square> Knight::getTargetSquares(const Square &start) {
    return std::vector<Square>();
}

int Knight::getPieceType() const {
    return KNIGHT;
}

//
// Created by Gamer on 11/18/2021.
//

#include "Knight.h"

Knight::Knight(char color) {
    this->color = color;
}

int Knight::getPieceType() const {
    return KNIGHT;
}

std::vector<Square> Knight::getTargetSquares(const Square &start, const std::array<std::array<Piece *, 8>, 8> &board, char startColor, char oppositeColor, const Move& lastMove) {
    return {};
}

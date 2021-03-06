#include "Piece.h"

Piece::Piece() : color('N') {
}

void Piece::setColor(char color) {
    this->color = color;
}

char Piece::getColor() const {
    return color;
}

void Piece::setHasMoved(bool moved) {
    hasMoved = moved;
}

bool Piece::getHasMoved() const {
    return hasMoved;
}

std::vector<Square> Piece::getTargetSquares(const Square &start, const std::array<std::array<Piece*, 8>, 8>& board , char startColor, char oppositeColor, const Move& lastMove) {
    return {};
}

int Piece::getPieceType() const {
    return EMPTY;
}

bool Piece::squareIsInBounds(const Square &square) {
    if (square.row >= 8 || square.row < 0 || square.col >= 8 || square.col < 0) {
        return false;
    }
    return true;
}





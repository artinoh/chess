#include "Piece.h"

Piece::Piece() {

}

void Piece::setColor(char color) {
    this->color = color;
}

char Piece::getColor() const {
    return color;
}

void Piece::move() {
    hasMoved = true;
}

bool Piece::getHasMoved() const {
    return hasMoved;
}

std::vector<Square> Piece::getTargetSquares(const Square &start) {
    return {};
}

int Piece::getPieceType() const {
    return EMPTY;
}





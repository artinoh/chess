#include "Pawn.h"

Pawn::Pawn(char color) {
    this->color = color;


}



std::vector<Square> Pawn::getTargetSquares(const Square &start, const std::array<std::array<Piece*, 8>, 8>& board, char startColor, char oppositeColor) {

    std::vector<Square> targetSquares;
    if (color == 'W') {
        if (start.row - 1 >= 0) {
            //Regular Move Forward
            if (board[start.row-1][start.col]->getPieceType() == EMPTY) {
                targetSquares.emplace_back(start.row-1, start.col);
                //Double Move on first
                if (start.row == 6 && board[start.row-2][start.col]->getPieceType() == EMPTY) {
                    targetSquares.emplace_back(start.row-2, start.col);
                }
            }
            if (board[start.row-1][start.col+1]->getColor() == oppositeColor) {
                targetSquares.emplace_back(start.row-1, start.col+1);
            }
            if (board[start.row-1][start.col-1]->getColor() == oppositeColor) {
                targetSquares.emplace_back(start.row-1,start.col-1);
            }
            if (start.row == 3) {
                if (start.col - 1 >= 0 && board[start.row][start.col - 1]->getPieceType() == PAWN && board[start.row][start.col - 1]->getColor() == oppositeColor) {
                    Pawn *targetPawn = dynamic_cast<Pawn *>(board[start.row][start.col - 1]);
                    if (targetPawn->getHasDoubleMoved()) {
                        Square targetSquare(start.row-1, start.col-1);
                        targetSquare.enPassant = true;
                        targetSquares.push_back(targetSquare);
                    }
                }
                if (start.col + 1 < 8 && board[start.row][start.col + 1]->getPieceType() == PAWN && board[start.row][start.col + 1]->getColor() == oppositeColor) {
                    Pawn *targetPawn = dynamic_cast<Pawn *>(board[start.row][start.col + 1]);
                    if (targetPawn->getHasDoubleMoved()) {
                        Square targetSquare(start.row-1, start.col+1);
                        targetSquare.enPassant = true;
                        targetSquares.push_back(targetSquare);
                    }
                }
            }
        }
    }
    else if (color == 'B') {
        if (start.row + 1 < 8) {
            //Regular Move Forward
            if (board[start.row+1][start.col]->getPieceType() == EMPTY) {
                targetSquares.emplace_back(start.row+1, start.col);
                //Double Move on first
                if (start.row == 1 && board[start.row+2][start.col]->getPieceType() == EMPTY) {
                    targetSquares.emplace_back(start.row+2, start.col);
                }
            }
            if (board[start.row+1][start.col+1]->getColor() == oppositeColor) {
                targetSquares.emplace_back(start.row+1, start.col+1);
            }
            if (board[start.row+1][start.col-1]->getColor() == oppositeColor) {
                targetSquares.emplace_back(start.row+1,start.col-1);
            }
            if (start.row == 4) {
                if (start.col-1 >= 0 && board[start.row][start.col - 1]->getPieceType() == PAWN &&
                    board[start.row][start.col - 1]->getColor() == oppositeColor) {
                    Pawn *targetPawn = dynamic_cast<Pawn *>(board[start.row][start.col - 1]);
                    if (targetPawn->getHasDoubleMoved()) {
                        Square targetSquare(start.row+1, start.col-1);
                        targetSquare.enPassant = true;
                        targetSquares.push_back(targetSquare);
                    }
                }
                if (start.col+1 < 8 && board[start.row][start.col + 1]->getPieceType() == PAWN &&
                    board[start.row][start.col + 1]->getColor() == oppositeColor) {
                    Pawn *targetPawn = dynamic_cast<Pawn *>(board[start.row][start.col -+1]);
                    if (targetPawn->getHasDoubleMoved()) {
                        Square targetSquare(start.row+1, start.col+1);
                        targetSquare.enPassant = true;
                        targetSquares.push_back(targetSquare);
                    }
                }
            }
        }
    }
    return targetSquares;
}

int Pawn::getPieceType() const {
    return PAWN;
}

void Pawn::setHasDoubledMoved() {
    hasDoubleMoved = true;
}

bool Pawn::getHasDoubleMoved() const {
    return hasDoubleMoved;
}

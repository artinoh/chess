#include "Rook.h"

Rook::Rook(char color) {
    this->color = color;
}

int Rook::getPieceType() const {
    return ROOK;
}

std::vector<Square> Rook::getTargetSquares(const Square &start, const std::array<std::array<Piece *, 8>, 8> &board, char startColor, char oppositeColor, const Move& lastMove) {
    std::vector<Square> rookMoves;
    int tempRow, tempCol;

    //going down board
    tempRow = start.row + 1;
    tempCol = start.col;
    while (tempRow < 8) {
        if (board[tempRow][tempCol]->getPieceType() == EMPTY) {
            rookMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            rookMoves.emplace_back(tempRow, tempCol);
            break;
        }
        else {
            break;
        }
        tempRow++;
    }

    //going up board
    tempRow = start.row - 1;
    tempCol = start.col;
    while (tempRow >= 0) {
        if (board[tempRow][tempCol]->getPieceType() == EMPTY) {
            rookMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            rookMoves.emplace_back(tempRow, tempCol);
            break;
        }
        else {
            break;
        }
        tempRow--;
    }

    //going right
    tempRow = start.row;
    tempCol = start.col + 1;
    while (tempCol < 8) {
        if (board[tempRow][tempCol]->getPieceType() == EMPTY) {
            rookMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            rookMoves.emplace_back(tempRow, tempCol);
            break;
        }
        else {
            break;
        }
        tempCol++;
    }

    //going left
    tempRow = start.row;
    tempCol = start.col - 1;
    while (tempCol >= 0) {
        if (board[tempRow][tempCol]->getPieceType() == EMPTY) {
            rookMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            rookMoves.emplace_back(tempRow, tempCol);
            break;
        }
        else {
            break;
        }
        tempCol--;
    }


    return rookMoves;
}



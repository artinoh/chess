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

std::vector<Square> Bishop::getTargetSquares(const Square &start, const std::array<std::array<Piece *, 8>, 8> &board, char startColor, char oppositeColor, const Move& lastMove) {
    std::vector<Square> bishopMoves;
    int tempRow, tempCol;

    //Check Down and Right
    tempRow = start.row + 1;
    tempCol = start.col + 1;
    while (tempRow < 8 && tempCol < 8) {
        if (board[tempRow][tempCol]->getPieceType() == EMPTY) {
            bishopMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            bishopMoves.emplace_back(tempRow, tempCol);
            break;
        }
        else {
            break;
        }
        tempRow++;
        tempCol++;
    }

    //Check up and left
    tempRow = start.row - 1;
    tempCol = start.col - 1;
    while (tempRow >= 0 && tempCol >= 0) {
        if (board[tempRow][tempCol]->getPieceType() == EMPTY) {
            bishopMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            bishopMoves.emplace_back(tempRow, tempCol);
            break;
        }
        else {
            break;
        }
        tempRow--;
        tempCol--;
    }

    //check down and left
    tempRow = start.row + 1;
    tempCol = start.col - 1;
    while (tempRow < 8 && tempCol >= 0) {
        if (board[tempRow][tempCol]->getPieceType() == EMPTY) {
            bishopMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            bishopMoves.emplace_back(tempRow, tempCol);
            break;
        }
        else {
            break;
        }
        tempRow++;
        tempCol--;
    }

    //check up and right
    tempRow = start.row - 1;
    tempCol = start.col + 1;
    while (tempRow >= 0 && tempCol < 8) {
        if (board[tempRow][tempCol]->getPieceType() == EMPTY) {
            bishopMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            bishopMoves.emplace_back(tempRow, tempCol);
            break;
        }
        else {
            break;
        }
        tempRow--;
        tempCol++;
    }

    return  bishopMoves;
}


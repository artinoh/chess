//
// Created by Gamer on 11/18/2021.
//

#include "Queen.h"

Queen::Queen(char color) {
    this->color = color;
}

int Queen::getPieceType() const {
    return QUEEN;
}

std::vector<Square> Queen::getTargetSquares(const Square &start, const std::array<std::array<Piece *, 8>, 8> &board, char startColor, char oppositeColor, const Move& lastMove) {
    std::vector<Square> queenMoves;
    int tempRow, tempCol;

    //Check Down and Right
    tempRow = start.row + 1;
    tempCol = start.col + 1;
    while (tempRow < 8 && tempCol < 8) {
        if (board[tempRow][tempCol]->getPieceType() == EMPTY) {
            queenMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            queenMoves.emplace_back(tempRow, tempCol);
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
            queenMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            queenMoves.emplace_back(tempRow, tempCol);
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
            queenMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            queenMoves.emplace_back(tempRow, tempCol);
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
            queenMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            queenMoves.emplace_back(tempRow, tempCol);
            break;
        }
        else {
            break;
        }
        tempRow--;
        tempCol++;
    }
    //going down board
    tempRow = start.row + 1;
    tempCol = start.col;
    while (tempRow < 8) {
        if (board[tempRow][tempCol]->getPieceType() == EMPTY) {
            queenMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            queenMoves.emplace_back(tempRow, tempCol);
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
            queenMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            queenMoves.emplace_back(tempRow, tempCol);
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
            queenMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            queenMoves.emplace_back(tempRow, tempCol);
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
            queenMoves.emplace_back(tempRow, tempCol);
        }
        else if (board[tempRow][tempCol]->getColor() == oppositeColor) {
            queenMoves.emplace_back(tempRow, tempCol);
            break;
        }
        else {
            break;
        }
        tempCol--;
    }


    return queenMoves;
}

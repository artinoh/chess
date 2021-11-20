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
    std::vector<Square> knightMoves;
    Square squaretoCheck;

    squaretoCheck.row = start.row + 2;
    squaretoCheck.col = start.col + 1;
    if (squareIsInBounds(squaretoCheck) && (board[squaretoCheck.row][squaretoCheck.col]->getColor() == oppositeColor || board[squaretoCheck.row][squaretoCheck.col]->getPieceType() == EMPTY)) {
        knightMoves.push_back(squaretoCheck);
    }
    squaretoCheck.row = start.row - 2;
    squaretoCheck.col = start.col + 1;
    if (squareIsInBounds(squaretoCheck) && (board[squaretoCheck.row][squaretoCheck.col]->getColor() == oppositeColor || board[squaretoCheck.row][squaretoCheck.col]->getPieceType() == EMPTY)) {
        knightMoves.push_back(squaretoCheck);
    }
    squaretoCheck.row = start.row + 2;
    squaretoCheck.col = start.col - 1;
    if (squareIsInBounds(squaretoCheck) && (board[squaretoCheck.row][squaretoCheck.col]->getColor() == oppositeColor || board[squaretoCheck.row][squaretoCheck.col]->getPieceType() == EMPTY)) {
        knightMoves.push_back(squaretoCheck);
    }
    squaretoCheck.row = start.row - 2;
    squaretoCheck.col = start.col - 1;
    if (squareIsInBounds(squaretoCheck) && (board[squaretoCheck.row][squaretoCheck.col]->getColor() == oppositeColor || board[squaretoCheck.row][squaretoCheck.col]->getPieceType() == EMPTY)) {
        knightMoves.push_back(squaretoCheck);
    }
    squaretoCheck.row = start.row + 1;
    squaretoCheck.col = start.col + 2;
    if (squareIsInBounds(squaretoCheck) && (board[squaretoCheck.row][squaretoCheck.col]->getColor() == oppositeColor || board[squaretoCheck.row][squaretoCheck.col]->getPieceType() == EMPTY)) {
        knightMoves.push_back(squaretoCheck);
    }
    squaretoCheck.row = start.row - 1;
    squaretoCheck.col = start.col + 2;
    if (squareIsInBounds(squaretoCheck) && (board[squaretoCheck.row][squaretoCheck.col]->getColor() == oppositeColor || board[squaretoCheck.row][squaretoCheck.col]->getPieceType() == EMPTY)) {
        knightMoves.push_back(squaretoCheck);
    }
    squaretoCheck.row = start.row + 1;
    squaretoCheck.col = start.col - 2;
    if (squareIsInBounds(squaretoCheck) && (board[squaretoCheck.row][squaretoCheck.col]->getColor() == oppositeColor || board[squaretoCheck.row][squaretoCheck.col]->getPieceType() == EMPTY)) {
        knightMoves.push_back(squaretoCheck);
    }
    squaretoCheck.row = start.row - 1;
    squaretoCheck.col = start.col - 2;
    if (squareIsInBounds(squaretoCheck) && (board[squaretoCheck.row][squaretoCheck.col]->getColor() == oppositeColor || board[squaretoCheck.row][squaretoCheck.col]->getPieceType() == EMPTY)) {
        knightMoves.push_back(squaretoCheck);
    }

    for (int i=0; i<knightMoves.size(); i++) {
        knightMoves[i].enPassant = false;
        knightMoves[i].castle = false;
    }

    return knightMoves;
}

bool Knight::squareIsInBounds(const Square &square) {
    if (square.row >= 8 || square.row < 0 || square.col >= 8 || square.col < 0) {
        return false;
    }
    return true;
}

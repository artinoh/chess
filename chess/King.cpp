#include "King.h"

King::King(char color) {
    this->color = color;
}

int King::getPieceType() const {
    return KING;
}

std::vector<Square> King::getTargetSquares(const Square &start, const std::array<std::array<Piece *, 8>, 8> &board, char startColor, char oppositeColor, const Move& lastMove) {
    std::vector<Square> kingMoves;
    Square squareToCheck;
    squareToCheck.row = start.row + 1;
    squareToCheck.col = start.col;
    if (squareIsInBounds(squareToCheck) && (board[squareToCheck.row][squareToCheck.col]->getPieceType() == EMPTY || board[squareToCheck.row][squareToCheck.col]->getColor() == oppositeColor)) {
        kingMoves.push_back(squareToCheck);
    }
    squareToCheck.row = start.row - 1;
    squareToCheck.col = start.col;
    if (squareIsInBounds(squareToCheck) && (board[squareToCheck.row][squareToCheck.col]->getPieceType() == EMPTY || board[squareToCheck.row][squareToCheck.col]->getColor() == oppositeColor)) {
        kingMoves.push_back(squareToCheck);
    }
    squareToCheck.row = start.row;
    squareToCheck.col = start.col + 1;
    if (squareIsInBounds(squareToCheck) && (board[squareToCheck.row][squareToCheck.col]->getPieceType() == EMPTY || board[squareToCheck.row][squareToCheck.col]->getColor() == oppositeColor)) {
        kingMoves.push_back(squareToCheck);
    }
    squareToCheck.row = start.row;
    squareToCheck.col = start.col - 1;
    if (squareIsInBounds(squareToCheck) && (board[squareToCheck.row][squareToCheck.col]->getPieceType() == EMPTY || board[squareToCheck.row][squareToCheck.col]->getColor() == oppositeColor)) {
        kingMoves.push_back(squareToCheck);
    }
    squareToCheck.row = start.row + 1;
    squareToCheck.col = start.col + 1;
    if (squareIsInBounds(squareToCheck) && (board[squareToCheck.row][squareToCheck.col]->getPieceType() == EMPTY || board[squareToCheck.row][squareToCheck.col]->getColor() == oppositeColor)) {
        kingMoves.push_back(squareToCheck);
    }
    squareToCheck.row = start.row - 1;
    squareToCheck.col = start.col - 1;
    if (squareIsInBounds(squareToCheck) && (board[squareToCheck.row][squareToCheck.col]->getPieceType() == EMPTY || board[squareToCheck.row][squareToCheck.col]->getColor() == oppositeColor)) {
        kingMoves.push_back(squareToCheck);
    }
    squareToCheck.row = start.row + 1;
    squareToCheck.col = start.col - 1;
    if (squareIsInBounds(squareToCheck) && (board[squareToCheck.row][squareToCheck.col]->getPieceType() == EMPTY || board[squareToCheck.row][squareToCheck.col]->getColor() == oppositeColor)) {
        kingMoves.push_back(squareToCheck);
    }
    squareToCheck.row = start.row - 1;
    squareToCheck.col = start.col + 1;
    if (squareIsInBounds(squareToCheck) && (board[squareToCheck.row][squareToCheck.col]->getPieceType() == EMPTY || board[squareToCheck.row][squareToCheck.col]->getColor() == oppositeColor)) {
        kingMoves.push_back(squareToCheck);
    }

    //Castles
    //White Castle
    if (start.row == 7 && start.col == 4 && !board[start.row][start.col]->getHasMoved() && board[start.row][start.col]->getColor() == 'W') {
        //Castle Right
        if (board[7][5]->getPieceType() == EMPTY && board[7][6]->getPieceType() == EMPTY && board[7][7]->getPieceType() == ROOK && !board[7][7]->getHasMoved()) {
            Square castleRight(7,6);
            castleRight.castle = true;
            kingMoves.push_back(castleRight);
        }
        //Castle Left
        if (board[7][3]->getPieceType() == EMPTY && board[7][2]->getPieceType() == EMPTY && board[7][1]->getPieceType() == EMPTY && board[7][0]->getPieceType() == ROOK && !board[7][0]->getHasMoved()) {
            Square castleLeft(7,2);
            castleLeft.castle = true;
            kingMoves.push_back(castleLeft);
        }
    }
    //Black Castle
    else if (start.row == 0 && start.col == 4 && !board[start.row][start.col]->getHasMoved() && board[start.row][start.col]->getColor() == 'B') {
        if (board[0][5]->getPieceType() == EMPTY && board[0][6]->getPieceType() == EMPTY && board[0][7]->getPieceType() == ROOK && !board[0][7]->getHasMoved()) {
            Square castleRight(0,6);
            castleRight.castle = true;
            kingMoves.push_back(castleRight);
        }
        if (board[0][3]->getPieceType() == EMPTY && board[0][2]->getPieceType() == EMPTY && board[0][1]->getPieceType() == EMPTY && board[0][0]->getPieceType() == ROOK && !board[0][0]->getHasMoved()) {
            Square castleLeft(0,2);
            castleLeft.castle = true;
            kingMoves.push_back(castleLeft);
        }
    }

    return kingMoves;
}

bool King::squareIsInBounds(const Square &square) {
    if (square.row >= 8 || square.row < 0 || square.col >= 8 || square.col < 0) {
        return false;
    }
    return true;
}

King::King(char color, int inRow, int inCol) {
    this->color = color;
    this->row = inRow;
    this->col = inCol;
}

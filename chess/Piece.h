#ifndef CHESS_V2_PIECE_H
#define CHESS_V2_PIECE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <string>
#include "AssetManager.h"
#include "Definitions.h"
#include <iostream>


struct Square {
    int row, col;
    bool enPassant = false;
    bool castle = false;
    Square() : row(0), col(0) {}
    Square(int inRow, int inCol) : row(inRow), col(inCol) {}
    bool operator==(const Square& b) const {
        return (row == b.row && col == b.col);
    }
    Square& operator=(const Square& b) = default;
};

struct Move {
    Square start, target;
    bool tookPiece = false;
    Move() = default;
    Move(Square inStart, Square inTarget) : start(inStart), target(inTarget) {}
    bool operator ==(const Move& b) const {
        return (start == b.start && target == b.target);
    }
};

enum PieceType {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};


class Piece {

protected:
    char color;
    bool hasMoved = false;

public:
    Piece();
    void setColor(char color);
    char getColor () const;
    void setHasMoved(bool moved);
    bool getHasMoved() const;
    virtual std::vector<Square> getTargetSquares(const Square& start, const std::array<std::array<Piece*, 8>, 8>& board, char startColor, char oppositeColor, const Move& lastMove);
    virtual int getPieceType() const;


};


#endif //CHESS_V2_PIECE_H

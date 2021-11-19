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
    Square() : row(0), col(0) {}
    Square(int inRow, int inCol) : row(inRow), col(inCol) {}
    bool operator==(const Square& b) const {
        return (row == b.row && col == b.col);
    }
};

struct Move {
    Square start, target;
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
    void move();
    bool getHasMoved() const;
    virtual std::vector<Square> getTargetSquares(const Square& start);
    virtual int getPieceType() const;

};


#endif //CHESS_V2_PIECE_H

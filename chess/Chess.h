#ifndef CHESS_V2_CHESS_H
#define CHESS_V2_CHESS_H

#include <array>
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "ComputerPlayer.h"
#include "Definitions.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

class Chess : public sf::Drawable {

private:
    Piece* pieceBoard[8][8];
    sf::Sprite spriteBoard[8][8];
    sf::RectangleShape squaresBoard[8][8];
    sf::Sprite temp;
    gameDataRef data;
    Piece emptyPiece;

    void initPieces();
    void initBoardSquares();
    void prepareBoardToDraw();
    void printBoard() const;

public:
    Chess() = default;
    explicit Chess(gameDataRef inData);

    bool processPlayerMove(const Move& move);


    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CHESS_V2_CHESS_H

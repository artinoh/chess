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
    std::array<std::array<Piece*, 8>, 8> pieceBoard;
    sf::Sprite spriteBoard[8][8];
    sf::RectangleShape squaresBoard[8][8];
    sf::Sprite temp;
    gameDataRef data;
    Piece emptyPiece;
    std::deque<Move> moves;
    std::deque<Piece*> piecesTaken;


    std::vector<Square> getPotentialMoves(const Square& start);
    void initPieces();
    void initBoardSquares();
    void prepareBoardToDraw();


public:

    Chess() = default;
    ~Chess();
    explicit Chess(gameDataRef inData);
    bool processPlayerMove(Move& move);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void drawPotentialMoves(const Square& start);
    void drawCleanBoard();
    void undoMove();
};


#endif //CHESS_V2_CHESS_H

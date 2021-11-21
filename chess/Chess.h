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
#include "Definitions.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include <random>
#include <ctime>
#include <chrono>
using namespace std::chrono;

struct MaterialCountEvaluation {
    int whiteEval = 0;
    int blackEval = 0;
};

class Chess : public sf::Drawable {

private:
    std::array<std::array<Piece*, 8>, 8> pieceBoard;
    sf::Sprite spriteBoard[8][8];
    sf::RectangleShape squaresBoard[8][8];
    std::vector<sf::RectangleShape> potentialSquares;
    gameDataRef data;
    Piece emptyPiece;
    std::deque<std::array<std::array<Piece*, 8>, 8>> previousPositions;
    std::deque<Move> moves;


    std::vector<Square> getPotentialMovesFromSquare(const Square& start);
    void initPieces();
    void initBoardSquares();
    void prepareBoardToDraw();
    void castle(const Square& target, char color);
    void enPassant(const Square& target, char color);
    std::vector<std::vector<Square>> getAllAttacking(char teamColor);
    Square findKing(char teamColor) const;

    std::vector<Square> getLegalMovesFromSquare(const Square& start);
    std::vector<Piece*> newQueens;
    void processMove(Move& move);
    bool isKingAttacked(char teamColor);
    int numMovesAvailable(char teamColor);


    //MiniMaxStuff
    const int pawnValue = 100;
    const int knightValue = 300;
    const int bishopValue = 300;
    const int rookValue = 500;
    const int queenValue = 900;
    int evaluate(char teamColor);
    MaterialCountEvaluation countMaterial();
    int minimax(int depth, bool isMax, int alpha, int beta);
    std::vector<Move> getAllPossibleMoves(char teamColor);


public:
    Chess() = default;
    ~Chess();
    explicit Chess(gameDataRef inData);
    bool checkLegalMove(Move& move);


    bool isLegalMove(Move& move);
    void makeMove(Move& move);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void drawLegalMoves(const Square& start);
    void undoMove();
    void drawCleanBoard();

    bool isClickedOnWhitePiece(const Square& start);

    bool blackIsCheckmated();
    bool whiteIsCheckmated();
    bool stalemate();

    Move getComputerMove();
    Move getComputerMove(bool test);


};


#endif //CHESS_V2_CHESS_H

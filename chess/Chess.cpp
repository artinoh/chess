#include "Chess.h"
#include <utility>


Chess::Chess(gameDataRef inData) : data(std::move(inData)) {
    initPieces();
    initBoardSquares();
    prepareBoardToDraw();
}

void Chess::drawCleanBoard() {
    int squareSide = SCREEN_HEIGHT/8;
    sf::Vector2f squareSize(squareSide, squareSide);
    sf::Color whiteSquareColor(255,180,100);
    sf::Color blackSquareColor(120,60,0);
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if ((i+j) %2 == 0) {
                squaresBoard[i][j].setFillColor(whiteSquareColor);
            }
            else {
                squaresBoard[i][j].setFillColor(blackSquareColor);
            }
            squaresBoard[i][j].setSize(squareSize);
            squaresBoard[i][j].setPosition(squareSize.x * j, squareSize.y * i);
        }
    }
    potentialSquares.clear();
}

void Chess::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            window.draw(squaresBoard[i][j]);
        }
    }
    for (int i=0; i<potentialSquares.size(); i++) {
        window.draw(potentialSquares[i]);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            window.draw(spriteBoard[i][j]);
        }
    }
}

void Chess::initBoardSquares() {
    int squareSide = SCREEN_HEIGHT/8;
    sf::Vector2f squareSize(squareSide, squareSide);
    drawCleanBoard();

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            spriteBoard[i][j].setPosition(squareSize.x*j, squareSize.y*i);
            spriteBoard[i][j].setTexture(data->assets.getTexture("Empty Square"));
        }
    }
}

void Chess::initPieces() {

    std::array<Pawn*, 8> whitePawns;
    for(int i=0; i<whitePawns.size(); i++) {
        whitePawns[i] = new Pawn('W');
        pieceBoard[6][i] = whitePawns[i];
    }
    Rook* whiteLeftRook = new Rook('W');
    Rook* whiteRightRook = new Rook('W');
    Knight* whiteleftKnight = new Knight('W');
    Knight* whiteRightKnight = new Knight('W');
    Bishop* whiteLeftBishop = new Bishop('W');
    Bishop* whiteRightBishop = new Bishop('W');
    Queen* whiteQueen = new Queen('W');
    King* whiteKing = new King('W');

    pieceBoard[7][0] = whiteLeftRook;
    pieceBoard[7][1] = whiteleftKnight;
    pieceBoard[7][2] = whiteLeftBishop;
    pieceBoard[7][3] = whiteQueen;
    pieceBoard[7][4] = whiteKing;
    pieceBoard[7][5] = whiteRightBishop;
    pieceBoard[7][6] = whiteRightKnight;
    pieceBoard[7][7] = whiteRightRook;

    std::array<Pawn*, 8> blackPawns;
    for (int i=0; i<blackPawns.size(); i++) {
        blackPawns[i] = new Pawn('B');
        pieceBoard[1][i] = blackPawns[i];
    }

    Rook* blackLeftRook = new Rook('B');
    Rook* blackRightRook = new Rook('B');
    Knight* blackleftKnight = new Knight('B');
    Knight* blackRightKnight = new Knight('B');
    Bishop* blackLeftBishop = new Bishop('B');
    Bishop* blackRightBishop = new Bishop('B');
    Queen* blackQueen = new Queen('B');
    King* blackKing = new King('B');

    pieceBoard[0][0] = blackLeftRook;
    pieceBoard[0][1] = blackleftKnight;
    pieceBoard[0][2] = blackLeftBishop;
    pieceBoard[0][3] = blackQueen;
    pieceBoard[0][4] = blackKing;
    pieceBoard[0][5] = blackRightBishop;
    pieceBoard[0][6] = blackRightKnight;
    pieceBoard[0][7] = blackRightRook;

    for (int i=2; i<6; i++) {
        for (int j=0; j<8; j++) {
            pieceBoard[i][j] = &emptyPiece;
        }
    }
}

void Chess::prepareBoardToDraw() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pieceBoard[i][j] != nullptr) {
                if (pieceBoard[i][j]->getPieceType() == PAWN) {
                    if (pieceBoard[i][j]->getColor() == 'W') {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("White Pawn"));
                    }
                    else {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("Black Pawn"));
                    }
                }
                else if (pieceBoard[i][j]->getPieceType() == KNIGHT) {
                    if (pieceBoard[i][j]->getColor() == 'W') {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("White Knight"));
                    }
                    else {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("Black Knight"));
                    }
                }
                else if (pieceBoard[i][j]->getPieceType() == BISHOP) {
                    if (pieceBoard[i][j]->getColor() == 'W') {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("White Bishop"));
                    }
                    else {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("Black Bishop"));
                    }
                }
                else if (pieceBoard[i][j]->getPieceType() == ROOK) {
                    if (pieceBoard[i][j]->getColor() == 'W') {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("White Rook"));
                    }
                    else {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("Black Rook"));
                    }
                }
                else if (pieceBoard[i][j]->getPieceType() == QUEEN) {
                    if (pieceBoard[i][j]->getColor() == 'W') {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("White Queen"));
                    }
                    else {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("Black Queen"));
                    }
                }
                else if (pieceBoard[i][j]->getPieceType() == KING) {
                    if (pieceBoard[i][j]->getColor() == 'W') {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("White King"));
                    }
                    else {
                        spriteBoard[i][j].setTexture(data->assets.getTexture("Black King"));
                    }
                }
                else if (pieceBoard[i][j]->getPieceType() == EMPTY) {
                    spriteBoard[i][j].setTexture(data->assets.getTexture("Empty Square"));
                }
            }
        }
    }
}

void Chess::drawPotentialMoves(const Square &start) {
    potentialSquares.clear();
    int squareSide = SCREEN_HEIGHT/8;
    std::vector<Square> potentialMoves = getPotentialMoves(start);
    sf::Color potentialMoveColor(255,0,0, 100);
    for (int i=0; i<potentialMoves.size(); i++) {
        int row = potentialMoves[i].row;
        int col = potentialMoves[i].col;
        sf::RectangleShape tempSquare;
        tempSquare.setFillColor(potentialMoveColor);
        tempSquare.setSize(squaresBoard[row][col].getSize());
        tempSquare.setPosition(squaresBoard[row][col].getPosition());
        potentialSquares.push_back(tempSquare);
    }
}

bool Chess::processPlayerMove(Move &move) {
    std::vector<Square> legalMoves = getPotentialMoves(move.start);
    char currentPieceType = pieceBoard[move.start.row][move.start.col]->getPieceType();
    char currentPieceColor = pieceBoard[move.start.row][move.start.col]->getColor();
    Piece* tempPieceHolder = nullptr;

    bool moveFound = false;
    for (int i=0; i<legalMoves.size(); i++) {
        if (move.target == legalMoves[i]) {
            moveFound = true;
            move.target = legalMoves[i];
        }
    }

    if (moveFound) {
        moves.push_back(move);
        pieceBoard[move.start.row][move.start.col]->pieceHasMoved();

        //Pawn Flag for double pieceHasMoved
        if (currentPieceType == PAWN) {
            if (abs(move.start.row - move.target.row) == 2) {
                Pawn *thisPawn = dynamic_cast<Pawn *>(pieceBoard[move.start.row][move.start.col]);
                thisPawn->setHasDoubledMoved();
            }
        }
        //Handle En Passant and get pointer to piece being removed
        if (pieceBoard[move.target.row][move.target.col]->getPieceType() != EMPTY || move.target.enPassant) {
            move.tookPiece = true;
            //En Passant
            if (move.target.enPassant) {
                move.target.enPassant = false;
                std::cout << "IN EN PASSANT" << std::endl;
                if (currentPieceColor == 'W') {
                    std::cout << "IN WHITE EN PASSANT" << std::endl;
                    tempPieceHolder = pieceBoard[move.target.row+1][move.target.col];
                    pieceBoard[move.target.row+1][move.target.col] = &emptyPiece;
                    piecesTaken.push_back(PAWN);
                }
                else if (currentPieceColor == 'B') {
                    std::cout << "IN BLACK EN PASSANT" << std::endl;
                    tempPieceHolder = pieceBoard[move.target.row-1][move.target.col];
                    pieceBoard[move.target.row- 1][move.target.col] = &emptyPiece;
                    piecesTaken.push_back(PAWN);
                }
            }
            else {
                piecesTaken.push_back(pieceBoard[move.target.row][move.target.col]->getPieceType());
                tempPieceHolder = pieceBoard[move.target.row][move.target.col];
            }
        }

        //Complete Move
        pieceBoard[move.target.row][move.target.col] = pieceBoard[move.start.row][move.start.col];
        pieceBoard[move.start.row][move.start.col] = &emptyPiece;


        //Queening Pawn
        if (currentPieceType == PAWN && currentPieceColor == 'W' && move.target.row == 0) {
            delete pieceBoard[move.target.row][move.target.col];
            pieceBoard[move.target.row][move.target.col] = new Queen('W');
        }
        else if (currentPieceType == PAWN && currentPieceColor == 'B' && move.target.row == 7) {
            delete pieceBoard[move.target.row][move.target.col];
            pieceBoard[move.target.row][move.target.col] = new Queen('B');
        }

        delete tempPieceHolder;
        tempPieceHolder = nullptr;

        prepareBoardToDraw();
        return true;
    }
    else {
        return false;
    }
}

std::vector<Square> Chess::getPotentialMoves(const Square &start) {
    std::vector<Square> potentialMoves;
    char startColor = pieceBoard[start.row][start.col]->getColor();
    char oppositeColor;

    if (startColor == 'W')
        oppositeColor = 'B';
    else if (startColor == 'B')
        oppositeColor = 'W';
    else
        oppositeColor = startColor;

    potentialMoves = pieceBoard[start.row][start.col]->getTargetSquares(start, pieceBoard, startColor, oppositeColor, moves.back());
    std::cout << "Start Square Row: " << start.row << " Start Square Col: " << start.col << std::endl;
    for (int i = 0; i < potentialMoves.size(); i++) {
        std::cout << "Potential Row: " << potentialMoves[i].row << " Potential Col: " << potentialMoves[i].col << std::endl;
    }
    return potentialMoves;
}


Chess::~Chess() {
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (pieceBoard[i][j]) {
                delete pieceBoard[i][j];
            }
        }
    }
}

void Chess::clearPotentialSquares() {
    potentialSquares.clear();
}




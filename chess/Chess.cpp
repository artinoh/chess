#include "Chess.h"
#include <utility>


Chess::Chess(gameDataRef inData) : data(std::move(inData)) {
    initPieces();
    initBoardSquares();
    prepareBoardToDraw();
    srand(time(NULL));
}

Chess::~Chess() {
    pieceBoard = previousPositions.front();
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (pieceBoard[i][j]->getPieceType() != EMPTY) {
                delete pieceBoard[i][j];
                pieceBoard[i][j] = nullptr;
            }
        }
    }
    for (int i=0; i<newQueens.size(); i++) {
        delete newQueens[i];
        newQueens[i] = nullptr;
    }
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
    Bishop* blackRightBishop = new Bishop('B');
    Bishop* blackLeftBishop = new Bishop('B');
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
    previousPositions.push_back(pieceBoard);
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

void Chess::drawLegalMoves(const Square &start) {
    if (isClickedOnWhitePiece(start)) {
        potentialSquares.clear();
        int squareSide = SCREEN_HEIGHT/8;
        std::vector<Square> potentialMoves = getLegalMovesFromSquare(start);
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
}

bool Chess::checkLegalMove(Move &move) {
    char currentPieceColor = pieceBoard[move.start.row][move.start.col]->getColor();
    char oppositeColor;
    if (currentPieceColor == 'W') {
        oppositeColor = 'B';
    }
    else if (currentPieceColor == 'B') {
        oppositeColor = 'W';
    }
    else {
        oppositeColor = currentPieceColor;
    }

    processMove(move);
    bool isKingSafe = !isKingAttacked(currentPieceColor);
    undoMove();
    return isKingSafe;
}

bool Chess::isKingAttacked(char teamColor) {
    //Make this a member variable
    Square currentKingSquare = findKing(teamColor);
    char oppositeColor;
    if (teamColor == 'W') {
        oppositeColor = 'B';
    }
    else if (teamColor == 'B') {
        oppositeColor = 'W';
    }
    else {
        oppositeColor = teamColor;
    }

    //get column / row of king
    //get diagonal of king
    //only check those

    std::vector<std::vector<Square>> oppositeColorAttacking = getAllAttacking(oppositeColor);
    bool isKingAttacked = false;
    for (int i=0; i<oppositeColorAttacking.size(); i++) {
        for (int j=0; j<oppositeColorAttacking[i].size(); j++) {
            if (oppositeColorAttacking[i][j] == currentKingSquare) {
                isKingAttacked = true;
            }
        }
    }
    return isKingAttacked;
}

//Puts a move on board
void Chess::processMove(Move &move) {
    char currentPieceColor = pieceBoard[move.start.row][move.start.col]->getColor();
    int currentPieceType = pieceBoard[move.start.row][move.start.col]->getPieceType();
    previousPositions.push_back(pieceBoard);
    moves.push_back(move);

    pieceBoard[move.start.row][move.start.col]->setHasMoved(true);

    //Pawn Flag for hasDoubleMoved
    if (currentPieceType == PAWN) {
        if (abs(move.start.row - move.target.row) == 2) {
            Pawn *thisPawn = dynamic_cast<Pawn *>(pieceBoard[move.start.row][move.start.col]);
            thisPawn->setHasDoubledMoved(true);
        }
    }

    //Handle En Passant
    if (move.target.enPassant) {
        enPassant(move.target, currentPieceColor);
    }

    //Handle Castles
    if (move.target.castle) {
        castle(move.target, currentPieceColor);
    }

    //Complete Move
    pieceBoard[move.target.row][move.target.col] = pieceBoard[move.start.row][move.start.col];
    pieceBoard[move.start.row][move.start.col] = &emptyPiece;


    //Queening Pawn
    if (currentPieceType == PAWN && currentPieceColor == 'W' && move.target.row == 0) {
        pieceBoard[move.target.row][move.target.col] = new Queen('W');
        newQueens.push_back(pieceBoard[move.target.row][move.target.col]);
    }
    else if (currentPieceType == PAWN && currentPieceColor == 'B' && move.target.row == 7) {
        pieceBoard[move.target.row][move.target.col] = new Queen('B');
        newQueens.push_back(pieceBoard[move.target.row][move.target.col]);
    }
}

//Gets Potential moves, checks if they are legal
//If they are legal pushes back to legal targets
std::vector<Square> Chess::getLegalMovesFromSquare(const Square& start) {
    std::vector<Square> potentialTargets = getPotentialMovesFromSquare(start);
    std::vector<Square> legalTargets;
    for (int i=0; i < potentialTargets.size(); i++) {
        Move potentialMove;
        potentialMove.start = start;
        potentialMove.target = potentialTargets[i];
        if (checkLegalMove(potentialMove)) {
            legalTargets.push_back(potentialTargets[i]);
        }
    }
    return legalTargets;
}

//checks if input move is contained in legal targets
bool Chess::isLegalMove(Move &move) {
    std::vector<Square> legalTargets = getLegalMovesFromSquare(move.start);
    for (int i=0; i<legalTargets.size(); i++) {
        if (move.target == legalTargets[i]) {
            move.target = legalTargets[i];
            return true;
        }
    }
    return false;
}

//Only called when move is legal
void Chess::makeMove(Move &move) {
    processMove(move);
    prepareBoardToDraw();
}

std::vector<Square> Chess::getPotentialMovesFromSquare(const Square &start) {
    std::vector<Square> potentialMoves;
    char startColor = pieceBoard[start.row][start.col]->getColor();
    char oppositeColor;

    if (startColor == 'W') {
        oppositeColor = 'B';
    }
    else if (startColor == 'B') {
        oppositeColor = 'W';
    }
    else {
        oppositeColor = startColor;
    }

    potentialMoves = pieceBoard[start.row][start.col]->getTargetSquares(start, pieceBoard, startColor, oppositeColor, moves.back());
    return potentialMoves;
}

Square Chess::findKing(char teamColor) const {
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (pieceBoard[i][j]->getColor() == teamColor && pieceBoard[i][j]->getPieceType() == KING) {
                return {i,j};
            }
        }
    }
    return {};
}

void Chess::enPassant(const Square &target, char pieceColor) {
    if (pieceColor == 'W') {
        pieceBoard[target.row+1][target.col] = &emptyPiece;
    }
    else if (pieceColor == 'B') {
        pieceBoard[target.row- 1][target.col] = &emptyPiece;
    }
}

void Chess::castle(const Square &target, char color) {
    if (color == 'W') {
        if (target.col == 6) {
            pieceBoard[7][5] = pieceBoard[7][7];
            pieceBoard[7][7] = &emptyPiece;
            pieceBoard[7][5]->setHasMoved(true);
        }
        else if (target.col == 2) {
            pieceBoard[7][3] = pieceBoard[7][0];
            pieceBoard[7][0] = &emptyPiece;
            pieceBoard[7][3]->setHasMoved(true);
        }
    }
    else if (color == 'B') {
        if (target.col == 6) {
            pieceBoard[0][5] = pieceBoard[0][7];
            pieceBoard[0][7] = &emptyPiece;
            pieceBoard[0][5]->setHasMoved(true);
        }
        else if (target.col == 2) {
            pieceBoard[0][3] = pieceBoard[0][0];
            pieceBoard[0][0] = &emptyPiece;
            pieceBoard[0][3]->setHasMoved(true);
        }
    }
}

void Chess::undoMove() {
    if (previousPositions.size() > 1) {
        Move lastMove = moves.back();
        pieceBoard = previousPositions.back();
        previousPositions.pop_back();
        moves.pop_back();

        //Handle Move Flags for Castle
        if (lastMove.target.castle) {
            //Undo White Castle
            if (lastMove.target.row == 7) {
                if (lastMove.target.col == 6) {
                    pieceBoard[7][4]->setHasMoved(false);
                    pieceBoard[7][7]->setHasMoved(false);
                }
                else if (lastMove.target.col == 2) {
                    pieceBoard[7][4]->setHasMoved(false);
                    pieceBoard[7][0]->setHasMoved(false);
                }
            }
            //Undo Black Castle
            if (lastMove.target.row == 0) {
                if (lastMove.target.col == 6) {
                    pieceBoard[0][4]->setHasMoved(false);
                    pieceBoard[0][7]->setHasMoved(false);
                }
                else if (lastMove.target.col == 2) {
                    pieceBoard[0][4]->setHasMoved(false);
                    pieceBoard[0][0]->setHasMoved(false);
                }
            }
        }

        //Undo Rook Flags if has made one move, this is 100% wrong
        if (pieceBoard[lastMove.start.row][lastMove.start.col]->getPieceType() == ROOK) {
            Piece* thisRook = pieceBoard[lastMove.start.row][lastMove.start.col];
            Square positionMovedFrom(lastMove.start);
            if (positionMovedFrom.row == 7 && positionMovedFrom.col == 7) {
                thisRook->setHasMoved(false);
            }
            else if (positionMovedFrom.row == 7 && positionMovedFrom.col == 0) {
                thisRook->setHasMoved(false);
            }
            else if (positionMovedFrom.row == 0  && positionMovedFrom.col == 0) {
                thisRook->setHasMoved(false);
            }
            else if (positionMovedFrom.row == 0 && positionMovedFrom.col == 7) {
                thisRook->setHasMoved(false);
            }
        }

        //Undo Kings flags if king was last to move
        if (pieceBoard[lastMove.start.row][lastMove.start.col]->getPieceType() == KING) {
            Piece *thisKing = pieceBoard[lastMove.start.row][lastMove.start.col];
            Square positionMovedFrom(lastMove.start);
            if (positionMovedFrom.row == 0 && positionMovedFrom.col == 4) {
                thisKing->setHasMoved(false);
            } else if (positionMovedFrom.row == 7 && positionMovedFrom.col == 4) {
                thisKing->setHasMoved(false);
            }
        }

        if (pieceBoard[lastMove.start.row][lastMove.start.col]->getPieceType() == PAWN) {
            if (abs(lastMove.start.row - lastMove.target.row) == 2) {
                Pawn *thisPawn = dynamic_cast<Pawn *>(pieceBoard[lastMove.start.row][lastMove.start.col]);
                thisPawn->setHasDoubledMoved(false);
            }
        }
        prepareBoardToDraw();
    }
}

std::vector<std::vector<Square>> Chess::getAllAttacking(char teamColor) {
    std::vector<std::vector<Square>> attacking;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pieceBoard[i][j]->getColor() == teamColor) {
                std::vector<Square> currentSquaresAttacking;
                if (pieceBoard[i][j]->getPieceType() == PAWN) {
                    Pawn *thisPawn = dynamic_cast<Pawn *>(pieceBoard[i][j]);
                    currentSquaresAttacking = thisPawn->getAttackingSquares({i,j},pieceBoard);
                    attacking.push_back(currentSquaresAttacking);
                }
                else {
                    currentSquaresAttacking = getPotentialMovesFromSquare({i, j});
                    attacking.push_back(currentSquaresAttacking);
                }
            }
        }
    }
    return attacking;
}

int Chess::numMovesAvailable(char teamColor) {
    int numMoves = 0;
    std::vector<Square> possibleTargets;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (pieceBoard[i][j]->getColor() == teamColor) {
                possibleTargets = getLegalMovesFromSquare({i,j});
                numMoves += possibleTargets.size();
            }
        }
    }
    return numMoves;
}

bool Chess::blackIsCheckmated() {
    int numBlackMovesAvailable = numMovesAvailable('B');
    if (numBlackMovesAvailable == 0 && isKingAttacked('B')) {
        return true;
    }
    return false;
}

bool Chess::whiteIsCheckmated() {
    int numWhiteMovesAvailable = numMovesAvailable('W');
    if (numWhiteMovesAvailable == 0 && isKingAttacked('W')) {
        return true;
    }
    return false;
}

bool Chess::stalemate() {
    int numBlackMovesAvailable = numMovesAvailable('B');
    int numWhiteMovesAvailable = numMovesAvailable('W');
    bool isWhiteKingAttacked = isKingAttacked('W');
    bool isBlackKingAttacked = isKingAttacked('B');

    if ((numWhiteMovesAvailable == 0 && !isWhiteKingAttacked) || (numBlackMovesAvailable == 0 && !isBlackKingAttacked)) {
        return true;
    }
    return false;
}

bool Chess::isClickedOnWhitePiece(const Square &start) {
    if (pieceBoard[start.row][start.col]->getColor() == 'W')
        return true;
    return false;
}



















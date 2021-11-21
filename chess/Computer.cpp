#include "Chess.h"

int Chess::evaluate(char teamColor) {
    int evaluation = 0;
    int whiteEval = countMaterial('W');
    int blackEval = countMaterial('B');

    if (teamColor == 'W')
        evaluation = whiteEval-blackEval;
    else if (teamColor == 'B')
        evaluation = blackEval-whiteEval;

    return evaluation;
}

int Chess::countMaterial(char teamColor) {
    int materialValue = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (pieceBoard[i][j]->getColor() == teamColor) {
                int piece = pieceBoard[i][j]->getPieceType();
                if (piece == PAWN)
                    materialValue += pawnValue;
                else if (piece == KNIGHT)
                    materialValue += knightValue;
                else if (piece == BISHOP)
                    materialValue += bishopValue;
                else if (piece == ROOK)
                    materialValue += rookValue;
                else if (piece == QUEEN)
                    materialValue += queenValue;
            }
        }
    }
    return materialValue;
}

int count = 0;

Move Chess::getComputerMove(bool test) {
    std::vector<Move> allPossibleMoves;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (pieceBoard[i][j]->getColor() == 'B') {
                std::vector<Square> movesFromSquare = getLegalMovesFromSquare({i,j});
                for (int k=0; k<movesFromSquare.size(); k++) {
                    Square startSquare(i,j);
                    Square targetSquare = movesFromSquare[k];
                    allPossibleMoves.emplace_back(startSquare,targetSquare);
                }
            }
        }
    }
    int randomMove = rand() % allPossibleMoves.size();
    return allPossibleMoves[randomMove];
}

Move Chess::getComputerMove() {
    std::vector<Move> allPossibleMoves;
    Move bestMove;
    int bestMoveValue = INT_MIN;
    //Generate Moves
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (pieceBoard[i][j]->getColor() == 'B') {
                std::vector<Square> movesFromSquare = getLegalMovesFromSquare({i,j});
                for (int k=0; k<movesFromSquare.size(); k++) {
                    Square startSquare(i,j);
                    Square targetSquare = movesFromSquare[k];
                    allPossibleMoves.emplace_back(startSquare,targetSquare);
                }
            }
        }
    }
    //Iterate through moves to find best
    for (int i=0; i<allPossibleMoves.size(); i++) {
        processMove(allPossibleMoves[i]);
        int moveVal = minimax(2, false, INT_MIN, INT_MAX);
        undoMove();
        if (moveVal > bestMoveValue) {
            bestMove = allPossibleMoves[i];
            bestMoveValue = moveVal;
        }
    }
    std::cout << "Num Moves Checked: " << count << std::endl;
    return bestMove;
}

int Chess::minimax(int depth, bool isMax, int alpha, int beta) {
    char teamColor = 'B';
    if (isMax)
        teamColor == 'W';

    std::vector<Move> allPossibleMoves;
    int score = evaluate(teamColor);
    if (depth == 0) {
        return score;
    }
    if (stalemate()) {
        return 0;
    }
    if (blackIsCheckmated()) {
        return INT_MIN;
    }
    if (whiteIsCheckmated()) {
        return INT_MAX;
    }
    if (isMax) {
        int best = INT_MIN;
        //Generate Moves //TRIPLE NESTED FOR LOOP? Has to be better
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                if (pieceBoard[i][j]->getColor() == 'B') {
                    std::vector<Square> movesFromSquare = getLegalMovesFromSquare({i,j});
                    for (int k=0; k<movesFromSquare.size(); k++) {
                        Square startSquare(i,j);
                        Square targetSquare = movesFromSquare[k];
                        allPossibleMoves.emplace_back(startSquare,targetSquare);
                    }
                }
            }
        }
        for (int i=0; i<allPossibleMoves.size(); i++) {
            processMove(allPossibleMoves[i]);
            best = std::max(best, minimax(depth-1, !isMax, alpha, beta));
            undoMove();
            alpha = std::max(alpha, best);
            if (alpha >= beta) {
                break;
            }
        }
        count++;
        return best;
    }
    else {
        int best = INT_MAX;
        //Generate Moves
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                if (pieceBoard[i][j]->getColor() == 'W') {
                    std::vector<Square> movesFromSquare = getLegalMovesFromSquare({i,j});
                    for (int k=0; k<movesFromSquare.size(); k++) {
                        Square startSquare(i,j);
                        Square targetSquare = movesFromSquare[k];
                        allPossibleMoves.emplace_back(startSquare,targetSquare);
                    }
                }
            }
        }
        for (int i=0; i<allPossibleMoves.size(); i++) {
            processMove(allPossibleMoves[i]);
            best = std::min(best, minimax(depth-1, !isMax, alpha, beta));
            undoMove();
            beta = std::min(beta, best);
            if (alpha >= beta) {
                break;
            }
        }
        count++;
        return best;
    }
}

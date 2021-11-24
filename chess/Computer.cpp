#include <random>

#include "Chess.h"



int Chess::evaluate() {
    MaterialCountEvaluation materialEvals = countMaterial();
    int evaluation = materialEvals.blackEval - materialEvals  .whiteEval;

    return evaluation;
}

MaterialCountEvaluation Chess::countMaterial() {
    MaterialCountEvaluation evals;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (pieceBoard[i][j]->getPieceType() != EMPTY) {
                Piece* curPiece = pieceBoard[i][j];
                int piece = curPiece->getPieceType();
                if (piece == PAWN) {
                    if (curPiece->getColor() == 'W')
                        evals.whiteEval += pawnValue;
                    else if (curPiece->getColor() == 'B')
                        evals.blackEval += pawnValue;
                }
                else if (piece == KNIGHT) {
                    if (curPiece->getColor() == 'W')
                        evals.whiteEval += knightValue;
                    else if (curPiece->getColor() == 'B')
                        evals.blackEval += knightValue;
                }
                else if (piece == BISHOP) {
                    if (curPiece->getColor() == 'W')
                        evals.whiteEval += bishopValue;
                    else if (curPiece->getColor() == 'B')
                        evals.blackEval += bishopValue;
                }
                else if (piece == ROOK) {
                    if (curPiece->getColor() == 'W')
                        evals.whiteEval += rookValue;
                    else if (curPiece->getColor() == 'B')
                        evals.blackEval += rookValue;
                }
                else if (piece == QUEEN) {
                    if (curPiece->getColor() == 'W')
                        evals.whiteEval += queenValue;
                    else if (curPiece->getColor() == 'B')
                        evals.blackEval += queenValue;
                }
            }
        }
    }
    return evals;
}

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
    auto start = std::chrono::steady_clock::now();
    std::vector<Move> allPossibleMoves = getAllPossibleMoves('B');
    Move bestMove;
    int bestMoveValue = INT_MIN;

    //Iterate through moves to find best
    for (int i=0; i<allPossibleMoves.size(); i++) {
        makeMove(allPossibleMoves[i]);
        int moveVal = minimax(2, false, INT_MIN, INT_MAX);
        undoMove();
        if (moveVal > bestMoveValue) {
            bestMove = allPossibleMoves[i];
            bestMoveValue = moveVal;
        }
    }
    auto end = std::chrono::steady_clock::now();
    std::cout << "Elapsed Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << " milliseconds." << std::endl;
    return bestMove;
}

int Chess::minimax(int depth, bool isMax, int alpha, int beta) {
    char teamColor = 'E';
    if (isMax)
        teamColor = 'B';

    std::vector<Move> allPossibleMoves;
    int score = evaluate();
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
        allPossibleMoves = getAllPossibleMoves('B');

        for (int i=0; i<allPossibleMoves.size(); i++) {
            makeMove(allPossibleMoves[i]);
            best = std::max(best, minimax(depth-1, false, alpha, beta));
            undoMove();
            alpha = std::max(alpha, best);
            if (alpha >= beta) {
                return best;
            }
        }
        return best;
    }
    else {
        int best = INT_MAX;
        allPossibleMoves = getAllPossibleMoves('W');

        for (int i=0; i<allPossibleMoves.size(); i++) {
            makeMove(allPossibleMoves[i]);
            best = std::min(best, minimax(depth-1, true, alpha, beta));
            undoMove();
            beta = std::min(beta, best);
            if (alpha >= beta) {
                return best;
            }
        }
        return best;
    }
}

std::vector<Move> Chess::getAllPossibleMoves(char teamColor) {
    std::vector<Move> allPossibleMoves;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (pieceBoard[i][j]->getColor() == teamColor) {
                std::vector<Square> movesFromSquare = getLegalMovesFromSquare({i,j});
                for (int k=0; k<movesFromSquare.size(); k++) {
                    Square startSquare(i,j);
                    Square targetSquare = movesFromSquare[k];
                    allPossibleMoves.emplace_back(startSquare,targetSquare);
                }
            }
        }
    }
    return allPossibleMoves;
}

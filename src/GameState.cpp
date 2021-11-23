#include "GameState.h"
#include "GameOverState.h"

GameState::GameState(gameDataRef inData) : data(std::move(inData)), chess(inData) {}

void GameState::init() {}

void GameState::handleInput() {
    if (chess.whiteIsCheckmated()) {
        data->machine.addState(stateRef(new GameOverState(data,'B')), true);
    }
    else if (chess.blackIsCheckmated()) {
        data->machine.addState(stateRef(new GameOverState(data,'W')), true);
    }
    else if (chess.stalemate()) {
        data->machine.addState(stateRef(new GameOverState(data,'S')), true);
    }
    else if (isPlayerTurn) {
        sf::Event event;
        while (data->window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    data->window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    mouseClickPos = sf::Mouse::getPosition(data->window);
                    chess.drawLegalMoves({mouseClickPos.y/100,mouseClickPos.x/100});
                    break;
                case sf::Event::MouseButtonReleased:
                    mouseReleasePos = sf::Mouse::getPosition(data->window);
                    if (mouseClickPos != mouseReleasePos) {
                        int startRow, startCol, endRow, endCol;
                        startRow = int(mouseClickPos.y / 100);
                        startCol = int(mouseClickPos.x / 100);
                        endRow = int(mouseReleasePos.y / 100);
                        endCol = int(mouseReleasePos.x / 100);
                        if (chess.isClickedOnWhitePiece({startRow,startCol})) {
                            Move desiredMove = {{startRow,startCol},{endRow,endCol}};
                            if (chess.isLegalMove(desiredMove)) {
                                chess.makeMove(desiredMove);
                                isPlayerTurn = !isPlayerTurn;
                            }
                        }
                    }
                    chess.drawCleanBoard();
                    break;
                case sf::Event::KeyPressed:
                    int numPositions = chess.moveGenererationTest(1);
                    std::cout << "Num Possible Positions: " << numPositions << std::endl;
                    break;
            }
        }
    }
    else {
        Move computerMove = chess.getComputerMove(true);
        chess.makeMove(computerMove);
        isPlayerTurn = !isPlayerTurn;
    }
}

void GameState::update() {}

void GameState::draw() {
    data->window.clear(sf::Color::Black);
    data->window.draw(chess);
    data->window.display();
}

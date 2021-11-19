#include "GameState.h"
#include "Definitions.h"

GameState::GameState(gameDataRef inData) : data(std::move(inData)), chess(inData) {}

void GameState::init() {

}

void GameState::handleInput() {
    sf::Event event;
    while (data->window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                data->window.close();
                break;
            case sf::Event::MouseButtonPressed:
                mouseClickPos = sf::Mouse::getPosition(data->window);
                break;
            case sf::Event::MouseButtonReleased:
                mouseReleasePos = sf::Mouse::getPosition(data->window);
                if (mouseClickPos.x != 0 && mouseClickPos.y != 0 && mouseReleasePos.x != 4 && mouseReleasePos.y != 2) {
                    int startRow, startCol, endRow, endCol;
                    startRow = int(mouseClickPos.y / 100);
                    startCol = int(mouseClickPos.x / 100);
                    endRow = int(mouseReleasePos.y / 100);
                    endCol = int(mouseReleasePos.x / 100);
                    Move desiredMove = {{startRow,startCol},{endRow,endCol}};
                    chess.processPlayerMove(desiredMove);
                }
                break;
        }
    }

}

void GameState::update() {

}

void GameState::draw() {
    data->window.clear(sf::Color::Black);
    data->window.draw(chess);
    data->window.display();
}

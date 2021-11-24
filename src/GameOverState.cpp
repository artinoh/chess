#include "GameOverState.h"

#include <utility>
#include "GameState.h"
#include "Definitions.h"

GameOverState::GameOverState(gameDataRef inData, char result) : data(std::move(inData)), gameResult(result) {}

void GameOverState::init() {
    background.setTexture(data->assets.getTexture("Background"));
    playAgainButton.setTexture(data->assets.getTexture("Play Again"));
    quitButton.setTexture(data->assets.getTexture("Quit Button"));

    if (gameResult == 'W')
        gameResultSprite.setTexture(data->assets.getTexture("White Won"));
    else if (gameResult == 'B')
        gameResultSprite.setTexture(data->assets.getTexture("Black Won"));
    else if (gameResult == 'S')
        gameResultSprite.setTexture(data->assets.getTexture("Stalemate"));
    else
        gameResultSprite.setTexture(data->assets.getTexture("Empty Square"));

    this->playAgainButton.setPosition((SCREEN_WIDTH/2)-(this->playAgainButton.getGlobalBounds().width*1.25),(SCREEN_HEIGHT/2)-(this->playAgainButton.getGlobalBounds().height/2));
    this->quitButton.setPosition((SCREEN_WIDTH / 2) + (this->quitButton.getGlobalBounds().width * .25), (SCREEN_HEIGHT / 2) - (this->quitButton.getGlobalBounds().height / 2));
    this->gameResultSprite.setPosition((SCREEN_WIDTH/2)-(this->title.getGlobalBounds().width),this->title.getGlobalBounds().height*0.1);
}

void GameOverState::handleInput() {
    sf::Event event{};
    while (data->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            data->window.close();
        }
        if (data->input.isSpriteClicked(playAgainButton, sf::Mouse::Left, data->window)) {
            data->machine.addState(stateRef(new GameState(data)), false);
        }
        if (data->input.isSpriteClicked(quitButton, sf::Mouse::Left, data->window)) {
            data->window.close();
        }
    }
}

void GameOverState::update() {

}

void GameOverState::draw() {
    data->window.clear(sf::Color::Black);
    data->window.draw(background);
    data->window.draw(gameResultSprite);
    data->window.draw(quitButton);
    data->window.draw(playAgainButton);
    data->window.display();
}

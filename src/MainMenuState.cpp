#include "MainMenuState.h"
#include "GameState.h"
#include "Definitions.h"

MainMenuState::MainMenuState(gameDataRef inData) : data(std::move(inData)) {}

void MainMenuState::init() {
    title.setTexture(data->assets.getTexture(("Title")));
    background.setTexture(data->assets.getTexture("Background"));
    playButton.setTexture(data->assets.getTexture("Play Button"));
    exitButton.setTexture(data->assets.getTexture("Exit Button"));

    this->playButton.setPosition((SCREEN_WIDTH/2)-(this->playButton.getGlobalBounds().width*1.25),(SCREEN_HEIGHT/2)-(this->playButton.getGlobalBounds().height/2));
    this->exitButton.setPosition((SCREEN_WIDTH/2)+(this->exitButton.getGlobalBounds().width*.25),(SCREEN_HEIGHT/2)-(this->exitButton.getGlobalBounds().height/2));
    this->title.setPosition((SCREEN_WIDTH/2)-(this->title.getGlobalBounds().width/2),this->title.getGlobalBounds().height*0.1);

}

void MainMenuState::handleInput() {
    sf::Event event;
    while (data->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            data->window.close();
        }
        if (data->input.isSpriteClicked(playButton, sf::Mouse::Left, data->window)) {
            data->machine.addState(stateRef(new GameState(data)), false);
        }
        if (data->input.isSpriteClicked(exitButton, sf::Mouse::Left, data->window)) {
            data->window.close();
        }
    }
}

void MainMenuState::update() {

}

void MainMenuState::draw() {
    data->window.clear(sf::Color::Black);
    data->window.draw(background);
    data->window.draw(playButton);
    data->window.draw(exitButton);
    data->window.draw(title);
    data->window.display();
}

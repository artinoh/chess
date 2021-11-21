#ifndef CHESS_V2_MAINMENUSTATE_H
#define CHESS_V2_MAINMENUSTATE_H

#include "Game.h"
#include "State.h"

class MainMenuState : public State {

private:
    gameDataRef data;
    sf::Sprite background;
    sf::Sprite playButton;
    sf::Sprite title;
    sf::Sprite quitButton;

public:
    MainMenuState() = default;
    explicit MainMenuState(gameDataRef inData);
    void init() override;
    void handleInput() override;
    void update() override;
    void draw() override;

};

#endif //CHESS_V2_MAINMENUSTATE_H

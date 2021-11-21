#ifndef CHESS_V2_GAMEOVERSTATE_H
#define CHESS_V2_GAMEOVERSTATE_H

#include "State.h"
#include "Game.h"
#include "Definitions.h"

class GameOverState : public State {

private:
    gameDataRef data;
    char gameResult{};
    sf::Sprite background;
    sf::Sprite playAgainButton;
    sf::Sprite gameResultSprite;
    sf::Sprite title;
    sf::Sprite quitButton;

public:
    GameOverState() = default;
    GameOverState(gameDataRef inData, char result);
    void init() override;
    void handleInput() override;
    void update() override;
    void draw() override;
};


#endif //CHESS_V2_GAMEOVERSTATE_H

#ifndef CHESS_V2_GAMESTATE_H
#define CHESS_V2_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include "Game.h"
#include "State.h"
#include "Chess.h"

#include <iostream>


class GameState : public State {

private:
    gameDataRef data;
    Chess chess;
    sf::Vector2i mouseClickPos;
    sf::Vector2i mouseReleasePos;

    bool isPlayerTurn = true;

public:
    GameState() = default;
    explicit GameState(gameDataRef inData);
    void init();
    void handleInput();
    void update();
    void draw();

};


#endif //CHESS_V2_GAMESTATE_H

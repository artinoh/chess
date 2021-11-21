#ifndef CHESS_V2_GAME_H
#define CHESS_V2_GAME_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "Definitions.h"

struct GameData {
    sf::RenderWindow window;
    StateMachine machine;
    AssetManager assets;
    InputManager input;
};

using gameDataRef = std::shared_ptr<GameData>;

class Game {

private:
    gameDataRef data = std::make_shared<GameData>();
    void init();
    void run();
    void loadMainMenuAssets();
    void loadGameOverAssets();
    void loadPieceAssets();
    void loadOtherAssets();

public:
    Game();
};


#endif //CHESS_V2_GAME_H

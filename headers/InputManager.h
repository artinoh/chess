#ifndef CHESS_V2_INPUTMANAGER_H
#define CHESS_V2_INPUTMANAGER_H


#include <SFML/Graphics.hpp>
#include "Definitions.h"

class InputManager {

private:

public:
    InputManager() = default;
    ~InputManager() = default;

    bool isSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow& window);
    sf::Vector2i getMousePosition(sf::RenderWindow& window) const;

};


#endif //CHESS_V2_INPUTMANAGER_H

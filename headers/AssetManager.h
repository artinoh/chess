#ifndef CHESS_V2_ASSETMANAGER_H
#define CHESS_V2_ASSETMANAGER_H


#include <map>
#include <SFML/Graphics.hpp>

class AssetManager {

private:
    static std::map<std::string, sf::Texture> textures;
public:
    AssetManager() = default;
    ~AssetManager() = default;

    void loadTexture(const std::string& name, const std::string& fileName);
    void loadTexture(const std::string& name, const sf::Texture& texture);
    sf::Texture &getTexture(const std::string& name) const;
};


#endif //CHESS_V2_ASSETMANAGER_H

#include "AssetManager.h"

std::map<std::string, sf::Texture> AssetManager::textures;

void AssetManager::loadTexture(const std::string &name, const std::string &fileName) {
    sf::Texture texture;
    if (texture.loadFromFile(fileName)) {
        textures[name] = texture;
    }
}

void AssetManager::loadTexture(const std::string &name, const sf::Texture& texture) {
    textures[name] = texture;
}

sf::Texture &AssetManager::getTexture(const std::string &name) const {
    return textures[name];
}
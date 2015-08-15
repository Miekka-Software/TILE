#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <string>

class Tile {
public:
    static std::vector<sf::Vector2f> expandCoords(sf::Vector2f, int);
    sf::Vector2f size;
    sf::Vector2f position;
    int tex;
};

class TileSet {
    public:
        TileSet(std::string);
        std::vector<sf::Vector2f> getTile(std::string);
        sf::Texture setTexture;
    private:
        int xSetSize;
        int ySetSize;
        int tileSize;
        std::string imageFile;
        std::vector<std::string> ids;
        std::map<std::string,sf::Vector2f> Set;
};

#endif

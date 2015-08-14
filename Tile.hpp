#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile {
public:
    static std::vector<sf::Vector2f> expandCoords(sf::Vector2f, float);
    sf::Vector2f size;
    sf::Vector2f position;
    int tex;
};

/*class TileSet {
    public:
        void TileSet();
}*/

#endif

#include <SFML/Graphics.hpp>
#include "Tile.hpp"
using namespace sf;

std::vector<Vector2f> Tile::expandCoords(Vector2f coord, float tileSize) {
    std::vector<Vector2f> tileCoords;
    tileCoords.push_back(coord);
    tileCoords.push_back(Vector2f(coord.x + tileSize, coord.y));
    tileCoords.push_back(Vector2f(coord.x + tileSize, coord.y + tileSize));
    tileCoords.push_back(Vector2f(coord.x, coord.y + tileSize));
    return tileCoords;
}

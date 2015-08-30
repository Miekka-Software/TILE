#include "Animate.hpp"
#include "Tile.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;

Entity::Entity(std::string file, Vector2f texsize, Vector2f spritesize) {
    if (!tex.loadFromFile(file)) {
        std::cout << "ERROR: Failed to load Entity Texture.\n";
        exit(-1);
    }
    vArray.resize(4);
    vArray.setPrimitiveType(Quads);
    auto pnts = Tile::expandCoords(Vector2f(0,0), spritesize);
    for(int i = 0; i < 4; ++i) {
        vArray[i].position = pnts[i];
    }
    auto texps = Tile::expandCoords(Vector2f(0,0), texsize);
    for(int i = 0; i < 4; ++i) {
        vArray[i].texCoords = texps[i];
    }
}

void Entity::moveEntity(float x, float y) {
    if (y < 0) {
        dir = Up;
    }
    else if (x > 0) {
        dir = Right;
    }
    else if (y > 0) {
        dir = Down;
    }
    else if (x < 0) {
        dir = Left;
    }
    this->move(x,y);
}

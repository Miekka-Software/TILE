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
    sprite.setTexture(tex);
    sprite.setTextureRect(IntRect(0,0,texsize.x,texsize.y));
    Vector2f scaleFactors = Vector2f(spritesize.x/texsize.x, spritesize.y/texsize.y);
    sprite.setScale(scaleFactors);
}

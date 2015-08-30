#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Tile.hpp"
#include "Animate.hpp"
using namespace std;

/*
*Todo:
*   1. Add comments to distinguish parts of the code.
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "TILE Dev Testing");
    TileSet ts("tileset.json");
    TileMap tm("levelmap.json", &ts);
    Entity ch("tilegrid.png", sf::Vector2f(64,64), sf::Vector2f(128,128));

    int speed = 1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            ch.moveEntity(-speed,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            ch.moveEntity(speed,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            ch.moveEntity(0,-speed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            ch.moveEntity(0,speed);
        }

        window.clear();
        window.draw(tm);
        window.draw(ch);
        window.display();
    }

    return 0;
}

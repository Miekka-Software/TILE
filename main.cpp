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
    window.setFramerateLimit(60);
    TileSet ts("tileset.json");
    TileMapL tm("levelmap.json", &ts);
    AnimateL<Entity> al;
    al.addEntity(Entity("tilegrid.png", sf::Vector2f(64,64), sf::Vector2f(128,128)));
    al.addEntity(Entity("tilegrid.png", sf::Vector2f(32,32), sf::Vector2f(128,128)));

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
            al[0].move(-speed,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            al[0].move(speed,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            al[0].move(0,-speed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            al[0].move(0,speed);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            al[1].move(-speed,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            al[1].move(speed,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            al[1].move(0,-speed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            al[1].move(0,speed);
        }

        window.clear();
        window.draw(tm);
        window.draw(al);
        window.display();
    }

    return 0;
}

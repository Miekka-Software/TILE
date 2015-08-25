#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Tile.hpp"
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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(tm);
        window.display();
    }

    return 0;
}

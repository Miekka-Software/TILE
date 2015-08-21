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
    sf::VertexArray aquad(sf::Quads, 8);
    aquad[0].position = sf::Vector2f(0,0);
    aquad[0].color = sf::Color::Red;
    aquad[1].position = sf::Vector2f(0,50);
    aquad[2].position = sf::Vector2f(50,50);
    aquad[3].position = sf::Vector2f(50,0);
    aquad[4].position = sf::Vector2f(100,100);
    aquad[5].position = sf::Vector2f(100,150);
    aquad[6].position = sf::Vector2f(150,150);
    aquad[7].position = sf::Vector2f(150,100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(aquad);
        window.display();
    }

    return 0;
}

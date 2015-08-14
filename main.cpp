#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tile.hpp"
using namespace std;

int main()
{
    auto v = Tile::expandCoords(sf::Vector2f(50,50), 100);

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::VertexArray quad(sf::Quads, 4);
    quad[0].position = v[0];
    quad[1].position = v[1];
    quad[2].position = v[2];
    quad[3].position = v[3];

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(quad);
        window.display();
    }

    return 0;
}

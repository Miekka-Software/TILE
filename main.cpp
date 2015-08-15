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

    TileSet tileset("tileset.json");
    auto a = tileset.getTile("grass");
    auto b = tileset.getTile("dirt");
    auto c = tileset.getTile("stone");
    auto d = tileset.getTile("sponge");

    sf::RenderWindow window(sf::VideoMode(600, 600), "TILE Dev Testing");
    sf::VertexArray aquad(sf::Quads, 4);
    aquad[0].position = a[0];
    aquad[0].color = sf::Color::Red;
    aquad[1].position = a[1];
    aquad[2].position = a[2];
    aquad[3].position = a[3];
    sf::VertexArray bquad(sf::Quads, 4);
    bquad[0].position = b[0];
    bquad[0].color = sf::Color::Blue;
    bquad[1].position = b[1];
    bquad[2].position = b[2];
    bquad[3].position = b[3];
    sf::VertexArray cquad(sf::Quads, 4);
    cquad[0].position = c[0];
    cquad[0].color = sf::Color::Green;
    cquad[1].position = c[1];
    cquad[2].position = c[2];
    cquad[3].position = c[3];
    sf::VertexArray dquad(sf::Quads, 4);
    dquad[0].position = d[0];
    dquad[0].color = sf::Color::Yellow;
    dquad[1].position = d[1];
    dquad[2].position = d[2];
    dquad[3].position = d[3];

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
        window.draw(bquad);
        window.draw(cquad);
        window.draw(dquad);
        window.display();
    }

    return 0;
}

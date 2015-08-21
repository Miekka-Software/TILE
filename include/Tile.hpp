#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <string>

class Tile {
    public:
        Tile();
        void setPostion(std::vector<sf::Vector2f>);
        void setTile(std::vector<sf::Vector2f>);
        void toggleCollide();
        sf::VertexArray returnVArray();
        static std::vector<sf::Vector2f> expandCoords(sf::Vector2f, int);
    private:
        bool collide;
        sf::VertexArray verts;
};

class TileSet {
    public:
        TileSet(std::string);
        std::vector<sf::Vector2f> getTile(std::string);
        sf::Texture setTexture;
    private:
        int xSetSize;
        int ySetSize;
        int tileSize;
        std::string imageFile;
        std::vector<std::string> ids;
        std::map<std::string,sf::Vector2f> Set;
};

class TileMap : public sf::Drawable, public sf::Transformable {
    public:
        TileMap(std::string, TileSet&);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &tSet.setTexture;
        target.draw(vArray, states);
    }
    int xLevSize;
    int yLevSize;
    int tileSize;
    sf::VertexArray vArray;
    TileSet& tSet;
};

#endif

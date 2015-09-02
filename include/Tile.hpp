#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <json/json.h>
#include <string>

class Tile {
    public:
        Tile();
        void setPostion(sf::Vector2f);
        void setTile(std::vector<sf::Vector2f>);
        void toggleCollide();
        int size;
        sf::VertexArray returnVArray();
        static std::vector<sf::Vector2f> expandCoords(sf::Vector2f, int);
        static std::vector<sf::Vector2f> expandCoords(sf::Vector2f, sf::Vector2f);
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

class TileMapL : public sf::Drawable, public sf::Transformable {
    public:
        TileMapL(std::string, TileSet*);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &tSet->setTexture;
        target.draw(vArray, states);
        }
        void push_tile(Tile);
        int xLevSize;
        int yLevSize;
        int tileSize;
        sf::VertexArray vArray;
        std::vector<Json::Value> tiles;
        TileSet* tSet;
};

#endif

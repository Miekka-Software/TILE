#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Tile.hpp"
#include <json/json.h>
using namespace sf;

std::vector<Vector2f> Tile::expandCoords(Vector2f coord, int ts) {
    std::vector<Vector2f> tileCoords;
    tileCoords.push_back(coord);
    tileCoords.push_back(Vector2f(coord.x, coord.y + ts));
    tileCoords.push_back(Vector2f(coord.x + ts, coord.y + ts));
    tileCoords.push_back(Vector2f(coord.x + ts, coord.y));
    return tileCoords;
}

TileSet::TileSet(std::string file) {
    std::ifstream datFile(file);
    if (datFile.is_open()) {
        Json::Value dat;
        datFile >> dat;
        xSetSize = dat.get("xSetSize", 0).asInt();
        ySetSize = dat.get("ySetSize", 0).asInt();
        tileSize = dat.get("tileSize", 0).asInt();
        imageFile = dat.get("imageFile", "").asString();
        Json::Value idsVal = dat["ids"];
        for(unsigned int itr = 0; itr < idsVal.size(); ++itr) {
            ids.push_back(idsVal[itr].asString());
        }
        std::reverse(ids.begin(), ids.end());
        if(!setTexture.loadFromFile(imageFile)){
            std::cout << "ERROR: Failed to load Tileset Image.\n";
            exit(-1);
        }
        for(int yi = 0; yi < ySetSize; ++yi){
            for(int xi = 0; xi < xSetSize; ++xi){
                if(!(ids.size() > 0)) {
                    break;
                }
                Set[ids.back()] = Vector2f(xi*tileSize,yi*tileSize);
                ids.pop_back();
            }
        }
    }
    else {
        std::cout << "ERROR: Failed to load Tileset Data.\n";
        exit(-1);
    }
}

std::vector<Vector2f> TileSet::getTile(std::string id) {
    auto it = Set.find(id);
    if(!(it == Set.end())) {
        return Tile::expandCoords(it->second, tileSize);
    }
    return Tile::expandCoords(Vector2f(0,0), tileSize);
}
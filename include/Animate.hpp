#ifndef ANIMATE_H
#define ANIMATE_H

#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Drawable, public sf::Transformable {
    public:
        Entity(std::string, sf::Vector2f, sf::Vector2f);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = tex;
        target.draw(vArray, states);
        }
        sf::Texture tex;
        sf::VertexArray vArray;
};

#endif
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
        states.texture = &tex;
        target.draw(vArray, states);
        }
        sf::Texture tex;
        sf::VertexArray vArray;
};

template <class T>
class AnimateL : public sf::Drawable, public sf::Transformable{
    public:
        void addEntity(T);
        T& operator[](unsigned int);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        for (int itr = 0; itr < entities.size(); ++itr) {
            target.draw(entities[itr], states);
        }
        }
        std::vector<T> entities;
};

template <class T>
void AnimateL<T>::addEntity(T entity) {
    entities.push_back(entity);
}

template <class T>
T& AnimateL<T>::operator[](unsigned int i) {
    return entities[i];
}

#endif

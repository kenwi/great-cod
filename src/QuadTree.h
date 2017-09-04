//
// Created by kenwi on 9/4/17.
//

#ifndef GREAT_COD_QUADTREE_H
#define GREAT_COD_QUADTREE_H

#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class QuadTree {

public:
    QuadTree(unsigned int level, sf::RectangleShape bounds, sf::Vector2f position);

    void Split();
    sf::RectangleShape& GetBounds();

private:
    sf::RectangleShape bounds;
    sf::Color outlineColor;
    sf::Color fillColor;
    sf::Vector2f position;
    sf::Vector2f size;

    float outlineThickness;
    bool drawBounds;
    unsigned maxObjects;
    unsigned maxLevels;
    unsigned level;

    std::vector<QuadTree> nodes;
    std::vector<sf::CircleShape> objects;
};


#endif //GREAT_COD_QUADTREE_H

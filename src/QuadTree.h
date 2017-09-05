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

    void Insert(sf::CircleShape shape);
    void Clear();
    void Split();
    sf::RectangleShape& GetBounds();
    std::vector<sf::CircleShape> GetObjects();
    std::vector<QuadTree>& GetNodes();

private:
    int getIndex(sf::CircleShape shape);

    sf::RectangleShape bounds;
    sf::Color outlineColor = sf::Color::White;
    sf::Color fillColor = sf::Color::Black;
    sf::Vector2f position;

    float outlineThickness = 1;
    bool drawBounds = true;
    unsigned maxObjects = 10;
    unsigned maxLevels = 5;
    unsigned level = 0;

    std::vector<QuadTree> nodes;
    std::vector<sf::CircleShape> objects;
};


#endif //GREAT_COD_QUADTREE_H

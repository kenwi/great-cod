//
// Created by kenwi on 9/4/17.
//

#include <iostream>
#include "QuadTree.h"

QuadTree::QuadTree(unsigned int level, sf::RectangleShape bounds, sf::Vector2f position) {
    this->level = level;
    this->position = position;

    bounds.setPosition(this->position);
    bounds.setOutlineThickness(this->outlineThickness);
    bounds.setFillColor(this->fillColor);
    bounds.setOutlineColor(this->outlineColor);
    this->bounds = bounds;
    std::cout << "Initialized quadtree" << std::endl;
    std::cout << bounds.getPosition().x << ", " << bounds.getPosition().y << std::endl;
}

sf::RectangleShape& QuadTree::GetBounds() {
    return bounds;
}

void QuadTree::Split() {
    std::cout << "Splitting quadtree" << std::endl;
/*
    auto subWidth = bounds.getSize().x / 2;
    auto subHeight = bounds.getSize().y /2;
    auto x = bounds.getPosition().x;
    auto y = bounds.getPosition().y;

    nodes.push_back(QuadTree(level+1, sf::RectangleShape({subWidth, subHeight}), {100, 100}));
    //nodes.push_back(QuadTree(level+1, sf::RectangleShape({subWidth, subHeight}), {x, y}));

    std::cout << "Node count: " << nodes.size() << std::endl;
*/
}



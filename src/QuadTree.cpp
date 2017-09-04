//
// Created by kenwi on 9/4/17.
//

#include <iostream>
#include "QuadTree.h"

QuadTree::QuadTree() {
    std::cout << "Init quadtree" << std::endl;
    QuadTree(1, sf::RectangleShape({100, 100}), {1024/2, 768/2});
}

QuadTree::QuadTree(unsigned int level, sf::RectangleShape bounds,sf::Vector2f position) {
    this->level = level;
    this->bounds = bounds;
    this->position = position;

    outlineThickness = 1;
    outlineColor = sf::Color::White;
    fillColor = sf::Color::Black;
    maxObjects = 10;
    maxLevels = 5;

    bounds.setOutlineThickness(outlineThickness);
    bounds.setOutlineColor(outlineColor);
    bounds.setFillColor(fillColor);
    bounds.setPosition(position);
    bounds.setSize(size);
}

void QuadTree::SetPosition(float x, float y) {
    bounds.setPosition(x, y);
}

sf::RectangleShape QuadTree::GetBounds() {
    return bounds;
}

void QuadTree::Split() {
    std::cout << "Splitting quadtree" << std::endl;

    auto subWidth = bounds.getSize().x / 2;
    auto subHeight = bounds.getSize().y /2;
    auto x = bounds.getPosition().x;
    auto y = bounds.getPosition().y;

    nodes.push_back(QuadTree(level+1, sf::RectangleShape({subWidth, subHeight}), {100, 100}));
    //nodes.push_back(QuadTree(level+1, sf::RectangleShape({subWidth, subHeight}), {x, y}));

    std::cout << "Node count: " << nodes.size() << std::endl;
}

std::vector<QuadTree> QuadTree::GetNodes() {
    return nodes;
}



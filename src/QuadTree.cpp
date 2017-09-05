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
}

sf::RectangleShape& QuadTree::GetBounds() {
    return bounds;
}

void QuadTree::Split() {
    std::cout << "Splitting quadtree" << std::endl;

    auto subWidth = bounds.getSize().x / 2;
    auto subHeight = bounds.getSize().y /2;

    auto padding = 1;
    auto x = bounds.getPosition().x;
    auto y = bounds.getPosition().y;
    auto shape = sf::RectangleShape({subWidth, subHeight});

    nodes.emplace_back(level+1, shape, sf::Vector2<float>(x + subWidth + padding, y - padding));
    nodes.emplace_back(level+1, shape, sf::Vector2<float>(x - padding, y - padding));
    nodes.emplace_back(level+1, shape, sf::Vector2<float>(x - padding, y + subHeight + padding));
    nodes.emplace_back(level+1, shape, sf::Vector2<float>(x + subWidth + padding, y + subHeight + padding));

    std::cout << "Node count: " << nodes.size() << std::endl;
}

std::vector<QuadTree>& QuadTree::GetNodes() {
    return nodes;
}

void QuadTree::Clear() {
    std::cout << "Clearing quadtree" << std::endl;
    objects.clear();
    for(auto& node : nodes) {
        node.nodes.clear();
    }
    nodes.clear();
}



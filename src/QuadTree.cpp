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

void QuadTree::Insert(sf::CircleShape shape) {
    int index = getIndex(shape);
    std::cout << "Index: " << index << std::endl;
    /*
    if(index != -1) {
        nodes[index].Insert(shape);
        return;
    }
    objects.push_back(shape);
    */
    /*objects.push_back(shape);
    if(objects.size() > maxObjects && level > maxLevels) {
        Split();
    }*/
}

int QuadTree::getIndex(sf::CircleShape shape) {
    int index = -1;

    double xMidpoint = bounds.getPosition().x + (bounds.getSize().x / 2);
    double yMidpoint = bounds.getPosition().y + (bounds.getSize().y / 2);

    bool topQuadrant = (shape.getPosition().y < yMidpoint && shape.getPosition().y + shape.getRadius() < yMidpoint);
    bool bottomQuadrant = (shape.getPosition().y > yMidpoint);

    if(shape.getPosition().x < xMidpoint && shape.getPosition().x + shape.getRadius() < xMidpoint) {
        if(topQuadrant) {
            index = 1;
        } else if(bottomQuadrant) {
            index = 2;
        }
    }
    else if(shape.getPosition().x > xMidpoint) {
        if(topQuadrant) {
            index = 0;
        } else if(bottomQuadrant) {
            index = 3;
        }
    }
    return index;
}

std::vector<sf::CircleShape> QuadTree::GetObjects() {
    return objects;
}



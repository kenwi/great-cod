//
// Created by kenwi on 9/1/17.
//

#include <iostream>
#include "Widget.h"

void Widget::render(sf::RenderTarget &renderTarget) {
    sf::RectangleShape shape;
    shape.setSize({100, 100});
    shape.setPosition(0,0);
    shape.setFillColor(sf::Color::White);

    renderTarget.draw(shape);
}

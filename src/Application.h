//
// Created by kenwi on 9/1/17.
//

#ifndef GREAT_COD_APPLICATION_H
#define GREAT_COD_APPLICATION_H

#include <memory>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "RenderContext.h"
#include "QuadTree.h"

class Application {

public:
    Application();
    void Run();

private:
    QuadTree quadTree;
    RenderContext renderContext;
    sf::RenderWindow renderWindow;
    sf::Clock timer;

    void update(sf::Time time);
    void render(sf::Time time);

    void input();
    void handleWindowEvents();
};


#endif //GREAT_COD_APPLICATION_H

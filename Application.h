//
// Created by kenwi on 9/1/17.
//

#ifndef GREAT_COD_APPLICATION_H
#define GREAT_COD_APPLICATION_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "RenderContext.h"

class Application {

public:
    Application();
    void Run();

private:
    RenderContext renderContext;
    sf::RenderWindow renderWindow;
    sf::Clock timer;

    void update(sf::Time time);

    void render(sf::Time time);

    void handleInput();

    void handleWindowInput();
};


#endif //GREAT_COD_APPLICATION_H

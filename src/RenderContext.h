//
// Created by kenwi on 9/1/17.
//

#ifndef GREAT_COD_RENDERCONTEXT_H
#define GREAT_COD_RENDERCONTEXT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Widget.h"

class RenderContext {
public:
    //RenderContext(sf::RenderWindow renderWindow);
    bool Add(std::unique_ptr<Widget>& widget);
    void Render(sf::Time time);

private:
    std::vector<std::unique_ptr<Widget>> widgets;
    sf::RenderWindow renderWindow;
};


#endif //GREAT_COD_RENDERCONTEXT_H

//
// Created by kenwi on 9/1/17.
//

#include "RenderContext.h"

/*
RenderContext::RenderContext(sf::RenderWindow renderWindow) {

}
*/

bool RenderContext::Add(std::unique_ptr<Widget>& widget) {
    auto count = widgets.size();
    widgets.push_back(std::move(widget));
    count != widgets.size();
}

void RenderContext::Render(sf::Time time) {

}


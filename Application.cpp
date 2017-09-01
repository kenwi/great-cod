//
// Created by kenwi on 9/1/17.
//

#include "Application.h"

Application::Application()
:   renderWindow({1024, 768}, "Application")
{
    std::cout << "Init Application" << std::endl;
}

void Application::Run() {
    std::cout << "Run" << std::endl;

    sf::Clock timer;
    auto lastTime = sf::Time::Zero;
    auto lag = sf::Time::Zero;

    while(renderWindow.isOpen()) {
        auto time = timer.getElapsedTime();
        auto dt = time - lastTime;

        // Input, Update, Render
        handleInput();
        update(dt);
        render(dt);

        // Update time
        lastTime = time;
        handleWindowInput();
    }
}

void Application::handleInput() {

}

void Application::update(sf::Time time) {

}

void Application::render(sf::Time time) {
    renderWindow.clear();
    renderContext.Render(time);
    renderWindow.display();
}

void Application::handleWindowInput() {
    sf::Event e;
    while(renderWindow.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                std::cout << "Event closed" << std::endl;
                renderWindow.close();
            default:
                break;
        }
    }
}
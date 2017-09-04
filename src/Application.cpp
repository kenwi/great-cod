//
// Created by kenwi on 9/1/17.
//

#include "Application.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

Application::Application() :
        renderWindow({SCREEN_WIDTH, SCREEN_HEIGHT}, "Application"),
        quadTree(0, sf::RectangleShape({900, 700}), {0, 0})
{
    quadTree.GetBounds().setPosition({
                    SCREEN_WIDTH/2 - quadTree.GetBounds().getSize().x/2,
                    SCREEN_HEIGHT/2 - quadTree.GetBounds().getSize().y/2
            });
    std::cout << "Initialized application" << std::endl;
}

void Application::Run() {
    std::cout << "Run" << std::endl;

    sf::Clock timer;
    auto lastTime = sf::Time::Zero;
    auto lag = sf::Time::Zero;

    while(renderWindow.isOpen()) {
        auto time = timer.getElapsedTime();
        auto dt = time - lastTime;

        // Render
        render(dt);

        // Update time
        lastTime = time;
        handleWindowEvents();
    }
}

void Application::render(sf::Time time) {
    renderWindow.clear();

    renderWindow.draw(quadTree.GetBounds());
    for(auto &node : quadTree.GetNodes()) {
        renderWindow.draw(node.GetBounds());
    }

    renderWindow.display();
}

void Application::handleWindowEvents() {
    sf::Event e;
    while(renderWindow.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:

                std::cout << "Event closed" << std::endl;
                renderWindow.close();
                break;
            case sf::Event::KeyPressed:
                std::cout << "Key pressed: " << e.key.code << std::endl;
                if(e.key.code == sf::Keyboard::Escape) {
                    renderWindow.close();
                }
                if(e.key.code == sf::Keyboard::S) {
                    quadTree.Split();
                }
                break;
            case sf::Event::MouseButtonPressed:
                std::cout << "Mouse event: " << e.mouseButton.button << std::endl;
                break;
            default:
                break;
        }
    }
}
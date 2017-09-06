//
// Created by kenwi on 9/1/17.
//

#include "Application.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define RENDER_WINDOW_WIDTH 900
#define RENDER_WINDOW_HEIGHT 700

Application::Application() :
        renderWindow({SCREEN_WIDTH, SCREEN_HEIGHT}, "Application"),
        quadTree(0, sf::RectangleShape({RENDER_WINDOW_WIDTH, RENDER_WINDOW_HEIGHT}), {0, 0})
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

    for(auto &object : quadTree.GetObjects()) {
        renderWindow.draw(object);
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
                if(e.key.code == sf::Keyboard::C) {
                    quadTree.Clear();
                }
                if(e.key.code == sf::Keyboard::I) {
                    auto nodeCount = quadTree.GetNodes().size();
                    auto objectCount = quadTree.GetObjects().size();
                    auto bounds = quadTree.GetBounds();

                    std::cout << "Node count: " << nodeCount << ", Object count: " << objectCount << std::endl;
                    std::cout << "Bounds: x = " << bounds.getPosition().x << ", y = " << bounds.getPosition().y << std::endl;
                }
                break;

            case sf::Event::MouseButtonPressed:
                if(e.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "Insert at x: " << e.mouseButton.x << ", y: " << e.mouseButton.y << std::endl;

                    auto shape = sf::CircleShape(1);
                    shape.setRadius(10);
                    shape.setPosition(e.mouseButton.x, e.mouseButton.y);
                    quadTree.Insert(shape);
                }
                if(e.mouseButton.button == sf::Mouse::Right) {
                    auto quad = QuadTree(1, sf::RectangleShape({10, 10}), {10, 10});
                    quadTree.GetNodes().push_back(quad);
                }
                break;

            default:
                break;
        }
    }
}
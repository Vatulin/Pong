#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "Paddle.h"
#include "Ball.h"
#include "Score.h"


std::string randDirection() {
    if (std::rand() % 2 == 0) {
        return "Right";
    }
    else
    {
        return "Left";
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Pong");
    sf::Clock clock;
    float time;
    std::string type = randDirection();
    int firstPlayerScore = 0, secondPlayerScore = 0;
    sf::Font font;

    window.setVerticalSyncEnabled(true);


    Paddle paddle1(&window, 1);
    Paddle paddle2(&window, 2);
    Ball ball(&window);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scan::Escape)
                {
                    window.close();
                }
            }

        std::string scoreString = std::to_string(secondPlayerScore) + ":" + std::to_string(firstPlayerScore);
        if (!font.openFromFile("fonts/arial.ttf")) {
            std::cerr << "Ошибка загрузки шрифта!\n";
        }
        Score score(&window, scoreString, font);

        //Отскок мяча и начисление очков первому игроку
        if (ball.getX() >= 750.f && ball.getY() <= paddle2.getY() + 45 && ball.getY() >= paddle2.getY() - 45 &&
            type == "Right") {
            type = "Left";
            ball.addAcceleration();
            ball.setTangle();
                
        }
        if (ball.getX() >= 800) {
            secondPlayerScore += 1;
            ball.reset();
            type = randDirection();
        }
        
        //Отскок мяча и начисление очков второму игроку 

        if (ball.getY() >= 590.f) {
            ball.setTangle();
        }
        if (ball.getY() <= 10.f) {
            ball.setTangle();
        }

        if (ball.getX() <= 25.f && ball.getY() <= paddle1.getY() + 55 && ball.getY() >= paddle1.getY() - 55 &&
            type == "Left") {
            type = "Right";
            ball.addAcceleration();
            ball.setTangle();
        }

        if (ball.getX() <= 0.f) {
            firstPlayerScore += 1;
            ball.reset();

            type = randDirection();
        }

        //Изменение направления движения мяча
        if (type == "Right") {
            ball.startRight();
        }
        else {
            ball.startLeft();
        }

        float deltaTime = clock.restart().asMilliseconds();

        paddle1.update(deltaTime);
        paddle2.update(deltaTime);

        window.clear();
        
        score.draw();
        ball.draw();
        paddle1.draw();
        paddle2.draw();
        
        time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        window.display();
    }
}
#include <SFML/Graphics.hpp>
#include <iostream>



class Paddle {
    sf::RenderWindow* window;
    sf::RectangleShape rectangle;
    float y;
    int player, score;

public:
    Paddle(sf::RenderWindow* window, int player) {
        this->score = 0;
        this->player = player;
        this->window = window;

        this->rectangle.setSize(sf::Vector2f(10.f, 100.f));
        this->rectangle.setOrigin({ 5.f, 50.f });
        if (this->player == 1) {
            this->y = 300.f;
            this->rectangle.setPosition({ 25.f, this->y });
        }
        else {
            this->y = 300.f;
            this->rectangle.setPosition({ 775.f, this->y });
        }
    }

    void setY(float newY) {
        if (newY < 50.f) {
            this->y = 50.f;
            this->rectangle.setPosition({ this->rectangle.getPosition().x, this->y });
        }
        if (newY > 550.f) {
            this->y = 550.f;
            this->rectangle.setPosition({ this->rectangle.getPosition().x, this->y });
        }
        if (newY >= 50.f && newY <= 550.f) {
            this->y = newY;
            this->rectangle.setPosition({ this->rectangle.getPosition().x, this->y });
        }
    }

    float getY() {
        return this->y;
    }

    void draw() {
        this->window->draw(this->rectangle);
    }

    void update(float time) {
        if (this->player == 2) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                this->y -= time * 0.3;
                this->setY(this->y);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                this->y += time * 0.3;
                this->setY(this->y);
            }
        }
        else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                this->setY(this->y - time * 0.3);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                this->setY(this->y + time * 0.3);
            }
        }
    }
};
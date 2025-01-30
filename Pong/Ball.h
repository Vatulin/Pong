#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

class Ball
{
private:
	sf::RenderWindow* window;
    sf::CircleShape circle;
	float x, y, acceleration, tangle;

	float randTangle() {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> dist(-0.2, 0.2);
		return dist(gen);
	}

public:
	Ball(sf::RenderWindow* window) {
		this->window = window;
		this->x = 400;
		this->y = 300;
		this->acceleration = 2.f;
		this->tangle = randTangle();

		this->circle.setRadius(10.f);
		this->circle.setPosition({x, y});
	}


	void draw() {
		this->window->draw(this->circle);
	}

	void startRight() {
		this->x += this->acceleration;
		this->y += std::sin(this->tangle) * acceleration;
		this->circle.setPosition({ x, y });
	}

	void startLeft() {
		this->x -= this->acceleration;
		this->y -= std::sin(this->tangle) * acceleration;
		this->circle.setPosition({ x, y });
	}

	void reset() {
		this->x = 400;
		this->y = 300;
		this->acceleration = 2.f;
		this->circle.setPosition({x, y});
	}
	
	void addAcceleration() {
		this->acceleration += 0.5f;
	}

	void setTangle() {
		this->tangle = randTangle();
	}

	float getX() {
		return x;
	}

	float getY() {
		return y;
	}
};
#include <SFML/Graphics.hpp>
#include <iostream>
class Score
{	
	sf::RenderWindow* window;
	std::string score;
	sf::Font font;

public:

	Score(sf::RenderWindow* window, std::string score, sf::Font font) {
		this->window = window;
		this->score = score;
		this->font = font;
	}

	void draw() {
		sf::Text text(this->font, this->score);
		text.setCharacterSize(50);
		text.setPosition({ 400, 50 });
		this->window->draw(text);
	}
};
#pragma once

#include <SFML/Graphics.hpp>

class TempoText {
public:
	TempoText(sf::Vector2f position);
	void setBPM(float bpm);
	void draw(sf::RenderWindow &window);
private:
	sf::Font font;
	sf::Text text_a;
	sf::Text text_b;
	sf::Vector2f position;
};
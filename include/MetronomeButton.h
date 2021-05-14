#pragma once

#include <SFML/Graphics.hpp>

class MetronomeButton {
public:
	MetronomeButton(sf::Vector2f);
	
	bool contains(sf::Vector2f);
	void draw(sf::RenderWindow &window);
	void setToggled(bool toggled);
	void setActive(bool active);
	bool isToggled();
private:
	sf::Texture texture_a;
	sf::Texture texture_b;
	sf::Texture texture_c;
	
	sf::Sprite sprite;
	sf::Vector2f position;
	
	bool toggled;
	bool active;
};
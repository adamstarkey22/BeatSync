#pragma once

#include <SFML/Graphics.hpp>

class GenericButton {
public:
	GenericButton(sf::Vector2f, std::string texturePath_a, std::string texturePath_b);
	
	bool contains(sf::Vector2f);
	void draw(sf::RenderWindow &window);
	void setToggled(bool toggled);
	bool isToggled();
private:
	sf::Texture texture_a;
	sf::Texture texture_b;
	
	sf::Sprite sprite;
	sf::Vector2f position;
	
	bool toggled;
};
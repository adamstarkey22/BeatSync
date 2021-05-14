#include "GenericButton.h"

GenericButton::GenericButton(sf::Vector2f position, std::string texturePath_a, std::string texturePath_b) : position(position), toggled(false) {
	texture_a.loadFromFile(texturePath_a);
	texture_b.loadFromFile(texturePath_b);
	
	sprite.setTexture(texture_a);
	sprite.setPosition(position);
}

bool GenericButton::contains(sf::Vector2f point) {	
	float radius = sprite.getGlobalBounds().width / 2.0f;
	sf::Vector2f origin(position.x + radius, position.y + radius);
	
	sf::Vector2f distanceVector = point - origin;
	float distanceFloat = (float) sqrt(pow(distanceVector.x, 2) + pow(distanceVector.y, 2));
	
	return distanceFloat < radius;
}

void GenericButton::draw(sf::RenderWindow & window) {
	window.draw(sprite);
}

void GenericButton::setToggled(bool toggled) {
	this->toggled = toggled;
	
	if (toggled) {
		sprite.setTexture(texture_b);
	} else {
		sprite.setTexture(texture_a);
	}
}

bool GenericButton::isToggled() {
	return toggled;
}
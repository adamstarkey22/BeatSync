#include "MetronomeButton.h"

MetronomeButton::MetronomeButton(sf::Vector2f position) : position(position), toggled(false), active(false) {
	texture_a.loadFromFile("images/metronome-a.png");
	texture_b.loadFromFile("images/metronome-b.png");
	texture_c.loadFromFile("images/metronome-c.png");
	
	sprite.setTexture(texture_a);
	sprite.setPosition(position);
}

bool MetronomeButton::contains(sf::Vector2f point) {	
	float radius = sprite.getGlobalBounds().width / 2.0f;
	sf::Vector2f origin(position.x + radius, position.y + radius);
	
	sf::Vector2f distanceVector = point - origin;
	float distanceFloat = (float) sqrt(pow(distanceVector.x, 2) + pow(distanceVector.y, 2));
	
	return distanceFloat < radius;
}

void MetronomeButton::draw(sf::RenderWindow & window) {
	window.draw(sprite);
}

void MetronomeButton::setToggled(bool toggled) {
	this->toggled = toggled;
	
	if (active) {
		if (toggled) {
			sprite.setTexture(texture_b);
		} else {
			sprite.setTexture(texture_a);
		}
	} else {
		sprite.setTexture(texture_c);
	}
}

void MetronomeButton::setActive(bool active) {
	this->active = active;
	
	if (active) {
		if (toggled) {
			sprite.setTexture(texture_b);
		} else {
			sprite.setTexture(texture_a);
		}
	} else {
		sprite.setTexture(texture_c);
	}
}

bool MetronomeButton::isToggled() {
	return toggled;
}
#include "TempoText.h"

TempoText::TempoText(sf::Vector2f position) : position(position) {
	font.loadFromFile("fonts/sinkin_sans-regular.otf");
	
	text_a.setFont(font);
	text_a.setCharacterSize(41);
	
	text_b.setFont(font);
	text_b.setCharacterSize(27);
	text_b.setString("BPM");
	text_b.setPosition(position.x - (text_b.getGlobalBounds().width / 2.0f), position.y + 60.75f);
}

void TempoText::setBPM(float bpm) {
	if (bpm > 0) {
		text_a.setString(std::to_string(bpm));
	} else {
		text_a.setString("-");
	}
	
	text_a.setPosition(position.x - (text_a.getGlobalBounds().width / 2.0f), position.y);
}

void TempoText::draw(sf::RenderWindow &window) {
	window.draw(text_a);
	window.draw(text_b);
}
#pragma once

#include <deque>
#include <SFML/System.hpp>

class Metronome {
public:
	Metronome();
	void tick();
	bool isActive();
	float calculateAverage();
	float calculateBPM(float seconds);
	void update();
private:
	sf::Clock clock;
	std::deque<sf::Time> samples;
	bool active;
	int maxSamples;
};
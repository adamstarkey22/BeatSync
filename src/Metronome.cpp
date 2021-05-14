#include "Metronome.h"

Metronome::Metronome() : active(false), maxSamples(32) {}

void Metronome::tick() {
	if (!active) {
		clock.restart();
		samples.clear();
		active = true;
	} else {
		samples.push_back(clock.restart());
		
		if (samples.size() > maxSamples) {
			samples.pop_front();
		}
	}
}

bool Metronome::isActive() {
	return active;
}

float Metronome::calculateAverage() {
	float result = 0;
	
	for (auto i = samples.begin(); i != samples.end(); ++i) {
		result += i->asSeconds();
	}
	
	result /= samples.size();
	
	return result;
}

float Metronome::calculateBPM(float seconds) {
	return 60.0f / seconds;
}

void Metronome::update() {
	if (clock.getElapsedTime().asSeconds() > calculateAverage() * 2) {
		active = false;
	}
}
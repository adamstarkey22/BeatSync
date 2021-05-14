#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "BeatSyncConfig.h"
#include "Metronome.h"
#include "MetronomeButton.h"
#include "TempoText.h"
#include "GenericButton.h"

const std::string version = std::to_string(BeatSync_VERSION_MAJOR) + "." + std::to_string(BeatSync_VERSION_MINOR) + "." + std::to_string(BeatSync_VERSION_PATCH);

int main(int argc, char *argv[]) {
	std::string audioPath;
	float bpm;
	
	if (argc == 3) {
		audioPath = argv[1];
		bpm = (float) atof(argv[2]);
	} else {
		std::cout << "Usage: beatsync <path-to-audio> <original-bpm>" << std::endl;
		return 0;
	}
	
	sf::RenderWindow window(sf::VideoMode(540, 960), "BeatSync " + version, sf::Style::Close);
	window.setFramerateLimit(60);
	
	// Logic
	Metronome metronome;
	
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile(audioPath)) {
		std::cout << "Error loading sound file." << std::endl;
	}
	
	sf::Sound sound;
	sound.setBuffer(buffer);
	
	// Creating background sprite
	sf::Texture bgTexture;
	bgTexture.loadFromFile("images/background.png");
	sf::Sprite bgSprite;
	bgSprite.setTexture(bgTexture);
	
	// UI elements
	GenericButton playButton(
		sf::Vector2f(135.0f, 270.0f),
		"images/play-a.png",
		"images/play-b.png"
	);
	
	GenericButton loopButton(
		sf::Vector2f(27.0f, 27.0f),
		"images/loop-a.png",
		"images/loop-b.png"
	);
	
	MetronomeButton metronomeButton(sf::Vector2f(202.5f, 621.0f));	
	TempoText tempoText(sf::Vector2f(270.0f, 155.25f));
	tempoText.setBPM(bpm);
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			} else if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					// Play button clicked					
					if (playButton.contains(sf::Vector2f((float) sf::Mouse::getPosition(window).x, (float) sf::Mouse::getPosition(window).y))) {
						if (sound.getStatus() == sf::SoundSource::Stopped) {
							sound.setPitch(metronome.calculateBPM(metronome.calculateAverage()) / bpm);
							sound.play();
						} else if (sound.getStatus() == sf::SoundSource::Playing) {
							sound.stop();
						}
					}
					
					// Metronome button clicked
					if (metronomeButton.contains(sf::Vector2f((float) sf::Mouse::getPosition(window).x, (float) sf::Mouse::getPosition(window).y))) {
						metronomeButton.setToggled(true);
						metronome.tick();
						tempoText.setBPM(metronome.calculateBPM(metronome.calculateAverage()));
					}
					
					// Loop button clicked
					if (loopButton.contains(sf::Vector2f((float) sf::Mouse::getPosition(window).x, (float) sf::Mouse::getPosition(window).y))) {
						sound.setLoop(!sound.getLoop());
						loopButton.setToggled(sound.getLoop());
					}
				}
			} else if (event.type == sf::Event::MouseButtonReleased) {
				 if (event.mouseButton.button == sf::Mouse::Left) {
					metronomeButton.setToggled(false);
				}
			}
		}
		
		if (sound.getStatus() == sf::SoundSource::Playing && !playButton.isToggled()) {
			playButton.setToggled(true);
		} else if (sound.getStatus() == sf::SoundSource::Stopped && playButton.isToggled()) {
			playButton.setToggled(false);
		}
		
		metronome.update();
		metronomeButton.setActive(metronome.isActive());
		
		window.clear(sf::Color::Black);
		window.draw(bgSprite);
		playButton.draw(window);
		metronomeButton.draw(window);
		loopButton.draw(window);
		tempoText.draw(window);
		window.display();
	}
	
	return 0;
}
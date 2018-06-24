#include "stdafx.h"
#include "GameOver.h"


GameOver::GameOver(const Mode& mode, const int scoreORwinner) 
: m_mode(mode) {
	m_font.loadFromFile("font.ttf");

	std::string title = mode == Mode::SinglePlayer ?  "GameOver!" : "Congratulations!";
	std::string message = mode == Mode::SinglePlayer ? "You have scored " + std::to_string(scoreORwinner) + " points." :
		"Player " + std::to_string(scoreORwinner) + " wins.";

	init_text(m_title, sf::Color::Red, title, 70, 200);
	init_text(m_message, sf::Color::Green, message, 50, 300);
	init_text(m_instruction, sf::Color::Blue, "Press R to restart and Q to quit.", 50, 370);
}

void GameOver::handleInput(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		stateManager.setState(new Menu());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		switch (m_mode) {
		case Mode::SinglePlayer:
			stateManager.setState(new SinglePlayer());
			break;
		case Mode::MultiPlayer:
			stateManager.setState(new MultiPlayer());
			break;
		}
	}
}

void GameOver::render(sf::RenderWindow& window) {
	window.draw(m_title);
	window.draw(m_message);
	window.draw(m_instruction);
}

void GameOver::init_text(sf::Text& text, const sf::Color& color, const std::string& string, const unsigned int charsize,const int ypos) {
	text.setFont(m_font);
	text.setCharacterSize(charsize);
	text.setString(string);
	text.setFillColor(color);
	text.setPosition(screenSize.x / 2 - text.getGlobalBounds().width / 2, ypos);
}

GameOver::~GameOver() {

}

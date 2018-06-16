#include "stdafx.h"
#include "Menu.h"


Menu::Menu() {
	m_title.setString("The Snek Game");
	m_options[0].setString("Single-Player");
	m_options[1].setString("Multi-Player");
	m_options[2].setString("Quit");
	m_font.loadFromFile("font.ttf");

	init_text(m_title, 120, 20);
	for (int i = 0; i < 3; i++)
		init_text(m_options[i], 60, (i * 80) + 200);
}

void Menu::handleInput(sf::RenderWindow& window) {
	if (isUpPressed()) {
		if (m_selected == 0)
			m_selected = 2;
		else
			m_selected--;
	}
	else if (isDownPressed()) {
		if (m_selected == 2)
			m_selected = 0;
		else
			m_selected++;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		switch (m_selected) {
		case 0:
			stateManager.setState(new SinglePlayer());
			break;
		case 1:
			stateManager.setState(new MultiPlayer());
			break;
		case 2:
			window.close();
			break;
		}
	}
}

void Menu::update(sf::RenderWindow& window) {
	for (int i = 0; i < 3; i++) {
		if (i == m_selected)
			m_options[i].setFillColor(sf::Color::Green);
		else
			m_options[i].setFillColor(sf::Color::White);
	}
}

void Menu::render(sf::RenderWindow& window) {
	window.draw(m_title);
	for (int i = 0; i < 3; i++)
		window.draw(m_options[i]);

}

void Menu::init_text(sf::Text& text, unsigned int charSize, const int ypos) {
	text.setFont(m_font);
	text.setCharacterSize(charSize);
	text.setFillColor(sf::Color::White);
	text.setPosition( screenSize.x /2 - text.getGlobalBounds().width /2, ypos);
}

bool Menu::isUpPressed() {
	bool pressedNow = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	bool Val = pressedNow && !m_pressedLastFrameUP;
	m_pressedLastFrameUP = pressedNow;
	return Val;
}

bool Menu::isDownPressed() {
	bool pressedNow = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	bool Val = pressedNow && !m_pressedLastFrameDOWN;
	m_pressedLastFrameDOWN = pressedNow;
	return Val;
}
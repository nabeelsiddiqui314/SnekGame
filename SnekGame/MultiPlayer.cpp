#include "stdafx.h"
#include "MultiPlayer.h"


MultiPlayer::MultiPlayer() {
	m_board = new Board({ cellNumber.x, cellNumber.y }, cellWidth, { 0, 0 }, cellGap, sf::Color::Black);
	for (int i = 0; i < 2; i++) {
		m_players[i].snek = new Snek({ i * cellNumber.x / 2 + cellNumber.x / 4 , cellNumber.y / 2 }, sf::Color(0, ((i + 1) % 2) * 255, ((i + 2) % 2) * 255), i + 1);
		m_fruits[i] = new Collectable(sf::Color::Red, 3);
		m_fruits[i]->changepos(m_board);
		m_players[i].direction = { 0, 0 };
	}
}

void MultiPlayer::handleInput(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_players[0].direction = { 0, -1 };
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_players[0].direction = { -1, 0 };
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_players[0].direction = { 0, 1 };
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_players[0].direction = { 1, 0 };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_players[1].direction = { 0, -1 };
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_players[1].direction = { -1, 0 };
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_players[1].direction = { 0, 1 };
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_players[1].direction = { 1, 0 };
}

void MultiPlayer::update(sf::RenderWindow& window) {
	if (m_updateClock.getElapsedTime().asMilliseconds() > 90) {
		for (int i = 0; i < 2; i++) {
			m_players[i].snek->move(m_players[i].direction, m_board);
			m_players[i].snek->updateColor(m_board);
			m_fruits[i]->updateColor(m_board);
		}
		m_updateClock.restart();
	}
}

void MultiPlayer::render(sf::RenderWindow& window) {
	m_board->render(window);
}

MultiPlayer::~MultiPlayer() {
	for (int i = 0; i < 2; i++) {
		delete m_players[i].snek;
		delete m_fruits[i];
	}
	delete m_board;
}

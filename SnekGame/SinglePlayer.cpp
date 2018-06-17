#include "stdafx.h"
#include "SinglePlayer.h"


SinglePlayer::SinglePlayer() {
	m_board = new Board({ cellNumber.x, cellNumber.y }, cellWidth, {0, 0}, cellGap, sf::Color::Black);
	m_snek = new Snek({cellNumber.x /2, cellNumber.y / 2}, sf::Color::Green, 1);
	m_fruit = new Collectable(sf::Color::Red, 2);
	m_fruit->changepos(m_board);
	m_direction = {0, 0};
}

void SinglePlayer::handleInput(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_direction = {0, -1};
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_direction = { -1, 0 };
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_direction = { 0, 1 };
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_direction = { 1, 0 };
}

void SinglePlayer::update(sf::RenderWindow& window) {
	if (m_updateClock.getElapsedTime().asMilliseconds() > 90) {
		if (m_snek->isInBounds(m_board)) {
			m_snek->move(m_direction, m_board);
			if (m_snek->getNextCellID() == m_fruit->getID()) {
				m_snek->grow();
				m_fruit->changepos(m_board);
			}
			else if (m_snek->getNextCellID() > 0) {
				end_game();
				return;
			}
			m_fruit->updateColor(m_board);
			m_snek->updateColor(m_board);
			m_updateClock.restart();
		}
		else
			end_game();
	}
}

void SinglePlayer::render(sf::RenderWindow& window) {
	m_board->render(window);
}

void SinglePlayer::end_game() {
	stateManager.setState(new Menu());
}

SinglePlayer::~SinglePlayer() {
	delete m_fruit;
	delete m_snek;
	delete m_board;
}

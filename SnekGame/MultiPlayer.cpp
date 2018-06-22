#include "stdafx.h"
#include "MultiPlayer.h"


MultiPlayer::MultiPlayer() {
	m_board = new Board({ cellNumber.x, cellNumber.y }, cellWidth, { 0, 0 }, cellGap, sf::Color::Black);
	for (int i = 0; i < 2; i++) {
		m_players[i].snek = new Snek({ i * cellNumber.x / 2 + cellNumber.x / 4 , cellNumber.y / 2 }, sf::Color(0, ((i + 1) % 2) * 255, ((i + 2) % 2) * 255), i + 1);
		m_players[i].direction = { 0, 0 };
	}
	m_fruit = new Collectable(sf::Color::Red, 3);
	m_fruit->changepos(m_board);

	m_font.loadFromFile("font.ttf");
	m_gameOver.setFont(m_font);
	m_gameOver.setCharacterSize(70);
	m_gameOver.setFillColor(sf::Color::Red);
}

void MultiPlayer::handleInput(sf::RenderWindow& window) {
	switch (m_isGameOver) {
	case false:
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
		break;
	case true:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			stateManager.setState(new MultiPlayer());
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			stateManager.setState(new Menu());
		}
		break;
	}
}

void MultiPlayer::update(sf::RenderWindow& window) {
	if (m_isGameOver)
		return;

	if (m_updateClock.getElapsedTime().asMilliseconds() > 90) {
		for (int i = 0; i < 2; i++) {
			if (m_players[i].snek->isInBounds(m_board)) {
				m_players[i].snek->move(m_players[i].direction, m_board);
				if (m_players[i].snek->getNextCellID() == m_fruit->getID()) {
					m_players[i].snek->grow();
					m_fruit->changepos(m_board);
				}
				else if (m_players[i].snek->getNextCellID() > 0) {
					end_game(swap(i));
					break;
				}
				m_players[i].snek->updateColor(m_board);
				m_fruit->updateColor(m_board);
			}
			else {
				end_game(swap(i));
				break;
			}
		}
		m_updateClock.restart();
	}
}

void MultiPlayer::render(sf::RenderWindow& window) {
	if (!m_isGameOver)
		m_board->render(window);
	else
		window.draw(m_gameOver);
}

const int MultiPlayer::swap(const int num) const {
	if (num == 0)
		return 1;
	else
		return 0;
}

void MultiPlayer::end_game(const int winner) {
	m_gameOver.setString("             Game Over! \n           Player " + std::to_string(winner + 1) + " wins! \nPress R to restart or Q to quit.");
	m_gameOver.setPosition(screenSize.x / 2 - m_gameOver.getGlobalBounds().width / 2,
		screenSize.y / 2 - m_gameOver.getGlobalBounds().height / 2);
	m_isGameOver = true;
}

MultiPlayer::~MultiPlayer() {
	for (int i = 0; i < 2; i++) {
		delete m_players[i].snek;
	}
	delete m_fruit;
	delete m_board;
}

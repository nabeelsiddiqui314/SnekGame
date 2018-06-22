#include "stdafx.h"
#include "SinglePlayer.h"


SinglePlayer::SinglePlayer() {
	m_board = new Board({ cellNumber.x, cellNumber.y }, cellWidth, {0, 0}, cellGap, sf::Color::Black);
	m_snek = new Snek({cellNumber.x /2, cellNumber.y / 2}, sf::Color::Green, 1);
	m_fruit = new Collectable(sf::Color::Red, 2);
	m_fruit->changepos(m_board);
	m_direction = {0, 0};

	m_font.loadFromFile("font.ttf");
	m_gameOver.setFont(m_font);
	m_gameOver.setCharacterSize(70);
	m_gameOver.setFillColor(sf::Color::Red);
}

void SinglePlayer::handleInput(sf::RenderWindow& window) {
	switch (m_isGameOver) {
	case false:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			m_direction = { 0, -1 };
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			m_direction = { -1, 0 };
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			m_direction = { 0, 1 };
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			m_direction = { 1, 0 };
		break;
	case true:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			stateManager.setState(new SinglePlayer());
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			stateManager.setState(new Menu());
		}
		break;
	}
}

void SinglePlayer::update(sf::RenderWindow& window) {
	if (m_isGameOver)
		return;

	if (m_updateClock.getElapsedTime().asMilliseconds() > 90) {
		if (m_snek->isInBounds(m_board)) {
			m_snek->move(m_direction, m_board);
			if (m_snek->getNextCellID() == m_fruit->getID()) {
				m_score++;
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
	if (!m_isGameOver)
		m_board->render(window);
	else
		window.draw(m_gameOver);
}

void SinglePlayer::end_game() {
	m_gameOver.setString("             Game Over! \n         Your score is: " + std::to_string(m_score) + "\nPress R to restart or Q to quit.");
	m_gameOver.setPosition(screenSize.x / 2 - m_gameOver.getGlobalBounds().width / 2,
		screenSize.y / 2 - m_gameOver.getGlobalBounds().height / 2);
	m_isGameOver = true;
}

SinglePlayer::~SinglePlayer() {
	delete m_fruit;
	delete m_snek;
	delete m_board;
}

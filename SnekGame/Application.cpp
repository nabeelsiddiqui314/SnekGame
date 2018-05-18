#include "stdafx.h"
#include "Application.h"


Application::Application() {
	m_board = new Board({ 100, 60 }, 10, { 50, 70 }, 5, sf::Color::Black);
	m_snek = new Snek({1, 1}, sf::Color::Green, 1);
	m_window.create(sf::VideoMode(1000, 600), "SnekGame", sf::Style::Close);
}

void Application::update(float deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		m_velocity = { 0, -1 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_velocity = { -1, 0 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		m_velocity = { 0, 1 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_velocity = { 1, 0 };
	}

	if (m_updateClock.getElapsedTime().asMilliseconds() > deltaTime) {
		m_snek->move(m_velocity, m_board);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
			m_snek->grow();
		}
		m_snek->updateColor(m_board);
		m_updateClock.restart();
	}
}

void Application::render() {
	m_board->render(m_window);
}

void Application::run() {
	while (m_window.isOpen()) {
		sf::Event evnt;
		while (m_window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				m_window.close();
			}
		}
		m_window.clear(sf::Color::White);
		update(90);
		render();
		m_window.display();
	}
}

Application::~Application()
{
}

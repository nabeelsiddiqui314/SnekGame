#include "stdafx.h"
#include "Application.h"


Application::Application() {
	for (int x = 0; x < cellNumberX; x++) {
		for (int y = 0; y < cellNumberY; y++) {
			m_board[x][y] = { x * cellWidth, y * cellWidth };
		}
	}

	m_window.create(sf::VideoMode(cellNumberX * cellWidth, cellNumberY * cellWidth), "SnekGame", sf::Style::Close);
}

void Application::update(float deltaTime) {
	if (m_updateClock.getElapsedTime().asSeconds() > 0.2) {
		shnek.move({ 1, 0 });
		//shnek.grow(1);
		m_updateClock.restart();
	}
}

void Application::render() {
	shnek.render(m_window);
}

void Application::run() {
	while (m_window.isOpen()) {
		sf::Event evnt;
		while (m_window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				m_window.close();
			}
		}
		m_window.clear(sf::Color(100, 100, 100));
		update(1);
		render();
		m_window.display();
	}
}

Application::~Application()
{
}

#include "stdafx.h"
#include "Application.h"


Application::Application() {
	m_window.create(sf::VideoMode(1000, 600), "SnekGame", sf::Style::Close);
}

void Application::run() {
	while (m_window.isOpen()) {
		sf::Event evnt;
		while (m_window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				m_window.close();
			}
		}
		m_window.clear();
		m_window.display();
	}
}

Application::~Application()
{
}

#pragma once
#include <SFML/Graphics.hpp>

class Application
{
public:
	Application();
	~Application();
public:
	void run();
private:
	sf::RenderWindow m_window;
};


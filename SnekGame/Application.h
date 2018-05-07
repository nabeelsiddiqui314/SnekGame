#pragma once
#include <SFML/Graphics.hpp>
#include "data.h"
#include "Snek.h"

class Application
{
public:
	Application();
	~Application();
public:
	void run();
private:
	void update(float deltaTime);
	void render();
private:
	sf::RenderWindow m_window;
	sf::Vector2i     m_board[cellNumberX][cellNumberY];
	Snek shnek;
	sf::Vector2i m_velocity = {0, 0};
	sf::Clock m_updateClock;
};


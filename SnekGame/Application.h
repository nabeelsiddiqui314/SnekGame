#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Snek.h"
#include "Collectable.h"

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
	Board* m_board;
	Snek* m_snek;
	Collectable* m_fruit;
	sf::Vector2i m_velocity = {0, 0};
	sf::Clock m_updateClock;
	bool m_isOver = false;
};


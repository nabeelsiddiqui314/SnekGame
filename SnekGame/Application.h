#pragma once
#include <SFML/Graphics.hpp>
#include "Position.h"

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
	
};


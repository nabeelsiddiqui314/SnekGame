#pragma once
#include <SFML/Graphics.hpp>

class State
{
public:
	State() {}
	virtual ~State() {}
public:
	virtual void handleInput(sf::RenderWindow& window) {};
	virtual void update(sf::RenderWindow& window) {};
	virtual void render(sf::RenderWindow& window) {};
};

class StateManager {
public:
	StateManager();
	~StateManager();
public:
	void setWindow(sf::RenderWindow& window);
	void setState(State* state);
	void update();
	void render();
private:
	sf::RenderWindow* m_window;
	State* m_state;
};

extern StateManager stateManager;


#pragma once
#include <SFML/Graphics.hpp>

class State
{
public:
	State() {}
	virtual ~State() {}
public:
	virtual void HandleInput(sf::RenderWindow& window) {};
	virtual void Update(sf::RenderWindow& window) {};
	virtual void Render(sf::RenderWindow& window) {};
};

class StateManager {
public:
	StateManager();
	~StateManager();
public:
	void SetWindow(sf::RenderWindow& window);
	void SetState(State* state);
	void Update();
	void Render();
private:
	sf::RenderWindow* m_window;
	State* m_state;
};

extern StateManager stateManager;


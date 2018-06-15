#pragma once
#include "State.h"
#include "Menu.h"
#include "GlobalVars.h"
#include <memory>
#include "Board.h"
#include "Snek.h"
#include "Collectable.h"

class SinglePlayer : public State
{
public:
	SinglePlayer();
	~SinglePlayer();
public:
	void handleInput(sf::RenderWindow& window) override;
	void update(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
private:
	void end_game();
private:
	Board* m_board;
	Snek* m_snek;
	Collectable* m_fruit;
	sf::Vector2i m_direction;
	sf::Clock m_updateClock;
};


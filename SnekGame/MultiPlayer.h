#pragma once
#include "State.h"
#include "Menu.h"
#include "Board.h"
#include "Snek.h"
#include "Collectable.h"
#include "GlobalVars.h"

class MultiPlayer : public State
{
private:
	struct Player {
		Snek* snek;
		sf::Vector2i direction;
	};
public:
	MultiPlayer();
	~MultiPlayer();
public:
	void handleInput(sf::RenderWindow& window) override;
	void update(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
private:
	const int swap(const int num) const;
	void end_game(const int winner);
private:
	Board* m_board;
	Player m_players[2];
	Collectable* m_fruit;
	sf::Clock m_updateClock;
	bool m_isGameOver = false;
	sf::Font m_font;
	sf::Text m_gameOver;
};


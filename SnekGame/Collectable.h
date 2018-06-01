#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Collectable
{
public:
	Collectable(const sf::Color& color, const int id);
public:
	void changepos(Board* brd);
	void updateColor(Board* brd);
private:
	const sf::Color m_color;
	const int m_id;
	sf::Vector2i m_pos = {0, 0};
};


#pragma once
#include <SFML/Graphics.hpp>

class Board
{
public:
	Board(const sf::Vector2i& cellNumber, int cellWidth, const sf::Color& clr);
public:
	void setCellColor(const sf::Vector2i& cell, const sf::Color& color);
	void render(sf::RenderWindow& window);
private:
	sf::VertexArray m_brdVerts;
};


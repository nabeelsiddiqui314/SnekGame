#pragma once
#include <SFML/Graphics.hpp>

class Board
{
public:
	Board(const sf::Vector2i& cellNumber, int cellWidth, const sf::Color& clr);
public:
	void setCellColor(const sf::Vector2i& cell, const sf::Color& color);
	void resetColor(const sf::Vector2i& cell);
	void setCellID(const sf::Vector2i& cell, int id);
	const int getCellID(const sf::Vector2i& cell) const;
	void render(sf::RenderWindow& window);
private:
	sf::VertexArray m_brdVerts;
	int* m_cellIDs;
	sf::Vector2i m_cellNumber;
	int          m_cellWidth;
	sf::Color    m_color;
};


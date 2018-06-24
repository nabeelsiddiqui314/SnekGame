#include "stdafx.h"
#include "Board.h"

Board::Board(const sf::Vector2i& cellNumber, int cellWidth, const sf::Vector2i& origin, int gap, const sf::Color& clr)
	: m_brdVerts(sf::Quads, cellNumber.x * cellNumber.y * 4),
      m_cellNumber(cellNumber),
      m_cellWidth(cellWidth),
      m_color(clr) {
	int xCount = 0;
	int yCount = 0;

	for (int i = 0; i < cellNumber.x * cellNumber.y * 4; i+= 4) {
		for (int j = 0; j < 4; j++) {
			m_brdVerts[i + j].color = clr;
		}

		int x = xCount * cellWidth;
		int y = yCount * cellWidth;

		int xPos = x + origin.x + xCount * gap;
		int yPos = y + origin.y + yCount * gap;

		m_brdVerts[i].position.x = xPos;
		m_brdVerts[i].position.y = yPos;

		m_brdVerts[i + 1].position.x = xPos + cellWidth;
		m_brdVerts[i + 1].position.y = yPos;

		m_brdVerts[i + 2].position.x = xPos + cellWidth;
		m_brdVerts[i + 2].position.y = yPos + cellWidth;

		m_brdVerts[i + 3].position.x = xPos;
		m_brdVerts[i + 3].position.y = yPos + cellWidth;

		xCount++;

		if ((x + cellWidth) % (cellNumber.x * cellWidth) == 0) {
			xCount = 0;
			yCount++;
		}
	}
	m_cellIDs = new int[cellNumber.x * cellNumber.y];
	memset(m_cellIDs, 0, cellNumber.x * cellNumber.y * sizeof(m_cellIDs[0]));
}

void Board::setCellColor(const sf::Vector2i& cell, const sf::Color& color) {
	int index = (cell.x + cell.y * m_cellNumber.x) * 4;
	for (int i = index; i < index + 4; i++)
		m_brdVerts[i].color = color;
}

void Board::resetColor(const sf::Vector2i& cell) {
	setCellColor(cell, m_color);
}

void Board::setCellID(const sf::Vector2i& cell, int id) {
	int index = (cell.x + cell.y * m_cellNumber.x);
	m_cellIDs[index] = id;
}

const int Board::getCellID(const sf::Vector2i& cell) const {
	if (cell.x < 0 || cell.y < 0 || cell.x > m_cellNumber.x-1 || cell.y > m_cellNumber.y-1)
		return 0;

	int index = (cell.x + cell.y * m_cellNumber.x);
	return m_cellIDs[index];
}

const sf::Vector2i& Board::getCellNumber() const {
	return m_cellNumber;
}

void Board::render(sf::RenderWindow& window) {
	window.draw(m_brdVerts);
}

#include "stdafx.h"
#include "Board.h"

Board::Board(const sf::Vector2i& cellNumber, int cellWidth, const sf::Color& clr)
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

		m_brdVerts[i].position.x = x;
		m_brdVerts[i].position.y = y;

		m_brdVerts[i + 1].position.x = x + cellWidth;
		m_brdVerts[i + 1].position.y = y;

		m_brdVerts[i + 2].position.x = x + cellWidth;
		m_brdVerts[i + 2].position.y = y + cellWidth;

		m_brdVerts[i + 3].position.x = x;
		m_brdVerts[i + 3].position.y = y + cellWidth;

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
	m_brdVerts[index].color = color;
	m_brdVerts[index + 1].color = color;
	m_brdVerts[index + 2].color = color;
	m_brdVerts[index + 3].color = color;
}

void Board::setCellID(const sf::Vector2i& cell, int id) {
	int index = (cell.x + cell.y * m_cellNumber.x) * 4;
	m_cellIDs[index] = id;
}

const int Board::getCellID(const sf::Vector2i& cell) const {
	int index = (cell.x + cell.y * m_cellNumber.x) * 4;
	return m_cellIDs[index];
}

void Board::render(sf::RenderWindow& window) {
	window.draw(m_brdVerts);
}

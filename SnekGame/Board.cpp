#include "stdafx.h"
#include "Board.h"
#include <iostream>

Board::Board(const sf::Vector2i& cellNumber, int cellWidth, const sf::Color& clr)
	: m_brdVerts(sf::Quads, cellNumber.x * cellNumber.y * 4) {
	int xCount = 0;
	int yCount = 0;

	for (int i = 0; i < cellNumber.x * cellNumber.y * 4; i+= 4) {
		for (int j = 0; j < 4; j++) {
			m_brdVerts[i + j].color = sf::Color(j * 50, j * 25, 255);
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
}

void Board::setCellColor(const sf::Vector2i& cell, const sf::Color& color) {

}

void Board::render(sf::RenderWindow& window) {
	window.draw(m_brdVerts);
}

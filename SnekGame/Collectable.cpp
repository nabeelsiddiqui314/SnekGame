#include "stdafx.h"
#include "Collectable.h"


Collectable::Collectable(const sf::Color& color, const int id)
	: m_color(color)
	, m_id(id) {
	srand(time(NULL));
}

void Collectable::changepos(Board* brd) {
	brd->resetColor(m_pos);
	brd->setCellID(m_pos, 0);

	int x = rand() % brd->getCellNumber().x;
	int y = rand() % brd->getCellNumber().y; 
	while (brd->getCellID({ x, y }) != 0) {
		x = rand() % brd->getCellNumber().x;
		y = rand() % brd->getCellNumber().y;
	}
	m_pos = { x, y };
}

void Collectable::updateColor(Board* brd) {
	brd->setCellColor(m_pos, m_color);
	brd->setCellID(m_pos, m_id);
}

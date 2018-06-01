#include "stdafx.h"
#include "Snek.h"

Snek::Segment::Segment(const sf::Vector2i& pos) 
: m_pos(pos) {}

void Snek::Segment::changePos(const sf::Vector2i& deltaPos) {
	m_pos.x += deltaPos.x;
	m_pos.y += deltaPos.y;
}

void Snek::Segment::follow(const Segment& other) {
	m_pos = other.getPosition();
}

const sf::Vector2i& Snek::Segment::getPosition() const {
	return m_pos;
}

Snek::Snek(const sf::Vector2i& pos, const sf::Color& color, const int id) 
: m_id(id)
, m_color(color) {
	m_snek.emplace_back(pos);
}

void Snek::grow() {
	m_snek.emplace_back(m_snek[m_snek.size() - 1].getPosition());
}

void Snek::move(const sf::Vector2i& deltaPos, Board* brd) {
	if (deltaPos.x == 0 && deltaPos.y == 0)
		return;

	brd->resetColor(m_snek[m_snek.size() - 1].getPosition());
	brd->setCellID(m_snek[m_snek.size() - 1].getPosition(), 0);

	for (int i = m_snek.size() -1; i > 0; i--) {
		m_snek[i].follow(m_snek[i-1]);
	}
	m_snek[0].changePos(deltaPos);
	m_nextID = brd->getCellID(m_snek[0].getPosition());
}

void Snek::updateColor(Board* brd) {
	for (int i = 0; i < m_snek.size(); i++) {
		brd->setCellColor(m_snek[i].getPosition(), m_color);
		brd->setCellID(m_snek[i].getPosition(), m_id);
	}
}

const int Snek::getNextCellID() {
	return m_nextID;
}

bool Snek::isInBounds(Board* brd) {
	return m_snek[0].getPosition().x > 0 && m_snek[0].getPosition().x < brd->getCellNumber().x &&
		   m_snek[0].getPosition().y > 0 && m_snek[0].getPosition().y < brd->getCellNumber().y - 1;
}

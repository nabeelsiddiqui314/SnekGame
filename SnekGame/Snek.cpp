#include "stdafx.h"
#include "Snek.h"

bool Snek::Segment::s_texInited = false;
sf::Texture Snek::Segment::s_texture;

Snek::Segment::Segment(const sf::Vector2i& pos) {
	if (!s_texInited) {
		Snek::Segment::s_texture.loadFromFile("./assets/graphics/snek.jpg");
		s_texInited = true;
	}
	m_pos = pos;
}

void Snek::Segment::changePos(const sf::Vector2i& deltaPos) {
	m_pos.x += deltaPos.x;
	m_pos.y += deltaPos.y;
}

void Snek::Segment::follow(const Segment& other) {
	m_pos = other.getPosition();
}

void Snek::Segment::setType(const Type& type) {
	/*switch (type) {
	case HEAD:
		m_segment.setFillColor(sf::Color::Blue);
		break;
	case BODY:
		m_segment.setFillColor(sf::Color::Green);
		break;
	case TAIL:
		m_segment.setFillColor(sf::Color::Red);
		break;
	}*/
}

const sf::Vector2i& Snek::Segment::getPosition() const {
	return m_pos;
}

void Snek::Segment::render(Board* brd) {
	brd->setCellColor(m_pos, sf::Color::Blue);
}

Snek::Snek(const sf::Vector2i& pos) {
	m_snek.emplace_back(pos);
}

void Snek::grow() {
	m_snek.emplace_back(m_snek[m_snek.size() - 1].getPosition());
}

void Snek::move(const sf::Vector2i& deltaPos, Board* brd) {
	if (deltaPos.x == 0 && deltaPos.y == 0)
		return;

	brd->setCellColor(m_snek[m_snek.size() - 1].getPosition(), sf::Color::White);

	for (int i = m_snek.size() -1; i > 0; i--) {
		m_snek[i].follow(m_snek[i-1]);
	}
	m_snek[0].changePos(deltaPos);
}

void Snek::render(Board* brd) {
	for (int i = 0; i < m_snek.size(); i++) {
		m_snek[i].render(brd);
	}
}
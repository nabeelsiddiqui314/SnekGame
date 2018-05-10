#include "stdafx.h"
#include "Snek.h"

bool Snek::Segment::s_texInited = false;
sf::Texture Snek::Segment::s_texture;

Snek::Segment::Segment() {
	if (!s_texInited) {
		Snek::Segment::s_texture.loadFromFile("./assets/graphics/snek.jpg");
		s_texInited = true;
	}

	m_segment.setSize({ static_cast<float>(cellWidth), static_cast<float>(cellWidth) });
	m_segment.setTexture(&s_texture);

	//temp
}

void Snek::Segment::changePos(const sf::Vector2i& deltaPos) {
	m_segment.setPosition(m_segment.getPosition().x + (deltaPos.x * cellWidth),
		                  m_segment.getPosition().y + (deltaPos.y * cellWidth));
}

void Snek::Segment::follow(const Segment& other) {
	m_segment.setPosition(other.getPosition());
}

void Snek::Segment::setType(const Type& type) {
	switch (type) {
	case HEAD:
		m_segment.setFillColor(sf::Color::Blue);
		break;
	case BODY:
		m_segment.setFillColor(sf::Color::Green);
		break;
	case TAIL:
		m_segment.setFillColor(sf::Color::Red);
		break;
	}
}

void Snek::Segment::setPosition(const sf::Vector2f& pos) {
	m_segment.setPosition(pos);
}

const sf::Vector2f& Snek::Segment::getPosition() const {
	return m_segment.getPosition();
	
}

void Snek::Segment::render(sf::RenderWindow& window) {
	window.draw(m_segment);
}

Snek::Snek() {
	m_snek.emplace_back();
	m_snek.emplace_back();
	m_snek[0].setPosition({cellWidth * 5, cellWidth * 5});
	m_snek[1].setPosition({ cellWidth * 4, cellWidth * 5 });
	m_snek[0].setType(Segment::HEAD);
	m_snek[1].setType(Segment::TAIL);
}

void Snek::grow() {
	m_snek.emplace_back();

	int last_val = m_snek.size() - 1;

	m_snek[last_val].setPosition(m_snek[last_val - 1].getPosition());

	m_snek[last_val - 1].setType(Segment::BODY);
	m_snek[last_val].setType(Segment::TAIL);
}

void Snek::move(const sf::Vector2i& deltaPos) {
	if (deltaPos.x == 0 && deltaPos.y == 0)
		return;

	for (int i = m_snek.size() -1; i > 0; i--) {
		m_snek[i].follow(m_snek[i-1]);
	}
	m_snek[0].changePos(deltaPos);
}

void Snek::render(sf::RenderWindow& window) {
	for (int i = 0; i < m_snek.size(); i++) {
		m_snek[i].render(window);
	}
}
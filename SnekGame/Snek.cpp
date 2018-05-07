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
	m_segment.setFillColor(sf::Color::Green);
}

void Snek::Segment::changePos(const sf::Vector2i& deltaPos) {
	m_segment.setPosition(m_segment.getPosition().x + (deltaPos.x * cellWidth),
		                  m_segment.getPosition().y + (deltaPos.y * cellWidth));
}

void Snek::Segment::follow(const Segment& other) {
	m_segment.setPosition(other.getPosition());
}

void Snek::Segment::setType(const Type& type) {

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
}

void Snek::grow(int segments) {
	m_snek.emplace_back();
}

void Snek::move(const sf::Vector2i& deltaPos) {
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
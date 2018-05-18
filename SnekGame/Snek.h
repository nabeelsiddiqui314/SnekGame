#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Snek
{
private:
	class Segment {
	public:
		enum Type {
			HEAD,
			BODY,
			TAIL
		};
	public:
		Segment(const sf::Vector2i& pos);
	public:
		void changePos(const sf::Vector2i& deltaPos);
		void follow(const Segment& other);
		void setType(const Type& type);
		const sf::Vector2i& getPosition() const;
	private:
		sf::Vector2i m_pos;
	};
public:
	Snek(const sf::Vector2i& pos, const sf::Color& color, int id);
	~Snek() = default;
public:
	void grow();
	void move(const sf::Vector2i& deltaPos, Board* brd);
	void updateColor(Board* brd);
private:
	int m_id;
	sf::Color m_color;
	std::vector<Segment> m_snek;
};
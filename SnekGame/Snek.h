#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Snek
{
private:
	class Segment {
	public:
		Segment(const sf::Vector2i& pos);
	public:
		void changePos(const sf::Vector2i& deltaPos);
		void follow(const Segment& other);
		const sf::Vector2i& getPosition() const;
	private:
		sf::Vector2i m_pos;
	};
public:
	Snek(const sf::Vector2i& pos, const sf::Color& color, const int id);
	~Snek() = default;
public:
	void grow();
	void move(const sf::Vector2i& deltaPos, Board* brd);
	void updateColor(Board* brd);
	const int getNextCellID() const;
	bool isInBounds(Board* brd) const;
	const int getID() const;
private:
	const int m_id;
	const sf::Color m_color;
	std::vector<Segment> m_snek;
	int m_nextID;
};
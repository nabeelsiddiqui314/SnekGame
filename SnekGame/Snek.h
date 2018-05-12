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
		void render(Board* brd);
	private:
		sf::Vector2i m_pos;
		static sf::Texture s_texture;
		static bool        s_texInited;
	};
public:
	Snek(const sf::Vector2i& pos);
	~Snek() = default;
public:
	void grow();
	void move(const sf::Vector2i& deltaPos, Board* brd);
	void render(Board* brd);
private:
	std::vector<Segment> m_snek;
};
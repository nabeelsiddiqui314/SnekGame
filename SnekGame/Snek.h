#pragma once
#include <SFML/Graphics.hpp>

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
		Segment();
	public:
		void changePos(const sf::Vector2i& deltaPos);
		void follow(const Segment& other);
		void setType(const Type& type);
		void setPosition(const sf::Vector2f& pos);
		const sf::Vector2f& getPosition() const;
		void render(sf::RenderWindow& window);
	private:
		sf::RectangleShape m_segment;
		static sf::Texture s_texture;
		static bool        s_texInited;
	};
public:
	Snek();
	~Snek() = default;
public:
	void grow();
	void move(const sf::Vector2i& deltaPos);
	void render(sf::RenderWindow& window);
private:
	std::vector<Segment> m_snek;

};
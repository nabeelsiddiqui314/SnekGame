#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Menu.h"
#include "SinglePlayer.h"
#include "MultiPlayer.h"

enum class Mode {
	SinglePlayer,
	MultiPlayer
};

class GameOver : public State
{
public:
	GameOver(const Mode& mode, const int scoreORwinner);
	~GameOver();
public:
	void handleInput(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
private:
	void init_text(sf::Text& text, const sf::Color& color, const std::string& string, const unsigned int charsize, const int ypos);
private:
	Mode m_mode;
	sf::Font m_font;
	sf::Text m_title;
	sf::Text m_message;
	sf::Text m_instruction;
};


#pragma once
#include "State.h"
#include "GlobalVars.h"

class Menu : public State
{
public:
	Menu();
	~Menu();
public:
	void handleInput(sf::RenderWindow& window) override;
	void update(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
private:
	void init_text(sf::Text& text, unsigned int charSize, const int ypos);
	bool isUpPressed();
	bool isDownPressed();
private:
	bool m_pressedLastFrameUP = false;
	bool m_pressedLastFrameDOWN = false;
	sf::Font m_font;
	sf::Text m_title;
	sf::Text m_options[3];
	int m_selected = 0;
	sf::Clock m_updateClock;
};


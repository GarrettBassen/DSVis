#pragma once
#include "SFML/Graphics.hpp"

#include "UIHelper.h"

class TreeManager {
private:
	std::vector<UIHelper::Node> m_tree; // Vector doesn't seem efficient for this
	sf::Text m_text;
	sf::Font m_font;

public:
	TreeManager();
	void render(sf::RenderWindow& window);
	void update();

private:
	void insert();
	void remove();
	void rotate();
};
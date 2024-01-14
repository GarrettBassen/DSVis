#pragma once
#include "SFML/Graphics.hpp"

#include "UIHelper.h"

class StackManager {
private:
	std::vector<UIHelper::Frame> m_stack;
	sf::Text m_text;
	sf::Font m_font;

public:
	StackManager();
	void render(sf::RenderWindow& window);
	void update();

private:
	void push();
	void peek();
	void pop();
};
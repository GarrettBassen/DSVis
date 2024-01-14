#pragma once
#include "SFML/Graphics.hpp"
#include <deque>

#include "UIHelper.h"

class DequeManager {
private:
	std::deque<UIHelper::Frame> m_deque;
	sf::Text m_text;
	sf::Font m_font;

public:
	DequeManager();
	void render(sf::RenderWindow& window);
	void update();

private:
	void push();
	void peek();
	void pop();
};
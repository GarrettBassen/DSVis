#pragma once
#include "SFML/Graphics.hpp"

#include "UITriggers.h"

class StackManager {
private:
	struct Frame {
		std::string data;
		sf::RectangleShape rect;
	};
	
	std::vector<Frame> m_stack;
	sf::Text m_text;
	sf::Font m_font;

public:
	StackManager();
	void render(sf::RenderWindow& window);
	void update();

	void push(const std::string& data);
	void peek();
	void pop();
};
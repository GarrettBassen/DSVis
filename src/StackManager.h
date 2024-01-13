#pragma once
#include "SFML/Graphics.hpp"

#include "StackGUI.h"

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
	void push(const std::string& data);
	void pop();
	const std::string peek();
	void render(sf::RenderWindow& window);
};
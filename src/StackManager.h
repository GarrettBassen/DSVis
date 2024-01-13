#pragma once
#include "SFML/Graphics.hpp"
#include <memory>

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
	void Push(const std::string& data);
	void Pop();
	const std::string Peek();
	void Render(sf::RenderWindow& window);
};